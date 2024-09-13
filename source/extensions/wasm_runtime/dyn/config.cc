#include "envoy/registry/registry.h"

#include "source/extensions/common/wasm/wasm_runtime_factory.h"

#include "include/proxy-wasm/dyn.h"

namespace Envoy {
namespace Extensions {
namespace Common {
namespace Wasm {

class DynRuntimeFactory : public WasmRuntimeFactory {
public:
  WasmVmPtr createWasmVm() override { return proxy_wasm::createDynVm(); }

  std::string name() const override { return "envoy.wasm.runtime.dyn"; }
};

REGISTER_FACTORY(DynRuntimeFactory, WasmRuntimeFactory);

} // namespace Wasm
} // namespace Common
} // namespace Extensions
} // namespace Envoy
