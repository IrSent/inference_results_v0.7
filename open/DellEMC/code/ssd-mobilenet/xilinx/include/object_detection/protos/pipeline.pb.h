// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: object_detection/protos/pipeline.proto

#ifndef PROTOBUF_object_5fdetection_2fprotos_2fpipeline_2eproto__INCLUDED
#define PROTOBUF_object_5fdetection_2fprotos_2fpipeline_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "object_detection/protos/eval.pb.h"
#include "object_detection/protos/graph_rewriter.pb.h"
#include "object_detection/protos/input_reader.pb.h"
#include "object_detection/protos/model.pb.h"
#include "object_detection/protos/train.pb.h"
// @@protoc_insertion_point(includes)
namespace object_detection {
namespace protos {
class TrainEvalPipelineConfig;
class TrainEvalPipelineConfigDefaultTypeInternal;
extern TrainEvalPipelineConfigDefaultTypeInternal _TrainEvalPipelineConfig_default_instance_;
}  // namespace protos
}  // namespace object_detection

namespace object_detection {
namespace protos {

namespace protobuf_object_5fdetection_2fprotos_2fpipeline_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_object_5fdetection_2fprotos_2fpipeline_2eproto

// ===================================================================

class TrainEvalPipelineConfig : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:object_detection.protos.TrainEvalPipelineConfig) */ {
 public:
  TrainEvalPipelineConfig();
  virtual ~TrainEvalPipelineConfig();

  TrainEvalPipelineConfig(const TrainEvalPipelineConfig& from);

