/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mlir {
namespace nvgpu {
class DeviceAsyncTokenType;
class MBarrierType;
class MBarrierTokenType;
class TensorMapDescriptorType;
class DeviceAsyncTokenType : public ::mlir::Type::TypeBase<DeviceAsyncTokenType, ::mlir::Type, ::mlir::TypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"device.async.token"};
  }

};
namespace detail {
struct MBarrierTypeStorage;
} // namespace detail
class MBarrierType : public ::mlir::Type::TypeBase<MBarrierType, ::mlir::Type, detail::MBarrierTypeStorage> {
public:
  using Base::Base;
  static MBarrierType get(::mlir::MLIRContext *context, Attribute memorySpace);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"mbarrier.barrier"};
  }

  static ::mlir::Type parse(::mlir::AsmParser &odsParser);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  Attribute getMemorySpace() const;
};
class MBarrierTokenType : public ::mlir::Type::TypeBase<MBarrierTokenType, ::mlir::Type, ::mlir::TypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"mbarrier.token"};
  }

};
namespace detail {
struct TensorMapDescriptorTypeStorage;
} // namespace detail
class TensorMapDescriptorType : public ::mlir::Type::TypeBase<TensorMapDescriptorType, ::mlir::Type, detail::TensorMapDescriptorTypeStorage> {
public:
  using Base::Base;
  static TensorMapDescriptorType get(::mlir::MLIRContext *context, MemRefType tensor, ::mlir::nvgpu::TensorMapSwizzleKind swizzle, ::mlir::nvgpu::TensorMapL2PromoKind l2promo, ::mlir::nvgpu::TensorMapOOBKind oob, ::mlir::nvgpu::TensorMapInterleaveKind interleave);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"tensormap.descriptor"};
  }

  static ::mlir::Type parse(::mlir::AsmParser &odsParser);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  MemRefType getTensor() const;
  ::mlir::nvgpu::TensorMapSwizzleKind getSwizzle() const;
  ::mlir::nvgpu::TensorMapL2PromoKind getL2promo() const;
  ::mlir::nvgpu::TensorMapOOBKind getOob() const;
  ::mlir::nvgpu::TensorMapInterleaveKind getInterleave() const;
};
} // namespace nvgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::DeviceAsyncTokenType)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MBarrierType)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::MBarrierTokenType)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::nvgpu::TensorMapDescriptorType)

#endif  // GET_TYPEDEF_CLASSES

