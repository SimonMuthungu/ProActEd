/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::mlir::nvgpu::DeviceAsyncTokenType,
::mlir::nvgpu::MBarrierType,
::mlir::nvgpu::MBarrierTokenType,
::mlir::nvgpu::TensorMapDescriptorType

#endif  // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::nvgpu::DeviceAsyncTokenType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::nvgpu::DeviceAsyncTokenType::get(parser.getContext());
      return ::mlir::success(!!value);
    })
    .Case(::mlir::nvgpu::MBarrierType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::nvgpu::MBarrierType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::nvgpu::MBarrierTokenType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::nvgpu::MBarrierTokenType::get(parser.getContext());
      return ::mlir::success(!!value);
    })
    .Case(::mlir::nvgpu::TensorMapDescriptorType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::nvgpu::TensorMapDescriptorType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::mlir::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::mlir::LogicalResult>(def)    .Case<::mlir::nvgpu::DeviceAsyncTokenType>([&](auto t) {
      printer << ::mlir::nvgpu::DeviceAsyncTokenType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::nvgpu::MBarrierType>([&](auto t) {
      printer << ::mlir::nvgpu::MBarrierType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::nvgpu::MBarrierTokenType>([&](auto t) {
      printer << ::mlir::nvgpu::MBarrierTokenType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::nvgpu::TensorMapDescriptorType>([&](auto t) {
      printer << ::mlir::nvgpu::TensorMapDescriptorType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace nvgpu {
} // namespace nvgpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::nvgpu::DeviceAsyncTokenType)
namespace mlir {
namespace nvgpu {
namespace detail {
struct MBarrierTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<Attribute>;
  MBarrierTypeStorage(Attribute memorySpace) : memorySpace(memorySpace) {}

  KeyTy getAsKey() const {
    return KeyTy(memorySpace);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (memorySpace == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static MBarrierTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, const KeyTy &tblgenKey) {
    auto memorySpace = std::get<0>(tblgenKey);
    return new (allocator.allocate<MBarrierTypeStorage>()) MBarrierTypeStorage(memorySpace);
  }

  Attribute memorySpace;
};
} // namespace detail
MBarrierType MBarrierType::get(::mlir::MLIRContext *context, Attribute memorySpace) {
  return Base::get(context, memorySpace);
}

::mlir::Type MBarrierType::parse(::mlir::AsmParser &odsParser) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<Attribute> _result_memorySpace;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};
  // Parse parameter struct
  bool _seen_memorySpace = false;
  {
    const auto _loop_body = [&](::llvm::StringRef _paramKey) -> bool {
      // Parse literal '='
      if (odsParser.parseEqual()) return {};
      if (!_seen_memorySpace && _paramKey == "memorySpace") {
        _seen_memorySpace = true;

        // Parse variable 'memorySpace'
        _result_memorySpace = ::mlir::FieldParser<Attribute>::parse(odsParser);
        if (::mlir::failed(_result_memorySpace)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse NVGPU_MBarrier parameter 'memorySpace' which is to be a `Attribute`");
          return {};
        }
      } else {
        odsParser.emitError(odsParser.getCurrentLocation(), "duplicate or unknown struct parameter name: ") << _paramKey;
        return {};
      }
      return true;
    };
    for (unsigned odsStructIndex = 0; odsStructIndex < 1; ++odsStructIndex) {
      ::llvm::StringRef _paramKey;
      if (odsParser.parseKeyword(&_paramKey)) {
        odsParser.emitError(odsParser.getCurrentLocation(),
                           "expected a parameter name in struct");
        return {};
      }
      if (!_loop_body(_paramKey)) return {};
      if ((odsStructIndex != 1 - 1) && odsParser.parseComma())
        return {};
    }
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_memorySpace));
  return MBarrierType::get(odsParser.getContext(),
      Attribute((*_result_memorySpace)));
}

void MBarrierType::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  {
    bool _firstPrinted = true;
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "memorySpace = ";
    odsPrinter.printStrippedAttrOrType(getMemorySpace());
  }
  odsPrinter << ">";
}

Attribute MBarrierType::getMemorySpace() const {
  return getImpl()->memorySpace;
}

} // namespace nvgpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MBarrierType)
namespace mlir {
namespace nvgpu {
} // namespace nvgpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MBarrierTokenType)
namespace mlir {
namespace nvgpu {
namespace detail {
struct TensorMapDescriptorTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<MemRefType, ::mlir::nvgpu::TensorMapSwizzleKind, ::mlir::nvgpu::TensorMapL2PromoKind, ::mlir::nvgpu::TensorMapOOBKind, ::mlir::nvgpu::TensorMapInterleaveKind>;
  TensorMapDescriptorTypeStorage(MemRefType tensor, ::mlir::nvgpu::TensorMapSwizzleKind swizzle, ::mlir::nvgpu::TensorMapL2PromoKind l2promo, ::mlir::nvgpu::TensorMapOOBKind oob, ::mlir::nvgpu::TensorMapInterleaveKind interleave) : tensor(tensor), swizzle(swizzle), l2promo(l2promo), oob(oob), interleave(interleave) {}

  KeyTy getAsKey() const {
    return KeyTy(tensor, swizzle, l2promo, oob, interleave);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (tensor == std::get<0>(tblgenKey)) && (swizzle == std::get<1>(tblgenKey)) && (l2promo == std::get<2>(tblgenKey)) && (oob == std::get<3>(tblgenKey)) && (interleave == std::get<4>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey), std::get<3>(tblgenKey), std::get<4>(tblgenKey));
  }

  static TensorMapDescriptorTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, const KeyTy &tblgenKey) {
    auto tensor = std::get<0>(tblgenKey);
    auto swizzle = std::get<1>(tblgenKey);
    auto l2promo = std::get<2>(tblgenKey);
    auto oob = std::get<3>(tblgenKey);
    auto interleave = std::get<4>(tblgenKey);
    return new (allocator.allocate<TensorMapDescriptorTypeStorage>()) TensorMapDescriptorTypeStorage(tensor, swizzle, l2promo, oob, interleave);
  }

  MemRefType tensor;
  ::mlir::nvgpu::TensorMapSwizzleKind swizzle;
  ::mlir::nvgpu::TensorMapL2PromoKind l2promo;
  ::mlir::nvgpu::TensorMapOOBKind oob;
  ::mlir::nvgpu::TensorMapInterleaveKind interleave;
};
} // namespace detail
TensorMapDescriptorType TensorMapDescriptorType::get(::mlir::MLIRContext *context, MemRefType tensor, ::mlir::nvgpu::TensorMapSwizzleKind swizzle, ::mlir::nvgpu::TensorMapL2PromoKind l2promo, ::mlir::nvgpu::TensorMapOOBKind oob, ::mlir::nvgpu::TensorMapInterleaveKind interleave) {
  return Base::get(context, tensor, swizzle, l2promo, oob, interleave);
}

::mlir::Type TensorMapDescriptorType::parse(::mlir::AsmParser &odsParser) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<MemRefType> _result_tensor;
  ::mlir::FailureOr<::mlir::nvgpu::TensorMapSwizzleKind> _result_swizzle;
  ::mlir::FailureOr<::mlir::nvgpu::TensorMapL2PromoKind> _result_l2promo;
  ::mlir::FailureOr<::mlir::nvgpu::TensorMapOOBKind> _result_oob;
  ::mlir::FailureOr<::mlir::nvgpu::TensorMapInterleaveKind> _result_interleave;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};
  // Parse parameter struct
  bool _seen_tensor = false;
  bool _seen_swizzle = false;
  bool _seen_l2promo = false;
  bool _seen_oob = false;
  bool _seen_interleave = false;
  {
    const auto _loop_body = [&](::llvm::StringRef _paramKey) -> bool {
      // Parse literal '='
      if (odsParser.parseEqual()) return {};
      if (!_seen_tensor && _paramKey == "tensor") {
        _seen_tensor = true;

        // Parse variable 'tensor'
        _result_tensor = ::mlir::FieldParser<MemRefType>::parse(odsParser);
        if (::mlir::failed(_result_tensor)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse NVGPU_TensorMapDescriptor parameter 'tensor' which is to be a `MemRefType`");
          return {};
        }
      } else if (!_seen_swizzle && _paramKey == "swizzle") {
        _seen_swizzle = true;

        // Parse variable 'swizzle'
        _result_swizzle = [&]() -> ::mlir::FailureOr<::mlir::nvgpu::TensorMapSwizzleKind> {
            auto loc = odsParser.getCurrentLocation();
            ::llvm::StringRef enumKeyword;
            if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
              return ::mlir::failure();
            auto maybeEnum = ::mlir::nvgpu::symbolizeTensorMapSwizzleKind(enumKeyword);
            if (maybeEnum)
              return *maybeEnum;
            return {(::mlir::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::nvgpu::TensorMapSwizzleKind" << " to be one of: " << "none" << ", " << "swizzle_32b" << ", " << "swizzle_64b" << ", " << "swizzle_128b")};
          }();
        if (::mlir::failed(_result_swizzle)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse NVGPU_TensorMapDescriptor parameter 'swizzle' which is to be a `::mlir::nvgpu::TensorMapSwizzleKind`");
          return {};
        }
      } else if (!_seen_l2promo && _paramKey == "l2promo") {
        _seen_l2promo = true;

        // Parse variable 'l2promo'
        _result_l2promo = [&]() -> ::mlir::FailureOr<::mlir::nvgpu::TensorMapL2PromoKind> {
            auto loc = odsParser.getCurrentLocation();
            ::llvm::StringRef enumKeyword;
            if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
              return ::mlir::failure();
            auto maybeEnum = ::mlir::nvgpu::symbolizeTensorMapL2PromoKind(enumKeyword);
            if (maybeEnum)
              return *maybeEnum;
            return {(::mlir::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::nvgpu::TensorMapL2PromoKind" << " to be one of: " << "none" << ", " << "l2promo_64b" << ", " << "l2promo_128b" << ", " << "l2promo_256b")};
          }();
        if (::mlir::failed(_result_l2promo)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse NVGPU_TensorMapDescriptor parameter 'l2promo' which is to be a `::mlir::nvgpu::TensorMapL2PromoKind`");
          return {};
        }
      } else if (!_seen_oob && _paramKey == "oob") {
        _seen_oob = true;

        // Parse variable 'oob'
        _result_oob = [&]() -> ::mlir::FailureOr<::mlir::nvgpu::TensorMapOOBKind> {
            auto loc = odsParser.getCurrentLocation();
            ::llvm::StringRef enumKeyword;
            if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
              return ::mlir::failure();
            auto maybeEnum = ::mlir::nvgpu::symbolizeTensorMapOOBKind(enumKeyword);
            if (maybeEnum)
              return *maybeEnum;
            return {(::mlir::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::nvgpu::TensorMapOOBKind" << " to be one of: " << "zero" << ", " << "nan")};
          }();
        if (::mlir::failed(_result_oob)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse NVGPU_TensorMapDescriptor parameter 'oob' which is to be a `::mlir::nvgpu::TensorMapOOBKind`");
          return {};
        }
      } else if (!_seen_interleave && _paramKey == "interleave") {
        _seen_interleave = true;

        // Parse variable 'interleave'
        _result_interleave = [&]() -> ::mlir::FailureOr<::mlir::nvgpu::TensorMapInterleaveKind> {
            auto loc = odsParser.getCurrentLocation();
            ::llvm::StringRef enumKeyword;
            if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
              return ::mlir::failure();
            auto maybeEnum = ::mlir::nvgpu::symbolizeTensorMapInterleaveKind(enumKeyword);
            if (maybeEnum)
              return *maybeEnum;
            return {(::mlir::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::nvgpu::TensorMapInterleaveKind" << " to be one of: " << "none" << ", " << "interleave_16b" << ", " << "interleave_32b")};
          }();
        if (::mlir::failed(_result_interleave)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse NVGPU_TensorMapDescriptor parameter 'interleave' which is to be a `::mlir::nvgpu::TensorMapInterleaveKind`");
          return {};
        }
      } else {
        odsParser.emitError(odsParser.getCurrentLocation(), "duplicate or unknown struct parameter name: ") << _paramKey;
        return {};
      }
      return true;
    };
    for (unsigned odsStructIndex = 0; odsStructIndex < 5; ++odsStructIndex) {
      ::llvm::StringRef _paramKey;
      if (odsParser.parseKeyword(&_paramKey)) {
        odsParser.emitError(odsParser.getCurrentLocation(),
                           "expected a parameter name in struct");
        return {};
      }
      if (!_loop_body(_paramKey)) return {};
      if ((odsStructIndex != 5 - 1) && odsParser.parseComma())
        return {};
    }
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_tensor));
  assert(::mlir::succeeded(_result_swizzle));
  assert(::mlir::succeeded(_result_l2promo));
  assert(::mlir::succeeded(_result_oob));
  assert(::mlir::succeeded(_result_interleave));
  return TensorMapDescriptorType::get(odsParser.getContext(),
      MemRefType((*_result_tensor)),
      ::mlir::nvgpu::TensorMapSwizzleKind((*_result_swizzle)),
      ::mlir::nvgpu::TensorMapL2PromoKind((*_result_l2promo)),
      ::mlir::nvgpu::TensorMapOOBKind((*_result_oob)),
      ::mlir::nvgpu::TensorMapInterleaveKind((*_result_interleave)));
}

void TensorMapDescriptorType::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  {
    bool _firstPrinted = true;
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "tensor = ";
    odsPrinter.printStrippedAttrOrType(getTensor());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "swizzle = ";
    odsPrinter << stringifyTensorMapSwizzleKind(getSwizzle());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "l2promo = ";
    odsPrinter << stringifyTensorMapL2PromoKind(getL2promo());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "oob = ";
    odsPrinter << stringifyTensorMapOOBKind(getOob());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "interleave = ";
    odsPrinter << stringifyTensorMapInterleaveKind(getInterleave());
  }
  odsPrinter << ">";
}

MemRefType TensorMapDescriptorType::getTensor() const {
  return getImpl()->tensor;
}

::mlir::nvgpu::TensorMapSwizzleKind TensorMapDescriptorType::getSwizzle() const {
  return getImpl()->swizzle;
}

::mlir::nvgpu::TensorMapL2PromoKind TensorMapDescriptorType::getL2promo() const {
  return getImpl()->l2promo;
}

::mlir::nvgpu::TensorMapOOBKind TensorMapDescriptorType::getOob() const {
  return getImpl()->oob;
}

::mlir::nvgpu::TensorMapInterleaveKind TensorMapDescriptorType::getInterleave() const {
  return getImpl()->interleave;
}

} // namespace nvgpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::nvgpu::TensorMapDescriptorType)
namespace mlir {
namespace nvgpu {

/// Parse a type registered to this dialect.
::mlir::Type NVGPUDialect::parseType(::mlir::DialectAsmParser &parser) const {
  ::llvm::SMLoc typeLoc = parser.getCurrentLocation();
  ::llvm::StringRef mnemonic;
  ::mlir::Type genType;
  auto parseResult = generatedTypeParser(parser, &mnemonic, genType);
  if (parseResult.has_value())
    return genType;
  
  parser.emitError(typeLoc) << "unknown  type `"
      << mnemonic << "` in dialect `" << getNamespace() << "`";
  return {};
}
/// Print a type registered to this dialect.
void NVGPUDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}
} // namespace nvgpu
} // namespace mlir

#endif  // GET_TYPEDEF_CLASSES

