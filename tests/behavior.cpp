#include <external/external_interrupt.hpp>
#include <external/pin_change_interrupt.hpp>
#include "../examples/fake.hpp"

#include <cassert>

using namespace mhaa::external;
using namespace example;

int main()
{
    FakeLine line;
    ExternalInterrupt irq(line);
    assert(!irq.enable(Trigger::FallingEdge) && !line.enabled);
    assert(irq.enable(Trigger::RisingEdge) && line.enabled && line.pending());
    irq.disable();
    assert(!line.enabled && line.pending());
    FakeGroup group;
    PinChangeInterrupt changes(group);
    assert(!changes.enable(1) && !group.enabled);
    assert(changes.enable(UINT32_C(0x80000000)) && group.enabled);
    assert(group.selected == UINT32_C(0x80000000));
    changes.disable();
    assert(!group.enabled);

    assert(irq.pending());
    irq.clear_pending();
    assert(!irq.pending());
    assert(irq.configure(Trigger::RisingEdge));
    irq.enable();
    assert(line.enabled);
    group.flagged = true;
    assert(changes.pending());
    changes.clear_pending();
    assert(!changes.pending());
    assert(changes.set_mask(0));
    changes.enable();
    assert(group.enabled && group.selected == 0);
}
