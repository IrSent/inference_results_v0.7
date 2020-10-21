// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: object_detection/protos/argmax_matcher.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "object_detection/protos/argmax_matcher.pb.h"

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
class ArgMaxMatcherDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<ArgMaxMatcher>
     _instance;
} _ArgMaxMatcher_default_instance_;

namespace protobuf_object_5fdetection_2fprotos_2fargmax_5fmatcher_2eproto {


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
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArgMaxMatcher, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArgMaxMatcher, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArgMaxMatcher, matched_threshold_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArgMaxMatcher, unmatched_threshold_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArgMaxMatcher, ignore_thresholds_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArgMaxMatcher, negatives_lower_than_unmatched_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArgMaxMatcher, force_match_for_each_row_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArgMaxMatcher, use_matmul_gather_),
  4,
  5,
  0,
  3,
  1,
  2,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, sizeof(ArgMaxMatcher)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_ArgMaxMatcher_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "object_detection/protos/argmax_matcher.proto", schemas, file_default_instances, TableStruct::offsets, factory,
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
  _ArgMaxMatcher_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_ArgMaxMatcher_default_instance_);}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n,object_detection/protos/argmax_matcher"
      ".proto\022\027object_detection.protos\"\354\001\n\rArgM"
      "axMatcher\022\036\n\021matched_threshold\030\001 \001(\002:\0030."
      "5\022 \n\023unmatched_threshold\030\002 \001(\002:\0030.5\022 \n\021i"
      "gnore_thresholds\030\003 \001(\010:\005false\022,\n\036negativ"
      "es_lower_than_unmatched\030\004 \001(\010:\004true\022\'\n\030f"
      "orce_match_for_each_row\030\005 \001(\010:\005false\022 \n\021"
      "use_matmul_gather\030\006 \001(\010:\005false"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 310);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "object_detection/protos/argmax_matcher.proto", &protobuf_RegisterTypes);
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

}  // namespace protobuf_object_5fdetection_2fprotos_2fargmax_5fmatcher_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ArgMaxMatcher::kMatchedThresholdFieldNumber;
const int ArgMaxMatcher::kUnmatchedThresholdFieldNumber;
const int ArgMaxMatcher::kIgnoreThresholdsFieldNumber;
const int ArgMaxMatcher::kNegativesLowerThanUnmatchedFieldNumber;
const int ArgMaxMatcher::kForceMatchForEachRowFieldNumber;
const int ArgMaxMatcher::kUseMatmulGatherFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ArgMaxMatcher::ArgMaxMatcher()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_object_5fdetection_2fprotos_2fargmax_5fmatcher_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:object_detection.protos.ArgMaxMatcher)
}
ArgMaxMatcher::ArgMaxMatcher(const ArgMaxMatcher& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&ignore_thresholds_, &from.ignore_thresholds_,
    static_cast<size_t>(reinterpret_cast<char*>(&unmatched_threshold_) -
    reinterpret_cast<char*>(&ignore_thresholds_)) + sizeof(unmatched_threshold_));
  // @@protoc_insertion_point(copy_constructor:object_detection.protos.ArgMaxMatcher)
}

void ArgMaxMatcher::SharedCtor() {
  _cached_size_ = 0;
  ::memset(&ignore_thresholds_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&use_matmul_gather_) -
      reinterpret_cast<char*>(&ignore_thresholds_)) + sizeof(use_matmul_gather_));
  negatives_lower_than_unmatched_ = true;
  matched_threshold_ = 0.5f;
  unmatched_threshold_ = 0.5f;
}

ArgMaxMatcher::~ArgMaxMatcher() {
  // @@protoc_insertion_point(destructor:object_detection.protos.ArgMaxMatcher)
  SharedDtor();
}

void ArgMaxMatcher::SharedDtor() {
}

