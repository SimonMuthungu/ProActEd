/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mlir::bufferization::AllocTensorOp,
::mlir::bufferization::CloneOp,
::mlir::bufferization::CopyTensorOp,
::mlir::bufferization::DeallocOp,
::mlir::bufferization::DeallocTensorOp,
::mlir::bufferization::ToMemrefOp,
::mlir::bufferization::ToTensorOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace bufferization {

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_BufferizationOps0(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((::llvm::isa<::mlir::IndexType>(type)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be index, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_BufferizationOps1(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::TensorType>(type))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>(type).getElementType())))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be tensor of any type values, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_BufferizationOps2(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::BaseMemRefType>(type))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>(type).getElementType())))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be ranked or unranked memref of any type values, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_BufferizationOps3(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((type.isSignlessInteger(1)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be 1-bit signless integer, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_BufferizationOps0(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
  if (attr && !((true)))
    return getDiag() << "attribute '" << attrName
        << "' failed to satisfy constraint: any attribute";
  return ::mlir::success();
}
static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_BufferizationOps0(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_BufferizationOps0(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_BufferizationOps1(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
  if (attr && !((::llvm::isa<::mlir::UnitAttr>(attr))))
    return getDiag() << "attribute '" << attrName
        << "' failed to satisfy constraint: unit attribute";
  return ::mlir::success();
}
static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_BufferizationOps1(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_BufferizationOps1(attr, attrName, [op]() {
    return op->emitOpError();
  });
}
} // namespace bufferization
} // namespace mlir
namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::AllocTensorOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AllocTensorOpGenericAdaptorBase::AllocTensorOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("bufferization.alloc_tensor", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AllocTensorOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  ::llvm::ArrayRef<int32_t> sizeAttr = getProperties().odsOperandSegmentSizes;

  unsigned start = 0;
  for (unsigned i = 0; i < index; ++i)
    start += sizeAttr[i];
  return {start, sizeAttr[index]};
}

::mlir::DictionaryAttr AllocTensorOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

::mlir::Attribute AllocTensorOpGenericAdaptorBase::getMemorySpaceAttr() {
  auto attr = ::llvm::dyn_cast_or_null<::mlir::Attribute>(getProperties().memory_space);
  return attr;
}

::std::optional<::mlir::Attribute> AllocTensorOpGenericAdaptorBase::getMemorySpace() {
  auto attr = getMemorySpaceAttr();
  return attr ? ::std::optional<::mlir::Attribute>(attr) : (::std::nullopt);
}

} // namespace detail
AllocTensorOpAdaptor::AllocTensorOpAdaptor(AllocTensorOp op) : AllocTensorOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AllocTensorOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_memory_space = getProperties().memory_space; (void)tblgen_memory_space;

  if (tblgen_memory_space && !((true)))
    return emitError(loc, "'bufferization.alloc_tensor' op ""attribute 'memory_space' failed to satisfy constraint: any attribute");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AllocTensorOp::getODSOperandIndexAndLength(unsigned index) {
  ::llvm::ArrayRef<int32_t> sizeAttr = getProperties().odsOperandSegmentSizes;

  unsigned start = 0;
  for (unsigned i = 0; i < index; ++i)
    start += sizeAttr[i];
  return {start, sizeAttr[index]};
}

::mlir::Operation::operand_range AllocTensorOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::operand_range AllocTensorOp::getDynamicSizes() {
  return getODSOperands(0);
}

::mlir::TypedValue<::mlir::TensorType> AllocTensorOp::getCopy() {
  auto operands = getODSOperands(1);
  return operands.empty() ? ::mlir::TypedValue<::mlir::TensorType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*operands.begin());
}

::mlir::TypedValue<::mlir::IndexType> AllocTensorOp::getSizeHint() {
  auto operands = getODSOperands(2);
  return operands.empty() ? ::mlir::TypedValue<::mlir::IndexType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::IndexType>>(*operands.begin());
}

::mlir::MutableOperandRange AllocTensorOp::getDynamicSizesMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second, ::mlir::MutableOperandRange::OperandSegment(0u, {getOperandSegmentSizesAttrName(), DenseI32ArrayAttr::get(getContext(), getProperties().odsOperandSegmentSizes)}));
  return mutableRange;
}

::mlir::MutableOperandRange AllocTensorOp::getCopyMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second, ::mlir::MutableOperandRange::OperandSegment(1u, {getOperandSegmentSizesAttrName(), DenseI32ArrayAttr::get(getContext(), getProperties().odsOperandSegmentSizes)}));
  return mutableRange;
}

::mlir::MutableOperandRange AllocTensorOp::getSizeHintMutable() {
  auto range = getODSOperandIndexAndLength(2);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second, ::mlir::MutableOperandRange::OperandSegment(2u, {getOperandSegmentSizesAttrName(), DenseI32ArrayAttr::get(getContext(), getProperties().odsOperandSegmentSizes)}));
  return mutableRange;
}

std::pair<unsigned, unsigned> AllocTensorOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AllocTensorOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::TensorType> AllocTensorOp::getResult() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
}

::mlir::LogicalResult AllocTensorOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    if (diag)
      *diag << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.memory_space;
       auto attr = dict.get("memory_space");
    if (attr || /*isRequired=*/false) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for memory_space in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `memory_space` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
;
    {
      auto setFromAttr = [] (auto &propStorage, ::mlir::Attribute propAttr,
                             ::mlir::InFlightDiagnostic *propDiag) {
        return convertFromAttribute(propStorage, propAttr, propDiag);;
      };
         auto attr = dict.get("odsOperandSegmentSizes");   if (!attr) attr = dict.get("operand_segment_sizes");;
      if (!attr) {
        if (diag)
          *diag << "expected key entry for odsOperandSegmentSizes in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      if (::mlir::failed(setFromAttr(prop.odsOperandSegmentSizes, attr, diag)))
        return ::mlir::failure();
    }
  return ::mlir::success();
}

::mlir::Attribute AllocTensorOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.memory_space;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("memory_space",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.odsOperandSegmentSizes;
      attrs.push_back(odsBuilder.getNamedAttr("odsOperandSegmentSizes",
                                              DenseI32ArrayAttr::get(ctx, propStorage)));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code AllocTensorOp::computePropertiesHash(const Properties &prop) {
  auto hash_odsOperandSegmentSizes = [] (const auto &propStorage) -> llvm::hash_code {
    return llvm::hash_combine_range(std::begin(propStorage), std::end(propStorage));;
  };
  return llvm::hash_combine(
    llvm::hash_value(prop.memory_space.getAsOpaquePointer()), 
    hash_odsOperandSegmentSizes(prop.odsOperandSegmentSizes));
}

std::optional<mlir::Attribute> AllocTensorOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "memory_space")
      return prop.memory_space;
    if (name == "odsOperandSegmentSizes" || name == "operand_segment_sizes") return DenseI32ArrayAttr::get(ctx, prop.odsOperandSegmentSizes);
  return std::nullopt;
}

void AllocTensorOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "memory_space") {
       prop.memory_space = dyn_cast_or_null<std::remove_reference_t<decltype(prop.memory_space)>>(value);
       return;
    }
        if (name == "odsOperandSegmentSizes" || name == "operand_segment_sizes") {
       auto arrAttr = dyn_cast_or_null<DenseI32ArrayAttr>(value);
       if (!arrAttr) return;
       if (arrAttr.size() != sizeof(prop.odsOperandSegmentSizes) / sizeof(int32_t))
         return;
       llvm::copy(arrAttr.asArrayRef(), prop.odsOperandSegmentSizes);
       return;
    }
}

void AllocTensorOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.memory_space) attrs.append("memory_space", prop.memory_space);
  attrs.append("operand_segment_sizes", DenseI32ArrayAttr::get(ctx, prop.odsOperandSegmentSizes));
}

::mlir::LogicalResult AllocTensorOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
    {
      ::mlir::Attribute attr = attrs.get(getMemorySpaceAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_BufferizationOps0(attr, "memory_space", getDiag)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::mlir::LogicalResult AllocTensorOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readOptionalAttribute(prop.memory_space)))
    return ::mlir::failure();

  {
    auto &propStorage = prop.odsOperandSegmentSizes;
    auto readProp = [&]() {

if (reader.getBytecodeVersion() < /*kNativePropertiesODSSegmentSize=*/6) {
  DenseI32ArrayAttr attr;
  if (::mlir::failed(reader.readAttribute(attr))) return failure();
  if (attr.size() > static_cast<int64_t>(sizeof(propStorage) / sizeof(int32_t))) {
    reader.emitError("size mismatch for operand/result_segment_size");
    return failure();
  }
  llvm::copy(ArrayRef<int32_t>(attr), propStorage);
} else {
  return reader.readSparseArray(MutableArrayRef(propStorage));
}
;
      return ::mlir::success();
    };
    if (::mlir::failed(readProp()))
      return ::mlir::failure();
  }
  return ::mlir::success();
}

void AllocTensorOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;

  writer.writeOptionalAttribute(prop.memory_space);

  {
    auto &propStorage = prop.odsOperandSegmentSizes;

if (writer.getBytecodeVersion() < /*kNativePropertiesODSSegmentSize=*/6)
  writer.writeAttribute(DenseI32ArrayAttr::get(getContext(), propStorage));
else
  writer.writeSparseArray(ArrayRef(propStorage));
;
  }
}

::mlir::Attribute AllocTensorOp::getMemorySpaceAttr() {
  return ::llvm::dyn_cast_or_null<::mlir::Attribute>(getProperties().memory_space);
}

::std::optional<::mlir::Attribute> AllocTensorOp::getMemorySpace() {
  auto attr = getMemorySpaceAttr();
  return attr ? ::std::optional<::mlir::Attribute>(attr) : (::std::nullopt);
}

void AllocTensorOp::setMemorySpaceAttr(::mlir::Attribute attr) {
  (*this)->setAttr(getMemorySpaceAttrName(), attr);
}

::mlir::Attribute AllocTensorOp::removeMemorySpaceAttr() {
    auto &attr = getProperties().memory_space;
    attr = {};
    return attr;
}

void AllocTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::ValueRange dynamic_sizes, /*optional*/::mlir::Value copy, /*optional*/::mlir::Value size_hint, /*optional*/::mlir::Attribute memory_space) {
  odsState.addOperands(dynamic_sizes);
  if (copy)
    odsState.addOperands(copy);
  if (size_hint)
    odsState.addOperands(size_hint);
  llvm::copy(ArrayRef<int32_t>({static_cast<int32_t>(dynamic_sizes.size()), (copy ? 1 : 0), (size_hint ? 1 : 0)}), odsState.getOrAddProperties<Properties>().odsOperandSegmentSizes);
  if (memory_space) {
    odsState.getOrAddProperties<Properties>().memory_space = memory_space;
  }
  odsState.addTypes(result);
}

void AllocTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange dynamic_sizes, /*optional*/::mlir::Value copy, /*optional*/::mlir::Value size_hint, /*optional*/::mlir::Attribute memory_space) {
  odsState.addOperands(dynamic_sizes);
  if (copy)
    odsState.addOperands(copy);
  if (size_hint)
    odsState.addOperands(size_hint);
  llvm::copy(ArrayRef<int32_t>({static_cast<int32_t>(dynamic_sizes.size()), (copy ? 1 : 0), (size_hint ? 1 : 0)}), odsState.getOrAddProperties<Properties>().odsOperandSegmentSizes);
  if (memory_space) {
    odsState.getOrAddProperties<Properties>().memory_space = memory_space;
  }
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AllocTensorOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AllocTensorOp::verifyInvariantsImpl() {
  auto tblgen_memory_space = getProperties().memory_space; (void)tblgen_memory_space;

  if (::mlir::failed(__mlir_ods_local_attr_constraint_BufferizationOps0(*this, tblgen_memory_space, "memory_space")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    if (valueGroup1.size() > 1) {
      return emitOpError("operand group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup1.size();
    }

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    if (valueGroup2.size() > 1) {
      return emitOpError("operand group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup2.size();
    }

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AllocTensorOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

} // namespace bufferization
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::bufferization::AllocTensorOp)

namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::CloneOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
CloneOpGenericAdaptorBase::CloneOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("bufferization.clone", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> CloneOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr CloneOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
CloneOpAdaptor::CloneOpAdaptor(CloneOp op) : CloneOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult CloneOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> CloneOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range CloneOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::BaseMemRefType> CloneOp::getInput() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::BaseMemRefType>>(*getODSOperands(0).begin());
}

::mlir::MutableOperandRange CloneOp::getInputMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> CloneOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range CloneOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::BaseMemRefType> CloneOp::getOutput() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::BaseMemRefType>>(*getODSResults(0).begin());
}

void CloneOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value value) {
      return build(odsBuilder, odsState, value.getType(), value);
    
}

void CloneOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type output, ::mlir::Value input) {
  odsState.addOperands(input);
  odsState.addTypes(output);
}

void CloneOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input) {
  odsState.addOperands(input);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void CloneOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult CloneOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult CloneOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult CloneOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand inputRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> inputOperands(inputRawOperands);  ::llvm::SMLoc inputOperandsLoc;
  (void)inputOperandsLoc;
  ::mlir::Type inputRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> inputTypes(inputRawTypes);
  ::mlir::Type outputRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> outputTypes(outputRawTypes);

  inputOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(inputRawOperands[0]))
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::BaseMemRefType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    inputRawTypes[0] = type;
  }
  if (parser.parseKeyword("to"))
    return ::mlir::failure();

  {
    ::mlir::BaseMemRefType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    outputRawTypes[0] = type;
  }
  result.addTypes(outputTypes);
  if (parser.resolveOperands(inputOperands, inputTypes, inputOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void CloneOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getInput();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getInput().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::BaseMemRefType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ' ' << "to";
  _odsPrinter << ' ';
  {
    auto type = getOutput().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::BaseMemRefType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

} // namespace bufferization
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::bufferization::CloneOp)

namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::CopyTensorOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
CopyTensorOpGenericAdaptorBase::CopyTensorOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("bufferization.copy_tensor", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> CopyTensorOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr CopyTensorOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
CopyTensorOpAdaptor::CopyTensorOpAdaptor(CopyTensorOp op) : CopyTensorOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult CopyTensorOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> CopyTensorOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range CopyTensorOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::TensorType> CopyTensorOp::getSource() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
}

::mlir::TypedValue<::mlir::TensorType> CopyTensorOp::getDest() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(1).begin());
}

