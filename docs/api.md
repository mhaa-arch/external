# Use the External Interrupt Core

Public entry headers are [external/external_interrupt.hpp](../include/external/external_interrupt.hpp), [external/pin_change_interrupt.hpp](../include/external/pin_change_interrupt.hpp).

## Use the matching facade

Bind `ExternalInterrupt` to a live `Line&`. Use `enable(trigger)` for a checked setup, or configure separately and then call `enable()`. Bind `PinChangeInterrupt` to a `PinChangeGroup&` and use `enable(mask)` or `set_mask(mask)` followed by `enable()`. Both checked overloads skip the enable call on rejection.

Read and clear a pending flag explicitly. Delivery can stay enabled across an acknowledgement. If an input remains asserted or transitions again, the flag can reappear. Consult the target's interrupt routing before associating the line or group with an application handler.

## Composition and lifetime

Application code calls the External Interrupt Core. It borrows the matching Contract, which an Adapter implements using its Hardware Definitions. Future Devices will create or bind these objects and establish their lifetime. To use the examples today, construct the facade directly with the supplied fake. Keep each borrowed resource alive for its use by the facade and follow the Adapter's access and synchronization requirements.
