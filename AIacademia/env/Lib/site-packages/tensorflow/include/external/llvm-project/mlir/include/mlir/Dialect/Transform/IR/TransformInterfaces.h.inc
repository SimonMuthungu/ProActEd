/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace transform {
class TransformOpInterface;
namespace detail {
struct TransformOpInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    ::mlir::DiagnosedSilenceableFailure (*apply)(const Concept *impl, ::mlir::Operation *, ::mlir::transform::TransformRewriter &, ::mlir::transform::TransformResults &, ::mlir::transform::TransformState &);
    bool (*allowsRepeatedHandleOperands)(const Concept *impl, ::mlir::Operation *);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::transform::TransformOpInterface;
    Model() : Concept{apply, allowsRepeatedHandleOperands} {}

    static inline ::mlir::DiagnosedSilenceableFailure apply(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::transform::TransformRewriter & rewriter, ::mlir::transform::TransformResults & transformResults, ::mlir::transform::TransformState & state);
    static inline bool allowsRepeatedHandleOperands(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::transform::TransformOpInterface;
    FallbackModel() : Concept{apply, allowsRepeatedHandleOperands} {}

    static inline ::mlir::DiagnosedSilenceableFailure apply(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::transform::TransformRewriter & rewriter, ::mlir::transform::TransformResults & transformResults, ::mlir::transform::TransformState & state);
    static inline bool allowsRepeatedHandleOperands(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
    bool allowsRepeatedHandleOperands(::mlir::Operation *tablegen_opaque_val) const;
  };
};template <typename ConcreteOp>
struct TransformOpInterfaceTrait;

} // namespace detail
class TransformOpInterface : public ::mlir::OpInterface<TransformOpInterface, detail::TransformOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<TransformOpInterface, detail::TransformOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::TransformOpInterfaceTrait<ConcreteOp> {};
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
  ::mlir::DiagnosedSilenceableFailure apply(::mlir::transform::TransformRewriter & rewriter, ::mlir::transform::TransformResults & transformResults, ::mlir::transform::TransformState & state);
  /// Indicates whether the op instance allows its handle operands to be
  /// associated with the same payload operations.
  bool allowsRepeatedHandleOperands();

    /// Creates the silenceable failure object with a diagnostic located at the
    /// current operation. Silenceable failure must be suppressed or reported
    /// explicitly at some later time.
    DiagnosedSilenceableFailure
    emitSilenceableError(const ::llvm::Twine &message = {}) {
      return ::mlir::emitSilenceableFailure((*this), message);
    }

    /// Creates the definite failure object with a diagnostic located at the
    /// current operation. Definite failure will be reported when the object
    /// is destroyed or converted.
    DiagnosedDefiniteFailure
    emitDefiniteFailure(const ::llvm::Twine &message = {}) {
      return ::mlir::emitDefiniteFailure((*this), message);
    }

    /// Emits a generic definite failure for the current transform operation
    /// targeting the given Payload IR operation and returns failure. Should
    /// be only used as a last resort when the transformation itself provides
    /// no further indication as to the reason of the failure.
    DiagnosedDefiniteFailure emitDefaultDefiniteFailure(
        ::mlir::Operation *target) {
      auto diag = ::mlir::emitDefiniteFailure((*this), "failed to apply");
      diag.attachNote(target->getLoc()) << "attempted to apply to this op";
      return diag;
    }

    /// Creates the default silenceable failure for a transform op that failed
    /// to properly apply to a target.
    DiagnosedSilenceableFailure emitDefaultSilenceableFailure(
        Operation *target) {
      DiagnosedSilenceableFailure diag = emitSilenceableFailure((*this)->getLoc());
      diag << (*this)->getName() << " failed to apply";
      diag.attachNote(target->getLoc()) << "when applied to this op";
      return diag;
    }

    /// Returns all operands that are handles and being consumed by this op.
    ::llvm::SmallVector<OpOperand *> getConsumedHandleOpOperands() {
      return ::mlir::transform::detail::getConsumedHandleOpOperands((*this));
    }
};
namespace detail {
  template <typename ConcreteOp>
  struct TransformOpInterfaceTrait : public ::mlir::OpInterface<TransformOpInterface, detail::TransformOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
    /// Indicates whether the op instance allows its handle operands to be
    /// associated with the same payload operations.
    bool allowsRepeatedHandleOperands() {
      return false;
    }
    static ::mlir::LogicalResult verifyTrait(::mlir::Operation *op) {
      return ::mlir::transform::detail::verifyTransformOpInterface(op);
    }

