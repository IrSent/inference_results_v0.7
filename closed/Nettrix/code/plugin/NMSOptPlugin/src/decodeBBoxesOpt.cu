/*
 * Copyright (c) 2020, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <vector>
#include <cstring>
#include <iostream>

#include "NvInferPlugin.h"
#include "ssdOpt.h"
#include "ssdOptMacros.h"
//#include "ssd_internal.h"
#include "nmsPluginOpt.h"
#include "fast_divmod.h"

namespace nvinfer1
{
namespace plugin
{


template <typename T_BBOX, int NUM_LAYERS>
struct DecodeBBoxesOptData {
    const T_BBOX * loc_data[NUM_LAYERS];
    int feature_size_pow2[NUM_LAYERS];
    int end_layer_prior[NUM_LAYERS];
    int num_anchors[NUM_LAYERS];
    int box_channels[NUM_LAYERS];
    int conf_channels[NUM_LAYERS];
    uint32_t num_anchors_mul[NUM_LAYERS];
    uint32_t num_anchors_shr[NUM_LAYERS];
    bool reshape_before_permute;
    bool packed32_nchw;
};

/* This function maps the input index to the corresponding loc_data offset.
The input "loc_data" is composed of "num_layers" loc tensors from the CONV
layers in SSD. These tensors are in NCHW layout.
The input index is broken down to 4 components: i, c, d, n
i - box coordinate (max 4)
c - class (max num_loc_classes)
d - prior (max num_priors)
n - batch size

For SSD-MobileNet:
The transformed loc_data is generated by:
1. loc_data[id_layer] -> NCHW
2. permute(1,2,0) -> NHWC
3. reshape -> (N, H*W*C/num_loc_classes/4, num_loc_classes, 4) or (N, num_priors_layer, num_loc_classes, 4)
4. concat(axis=1, num_layers) -> (N, num_priors, num_loc_classes, 4)
5. flatten -> (N, num_priors * num_loc_classes *4, 1, 1)
Therefore, before concat, each loc_data[id_layer] effectively has:
num_anchors_layer = C/num_loc_classes/4
num_priors_layer = H*W*num_anchors_layer = H*W*C/num_loc_classes/4
num_box_coors = 4
After concat, the num_priors_layer (id_layer=0...5) are concatenated together, so
num_priors = sum(num_priors_layer)
Correspondingly, giving an index from the result of step 5 above, the mapping process will
a. Compute its i (box corrdinate), c (class), d (prior), n (batch size) accordingly
b. Using d, find the corresponding id_layer using num_priors_layer and num_priors
c. Compute prior_in_layer which is prior in id_layer
d. Using prior_in_layer to get the original value of hw. hw = priors_in_layer / num_anchors_layer. And correspondingly anchor = priors_in_layer % num_anchors_layer
e. C = num_anchors_layer * num_loc_classes * 4, the original value of ch can be computed using anchor, c (class), and i (box coordinate).
f. With n, hw and ch, the original index in an id_layer can be computed according to NCHW layerout
e.g. for ssd-mobilenet-v1, layer 0:
C = 12
HW = 19x19
num_anchors_layer = 3
num_loc_classes = 1 (shared)
num_priors_layer = 1083

For SSD-ResNet34, it is a bit different since reshape happens before permute
1. loc_data[id_layer] -> NCHW
2. reshape -> (N, num_loc_classes, 4,  C/num_loc_classes/4*H*W) or (N, num_loc_classes, 4, num_priors_layer)
2. permute(0,2,1) -> (N, num_loc_classes, num_priors_layer, 4)
4. concat(axis=2, num_layers) -> (N, num_loc_classes, num_priors, 4)
5. flatten -> (N, num_loc_classes*num_priors*4, 1, 1)
num_anchors_layer = C/num_loc_classes/4
num_priors_layer = num_anchors_layer*H*W = C/num_loc_classes/4*H*W
num_box_coors = 4
After concat, the num_priors_layer (id_layer=0...5) are concatenated together, so
num_priors = sum(num_priors_layer)
Correspondingly, giving an index from the result of step 5 above, the mapping process will
a. Compute its i (box corrdinate), d (prior), c (class), n (batch size) accordingly
b. Using d, find the corresponding id_layer using num_priors_layer and num_priors
c. Compute prior_in_layer which is prior in id_layer
d. Using prior_in_layer to get the original value of anchor. anchor = priors_in_layer / HW. And correspondingly hw = priors_in_layer % HW
e. C = num_loc_classes*4*num_anchors_layer, the original value of ch can be computed using c (class), i (box coordinate) and anchor.
f. With n, hw and ch, the original index in an id_layer can be computed according to NCHW layerout
(g). An alternative to step d), e), and f) is that since CHW = num_loc_classes * 4 * C/num_loc_classes/4*HW = num_loc_classes*4*num_priors_layer, the original index in NCHW layout can be computed using prior_in_layer, i (box coordinate) and c (class).

Dealing with inputs with NC/32HW32 packed layout:
This means the loc_data[id_layer] would be in NC/32HW32 format instead of NCHW. As a result, after n, ch, hw are computed, extra steps are needed to map them back to the original index:
h. packed_C = (C+31)/32
i. packed_ch = ch/32
j. packed_ch_offset = ch%32
k. Get the packed index for NC/32HW32 using h),i) and j) 


*/

