/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mlir::affine::AffineApplyOp,
::mlir::affine::AffineDelinearizeIndexOp,
::mlir::affine::AffineForOp,
::mlir::affine::AffineIfOp,
::mlir::affine::AffineLoadOp,
::mlir::affine::AffineMaxOp,
::mlir::affine::AffineMinOp,
::mlir::affine::AffineParallelOp,
::mlir::affine::AffinePrefetchOp,
::mlir::affine::AffineStoreOp,
::mlir::affine::AffineVectorLoadOp,
::mlir::affine::AffineVectorStoreOp,
::mlir::affine::AffineYieldOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace affine {

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_AffineOps0(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((::llvm::isa<::mlir::IndexType>(type)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be index, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_AffineOps1(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((true))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be any type, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_AffineOps2(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::MemRefType>(type))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>(type).getElementType())))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be memref of any type values, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_AffineOps3(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((((::llvm::isa<::mlir::VectorType>(type))) && ((::llvm::cast<::mlir::VectorType>(type).getRank() > 0))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>(type).getElementType())))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be vector of any type values, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps0(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
  if (attr && !((::llvm::isa<::mlir::AffineMapAttr>(attr))))
    return getDiag() << "attribute '" << attrName
        << "' failed to satisfy constraint: AffineMap attribute";
  return ::mlir::success();
}
static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps0(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_AffineOps0(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps1(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
  if (attr && !(((::llvm::isa<::mlir::ArrayAttr>(attr))) && (::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>(attr), [&](::mlir::Attribute attr) { return attr && ((::llvm::isa<::mlir::arith::AtomicRMWKindAttr>(attr))); }))))
    return getDiag() << "attribute '" << attrName
        << "' failed to satisfy constraint: Reduction ops";
  return ::mlir::success();
}
static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps1(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_AffineOps1(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps2(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
  if (attr && !(((::llvm::isa<::mlir::DenseIntElementsAttr>(attr))) && ((::llvm::cast<::mlir::DenseIntElementsAttr>(attr).getType().getElementType().isSignlessInteger(32)))))
    return getDiag() << "attribute '" << attrName
        << "' failed to satisfy constraint: 32-bit signless integer elements attribute";
  return ::mlir::success();
}
static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps2(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_AffineOps2(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps3(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
  if (attr && !(((::llvm::isa<::mlir::ArrayAttr>(attr))) && (::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>(attr), [&](::mlir::Attribute attr) { return attr && (((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(64)))); }))))
    return getDiag() << "attribute '" << attrName
        << "' failed to satisfy constraint: 64-bit integer array attribute";
  return ::mlir::success();
}
static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps3(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_AffineOps3(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps4(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
  if (attr && !((::llvm::isa<::mlir::BoolAttr>(attr))))
    return getDiag() << "attribute '" << attrName
        << "' failed to satisfy constraint: bool attribute";
  return ::mlir::success();
}
static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps4(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_AffineOps4(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps5(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
  if (attr && !((((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(32)))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() >= 0)) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() <= 3))))
    return getDiag() << "attribute '" << attrName
        << "' failed to satisfy constraint: 32-bit signless integer attribute whose minimum value is 0 whose maximum value is 3";
  return ::mlir::success();
}
static ::mlir::LogicalResult __mlir_ods_local_attr_constraint_AffineOps5(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_AffineOps5(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::mlir::LogicalResult __mlir_ods_local_region_constraint_AffineOps0(
    ::mlir::Operation *op, ::mlir::Region &region, ::llvm::StringRef regionName,
    unsigned regionIndex) {
  if (!((::llvm::hasNItems(region, 1)))) {
    return op->emitOpError("region #") << regionIndex
        << (regionName.empty() ? " " : " ('" + regionName + "') ")
        << "failed to verify constraint: region with 1 blocks";
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_region_constraint_AffineOps1(
    ::mlir::Operation *op, ::mlir::Region &region, ::llvm::StringRef regionName,
    unsigned regionIndex) {
  if (!((true))) {
    return op->emitOpError("region #") << regionIndex
        << (regionName.empty() ? " " : " ('" + regionName + "') ")
        << "failed to verify constraint: any region";
  }
  return ::mlir::success();
}
} // namespace affine
} // namespace mlir
namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineApplyOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineApplyOpGenericAdaptorBase::AffineApplyOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.apply", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineApplyOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineApplyOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

::mlir::AffineMapAttr AffineApplyOpGenericAdaptorBase::getMapAttr() {
  auto attr = ::llvm::cast<::mlir::AffineMapAttr>(getProperties().map);
  return attr;
}

::mlir::AffineMap AffineApplyOpGenericAdaptorBase::getMap() {
  auto attr = getMapAttr();
  return attr.getValue();
}

} // namespace detail
AffineApplyOpAdaptor::AffineApplyOpAdaptor(AffineApplyOp op) : AffineApplyOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineApplyOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_map = getProperties().map; (void)tblgen_map;
  if (!tblgen_map) return emitError(loc, "'affine.apply' op ""requires attribute 'map'");

  if (tblgen_map && !((::llvm::isa<::mlir::AffineMapAttr>(tblgen_map))))
    return emitError(loc, "'affine.apply' op ""attribute 'map' failed to satisfy constraint: AffineMap attribute");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineApplyOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineApplyOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::operand_range AffineApplyOp::getMapOperands() {
  return getODSOperands(0);
}

::mlir::MutableOperandRange AffineApplyOp::getMapOperandsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> AffineApplyOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AffineApplyOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::LogicalResult AffineApplyOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    if (diag)
      *diag << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.map;
       auto attr = dict.get("map");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for map in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `map` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute AffineApplyOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.map;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("map",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code AffineApplyOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.map.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> AffineApplyOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "map")
      return prop.map;
  return std::nullopt;
}

void AffineApplyOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "map") {
       prop.map = dyn_cast_or_null<std::remove_reference_t<decltype(prop.map)>>(value);
       return;
    }
}

void AffineApplyOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.map) attrs.append("map", prop.map);
}

::mlir::LogicalResult AffineApplyOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
    {
      ::mlir::Attribute attr = attrs.get(getMapAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps0(attr, "map", getDiag)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::mlir::LogicalResult AffineApplyOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.map)))
    return ::mlir::failure();
  return ::mlir::success();
}

void AffineApplyOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.map);
}

::mlir::AffineMapAttr AffineApplyOp::getMapAttr() {
  return ::llvm::cast<::mlir::AffineMapAttr>(getProperties().map);
}

::mlir::AffineMap AffineApplyOp::getMap() {
  auto attr = getMapAttr();
  return attr.getValue();
}

void AffineApplyOp::setMapAttr(::mlir::AffineMapAttr attr) {
  (*this)->setAttr(getMapAttrName(), attr);
}

void AffineApplyOp::setMap(::mlir::AffineMap attrValue) {
  (*this)->setAttr(getMapAttrName(), ::mlir::AffineMapAttr::get(attrValue));
}

void AffineApplyOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, AffineMap map, ValueRange mapOperands) {
      build(odsBuilder, odsState, odsBuilder.getIndexType(), map, mapOperands);
    
}

void AffineApplyOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ArrayRef<AffineExpr>  exprList, ValueRange mapOperands) {
      build(odsBuilder, odsState, odsBuilder.getIndexType(),
            AffineMap::inferFromExprList(exprList).front(), mapOperands);
    
}

void AffineApplyOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::AffineMapAttr map, ::mlir::ValueRange mapOperands) {
  odsState.addOperands(mapOperands);
  odsState.getOrAddProperties<Properties>().map = map;
  odsState.addTypes(resultType0);
}

void AffineApplyOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::AffineMapAttr map, ::mlir::ValueRange mapOperands) {
  odsState.addOperands(mapOperands);
  odsState.getOrAddProperties<Properties>().map = map;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AffineApplyOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::AffineMap map, ::mlir::ValueRange mapOperands) {
  odsState.addOperands(mapOperands);
  odsState.getOrAddProperties<Properties>().map = ::mlir::AffineMapAttr::get(map);
  odsState.addTypes(resultType0);
}

void AffineApplyOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::AffineMap map, ::mlir::ValueRange mapOperands) {
  odsState.addOperands(mapOperands);
  odsState.getOrAddProperties<Properties>().map = ::mlir::AffineMapAttr::get(map);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AffineApplyOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AffineApplyOp::verifyInvariantsImpl() {
  auto tblgen_map = getProperties().map; (void)tblgen_map;
  if (!tblgen_map) return emitOpError("requires attribute 'map'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps0(*this, tblgen_map, "map")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineApplyOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

void AffineApplyOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineApplyOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineDelinearizeIndexOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineDelinearizeIndexOpGenericAdaptorBase::AffineDelinearizeIndexOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.delinearize_index", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineDelinearizeIndexOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineDelinearizeIndexOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
AffineDelinearizeIndexOpAdaptor::AffineDelinearizeIndexOpAdaptor(AffineDelinearizeIndexOp op) : AffineDelinearizeIndexOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineDelinearizeIndexOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineDelinearizeIndexOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineDelinearizeIndexOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::IndexType> AffineDelinearizeIndexOp::getLinearIndex() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::IndexType>>(*getODSOperands(0).begin());
}

::mlir::Operation::operand_range AffineDelinearizeIndexOp::getBasis() {
  return getODSOperands(1);
}

::mlir::MutableOperandRange AffineDelinearizeIndexOp::getLinearIndexMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::mlir::MutableOperandRange AffineDelinearizeIndexOp::getBasisMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> AffineDelinearizeIndexOp::getODSResultIndexAndLength(unsigned index) {
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

::mlir::Operation::result_range AffineDelinearizeIndexOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::result_range AffineDelinearizeIndexOp::getMultiIndex() {
  return getODSResults(0);
}

void AffineDelinearizeIndexOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange multi_index, ::mlir::Value linear_index, ::mlir::ValueRange basis) {
  odsState.addOperands(linear_index);
  odsState.addOperands(basis);
  odsState.addTypes(multi_index);
}

void AffineDelinearizeIndexOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() >= 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AffineDelinearizeIndexOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineDelinearizeIndexOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::mlir::ParseResult AffineDelinearizeIndexOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand linear_indexRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> linear_indexOperands(linear_indexRawOperands);  ::llvm::SMLoc linear_indexOperandsLoc;
  (void)linear_indexOperandsLoc;
  ::llvm::SmallVector<::mlir::OpAsmParser::UnresolvedOperand, 4> basisOperands;
  ::llvm::SMLoc basisOperandsLoc;
  (void)basisOperandsLoc;
  ::llvm::SmallVector<::mlir::Type, 1> multi_indexTypes;

  linear_indexOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(linear_indexRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseKeyword("into"))
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  basisOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperandList(basisOperands))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  if (parser.parseTypeList(multi_indexTypes))
    return ::mlir::failure();
  ::mlir::Type odsBuildableType0 = parser.getBuilder().getIndexType();
  result.addTypes(multi_indexTypes);
  if (parser.resolveOperands(linear_indexOperands, odsBuildableType0, linear_indexOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(basisOperands, odsBuildableType0, basisOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void AffineDelinearizeIndexOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getLinearIndex();
  _odsPrinter << ' ' << "into";
  _odsPrinter << ' ';
  _odsPrinter << "(";
  _odsPrinter << getBasis();
  _odsPrinter << ")";
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  _odsPrinter << getMultiIndex().getTypes();
}

void AffineDelinearizeIndexOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineDelinearizeIndexOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineForOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineForOpGenericAdaptorBase::AffineForOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.for", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineForOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineForOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

::mlir::Region &AffineForOpGenericAdaptorBase::getRegion() {
  return *odsRegions[0];
}

::mlir::RegionRange AffineForOpGenericAdaptorBase::getRegions() {
  return odsRegions;
}

} // namespace detail
AffineForOpAdaptor::AffineForOpAdaptor(AffineForOp op) : AffineForOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineForOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineForOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineForOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

std::pair<unsigned, unsigned> AffineForOp::getODSResultIndexAndLength(unsigned index) {
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

::mlir::Operation::result_range AffineForOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::result_range AffineForOp::getResults() {
  return getODSResults(0);
}

::mlir::Region &AffineForOp::getRegion() {
  return (*this)->getRegion(0);
}

::mlir::LogicalResult AffineForOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;

    for (auto &region : ::llvm::MutableArrayRef((*this)->getRegion(0)))
      if (::mlir::failed(__mlir_ods_local_region_constraint_AffineOps0(*this, region, "region", index++)))
        return ::mlir::failure();
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineForOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineForOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineIfOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineIfOpGenericAdaptorBase::AffineIfOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.if", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineIfOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineIfOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

::mlir::Region &AffineIfOpGenericAdaptorBase::getThenRegion() {
  return *odsRegions[0];
}

::mlir::Region &AffineIfOpGenericAdaptorBase::getElseRegion() {
  return *odsRegions[1];
}

::mlir::RegionRange AffineIfOpGenericAdaptorBase::getRegions() {
  return odsRegions;
}

} // namespace detail
AffineIfOpAdaptor::AffineIfOpAdaptor(AffineIfOp op) : AffineIfOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineIfOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineIfOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineIfOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

std::pair<unsigned, unsigned> AffineIfOp::getODSResultIndexAndLength(unsigned index) {
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

::mlir::Operation::result_range AffineIfOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::result_range AffineIfOp::getResults() {
  return getODSResults(0);
}

::mlir::Region &AffineIfOp::getThenRegion() {
  return (*this)->getRegion(0);
}

::mlir::Region &AffineIfOp::getElseRegion() {
  return (*this)->getRegion(1);
}

::mlir::LogicalResult AffineIfOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;

    for (auto &region : ::llvm::MutableArrayRef((*this)->getRegion(0)))
      if (::mlir::failed(__mlir_ods_local_region_constraint_AffineOps0(*this, region, "thenRegion", index++)))
        return ::mlir::failure();

    for (auto &region : ::llvm::MutableArrayRef((*this)->getRegion(1)))
      if (::mlir::failed(__mlir_ods_local_region_constraint_AffineOps1(*this, region, "elseRegion", index++)))
        return ::mlir::failure();
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineIfOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineIfOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineLoadOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineLoadOpGenericAdaptorBase::AffineLoadOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.load", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineLoadOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineLoadOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
AffineLoadOpAdaptor::AffineLoadOpAdaptor(AffineLoadOp op) : AffineLoadOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineLoadOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineLoadOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineLoadOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::MemRefType> AffineLoadOp::getMemref() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(0).begin());
}

::mlir::Operation::operand_range AffineLoadOp::getIndices() {
  return getODSOperands(1);
}

::mlir::MutableOperandRange AffineLoadOp::getMemrefMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::mlir::MutableOperandRange AffineLoadOp::getIndicesMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> AffineLoadOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AffineLoadOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value AffineLoadOp::getResult() {
  return ::llvm::cast<::mlir::Value>(*getODSResults(0).begin());
}

void AffineLoadOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value memref, ::mlir::ValueRange indices) {
  odsState.addOperands(memref);
  odsState.addOperands(indices);
  odsState.addTypes(result);
}

void AffineLoadOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value memref, ::mlir::ValueRange indices) {
  odsState.addOperands(memref);
  odsState.addOperands(indices);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AffineLoadOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() >= 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AffineLoadOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineLoadOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

void AffineLoadOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
  for (::mlir::Value value : getODSOperands(0))
    effects.emplace_back(::mlir::MemoryEffects::Read::get(), value, ::mlir::SideEffects::DefaultResource::get());
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineLoadOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineMaxOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineMaxOpGenericAdaptorBase::AffineMaxOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.max", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineMaxOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineMaxOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

::mlir::AffineMapAttr AffineMaxOpGenericAdaptorBase::getMapAttr() {
  auto attr = ::llvm::cast<::mlir::AffineMapAttr>(getProperties().map);
  return attr;
}

::mlir::AffineMap AffineMaxOpGenericAdaptorBase::getMap() {
  auto attr = getMapAttr();
  return attr.getValue();
}

} // namespace detail
AffineMaxOpAdaptor::AffineMaxOpAdaptor(AffineMaxOp op) : AffineMaxOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineMaxOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_map = getProperties().map; (void)tblgen_map;
  if (!tblgen_map) return emitError(loc, "'affine.max' op ""requires attribute 'map'");

  if (tblgen_map && !((::llvm::isa<::mlir::AffineMapAttr>(tblgen_map))))
    return emitError(loc, "'affine.max' op ""attribute 'map' failed to satisfy constraint: AffineMap attribute");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineMaxOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineMaxOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::operand_range AffineMaxOp::getOperands() {
  return getODSOperands(0);
}

::mlir::MutableOperandRange AffineMaxOp::getOperandsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> AffineMaxOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AffineMaxOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::LogicalResult AffineMaxOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    if (diag)
      *diag << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.map;
       auto attr = dict.get("map");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for map in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `map` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute AffineMaxOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.map;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("map",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code AffineMaxOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.map.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> AffineMaxOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "map")
      return prop.map;
  return std::nullopt;
}

void AffineMaxOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "map") {
       prop.map = dyn_cast_or_null<std::remove_reference_t<decltype(prop.map)>>(value);
       return;
    }
}

void AffineMaxOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.map) attrs.append("map", prop.map);
}

::mlir::LogicalResult AffineMaxOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
    {
      ::mlir::Attribute attr = attrs.get(getMapAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps0(attr, "map", getDiag)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::mlir::LogicalResult AffineMaxOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.map)))
    return ::mlir::failure();
  return ::mlir::success();
}

void AffineMaxOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.map);
}

::mlir::AffineMapAttr AffineMaxOp::getMapAttr() {
  return ::llvm::cast<::mlir::AffineMapAttr>(getProperties().map);
}

::mlir::AffineMap AffineMaxOp::getMap() {
  auto attr = getMapAttr();
  return attr.getValue();
}

void AffineMaxOp::setMapAttr(::mlir::AffineMapAttr attr) {
  (*this)->setAttr(getMapAttrName(), attr);
}

void AffineMaxOp::setMap(::mlir::AffineMap attrValue) {
  (*this)->setAttr(getMapAttrName(), ::mlir::AffineMapAttr::get(attrValue));
}

void AffineMaxOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, AffineMap affineMap, ValueRange mapOperands) {
      build(odsBuilder, odsState, odsBuilder.getIndexType(), affineMap, mapOperands);
    
}

void AffineMaxOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::AffineMapAttr map, ::mlir::ValueRange operands) {
  odsState.addOperands(operands);
  odsState.getOrAddProperties<Properties>().map = map;
  odsState.addTypes(resultType0);
}

void AffineMaxOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::AffineMapAttr map, ::mlir::ValueRange operands) {
  odsState.addOperands(operands);
  odsState.getOrAddProperties<Properties>().map = map;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AffineMaxOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::AffineMap map, ::mlir::ValueRange operands) {
  odsState.addOperands(operands);
  odsState.getOrAddProperties<Properties>().map = ::mlir::AffineMapAttr::get(map);
  odsState.addTypes(resultType0);
}

void AffineMaxOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::AffineMap map, ::mlir::ValueRange operands) {
  odsState.addOperands(operands);
  odsState.getOrAddProperties<Properties>().map = ::mlir::AffineMapAttr::get(map);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AffineMaxOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AffineMaxOp::verifyInvariantsImpl() {
  auto tblgen_map = getProperties().map; (void)tblgen_map;
  if (!tblgen_map) return emitOpError("requires attribute 'map'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps0(*this, tblgen_map, "map")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineMaxOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

void AffineMaxOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineMaxOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineMinOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineMinOpGenericAdaptorBase::AffineMinOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.min", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineMinOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineMinOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

::mlir::AffineMapAttr AffineMinOpGenericAdaptorBase::getMapAttr() {
  auto attr = ::llvm::cast<::mlir::AffineMapAttr>(getProperties().map);
  return attr;
}

::mlir::AffineMap AffineMinOpGenericAdaptorBase::getMap() {
  auto attr = getMapAttr();
  return attr.getValue();
}

} // namespace detail
AffineMinOpAdaptor::AffineMinOpAdaptor(AffineMinOp op) : AffineMinOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineMinOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_map = getProperties().map; (void)tblgen_map;
  if (!tblgen_map) return emitError(loc, "'affine.min' op ""requires attribute 'map'");

  if (tblgen_map && !((::llvm::isa<::mlir::AffineMapAttr>(tblgen_map))))
    return emitError(loc, "'affine.min' op ""attribute 'map' failed to satisfy constraint: AffineMap attribute");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineMinOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineMinOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::operand_range AffineMinOp::getOperands() {
  return getODSOperands(0);
}

::mlir::MutableOperandRange AffineMinOp::getOperandsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> AffineMinOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AffineMinOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::LogicalResult AffineMinOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    if (diag)
      *diag << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.map;
       auto attr = dict.get("map");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for map in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `map` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute AffineMinOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.map;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("map",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code AffineMinOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.map.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> AffineMinOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "map")
      return prop.map;
  return std::nullopt;
}

void AffineMinOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "map") {
       prop.map = dyn_cast_or_null<std::remove_reference_t<decltype(prop.map)>>(value);
       return;
    }
}

void AffineMinOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.map) attrs.append("map", prop.map);
}

::mlir::LogicalResult AffineMinOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
    {
      ::mlir::Attribute attr = attrs.get(getMapAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps0(attr, "map", getDiag)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::mlir::LogicalResult AffineMinOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.map)))
    return ::mlir::failure();
  return ::mlir::success();
}

void AffineMinOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.map);
}

::mlir::AffineMapAttr AffineMinOp::getMapAttr() {
  return ::llvm::cast<::mlir::AffineMapAttr>(getProperties().map);
}

::mlir::AffineMap AffineMinOp::getMap() {
  auto attr = getMapAttr();
  return attr.getValue();
}

void AffineMinOp::setMapAttr(::mlir::AffineMapAttr attr) {
  (*this)->setAttr(getMapAttrName(), attr);
}

void AffineMinOp::setMap(::mlir::AffineMap attrValue) {
  (*this)->setAttr(getMapAttrName(), ::mlir::AffineMapAttr::get(attrValue));
}

void AffineMinOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, AffineMap affineMap, ValueRange mapOperands) {
      build(odsBuilder, odsState, odsBuilder.getIndexType(), affineMap, mapOperands);
    
}

void AffineMinOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::AffineMapAttr map, ::mlir::ValueRange operands) {
  odsState.addOperands(operands);
  odsState.getOrAddProperties<Properties>().map = map;
  odsState.addTypes(resultType0);
}

void AffineMinOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::AffineMapAttr map, ::mlir::ValueRange operands) {
  odsState.addOperands(operands);
  odsState.getOrAddProperties<Properties>().map = map;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AffineMinOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::AffineMap map, ::mlir::ValueRange operands) {
  odsState.addOperands(operands);
  odsState.getOrAddProperties<Properties>().map = ::mlir::AffineMapAttr::get(map);
  odsState.addTypes(resultType0);
}

void AffineMinOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::AffineMap map, ::mlir::ValueRange operands) {
  odsState.addOperands(operands);
  odsState.getOrAddProperties<Properties>().map = ::mlir::AffineMapAttr::get(map);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AffineMinOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AffineMinOp::verifyInvariantsImpl() {
  auto tblgen_map = getProperties().map; (void)tblgen_map;
  if (!tblgen_map) return emitOpError("requires attribute 'map'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps0(*this, tblgen_map, "map")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineMinOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

void AffineMinOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineMinOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineParallelOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineParallelOpGenericAdaptorBase::AffineParallelOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.parallel", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineParallelOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineParallelOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

::mlir::ArrayAttr AffineParallelOpGenericAdaptorBase::getReductionsAttr() {
  auto attr = ::llvm::cast<::mlir::ArrayAttr>(getProperties().reductions);
  return attr;
}

::mlir::ArrayAttr AffineParallelOpGenericAdaptorBase::getReductions() {
  auto attr = getReductionsAttr();
  return attr;
}

::mlir::AffineMapAttr AffineParallelOpGenericAdaptorBase::getLowerBoundsMapAttr() {
  auto attr = ::llvm::cast<::mlir::AffineMapAttr>(getProperties().lowerBoundsMap);
  return attr;
}

::mlir::AffineMap AffineParallelOpGenericAdaptorBase::getLowerBoundsMap() {
  auto attr = getLowerBoundsMapAttr();
  return attr.getValue();
}

::mlir::DenseIntElementsAttr AffineParallelOpGenericAdaptorBase::getLowerBoundsGroupsAttr() {
  auto attr = ::llvm::cast<::mlir::DenseIntElementsAttr>(getProperties().lowerBoundsGroups);
  return attr;
}

::mlir::DenseIntElementsAttr AffineParallelOpGenericAdaptorBase::getLowerBoundsGroups() {
  auto attr = getLowerBoundsGroupsAttr();
  return attr;
}

::mlir::AffineMapAttr AffineParallelOpGenericAdaptorBase::getUpperBoundsMapAttr() {
  auto attr = ::llvm::cast<::mlir::AffineMapAttr>(getProperties().upperBoundsMap);
  return attr;
}

::mlir::AffineMap AffineParallelOpGenericAdaptorBase::getUpperBoundsMap() {
  auto attr = getUpperBoundsMapAttr();
  return attr.getValue();
}

::mlir::DenseIntElementsAttr AffineParallelOpGenericAdaptorBase::getUpperBoundsGroupsAttr() {
  auto attr = ::llvm::cast<::mlir::DenseIntElementsAttr>(getProperties().upperBoundsGroups);
  return attr;
}

::mlir::DenseIntElementsAttr AffineParallelOpGenericAdaptorBase::getUpperBoundsGroups() {
  auto attr = getUpperBoundsGroupsAttr();
  return attr;
}

::mlir::ArrayAttr AffineParallelOpGenericAdaptorBase::getStepsAttr() {
  auto attr = ::llvm::cast<::mlir::ArrayAttr>(getProperties().steps);
  return attr;
}

::llvm::SmallVector<int64_t, 8> AffineParallelOpGenericAdaptorBase::getSteps() {
  auto attr = getStepsAttr();
  return llvm::to_vector<4>(
      llvm::map_range(attr.getAsRange<mlir::IntegerAttr>(),
      [](IntegerAttr attr) { return attr.getInt(); }));;
}

::mlir::Region &AffineParallelOpGenericAdaptorBase::getRegion() {
  return *odsRegions[0];
}

::mlir::RegionRange AffineParallelOpGenericAdaptorBase::getRegions() {
  return odsRegions;
}

} // namespace detail
AffineParallelOpAdaptor::AffineParallelOpAdaptor(AffineParallelOp op) : AffineParallelOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineParallelOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_lowerBoundsGroups = getProperties().lowerBoundsGroups; (void)tblgen_lowerBoundsGroups;
  if (!tblgen_lowerBoundsGroups) return emitError(loc, "'affine.parallel' op ""requires attribute 'lowerBoundsGroups'");
  auto tblgen_lowerBoundsMap = getProperties().lowerBoundsMap; (void)tblgen_lowerBoundsMap;
  if (!tblgen_lowerBoundsMap) return emitError(loc, "'affine.parallel' op ""requires attribute 'lowerBoundsMap'");
  auto tblgen_reductions = getProperties().reductions; (void)tblgen_reductions;
  if (!tblgen_reductions) return emitError(loc, "'affine.parallel' op ""requires attribute 'reductions'");
  auto tblgen_steps = getProperties().steps; (void)tblgen_steps;
  if (!tblgen_steps) return emitError(loc, "'affine.parallel' op ""requires attribute 'steps'");
  auto tblgen_upperBoundsGroups = getProperties().upperBoundsGroups; (void)tblgen_upperBoundsGroups;
  if (!tblgen_upperBoundsGroups) return emitError(loc, "'affine.parallel' op ""requires attribute 'upperBoundsGroups'");
  auto tblgen_upperBoundsMap = getProperties().upperBoundsMap; (void)tblgen_upperBoundsMap;
  if (!tblgen_upperBoundsMap) return emitError(loc, "'affine.parallel' op ""requires attribute 'upperBoundsMap'");

  if (tblgen_reductions && !(((::llvm::isa<::mlir::ArrayAttr>(tblgen_reductions))) && (::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>(tblgen_reductions), [&](::mlir::Attribute attr) { return attr && ((::llvm::isa<::mlir::arith::AtomicRMWKindAttr>(attr))); }))))
    return emitError(loc, "'affine.parallel' op ""attribute 'reductions' failed to satisfy constraint: Reduction ops");

  if (tblgen_lowerBoundsMap && !((::llvm::isa<::mlir::AffineMapAttr>(tblgen_lowerBoundsMap))))
    return emitError(loc, "'affine.parallel' op ""attribute 'lowerBoundsMap' failed to satisfy constraint: AffineMap attribute");

  if (tblgen_lowerBoundsGroups && !(((::llvm::isa<::mlir::DenseIntElementsAttr>(tblgen_lowerBoundsGroups))) && ((::llvm::cast<::mlir::DenseIntElementsAttr>(tblgen_lowerBoundsGroups).getType().getElementType().isSignlessInteger(32)))))
    return emitError(loc, "'affine.parallel' op ""attribute 'lowerBoundsGroups' failed to satisfy constraint: 32-bit signless integer elements attribute");

  if (tblgen_upperBoundsMap && !((::llvm::isa<::mlir::AffineMapAttr>(tblgen_upperBoundsMap))))
    return emitError(loc, "'affine.parallel' op ""attribute 'upperBoundsMap' failed to satisfy constraint: AffineMap attribute");

  if (tblgen_upperBoundsGroups && !(((::llvm::isa<::mlir::DenseIntElementsAttr>(tblgen_upperBoundsGroups))) && ((::llvm::cast<::mlir::DenseIntElementsAttr>(tblgen_upperBoundsGroups).getType().getElementType().isSignlessInteger(32)))))
    return emitError(loc, "'affine.parallel' op ""attribute 'upperBoundsGroups' failed to satisfy constraint: 32-bit signless integer elements attribute");

  if (tblgen_steps && !(((::llvm::isa<::mlir::ArrayAttr>(tblgen_steps))) && (::llvm::all_of(::llvm::cast<::mlir::ArrayAttr>(tblgen_steps), [&](::mlir::Attribute attr) { return attr && (((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(64)))); }))))
    return emitError(loc, "'affine.parallel' op ""attribute 'steps' failed to satisfy constraint: 64-bit integer array attribute");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineParallelOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineParallelOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::operand_range AffineParallelOp::getMapOperands() {
  return getODSOperands(0);
}

::mlir::MutableOperandRange AffineParallelOp::getMapOperandsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> AffineParallelOp::getODSResultIndexAndLength(unsigned index) {
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

::mlir::Operation::result_range AffineParallelOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::result_range AffineParallelOp::getResults() {
  return getODSResults(0);
}

::mlir::Region &AffineParallelOp::getRegion() {
  return (*this)->getRegion(0);
}

::mlir::LogicalResult AffineParallelOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    if (diag)
      *diag << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.lowerBoundsGroups;
       auto attr = dict.get("lowerBoundsGroups");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for lowerBoundsGroups in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `lowerBoundsGroups` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.lowerBoundsMap;
       auto attr = dict.get("lowerBoundsMap");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for lowerBoundsMap in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `lowerBoundsMap` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.reductions;
       auto attr = dict.get("reductions");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for reductions in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `reductions` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.steps;
       auto attr = dict.get("steps");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for steps in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `steps` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.upperBoundsGroups;
       auto attr = dict.get("upperBoundsGroups");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for upperBoundsGroups in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `upperBoundsGroups` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.upperBoundsMap;
       auto attr = dict.get("upperBoundsMap");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for upperBoundsMap in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `upperBoundsMap` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute AffineParallelOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.lowerBoundsGroups;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("lowerBoundsGroups",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.lowerBoundsMap;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("lowerBoundsMap",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.reductions;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("reductions",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.steps;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("steps",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.upperBoundsGroups;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("upperBoundsGroups",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.upperBoundsMap;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("upperBoundsMap",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code AffineParallelOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.lowerBoundsGroups.getAsOpaquePointer()), 
    llvm::hash_value(prop.lowerBoundsMap.getAsOpaquePointer()), 
    llvm::hash_value(prop.reductions.getAsOpaquePointer()), 
    llvm::hash_value(prop.steps.getAsOpaquePointer()), 
    llvm::hash_value(prop.upperBoundsGroups.getAsOpaquePointer()), 
    llvm::hash_value(prop.upperBoundsMap.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> AffineParallelOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "lowerBoundsGroups")
      return prop.lowerBoundsGroups;

    if (name == "lowerBoundsMap")
      return prop.lowerBoundsMap;

    if (name == "reductions")
      return prop.reductions;

    if (name == "steps")
      return prop.steps;

    if (name == "upperBoundsGroups")
      return prop.upperBoundsGroups;

    if (name == "upperBoundsMap")
      return prop.upperBoundsMap;
  return std::nullopt;
}

void AffineParallelOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "lowerBoundsGroups") {
       prop.lowerBoundsGroups = dyn_cast_or_null<std::remove_reference_t<decltype(prop.lowerBoundsGroups)>>(value);
       return;
    }

    if (name == "lowerBoundsMap") {
       prop.lowerBoundsMap = dyn_cast_or_null<std::remove_reference_t<decltype(prop.lowerBoundsMap)>>(value);
       return;
    }

    if (name == "reductions") {
       prop.reductions = dyn_cast_or_null<std::remove_reference_t<decltype(prop.reductions)>>(value);
       return;
    }

    if (name == "steps") {
       prop.steps = dyn_cast_or_null<std::remove_reference_t<decltype(prop.steps)>>(value);
       return;
    }

    if (name == "upperBoundsGroups") {
       prop.upperBoundsGroups = dyn_cast_or_null<std::remove_reference_t<decltype(prop.upperBoundsGroups)>>(value);
       return;
    }

    if (name == "upperBoundsMap") {
       prop.upperBoundsMap = dyn_cast_or_null<std::remove_reference_t<decltype(prop.upperBoundsMap)>>(value);
       return;
    }
}

void AffineParallelOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.lowerBoundsGroups) attrs.append("lowerBoundsGroups", prop.lowerBoundsGroups);

    if (prop.lowerBoundsMap) attrs.append("lowerBoundsMap", prop.lowerBoundsMap);

    if (prop.reductions) attrs.append("reductions", prop.reductions);

    if (prop.steps) attrs.append("steps", prop.steps);

    if (prop.upperBoundsGroups) attrs.append("upperBoundsGroups", prop.upperBoundsGroups);

    if (prop.upperBoundsMap) attrs.append("upperBoundsMap", prop.upperBoundsMap);
}

::mlir::LogicalResult AffineParallelOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
    {
      ::mlir::Attribute attr = attrs.get(getLowerBoundsGroupsAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps2(attr, "lowerBoundsGroups", getDiag)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getLowerBoundsMapAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps0(attr, "lowerBoundsMap", getDiag)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getReductionsAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps1(attr, "reductions", getDiag)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getStepsAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps3(attr, "steps", getDiag)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getUpperBoundsGroupsAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps2(attr, "upperBoundsGroups", getDiag)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getUpperBoundsMapAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps0(attr, "upperBoundsMap", getDiag)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::mlir::LogicalResult AffineParallelOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.lowerBoundsGroups)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.lowerBoundsMap)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.reductions)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.steps)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.upperBoundsGroups)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.upperBoundsMap)))
    return ::mlir::failure();
  return ::mlir::success();
}

void AffineParallelOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.lowerBoundsGroups);
  writer.writeAttribute(prop.lowerBoundsMap);
  writer.writeAttribute(prop.reductions);
  writer.writeAttribute(prop.steps);
  writer.writeAttribute(prop.upperBoundsGroups);
  writer.writeAttribute(prop.upperBoundsMap);
}

::mlir::ArrayAttr AffineParallelOp::getReductionsAttr() {
  return ::llvm::cast<::mlir::ArrayAttr>(getProperties().reductions);
}

::mlir::ArrayAttr AffineParallelOp::getReductions() {
  auto attr = getReductionsAttr();
  return attr;
}

::mlir::AffineMapAttr AffineParallelOp::getLowerBoundsMapAttr() {
  return ::llvm::cast<::mlir::AffineMapAttr>(getProperties().lowerBoundsMap);
}

::mlir::AffineMap AffineParallelOp::getLowerBoundsMap() {
  auto attr = getLowerBoundsMapAttr();
  return attr.getValue();
}

::mlir::DenseIntElementsAttr AffineParallelOp::getLowerBoundsGroupsAttr() {
  return ::llvm::cast<::mlir::DenseIntElementsAttr>(getProperties().lowerBoundsGroups);
}

::mlir::DenseIntElementsAttr AffineParallelOp::getLowerBoundsGroups() {
  auto attr = getLowerBoundsGroupsAttr();
  return attr;
}

::mlir::AffineMapAttr AffineParallelOp::getUpperBoundsMapAttr() {
  return ::llvm::cast<::mlir::AffineMapAttr>(getProperties().upperBoundsMap);
}

::mlir::AffineMap AffineParallelOp::getUpperBoundsMap() {
  auto attr = getUpperBoundsMapAttr();
  return attr.getValue();
}

::mlir::DenseIntElementsAttr AffineParallelOp::getUpperBoundsGroupsAttr() {
  return ::llvm::cast<::mlir::DenseIntElementsAttr>(getProperties().upperBoundsGroups);
}

::mlir::DenseIntElementsAttr AffineParallelOp::getUpperBoundsGroups() {
  auto attr = getUpperBoundsGroupsAttr();
  return attr;
}

::mlir::ArrayAttr AffineParallelOp::getStepsAttr() {
  return ::llvm::cast<::mlir::ArrayAttr>(getProperties().steps);
}

::llvm::SmallVector<int64_t, 8> AffineParallelOp::getSteps() {
  auto attr = getStepsAttr();
  return llvm::to_vector<4>(
      llvm::map_range(attr.getAsRange<mlir::IntegerAttr>(),
      [](IntegerAttr attr) { return attr.getInt(); }));;
}

void AffineParallelOp::setReductionsAttr(::mlir::ArrayAttr attr) {
  (*this)->setAttr(getReductionsAttrName(), attr);
}

void AffineParallelOp::setLowerBoundsMapAttr(::mlir::AffineMapAttr attr) {
  (*this)->setAttr(getLowerBoundsMapAttrName(), attr);
}

void AffineParallelOp::setLowerBoundsMap(::mlir::AffineMap attrValue) {
  (*this)->setAttr(getLowerBoundsMapAttrName(), ::mlir::AffineMapAttr::get(attrValue));
}

void AffineParallelOp::setLowerBoundsGroupsAttr(::mlir::DenseIntElementsAttr attr) {
  (*this)->setAttr(getLowerBoundsGroupsAttrName(), attr);
}

void AffineParallelOp::setUpperBoundsMapAttr(::mlir::AffineMapAttr attr) {
  (*this)->setAttr(getUpperBoundsMapAttrName(), attr);
}