::mlir::MutableOperandRange CopyTensorOp::getSourceMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::mlir::MutableOperandRange CopyTensorOp::getDestMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> CopyTensorOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range CopyTensorOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::TensorType> CopyTensorOp::getResult() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
}

void CopyTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value source, ::mlir::Value dest) {
  odsState.addOperands(source);
  odsState.addOperands(dest);
  odsState.addTypes(result);
}

void CopyTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value source, ::mlir::Value dest) {
  odsState.addOperands(source);
  odsState.addOperands(dest);

        ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
        if (::mlir::succeeded(CopyTensorOp::inferReturnTypes(odsBuilder.getContext(),
                      odsState.location, odsState.operands,
                      odsState.attributes.getDictionary(odsState.getContext()),
                      odsState.getRawProperties(),
                      odsState.regions, inferredReturnTypes)))
          odsState.addTypes(inferredReturnTypes);
        else
          ::llvm::report_fatal_error("Failed to infer result type(s).");
}

void CopyTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::Value dest) {
  odsState.addOperands(source);
  odsState.addOperands(dest);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void CopyTensorOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

void CopyTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);

  ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
  if (::mlir::succeeded(CopyTensorOp::inferReturnTypes(odsBuilder.getContext(),
          odsState.location, operands,
          odsState.attributes.getDictionary(odsState.getContext()),
          odsState.getRawProperties(),
          odsState.regions, inferredReturnTypes))) {
    assert(inferredReturnTypes.size() == 1u && "mismatched number of return types");
    odsState.addTypes(inferredReturnTypes);
  } else {
    ::llvm::report_fatal_error("Failed to infer result type(s).");
  }
}

::mlir::LogicalResult CopyTensorOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult CopyTensorOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::LogicalResult CopyTensorOp::inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes) {
  inferredReturnTypes.resize(1);
  ::mlir::Builder odsBuilder(context);
  ::mlir::Type odsInferredType0 = operands[0].getType();
  inferredReturnTypes[0] = odsInferredType0;
  return ::mlir::success();
}

::mlir::ParseResult CopyTensorOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand sourceRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> sourceOperands(sourceRawOperands);  ::llvm::SMLoc sourceOperandsLoc;
  (void)sourceOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand destRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> destOperands(destRawOperands);  ::llvm::SMLoc destOperandsLoc;
  (void)destOperandsLoc;
  ::mlir::Type sourceRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> sourceTypes(sourceRawTypes);

  sourceOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(sourceRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  destOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(destRawOperands[0]))
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::TensorType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    sourceRawTypes[0] = type;
  }
  result.addTypes(sourceTypes[0]);
  if (parser.resolveOperands(sourceOperands, sourceTypes, sourceOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(destOperands, sourceTypes[0], destOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void CopyTensorOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getSource();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getDest();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getSource().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::TensorType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

} // namespace bufferization
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::bufferization::CopyTensorOp)

namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::DeallocOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
DeallocOpGenericAdaptorBase::DeallocOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("bufferization.dealloc", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> DeallocOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  ::llvm::ArrayRef<int32_t> sizeAttr = getProperties().odsOperandSegmentSizes;

  unsigned start = 0;
  for (unsigned i = 0; i < index; ++i)
    start += sizeAttr[i];
  return {start, sizeAttr[index]};
}

::mlir::DictionaryAttr DeallocOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
DeallocOpAdaptor::DeallocOpAdaptor(DeallocOp op) : DeallocOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult DeallocOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> DeallocOp::getODSOperandIndexAndLength(unsigned index) {
  ::llvm::ArrayRef<int32_t> sizeAttr = getProperties().odsOperandSegmentSizes;

  unsigned start = 0;
  for (unsigned i = 0; i < index; ++i)
    start += sizeAttr[i];
  return {start, sizeAttr[index]};
}

::mlir::Operation::operand_range DeallocOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::operand_range DeallocOp::getMemrefs() {
  return getODSOperands(0);
}

::mlir::Operation::operand_range DeallocOp::getConditions() {
  return getODSOperands(1);
}

::mlir::Operation::operand_range DeallocOp::getRetained() {
  return getODSOperands(2);
}

::mlir::MutableOperandRange DeallocOp::getMemrefsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second, ::mlir::MutableOperandRange::OperandSegment(0u, {getOperandSegmentSizesAttrName(), DenseI32ArrayAttr::get(getContext(), getProperties().odsOperandSegmentSizes)}));
  return mutableRange;
}

::mlir::MutableOperandRange DeallocOp::getConditionsMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second, ::mlir::MutableOperandRange::OperandSegment(1u, {getOperandSegmentSizesAttrName(), DenseI32ArrayAttr::get(getContext(), getProperties().odsOperandSegmentSizes)}));
  return mutableRange;
}