template <typename T_BBOX, int NUM_LAYERS >
__device__ inline void mapLocData(const int c,
        int d, const int n,
        const T_BBOX* const* loc_data,
        const int * feature_size_pow2,
        const int * end_layer_prior,
        const int * num_anchors_data,
        const uint32_t * num_anchors_mul_data,
        const uint32_t * num_anchors_shr_data,
        const int num_loc_classes,
        T_BBOX mapped_loc_data[4],
        const bool reshape_before_permute,
        const int * box_channels,
        const int * conf_channels,
        const bool packed32_nchw
        ) {

    //find layer_id
    int start_layer_prior = 0;
    int prior_in_layer = 0;
    int num_anchors, num_anchors_mul, num_anchors_shr;
    int num_hw;
    int num_ch;
    const T_BBOX* loc_data_layer;

    #pragma unroll
    for(int layer = 0; layer < NUM_LAYERS; layer++) {
        if(d < end_layer_prior[layer]) {
            num_anchors = num_anchors_data[layer];
            num_anchors_mul = num_anchors_mul_data[layer];
            num_anchors_shr = num_anchors_shr_data[layer];
            num_hw = feature_size_pow2[layer];
            num_ch = box_channels[layer] + conf_channels[layer];
            prior_in_layer = d - start_layer_prior;
            loc_data_layer = loc_data[layer];
            // there should be a break here - but this would make all access to the arrays dynamic
            // due to compiler deoptimizations
            d = INT_MAX;
        }

        start_layer_prior = end_layer_prior[layer];
    }

    //Transform id_in_layer from HWC -> CHW

    if(reshape_before_permute) {
        int hw = prior_in_layer % num_hw;
        int anchor = prior_in_layer / num_hw;
    
        #pragma unroll
        for (int i = 0;i < 4;++i) {
            int ch = (c*4 + i)*num_anchors + anchor;
            int mappedIndex;
            if(packed32_nchw) {
                int packed_num_ch = (num_ch+31)/32;
                
                int packed_ch = ch >> 5; // ch/32;
                int packed_ch_offset = ch & 31; // ch%32;

                mappedIndex = ((n * packed_num_ch + packed_ch)*num_hw + hw)*32 + packed_ch_offset;
            }
            else {
                mappedIndex = (n * num_ch + ch)*num_hw + hw;
            }

            mapped_loc_data[i] = loc_data_layer[mappedIndex];
        }
    }
    else {
        //anchor = prior_in_layer % num_anchors;
        //hw = prior_in_layer / num_anchors;
        int anchor, hw;
        fast_divmod(hw, anchor, prior_in_layer, num_anchors, num_anchors_mul, num_anchors_shr);

        int ch_base = (anchor*num_loc_classes+c)*4;

    
        #pragma unroll
        for (int i = 0;i < 4;++i) {

            int ch = ch_base + i;
            int mappedIndex;
            if(packed32_nchw) {
                int packed_num_ch = (num_ch+31)/32;
                
                int packed_ch = ch >> 5; // ch/32;
                int packed_ch_offset = ch & 31; // ch%32;

                mappedIndex = ((n * packed_num_ch + packed_ch)*num_hw + hw)*32 + packed_ch_offset;
            }
            else {
                mappedIndex = (n * num_ch + ch)*num_hw + hw;
            }
            mapped_loc_data[i] = loc_data_layer[mappedIndex];
        }
    }
}

