// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_NATION_DBGEN_CONVERTER_H_
#define FLATBUFFERS_GENERATED_NATION_DBGEN_CONVERTER_H_

#include "flatbuffers/flatbuffers.h"

#include "customer_generated.h"
#include "lineitem_generated.h"

namespace dbgen_converter {
struct CUSTOMER;
}  // namespace dbgen_converter
namespace dbgen_converter {
struct LINEITEM;
}  // namespace dbgen_converter

namespace dbgen_converter {

struct NATION;

struct NATION FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  int32_t N_NATIONKEY() const { return GetField<int32_t>(4, 0); }
  const flatbuffers::String *N_NAME() const { return GetPointer<const flatbuffers::String *>(6); }
  int32_t N_REGIONKEY() const { return GetField<int32_t>(8, 0); }
  const flatbuffers::String *N_COMMENT() const { return GetPointer<const flatbuffers::String *>(10); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, 4 /* N_NATIONKEY */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 6 /* N_NAME */) &&
           verifier.Verify(N_NAME()) &&
           VerifyField<int32_t>(verifier, 8 /* N_REGIONKEY */) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, 10 /* N_COMMENT */) &&
           verifier.Verify(N_COMMENT()) &&
           verifier.EndTable();
  }
};

struct NATIONBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_N_NATIONKEY(int32_t N_NATIONKEY) { fbb_.AddElement<int32_t>(4, N_NATIONKEY, 0); }
  void add_N_NAME(flatbuffers::Offset<flatbuffers::String> N_NAME) { fbb_.AddOffset(6, N_NAME); }
  void add_N_REGIONKEY(int32_t N_REGIONKEY) { fbb_.AddElement<int32_t>(8, N_REGIONKEY, 0); }
  void add_N_COMMENT(flatbuffers::Offset<flatbuffers::String> N_COMMENT) { fbb_.AddOffset(10, N_COMMENT); }
  NATIONBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  NATIONBuilder &operator=(const NATIONBuilder &);
  flatbuffers::Offset<NATION> Finish() {
    auto o = flatbuffers::Offset<NATION>(fbb_.EndTable(start_, 4));
    return o;
  }
};

inline flatbuffers::Offset<NATION> CreateNATION(flatbuffers::FlatBufferBuilder &_fbb,
   int32_t N_NATIONKEY = 0,
   flatbuffers::Offset<flatbuffers::String> N_NAME = 0,
   int32_t N_REGIONKEY = 0,
   flatbuffers::Offset<flatbuffers::String> N_COMMENT = 0) {
  NATIONBuilder builder_(_fbb);
  builder_.add_N_COMMENT(N_COMMENT);
  builder_.add_N_REGIONKEY(N_REGIONKEY);
  builder_.add_N_NAME(N_NAME);
  builder_.add_N_NATIONKEY(N_NATIONKEY);
  return builder_.Finish();
}

inline const dbgen_converter::NATION *GetNATION(const void *buf) { return flatbuffers::GetRoot<dbgen_converter::NATION>(buf); }

inline bool VerifyNATIONBuffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<dbgen_converter::NATION>(); }

inline void FinishNATIONBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<dbgen_converter::NATION> root) { fbb.Finish(root); }

}  // namespace dbgen_converter

#endif  // FLATBUFFERS_GENERATED_NATION_DBGEN_CONVERTER_H_