::mlir::MutableOperandRange DeallocOp::getRetainedMutable() {
  auto range = getODSOperandIndexAndLength(2);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second, ::mlir::MutableOperandRange::OperandSegment(2u, {getOperandSegmentSizesAttrName(), DenseI32ArrayAttr::get(getContext(), getProperties().odsOperandSegmentSizes)}));
  return mutableRange;
}

std::pair<unsigned, unsigned> DeallocOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::result_range DeallocOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::result_range DeallocOp::getUpdatedConditions() {
  return getODSResults(0);
}

::mlir::LogicalResult DeallocOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    if (diag)
      *diag << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }
    ;
    {
      auto setFromAttr = [] (auto &propStorage, ::mlir::Attribute propAttr,
                             ::mlir::InFlightDiagnostic *propDiag) {
        return convertFromAttribute(propStorage, propAttr, propDiag);;
      };
         auto attr = dict.get("odsOperandSegmentSizes");   if (!attr) attr = dict.get("operand_segment_sizes");;
      if (!attr) {
        if (diag)
          *diag << "expected key entry for odsOperandSegmentSizes in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      if (::mlir::failed(setFromAttr(prop.odsOperandSegmentSizes, attr, diag)))
        return ::mlir::failure();
    }
  return ::mlir::success();
}

::mlir::Attribute DeallocOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.odsOperandSegmentSizes;
      attrs.push_back(odsBuilder.getNamedAttr("odsOperandSegmentSizes",
                                              DenseI32ArrayAttr::get(ctx, propStorage)));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code DeallocOp::computePropertiesHash(const Properties &prop) {
  auto hash_odsOperandSegmentSizes = [] (const auto &propStorage) -> llvm::hash_code {
    return llvm::hash_combine_range(std::begin(propStorage), std::end(propStorage));;
  };
  return llvm::hash_combine(
    hash_odsOperandSegmentSizes(prop.odsOperandSegmentSizes));
}

std::optional<mlir::Attribute> DeallocOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "odsOperandSegmentSizes" || name == "operand_segment_sizes") return DenseI32ArrayAttr::get(ctx, prop.odsOperandSegmentSizes);
  return std::nullopt;
}

void DeallocOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
        if (name == "odsOperandSegmentSizes" || name == "operand_segment_sizes") {
       auto arrAttr = dyn_cast_or_null<DenseI32ArrayAttr>(value);
       if (!arrAttr) return;
       if (arrAttr.size() != sizeof(prop.odsOperandSegmentSizes) / sizeof(int32_t))
         return;
       llvm::copy(arrAttr.asArrayRef(), prop.odsOperandSegmentSizes);
       return;
    }
}

void DeallocOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
  attrs.append("operand_segment_sizes", DenseI32ArrayAttr::get(ctx, prop.odsOperandSegmentSizes));
}

::mlir::LogicalResult DeallocOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
    return ::mlir::success();
}

::mlir::LogicalResult DeallocOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  {
    auto &propStorage = prop.odsOperandSegmentSizes;
    auto readProp = [&]() {

if (reader.getBytecodeVersion() < /*kNativePropertiesODSSegmentSize=*/6) {
  DenseI32ArrayAttr attr;
  if (::mlir::failed(reader.readAttribute(attr))) return failure();
  if (attr.size() > static_cast<int64_t>(sizeof(propStorage) / sizeof(int32_t))) {
    reader.emitError("size mismatch for operand/result_segment_size");
    return failure();
  }
  llvm::copy(ArrayRef<int32_t>(attr), propStorage);
} else {
  return reader.readSparseArray(MutableArrayRef(propStorage));
}
;
      return ::mlir::success();
    };
    if (::mlir::failed(readProp()))
      return ::mlir::failure();
  }
  return ::mlir::success();
}

void DeallocOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;

  {
    auto &propStorage = prop.odsOperandSegmentSizes;

if (writer.getBytecodeVersion() < /*kNativePropertiesODSSegmentSize=*/6)
  writer.writeAttribute(DenseI32ArrayAttr::get(getContext(), propStorage));
else
  writer.writeSparseArray(ArrayRef(propStorage));
;
  }
}

void DeallocOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange updatedConditions, ::mlir::ValueRange memrefs, ::mlir::ValueRange conditions, ::mlir::ValueRange retained) {
  odsState.addOperands(memrefs);
  odsState.addOperands(conditions);
  odsState.addOperands(retained);
  llvm::copy(ArrayRef<int32_t>({static_cast<int32_t>(memrefs.size()), static_cast<int32_t>(conditions.size()), static_cast<int32_t>(retained.size())}), odsState.getOrAddProperties<Properties>().odsOperandSegmentSizes);
  odsState.addTypes(updatedConditions);
}

void DeallocOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange memrefs, ::mlir::ValueRange conditions, ::mlir::ValueRange retained) {
  odsState.addOperands(memrefs);
  odsState.addOperands(conditions);
  odsState.addOperands(retained);
  llvm::copy(ArrayRef<int32_t>({static_cast<int32_t>(memrefs.size()), static_cast<int32_t>(conditions.size()), static_cast<int32_t>(retained.size())}), odsState.getOrAddProperties<Properties>().odsOperandSegmentSizes);

        ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
        if (::mlir::succeeded(DeallocOp::inferReturnTypes(odsBuilder.getContext(),
                      odsState.location, odsState.operands,
                      odsState.attributes.getDictionary(odsState.getContext()),
                      odsState.getRawProperties(),
                      odsState.regions, inferredReturnTypes)))
          odsState.addTypes(inferredReturnTypes);
        else
          ::llvm::report_fatal_error("Failed to infer result type(s).");
}

void DeallocOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  odsState.addTypes(resultTypes);
}

void DeallocOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);

  ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
  if (::mlir::succeeded(DeallocOp::inferReturnTypes(odsBuilder.getContext(),
          odsState.location, operands,
          odsState.attributes.getDictionary(odsState.getContext()),
          odsState.getRawProperties(),
          odsState.regions, inferredReturnTypes))) {
    odsState.addTypes(inferredReturnTypes);
  } else {
    ::llvm::report_fatal_error("Failed to infer result type(s).");
  }
}

