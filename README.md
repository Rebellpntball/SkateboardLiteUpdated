# SkateboardLite Updated (Standalone)

Updated standalone version of the abandoned **Skateboards Lite** mod (original by Lugge / TMNT Labs, last Workshop update Sep 2022).

## Goals of this update
- **Standalone** – no RoadTrip / Raft dependency
- **Expansion compatible** – hologram placement no longer breaks when Expansion BaseBuilding is loaded
- **Less lag** – removed debug spam, throttled client raycasts and idle checks
- Same classnames & assets so existing items and types.xml keep working

## Features (unchanged gameplay)
- Ride skateboards
- Attack with the board
- Jump while on the board

## Controls
Place a packed skateboard on the ground, then stand on it:
- **Numpad 8** – forward / increase speed
- **Numpad 2** – reverse
- **Numpad 4 / 6** – turn left / right
- **Numpad 5** – straighten
- **Space** – jump

## Requirements
- DayZ 1.29+ (tested path for 1.29 stable; 1.30 exp should work)
- Community Framework (CF) – already in requiredAddons

## Load order recommendation
```
@CF;@DayZ-Expansion-*;@Skateboard
```
(or any Expansion modules you use, then this mod last among them)

## What was fixed
| Issue | Fix |
|-------|-----|
| Expansion hologram placement broken | Hologram override always calls `super` and only special-cases our packed kit |
| High lag / log spam | Removed `Print` spam, throttled idle player checks, throttled client link raycasts (~8 Hz) |
| RoadTrip soft dependency | Removed from config and PlayerBase |

## Notes
- Still requires a **live server** (original limitation of the linking system).
- Original author is inactive; this is a community maintenance update under the same assets/classnames.
- Repacking for private servers is fine; credit original (Lugge) + this update.

## Credits
- Original: Lugge / HunterCZ (Pizza Time / Skateboards Lite)
- Update: community maintenance for 1.29+ and Expansion compatibility
