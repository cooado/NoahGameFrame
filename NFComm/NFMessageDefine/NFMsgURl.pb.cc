// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: NFMsgURl.proto

#include "NFMsgURl.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace NFMsg {
class PackSURLParamDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<PackSURLParam>
      _instance;
} _PackSURLParam_default_instance_;
}  // namespace NFMsg
namespace protobuf_NFMsgURl_2eproto {
static void InitDefaultsPackSURLParam() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::NFMsg::_PackSURLParam_default_instance_;
    new (ptr) ::NFMsg::PackSURLParam();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::NFMsg::PackSURLParam::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_PackSURLParam =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsPackSURLParam}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_PackSURLParam.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::NFMsg::PackSURLParam, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::NFMsg::PackSURLParam, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::NFMsg::PackSURLParam, strurl_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::NFMsg::PackSURLParam, strgetparams_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::NFMsg::PackSURLParam, strbodydata_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::NFMsg::PackSURLParam, strcookies_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::NFMsg::PackSURLParam, ftimeoutsec_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::NFMsg::PackSURLParam, strrsp_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::NFMsg::PackSURLParam, nret_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::NFMsg::PackSURLParam, nreqid_),
  0,
  1,
  2,
  3,
  5,
  4,
  6,
  7,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 13, sizeof(::NFMsg::PackSURLParam)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::NFMsg::_PackSURLParam_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "NFMsgURl.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\016NFMsgURl.proto\022\005NFMsg\"\241\001\n\rPackSURLPara"
      "m\022\016\n\006strUrl\030\001 \002(\014\022\024\n\014strGetParams\030\002 \002(\014\022"
      "\023\n\013strBodyData\030\003 \002(\014\022\022\n\nstrCookies\030\004 \002(\014"
      "\022\023\n\013fTimeOutSec\030\005 \002(\001\022\016\n\006strRsp\030\006 \002(\014\022\014\n"
      "\004nRet\030\007 \002(\003\022\016\n\006nReqID\030\010 \002(\003"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 187);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "NFMsgURl.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_NFMsgURl_2eproto
namespace NFMsg {

// ===================================================================

void PackSURLParam::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PackSURLParam::kStrUrlFieldNumber;
const int PackSURLParam::kStrGetParamsFieldNumber;
const int PackSURLParam::kStrBodyDataFieldNumber;
const int PackSURLParam::kStrCookiesFieldNumber;
const int PackSURLParam::kFTimeOutSecFieldNumber;
const int PackSURLParam::kStrRspFieldNumber;
const int PackSURLParam::kNRetFieldNumber;
const int PackSURLParam::kNReqIDFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PackSURLParam::PackSURLParam()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_NFMsgURl_2eproto::scc_info_PackSURLParam.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:NFMsg.PackSURLParam)
}
PackSURLParam::PackSURLParam(const PackSURLParam& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  strurl_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_strurl()) {
    strurl_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.strurl_);
  }
  strgetparams_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_strgetparams()) {
    strgetparams_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.strgetparams_);
  }
  strbodydata_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_strbodydata()) {
    strbodydata_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.strbodydata_);
  }
  strcookies_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_strcookies()) {
    strcookies_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.strcookies_);
  }
  strrsp_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_strrsp()) {
    strrsp_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.strrsp_);
  }
  ::memcpy(&ftimeoutsec_, &from.ftimeoutsec_,
    static_cast<size_t>(reinterpret_cast<char*>(&nreqid_) -
    reinterpret_cast<char*>(&ftimeoutsec_)) + sizeof(nreqid_));
  // @@protoc_insertion_point(copy_constructor:NFMsg.PackSURLParam)
}

void PackSURLParam::SharedCtor() {
  strurl_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  strgetparams_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  strbodydata_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  strcookies_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  strrsp_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&ftimeoutsec_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&nreqid_) -
      reinterpret_cast<char*>(&ftimeoutsec_)) + sizeof(nreqid_));
}