template <typename T_BBOX, unsigned nthds_per_cta, int NUM_LAYERS>
__launch_bounds__(nthds_per_cta)
    __global__ void decodeBBoxesOpt_kernel(
        const int nthreads,
        const CodeTypeSSD code_type,
        const bool variance_encoded_in_target,
        const int num_priors, const uint32_t num_priors_mul, const uint32_t num_priors_shr,
        const bool share_location,
        const int num_loc_classes, const uint32_t num_loc_classes_mul, const uint32_t num_loc_classes_shr,
        const int background_label_id,
        const bool clip_bbox,
        const T_BBOX* prior_data,
        T_BBOX* bbox_data,
        const DecodeBBoxesOptData<T_BBOX, NUM_LAYERS> decodeBBoxesOptData)
{
    for (int index = blockIdx.x * nthds_per_cta + threadIdx.x;
         index < nthreads;
         index += nthds_per_cta * gridDim.x)
    {
        const T_BBOX* const* loc_data = &decodeBBoxesOptData.loc_data[0];
        const int* feature_size_pow2 = &decodeBBoxesOptData.feature_size_pow2[0];
        const int* end_layer_prior = &decodeBBoxesOptData.end_layer_prior[0];
        const int* num_anchors = &decodeBBoxesOptData.num_anchors[0];
        const uint32_t* num_anchors_mul = &decodeBBoxesOptData.num_anchors_mul[0];
        const uint32_t* num_anchors_shr = &decodeBBoxesOptData.num_anchors_shr[0];
        const bool reshape_before_permute = decodeBBoxesOptData.reshape_before_permute;
        const bool packed32_nchw = decodeBBoxesOptData.packed32_nchw;
        const int* box_channels = &decodeBBoxesOptData.box_channels[0];
        const int* conf_channels = &decodeBBoxesOptData.conf_channels[0];

        // index has been already been divided by 4 (num_box_coors) before passed to this function
        //c = (index) % num_loc_classes;
        //d = (index / num_loc_classes) % num_priors;
        //n = (index / num_loc_classes / num_priors);
        int c, c_div, d, n;
        fast_divmod(c_div, c, index, num_loc_classes, num_loc_classes_mul, num_loc_classes_shr);
        fast_divmod(n, d, c_div, num_priors, num_priors_mul, num_priors_shr);
        

        if (!share_location && c == background_label_id)
        {
            // Ignore background class if not share_location.
            return;
        }
        const int pi = d * 4;
        const int vi = pi + num_priors * 4;

        T_BBOX locData[4];
        mapLocData<T_BBOX, NUM_LAYERS>(c, d, n, loc_data,
                                       feature_size_pow2, end_layer_prior, num_anchors, num_anchors_mul,
                                       num_anchors_shr, num_loc_classes, locData, reshape_before_permute,
                                       box_channels, conf_channels, packed32_nchw);

        if (code_type == CodeTypeSSD::CORNER)
        {
            #pragma unroll
            for (int i = 0;i < 4;++i) {
                //mapping index to original input loc_data[NUM_LAYERS]
                T_BBOX mapped_loc_data = locData[i];
                if (variance_encoded_in_target)
                {
                    // variance is encoded in target, we simply need to add the offset
                    // predictions.
                    bbox_data[index] = prior_data[pi + i] + mapped_loc_data;
                }
                else
                {
                    // variance is encoded in bbox, we need to scale the offset accordingly.
                    bbox_data[index] = prior_data[pi + i] + mapped_loc_data * prior_data[vi + i];
                }
            }
        }
        else if (code_type == CodeTypeSSD::CENTER_SIZE)
        {
            const T_BBOX p_xmin = prior_data[pi];
            const T_BBOX p_ymin = prior_data[pi + 1];
            const T_BBOX p_xmax = prior_data[pi + 2];
            const T_BBOX p_ymax = prior_data[pi + 3];
            const T_BBOX prior_width = p_xmax - p_xmin;
            const T_BBOX prior_height = p_ymax - p_ymin;
            const T_BBOX prior_center_x = (p_xmin + p_xmax) / T_BBOX(2);
            const T_BBOX prior_center_y = (p_ymin + p_ymax) / T_BBOX(2);

            //mapping index to original input loc_data[NUM_LAYERS]
            const T_BBOX xmin = locData[0];
            const T_BBOX ymin = locData[1];
            const T_BBOX xmax = locData[2];
            const T_BBOX ymax = locData[3];

            T_BBOX decode_bbox_center_x, decode_bbox_center_y;
            T_BBOX decode_bbox_width, decode_bbox_height;
            if (variance_encoded_in_target)
            {
                // variance is encoded in target, we simply need to retore the offset
                // predictions.
                decode_bbox_center_x = xmin * prior_width + prior_center_x;
                decode_bbox_center_y = ymin * prior_height + prior_center_y;
                decode_bbox_width = __expf(xmax) * prior_width;
                decode_bbox_height = __expf(ymax) * prior_height;
            }
            else
            {
                // variance is encoded in bbox, we need to scale the offset accordingly.
                decode_bbox_center_x = prior_data[vi] * xmin * prior_width + prior_center_x;
                decode_bbox_center_y = prior_data[vi + 1] * ymin * prior_height + prior_center_y;
                decode_bbox_width = __expf(prior_data[vi + 2] * xmax) * prior_width;
                decode_bbox_height = __expf(prior_data[vi + 3] * ymax) * prior_height;
            }

            bbox_data[4 * index + 0] = decode_bbox_center_x - decode_bbox_width / T_BBOX(2);
            bbox_data[4 * index + 1] = decode_bbox_center_y - decode_bbox_height / T_BBOX(2);
            bbox_data[4 * index + 2] = decode_bbox_center_x + decode_bbox_width / T_BBOX(2);
            bbox_data[4 * index + 3] = decode_bbox_center_y + decode_bbox_height / T_BBOX(2);
        }
        else if (code_type == CodeTypeSSD::CORNER_SIZE)
        {
            //mapping index to original input loc_data[NUM_LAYERS]
            const T_BBOX p_xmin = prior_data[pi];
            const T_BBOX p_ymin = prior_data[pi + 1];
            const T_BBOX p_xmax = prior_data[pi + 2];
            const T_BBOX p_ymax = prior_data[pi + 3];
            const T_BBOX prior_width = p_xmax - p_xmin;
            const T_BBOX prior_height = p_ymax - p_ymin;
            T_BBOX p_size;

            for (int i = 0;i < 4;++i) {
                T_BBOX mapped_loc_data = locData[i];

                if (i == 0 || i == 2)
                {
                    p_size = prior_width;
                }
                else
                {
                    p_size = prior_height;
                }
                if (variance_encoded_in_target)
                {
                    // variance is encoded in target, we simply need to add the offset
                    // predictions.
                    bbox_data[4 * index + i] = prior_data[pi + i] + mapped_loc_data * p_size;
                }
                else
                {
                    // variance is encoded in bbox, we need to scale the offset accordingly.
                    bbox_data[4 * index + i] = prior_data[pi + i] + mapped_loc_data * prior_data[vi + i] * p_size;
                }
            }
        }
        else if (code_type == CodeTypeSSD::TF_CENTER)
        {
            float4 prior_data_p = *((float4*)(prior_data + pi));
            const T_BBOX pXmin = prior_data_p.x;
            const T_BBOX pYmin = prior_data_p.y;
            const T_BBOX pXmax = prior_data_p.z;
            const T_BBOX pYmax = prior_data_p.w;


            const T_BBOX priorWidth = pXmax - pXmin;
            const T_BBOX priorHeight = pYmax - pYmin;
            const T_BBOX priorCenterX = (pXmin + pXmax) / T_BBOX(2);
            const T_BBOX priorCenterY = (pYmin + pYmax) / T_BBOX(2);

            const T_BBOX ymin = locData[0];
            const T_BBOX xmin = locData[1];
            const T_BBOX ymax = locData[2];
            const T_BBOX xmax = locData[3];

            T_BBOX bboxCenterX, bboxCenterY;
            T_BBOX bboxWidth, bboxHeight;

            float4 prior_data_v = *((float4*)(prior_data + vi));
            bboxCenterX = prior_data_v.x * xmin * priorWidth + priorCenterX;
            bboxCenterY = prior_data_v.y * ymin * priorHeight + priorCenterY;
            bboxWidth = __expf(prior_data_v.z * xmax) * priorWidth;
            bboxHeight = __expf(prior_data_v.w * ymax) * priorHeight;

            *((float4*)(bbox_data + 4 * index)) = make_float4(
                                                              bboxCenterX - bboxWidth / T_BBOX(2),
                                                              bboxCenterY - bboxHeight / T_BBOX(2),
                                                              bboxCenterX + bboxWidth / T_BBOX(2),
                                                              bboxCenterY + bboxHeight / T_BBOX(2)
                                                              );

        }
        else
        {
            // Unknown code type.
            assert("Unknown Box decode code type");
        }
        if (clip_bbox)
        {
            bbox_data[index] = max(min(bbox_data[index], T_BBOX(1.)), T_BBOX(0.));
        }
    }
}

