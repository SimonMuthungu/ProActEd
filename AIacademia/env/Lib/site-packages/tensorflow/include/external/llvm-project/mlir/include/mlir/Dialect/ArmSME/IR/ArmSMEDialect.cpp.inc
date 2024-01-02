/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::arm_sme::ArmSMEDialect)
namespace mlir {
namespace arm_sme {

ArmSMEDialect::ArmSMEDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<ArmSMEDialect>()) {
  
    getContext()->loadDialect<scf::SCFDialect>();

    getContext()->loadDialect<vector::VectorDialect>();

  initialize();
}

ArmSMEDialect::~ArmSMEDialect() = default;

} // namespace arm_sme
} // namespace mlir
