/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Definitions                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

/// Return the operands at which the lookup for replacement payload ops
/// should continue.
::llvm::SmallVector<::mlir::Value> mlir::transform::FindPayloadReplacementOpInterface::getNextOperands() {
      return getImpl()->getNextOperands(getImpl(), getOperation());
  }
/// Populate patterns into the given pattern set.
void mlir::transform::PatternDescriptorOpInterface::populatePatterns(RewritePatternSet & patterns) {
      return getImpl()->populatePatterns(getImpl(), getOperation(), patterns);
  }
/// Applies the transformation represented by the current operation. This
/// accepts as arguments the object that must be populated with results of
/// the current transformation and a transformation state object that can be
/// used for queries, e.g., to obtain the list of operations on which the
/// transformation represented by the current op is targeted. Returns a
/// special status object indicating whether the transformation succeeded
/// or failed, and, if it failed, whether the failure is recoverable or not.
/// 
/// IR must be created, modified and deleted with the provided rewriter.
/// implementations are responsible for setting the insertion point of the
/// rewriter to the desired location.
::mlir::DiagnosedSilenceableFailure mlir::transform::TransformOpInterface::apply(::mlir::transform::TransformRewriter & rewriter, ::mlir::transform::TransformResults & transformResults, ::mlir::transform::TransformState & state) {
      return getImpl()->apply(getImpl(), getOperation(), rewriter, transformResults, state);
  }
/// Indicates whether the op instance allows its handle operands to be
/// associated with the same payload operations.
bool mlir::transform::TransformOpInterface::allowsRepeatedHandleOperands() {
      return getImpl()->allowsRepeatedHandleOperands(getImpl(), getOperation());
  }