void AffineParallelOp::setUpperBoundsMap(::mlir::AffineMap attrValue) {
  (*this)->setAttr(getUpperBoundsMapAttrName(), ::mlir::AffineMapAttr::get(attrValue));
}

void AffineParallelOp::setUpperBoundsGroupsAttr(::mlir::DenseIntElementsAttr attr) {
  (*this)->setAttr(getUpperBoundsGroupsAttrName(), attr);
}

void AffineParallelOp::setStepsAttr(::mlir::ArrayAttr attr) {
  (*this)->setAttr(getStepsAttrName(), attr);
}

void AffineParallelOp::setSteps(::llvm::SmallVector<int64_t, 8> attrValue) {
  (*this)->setAttr(getStepsAttrName(), ::mlir::Builder((*this)->getContext()).getI64ArrayAttr(attrValue));
}

void AffineParallelOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange results, ::mlir::ArrayAttr reductions, ::mlir::AffineMapAttr lowerBoundsMap, ::mlir::DenseIntElementsAttr lowerBoundsGroups, ::mlir::AffineMapAttr upperBoundsMap, ::mlir::DenseIntElementsAttr upperBoundsGroups, ::mlir::ArrayAttr steps, ::mlir::ValueRange mapOperands) {
  odsState.addOperands(mapOperands);
  odsState.getOrAddProperties<Properties>().reductions = reductions;
  odsState.getOrAddProperties<Properties>().lowerBoundsMap = lowerBoundsMap;
  odsState.getOrAddProperties<Properties>().lowerBoundsGroups = lowerBoundsGroups;
  odsState.getOrAddProperties<Properties>().upperBoundsMap = upperBoundsMap;
  odsState.getOrAddProperties<Properties>().upperBoundsGroups = upperBoundsGroups;
  odsState.getOrAddProperties<Properties>().steps = steps;
  (void)odsState.addRegion();
  odsState.addTypes(results);
}

void AffineParallelOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange results, ::mlir::ArrayAttr reductions, ::mlir::AffineMap lowerBoundsMap, ::mlir::DenseIntElementsAttr lowerBoundsGroups, ::mlir::AffineMap upperBoundsMap, ::mlir::DenseIntElementsAttr upperBoundsGroups, ::llvm::SmallVector<int64_t, 8> steps, ::mlir::ValueRange mapOperands) {
  odsState.addOperands(mapOperands);
  odsState.getOrAddProperties<Properties>().reductions = reductions;
  odsState.getOrAddProperties<Properties>().lowerBoundsMap = ::mlir::AffineMapAttr::get(lowerBoundsMap);
  odsState.getOrAddProperties<Properties>().lowerBoundsGroups = lowerBoundsGroups;
  odsState.getOrAddProperties<Properties>().upperBoundsMap = ::mlir::AffineMapAttr::get(upperBoundsMap);
  odsState.getOrAddProperties<Properties>().upperBoundsGroups = upperBoundsGroups;
  odsState.getOrAddProperties<Properties>().steps = odsBuilder.getI64ArrayAttr(steps);
  (void)odsState.addRegion();
  odsState.addTypes(results);
}

void AffineParallelOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  for (unsigned i = 0; i != 1; ++i)
    (void)odsState.addRegion();
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AffineParallelOp::verifyInvariantsImpl() {
  auto tblgen_lowerBoundsGroups = getProperties().lowerBoundsGroups; (void)tblgen_lowerBoundsGroups;
  if (!tblgen_lowerBoundsGroups) return emitOpError("requires attribute 'lowerBoundsGroups'");
  auto tblgen_lowerBoundsMap = getProperties().lowerBoundsMap; (void)tblgen_lowerBoundsMap;
  if (!tblgen_lowerBoundsMap) return emitOpError("requires attribute 'lowerBoundsMap'");
  auto tblgen_reductions = getProperties().reductions; (void)tblgen_reductions;
  if (!tblgen_reductions) return emitOpError("requires attribute 'reductions'");
  auto tblgen_steps = getProperties().steps; (void)tblgen_steps;
  if (!tblgen_steps) return emitOpError("requires attribute 'steps'");
  auto tblgen_upperBoundsGroups = getProperties().upperBoundsGroups; (void)tblgen_upperBoundsGroups;
  if (!tblgen_upperBoundsGroups) return emitOpError("requires attribute 'upperBoundsGroups'");
  auto tblgen_upperBoundsMap = getProperties().upperBoundsMap; (void)tblgen_upperBoundsMap;
  if (!tblgen_upperBoundsMap) return emitOpError("requires attribute 'upperBoundsMap'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps1(*this, tblgen_reductions, "reductions")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps0(*this, tblgen_lowerBoundsMap, "lowerBoundsMap")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps2(*this, tblgen_lowerBoundsGroups, "lowerBoundsGroups")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps0(*this, tblgen_upperBoundsMap, "upperBoundsMap")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps2(*this, tblgen_upperBoundsGroups, "upperBoundsGroups")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps3(*this, tblgen_steps, "steps")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;

    for (auto &region : ::llvm::MutableArrayRef((*this)->getRegion(0)))
      if (::mlir::failed(__mlir_ods_local_region_constraint_AffineOps0(*this, region, "region", index++)))
        return ::mlir::failure();
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineParallelOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineParallelOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffinePrefetchOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffinePrefetchOpGenericAdaptorBase::AffinePrefetchOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.prefetch", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffinePrefetchOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffinePrefetchOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

::mlir::BoolAttr AffinePrefetchOpGenericAdaptorBase::getIsWriteAttr() {
  auto attr = ::llvm::cast<::mlir::BoolAttr>(getProperties().isWrite);
  return attr;
}

bool AffinePrefetchOpGenericAdaptorBase::getIsWrite() {
  auto attr = getIsWriteAttr();
  return attr.getValue();
}

::mlir::IntegerAttr AffinePrefetchOpGenericAdaptorBase::getLocalityHintAttr() {
  auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().localityHint);
  return attr;
}

uint32_t AffinePrefetchOpGenericAdaptorBase::getLocalityHint() {
  auto attr = getLocalityHintAttr();
  return attr.getValue().getZExtValue();
}

::mlir::BoolAttr AffinePrefetchOpGenericAdaptorBase::getIsDataCacheAttr() {
  auto attr = ::llvm::cast<::mlir::BoolAttr>(getProperties().isDataCache);
  return attr;
}

bool AffinePrefetchOpGenericAdaptorBase::getIsDataCache() {
  auto attr = getIsDataCacheAttr();
  return attr.getValue();
}

} // namespace detail
AffinePrefetchOpAdaptor::AffinePrefetchOpAdaptor(AffinePrefetchOp op) : AffinePrefetchOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffinePrefetchOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_isDataCache = getProperties().isDataCache; (void)tblgen_isDataCache;
  if (!tblgen_isDataCache) return emitError(loc, "'affine.prefetch' op ""requires attribute 'isDataCache'");
  auto tblgen_isWrite = getProperties().isWrite; (void)tblgen_isWrite;
  if (!tblgen_isWrite) return emitError(loc, "'affine.prefetch' op ""requires attribute 'isWrite'");
  auto tblgen_localityHint = getProperties().localityHint; (void)tblgen_localityHint;
  if (!tblgen_localityHint) return emitError(loc, "'affine.prefetch' op ""requires attribute 'localityHint'");

  if (tblgen_isWrite && !((::llvm::isa<::mlir::BoolAttr>(tblgen_isWrite))))
    return emitError(loc, "'affine.prefetch' op ""attribute 'isWrite' failed to satisfy constraint: bool attribute");

  if (tblgen_localityHint && !((((::llvm::isa<::mlir::IntegerAttr>(tblgen_localityHint))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_localityHint).getType().isSignlessInteger(32)))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_localityHint).getInt() >= 0)) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_localityHint).getInt() <= 3))))
    return emitError(loc, "'affine.prefetch' op ""attribute 'localityHint' failed to satisfy constraint: 32-bit signless integer attribute whose minimum value is 0 whose maximum value is 3");

  if (tblgen_isDataCache && !((::llvm::isa<::mlir::BoolAttr>(tblgen_isDataCache))))
    return emitError(loc, "'affine.prefetch' op ""attribute 'isDataCache' failed to satisfy constraint: bool attribute");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffinePrefetchOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffinePrefetchOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::MemRefType> AffinePrefetchOp::getMemref() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(0).begin());
}