template <typename T_BBOX>
ssdStatus_t decodeBBoxesOpt_gpu(
    cudaStream_t stream,
    const int nthreads,
    const CodeTypeSSD code_type,
    const bool variance_encoded_in_target,
    const int num_priors,
    const bool share_location,
    const int num_loc_classes,
    const int background_label_id,
    const bool clip_bbox,
    const void* const* loc_data,
    const void* prior_data,
    void* bbox_data,
    const int num_layers,
    const int* feature_size,
    const int* num_anchors,
    const int* box_channels,
    const int* conf_channels,
    const bool reshape_before_permute,
    const bool packed32_nchw)
{
    const int BS = 512;
    const int GS = (nthreads / 4 + BS - 1) / BS;
    if(num_layers == 6) { // handle a special case
        DecodeBBoxesOptData<T_BBOX, 6> decodeBBoxesOptData;
        decodeBBoxesOptData.reshape_before_permute = reshape_before_permute;
        decodeBBoxesOptData.packed32_nchw = packed32_nchw;
        int end_layer_prior = 0;
        for (int layer = 0;layer < num_layers;++layer) {
            end_layer_prior = end_layer_prior + num_anchors[layer] * feature_size[layer] * feature_size[layer];
            decodeBBoxesOptData.end_layer_prior[layer] = end_layer_prior;
            decodeBBoxesOptData.feature_size_pow2[layer] = feature_size[layer] * feature_size[layer];
            decodeBBoxesOptData.box_channels[layer] = box_channels[layer];
            decodeBBoxesOptData.conf_channels[layer] = conf_channels[layer];

            find_divisor(decodeBBoxesOptData.num_anchors_mul[layer], decodeBBoxesOptData.num_anchors_shr[layer], num_anchors[layer]);
        }
        std::memcpy(decodeBBoxesOptData.num_anchors, num_anchors, 6 * sizeof(int));
        std::memcpy(decodeBBoxesOptData.loc_data, loc_data, 6 * sizeof(void*));

        // determine constants for efficient integer division
        uint32_t num_loc_classes_mul, num_loc_classes_shr;
        uint32_t num_priors_mul, num_priors_shr;
        find_divisor(num_loc_classes_mul, num_loc_classes_shr, num_loc_classes);
        find_divisor(num_priors_mul, num_priors_shr, num_priors);

        decodeBBoxesOpt_kernel<T_BBOX, BS, 6><<<GS, BS, 0, stream>>>(nthreads/4, code_type, variance_encoded_in_target,
                                                                     num_priors, num_priors_mul, num_priors_shr,
                                                                     share_location,
                                                                     num_loc_classes, num_loc_classes_mul, num_loc_classes_shr,
                                                           background_label_id, clip_bbox,
                                                           (const T_BBOX*) prior_data,
                                                           (T_BBOX*) bbox_data,
                                                           decodeBBoxesOptData);
    }
    else{
        std::cerr<< "Only support numLayers == 6" << std::endl;
        return STATUS_FAILURE;
    }
        
    CSC(cudaGetLastError(), STATUS_FAILURE);
    return STATUS_SUCCESS;
}

