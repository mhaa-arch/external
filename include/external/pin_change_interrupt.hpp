#ifndef MHAA_EXTERNAL_PIN_CHANGE_INTERRUPT_HPP
#define MHAA_EXTERNAL_PIN_CHANGE_INTERRUPT_HPP

#include <external/pin_change_group.hpp>
#include <external/types.hpp>

namespace mhaa
{
    namespace external
    {
        /** @brief Configures delivery for one borrowed pin-change group. */
        class PinChangeInterrupt
        {
        public:
            explicit PinChangeInterrupt(PinChangeGroup &group) : group_(group) {}

            bool set_mask(PinMask mask) { return group_.set_mask(mask); }
            void enable() { group_.enable(); }

            bool enable(PinMask mask)
            {
                if (!set_mask(mask))
                {
                    return false;
                }
                enable();
                return true;
            }

            void disable() { group_.disable(); }
            bool pending() const { return group_.pending(); }
            void clear_pending() { group_.clear_pending(); }

        private:
            PinChangeGroup &group_;
        };
    }
}

#endif