::mlir::Operation::operand_range AffinePrefetchOp::getIndices() {
  return getODSOperands(1);
}

::mlir::MutableOperandRange AffinePrefetchOp::getMemrefMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::mlir::MutableOperandRange AffinePrefetchOp::getIndicesMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> AffinePrefetchOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AffinePrefetchOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::LogicalResult AffinePrefetchOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::mlir::InFlightDiagnostic *diag) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    if (diag)
      *diag << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.isDataCache;
       auto attr = dict.get("isDataCache");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for isDataCache in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `isDataCache` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.isWrite;
       auto attr = dict.get("isWrite");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for isWrite in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `isWrite` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.localityHint;
       auto attr = dict.get("localityHint");
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        if (diag)
          *diag << "expected key entry for localityHint in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        if (diag)
          *diag << "Invalid attribute `localityHint` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute AffinePrefetchOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.isDataCache;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("isDataCache",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.isWrite;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("isWrite",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.localityHint;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("localityHint",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code AffinePrefetchOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.isDataCache.getAsOpaquePointer()), 
    llvm::hash_value(prop.isWrite.getAsOpaquePointer()), 
    llvm::hash_value(prop.localityHint.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> AffinePrefetchOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "isDataCache")
      return prop.isDataCache;

    if (name == "isWrite")
      return prop.isWrite;

    if (name == "localityHint")
      return prop.localityHint;
  return std::nullopt;
}

void AffinePrefetchOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "isDataCache") {
       prop.isDataCache = dyn_cast_or_null<std::remove_reference_t<decltype(prop.isDataCache)>>(value);
       return;
    }

    if (name == "isWrite") {
       prop.isWrite = dyn_cast_or_null<std::remove_reference_t<decltype(prop.isWrite)>>(value);
       return;
    }

    if (name == "localityHint") {
       prop.localityHint = dyn_cast_or_null<std::remove_reference_t<decltype(prop.localityHint)>>(value);
       return;
    }
}

void AffinePrefetchOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.isDataCache) attrs.append("isDataCache", prop.isDataCache);

    if (prop.isWrite) attrs.append("isWrite", prop.isWrite);

    if (prop.localityHint) attrs.append("localityHint", prop.localityHint);
}

::mlir::LogicalResult AffinePrefetchOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> getDiag) {
    {
      ::mlir::Attribute attr = attrs.get(getIsDataCacheAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps4(attr, "isDataCache", getDiag)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getIsWriteAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps4(attr, "isWrite", getDiag)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getLocalityHintAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps5(attr, "localityHint", getDiag)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::mlir::LogicalResult AffinePrefetchOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.isDataCache)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.isWrite)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.localityHint)))
    return ::mlir::failure();
  return ::mlir::success();
}

void AffinePrefetchOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.isDataCache);
  writer.writeAttribute(prop.isWrite);
  writer.writeAttribute(prop.localityHint);
}

::mlir::BoolAttr AffinePrefetchOp::getIsWriteAttr() {
  return ::llvm::cast<::mlir::BoolAttr>(getProperties().isWrite);
}

bool AffinePrefetchOp::getIsWrite() {
  auto attr = getIsWriteAttr();
  return attr.getValue();
}

::mlir::IntegerAttr AffinePrefetchOp::getLocalityHintAttr() {
  return ::llvm::cast<::mlir::IntegerAttr>(getProperties().localityHint);
}

uint32_t AffinePrefetchOp::getLocalityHint() {
  auto attr = getLocalityHintAttr();
  return attr.getValue().getZExtValue();
}

::mlir::BoolAttr AffinePrefetchOp::getIsDataCacheAttr() {
  return ::llvm::cast<::mlir::BoolAttr>(getProperties().isDataCache);
}

bool AffinePrefetchOp::getIsDataCache() {
  auto attr = getIsDataCacheAttr();
  return attr.getValue();
}

void AffinePrefetchOp::setIsWriteAttr(::mlir::BoolAttr attr) {
  (*this)->setAttr(getIsWriteAttrName(), attr);
}

void AffinePrefetchOp::setIsWrite(bool attrValue) {
  (*this)->setAttr(getIsWriteAttrName(), ::mlir::Builder((*this)->getContext()).getBoolAttr(attrValue));
}

void AffinePrefetchOp::setLocalityHintAttr(::mlir::IntegerAttr attr) {
  (*this)->setAttr(getLocalityHintAttrName(), attr);
}

void AffinePrefetchOp::setLocalityHint(uint32_t attrValue) {
  (*this)->setAttr(getLocalityHintAttrName(), ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(32), attrValue));
}

void AffinePrefetchOp::setIsDataCacheAttr(::mlir::BoolAttr attr) {
  (*this)->setAttr(getIsDataCacheAttrName(), attr);
}

void AffinePrefetchOp::setIsDataCache(bool attrValue) {
  (*this)->setAttr(getIsDataCacheAttrName(), ::mlir::Builder((*this)->getContext()).getBoolAttr(attrValue));
}

void AffinePrefetchOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value memref, AffineMap map, ArrayRef<Value> mapOperands, bool isWrite, unsigned localityHint, bool isDataCache) {
      assert(map.getNumInputs() == mapOperands.size()
             && "inconsistent index info");
      auto localityHintAttr = odsBuilder.getI32IntegerAttr(localityHint);
      auto isWriteAttr = odsBuilder.getBoolAttr(isWrite);
      auto isDataCacheAttr = odsBuilder.getBoolAttr(isDataCache);
      odsState.addOperands(memref);
      odsState.addAttribute(getMapAttrStrName(), AffineMapAttr::get(map));
      odsState.addOperands(mapOperands);
      odsState.addAttribute(getLocalityHintAttrStrName(), localityHintAttr);
      odsState.addAttribute(getIsWriteAttrStrName(), isWriteAttr);
      odsState.addAttribute(getIsDataCacheAttrStrName(), isDataCacheAttr);
    
}

void AffinePrefetchOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr isWrite, ::mlir::IntegerAttr localityHint, ::mlir::BoolAttr isDataCache) {
  odsState.addOperands(memref);
  odsState.addOperands(indices);
  odsState.getOrAddProperties<Properties>().isWrite = isWrite;
  odsState.getOrAddProperties<Properties>().localityHint = localityHint;
  odsState.getOrAddProperties<Properties>().isDataCache = isDataCache;
}

void AffinePrefetchOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr isWrite, ::mlir::IntegerAttr localityHint, ::mlir::BoolAttr isDataCache) {
  odsState.addOperands(memref);
  odsState.addOperands(indices);
  odsState.getOrAddProperties<Properties>().isWrite = isWrite;
  odsState.getOrAddProperties<Properties>().localityHint = localityHint;
  odsState.getOrAddProperties<Properties>().isDataCache = isDataCache;
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AffinePrefetchOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value memref, ::mlir::ValueRange indices, bool isWrite, uint32_t localityHint, bool isDataCache) {
  odsState.addOperands(memref);
  odsState.addOperands(indices);
  odsState.getOrAddProperties<Properties>().isWrite = odsBuilder.getBoolAttr(isWrite);
  odsState.getOrAddProperties<Properties>().localityHint = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), localityHint);
  odsState.getOrAddProperties<Properties>().isDataCache = odsBuilder.getBoolAttr(isDataCache);
}

void AffinePrefetchOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value memref, ::mlir::ValueRange indices, bool isWrite, uint32_t localityHint, bool isDataCache) {
  odsState.addOperands(memref);
  odsState.addOperands(indices);
  odsState.getOrAddProperties<Properties>().isWrite = odsBuilder.getBoolAttr(isWrite);
  odsState.getOrAddProperties<Properties>().localityHint = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), localityHint);
  odsState.getOrAddProperties<Properties>().isDataCache = odsBuilder.getBoolAttr(isDataCache);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AffinePrefetchOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() >= 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AffinePrefetchOp::verifyInvariantsImpl() {
  auto tblgen_isDataCache = getProperties().isDataCache; (void)tblgen_isDataCache;
  if (!tblgen_isDataCache) return emitOpError("requires attribute 'isDataCache'");
  auto tblgen_isWrite = getProperties().isWrite; (void)tblgen_isWrite;
  if (!tblgen_isWrite) return emitOpError("requires attribute 'isWrite'");
  auto tblgen_localityHint = getProperties().localityHint; (void)tblgen_localityHint;
  if (!tblgen_localityHint) return emitOpError("requires attribute 'localityHint'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps4(*this, tblgen_isWrite, "isWrite")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps5(*this, tblgen_localityHint, "localityHint")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_AffineOps4(*this, tblgen_isDataCache, "isDataCache")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffinePrefetchOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffinePrefetchOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineStoreOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineStoreOpGenericAdaptorBase::AffineStoreOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.store", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineStoreOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {false, false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 2) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineStoreOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
AffineStoreOpAdaptor::AffineStoreOpAdaptor(AffineStoreOp op) : AffineStoreOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineStoreOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineStoreOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {false, false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 2) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineStoreOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value AffineStoreOp::getValue() {
  return ::llvm::cast<::mlir::Value>(*getODSOperands(0).begin());
}

::mlir::TypedValue<::mlir::MemRefType> AffineStoreOp::getMemref() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(1).begin());
}

::mlir::Operation::operand_range AffineStoreOp::getIndices() {
  return getODSOperands(2);
}

::mlir::MutableOperandRange AffineStoreOp::getValueMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::mlir::MutableOperandRange AffineStoreOp::getMemrefMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::mlir::MutableOperandRange AffineStoreOp::getIndicesMutable() {
  auto range = getODSOperandIndexAndLength(2);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> AffineStoreOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AffineStoreOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::LogicalResult AffineStoreOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineStoreOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

void AffineStoreOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
  for (::mlir::Value value : getODSOperands(1))
    effects.emplace_back(::mlir::MemoryEffects::Write::get(), value, ::mlir::SideEffects::DefaultResource::get());
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineStoreOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineVectorLoadOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineVectorLoadOpGenericAdaptorBase::AffineVectorLoadOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.vector_load", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineVectorLoadOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineVectorLoadOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
AffineVectorLoadOpAdaptor::AffineVectorLoadOpAdaptor(AffineVectorLoadOp op) : AffineVectorLoadOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineVectorLoadOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineVectorLoadOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineVectorLoadOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::MemRefType> AffineVectorLoadOp::getMemref() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(0).begin());
}

::mlir::Operation::operand_range AffineVectorLoadOp::getIndices() {
  return getODSOperands(1);
}

::mlir::MutableOperandRange AffineVectorLoadOp::getMemrefMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::mlir::MutableOperandRange AffineVectorLoadOp::getIndicesMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> AffineVectorLoadOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AffineVectorLoadOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::VectorType> AffineVectorLoadOp::getResult() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*getODSResults(0).begin());
}

void AffineVectorLoadOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value memref, ::mlir::ValueRange indices) {
  odsState.addOperands(memref);
  odsState.addOperands(indices);
  odsState.addTypes(result);
}

void AffineVectorLoadOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value memref, ::mlir::ValueRange indices) {
  odsState.addOperands(memref);
  odsState.addOperands(indices);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AffineVectorLoadOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() >= 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AffineVectorLoadOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps3(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineVectorLoadOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

void AffineVectorLoadOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
  for (::mlir::Value value : getODSOperands(0))
    effects.emplace_back(::mlir::MemoryEffects::Read::get(), value, ::mlir::SideEffects::DefaultResource::get());
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineVectorLoadOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineVectorStoreOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineVectorStoreOpGenericAdaptorBase::AffineVectorStoreOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.vector_store", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineVectorStoreOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {false, false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 2) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineVectorStoreOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
AffineVectorStoreOpAdaptor::AffineVectorStoreOpAdaptor(AffineVectorStoreOp op) : AffineVectorStoreOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineVectorStoreOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineVectorStoreOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {false, false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 2) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineVectorStoreOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::TypedValue<::mlir::VectorType> AffineVectorStoreOp::getValue() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*getODSOperands(0).begin());
}

::mlir::TypedValue<::mlir::MemRefType> AffineVectorStoreOp::getMemref() {
  return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(1).begin());
}

::mlir::Operation::operand_range AffineVectorStoreOp::getIndices() {
  return getODSOperands(2);
}

::mlir::MutableOperandRange AffineVectorStoreOp::getValueMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::mlir::MutableOperandRange AffineVectorStoreOp::getMemrefMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::mlir::MutableOperandRange AffineVectorStoreOp::getIndicesMutable() {
  auto range = getODSOperandIndexAndLength(2);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> AffineVectorStoreOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AffineVectorStoreOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::LogicalResult AffineVectorStoreOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps0(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineVectorStoreOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

void AffineVectorStoreOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
  for (::mlir::Value value : getODSOperands(1))
    effects.emplace_back(::mlir::MemoryEffects::Write::get(), value, ::mlir::SideEffects::DefaultResource::get());
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineVectorStoreOp)

namespace mlir {
namespace affine {

//===----------------------------------------------------------------------===//
// ::mlir::affine::AffineYieldOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AffineYieldOpGenericAdaptorBase::AffineYieldOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const ::mlir::EmptyProperties &properties, ::mlir::RegionRange regions) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
    odsOpName.emplace("affine.yield", odsAttrs.getContext());
}

std::pair<unsigned, unsigned> AffineYieldOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::DictionaryAttr AffineYieldOpGenericAdaptorBase::getAttributes() {
  return odsAttrs;
}

} // namespace detail
AffineYieldOpAdaptor::AffineYieldOpAdaptor(AffineYieldOp op) : AffineYieldOpAdaptor(op->getOperands(), op->getAttrDictionary(), op.getProperties(), op->getRegions()) {}

::mlir::LogicalResult AffineYieldOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AffineYieldOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::operand_range AffineYieldOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::operand_range AffineYieldOp::getOperands() {
  return getODSOperands(0);
}

::mlir::MutableOperandRange AffineYieldOp::getOperandsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

std::pair<unsigned, unsigned> AffineYieldOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AffineYieldOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

void AffineYieldOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState) {
 build(odsBuilder, odsState, std::nullopt); 
}

void AffineYieldOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands) {
  odsState.addOperands(operands);
}

void AffineYieldOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AffineYieldOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_AffineOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::mlir::LogicalResult AffineYieldOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::mlir::ParseResult AffineYieldOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::llvm::SmallVector<::mlir::OpAsmParser::UnresolvedOperand, 4> operandsOperands;
  ::llvm::SMLoc operandsOperandsLoc;
  (void)operandsOperandsLoc;
  ::llvm::SmallVector<::mlir::Type, 1> operandsTypes;
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }

  operandsOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperandList(operandsOperands))
    return ::mlir::failure();
  if (!operandsOperands.empty()) {
  if (parser.parseColon())
    return ::mlir::failure();

  if (parser.parseTypeList(operandsTypes))
    return ::mlir::failure();
  }
  if (parser.resolveOperands(operandsOperands, operandsTypes, operandsOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void AffineYieldOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  if (!getOperands().empty()) {
    _odsPrinter << ' ';
    _odsPrinter << getOperands();
    _odsPrinter << ' ' << ":";
    _odsPrinter << ' ';
    _odsPrinter << getOperands().getTypes();
  }
}

void AffineYieldOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}

} // namespace affine
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::affine::AffineYieldOp)


#endif  // GET_OP_CLASSES