::mlir::LogicalResult DeallocOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps3(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult DeallocOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::mlir::ParseResult DeallocOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::llvm::SmallVector<::mlir::OpAsmParser::UnresolvedOperand, 4> memrefsOperands;
  ::llvm::SMLoc memrefsOperandsLoc;
  (void)memrefsOperandsLoc;
  ::llvm::SmallVector<::mlir::Type, 1> memrefsTypes;
  ::llvm::SmallVector<::mlir::OpAsmParser::UnresolvedOperand, 4> conditionsOperands;
  ::llvm::SMLoc conditionsOperandsLoc;
  (void)conditionsOperandsLoc;
  ::llvm::SmallVector<::mlir::OpAsmParser::UnresolvedOperand, 4> retainedOperands;
  ::llvm::SMLoc retainedOperandsLoc;
  (void)retainedOperandsLoc;
  ::llvm::SmallVector<::mlir::Type, 1> retainedTypes;
  if (::mlir::succeeded(parser.parseOptionalLParen())) {

  memrefsOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperandList(memrefsOperands))
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();

  if (parser.parseTypeList(memrefsTypes))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseKeyword("if"))
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  conditionsOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperandList(conditionsOperands))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  }
  if (::mlir::succeeded(parser.parseOptionalKeyword("retain"))) {
  if (parser.parseLParen())
    return ::mlir::failure();

  retainedOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperandList(retainedOperands))
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();

  if (parser.parseTypeList(retainedTypes))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  }
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
llvm::copy(ArrayRef<int32_t>({static_cast<int32_t>(memrefsOperands.size()), static_cast<int32_t>(conditionsOperands.size()), static_cast<int32_t>(retainedOperands.size())}), result.getOrAddProperties<DeallocOp::Properties>().odsOperandSegmentSizes);
  ::mlir::Type odsBuildableType0 = parser.getBuilder().getIntegerType(1);
  if (parser.resolveOperands(memrefsOperands, memrefsTypes, memrefsOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(conditionsOperands, odsBuildableType0, conditionsOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(retainedOperands, retainedTypes, retainedOperandsLoc, result.operands))
    return ::mlir::failure();

  ::llvm::SmallVector<::mlir::Type> inferredReturnTypes;
  if (::mlir::failed(DeallocOp::inferReturnTypes(parser.getContext(),
      result.location, result.operands,
      result.attributes.getDictionary(parser.getContext()),
      result.getRawProperties(),
      result.regions, inferredReturnTypes)))
    return ::mlir::failure();
  result.addTypes(inferredReturnTypes);
  return ::mlir::success();
}

void DeallocOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  if (!getMemrefs().empty()) {
    _odsPrinter << ' ';
    _odsPrinter << "(";
    _odsPrinter << getMemrefs();
    _odsPrinter << ' ' << ":";
    _odsPrinter << ' ';
    _odsPrinter << getMemrefs().getTypes();
    _odsPrinter << ")";
    _odsPrinter << ' ' << "if";
    _odsPrinter << ' ';
    _odsPrinter << "(";
    _odsPrinter << getConditions();
    _odsPrinter << ")";
  }
  if (!getRetained().empty()) {
    _odsPrinter << ' ' << "retain";
    _odsPrinter << ' ';
    _odsPrinter << "(";
    _odsPrinter << getRetained();
    _odsPrinter << ' ' << ":";
    _odsPrinter << ' ';
    _odsPrinter << getRetained().getTypes();
    _odsPrinter << ")";
  }
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  elidedAttrs.push_back("operand_segment_sizes");
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
}

} // namespace bufferization
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::bufferization::DeallocOp)

namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::DeallocTensorOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
DeallocTensorOpGenericAdaptorBase::DeallocTensorOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("bufferization.dealloc_tensor", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> DeallocTensorOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr DeallocTensorOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
DeallocTensorOpAdaptor::DeallocTensorOpAdaptor(DeallocTensorOp op) : DeallocTensorOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult DeallocTensorOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> DeallocTensorOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range DeallocTensorOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::TensorType> DeallocTensorOp::getTensor() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
}

::mlir::MutableOperandRange DeallocTensorOp::getTensorMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> DeallocTensorOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range DeallocTensorOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

void DeallocTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor) {
  odsState.addOperands(tensor);
}

void DeallocTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor) {
  odsState.addOperands(tensor);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void DeallocTensorOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult DeallocTensorOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult DeallocTensorOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult DeallocTensorOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand tensorRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> tensorOperands(tensorRawOperands);  ::llvm::SMLoc tensorOperandsLoc;
  (void)tensorOperandsLoc;
  ::mlir::Type tensorRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> tensorTypes(tensorRawTypes);

  tensorOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(tensorRawOperands[0]))
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::TensorType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    tensorRawTypes[0] = type;
  }
  if (parser.resolveOperands(tensorOperands, tensorTypes, tensorOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void DeallocTensorOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getTensor();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getTensor().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::TensorType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

} // namespace bufferization
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::bufferization::DeallocTensorOp)

namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::ToMemrefOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
ToMemrefOpGenericAdaptorBase::ToMemrefOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("bufferization.to_memref", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> ToMemrefOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr ToMemrefOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

::mlir::UnitAttr ToMemrefOpGenericAdaptorBase::getReadOnlyAttr() {
  auto attr = ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().read_only);
  if (!attr)
    attr = ((false) ? ::mlir::Builder(odsAttrs.getContext()).getUnitAttr() : nullptr);
  return attr;
}

bool ToMemrefOpGenericAdaptorBase::getReadOnly() {
  auto attr = getReadOnlyAttr();
    if (!attr)
      return ((false) ? ::mlir::Builder(odsAttrs.getContext()).getUnitAttr() : nullptr) != nullptr;
  return attr != nullptr;
}

} // namespace detail
ToMemrefOpAdaptor::ToMemrefOpAdaptor(ToMemrefOp op) : ToMemrefOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult ToMemrefOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_read_only = getProperties().read_only; (void)tblgen_read_only;

  if (tblgen_read_only && !((::llvm::isa<::mlir::UnitAttr>(tblgen_read_only))))
    return emitError(loc, "'bufferization.to_memref' op ""attribute 'read_only' failed to satisfy constraint: unit attribute");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> ToMemrefOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range ToMemrefOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::TensorType> ToMemrefOp::getTensor() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
}

::mlir::MutableOperandRange ToMemrefOp::getTensorMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> ToMemrefOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range ToMemrefOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::BaseMemRefType> ToMemrefOp::getMemref() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::BaseMemRefType>>(*getODSResults(0).begin());
}

::mlir::LogicalResult ToMemrefOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    if (diag)
      *diag << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.read_only;
       auto attr = dict.get("read_only");
    if (attr || /*isRequired=*/false) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for read_only in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `read_only` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute ToMemrefOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.read_only;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("read_only",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code ToMemrefOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.read_only.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> ToMemrefOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "read_only")
      return prop.read_only;
  return std::nullopt;
}

void ToMemrefOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "read_only") {
       prop.read_only = dyn_cast_or_null<std::remove_reference_t<decltype(prop.read_only)>>(value);
       return;
    }
}

void ToMemrefOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.read_only) attrs.append("read_only", prop.read_only);
}

::mlir::LogicalResult ToMemrefOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
    {
      ::mlir::Attribute attr = attrs.get(getReadOnlyAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_BufferizationOps1(attr, "read_only", getDiag)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::mlir::LogicalResult ToMemrefOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readOptionalAttribute(prop.read_only)))
    return ::mlir::failure();
  return ::mlir::success();
}

void ToMemrefOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;

  writer.writeOptionalAttribute(prop.read_only);
}

::mlir::UnitAttr ToMemrefOp::getReadOnlyAttr() {
  return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().read_only);
}

bool ToMemrefOp::getReadOnly() {
  auto attr = getReadOnlyAttr();
    if (!attr)
      return ((false) ? ::mlir::Builder((*this)->getContext()).getUnitAttr() : nullptr) != nullptr;
  return attr != nullptr;
}

void ToMemrefOp::setReadOnlyAttr(::mlir::UnitAttr attr) {
  (*this)->setAttr(getReadOnlyAttrName(), attr);
}

void ToMemrefOp::setReadOnly(bool attrValue) {
    if (attrValue)
      return (*this)->setAttr(getReadOnlyAttrName(), ((attrValue) ? ::mlir::Builder((*this)->getContext()).getUnitAttr() : nullptr));
    (*this)->removeAttr(getReadOnlyAttrName());
}

::mlir::Attribute ToMemrefOp::removeReadOnlyAttr() {
    auto &attr = getProperties().read_only;
    attr = {};
    return attr;
}

void ToMemrefOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type memref, ::mlir::Value tensor, /*optional*/::mlir::UnitAttr read_only) {
  odsState.addOperands(tensor);
  if (read_only) {
    odsState.getOrAddProperties<Properties>().read_only = read_only;
  }
  odsState.addTypes(memref);
}

void ToMemrefOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, /*optional*/::mlir::UnitAttr read_only) {
  odsState.addOperands(tensor);
  if (read_only) {
    odsState.getOrAddProperties<Properties>().read_only = read_only;
  }
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ToMemrefOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type memref, ::mlir::Value tensor, /*optional*/bool read_only) {
  odsState.addOperands(tensor);
  if (read_only) {
    odsState.getOrAddProperties<Properties>().read_only = ((read_only) ? odsBuilder.getUnitAttr() : nullptr);
  }
  odsState.addTypes(memref);
}

void ToMemrefOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, /*optional*/bool read_only) {
  odsState.addOperands(tensor);
  if (read_only) {
    odsState.getOrAddProperties<Properties>().read_only = ((read_only) ? odsBuilder.getUnitAttr() : nullptr);
  }
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ToMemrefOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult ToMemrefOp::verifyInvariantsImpl() {
  auto tblgen_read_only = getProperties().read_only; (void)tblgen_read_only;

  if (::mlir::failed(__mlir_ods_local_attr_constraint_BufferizationOps1(*this, tblgen_read_only, "read_only")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  if (!((std::equal_to<>()(memref::getTensorTypeFromMemRefType((*this->getODSResults(0).begin()).getType()), (*this->getODSOperands(0).begin()).getType()))))
    return emitOpError("failed to verify that type of 'tensor' is the tensor equivalent of 'memref'");
  return ::mlir::success();
}

::mlir::LogicalResult ToMemrefOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult ToMemrefOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand tensorRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> tensorOperands(tensorRawOperands);  ::llvm::SMLoc tensorOperandsLoc;
  (void)tensorOperandsLoc;
  ::mlir::Type memrefRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> memrefTypes(memrefRawTypes);

  tensorOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(tensorRawOperands[0]))
    return ::mlir::failure();
  if (::mlir::succeeded(parser.parseOptionalKeyword("read_only"))) {
    result.getOrAddProperties<ToMemrefOp::Properties>().read_only = parser.getBuilder().getUnitAttr();  }
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
    if (failed(verifyInherentAttrs(result.name, result.attributes, [&]() {
        return parser.emitError(loc) << "'" << result.name.getStringRef() << "' op ";
      })))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::BaseMemRefType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    memrefRawTypes[0] = type;
  }
  for (::mlir::Type type : memrefTypes) {
    (void)type;
    if (!(((::llvm::isa<::mlir::BaseMemRefType>(type))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>(type).getElementType())))) {
      return parser.emitError(parser.getNameLoc()) << "'memref' must be ranked or unranked memref of any type values, but got " << type;
    }
  }
  result.addTypes(memrefTypes);
  if (parser.resolveOperands(tensorOperands, memref::getTensorTypeFromMemRefType(memrefTypes[0]), tensorOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void ToMemrefOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getTensor();
  if (getReadOnlyAttr()) {
    _odsPrinter << ' ' << "read_only";
  }
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  elidedAttrs.push_back("read_only");
  {
     ::mlir::Builder odsBuilder(getContext());
     ::mlir::Attribute attr = getReadOnlyAttr();
     if(attr && (attr == ((false) ? odsBuilder.getUnitAttr() : nullptr)))
       elidedAttrs.push_back("read_only");
  }
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getMemref().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::BaseMemRefType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

void ToMemrefOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}

} // namespace bufferization
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::bufferization::ToMemrefOp)

namespace mlir {
namespace bufferization {

//===----------------------------------------------------------------------===//
// ::mlir::bufferization::ToTensorOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
ToTensorOpGenericAdaptorBase::ToTensorOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("bufferization.to_tensor", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> ToTensorOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  return {index, 1};
}

::mlir::DictionaryAttr ToTensorOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

::mlir::UnitAttr ToTensorOpGenericAdaptorBase::getRestrictAttr() {
  auto attr = ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().restrict);
  if (!attr)
    attr = ((false) ? ::mlir::Builder(odsAttrs.getContext()).getUnitAttr() : nullptr);
  return attr;
}

bool ToTensorOpGenericAdaptorBase::getRestrict() {
  auto attr = getRestrictAttr();
    if (!attr)
      return ((false) ? ::mlir::Builder(odsAttrs.getContext()).getUnitAttr() : nullptr) != nullptr;
  return attr != nullptr;
}

::mlir::UnitAttr ToTensorOpGenericAdaptorBase::getWritableAttr() {
  auto attr = ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().writable);
  if (!attr)
    attr = ((false) ? ::mlir::Builder(odsAttrs.getContext()).getUnitAttr() : nullptr);
  return attr;
}