PackSURLParam::~PackSURLParam() {
  // @@protoc_insertion_point(destructor:NFMsg.PackSURLParam)
  SharedDtor();
}

void PackSURLParam::SharedDtor() {
  strurl_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  strgetparams_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  strbodydata_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  strcookies_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  strrsp_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void PackSURLParam::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* PackSURLParam::descriptor() {
  ::protobuf_NFMsgURl_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_NFMsgURl_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const PackSURLParam& PackSURLParam::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_NFMsgURl_2eproto::scc_info_PackSURLParam.base);
  return *internal_default_instance();
}


void PackSURLParam::Clear() {
// @@protoc_insertion_point(message_clear_start:NFMsg.PackSURLParam)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 31u) {
    if (cached_has_bits & 0x00000001u) {
      strurl_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      strgetparams_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      strbodydata_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000008u) {
      strcookies_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000010u) {
      strrsp_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 224u) {
    ::memset(&ftimeoutsec_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&nreqid_) -
        reinterpret_cast<char*>(&ftimeoutsec_)) + sizeof(nreqid_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool PackSURLParam::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:NFMsg.PackSURLParam)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bytes strUrl = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_strurl()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required bytes strGetParams = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_strgetparams()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required bytes strBodyData = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_strbodydata()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required bytes strCookies = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_strcookies()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required double fTimeOutSec = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(41u /* 41 & 0xFF */)) {
          set_has_ftimeoutsec();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &ftimeoutsec_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required bytes strRsp = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(50u /* 50 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_strrsp()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int64 nRet = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(56u /* 56 & 0xFF */)) {
          set_has_nret();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &nret_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int64 nReqID = 8;
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(64u /* 64 & 0xFF */)) {
          set_has_nreqid();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &nreqid_)));
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
  // @@protoc_insertion_point(parse_success:NFMsg.PackSURLParam)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:NFMsg.PackSURLParam)
  return false;
#undef DO_
}

void PackSURLParam::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:NFMsg.PackSURLParam)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required bytes strUrl = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->strurl(), output);
  }

  // required bytes strGetParams = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->strgetparams(), output);
  }

  // required bytes strBodyData = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      3, this->strbodydata(), output);
  }

  // required bytes strCookies = 4;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      4, this->strcookies(), output);
  }

  // required double fTimeOutSec = 5;
  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(5, this->ftimeoutsec(), output);
  }

  // required bytes strRsp = 6;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      6, this->strrsp(), output);
  }

  // required int64 nRet = 7;
  if (cached_has_bits & 0x00000040u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(7, this->nret(), output);
  }

  // required int64 nReqID = 8;
  if (cached_has_bits & 0x00000080u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(8, this->nreqid(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:NFMsg.PackSURLParam)
}

::google::protobuf::uint8* PackSURLParam::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:NFMsg.PackSURLParam)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required bytes strUrl = 1;
  if (cached_has_bits & 0x00000001u) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->strurl(), target);
  }

  // required bytes strGetParams = 2;
  if (cached_has_bits & 0x00000002u) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->strgetparams(), target);
  }

  // required bytes strBodyData = 3;
  if (cached_has_bits & 0x00000004u) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->strbodydata(), target);
  }

  // required bytes strCookies = 4;
  if (cached_has_bits & 0x00000008u) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        4, this->strcookies(), target);
  }

  // required double fTimeOutSec = 5;
  if (cached_has_bits & 0x00000020u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, this->ftimeoutsec(), target);
  }

  // required bytes strRsp = 6;
  if (cached_has_bits & 0x00000010u) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        6, this->strrsp(), target);
  }

  // required int64 nRet = 7;
  if (cached_has_bits & 0x00000040u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(7, this->nret(), target);
  }

  // required int64 nReqID = 8;
  if (cached_has_bits & 0x00000080u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(8, this->nreqid(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:NFMsg.PackSURLParam)
  return target;
}

size_t PackSURLParam::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:NFMsg.PackSURLParam)
  size_t total_size = 0;

  if (has_strurl()) {
    // required bytes strUrl = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->strurl());
  }

  if (has_strgetparams()) {
    // required bytes strGetParams = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->strgetparams());
  }

  if (has_strbodydata()) {
    // required bytes strBodyData = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->strbodydata());
  }

  if (has_strcookies()) {
    // required bytes strCookies = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->strcookies());
  }

  if (has_strrsp()) {
    // required bytes strRsp = 6;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->strrsp());
  }

  if (has_ftimeoutsec()) {
    // required double fTimeOutSec = 5;
    total_size += 1 + 8;
  }

  if (has_nret()) {
    // required int64 nRet = 7;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->nret());
  }

  if (has_nreqid()) {
    // required int64 nReqID = 8;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->nreqid());
  }

  return total_size;
}
size_t PackSURLParam::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:NFMsg.PackSURLParam)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x000000ff) ^ 0x000000ff) == 0) {  // All required fields are present.
    // required bytes strUrl = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->strurl());

    // required bytes strGetParams = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->strgetparams());

    // required bytes strBodyData = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->strbodydata());

    // required bytes strCookies = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->strcookies());

    // required bytes strRsp = 6;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->strrsp());

    // required double fTimeOutSec = 5;
    total_size += 1 + 8;

    // required int64 nRet = 7;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->nret());

    // required int64 nReqID = 8;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->nreqid());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PackSURLParam::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:NFMsg.PackSURLParam)
  GOOGLE_DCHECK_NE(&from, this);
  const PackSURLParam* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const PackSURLParam>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:NFMsg.PackSURLParam)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:NFMsg.PackSURLParam)
    MergeFrom(*source);
  }
}

