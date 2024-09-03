#ifndef CHAOS_STRUCT_H
#define CHAOS_STRUCT_H

#include "types.h"

#define MAX_NUM_CHAOS_EFFECTS 5

struct ChaosEffectData {
    u8 exists;
    u8 id;
    u16 timer;
    u16 data;
};

struct HudPositions {
    u8 energyX;
    u8 energyY;
    u8 chargeBarX;
    u8 chargeBarY;
    u8 missileX;
    u8 missileY;
    u8 superMissileX;
    u8 superMissileY;
    u8 powerBombX;
    u8 powerBombY;
    u8 minimapX;
    u8 minimapY;
};

extern u32 gChaosRng;
extern u32 gActiveChaosEffects;
extern u8 gPrevOneTimeChaosEffect;
extern struct HudPositions gHudPositions;
extern const u16* gChaosTextPointer;
extern struct ChaosEffectData gChaosEffects[MAX_NUM_CHAOS_EFFECTS];

#endif /* CHAOS_STRUCT_H */
