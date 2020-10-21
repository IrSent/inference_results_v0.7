// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: object_detection/protos/multiscale_anchor_generator.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "object_detection/protos/multiscale_anchor_generator.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace object_detection {
namespace protos {
class MultiscaleAnchorGeneratorDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<MultiscaleAnchorGenerator>
     _instance;
} _MultiscaleAnchorGenerator_default_instance_;

namespace protobuf_object_5fdetection_2fprotos_2fmultiscale_5fanchor_5fgenerator_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MultiscaleAnchorGenerator, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MultiscaleAnchorGenerator, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MultiscaleAnchorGenerator, min_level_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MultiscaleAnchorGenerator, max_level_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MultiscaleAnchorGenerator, anchor_scale_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MultiscaleAnchorGenerator, aspect_ratios_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MultiscaleAnchorGenerator, scales_per_octave_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MultiscaleAnchorGenerator, normalize_coordinates_),
  1,
  2,
  3,
  ~0u,
  4,
  0,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, sizeof(MultiscaleAnchorGenerator)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_MultiscaleAnchorGenerator_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "object_detection/protos/multiscale_anchor_generator.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace
void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _MultiscaleAnchorGenerator_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_MultiscaleAnchorGenerator_default_instance_);}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n9object_detection/protos/multiscale_anc"
      "hor_generator.proto\022\027object_detection.pr"
      "otos\"\272\001\n\031MultiscaleAnchorGenerator\022\024\n\tmi"
      "n_level\030\001 \001(\005:\0013\022\024\n\tmax_level\030\002 \001(\005:\0017\022\027"
      "\n\014anchor_scale\030\003 \001(\002:\0014\022\025\n\raspect_ratios"
      "\030\004 \003(\002\022\034\n\021scales_per_octave\030\005 \001(\005:\0012\022#\n\025"
      "normalize_coordinates\030\006 \001(\010:\004true"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 273);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "object_detection/protos/multiscale_anchor_generator.proto", &protobuf_RegisterTypes);
}
} // anonymous namespace

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_object_5fdetection_2fprotos_2fmultiscale_5fanchor_5fgenerator_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MultiscaleAnchorGenerator::kMinLevelFieldNumber;
const int MultiscaleAnchorGenerator::kMaxLevelFieldNumber;
const int MultiscaleAnchorGenerator::kAnchorScaleFieldNumber;
const int MultiscaleAnchorGenerator::kAspectRatiosFieldNumber;
const int MultiscaleAnchorGenerator::kScalesPerOctaveFieldNumber;
const int MultiscaleAnchorGenerator::kNormalizeCoordinatesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MultiscaleAnchorGenerator::MultiscaleAnchorGenerator()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_object_5fdetection_2fprotos_2fmultiscale_5fanchor_5fgenerator_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:object_detection.protos.MultiscaleAnchorGenerator)
}
MultiscaleAnchorGenerator::MultiscaleAnchorGenerator(const MultiscaleAnchorGenerator& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0),
      aspect_ratios_(from.aspect_ratios_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&normalize_coordinates_, &from.normalize_coordinates_,
    static_cast<size_t>(reinterpret_cast<char*>(&scales_per_octave_) -
    reinterpret_cast<char*>(&normalize_coordinates_)) + sizeof(scales_per_octave_));
  // @@protoc_insertion_point(copy_constructor:object_detection.protos.MultiscaleAnchorGenerator)
}

void MultiscaleAnchorGenerator::SharedCtor() {
  _cached_size_ = 0;
  normalize_coordinates_ = true;
  min_level_ = 3;
  max_level_ = 7;
  anchor_scale_ = 4;
  scales_per_octave_ = 2;
}

MultiscaleAnchorGenerator::~MultiscaleAnchorGenerator() {
  // @@protoc_insertion_point(destructor:object_detection.protos.MultiscaleAnchorGenerator)
  SharedDtor();
}

void MultiscaleAnchorGenerator::SharedDtor() {
}