// decodeBBoxesOpt LAUNCH CONFIG{{{
typedef ssdStatus_t (*dbbFunc)(cudaStream_t,
                               const int,
                               const CodeTypeSSD,
                               const bool,
                               const int,
                               const bool,
                               const int,
                               const int,
                               const bool,
                               const void* const*,
                               const void*,
                               void*,
                               const int,
                               const int*,
                               const int*,
                               const int*,
                               const int*,
                               const bool,
                               const bool);

struct dbbLaunchConfig
{
    DType_t t_bbox;
    dbbFunc function;

    dbbLaunchConfig(DType_t t_bbox)
        : t_bbox(t_bbox)
    {
    }
    dbbLaunchConfig(DType_t t_bbox, dbbFunc function)
        : t_bbox(t_bbox)
        , function(function)
    {
    }
    bool operator==(const dbbLaunchConfig& other)
    {
        return t_bbox == other.t_bbox;
    }
};

static std::vector<dbbLaunchConfig> dbbFuncVec;

bool decodeBBoxesOptInit()
{
    dbbFuncVec.push_back(dbbLaunchConfig(DataType::kFLOAT,
                                         decodeBBoxesOpt_gpu<float>));
    return true;
}

static bool initialized = decodeBBoxesOptInit();

//}}}

ssdStatus_t decodeBBoxesOpt(
    cudaStream_t stream,
    const int nthreads,
    const CodeTypeSSD code_type,
    const bool variance_encoded_in_target,
    const int num_priors,
    const bool share_location,
    const int num_loc_classes,
    const int background_label_id,
    const bool clip_bbox,
    const DType_t DT_BBOX,
    const void* const* loc_data,
    const void* prior_data,
    void* bbox_data,
    const int num_layers,
    const int * feature_size, 
    const int * num_anchors,
    const int * box_channels,
    const int * conf_channels,
    const bool packed32_nchw,
    const bool reshape_before_permute)
{
    dbbLaunchConfig lc = dbbLaunchConfig(DT_BBOX);
    for (unsigned i = 0; i < dbbFuncVec.size(); ++i)
    {
        if (lc == dbbFuncVec[i])
        {
            DEBUG_PRINTF("decodeBBox kernel %d\n", i);
            return dbbFuncVec[i].function(stream,
                                          nthreads,
                                          code_type,
                                          variance_encoded_in_target,
                                          num_priors,
                                          share_location,
                                          num_loc_classes,
                                          background_label_id,
                                          clip_bbox,
                                          loc_data,
                                          prior_data,
                                          bbox_data,
                                          num_layers,
                                          feature_size,
                                          num_anchors,
                                          box_channels,
                                          conf_channels,
                                          reshape_before_permute,
                                          packed32_nchw);
        }
    }
    return STATUS_BAD_PARAM;
}

} // namespace plugin
} // namespace nvinfer1
