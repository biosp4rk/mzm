#ifndef HATCH_DATA_H
#define HATCH_DATA_H

#include "types.h"

#include "constants/connection.h"

#include "structs/connection.h"

extern const HatchType sHatchTypeTable[HATCH_COUNT];

extern const struct HatchLockEvent sHatchLockEventsBrinstar[1];

#ifdef RANDOMIZER
extern const struct HatchLockEvent sHatchLockEventsKraid[0];
#else // !RANDOMIZER
extern const struct HatchLockEvent sHatchLockEventsKraid[1];
#endif // RANDOMIZER

#ifdef RANDOMIZER
extern const struct HatchLockEvent sHatchLockEventsCrateria[1];
#else // !RANDOMIZER
extern const struct HatchLockEvent sHatchLockEventsCrateria[2];
#endif // RANDOMIZER

extern const struct HatchLockEvent sHatchLockEventsChozodia[15];

extern const u8 sEventBasedConnections[41][EVENT_BASED_CONNECTION_FIELD_COUNT];

extern const u8 sAreaConnections[][AREA_CONNECTION_FIELD_COUNT];

extern const u8 sHatchesAnimationDurationCounter[6];

extern const u16 sHatchesTilemapValues[HATCH_COUNT];

extern const u16 sNumberOfHatchLockEventsPerArea[MAX_AMOUNT_OF_AREAS];

#endif /* HATCH_DATA_H */