bool ToTensorOpGenericAdaptorBase::getWritable() {
  auto attr = getWritableAttr();
    if (!attr)
      return ((false) ? ::mlir::Builder(odsAttrs.getContext()).getUnitAttr() : nullptr) != nullptr;
  return attr != nullptr;
}

} // namespace detail
ToTensorOpAdaptor::ToTensorOpAdaptor(ToTensorOp op) : ToTensorOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult ToTensorOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_restrict = getProperties().restrict; (void)tblgen_restrict;
  auto tblgen_writable = getProperties().writable; (void)tblgen_writable;

  if (tblgen_restrict && !((::llvm::isa<::mlir::UnitAttr>(tblgen_restrict))))
    return emitError(loc, "'bufferization.to_tensor' op ""attribute 'restrict' failed to satisfy constraint: unit attribute");

  if (tblgen_writable && !((::llvm::isa<::mlir::UnitAttr>(tblgen_writable))))
    return emitError(loc, "'bufferization.to_tensor' op ""attribute 'writable' failed to satisfy constraint: unit attribute");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> ToTensorOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range ToTensorOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::BaseMemRefType> ToTensorOp::getMemref() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::BaseMemRefType>>(*getODSOperands(0).begin());
}

::mlir::MutableOperandRange ToTensorOp::getMemrefMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> ToTensorOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range ToTensorOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::TensorType> ToTensorOp::getResult() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
}

::mlir::LogicalResult ToTensorOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    if (diag)
      *diag << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.restrict;
       auto attr = dict.get("restrict");
    if (attr || /*isRequired=*/false) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for restrict in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `restrict` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.writable;
       auto attr = dict.get("writable");
    if (attr || /*isRequired=*/false) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for writable in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `writable` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute ToTensorOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.restrict;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("restrict",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.writable;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("writable",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code ToTensorOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.restrict.getAsOpaquePointer()), 
    llvm::hash_value(prop.writable.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> ToTensorOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "restrict")
      return prop.restrict;

    if (name == "writable")
      return prop.writable;
  return std::nullopt;
}

void ToTensorOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "restrict") {
       prop.restrict = dyn_cast_or_null<std::remove_reference_t<decltype(prop.restrict)>>(value);
       return;
    }

    if (name == "writable") {
       prop.writable = dyn_cast_or_null<std::remove_reference_t<decltype(prop.writable)>>(value);
       return;
    }
}

void ToTensorOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.restrict) attrs.append("restrict", prop.restrict);

    if (prop.writable) attrs.append("writable", prop.writable);
}

::mlir::LogicalResult ToTensorOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
    {
      ::mlir::Attribute attr = attrs.get(getRestrictAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_BufferizationOps1(attr, "restrict", getDiag)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getWritableAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_BufferizationOps1(attr, "writable", getDiag)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::mlir::LogicalResult ToTensorOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readOptionalAttribute(prop.restrict)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readOptionalAttribute(prop.writable)))
    return ::mlir::failure();
  return ::mlir::success();
}

void ToTensorOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;

  writer.writeOptionalAttribute(prop.restrict);

  writer.writeOptionalAttribute(prop.writable);
}

::mlir::UnitAttr ToTensorOp::getRestrictAttr() {
  return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().restrict);
}

bool ToTensorOp::getRestrict() {
  auto attr = getRestrictAttr();
    if (!attr)
      return ((false) ? ::mlir::Builder((*this)->getContext()).getUnitAttr() : nullptr) != nullptr;
  return attr != nullptr;
}

::mlir::UnitAttr ToTensorOp::getWritableAttr() {
  return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().writable);
}

bool ToTensorOp::getWritable() {
  auto attr = getWritableAttr();
    if (!attr)
      return ((false) ? ::mlir::Builder((*this)->getContext()).getUnitAttr() : nullptr) != nullptr;
  return attr != nullptr;
}

void ToTensorOp::setRestrictAttr(::mlir::UnitAttr attr) {
  (*this)->setAttr(getRestrictAttrName(), attr);
}

void ToTensorOp::setRestrict(bool attrValue) {
    if (attrValue)
      return (*this)->setAttr(getRestrictAttrName(), ((attrValue) ? ::mlir::Builder((*this)->getContext()).getUnitAttr() : nullptr));
    (*this)->removeAttr(getRestrictAttrName());
}

void ToTensorOp::setWritableAttr(::mlir::UnitAttr attr) {
  (*this)->setAttr(getWritableAttrName(), attr);
}

void ToTensorOp::setWritable(bool attrValue) {
    if (attrValue)
      return (*this)->setAttr(getWritableAttrName(), ((attrValue) ? ::mlir::Builder((*this)->getContext()).getUnitAttr() : nullptr));
    (*this)->removeAttr(getWritableAttrName());
}

::mlir::Attribute ToTensorOp::removeRestrictAttr() {
    auto &attr = getProperties().restrict;
    attr = {};
    return attr;
}

::mlir::Attribute ToTensorOp::removeWritableAttr() {
    auto &attr = getProperties().writable;
    attr = {};
    return attr;
}

void ToTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value memref, /*optional*/::mlir::UnitAttr restrict, /*optional*/::mlir::UnitAttr writable) {
  odsState.addOperands(memref);
  if (restrict) {
    odsState.getOrAddProperties<Properties>().restrict = restrict;
  }
  if (writable) {
    odsState.getOrAddProperties<Properties>().writable = writable;
  }
  odsState.addTypes(result);
}

void ToTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value memref, /*optional*/::mlir::UnitAttr restrict, /*optional*/::mlir::UnitAttr writable) {
  odsState.addOperands(memref);
  if (restrict) {
    odsState.getOrAddProperties<Properties>().restrict = restrict;
  }
  if (writable) {
    odsState.getOrAddProperties<Properties>().writable = writable;
  }

        ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
        if (::mlir::succeeded(ToTensorOp::inferReturnTypes(odsBuilder.getContext(),
                      odsState.location, odsState.operands,
                      odsState.attributes.getDictionary(odsState.getContext()),
                      odsState.getRawProperties(),
                      odsState.regions, inferredReturnTypes)))
          odsState.addTypes(inferredReturnTypes);
        else
          ::llvm::report_fatal_error("Failed to infer result type(s).");
}

void ToTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value memref, /*optional*/::mlir::UnitAttr restrict, /*optional*/::mlir::UnitAttr writable) {
  odsState.addOperands(memref);
  if (restrict) {
    odsState.getOrAddProperties<Properties>().restrict = restrict;
  }
  if (writable) {
    odsState.getOrAddProperties<Properties>().writable = writable;
  }
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ToTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value memref, /*optional*/bool restrict, /*optional*/bool writable) {
  odsState.addOperands(memref);
  if (restrict) {
    odsState.getOrAddProperties<Properties>().restrict = ((restrict) ? odsBuilder.getUnitAttr() : nullptr);
  }
  if (writable) {
    odsState.getOrAddProperties<Properties>().writable = ((writable) ? odsBuilder.getUnitAttr() : nullptr);
  }
  odsState.addTypes(result);
}

void ToTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value memref, /*optional*/bool restrict, /*optional*/bool writable) {
  odsState.addOperands(memref);
  if (restrict) {
    odsState.getOrAddProperties<Properties>().restrict = ((restrict) ? odsBuilder.getUnitAttr() : nullptr);
  }
  if (writable) {
    odsState.getOrAddProperties<Properties>().writable = ((writable) ? odsBuilder.getUnitAttr() : nullptr);
  }

        ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
        if (::mlir::succeeded(ToTensorOp::inferReturnTypes(odsBuilder.getContext(),
                      odsState.location, odsState.operands,
                      odsState.attributes.getDictionary(odsState.getContext()),
                      odsState.getRawProperties(),
                      odsState.regions, inferredReturnTypes)))
          odsState.addTypes(inferredReturnTypes);
        else
          ::llvm::report_fatal_error("Failed to infer result type(s).");
}

void ToTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value memref, /*optional*/bool restrict, /*optional*/bool writable) {
  odsState.addOperands(memref);
  if (restrict) {
    odsState.getOrAddProperties<Properties>().restrict = ((restrict) ? odsBuilder.getUnitAttr() : nullptr);
  }
  if (writable) {
    odsState.getOrAddProperties<Properties>().writable = ((writable) ? odsBuilder.getUnitAttr() : nullptr);
  }
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ToTensorOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

void ToTensorOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);

  ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
  if (::mlir::succeeded(ToTensorOp::inferReturnTypes(odsBuilder.getContext(),
          odsState.location, operands,
          odsState.attributes.getDictionary(odsState.getContext()),
          odsState.getRawProperties(),
          odsState.regions, inferredReturnTypes))) {
    assert(inferredReturnTypes.size() == 1u && "mismatched number of return types");
    odsState.addTypes(inferredReturnTypes);
  } else {
    ::llvm::report_fatal_error("Failed to infer result type(s).");
  }
}

::mlir::LogicalResult ToTensorOp::verifyInvariantsImpl() {
  auto tblgen_restrict = getProperties().restrict; (void)tblgen_restrict;
  auto tblgen_writable = getProperties().writable; (void)tblgen_writable;

  if (::mlir::failed(__mlir_ods_local_attr_constraint_BufferizationOps1(*this, tblgen_restrict, "restrict")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_BufferizationOps1(*this, tblgen_writable, "writable")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_BufferizationOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  if (!((std::equal_to<>()(memref::getTensorTypeFromMemRefType((*this->getODSOperands(0).begin()).getType()), (*this->getODSResults(0).begin()).getType()))))
    return emitOpError("failed to verify that result type matches tensor equivalent of 'memref'");
  return ::mlir::success();
}

::mlir::LogicalResult ToTensorOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::LogicalResult ToTensorOp::inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes) {
  inferredReturnTypes.resize(1);
  ::mlir::Builder odsBuilder(context);
  ::mlir::Type odsInferredType0 = memref::getTensorTypeFromMemRefType(operands[0].getType());
  inferredReturnTypes[0] = odsInferredType0;
  return ::mlir::success();
}

::mlir::ParseResult ToTensorOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand memrefRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> memrefOperands(memrefRawOperands);  ::llvm::SMLoc memrefOperandsLoc;
  (void)memrefOperandsLoc;
  ::mlir::Type memrefRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> memrefTypes(memrefRawTypes);

  memrefOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(memrefRawOperands[0]))
    return ::mlir::failure();
  if (::mlir::succeeded(parser.parseOptionalKeyword("restrict"))) {
    result.getOrAddProperties<ToTensorOp::Properties>().restrict = parser.getBuilder().getUnitAttr();  }
  if (::mlir::succeeded(parser.parseOptionalKeyword("writable"))) {
    result.getOrAddProperties<ToTensorOp::Properties>().writable = parser.getBuilder().getUnitAttr();  }
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
    if (failed(verifyInherentAttrs(result.name, result.attributes, [&]() {
        return parser.emitError(loc) << "'" << result.name.getStringRef() << "' op ";
      })))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::BaseMemRefType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    memrefRawTypes[0] = type;
  }
  for (::mlir::Type type : memrefTypes) {
    (void)type;
    if (!(((::llvm::isa<::mlir::BaseMemRefType>(type))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>(type).getElementType())))) {
      return parser.emitError(parser.getNameLoc()) << "'memref' must be ranked or unranked memref of any type values, but got " << type;
    }
  }
  result.addTypes(memref::getTensorTypeFromMemRefType(memrefTypes[0]));
  if (parser.resolveOperands(memrefOperands, memrefTypes, memrefOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void ToTensorOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getMemref();
  if (getRestrictAttr()) {
    _odsPrinter << ' ' << "restrict";
  }
  if (getWritableAttr()) {
    _odsPrinter << ' ' << "writable";
  }
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  elidedAttrs.push_back("restrict");
  elidedAttrs.push_back("writable");
  {
     ::mlir::Builder odsBuilder(getContext());
     ::mlir::Attribute attr = getRestrictAttr();
     if(attr && (attr == ((false) ? odsBuilder.getUnitAttr() : nullptr)))
       elidedAttrs.push_back("restrict");
  }
  {
     ::mlir::Builder odsBuilder(getContext());
     ::mlir::Attribute attr = getWritableAttr();
     if(attr && (attr == ((false) ? odsBuilder.getUnitAttr() : nullptr)))
       elidedAttrs.push_back("writable");
  }
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getMemref().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::BaseMemRefType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

void ToTensorOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
  for (::mlir::Value value : getODSOperands(0))
    effects.emplace_back(::mlir::MemoryEffects::Read::get(), value, ::mlir::SideEffects::DefaultResource::get());
}

} // namespace bufferization
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::bufferization::ToTensorOp)


#endif  // GET_OP_CLASSES