void ArgMaxMatcher::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ArgMaxMatcher::descriptor() {
  protobuf_object_5fdetection_2fprotos_2fargmax_5fmatcher_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_object_5fdetection_2fprotos_2fargmax_5fmatcher_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ArgMaxMatcher& ArgMaxMatcher::default_instance() {
  protobuf_object_5fdetection_2fprotos_2fargmax_5fmatcher_2eproto::InitDefaults();
  return *internal_default_instance();
}

ArgMaxMatcher* ArgMaxMatcher::New(::google::protobuf::Arena* arena) const {
  ArgMaxMatcher* n = new ArgMaxMatcher;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ArgMaxMatcher::Clear() {
// @@protoc_insertion_point(message_clear_start:object_detection.protos.ArgMaxMatcher)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 63u) {
    ::memset(&ignore_thresholds_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&use_matmul_gather_) -
        reinterpret_cast<char*>(&ignore_thresholds_)) + sizeof(use_matmul_gather_));
    negatives_lower_than_unmatched_ = true;
    matched_threshold_ = 0.5f;
    unmatched_threshold_ = 0.5f;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ArgMaxMatcher::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:object_detection.protos.ArgMaxMatcher)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional float matched_threshold = 1 [default = 0.5];
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(13u /* 13 & 0xFF */)) {
          set_has_matched_threshold();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &matched_threshold_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float unmatched_threshold = 2 [default = 0.5];
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(21u /* 21 & 0xFF */)) {
          set_has_unmatched_threshold();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &unmatched_threshold_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bool ignore_thresholds = 3 [default = false];
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          set_has_ignore_thresholds();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &ignore_thresholds_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bool negatives_lower_than_unmatched = 4 [default = true];
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          set_has_negatives_lower_than_unmatched();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &negatives_lower_than_unmatched_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bool force_match_for_each_row = 5 [default = false];
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          set_has_force_match_for_each_row();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &force_match_for_each_row_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bool use_matmul_gather = 6 [default = false];
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {
          set_has_use_matmul_gather();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &use_matmul_gather_)));
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
  // @@protoc_insertion_point(parse_success:object_detection.protos.ArgMaxMatcher)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:object_detection.protos.ArgMaxMatcher)
  return false;
#undef DO_
}

void ArgMaxMatcher::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:object_detection.protos.ArgMaxMatcher)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional float matched_threshold = 1 [default = 0.5];
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(1, this->matched_threshold(), output);
  }

  // optional float unmatched_threshold = 2 [default = 0.5];
  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(2, this->unmatched_threshold(), output);
  }

  // optional bool ignore_thresholds = 3 [default = false];
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->ignore_thresholds(), output);
  }

  // optional bool negatives_lower_than_unmatched = 4 [default = true];
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->negatives_lower_than_unmatched(), output);
  }

  // optional bool force_match_for_each_row = 5 [default = false];
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->force_match_for_each_row(), output);
  }

  // optional bool use_matmul_gather = 6 [default = false];
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->use_matmul_gather(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:object_detection.protos.ArgMaxMatcher)
}

::google::protobuf::uint8* ArgMaxMatcher::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:object_detection.protos.ArgMaxMatcher)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional float matched_threshold = 1 [default = 0.5];
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(1, this->matched_threshold(), target);
  }

  // optional float unmatched_threshold = 2 [default = 0.5];
  if (cached_has_bits & 0x00000020u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(2, this->unmatched_threshold(), target);
  }

  // optional bool ignore_thresholds = 3 [default = false];
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->ignore_thresholds(), target);
  }

  // optional bool negatives_lower_than_unmatched = 4 [default = true];
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->negatives_lower_than_unmatched(), target);
  }

  // optional bool force_match_for_each_row = 5 [default = false];
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->force_match_for_each_row(), target);
  }

  // optional bool use_matmul_gather = 6 [default = false];
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->use_matmul_gather(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:object_detection.protos.ArgMaxMatcher)
  return target;
}

size_t ArgMaxMatcher::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:object_detection.protos.ArgMaxMatcher)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (_has_bits_[0 / 32] & 63u) {
    // optional bool ignore_thresholds = 3 [default = false];
    if (has_ignore_thresholds()) {
      total_size += 1 + 1;
    }

    // optional bool force_match_for_each_row = 5 [default = false];
    if (has_force_match_for_each_row()) {
      total_size += 1 + 1;
    }

    // optional bool use_matmul_gather = 6 [default = false];
    if (has_use_matmul_gather()) {
      total_size += 1 + 1;
    }

    // optional bool negatives_lower_than_unmatched = 4 [default = true];
    if (has_negatives_lower_than_unmatched()) {
      total_size += 1 + 1;
    }

    // optional float matched_threshold = 1 [default = 0.5];
    if (has_matched_threshold()) {
      total_size += 1 + 4;
    }

    // optional float unmatched_threshold = 2 [default = 0.5];
    if (has_unmatched_threshold()) {
      total_size += 1 + 4;
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ArgMaxMatcher::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:object_detection.protos.ArgMaxMatcher)
  GOOGLE_DCHECK_NE(&from, this);
  const ArgMaxMatcher* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ArgMaxMatcher>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:object_detection.protos.ArgMaxMatcher)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:object_detection.protos.ArgMaxMatcher)
    MergeFrom(*source);
  }
}