  inline TrainEvalPipelineConfig& operator=(const TrainEvalPipelineConfig& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  TrainEvalPipelineConfig(TrainEvalPipelineConfig&& from) noexcept
    : TrainEvalPipelineConfig() {
    *this = ::std::move(from);
  }

  inline TrainEvalPipelineConfig& operator=(TrainEvalPipelineConfig&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TrainEvalPipelineConfig& default_instance();

  static inline const TrainEvalPipelineConfig* internal_default_instance() {
    return reinterpret_cast<const TrainEvalPipelineConfig*>(
               &_TrainEvalPipelineConfig_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(TrainEvalPipelineConfig* other);
  friend void swap(TrainEvalPipelineConfig& a, TrainEvalPipelineConfig& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline TrainEvalPipelineConfig* New() const PROTOBUF_FINAL { return New(NULL); }

  TrainEvalPipelineConfig* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const TrainEvalPipelineConfig& from);
  void MergeFrom(const TrainEvalPipelineConfig& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(TrainEvalPipelineConfig* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .object_detection.protos.InputReader eval_input_reader = 5;
  int eval_input_reader_size() const;
  void clear_eval_input_reader();
  static const int kEvalInputReaderFieldNumber = 5;
  const ::object_detection::protos::InputReader& eval_input_reader(int index) const;
  ::object_detection::protos::InputReader* mutable_eval_input_reader(int index);
  ::object_detection::protos::InputReader* add_eval_input_reader();
  ::google::protobuf::RepeatedPtrField< ::object_detection::protos::InputReader >*
      mutable_eval_input_reader();
  const ::google::protobuf::RepeatedPtrField< ::object_detection::protos::InputReader >&
      eval_input_reader() const;

  // optional .object_detection.protos.DetectionModel model = 1;
  bool has_model() const;
  void clear_model();
  static const int kModelFieldNumber = 1;
  const ::object_detection::protos::DetectionModel& model() const;
  ::object_detection::protos::DetectionModel* mutable_model();
  ::object_detection::protos::DetectionModel* release_model();
  void set_allocated_model(::object_detection::protos::DetectionModel* model);

  // optional .object_detection.protos.TrainConfig train_config = 2;
  bool has_train_config() const;
  void clear_train_config();
  static const int kTrainConfigFieldNumber = 2;
  const ::object_detection::protos::TrainConfig& train_config() const;
  ::object_detection::protos::TrainConfig* mutable_train_config();
  ::object_detection::protos::TrainConfig* release_train_config();
  void set_allocated_train_config(::object_detection::protos::TrainConfig* train_config);

  // optional .object_detection.protos.InputReader train_input_reader = 3;
  bool has_train_input_reader() const;
  void clear_train_input_reader();
  static const int kTrainInputReaderFieldNumber = 3;
  const ::object_detection::protos::InputReader& train_input_reader() const;
  ::object_detection::protos::InputReader* mutable_train_input_reader();
  ::object_detection::protos::InputReader* release_train_input_reader();
  void set_allocated_train_input_reader(::object_detection::protos::InputReader* train_input_reader);

  // optional .object_detection.protos.EvalConfig eval_config = 4;
  bool has_eval_config() const;
  void clear_eval_config();
  static const int kEvalConfigFieldNumber = 4;
  const ::object_detection::protos::EvalConfig& eval_config() const;
  ::object_detection::protos::EvalConfig* mutable_eval_config();
  ::object_detection::protos::EvalConfig* release_eval_config();
  void set_allocated_eval_config(::object_detection::protos::EvalConfig* eval_config);

  // optional .object_detection.protos.GraphRewriter graph_rewriter = 6;
  bool has_graph_rewriter() const;
  void clear_graph_rewriter();
  static const int kGraphRewriterFieldNumber = 6;
  const ::object_detection::protos::GraphRewriter& graph_rewriter() const;
  ::object_detection::protos::GraphRewriter* mutable_graph_rewriter();
  ::object_detection::protos::GraphRewriter* release_graph_rewriter();
  void set_allocated_graph_rewriter(::object_detection::protos::GraphRewriter* graph_rewriter);

  GOOGLE_PROTOBUF_EXTENSION_ACCESSORS(TrainEvalPipelineConfig)
  // @@protoc_insertion_point(class_scope:object_detection.protos.TrainEvalPipelineConfig)
 private:
  void set_has_model();
  void clear_has_model();
  void set_has_train_config();
  void clear_has_train_config();
  void set_has_train_input_reader();
  void clear_has_train_input_reader();
  void set_has_eval_config();
  void clear_has_eval_config();
  void set_has_graph_rewriter();
  void clear_has_graph_rewriter();

  ::google::protobuf::internal::ExtensionSet _extensions_;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::object_detection::protos::InputReader > eval_input_reader_;
  ::object_detection::protos::DetectionModel* model_;
  ::object_detection::protos::TrainConfig* train_config_;
  ::object_detection::protos::InputReader* train_input_reader_;
  ::object_detection::protos::EvalConfig* eval_config_;
  ::object_detection::protos::GraphRewriter* graph_rewriter_;
  friend struct protobuf_object_5fdetection_2fprotos_2fpipeline_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TrainEvalPipelineConfig

// optional .object_detection.protos.DetectionModel model = 1;
inline bool TrainEvalPipelineConfig::has_model() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TrainEvalPipelineConfig::set_has_model() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TrainEvalPipelineConfig::clear_has_model() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TrainEvalPipelineConfig::clear_model() {
  if (model_ != NULL) model_->::object_detection::protos::DetectionModel::Clear();
  clear_has_model();
}
inline const ::object_detection::protos::DetectionModel& TrainEvalPipelineConfig::model() const {
  const ::object_detection::protos::DetectionModel* p = model_;
  // @@protoc_insertion_point(field_get:object_detection.protos.TrainEvalPipelineConfig.model)
  return p != NULL ? *p : *reinterpret_cast<const ::object_detection::protos::DetectionModel*>(
      &::object_detection::protos::_DetectionModel_default_instance_);
}
inline ::object_detection::protos::DetectionModel* TrainEvalPipelineConfig::mutable_model() {
  set_has_model();
  if (model_ == NULL) {
    model_ = new ::object_detection::protos::DetectionModel;
  }
  // @@protoc_insertion_point(field_mutable:object_detection.protos.TrainEvalPipelineConfig.model)
  return model_;
}
inline ::object_detection::protos::DetectionModel* TrainEvalPipelineConfig::release_model() {
  // @@protoc_insertion_point(field_release:object_detection.protos.TrainEvalPipelineConfig.model)
  clear_has_model();
  ::object_detection::protos::DetectionModel* temp = model_;
  model_ = NULL;
  return temp;
}
inline void TrainEvalPipelineConfig::set_allocated_model(::object_detection::protos::DetectionModel* model) {
  delete model_;
  model_ = model;
  if (model) {
    set_has_model();
  } else {
    clear_has_model();
  }
  // @@protoc_insertion_point(field_set_allocated:object_detection.protos.TrainEvalPipelineConfig.model)
}

// optional .object_detection.protos.TrainConfig train_config = 2;
inline bool TrainEvalPipelineConfig::has_train_config() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TrainEvalPipelineConfig::set_has_train_config() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TrainEvalPipelineConfig::clear_has_train_config() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TrainEvalPipelineConfig::clear_train_config() {
  if (train_config_ != NULL) train_config_->::object_detection::protos::TrainConfig::Clear();
  clear_has_train_config();
}
inline const ::object_detection::protos::TrainConfig& TrainEvalPipelineConfig::train_config() const {
  const ::object_detection::protos::TrainConfig* p = train_config_;
  // @@protoc_insertion_point(field_get:object_detection.protos.TrainEvalPipelineConfig.train_config)
  return p != NULL ? *p : *reinterpret_cast<const ::object_detection::protos::TrainConfig*>(
      &::object_detection::protos::_TrainConfig_default_instance_);
}
inline ::object_detection::protos::TrainConfig* TrainEvalPipelineConfig::mutable_train_config() {
  set_has_train_config();
  if (train_config_ == NULL) {
    train_config_ = new ::object_detection::protos::TrainConfig;
  }
  // @@protoc_insertion_point(field_mutable:object_detection.protos.TrainEvalPipelineConfig.train_config)
  return train_config_;
}
inline ::object_detection::protos::TrainConfig* TrainEvalPipelineConfig::release_train_config() {
  // @@protoc_insertion_point(field_release:object_detection.protos.TrainEvalPipelineConfig.train_config)
  clear_has_train_config();
  ::object_detection::protos::TrainConfig* temp = train_config_;
  train_config_ = NULL;
  return temp;
}
inline void TrainEvalPipelineConfig::set_allocated_train_config(::object_detection::protos::TrainConfig* train_config) {
  delete train_config_;
  train_config_ = train_config;
  if (train_config) {
    set_has_train_config();
  } else {
    clear_has_train_config();
  }
  // @@protoc_insertion_point(field_set_allocated:object_detection.protos.TrainEvalPipelineConfig.train_config)
}

// optional .object_detection.protos.InputReader train_input_reader = 3;
inline bool TrainEvalPipelineConfig::has_train_input_reader() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void TrainEvalPipelineConfig::set_has_train_input_reader() {
  _has_bits_[0] |= 0x00000004u;
}
inline void TrainEvalPipelineConfig::clear_has_train_input_reader() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void TrainEvalPipelineConfig::clear_train_input_reader() {
  if (train_input_reader_ != NULL) train_input_reader_->::object_detection::protos::InputReader::Clear();
  clear_has_train_input_reader();
}
inline const ::object_detection::protos::InputReader& TrainEvalPipelineConfig::train_input_reader() const {
  const ::object_detection::protos::InputReader* p = train_input_reader_;
  // @@protoc_insertion_point(field_get:object_detection.protos.TrainEvalPipelineConfig.train_input_reader)
  return p != NULL ? *p : *reinterpret_cast<const ::object_detection::protos::InputReader*>(
      &::object_detection::protos::_InputReader_default_instance_);
}
inline ::object_detection::protos::InputReader* TrainEvalPipelineConfig::mutable_train_input_reader() {
  set_has_train_input_reader();
  if (train_input_reader_ == NULL) {
    train_input_reader_ = new ::object_detection::protos::InputReader;
  }
  // @@protoc_insertion_point(field_mutable:object_detection.protos.TrainEvalPipelineConfig.train_input_reader)
  return train_input_reader_;
}
inline ::object_detection::protos::InputReader* TrainEvalPipelineConfig::release_train_input_reader() {
  // @@protoc_insertion_point(field_release:object_detection.protos.TrainEvalPipelineConfig.train_input_reader)
  clear_has_train_input_reader();
  ::object_detection::protos::InputReader* temp = train_input_reader_;
  train_input_reader_ = NULL;
  return temp;
}
inline void TrainEvalPipelineConfig::set_allocated_train_input_reader(::object_detection::protos::InputReader* train_input_reader) {
  delete train_input_reader_;
  train_input_reader_ = train_input_reader;
  if (train_input_reader) {
    set_has_train_input_reader();
  } else {
    clear_has_train_input_reader();
  }
  // @@protoc_insertion_point(field_set_allocated:object_detection.protos.TrainEvalPipelineConfig.train_input_reader)
}

// optional .object_detection.protos.EvalConfig eval_config = 4;
inline bool TrainEvalPipelineConfig::has_eval_config() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void TrainEvalPipelineConfig::set_has_eval_config() {
  _has_bits_[0] |= 0x00000008u;
}
inline void TrainEvalPipelineConfig::clear_has_eval_config() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void TrainEvalPipelineConfig::clear_eval_config() {
  if (eval_config_ != NULL) eval_config_->::object_detection::protos::EvalConfig::Clear();
  clear_has_eval_config();
}
inline const ::object_detection::protos::EvalConfig& TrainEvalPipelineConfig::eval_config() const {
  const ::object_detection::protos::EvalConfig* p = eval_config_;
  // @@protoc_insertion_point(field_get:object_detection.protos.TrainEvalPipelineConfig.eval_config)
  return p != NULL ? *p : *reinterpret_cast<const ::object_detection::protos::EvalConfig*>(
      &::object_detection::protos::_EvalConfig_default_instance_);
}
inline ::object_detection::protos::EvalConfig* TrainEvalPipelineConfig::mutable_eval_config() {
  set_has_eval_config();
  if (eval_config_ == NULL) {
    eval_config_ = new ::object_detection::protos::EvalConfig;
  }
  // @@protoc_insertion_point(field_mutable:object_detection.protos.TrainEvalPipelineConfig.eval_config)
  return eval_config_;
}
inline ::object_detection::protos::EvalConfig* TrainEvalPipelineConfig::release_eval_config() {
  // @@protoc_insertion_point(field_release:object_detection.protos.TrainEvalPipelineConfig.eval_config)
  clear_has_eval_config();
  ::object_detection::protos::EvalConfig* temp = eval_config_;
  eval_config_ = NULL;
  return temp;
}
inline void TrainEvalPipelineConfig::set_allocated_eval_config(::object_detection::protos::EvalConfig* eval_config) {
  delete eval_config_;
  eval_config_ = eval_config;
  if (eval_config) {
    set_has_eval_config();
  } else {
    clear_has_eval_config();
  }
  // @@protoc_insertion_point(field_set_allocated:object_detection.protos.TrainEvalPipelineConfig.eval_config)
}

// repeated .object_detection.protos.InputReader eval_input_reader = 5;
inline int TrainEvalPipelineConfig::eval_input_reader_size() const {
  return eval_input_reader_.size();
}
inline void TrainEvalPipelineConfig::clear_eval_input_reader() {
  eval_input_reader_.Clear();
}
inline const ::object_detection::protos::InputReader& TrainEvalPipelineConfig::eval_input_reader(int index) const {
  // @@protoc_insertion_point(field_get:object_detection.protos.TrainEvalPipelineConfig.eval_input_reader)
  return eval_input_reader_.Get(index);
}
inline ::object_detection::protos::InputReader* TrainEvalPipelineConfig::mutable_eval_input_reader(int index) {
  // @@protoc_insertion_point(field_mutable:object_detection.protos.TrainEvalPipelineConfig.eval_input_reader)
  return eval_input_reader_.Mutable(index);
}
inline ::object_detection::protos::InputReader* TrainEvalPipelineConfig::add_eval_input_reader() {
  // @@protoc_insertion_point(field_add:object_detection.protos.TrainEvalPipelineConfig.eval_input_reader)
  return eval_input_reader_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::object_detection::protos::InputReader >*
TrainEvalPipelineConfig::mutable_eval_input_reader() {
  // @@protoc_insertion_point(field_mutable_list:object_detection.protos.TrainEvalPipelineConfig.eval_input_reader)
  return &eval_input_reader_;
}
inline const ::google::protobuf::RepeatedPtrField< ::object_detection::protos::InputReader >&
TrainEvalPipelineConfig::eval_input_reader() const {
  // @@protoc_insertion_point(field_list:object_detection.protos.TrainEvalPipelineConfig.eval_input_reader)
  return eval_input_reader_;
}

// optional .object_detection.protos.GraphRewriter graph_rewriter = 6;
inline bool TrainEvalPipelineConfig::has_graph_rewriter() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void TrainEvalPipelineConfig::set_has_graph_rewriter() {
  _has_bits_[0] |= 0x00000010u;
}
inline void TrainEvalPipelineConfig::clear_has_graph_rewriter() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void TrainEvalPipelineConfig::clear_graph_rewriter() {
  if (graph_rewriter_ != NULL) graph_rewriter_->::object_detection::protos::GraphRewriter::Clear();
  clear_has_graph_rewriter();
}
inline const ::object_detection::protos::GraphRewriter& TrainEvalPipelineConfig::graph_rewriter() const {
  const ::object_detection::protos::GraphRewriter* p = graph_rewriter_;
  // @@protoc_insertion_point(field_get:object_detection.protos.TrainEvalPipelineConfig.graph_rewriter)
  return p != NULL ? *p : *reinterpret_cast<const ::object_detection::protos::GraphRewriter*>(
      &::object_detection::protos::_GraphRewriter_default_instance_);
}
inline ::object_detection::protos::GraphRewriter* TrainEvalPipelineConfig::mutable_graph_rewriter() {
  set_has_graph_rewriter();
  if (graph_rewriter_ == NULL) {
    graph_rewriter_ = new ::object_detection::protos::GraphRewriter;
  }
  // @@protoc_insertion_point(field_mutable:object_detection.protos.TrainEvalPipelineConfig.graph_rewriter)
  return graph_rewriter_;
}
inline ::object_detection::protos::GraphRewriter* TrainEvalPipelineConfig::release_graph_rewriter() {
  // @@protoc_insertion_point(field_release:object_detection.protos.TrainEvalPipelineConfig.graph_rewriter)
  clear_has_graph_rewriter();
  ::object_detection::protos::GraphRewriter* temp = graph_rewriter_;
  graph_rewriter_ = NULL;
  return temp;
}
inline void TrainEvalPipelineConfig::set_allocated_graph_rewriter(::object_detection::protos::GraphRewriter* graph_rewriter) {
  delete graph_rewriter_;
  graph_rewriter_ = graph_rewriter;
  if (graph_rewriter) {
    set_has_graph_rewriter();
  } else {
    clear_has_graph_rewriter();
  }
  // @@protoc_insertion_point(field_set_allocated:object_detection.protos.TrainEvalPipelineConfig.graph_rewriter)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace protos
}  // namespace object_detection

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_object_5fdetection_2fprotos_2fpipeline_2eproto__INCLUDED
