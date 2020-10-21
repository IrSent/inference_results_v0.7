/*
 * Copyright 2019 Xilinx Inc.
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
#ifndef DEEPHI_MULTISCALEANCHOR_HPP_
#define DEEPHI_MULTISCALEANCHOR_HPP_

#include <vector>
#include <memory>
#include <utility>

#include "anchorbase.hpp"

namespace vitis {
namespace ai {
namespace dptfssd {

class MultiscaleAnchor : public AnchorBase{

 public:
   MultiscaleAnchor(
                       int min_level,
                       int max_level,
                       float anchor_scale,
                       int scales_per_octave,
                       const std::vector<int>& feature_map_list,
                       const std::vector<float>& aspect_ratios,
                       int image_width,
                       int image_height);

};

}  // namespace dpssd
}  // namespace ai
}  // namespace vitis

#endif