void PackSURLParam::MergeFrom(const PackSURLParam& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:NFMsg.PackSURLParam)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 255u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_strurl();
      strurl_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.strurl_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_strgetparams();
      strgetparams_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.strgetparams_);
    }
    if (cached_has_bits & 0x00000004u) {
      set_has_strbodydata();
      strbodydata_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.strbodydata_);
    }
    if (cached_has_bits & 0x00000008u) {
      set_has_strcookies();
      strcookies_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.strcookies_);
    }
    if (cached_has_bits & 0x00000010u) {
      set_has_strrsp();
      strrsp_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.strrsp_);
    }
    if (cached_has_bits & 0x00000020u) {
      ftimeoutsec_ = from.ftimeoutsec_;
    }
    if (cached_has_bits & 0x00000040u) {
      nret_ = from.nret_;
    }
    if (cached_has_bits & 0x00000080u) {
      nreqid_ = from.nreqid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void PackSURLParam::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:NFMsg.PackSURLParam)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PackSURLParam::CopyFrom(const PackSURLParam& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:NFMsg.PackSURLParam)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PackSURLParam::IsInitialized() const {
  if ((_has_bits_[0] & 0x000000ff) != 0x000000ff) return false;
  return true;
}

void PackSURLParam::Swap(PackSURLParam* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PackSURLParam::InternalSwap(PackSURLParam* other) {
  using std::swap;
  strurl_.Swap(&other->strurl_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  strgetparams_.Swap(&other->strgetparams_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  strbodydata_.Swap(&other->strbodydata_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  strcookies_.Swap(&other->strcookies_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  strrsp_.Swap(&other->strrsp_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(ftimeoutsec_, other->ftimeoutsec_);
  swap(nret_, other->nret_);
  swap(nreqid_, other->nreqid_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata PackSURLParam::GetMetadata() const {
  protobuf_NFMsgURl_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_NFMsgURl_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace NFMsg
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::NFMsg::PackSURLParam* Arena::CreateMaybeMessage< ::NFMsg::PackSURLParam >(Arena* arena) {
  return Arena::CreateInternal< ::NFMsg::PackSURLParam >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
