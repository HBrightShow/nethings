// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sudoku.proto

#ifndef PROTOBUF_INCLUDED_sudoku_2eproto
#define PROTOBUF_INCLUDED_sudoku_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_sudoku_2eproto 

namespace protobuf_sudoku_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_sudoku_2eproto
namespace sudoku {
class SudokuRequest;
class SudokuRequestDefaultTypeInternal;
extern SudokuRequestDefaultTypeInternal _SudokuRequest_default_instance_;
class SudokuResponse;
class SudokuResponseDefaultTypeInternal;
extern SudokuResponseDefaultTypeInternal _SudokuResponse_default_instance_;
}  // namespace sudoku
namespace google {
namespace protobuf {
template<> ::sudoku::SudokuRequest* Arena::CreateMaybeMessage<::sudoku::SudokuRequest>(Arena*);
template<> ::sudoku::SudokuResponse* Arena::CreateMaybeMessage<::sudoku::SudokuResponse>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace sudoku {

// ===================================================================

class SudokuRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sudoku.SudokuRequest) */ {
 public:
  SudokuRequest();
  virtual ~SudokuRequest();

  SudokuRequest(const SudokuRequest& from);

  inline SudokuRequest& operator=(const SudokuRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SudokuRequest(SudokuRequest&& from) noexcept
    : SudokuRequest() {
    *this = ::std::move(from);
  }

  inline SudokuRequest& operator=(SudokuRequest&& from) noexcept {
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
  static const SudokuRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SudokuRequest* internal_default_instance() {
    return reinterpret_cast<const SudokuRequest*>(
               &_SudokuRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(SudokuRequest* other);
  friend void swap(SudokuRequest& a, SudokuRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SudokuRequest* New() const final {
    return CreateMaybeMessage<SudokuRequest>(NULL);
  }

  SudokuRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<SudokuRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const SudokuRequest& from);
  void MergeFrom(const SudokuRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SudokuRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string checkerboard = 1;
  bool has_checkerboard() const;
  void clear_checkerboard();
  static const int kCheckerboardFieldNumber = 1;
  const ::std::string& checkerboard() const;
  void set_checkerboard(const ::std::string& value);
  #if LANG_CXX11
  void set_checkerboard(::std::string&& value);
  #endif
  void set_checkerboard(const char* value);
  void set_checkerboard(const char* value, size_t size);
  ::std::string* mutable_checkerboard();
  ::std::string* release_checkerboard();
  void set_allocated_checkerboard(::std::string* checkerboard);

  // @@protoc_insertion_point(class_scope:sudoku.SudokuRequest)
 private:
  void set_has_checkerboard();
  void clear_has_checkerboard();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr checkerboard_;
  friend struct ::protobuf_sudoku_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SudokuResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sudoku.SudokuResponse) */ {
 public:
  SudokuResponse();
  virtual ~SudokuResponse();

  SudokuResponse(const SudokuResponse& from);

  inline SudokuResponse& operator=(const SudokuResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SudokuResponse(SudokuResponse&& from) noexcept
    : SudokuResponse() {
    *this = ::std::move(from);
  }

  inline SudokuResponse& operator=(SudokuResponse&& from) noexcept {
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
  static const SudokuResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SudokuResponse* internal_default_instance() {
    return reinterpret_cast<const SudokuResponse*>(
               &_SudokuResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(SudokuResponse* other);
  friend void swap(SudokuResponse& a, SudokuResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SudokuResponse* New() const final {
    return CreateMaybeMessage<SudokuResponse>(NULL);
  }

  SudokuResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<SudokuResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const SudokuResponse& from);
  void MergeFrom(const SudokuResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SudokuResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string checkerboard = 2;
  bool has_checkerboard() const;
  void clear_checkerboard();
  static const int kCheckerboardFieldNumber = 2;
  const ::std::string& checkerboard() const;
  void set_checkerboard(const ::std::string& value);
  #if LANG_CXX11
  void set_checkerboard(::std::string&& value);
  #endif
  void set_checkerboard(const char* value);
  void set_checkerboard(const char* value, size_t size);
  ::std::string* mutable_checkerboard();
  ::std::string* release_checkerboard();
  void set_allocated_checkerboard(::std::string* checkerboard);

  // optional bool solved = 1 [default = false];
  bool has_solved() const;
  void clear_solved();
  static const int kSolvedFieldNumber = 1;
  bool solved() const;
  void set_solved(bool value);

  // @@protoc_insertion_point(class_scope:sudoku.SudokuResponse)
 private:
  void set_has_solved();
  void clear_has_solved();
  void set_has_checkerboard();
  void clear_has_checkerboard();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr checkerboard_;
  bool solved_;
  friend struct ::protobuf_sudoku_2eproto::TableStruct;
};
// ===================================================================

class SudokuService_Stub;

class SudokuService : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline SudokuService() {};
 public:
  virtual ~SudokuService();

  typedef SudokuService_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void Solve(::google::protobuf::RpcController* controller,
                       const ::sudoku::SudokuRequest* request,
                       ::sudoku::SudokuResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(SudokuService);
};

class SudokuService_Stub : public SudokuService {
 public:
  SudokuService_Stub(::google::protobuf::RpcChannel* channel);
  SudokuService_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~SudokuService_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements SudokuService ------------------------------------------

  void Solve(::google::protobuf::RpcController* controller,
                       const ::sudoku::SudokuRequest* request,
                       ::sudoku::SudokuResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(SudokuService_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SudokuRequest

// required string checkerboard = 1;
inline bool SudokuRequest::has_checkerboard() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SudokuRequest::set_has_checkerboard() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SudokuRequest::clear_has_checkerboard() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SudokuRequest::clear_checkerboard() {
  checkerboard_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_checkerboard();
}
inline const ::std::string& SudokuRequest::checkerboard() const {
  // @@protoc_insertion_point(field_get:sudoku.SudokuRequest.checkerboard)
  return checkerboard_.GetNoArena();
}
inline void SudokuRequest::set_checkerboard(const ::std::string& value) {
  set_has_checkerboard();
  checkerboard_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:sudoku.SudokuRequest.checkerboard)
}
#if LANG_CXX11
inline void SudokuRequest::set_checkerboard(::std::string&& value) {
  set_has_checkerboard();
  checkerboard_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:sudoku.SudokuRequest.checkerboard)
}
#endif
inline void SudokuRequest::set_checkerboard(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_checkerboard();
  checkerboard_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:sudoku.SudokuRequest.checkerboard)
}
inline void SudokuRequest::set_checkerboard(const char* value, size_t size) {
  set_has_checkerboard();
  checkerboard_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:sudoku.SudokuRequest.checkerboard)
}
inline ::std::string* SudokuRequest::mutable_checkerboard() {
  set_has_checkerboard();
  // @@protoc_insertion_point(field_mutable:sudoku.SudokuRequest.checkerboard)
  return checkerboard_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SudokuRequest::release_checkerboard() {
  // @@protoc_insertion_point(field_release:sudoku.SudokuRequest.checkerboard)
  if (!has_checkerboard()) {
    return NULL;
  }
  clear_has_checkerboard();
  return checkerboard_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SudokuRequest::set_allocated_checkerboard(::std::string* checkerboard) {
  if (checkerboard != NULL) {
    set_has_checkerboard();
  } else {
    clear_has_checkerboard();
  }
  checkerboard_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), checkerboard);
  // @@protoc_insertion_point(field_set_allocated:sudoku.SudokuRequest.checkerboard)
}

// -------------------------------------------------------------------

// SudokuResponse

// optional bool solved = 1 [default = false];
inline bool SudokuResponse::has_solved() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SudokuResponse::set_has_solved() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SudokuResponse::clear_has_solved() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SudokuResponse::clear_solved() {
  solved_ = false;
  clear_has_solved();
}
inline bool SudokuResponse::solved() const {
  // @@protoc_insertion_point(field_get:sudoku.SudokuResponse.solved)
  return solved_;
}
inline void SudokuResponse::set_solved(bool value) {
  set_has_solved();
  solved_ = value;
  // @@protoc_insertion_point(field_set:sudoku.SudokuResponse.solved)
}

// optional string checkerboard = 2;
inline bool SudokuResponse::has_checkerboard() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SudokuResponse::set_has_checkerboard() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SudokuResponse::clear_has_checkerboard() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SudokuResponse::clear_checkerboard() {
  checkerboard_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_checkerboard();
}
inline const ::std::string& SudokuResponse::checkerboard() const {
  // @@protoc_insertion_point(field_get:sudoku.SudokuResponse.checkerboard)
  return checkerboard_.GetNoArena();
}
inline void SudokuResponse::set_checkerboard(const ::std::string& value) {
  set_has_checkerboard();
  checkerboard_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:sudoku.SudokuResponse.checkerboard)
}
#if LANG_CXX11
inline void SudokuResponse::set_checkerboard(::std::string&& value) {
  set_has_checkerboard();
  checkerboard_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:sudoku.SudokuResponse.checkerboard)
}
#endif
inline void SudokuResponse::set_checkerboard(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_checkerboard();
  checkerboard_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:sudoku.SudokuResponse.checkerboard)
}
inline void SudokuResponse::set_checkerboard(const char* value, size_t size) {
  set_has_checkerboard();
  checkerboard_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:sudoku.SudokuResponse.checkerboard)
}
inline ::std::string* SudokuResponse::mutable_checkerboard() {
  set_has_checkerboard();
  // @@protoc_insertion_point(field_mutable:sudoku.SudokuResponse.checkerboard)
  return checkerboard_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SudokuResponse::release_checkerboard() {
  // @@protoc_insertion_point(field_release:sudoku.SudokuResponse.checkerboard)
  if (!has_checkerboard()) {
    return NULL;
  }
  clear_has_checkerboard();
  return checkerboard_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SudokuResponse::set_allocated_checkerboard(::std::string* checkerboard) {
  if (checkerboard != NULL) {
    set_has_checkerboard();
  } else {
    clear_has_checkerboard();
  }
  checkerboard_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), checkerboard);
  // @@protoc_insertion_point(field_set_allocated:sudoku.SudokuResponse.checkerboard)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace sudoku

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_sudoku_2eproto