    /// Creates the silenceable failure object with a diagnostic located at the
    /// current operation. Silenceable failure must be suppressed or reported
    /// explicitly at some later time.
    DiagnosedSilenceableFailure
    emitSilenceableError(const ::llvm::Twine &message = {}) {
      return ::mlir::emitSilenceableFailure((*static_cast<ConcreteOp *>(this)), message);
    }

    /// Creates the definite failure object with a diagnostic located at the
    /// current operation. Definite failure will be reported when the object
    /// is destroyed or converted.
    DiagnosedDefiniteFailure
    emitDefiniteFailure(const ::llvm::Twine &message = {}) {
      return ::mlir::emitDefiniteFailure((*static_cast<ConcreteOp *>(this)), message);
    }

    /// Emits a generic definite failure for the current transform operation
    /// targeting the given Payload IR operation and returns failure. Should
    /// be only used as a last resort when the transformation itself provides
    /// no further indication as to the reason of the failure.
    DiagnosedDefiniteFailure emitDefaultDefiniteFailure(
        ::mlir::Operation *target) {
      auto diag = ::mlir::emitDefiniteFailure((*static_cast<ConcreteOp *>(this)), "failed to apply");
      diag.attachNote(target->getLoc()) << "attempted to apply to this op";
      return diag;
    }

    /// Creates the default silenceable failure for a transform op that failed
    /// to properly apply to a target.
    DiagnosedSilenceableFailure emitDefaultSilenceableFailure(
        Operation *target) {
      DiagnosedSilenceableFailure diag = emitSilenceableFailure((*static_cast<ConcreteOp *>(this))->getLoc());
      diag << (*static_cast<ConcreteOp *>(this))->getName() << " failed to apply";
      diag.attachNote(target->getLoc()) << "when applied to this op";
      return diag;
    }

    /// Returns all operands that are handles and being consumed by this op.
    ::llvm::SmallVector<OpOperand *> getConsumedHandleOpOperands() {
      return ::mlir::transform::detail::getConsumedHandleOpOperands((*static_cast<ConcreteOp *>(this)));
    }
  
  };
}// namespace detail
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class FindPayloadReplacementOpInterface;
namespace detail {
struct FindPayloadReplacementOpInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    ::llvm::SmallVector<::mlir::Value> (*getNextOperands)(const Concept *impl, ::mlir::Operation *);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::transform::FindPayloadReplacementOpInterface;
    Model() : Concept{getNextOperands} {}

    static inline ::llvm::SmallVector<::mlir::Value> getNextOperands(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::transform::FindPayloadReplacementOpInterface;
    FallbackModel() : Concept{getNextOperands} {}

    static inline ::llvm::SmallVector<::mlir::Value> getNextOperands(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
  };
};template <typename ConcreteOp>
struct FindPayloadReplacementOpInterfaceTrait;

} // namespace detail
class FindPayloadReplacementOpInterface : public ::mlir::OpInterface<FindPayloadReplacementOpInterface, detail::FindPayloadReplacementOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<FindPayloadReplacementOpInterface, detail::FindPayloadReplacementOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::FindPayloadReplacementOpInterfaceTrait<ConcreteOp> {};
  /// Return the operands at which the lookup for replacement payload ops
  /// should continue.
  ::llvm::SmallVector<::mlir::Value> getNextOperands();
};
namespace detail {
  template <typename ConcreteOp>
  struct FindPayloadReplacementOpInterfaceTrait : public ::mlir::OpInterface<FindPayloadReplacementOpInterface, detail::FindPayloadReplacementOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
  };
}// namespace detail
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class PatternDescriptorOpInterface;
namespace detail {
struct PatternDescriptorOpInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    void (*populatePatterns)(const Concept *impl, ::mlir::Operation *, RewritePatternSet &);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::transform::PatternDescriptorOpInterface;
    Model() : Concept{populatePatterns} {}

