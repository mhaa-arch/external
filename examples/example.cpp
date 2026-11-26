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
