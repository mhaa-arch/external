#ifndef MHAA_EXTERNAL_EXTERNAL_INTERRUPT_HPP
#define MHAA_EXTERNAL_EXTERNAL_INTERRUPT_HPP

#include <external/line.hpp>
#include <external/types.hpp>

namespace mhaa
{
    namespace external
    {
        /** @brief Configures delivery for one borrowed external interrupt line. */
        class ExternalInterrupt
        {
        public:
            explicit ExternalInterrupt(Line &line) : line_(line) {}

            bool configure(Trigger trigger) { return line_.configure(trigger); }
            void enable() { line_.enable(); }

            bool enable(Trigger trigger)
            {
                if (!configure(trigger))
                {
                    return false;
                }
                enable();
                return true;
            }

            void disable() { line_.disable(); }
            bool pending() const { return line_.pending(); }
            void clear_pending() { line_.clear_pending(); }

        private:
            Line &line_;
        };
    }
}

#endif
