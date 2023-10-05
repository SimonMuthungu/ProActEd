(function (global, factory) {
    typeof exports === 'object' && typeof module !== 'undefined' ? module.exports = factory() :
    typeof define === 'function' && define.amd ? define(factory) :
    (global.Popper = factory());
  }(this, (function () { 'use strict';
  
    function _defineProperty(obj, key, value) {
      if (key in obj) {
        Object.defineProperty(obj, key, {
          value: value,
          enumerable: true,
          configurable: true,
          writable: true
        });
      } else {
        obj[key] = value;
      }
  
      return obj;
    }
  
    function _objectSpread(target) {
      for (var i = 1; i < arguments.length; i++) {
        var source = arguments[i] != null ? arguments[i] : {};
        var ownKeys = Object.keys(source);
  
        if (typeof Object.getOwnPropertySymbols === 'function') {
          ownKeys = ownKeys.concat(Object.getOwnPropertySymbols(source).filter(function (sym) {
            return Object.getOwnPropertyDescriptor(source, sym).enumerable;
          }));
        }
  
        ownKeys.forEach(function (key) {
          _defineProperty(target, key, source[key]);
        });
      }
  
      return target;
    }
  
    function getWindow(node) {
      const ownerDocument = node.ownerDocument;
      return ownerDocument ? ownerDocument.defaultView : window;
    }
  
    function getComputedStyle(element) {
      return getWindow(element).getComputedStyle(element);
    }
  
    var getElementClientRect = (element => {
      // get the basic client rect, it doesn't include margins
      const width = element.offsetWidth;
      const height = element.offsetHeight;
      const top = element.offsetTop;
      const left = element.offsetLeft; // get the element margins, we need them to properly align the popper
  
      const styles = getComputedStyle(element);
      const marginTop = parseFloat(styles.marginTop) || 0;
      const marginRight = parseFloat(styles.marginRight) || 0;
      const marginBottom = parseFloat(styles.marginBottom) || 0;
      const marginLeft = parseFloat(styles.marginLeft) || 0;
      return {
        width: width + marginLeft + marginRight,
        height: height + marginTop + marginBottom,
        y: top - marginTop,
        x: left - marginLeft
      };
    });
  
    var getParentNode = (element => {
      if (element.nodeName === 'HTML') {
        // DocumentElement detectedF
        return element;
      }
  
      return element.parentNode || // DOM Element detected
      // $FlowFixMe: need a better way to handle this...
      element.host || // ShadowRoot detected
      document.ownerDocument || // Fallback to ownerDocument if available
      document.documentElement // Or to documentElement if everything else fails
      ;
    });
  
    function getScrollParent(node) {
      if (!node) {
        return document.body;
      }
  
      switch (node.nodeName) {
        case 'HTML':
        case 'BODY':
          return node.ownerDocument.body;
  
        case '#document':
          // Flow doesn't understand nodeName type refinement unfortunately
          return node.body;
      }
  
      if (node instanceof HTMLElement) {
        // Firefox want us to check `-x` and `-y` variations as well
        const {
          overflow,
          overflowX,
          overflowY
        } = getComputedStyle(node);
  
        if (/(auto|scroll|overlay)/.test(overflow + overflowY + overflowX)) {
          return node;
        }
      }
  
      return getScrollParent(getParentNode(node));
    }
  
    function listScrollParents(element, list = []) {
      const scrollParent = getScrollParent(element);
      const isBody = scrollParent.nodeName === 'BODY';
      const target = isBody ? scrollParent.ownerDocument.defaultView : scrollParent;
      const updatedList = list.concat(target);
      return isBody ? updatedList : updatedList.concat(listScrollParents(getParentNode(target)));
    }
  
    function getWindowScroll(node) {
      const win = getWindow(node);
      const scrollLeft = win.pageXOffset;
      const scrollTop = win.pageYOffset;
      return {
        scrollLeft,
        scrollTop
      };
    }
  
    function getHTMLElementScroll(element) {
      return {
        scrollLeft: element.scrollLeft,
        scrollTop: element.scrollTop
      };
    }
  
    function getElementScroll(node) {
      if (node === getWindow(node) || !(node instanceof HTMLElement)) {
        return getWindowScroll(node);
      } else {
        return getHTMLElementScroll(node);
      }
    }
  
    function getOffsetParent(element) {
      const offsetParent = element instanceof HTMLElement ? element.offsetParent : null;
      const window = getWindow(element);
  
      if (offsetParent && offsetParent.nodeName && offsetParent.nodeName.toUpperCase() === 'BODY') {
        return window;
      }
  
      return offsetParent || window;
    }
  
    const sumScroll = scrollParents => scrollParents.reduce((scroll, scrollParent) => {
      const nodeScroll = getElementScroll(scrollParent);
      scroll.scrollTop += nodeScroll.scrollTop;
      scroll.scrollLeft += nodeScroll.scrollLeft;
      return scroll;
    }, {
      scrollTop: 0,
      scrollLeft: 0
    });
  
    function getCommonTotalScroll(reference, referenceScrollParents, popperScrollParents) {
      // if the scrollParent is shared between the two elements, we don't pick
      // it because it wouldn't add anything to the equation (they nulllify themselves)
      const nonCommonReference = referenceScrollParents.filter(node => !popperScrollParents.includes(node)); // we then want to pick any scroll offset except for the one of the offsetParent
      // not sure why but that's how I got it working 😅
      // TODO: improve this comment with proper explanation
  
      const offsetParent = getOffsetParent(reference);
      const index = referenceScrollParents.findIndex(node => node === offsetParent);
      const scrollParents = referenceScrollParents.slice(0, index === -1 ? undefined : index);
      return sumScroll(scrollParents);
    }
  
    var unwrapJqueryElement = (element => element && element.jquery ? element[0] : element);
  
    // source: https://stackoverflow.com/questions/49875255
    const order = modifiers => {
      // indexed by name
      const mapped = modifiers.reduce((mem, i) => {
        mem[i.name] = i;
        return mem;
      }, {}); // inherit all dependencies for a given name
  
      const inherited = i => {
        return mapped[i].requires.reduce((mem, i) => {
          return [...mem, i, ...inherited(i)];
        }, []);
      }; // order ...
  
  
      const ordered = modifiers.sort((a, b) => {
        return !!~inherited(b.name).indexOf(a.name) ? -1 : 1;
      });
      return ordered;
    };
  
    var orderModifiers = (modifiers => [...order(modifiers.filter(({
      phase
    }) => phase === 'read')), ...order(modifiers.filter(({
      phase
    }) => phase === 'main')), ...order(modifiers.filter(({
      phase
    }) => phase === 'write'))]);
  
    // Expands the eventListeners value to an object containing the
    // `scroll` and `resize` booleans
    //
    // true => true, true
    // false => false, false
    // true, false => true, false
    // false, false => false, false
    var expandEventListeners = (eventListeners => {
      const fallbackValue = typeof eventListeners === 'boolean' ? eventListeners : false;
      return {
        scroll: typeof eventListeners.scroll === 'boolean' ? eventListeners.scroll : fallbackValue,
        resize: typeof eventListeners.resize === 'boolean' ? eventListeners.resize : fallbackValue
      };
    });
  
    var getBasePlacement = (placement => placement.split('-')[0]);
  
    const top = 'top';
    const bottom = 'bottom';
    const right = 'right';
    const left = 'left';
    const basePlacements = [top, bottom, right, left];
    const start = 'start';
    const end = 'end';
    const placements = basePlacements.reduce((acc, placement) => acc.concat([placement, `${placement}-${start}`, `${placement}-${end}`]), []); // modifiers that need to read the DOM
  
    const read = 'read'; // pure-logic modifiers
  
    const main = 'main'; // modifier with the purpose to write to the DOM (or write into a framework state)
  
    const write = 'write';
  
    var computeOffsets = (({
      reference,
      popper,
      strategy,
      placement,
      scroll
    }) => {
      const basePlacement = getBasePlacement(placement);
      const {
        scrollTop,
        scrollLeft
      } = scroll;
  
      switch (basePlacement) {
        case top:
          return {
            x: reference.x + reference.width / 2 - popper.width / 2 - scrollLeft,
            y: reference.y - popper.height - scrollTop
          };
  
        case bottom:
          return {
            x: reference.x + reference.width / 2 - popper.width / 2 - scrollLeft,
            y: reference.y + reference.height - scrollTop
          };
  
        case right:
          return {
            x: reference.x + reference.width - scrollLeft,
            y: reference.y + reference.height / 2 - popper.height / 2 - scrollTop
          };
  
        case left:
        default:
          return {
            x: reference.x - popper.width - scrollLeft,
            y: reference.y + reference.height / 2 - popper.height / 2 - scrollTop
          };
      }
    });
  
    var format = ((str, ...args) => [...args].reduce((p, c) => p.replace(/%s/, c), str));
  
    function microtaskDebounce(fn) {
      let called = false;
      return () => new Promise(resolve => {
        if (called) {
          return resolve();
        }
  
        called = true;
        Promise.resolve().then(() => {
          called = false;
          resolve(fn());
        });
      });
    }
  
    const ERROR_MESSAGE = 'PopperJS: modifier "%s" provided an invalid %s property, expected %s but got %s';
    const VALID_PROPERTIES = ['name', 'enabled', 'phase', 'fn', 'onLoad', 'requires', 'options'];
    var validateModifiers = (modifiers => {
      modifiers.forEach(modifier => {
        Object.keys(modifier).forEach(key => {
          switch (key) {
            case 'name':
              if (typeof modifier.name !== 'string') {
                console.error(format(ERROR_MESSAGE, String(modifier.name), '"name"', '"string"', `"${String(modifier.name)}"`));
              }
  
              break;
  
            case 'enabled':
              if (typeof modifier.enabled !== 'boolean') {
                console.error(format(ERROR_MESSAGE, modifier.name, '"enabled"', '"boolean"', `"${String(modifier.enabled)}"`));
              }
  
            case 'phase':
              if (![read, main, write].includes(modifier.phase)) {
                console.error(format(ERROR_MESSAGE, modifier.name, '"phase"', 'either "read", "main" or "write"', `"${String(modifier.phase)}"`));
              }
  
              break;
  
            case 'fn':
              if (typeof modifier.fn !== 'function') {
                console.error(format(ERROR_MESSAGE, modifier.name, '"fn"', '"function"', `"${String(modifier.fn)}"`));
              }
  
              break;
  
            case 'onLoad':
              if (typeof modifier.onLoad !== 'function') {
                console.error(format(ERROR_MESSAGE, modifier.name, '"onLoad"', '"function"', `"${String(modifier.fn)}"`));
              }
  
              break;
  
            case 'requires':
              if (!Array.isArray(modifier.requires)) {
                console.error(format(ERROR_MESSAGE, modifier.name, '"requires"', '"array"', `"${String(modifier.requires)}"`));
              }
  
              break;
  
            case 'object':
              break;
  
            default:
              console.error(`PopperJS: an invalid property has been provided to the "${modifier.name}" modifier, valid properties are ${VALID_PROPERTIES.map(s => `"${s}"`).join(', ')}; but "${key}" was provided.`);
          }
        });
      });
    });
  
    // This modifier takes the Popper.js state and prepares some StyleSheet properties
    // that can be applied to the popper element to make it render in the expected position.
    const mapStrategyToPosition = strategy => {
      switch (strategy) {
        case 'fixed':
          return 'fixed';
  
        case 'absolute':
        default:
          return 'absolute';
      }
    };
    const computePopperStyles = ({
      offsets,
      strategy,
      gpuAcceleration
    }) => {
      // by default it is active, disable it only if explicitly set to false
      if (gpuAcceleration === false) {
        return {
          top: `${offsets.y}px`,
          left: `${offsets.x}px`,
          position: mapStrategyToPosition(strategy)
        };
      } else {
        return {
          transform: `translate3d(${offsets.x}px, ${offsets.y}px, 0)`,
          position: mapStrategyToPosition(strategy)
        };
      }
    };
    const computeArrowStyles = ({
      offsets,
      gpuAcceleration
    }) => {
      if (gpuAcceleration) {
        return {
          top: `${offsets.y}px`,
          left: `${offsets.x}px`,
          position: 'absolute'
        };
      } else {
        return {
          transform: `translate3d(${offsets.x}px, ${offsets.y}px, 0)`,
          position: 'absolute'
        };
      }
    };
    function computeStyles(state, options) {
      const gpuAcceleration = options && options.gpuAcceleration != null ? options.gpuAcceleration : true;
      state.styles = {}; // popper offsets are always available
  
      state.styles.popper = computePopperStyles({
        offsets: state.offsets.popper,
        strategy: state.options.strategy,
        gpuAcceleration
      }); // arrow offsets may not be available
  
      if (state.offsets.arrow != null) {
        state.styles.arrow = computeArrowStyles({
          offsets: state.offsets.arrow,
          gpuAcceleration
        });
      }
  
      return state;
    }
    var computeStyles$1 = {
      name: 'computeStyles',
      enabled: true,
      phase: 'main',
      fn: computeStyles
    };
  
    // This modifier takes the styles prepared by the `computeStyles` modifier
    // and applies them to the HTMLElements such as popper and arrow
    function applyStyles(state) {
      Object.keys(state.elements).forEach(name => {
        const style = state.styles.hasOwnProperty(name) ? state.styles[name] : null; // Flow doesn't support to extend this property, but it's the most
        // effective way to apply styles to an HTMLElemen
        // $FlowIgnore
  
        Object.assign(state.elements[name].style, style);
      });
      return state;
    }
    var applyStyles$1 = {
      name: 'applyStyles',
      enabled: true,
      phase: 'write',
      fn: applyStyles,
      requires: ['computeStyles']
    };
  
    //export { default as preventOverflow } from './preventOverflow';
  
    var modifiers = /*#__PURE__*/Object.freeze({
      computeStyles: computeStyles$1,
      applyStyles: applyStyles$1
    });
  
    const defaultModifiers = Object.values(modifiers);
  
    const areValidElements = (a, b) => a instanceof Element && b instanceof Element;
  
    const defaultOptions = {
      placement: 'bottom',
      eventListeners: {
        scroll: true,
        resize: true
      },
      modifiers: [],
      strategy: 'absolute'
    };
    class Popper {
      constructor(reference, popper, options = defaultOptions) {
        _defineProperty(this, "state", {
          placement: 'bottom',
          orderedModifiers: [],
          options: defaultOptions
        });
  
        // make update() debounced, so that it only runs at most once-per-tick
        this.update = microtaskDebounce(this.update.bind(this)); // Unwrap `reference` and `popper` elements in case they are
        // wrapped by jQuery, otherwise consume them as is
  
        this.state.elements = {
          reference: unwrapJqueryElement(reference),
          popper: unwrapJqueryElement(popper)
        };
        const {
          reference: referenceElement,
          popper: popperElement
        } = this.state.elements; // Store options into state
  
        this.state.options = _objectSpread({}, defaultOptions, options); // Cache the placement in cache to make it available to the modifiers
        // modifiers will modify this one (rather than the one in options)
  
        this.state.placement = options.placement; // Don't proceed if `reference` or `popper` are invalid elements
  
        if (!areValidElements(referenceElement, popperElement)) {
          return;
        }
  
        this.state.scrollParents = {
          reference: listScrollParents(referenceElement),
          popper: listScrollParents(popperElement)
        }; // Order `options.modifiers` so that the dependencies are fulfilled
        // once the modifiers are executed
  
        this.state.orderedModifiers = orderModifiers([...defaultModifiers, ...this.state.options.modifiers]); // Validate the provided modifiers so that the consumer will get warned
        // of one of the custom modifiers is invalid for any reason
  
        {
          validateModifiers(this.state.options.modifiers);
        } // Modifiers have the opportunity to execute some arbitrary code before
        // the first update cycle is ran, the order of execution will be the same
        // defined by the modifier dependencies directive.
        // The `onLoad` function may add or alter the options of themselves
  
  
        this.state.orderedModifiers.forEach(({
          onLoad,
          enabled
        }) => enabled && onLoad && onLoad(this.state));
        this.update().then(() => {
          // After the first update completed, enable the event listeners
          this.enableEventListeners(this.state.options.eventListeners);
        });
      } // Async and optimistically optimized update
      // it will not be executed if not necessary
      // check Popper#constructor to see how it gets debounced
  
  
      update() {
        return new Promise((success, reject) => {
          this.forceUpdate();
          success(this.state);
        });
      } // Syncronous and forcefully executed update
      // it will always be executed even if not necessary, usually NOT needed
      // use Popper#update instead
  
  
      forceUpdate() {
        const {
          reference: referenceElement,
          popper: popperElement
        } = this.state.elements; // Don't proceed if `reference` or `popper` are not valid elements anymore
  
        if (!areValidElements(referenceElement, popperElement)) {
          return;
        } // Get initial measurements
        // these are going to be used to compute the initial popper offsets
        // and as cache for any modifier that needs them later
  
  
        this.state.measures = {
          reference: getElementClientRect(referenceElement),
          popper: getElementClientRect(popperElement)
        }; // Get scrollTop and scrollLeft of the offsetParent
        // this will be used in the `computeOffsets` function to properly
        // position the popper taking in account the scroll position
        // FIXME: right now we only look for a single offsetParent (the popper one)
        //        but we really want to take in account the reference offsetParent as well
  
        const offsetParentScroll = getElementScroll(getOffsetParent(popperElement)); // Offsets are the actual position the popper needs to have to be
        // properly positioned near its reference element
        // This is the most basic placement, and will be adjusted by
        // the modifiers in the next step
  
        this.state.offsets = {
          popper: computeOffsets({
            reference: this.state.measures.reference,
            popper: this.state.measures.popper,
            strategy: 'absolute',
            placement: this.state.options.placement,
            scroll: getCommonTotalScroll(referenceElement, this.state.scrollParents.reference, this.state.scrollParents.popper)
          })
        }; // Modifiers have the ability to read the current Popper.js state, included
        // the popper offsets, and modify it to address specifc cases
  
        this.state = this.state.orderedModifiers.reduce((state, {
          fn,
          enabled,
          options
        }) => {
          if (enabled && typeof fn === 'function') {
            state = fn(this.state, options);
          }
  
          return state;
        }, this.state);
      }
  
      enableEventListeners(eventListeners) {
        const {
          reference: referenceElement,
          popper: popperElement
        } = this.state.elements;
        const {
          scroll,
          resize
        } = expandEventListeners(eventListeners);
  
        if (scroll) {
          const scrollParents = [...this.state.scrollParents.reference, ...this.state.scrollParents.popper];
          scrollParents.forEach(scrollParent => scrollParent.addEventListener('scroll', this.update, {
            passive: true
          }));
        }
  
        if (resize) {
          const win = getWindow(this.state.elements.popper);
          win && win.addEventListener('resize', this.update, {
            passive: true
          });
        }
      }
  
    }
  
    return Popper;
  
  })));
  //# sourceMappingURL=index.js.map