void ArgMaxMatcher::MergeFrom(const ArgMaxMatcher& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:object_detection.protos.ArgMaxMatcher)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 63u) {
    if (cached_has_bits & 0x00000001u) {
      ignore_thresholds_ = from.ignore_thresholds_;
    }
    if (cached_has_bits & 0x00000002u) {
      force_match_for_each_row_ = from.force_match_for_each_row_;
    }
    if (cached_has_bits & 0x00000004u) {
      use_matmul_gather_ = from.use_matmul_gather_;
    }
    if (cached_has_bits & 0x00000008u) {
      negatives_lower_than_unmatched_ = from.negatives_lower_than_unmatched_;
    }
    if (cached_has_bits & 0x00000010u) {
      matched_threshold_ = from.matched_threshold_;
    }
    if (cached_has_bits & 0x00000020u) {
      unmatched_threshold_ = from.unmatched_threshold_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ArgMaxMatcher::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:object_detection.protos.ArgMaxMatcher)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArgMaxMatcher::CopyFrom(const ArgMaxMatcher& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:object_detection.protos.ArgMaxMatcher)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArgMaxMatcher::IsInitialized() const {
  return true;
}

void ArgMaxMatcher::Swap(ArgMaxMatcher* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ArgMaxMatcher::InternalSwap(ArgMaxMatcher* other) {
  using std::swap;
  swap(ignore_thresholds_, other->ignore_thresholds_);
  swap(force_match_for_each_row_, other->force_match_for_each_row_);
  swap(use_matmul_gather_, other->use_matmul_gather_);
  swap(negatives_lower_than_unmatched_, other->negatives_lower_than_unmatched_);
  swap(matched_threshold_, other->matched_threshold_);
  swap(unmatched_threshold_, other->unmatched_threshold_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ArgMaxMatcher::GetMetadata() const {
  protobuf_object_5fdetection_2fprotos_2fargmax_5fmatcher_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_object_5fdetection_2fprotos_2fargmax_5fmatcher_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ArgMaxMatcher

// optional float matched_threshold = 1 [default = 0.5];
bool ArgMaxMatcher::has_matched_threshold() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
void ArgMaxMatcher::set_has_matched_threshold() {
  _has_bits_[0] |= 0x00000010u;
}
void ArgMaxMatcher::clear_has_matched_threshold() {
  _has_bits_[0] &= ~0x00000010u;
}
void ArgMaxMatcher::clear_matched_threshold() {
  matched_threshold_ = 0.5f;
  clear_has_matched_threshold();
}
float ArgMaxMatcher::matched_threshold() const {
  // @@protoc_insertion_point(field_get:object_detection.protos.ArgMaxMatcher.matched_threshold)
  return matched_threshold_;
}
void ArgMaxMatcher::set_matched_threshold(float value) {
  set_has_matched_threshold();
  matched_threshold_ = value;
  // @@protoc_insertion_point(field_set:object_detection.protos.ArgMaxMatcher.matched_threshold)
}

// optional float unmatched_threshold = 2 [default = 0.5];
bool ArgMaxMatcher::has_unmatched_threshold() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
void ArgMaxMatcher::set_has_unmatched_threshold() {
  _has_bits_[0] |= 0x00000020u;
}
void ArgMaxMatcher::clear_has_unmatched_threshold() {
  _has_bits_[0] &= ~0x00000020u;
}
void ArgMaxMatcher::clear_unmatched_threshold() {
  unmatched_threshold_ = 0.5f;
  clear_has_unmatched_threshold();
}
float ArgMaxMatcher::unmatched_threshold() const {
  // @@protoc_insertion_point(field_get:object_detection.protos.ArgMaxMatcher.unmatched_threshold)
  return unmatched_threshold_;
}
void ArgMaxMatcher::set_unmatched_threshold(float value) {
  set_has_unmatched_threshold();
  unmatched_threshold_ = value;
  // @@protoc_insertion_point(field_set:object_detection.protos.ArgMaxMatcher.unmatched_threshold)
}

// optional bool ignore_thresholds = 3 [default = false];
bool ArgMaxMatcher::has_ignore_thresholds() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void ArgMaxMatcher::set_has_ignore_thresholds() {
  _has_bits_[0] |= 0x00000001u;
}
void ArgMaxMatcher::clear_has_ignore_thresholds() {
  _has_bits_[0] &= ~0x00000001u;
}
void ArgMaxMatcher::clear_ignore_thresholds() {
  ignore_thresholds_ = false;
  clear_has_ignore_thresholds();
}
bool ArgMaxMatcher::ignore_thresholds() const {
  // @@protoc_insertion_point(field_get:object_detection.protos.ArgMaxMatcher.ignore_thresholds)
  return ignore_thresholds_;
}
void ArgMaxMatcher::set_ignore_thresholds(bool value) {
  set_has_ignore_thresholds();
  ignore_thresholds_ = value;
  // @@protoc_insertion_point(field_set:object_detection.protos.ArgMaxMatcher.ignore_thresholds)
}

// optional bool negatives_lower_than_unmatched = 4 [default = true];
bool ArgMaxMatcher::has_negatives_lower_than_unmatched() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
void ArgMaxMatcher::set_has_negatives_lower_than_unmatched() {
  _has_bits_[0] |= 0x00000008u;
}
void ArgMaxMatcher::clear_has_negatives_lower_than_unmatched() {
  _has_bits_[0] &= ~0x00000008u;
}
void ArgMaxMatcher::clear_negatives_lower_than_unmatched() {
  negatives_lower_than_unmatched_ = true;
  clear_has_negatives_lower_than_unmatched();
}
bool ArgMaxMatcher::negatives_lower_than_unmatched() const {
  // @@protoc_insertion_point(field_get:object_detection.protos.ArgMaxMatcher.negatives_lower_than_unmatched)
  return negatives_lower_than_unmatched_;
}
void ArgMaxMatcher::set_negatives_lower_than_unmatched(bool value) {
  set_has_negatives_lower_than_unmatched();
  negatives_lower_than_unmatched_ = value;
  // @@protoc_insertion_point(field_set:object_detection.protos.ArgMaxMatcher.negatives_lower_than_unmatched)
}

// optional bool force_match_for_each_row = 5 [default = false];
bool ArgMaxMatcher::has_force_match_for_each_row() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void ArgMaxMatcher::set_has_force_match_for_each_row() {
  _has_bits_[0] |= 0x00000002u;
}
void ArgMaxMatcher::clear_has_force_match_for_each_row() {
  _has_bits_[0] &= ~0x00000002u;
}
void ArgMaxMatcher::clear_force_match_for_each_row() {
  force_match_for_each_row_ = false;
  clear_has_force_match_for_each_row();
}
bool ArgMaxMatcher::force_match_for_each_row() const {
  // @@protoc_insertion_point(field_get:object_detection.protos.ArgMaxMatcher.force_match_for_each_row)
  return force_match_for_each_row_;
}
void ArgMaxMatcher::set_force_match_for_each_row(bool value) {
  set_has_force_match_for_each_row();
  force_match_for_each_row_ = value;
  // @@protoc_insertion_point(field_set:object_detection.protos.ArgMaxMatcher.force_match_for_each_row)
}

// optional bool use_matmul_gather = 6 [default = false];
bool ArgMaxMatcher::has_use_matmul_gather() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
void ArgMaxMatcher::set_has_use_matmul_gather() {
  _has_bits_[0] |= 0x00000004u;
}
void ArgMaxMatcher::clear_has_use_matmul_gather() {
  _has_bits_[0] &= ~0x00000004u;
}
void ArgMaxMatcher::clear_use_matmul_gather() {
  use_matmul_gather_ = false;
  clear_has_use_matmul_gather();
}
bool ArgMaxMatcher::use_matmul_gather() const {
  // @@protoc_insertion_point(field_get:object_detection.protos.ArgMaxMatcher.use_matmul_gather)
  return use_matmul_gather_;
}
void ArgMaxMatcher::set_use_matmul_gather(bool value) {
  set_has_use_matmul_gather();
  use_matmul_gather_ = value;
  // @@protoc_insertion_point(field_set:object_detection.protos.ArgMaxMatcher.use_matmul_gather)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace protos
}  // namespace object_detection

// @@protoc_insertion_point(global_scope)
