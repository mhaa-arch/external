# Using External Interrupt across targets

The only project dependency is the matching `external-contract`. Keep its API revision aligned with this Core.

The facade sequences configuration and enabling the same way for any compatible line or group. A source mapped to a dedicated line on one target may need a pin-change group on another. Preserve that distinction in your composition and check routing, triggers and pending behavior before migrating handler code.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