    static inline void populatePatterns(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewritePatternSet & patterns);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::transform::PatternDescriptorOpInterface;
    FallbackModel() : Concept{populatePatterns} {}

    static inline void populatePatterns(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewritePatternSet & patterns);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
  };
};template <typename ConcreteOp>
struct PatternDescriptorOpInterfaceTrait;

} // namespace detail
class PatternDescriptorOpInterface : public ::mlir::OpInterface<PatternDescriptorOpInterface, detail::PatternDescriptorOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<PatternDescriptorOpInterface, detail::PatternDescriptorOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::PatternDescriptorOpInterfaceTrait<ConcreteOp> {};
  /// Populate patterns into the given pattern set.
  void populatePatterns(RewritePatternSet & patterns);
};
namespace detail {
  template <typename ConcreteOp>
  struct PatternDescriptorOpInterfaceTrait : public ::mlir::OpInterface<PatternDescriptorOpInterface, detail::PatternDescriptorOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
  };
}// namespace detail
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
template<typename ConcreteOp>
::mlir::DiagnosedSilenceableFailure detail::TransformOpInterfaceInterfaceTraits::Model<ConcreteOp>::apply(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::transform::TransformRewriter & rewriter, ::mlir::transform::TransformResults & transformResults, ::mlir::transform::TransformState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).apply(rewriter, transformResults, state);
}
template<typename ConcreteOp>
bool detail::TransformOpInterfaceInterfaceTraits::Model<ConcreteOp>::allowsRepeatedHandleOperands(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).allowsRepeatedHandleOperands();
}
template<typename ConcreteOp>
::mlir::DiagnosedSilenceableFailure detail::TransformOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::apply(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::transform::TransformRewriter & rewriter, ::mlir::transform::TransformResults & transformResults, ::mlir::transform::TransformState & state) {
  return static_cast<const ConcreteOp *>(impl)->apply(tablegen_opaque_val, rewriter, transformResults, state);
}
template<typename ConcreteOp>
bool detail::TransformOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::allowsRepeatedHandleOperands(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->allowsRepeatedHandleOperands(tablegen_opaque_val);
}
template<typename ConcreteModel, typename ConcreteOp>
bool detail::TransformOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::allowsRepeatedHandleOperands(::mlir::Operation *tablegen_opaque_val) const {
return false;
}
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
template<typename ConcreteOp>
::llvm::SmallVector<::mlir::Value> detail::FindPayloadReplacementOpInterfaceInterfaceTraits::Model<ConcreteOp>::getNextOperands(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getNextOperands();
}
template<typename ConcreteOp>
::llvm::SmallVector<::mlir::Value> detail::FindPayloadReplacementOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getNextOperands(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getNextOperands(tablegen_opaque_val);
}
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
template<typename ConcreteOp>
void detail::PatternDescriptorOpInterfaceInterfaceTraits::Model<ConcreteOp>::populatePatterns(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewritePatternSet & patterns) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).populatePatterns(patterns);
}
template<typename ConcreteOp>
void detail::PatternDescriptorOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::populatePatterns(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewritePatternSet & patterns) {
  return static_cast<const ConcreteOp *>(impl)->populatePatterns(tablegen_opaque_val, patterns);
}
} // namespace transform
} // namespace mlir