void MultiscaleAnchorGenerator::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MultiscaleAnchorGenerator::descriptor() {
  protobuf_object_5fdetection_2fprotos_2fmultiscale_5fanchor_5fgenerator_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_object_5fdetection_2fprotos_2fmultiscale_5fanchor_5fgenerator_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const MultiscaleAnchorGenerator& MultiscaleAnchorGenerator::default_instance() {
  protobuf_object_5fdetection_2fprotos_2fmultiscale_5fanchor_5fgenerator_2eproto::InitDefaults();
  return *internal_default_instance();
}

MultiscaleAnchorGenerator* MultiscaleAnchorGenerator::New(::google::protobuf::Arena* arena) const {
  MultiscaleAnchorGenerator* n = new MultiscaleAnchorGenerator;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MultiscaleAnchorGenerator::Clear() {
// @@protoc_insertion_point(message_clear_start:object_detection.protos.MultiscaleAnchorGenerator)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  aspect_ratios_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 31u) {
    normalize_coordinates_ = true;
    min_level_ = 3;
    max_level_ = 7;
    anchor_scale_ = 4;
    scales_per_octave_ = 2;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool MultiscaleAnchorGenerator::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:object_detection.protos.MultiscaleAnchorGenerator)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 min_level = 1 [default = 3];
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_min_level();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &min_level_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 max_level = 2 [default = 7];
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          set_has_max_level();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &max_level_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float anchor_scale = 3 [default = 4];
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(29u /* 29 & 0xFF */)) {
          set_has_anchor_scale();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &anchor_scale_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated float aspect_ratios = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(37u /* 37 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 1, 37u, input, this->mutable_aspect_ratios())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, this->mutable_aspect_ratios())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 scales_per_octave = 5 [default = 2];
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          set_has_scales_per_octave();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &scales_per_octave_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bool normalize_coordinates = 6 [default = true];
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {
          set_has_normalize_coordinates();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &normalize_coordinates_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:object_detection.protos.MultiscaleAnchorGenerator)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:object_detection.protos.MultiscaleAnchorGenerator)
  return false;
#undef DO_
}

void MultiscaleAnchorGenerator::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:object_detection.protos.MultiscaleAnchorGenerator)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 min_level = 1 [default = 3];
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->min_level(), output);
  }

  // optional int32 max_level = 2 [default = 7];
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->max_level(), output);
  }

  // optional float anchor_scale = 3 [default = 4];
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(3, this->anchor_scale(), output);
  }

  // repeated float aspect_ratios = 4;
  for (int i = 0, n = this->aspect_ratios_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(
      4, this->aspect_ratios(i), output);
  }

  // optional int32 scales_per_octave = 5 [default = 2];
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->scales_per_octave(), output);
  }

  // optional bool normalize_coordinates = 6 [default = true];
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->normalize_coordinates(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:object_detection.protos.MultiscaleAnchorGenerator)
}

::google::protobuf::uint8* MultiscaleAnchorGenerator::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:object_detection.protos.MultiscaleAnchorGenerator)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 min_level = 1 [default = 3];
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->min_level(), target);
  }

  // optional int32 max_level = 2 [default = 7];
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->max_level(), target);
  }

  // optional float anchor_scale = 3 [default = 4];
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(3, this->anchor_scale(), target);
  }

  // repeated float aspect_ratios = 4;
  target = ::google::protobuf::internal::WireFormatLite::
    WriteFloatToArray(4, this->aspect_ratios_, target);

  // optional int32 scales_per_octave = 5 [default = 2];
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->scales_per_octave(), target);
  }

  // optional bool normalize_coordinates = 6 [default = true];
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->normalize_coordinates(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:object_detection.protos.MultiscaleAnchorGenerator)
  return target;
}

size_t MultiscaleAnchorGenerator::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:object_detection.protos.MultiscaleAnchorGenerator)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated float aspect_ratios = 4;
  {
    unsigned int count = static_cast<unsigned int>(this->aspect_ratios_size());
    size_t data_size = 4UL * count;
    total_size += 1 *
                  ::google::protobuf::internal::FromIntSize(this->aspect_ratios_size());
    total_size += data_size;
  }

  if (_has_bits_[0 / 32] & 31u) {
    // optional bool normalize_coordinates = 6 [default = true];
    if (has_normalize_coordinates()) {
      total_size += 1 + 1;
    }

    // optional int32 min_level = 1 [default = 3];
    if (has_min_level()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->min_level());
    }

    // optional int32 max_level = 2 [default = 7];
    if (has_max_level()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->max_level());
    }

    // optional float anchor_scale = 3 [default = 4];
    if (has_anchor_scale()) {
      total_size += 1 + 4;
    }

    // optional int32 scales_per_octave = 5 [default = 2];
    if (has_scales_per_octave()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->scales_per_octave());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MultiscaleAnchorGenerator::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:object_detection.protos.MultiscaleAnchorGenerator)
  GOOGLE_DCHECK_NE(&from, this);
  const MultiscaleAnchorGenerator* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const MultiscaleAnchorGenerator>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:object_detection.protos.MultiscaleAnchorGenerator)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:object_detection.protos.MultiscaleAnchorGenerator)
    MergeFrom(*source);
  }
}

void MultiscaleAnchorGenerator::MergeFrom(const MultiscaleAnchorGenerator& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:object_detection.protos.MultiscaleAnchorGenerator)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  aspect_ratios_.MergeFrom(from.aspect_ratios_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 31u) {
    if (cached_has_bits & 0x00000001u) {
      normalize_coordinates_ = from.normalize_coordinates_;
    }
    if (cached_has_bits & 0x00000002u) {
      min_level_ = from.min_level_;
    }
    if (cached_has_bits & 0x00000004u) {
      max_level_ = from.max_level_;
    }
    if (cached_has_bits & 0x00000008u) {
      anchor_scale_ = from.anchor_scale_;
    }
    if (cached_has_bits & 0x00000010u) {
      scales_per_octave_ = from.scales_per_octave_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void MultiscaleAnchorGenerator::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:object_detection.protos.MultiscaleAnchorGenerator)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MultiscaleAnchorGenerator::CopyFrom(const MultiscaleAnchorGenerator& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:object_detection.protos.MultiscaleAnchorGenerator)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MultiscaleAnchorGenerator::IsInitialized() const {
  return true;
}

void MultiscaleAnchorGenerator::Swap(MultiscaleAnchorGenerator* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MultiscaleAnchorGenerator::InternalSwap(MultiscaleAnchorGenerator* other) {
  using std::swap;
  aspect_ratios_.InternalSwap(&other->aspect_ratios_);
  swap(normalize_coordinates_, other->normalize_coordinates_);
  swap(min_level_, other->min_level_);
  swap(max_level_, other->max_level_);
  swap(anchor_scale_, other->anchor_scale_);
  swap(scales_per_octave_, other->scales_per_octave_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata MultiscaleAnchorGenerator::GetMetadata() const {
  protobuf_object_5fdetection_2fprotos_2fmultiscale_5fanchor_5fgenerator_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_object_5fdetection_2fprotos_2fmultiscale_5fanchor_5fgenerator_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// MultiscaleAnchorGenerator

// optional int32 min_level = 1 [default = 3];
bool MultiscaleAnchorGenerator::has_min_level() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void MultiscaleAnchorGenerator::set_has_min_level() {
  _has_bits_[0] |= 0x00000002u;
}
void MultiscaleAnchorGenerator::clear_has_min_level() {
  _has_bits_[0] &= ~0x00000002u;
}
void MultiscaleAnchorGenerator::clear_min_level() {
  min_level_ = 3;
  clear_has_min_level();
}
::google::protobuf::int32 MultiscaleAnchorGenerator::min_level() const {
  // @@protoc_insertion_point(field_get:object_detection.protos.MultiscaleAnchorGenerator.min_level)
  return min_level_;
}
void MultiscaleAnchorGenerator::set_min_level(::google::protobuf::int32 value) {
  set_has_min_level();
  min_level_ = value;
  // @@protoc_insertion_point(field_set:object_detection.protos.MultiscaleAnchorGenerator.min_level)
}

// optional int32 max_level = 2 [default = 7];
bool MultiscaleAnchorGenerator::has_max_level() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
void MultiscaleAnchorGenerator::set_has_max_level() {
  _has_bits_[0] |= 0x00000004u;
}
void MultiscaleAnchorGenerator::clear_has_max_level() {
  _has_bits_[0] &= ~0x00000004u;
}
void MultiscaleAnchorGenerator::clear_max_level() {
  max_level_ = 7;
  clear_has_max_level();
}
::google::protobuf::int32 MultiscaleAnchorGenerator::max_level() const {
  // @@protoc_insertion_point(field_get:object_detection.protos.MultiscaleAnchorGenerator.max_level)
  return max_level_;
}
void MultiscaleAnchorGenerator::set_max_level(::google::protobuf::int32 value) {
  set_has_max_level();
  max_level_ = value;
  // @@protoc_insertion_point(field_set:object_detection.protos.MultiscaleAnchorGenerator.max_level)
}

// optional float anchor_scale = 3 [default = 4];
bool MultiscaleAnchorGenerator::has_anchor_scale() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
void MultiscaleAnchorGenerator::set_has_anchor_scale() {
  _has_bits_[0] |= 0x00000008u;
}
void MultiscaleAnchorGenerator::clear_has_anchor_scale() {
  _has_bits_[0] &= ~0x00000008u;
}
void MultiscaleAnchorGenerator::clear_anchor_scale() {
  anchor_scale_ = 4;
  clear_has_anchor_scale();
}
float MultiscaleAnchorGenerator::anchor_scale() const {
  // @@protoc_insertion_point(field_get:object_detection.protos.MultiscaleAnchorGenerator.anchor_scale)
  return anchor_scale_;
}
void MultiscaleAnchorGenerator::set_anchor_scale(float value) {
  set_has_anchor_scale();
  anchor_scale_ = value;
  // @@protoc_insertion_point(field_set:object_detection.protos.MultiscaleAnchorGenerator.anchor_scale)
}

// repeated float aspect_ratios = 4;
int MultiscaleAnchorGenerator::aspect_ratios_size() const {
  return aspect_ratios_.size();
}
void MultiscaleAnchorGenerator::clear_aspect_ratios() {
  aspect_ratios_.Clear();
}
float MultiscaleAnchorGenerator::aspect_ratios(int index) const {
  // @@protoc_insertion_point(field_get:object_detection.protos.MultiscaleAnchorGenerator.aspect_ratios)
  return aspect_ratios_.Get(index);
}
void MultiscaleAnchorGenerator::set_aspect_ratios(int index, float value) {
  aspect_ratios_.Set(index, value);
  // @@protoc_insertion_point(field_set:object_detection.protos.MultiscaleAnchorGenerator.aspect_ratios)
}
void MultiscaleAnchorGenerator::add_aspect_ratios(float value) {
  aspect_ratios_.Add(value);
  // @@protoc_insertion_point(field_add:object_detection.protos.MultiscaleAnchorGenerator.aspect_ratios)
}
const ::google::protobuf::RepeatedField< float >&
MultiscaleAnchorGenerator::aspect_ratios() const {
  // @@protoc_insertion_point(field_list:object_detection.protos.MultiscaleAnchorGenerator.aspect_ratios)
  return aspect_ratios_;
}
::google::protobuf::RepeatedField< float >*
MultiscaleAnchorGenerator::mutable_aspect_ratios() {
  // @@protoc_insertion_point(field_mutable_list:object_detection.protos.MultiscaleAnchorGenerator.aspect_ratios)
  return &aspect_ratios_;
}

// optional int32 scales_per_octave = 5 [default = 2];
bool MultiscaleAnchorGenerator::has_scales_per_octave() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
void MultiscaleAnchorGenerator::set_has_scales_per_octave() {
  _has_bits_[0] |= 0x00000010u;
}
void MultiscaleAnchorGenerator::clear_has_scales_per_octave() {
  _has_bits_[0] &= ~0x00000010u;
}
void MultiscaleAnchorGenerator::clear_scales_per_octave() {
  scales_per_octave_ = 2;
  clear_has_scales_per_octave();
}
::google::protobuf::int32 MultiscaleAnchorGenerator::scales_per_octave() const {
  // @@protoc_insertion_point(field_get:object_detection.protos.MultiscaleAnchorGenerator.scales_per_octave)
  return scales_per_octave_;
}
void MultiscaleAnchorGenerator::set_scales_per_octave(::google::protobuf::int32 value) {
  set_has_scales_per_octave();
  scales_per_octave_ = value;
  // @@protoc_insertion_point(field_set:object_detection.protos.MultiscaleAnchorGenerator.scales_per_octave)
}

// optional bool normalize_coordinates = 6 [default = true];
bool MultiscaleAnchorGenerator::has_normalize_coordinates() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void MultiscaleAnchorGenerator::set_has_normalize_coordinates() {
  _has_bits_[0] |= 0x00000001u;
}
void MultiscaleAnchorGenerator::clear_has_normalize_coordinates() {
  _has_bits_[0] &= ~0x00000001u;
}
void MultiscaleAnchorGenerator::clear_normalize_coordinates() {
  normalize_coordinates_ = true;
  clear_has_normalize_coordinates();
}
bool MultiscaleAnchorGenerator::normalize_coordinates() const {
  // @@protoc_insertion_point(field_get:object_detection.protos.MultiscaleAnchorGenerator.normalize_coordinates)
  return normalize_coordinates_;
}
void MultiscaleAnchorGenerator::set_normalize_coordinates(bool value) {
  set_has_normalize_coordinates();
  normalize_coordinates_ = value;
  // @@protoc_insertion_point(field_set:object_detection.protos.MultiscaleAnchorGenerator.normalize_coordinates)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace protos
}  // namespace object_detection

// @@protoc_insertion_point(global_scope)
