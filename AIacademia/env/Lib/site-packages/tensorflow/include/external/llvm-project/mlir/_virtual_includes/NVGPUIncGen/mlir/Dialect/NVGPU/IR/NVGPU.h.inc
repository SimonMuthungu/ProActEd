/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#if defined(GET_OP_CLASSES) || defined(GET_OP_FWD_DEFINES)
#undef GET_OP_FWD_DEFINES
namespace mlir {
namespace nvgpu {
class DeviceAsyncCopyOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class DeviceAsyncCreateGroupOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class DeviceAsyncWaitOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class LdMatrixOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class MBarrierArriveExpectTxOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class MBarrierArriveNoCompleteOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class MBarrierArriveOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class MBarrierCreateOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class MBarrierInitOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class MBarrierTestWaitOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class MBarrierTryWaitParityOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class MmaSparseSyncOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class MmaSyncOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class TmaAsyncLoadOp;
} // namespace nvgpu
} // namespace mlir
namespace mlir {
namespace nvgpu {
class TmaCreateDescriptorOp;
} // namespace nvgpu
} // namespace mlir
#endif

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::DeviceAsyncCopyOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class DeviceAsyncCopyOpGenericAdaptorBase {
public:
  struct Properties {
    using bypassL1Ty = ::mlir::UnitAttr;
    bypassL1Ty bypassL1;

    auto getBypassL1() {
      auto &propStorage = this->bypassL1;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setBypassL1(const ::mlir::UnitAttr &propValue) {
      this->bypassL1 = propValue;
    }
    using dstElementsTy = ::mlir::IntegerAttr;
    dstElementsTy dstElements;

    auto getDstElements() {
      auto &propStorage = this->dstElements;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setDstElements(const ::mlir::IntegerAttr &propValue) {
      this->dstElements = propValue;
    }
    using odsOperandSegmentSizesTy = int32_t[5];
    odsOperandSegmentSizesTy odsOperandSegmentSizes;
    ::llvm::ArrayRef<int32_t> getOdsOperandSegmentSizes() {
      auto &propStorage = this->odsOperandSegmentSizes;
      return propStorage;
    }
    void setOdsOperandSegmentSizes(const ::llvm::ArrayRef<int32_t> &propValue) {
      auto &propStorage = this->odsOperandSegmentSizes;
      ::llvm::copy(propValue, propStorage);
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.bypassL1 == this->bypassL1 &&
        rhs.dstElements == this->dstElements &&
        rhs.odsOperandSegmentSizes == this->odsOperandSegmentSizes &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  DeviceAsyncCopyOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes();
  ::mlir::IntegerAttr getDstElementsAttr();
  ::llvm::APInt getDstElements();
  ::mlir::UnitAttr getBypassL1Attr();
  ::std::optional<bool> getBypassL1();
};
} // namespace detail
template <typename RangeT>
class DeviceAsyncCopyOpGenericAdaptor : public detail::DeviceAsyncCopyOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::DeviceAsyncCopyOpGenericAdaptorBase;
public:
  DeviceAsyncCopyOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  DeviceAsyncCopyOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : DeviceAsyncCopyOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getDst() {
    return (*getODSOperands(0).begin());
  }

  RangeT getDstIndices() {
    return getODSOperands(1);
  }

  ValueT getSrc() {
    return (*getODSOperands(2).begin());
  }

  RangeT getSrcIndices() {
    return getODSOperands(3);
  }

  ValueT getSrcElements() {
    auto operands = getODSOperands(4);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class DeviceAsyncCopyOpAdaptor : public DeviceAsyncCopyOpGenericAdaptor<::mlir::ValueRange> {
public:
  using DeviceAsyncCopyOpGenericAdaptor::DeviceAsyncCopyOpGenericAdaptor;
  DeviceAsyncCopyOpAdaptor(DeviceAsyncCopyOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class DeviceAsyncCopyOp : public ::mlir::Op<DeviceAsyncCopyOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::nvgpu::DeviceAsyncTokenType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<2>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DeviceAsyncCopyOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = DeviceAsyncCopyOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("bypassL1"), ::llvm::StringRef("dstElements"), ::llvm::StringRef("operand_segment_sizes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getBypassL1AttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getBypassL1AttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getDstElementsAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getDstElementsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
   return (*this)->getName().getAttributeNames().back();
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
   return name.getAttributeNames().back();
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.device_async_copy");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::MemRefType> getDst();
  ::mlir::Operation::operand_range getDstIndices();
  ::mlir::TypedValue<::mlir::MemRefType> getSrc();
  ::mlir::Operation::operand_range getSrcIndices();
  ::mlir::TypedValue<::mlir::IndexType> getSrcElements();
  ::mlir::MutableOperandRange getDstMutable();
  ::mlir::MutableOperandRange getDstIndicesMutable();
  ::mlir::MutableOperandRange getSrcMutable();
  ::mlir::MutableOperandRange getSrcIndicesMutable();
  ::mlir::MutableOperandRange getSrcElementsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::DeviceAsyncTokenType> getAsyncToken();
  static ::mlir::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::mlir::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag);
  static ::mlir::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::IntegerAttr getDstElementsAttr();
  ::llvm::APInt getDstElements();
  ::mlir::UnitAttr getBypassL1Attr();
  ::std::optional<bool> getBypassL1();
  void setDstElementsAttr(::mlir::IntegerAttr attr);
  void setDstElements(::llvm::APInt attrValue);
  void setBypassL1Attr(::mlir::UnitAttr attr);
  void setBypassL1(bool attrValue);
  ::mlir::Attribute removeBypassL1Attr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type asyncToken, ::mlir::Value dst, ::mlir::ValueRange dstIndices, ::mlir::Value src, ::mlir::ValueRange srcIndices, ::mlir::IntegerAttr dstElements, /*optional*/::mlir::Value srcElements, /*optional*/::mlir::UnitAttr bypassL1);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value dst, ::mlir::ValueRange dstIndices, ::mlir::Value src, ::mlir::ValueRange srcIndices, ::mlir::IntegerAttr dstElements, /*optional*/::mlir::Value srcElements, /*optional*/::mlir::UnitAttr bypassL1);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type asyncToken, ::mlir::Value dst, ::mlir::ValueRange dstIndices, ::mlir::Value src, ::mlir::ValueRange srcIndices, ::llvm::APInt dstElements, /*optional*/::mlir::Value srcElements, /*optional*/::mlir::UnitAttr bypassL1);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value dst, ::mlir::ValueRange dstIndices, ::mlir::Value src, ::mlir::ValueRange srcIndices, ::llvm::APInt dstElements, /*optional*/::mlir::Value srcElements, /*optional*/::mlir::UnitAttr bypassL1);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::DeviceAsyncCopyOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::DeviceAsyncCreateGroupOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class DeviceAsyncCreateGroupOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  DeviceAsyncCreateGroupOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class DeviceAsyncCreateGroupOpGenericAdaptor : public detail::DeviceAsyncCreateGroupOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::DeviceAsyncCreateGroupOpGenericAdaptorBase;
public:
  DeviceAsyncCreateGroupOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  DeviceAsyncCreateGroupOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : DeviceAsyncCreateGroupOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getInputTokens() {
    return getODSOperands(0);
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class DeviceAsyncCreateGroupOpAdaptor : public DeviceAsyncCreateGroupOpGenericAdaptor<::mlir::ValueRange> {
public:
  using DeviceAsyncCreateGroupOpGenericAdaptor::DeviceAsyncCreateGroupOpGenericAdaptor;
  DeviceAsyncCreateGroupOpAdaptor(DeviceAsyncCreateGroupOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class DeviceAsyncCreateGroupOp : public ::mlir::Op<DeviceAsyncCreateGroupOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::nvgpu::DeviceAsyncTokenType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DeviceAsyncCreateGroupOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = DeviceAsyncCreateGroupOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.device_async_create_group");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range getInputTokens();
  ::mlir::MutableOperandRange getInputTokensMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::DeviceAsyncTokenType> getAsyncToken();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type asyncToken, ::mlir::ValueRange inputTokens);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::DeviceAsyncCreateGroupOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::DeviceAsyncWaitOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class DeviceAsyncWaitOpGenericAdaptorBase {
public:
  struct Properties {
    using numGroupsTy = ::mlir::IntegerAttr;
    numGroupsTy numGroups;

    auto getNumGroups() {
      auto &propStorage = this->numGroups;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setNumGroups(const ::mlir::IntegerAttr &propValue) {
      this->numGroups = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.numGroups == this->numGroups &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  DeviceAsyncWaitOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const Properties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes();
  ::mlir::IntegerAttr getNumGroupsAttr();
  ::std::optional<uint32_t> getNumGroups();
};
} // namespace detail
template <typename RangeT>
class DeviceAsyncWaitOpGenericAdaptor : public detail::DeviceAsyncWaitOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::DeviceAsyncWaitOpGenericAdaptorBase;
public:
  DeviceAsyncWaitOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const Properties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  DeviceAsyncWaitOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : DeviceAsyncWaitOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getAsyncDependencies() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class DeviceAsyncWaitOpAdaptor : public DeviceAsyncWaitOpGenericAdaptor<::mlir::ValueRange> {
public:
  using DeviceAsyncWaitOpGenericAdaptor::DeviceAsyncWaitOpGenericAdaptor;
  DeviceAsyncWaitOpAdaptor(DeviceAsyncWaitOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class DeviceAsyncWaitOp : public ::mlir::Op<DeviceAsyncWaitOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DeviceAsyncWaitOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = DeviceAsyncWaitOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("numGroups")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getNumGroupsAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getNumGroupsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.device_async_wait");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::DeviceAsyncTokenType> getAsyncDependencies();
  ::mlir::MutableOperandRange getAsyncDependenciesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static ::mlir::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::mlir::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag);
  static ::mlir::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::IntegerAttr getNumGroupsAttr();
  ::std::optional<uint32_t> getNumGroups();
  void setNumGroupsAttr(::mlir::IntegerAttr attr);
  void setNumGroups(::std::optional<uint32_t> attrValue);
  ::mlir::Attribute removeNumGroupsAttr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value asyncDependencies, /*optional*/::mlir::IntegerAttr numGroups);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value asyncDependencies, /*optional*/::mlir::IntegerAttr numGroups);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::DeviceAsyncWaitOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::LdMatrixOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class LdMatrixOpGenericAdaptorBase {
public:
  struct Properties {
    using numTilesTy = ::mlir::IntegerAttr;
    numTilesTy numTiles;

    auto getNumTiles() {
      auto &propStorage = this->numTiles;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setNumTiles(const ::mlir::IntegerAttr &propValue) {
      this->numTiles = propValue;
    }
    using transposeTy = ::mlir::BoolAttr;
    transposeTy transpose;

    auto getTranspose() {
      auto &propStorage = this->transpose;
      return ::llvm::cast<::mlir::BoolAttr>(propStorage);
    }
    void setTranspose(const ::mlir::BoolAttr &propValue) {
      this->transpose = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.numTiles == this->numTiles &&
        rhs.transpose == this->transpose &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  LdMatrixOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const Properties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes();
  ::mlir::BoolAttr getTransposeAttr();
  bool getTranspose();
  ::mlir::IntegerAttr getNumTilesAttr();
  uint32_t getNumTiles();
};
} // namespace detail
template <typename RangeT>
class LdMatrixOpGenericAdaptor : public detail::LdMatrixOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::LdMatrixOpGenericAdaptorBase;
public:
  LdMatrixOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const Properties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  LdMatrixOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : LdMatrixOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getSrcMemref() {
    return (*getODSOperands(0).begin());
  }

  RangeT getIndices() {
    return getODSOperands(1);
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class LdMatrixOpAdaptor : public LdMatrixOpGenericAdaptor<::mlir::ValueRange> {
public:
  using LdMatrixOpGenericAdaptor::LdMatrixOpGenericAdaptor;
  LdMatrixOpAdaptor(LdMatrixOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class LdMatrixOp : public ::mlir::Op<LdMatrixOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::VectorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = LdMatrixOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = LdMatrixOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("numTiles"), ::llvm::StringRef("transpose")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getNumTilesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getNumTilesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getTransposeAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getTransposeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.ldmatrix");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::MemRefType> getSrcMemref();
  ::mlir::Operation::operand_range getIndices();
  ::mlir::MutableOperandRange getSrcMemrefMutable();
  ::mlir::MutableOperandRange getIndicesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::VectorType> getRes();
  static ::mlir::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::mlir::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag);
  static ::mlir::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::BoolAttr getTransposeAttr();
  bool getTranspose();
  ::mlir::IntegerAttr getNumTilesAttr();
  uint32_t getNumTiles();
  void setTransposeAttr(::mlir::BoolAttr attr);
  void setTranspose(bool attrValue);
  void setNumTilesAttr(::mlir::IntegerAttr attr);
  void setNumTiles(uint32_t attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value srcMemref, ::mlir::ValueRange indices, ::mlir::BoolAttr transpose, ::mlir::IntegerAttr numTiles);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value srcMemref, ::mlir::ValueRange indices, ::mlir::BoolAttr transpose, ::mlir::IntegerAttr numTiles);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value srcMemref, ::mlir::ValueRange indices, bool transpose, uint32_t numTiles);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value srcMemref, ::mlir::ValueRange indices, bool transpose, uint32_t numTiles);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::LdMatrixOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::MBarrierArriveExpectTxOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MBarrierArriveExpectTxOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  MBarrierArriveExpectTxOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class MBarrierArriveExpectTxOpGenericAdaptor : public detail::MBarrierArriveExpectTxOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MBarrierArriveExpectTxOpGenericAdaptorBase;
public:
  MBarrierArriveExpectTxOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MBarrierArriveExpectTxOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MBarrierArriveExpectTxOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getBarrier() {
    return (*getODSOperands(0).begin());
  }

  ValueT getTxcount() {
    return (*getODSOperands(1).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MBarrierArriveExpectTxOpAdaptor : public MBarrierArriveExpectTxOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MBarrierArriveExpectTxOpGenericAdaptor::MBarrierArriveExpectTxOpGenericAdaptor;
  MBarrierArriveExpectTxOpAdaptor(MBarrierArriveExpectTxOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class MBarrierArriveExpectTxOp : public ::mlir::Op<MBarrierArriveExpectTxOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MBarrierArriveExpectTxOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MBarrierArriveExpectTxOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.mbarrier.arrive.expect_tx");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::MBarrierType> getBarrier();
  ::mlir::TypedValue<::mlir::IndexType> getTxcount();
  ::mlir::MutableOperandRange getBarrierMutable();
  ::mlir::MutableOperandRange getTxcountMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value barrier, ::mlir::Value txcount);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value barrier, ::mlir::Value txcount);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MBarrierArriveExpectTxOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::MBarrierArriveNoCompleteOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MBarrierArriveNoCompleteOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  MBarrierArriveNoCompleteOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class MBarrierArriveNoCompleteOpGenericAdaptor : public detail::MBarrierArriveNoCompleteOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MBarrierArriveNoCompleteOpGenericAdaptorBase;
public:
  MBarrierArriveNoCompleteOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MBarrierArriveNoCompleteOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MBarrierArriveNoCompleteOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getBarrier() {
    return (*getODSOperands(0).begin());
  }

  ValueT getCount() {
    return (*getODSOperands(1).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MBarrierArriveNoCompleteOpAdaptor : public MBarrierArriveNoCompleteOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MBarrierArriveNoCompleteOpGenericAdaptor::MBarrierArriveNoCompleteOpGenericAdaptor;
  MBarrierArriveNoCompleteOpAdaptor(MBarrierArriveNoCompleteOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class MBarrierArriveNoCompleteOp : public ::mlir::Op<MBarrierArriveNoCompleteOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::nvgpu::MBarrierTokenType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MBarrierArriveNoCompleteOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MBarrierArriveNoCompleteOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.mbarrier.arrive.nocomplete");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::MBarrierType> getBarrier();
  ::mlir::TypedValue<::mlir::IndexType> getCount();
  ::mlir::MutableOperandRange getBarrierMutable();
  ::mlir::MutableOperandRange getCountMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::MBarrierTokenType> getToken();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type token, ::mlir::Value barrier, ::mlir::Value count);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value barrier, ::mlir::Value count);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MBarrierArriveNoCompleteOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::MBarrierArriveOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MBarrierArriveOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  MBarrierArriveOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class MBarrierArriveOpGenericAdaptor : public detail::MBarrierArriveOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MBarrierArriveOpGenericAdaptorBase;
public:
  MBarrierArriveOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MBarrierArriveOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MBarrierArriveOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getBarrier() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MBarrierArriveOpAdaptor : public MBarrierArriveOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MBarrierArriveOpGenericAdaptor::MBarrierArriveOpGenericAdaptor;
  MBarrierArriveOpAdaptor(MBarrierArriveOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class MBarrierArriveOp : public ::mlir::Op<MBarrierArriveOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::nvgpu::MBarrierTokenType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MBarrierArriveOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MBarrierArriveOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.mbarrier.arrive");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::MBarrierType> getBarrier();
  ::mlir::MutableOperandRange getBarrierMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::MBarrierTokenType> getToken();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type token, ::mlir::Value barrier);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value barrier);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MBarrierArriveOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::MBarrierCreateOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MBarrierCreateOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  MBarrierCreateOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class MBarrierCreateOpGenericAdaptor : public detail::MBarrierCreateOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MBarrierCreateOpGenericAdaptorBase;
public:
  MBarrierCreateOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MBarrierCreateOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MBarrierCreateOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MBarrierCreateOpAdaptor : public MBarrierCreateOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MBarrierCreateOpGenericAdaptor::MBarrierCreateOpGenericAdaptor;
  MBarrierCreateOpAdaptor(MBarrierCreateOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class MBarrierCreateOp : public ::mlir::Op<MBarrierCreateOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::nvgpu::MBarrierType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MBarrierCreateOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MBarrierCreateOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.mbarrier.create");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::MBarrierType> getBarrier();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type barrier);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MBarrierCreateOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::MBarrierInitOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MBarrierInitOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  MBarrierInitOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class MBarrierInitOpGenericAdaptor : public detail::MBarrierInitOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MBarrierInitOpGenericAdaptorBase;
public:
  MBarrierInitOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MBarrierInitOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MBarrierInitOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getBarrier() {
    return (*getODSOperands(0).begin());
  }

  ValueT getCount() {
    return (*getODSOperands(1).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MBarrierInitOpAdaptor : public MBarrierInitOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MBarrierInitOpGenericAdaptor::MBarrierInitOpGenericAdaptor;
  MBarrierInitOpAdaptor(MBarrierInitOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class MBarrierInitOp : public ::mlir::Op<MBarrierInitOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MBarrierInitOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MBarrierInitOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.mbarrier.init");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::MBarrierType> getBarrier();
  ::mlir::TypedValue<::mlir::IndexType> getCount();
  ::mlir::MutableOperandRange getBarrierMutable();
  ::mlir::MutableOperandRange getCountMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value barrier, ::mlir::Value count);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value barrier, ::mlir::Value count);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MBarrierInitOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::MBarrierTestWaitOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MBarrierTestWaitOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  MBarrierTestWaitOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class MBarrierTestWaitOpGenericAdaptor : public detail::MBarrierTestWaitOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MBarrierTestWaitOpGenericAdaptorBase;
public:
  MBarrierTestWaitOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MBarrierTestWaitOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MBarrierTestWaitOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getBarrier() {
    return (*getODSOperands(0).begin());
  }

  ValueT getToken() {
    return (*getODSOperands(1).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MBarrierTestWaitOpAdaptor : public MBarrierTestWaitOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MBarrierTestWaitOpGenericAdaptor::MBarrierTestWaitOpGenericAdaptor;
  MBarrierTestWaitOpAdaptor(MBarrierTestWaitOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class MBarrierTestWaitOp : public ::mlir::Op<MBarrierTestWaitOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::IntegerType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MBarrierTestWaitOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MBarrierTestWaitOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.mbarrier.test.wait");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::MBarrierType> getBarrier();
  ::mlir::TypedValue<::mlir::nvgpu::MBarrierTokenType> getToken();
  ::mlir::MutableOperandRange getBarrierMutable();
  ::mlir::MutableOperandRange getTokenMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::IntegerType> getWaitComplete();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type waitComplete, ::mlir::Value barrier, ::mlir::Value token);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value barrier, ::mlir::Value token);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MBarrierTestWaitOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::MBarrierTryWaitParityOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MBarrierTryWaitParityOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  MBarrierTryWaitParityOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class MBarrierTryWaitParityOpGenericAdaptor : public detail::MBarrierTryWaitParityOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MBarrierTryWaitParityOpGenericAdaptorBase;
public:
  MBarrierTryWaitParityOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MBarrierTryWaitParityOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MBarrierTryWaitParityOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getBarrier() {
    return (*getODSOperands(0).begin());
  }

  ValueT getPhase() {
    return (*getODSOperands(1).begin());
  }

  ValueT getTicks() {
    return (*getODSOperands(2).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MBarrierTryWaitParityOpAdaptor : public MBarrierTryWaitParityOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MBarrierTryWaitParityOpGenericAdaptor::MBarrierTryWaitParityOpGenericAdaptor;
  MBarrierTryWaitParityOpAdaptor(MBarrierTryWaitParityOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class MBarrierTryWaitParityOp : public ::mlir::Op<MBarrierTryWaitParityOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<3>::Impl, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MBarrierTryWaitParityOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MBarrierTryWaitParityOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.mbarrier.try_wait.parity");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::MBarrierType> getBarrier();
  ::mlir::TypedValue<::mlir::IndexType> getPhase();
  ::mlir::TypedValue<::mlir::IndexType> getTicks();
  ::mlir::MutableOperandRange getBarrierMutable();
  ::mlir::MutableOperandRange getPhaseMutable();
  ::mlir::MutableOperandRange getTicksMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value barrier, ::mlir::Value phase, ::mlir::Value ticks);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value barrier, ::mlir::Value phase, ::mlir::Value ticks);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MBarrierTryWaitParityOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::MmaSparseSyncOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MmaSparseSyncOpGenericAdaptorBase {
public:
  struct Properties {
    using mmaShapeTy = ::mlir::ArrayAttr;
    mmaShapeTy mmaShape;

    auto getMmaShape() {
      auto &propStorage = this->mmaShape;
      return ::llvm::cast<::mlir::ArrayAttr>(propStorage);
    }
    void setMmaShape(const ::mlir::ArrayAttr &propValue) {
      this->mmaShape = propValue;
    }
    using sparsitySelectorTy = ::mlir::IntegerAttr;
    sparsitySelectorTy sparsitySelector;

    auto getSparsitySelector() {
      auto &propStorage = this->sparsitySelector;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setSparsitySelector(const ::mlir::IntegerAttr &propValue) {
      this->sparsitySelector = propValue;
    }
    using tf32EnabledTy = ::mlir::UnitAttr;
    tf32EnabledTy tf32Enabled;

    auto getTf32Enabled() {
      auto &propStorage = this->tf32Enabled;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setTf32Enabled(const ::mlir::UnitAttr &propValue) {
      this->tf32Enabled = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.mmaShape == this->mmaShape &&
        rhs.sparsitySelector == this->sparsitySelector &&
        rhs.tf32Enabled == this->tf32Enabled &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  MmaSparseSyncOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const Properties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr getMmaShapeAttr();
  ::mlir::ArrayAttr getMmaShape();
  ::mlir::IntegerAttr getSparsitySelectorAttr();
  uint32_t getSparsitySelector();
  ::mlir::UnitAttr getTf32EnabledAttr();
  ::std::optional<bool> getTf32Enabled();
};
} // namespace detail
template <typename RangeT>
class MmaSparseSyncOpGenericAdaptor : public detail::MmaSparseSyncOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MmaSparseSyncOpGenericAdaptorBase;
public:
  MmaSparseSyncOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const Properties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MmaSparseSyncOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MmaSparseSyncOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getMatrixA() {
    return (*getODSOperands(0).begin());
  }

  ValueT getMatrixB() {
    return (*getODSOperands(1).begin());
  }

  ValueT getMatrixC() {
    return (*getODSOperands(2).begin());
  }

  ValueT getSparseMetadata() {
    return (*getODSOperands(3).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MmaSparseSyncOpAdaptor : public MmaSparseSyncOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MmaSparseSyncOpGenericAdaptor::MmaSparseSyncOpGenericAdaptor;
  MmaSparseSyncOpAdaptor(MmaSparseSyncOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class MmaSparseSyncOp : public ::mlir::Op<MmaSparseSyncOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::VectorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<4>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MmaSparseSyncOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MmaSparseSyncOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("mmaShape"), ::llvm::StringRef("sparsitySelector"), ::llvm::StringRef("tf32Enabled")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getMmaShapeAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getMmaShapeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getSparsitySelectorAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getSparsitySelectorAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getTf32EnabledAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getTf32EnabledAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.mma.sp.sync");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::VectorType> getMatrixA();
  ::mlir::TypedValue<::mlir::VectorType> getMatrixB();
  ::mlir::TypedValue<::mlir::VectorType> getMatrixC();
  ::mlir::TypedValue<::mlir::VectorType> getSparseMetadata();
  ::mlir::MutableOperandRange getMatrixAMutable();
  ::mlir::MutableOperandRange getMatrixBMutable();
  ::mlir::MutableOperandRange getMatrixCMutable();
  ::mlir::MutableOperandRange getSparseMetadataMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::VectorType> getRes();
  static ::mlir::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::mlir::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag);
  static ::mlir::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::ArrayAttr getMmaShapeAttr();
  ::mlir::ArrayAttr getMmaShape();
  ::mlir::IntegerAttr getSparsitySelectorAttr();
  uint32_t getSparsitySelector();
  ::mlir::UnitAttr getTf32EnabledAttr();
  ::std::optional<bool> getTf32Enabled();
  void setMmaShapeAttr(::mlir::ArrayAttr attr);
  void setSparsitySelectorAttr(::mlir::IntegerAttr attr);
  void setSparsitySelector(uint32_t attrValue);
  void setTf32EnabledAttr(::mlir::UnitAttr attr);
  void setTf32Enabled(bool attrValue);
  ::mlir::Attribute removeTf32EnabledAttr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value matrixA, Value matrixB, Value matrixC, Value sparseMetadata, ArrayRef<int64_t> mmaShape);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value matrixA, ::mlir::Value matrixB, ::mlir::Value matrixC, ::mlir::Value sparseMetadata, ::mlir::ArrayAttr mmaShape, ::mlir::IntegerAttr sparsitySelector, /*optional*/::mlir::UnitAttr tf32Enabled);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value matrixA, ::mlir::Value matrixB, ::mlir::Value matrixC, ::mlir::Value sparseMetadata, ::mlir::ArrayAttr mmaShape, ::mlir::IntegerAttr sparsitySelector, /*optional*/::mlir::UnitAttr tf32Enabled);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value matrixA, ::mlir::Value matrixB, ::mlir::Value matrixC, ::mlir::Value sparseMetadata, ::mlir::ArrayAttr mmaShape, uint32_t sparsitySelector, /*optional*/::mlir::UnitAttr tf32Enabled);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value matrixA, ::mlir::Value matrixB, ::mlir::Value matrixC, ::mlir::Value sparseMetadata, ::mlir::ArrayAttr mmaShape, uint32_t sparsitySelector, /*optional*/::mlir::UnitAttr tf32Enabled);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 3 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    return name.getAttributeNames()[index];
  }

public:
  std::array<int64_t, 3> getMmaShapeAsArray() {
    ArrayAttr mmaShape = this->getMmaShape();
    assert(mmaShape.size() == 3 && "mmaShape should be three integers");
    return {::llvm::cast<IntegerAttr>(mmaShape[0]).getInt(),
            ::llvm::cast<IntegerAttr>(mmaShape[1]).getInt(),
            ::llvm::cast<IntegerAttr>(mmaShape[2]).getInt()};
  }
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MmaSparseSyncOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::MmaSyncOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MmaSyncOpGenericAdaptorBase {
public:
  struct Properties {
    using mmaShapeTy = ::mlir::ArrayAttr;
    mmaShapeTy mmaShape;

    auto getMmaShape() {
      auto &propStorage = this->mmaShape;
      return ::llvm::cast<::mlir::ArrayAttr>(propStorage);
    }
    void setMmaShape(const ::mlir::ArrayAttr &propValue) {
      this->mmaShape = propValue;
    }
    using tf32EnabledTy = ::mlir::UnitAttr;
    tf32EnabledTy tf32Enabled;

    auto getTf32Enabled() {
      auto &propStorage = this->tf32Enabled;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setTf32Enabled(const ::mlir::UnitAttr &propValue) {
      this->tf32Enabled = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.mmaShape == this->mmaShape &&
        rhs.tf32Enabled == this->tf32Enabled &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  MmaSyncOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const Properties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr getMmaShapeAttr();
  ::mlir::ArrayAttr getMmaShape();
  ::mlir::UnitAttr getTf32EnabledAttr();
  ::std::optional<bool> getTf32Enabled();
};
} // namespace detail
template <typename RangeT>
class MmaSyncOpGenericAdaptor : public detail::MmaSyncOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MmaSyncOpGenericAdaptorBase;
public:
  MmaSyncOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const Properties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MmaSyncOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MmaSyncOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getMatrixA() {
    return (*getODSOperands(0).begin());
  }

  ValueT getMatrixB() {
    return (*getODSOperands(1).begin());
  }

  ValueT getMatrixC() {
    return (*getODSOperands(2).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MmaSyncOpAdaptor : public MmaSyncOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MmaSyncOpGenericAdaptor::MmaSyncOpGenericAdaptor;
  MmaSyncOpAdaptor(MmaSyncOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class MmaSyncOp : public ::mlir::Op<MmaSyncOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::VectorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<3>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MmaSyncOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MmaSyncOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("mmaShape"), ::llvm::StringRef("tf32Enabled")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getMmaShapeAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getMmaShapeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getTf32EnabledAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getTf32EnabledAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.mma.sync");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::VectorType> getMatrixA();
  ::mlir::TypedValue<::mlir::VectorType> getMatrixB();
  ::mlir::TypedValue<::mlir::VectorType> getMatrixC();
  ::mlir::MutableOperandRange getMatrixAMutable();
  ::mlir::MutableOperandRange getMatrixBMutable();
  ::mlir::MutableOperandRange getMatrixCMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::VectorType> getRes();
  static ::mlir::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::mlir::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag);
  static ::mlir::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::ArrayAttr getMmaShapeAttr();
  ::mlir::ArrayAttr getMmaShape();
  ::mlir::UnitAttr getTf32EnabledAttr();
  ::std::optional<bool> getTf32Enabled();
  void setMmaShapeAttr(::mlir::ArrayAttr attr);
  void setTf32EnabledAttr(::mlir::UnitAttr attr);
  void setTf32Enabled(bool attrValue);
  ::mlir::Attribute removeTf32EnabledAttr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value matrixA, Value matrixB, Value matrixC, ArrayAttr mmaShape);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value matrixA, Value matrixB, Value matrixC, ArrayRef<int64_t> mmaShape, bool tf32Enabled = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value matrixA, ::mlir::Value matrixB, ::mlir::Value matrixC, ::mlir::ArrayAttr mmaShape, /*optional*/::mlir::UnitAttr tf32Enabled);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value matrixA, ::mlir::Value matrixB, ::mlir::Value matrixC, ::mlir::ArrayAttr mmaShape, /*optional*/::mlir::UnitAttr tf32Enabled);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    return name.getAttributeNames()[index];
  }

public:
  std::array<int64_t, 3> getMmaShapeAsArray() {
    ArrayAttr mmaShape = this->getMmaShape();
    assert(mmaShape.size() == 3 && "mmaShape should be three integers");
    return {::llvm::cast<IntegerAttr>(mmaShape[0]).getInt(),
            ::llvm::cast<IntegerAttr>(mmaShape[1]).getInt(),
            ::llvm::cast<IntegerAttr>(mmaShape[2]).getInt()};
  }
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MmaSyncOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::TmaAsyncLoadOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class TmaAsyncLoadOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  TmaAsyncLoadOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class TmaAsyncLoadOpGenericAdaptor : public detail::TmaAsyncLoadOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::TmaAsyncLoadOpGenericAdaptorBase;
public:
  TmaAsyncLoadOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  TmaAsyncLoadOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : TmaAsyncLoadOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getDst() {
    return (*getODSOperands(0).begin());
  }

  ValueT getBarrier() {
    return (*getODSOperands(1).begin());
  }

  ValueT getTensorMapDescriptor() {
    return (*getODSOperands(2).begin());
  }

  RangeT getCoordinates() {
    return getODSOperands(3);
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class TmaAsyncLoadOpAdaptor : public TmaAsyncLoadOpGenericAdaptor<::mlir::ValueRange> {
public:
  using TmaAsyncLoadOpGenericAdaptor::TmaAsyncLoadOpGenericAdaptor;
  TmaAsyncLoadOpAdaptor(TmaAsyncLoadOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class TmaAsyncLoadOp : public ::mlir::Op<TmaAsyncLoadOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<3>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = TmaAsyncLoadOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = TmaAsyncLoadOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.tma.async.load");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::MemRefType> getDst();
  ::mlir::TypedValue<::mlir::nvgpu::MBarrierType> getBarrier();
  ::mlir::TypedValue<::mlir::nvgpu::TensorMapDescriptorType> getTensorMapDescriptor();
  ::mlir::Operation::operand_range getCoordinates();
  ::mlir::MutableOperandRange getDstMutable();
  ::mlir::MutableOperandRange getBarrierMutable();
  ::mlir::MutableOperandRange getTensorMapDescriptorMutable();
  ::mlir::MutableOperandRange getCoordinatesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value dst, ::mlir::Value barrier, ::mlir::Value tensorMapDescriptor, ::mlir::ValueRange coordinates);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value dst, ::mlir::Value barrier, ::mlir::Value tensorMapDescriptor, ::mlir::ValueRange coordinates);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::TmaAsyncLoadOp)

namespace mlir {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::nvgpu::TmaCreateDescriptorOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class TmaCreateDescriptorOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  TmaCreateDescriptorOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {});

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes();
};
} // namespace detail
template <typename RangeT>
class TmaCreateDescriptorOpGenericAdaptor : public detail::TmaCreateDescriptorOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::TmaCreateDescriptorOpGenericAdaptorBase;
public:
  TmaCreateDescriptorOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  TmaCreateDescriptorOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : TmaCreateDescriptorOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensor() {
    return (*getODSOperands(0).begin());
  }

  RangeT getBoxDimensions() {
    return getODSOperands(1);
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class TmaCreateDescriptorOpAdaptor : public TmaCreateDescriptorOpGenericAdaptor<::mlir::ValueRange> {
public:
  using TmaCreateDescriptorOpGenericAdaptor::TmaCreateDescriptorOpGenericAdaptor;
  TmaCreateDescriptorOpAdaptor(TmaCreateDescriptorOp op);

  ::mlir::LogicalResult verify(::mlir::Location loc);
};
class TmaCreateDescriptorOp : public ::mlir::Op<TmaCreateDescriptorOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::nvgpu::TensorMapDescriptorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = TmaCreateDescriptorOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = TmaCreateDescriptorOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("nvgpu.tma.create.descriptor");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::TypedValue<::mlir::UnrankedMemRefType> getTensor();
  ::mlir::Operation::operand_range getBoxDimensions();
  ::mlir::MutableOperandRange getTensorMutable();
  ::mlir::MutableOperandRange getBoxDimensionsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::TypedValue<::mlir::nvgpu::TensorMapDescriptorType> getTensorMap();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type tensorMap, ::mlir::Value tensor, ::mlir::ValueRange boxDimensions);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, ::mlir::ValueRange boxDimensions);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::TmaCreateDescriptorOp)


#endif  // GET_OP_CLASSES

