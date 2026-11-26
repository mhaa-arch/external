# Run the External Interrupt Core example

The example binds a simulated line to `ExternalInterrupt` and requests rising-edge delivery with the checked overload. It verifies that the fake is enabled. The behavior test goes on to exercise rejections, pending and clear, and a separate group selected by mask.

## Example program

The [program](../examples/example.cpp) uses the [local fake](../examples/fake.hpp) to demonstrate injection. A concrete Adapter implementing the same Contract can be supplied to the same facade.

```cpp
#include <external/external_interrupt.hpp>
#include <external/pin_change_interrupt.hpp>
#include "fake.hpp"

using namespace mhaa::external;
using namespace example;

int main()
{
    FakeLine line;
    ExternalInterrupt irq(line);
    return irq.enable(Trigger::RisingEdge) && line.enabled ? 0 : 1;
}
```

## Build and run

Build from this repository root. Set `contract_include` to the matching Contract's `include/` directory. The value below applies to the MHAA development workspace. Both programs exit with status 0 on success and print no output. On Windows execute `example.exe` and `behavior.exe`.

```sh
contract_include=../../contracts/external-contract/include
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -I"$contract_include" examples/example.cpp -o example
./example
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -I"$contract_include" tests/behavior.cpp -o behavior
./behavior
```

See the [behavior test](../tests/behavior.cpp) for the additional cases described above.
