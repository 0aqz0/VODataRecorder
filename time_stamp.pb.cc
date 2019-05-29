// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: time_stamp.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "time_stamp.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* TimeStamp_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TimeStamp_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_time_5fstamp_2eproto() {
  protobuf_AddDesc_time_5fstamp_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "time_stamp.proto");
  GOOGLE_CHECK(file != NULL);
  TimeStamp_descriptor_ = file->message_type(0);
  static const int TimeStamp_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TimeStamp, time_),
  };
  TimeStamp_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      TimeStamp_descriptor_,
      TimeStamp::default_instance_,
      TimeStamp_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TimeStamp, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TimeStamp, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(TimeStamp));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_time_5fstamp_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    TimeStamp_descriptor_, &TimeStamp::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_time_5fstamp_2eproto() {
  delete TimeStamp::default_instance_;
  delete TimeStamp_reflection_;
}

void protobuf_AddDesc_time_5fstamp_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020time_stamp.proto\"\031\n\tTimeStamp\022\014\n\004time\030"
    "\001 \002(\004", 45);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "time_stamp.proto", &protobuf_RegisterTypes);
  TimeStamp::default_instance_ = new TimeStamp();
  TimeStamp::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_time_5fstamp_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_time_5fstamp_2eproto {
  StaticDescriptorInitializer_time_5fstamp_2eproto() {
    protobuf_AddDesc_time_5fstamp_2eproto();
  }
} static_descriptor_initializer_time_5fstamp_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int TimeStamp::kTimeFieldNumber;
#endif  // !_MSC_VER

TimeStamp::TimeStamp()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:TimeStamp)
}

void TimeStamp::InitAsDefaultInstance() {
}

TimeStamp::TimeStamp(const TimeStamp& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:TimeStamp)
}

void TimeStamp::SharedCtor() {
  _cached_size_ = 0;
  time_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

TimeStamp::~TimeStamp() {
  // @@protoc_insertion_point(destructor:TimeStamp)
  SharedDtor();
}

void TimeStamp::SharedDtor() {
  if (this != default_instance_) {
  }
}

void TimeStamp::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TimeStamp::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TimeStamp_descriptor_;
}

const TimeStamp& TimeStamp::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_time_5fstamp_2eproto();
  return *default_instance_;
}

TimeStamp* TimeStamp::default_instance_ = NULL;

TimeStamp* TimeStamp::New() const {
  return new TimeStamp;
}

void TimeStamp::Clear() {
  time_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool TimeStamp::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:TimeStamp)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 time = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &time_)));
          set_has_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:TimeStamp)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:TimeStamp)
  return false;
#undef DO_
}

void TimeStamp::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:TimeStamp)
  // required uint64 time = 1;
  if (has_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->time(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:TimeStamp)
}

::google::protobuf::uint8* TimeStamp::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:TimeStamp)
  // required uint64 time = 1;
  if (has_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->time(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:TimeStamp)
  return target;
}

int TimeStamp::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint64 time = 1;
    if (has_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->time());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void TimeStamp::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const TimeStamp* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const TimeStamp*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void TimeStamp::MergeFrom(const TimeStamp& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_time()) {
      set_time(from.time());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void TimeStamp::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TimeStamp::CopyFrom(const TimeStamp& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TimeStamp::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void TimeStamp::Swap(TimeStamp* other) {
  if (other != this) {
    std::swap(time_, other->time_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata TimeStamp::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = TimeStamp_descriptor_;
  metadata.reflection = TimeStamp_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
