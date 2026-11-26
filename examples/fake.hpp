#ifndef MHAA_EXTERNAL_EXAMPLE_FAKE_HPP
#define MHAA_EXTERNAL_EXAMPLE_FAKE_HPP

#include <external/line.hpp>
#include <external/pin_change_group.hpp>

namespace example
{
    using namespace mhaa::external;

    class FakeLine final : public Line
    {
    public:
        bool configure(Trigger trigger) override { return trigger == Trigger::RisingEdge; }
        void enable() override { enabled = true; }
        void disable() override { enabled = false; }
        bool pending() const override { return flagged; }
        void clear_pending() override { flagged = false; }

        bool enabled = false;
        bool flagged = true;
    };

    class FakeGroup final : public PinChangeGroup
    {
    public:
        bool set_mask(PinMask mask) override
        {
            if (mask & UINT32_C(0x7FFFFFFF))
            {
                return false;
            }
            selected = mask;
            return true;
        }
        void enable() override { enabled = true; }
        void disable() override { enabled = false; }
        bool pending() const override { return flagged; }
        void clear_pending() override { flagged = false; }

        PinMask selected = 0;
        bool flagged = false;
        bool enabled = false;
    };
}

#endif
