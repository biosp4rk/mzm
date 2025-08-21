#ifndef POWER_BOMB_EXPLOSION_STRUCT_H
#define POWER_BOMB_EXPLOSION_STRUCT_H

#include "types.h"

// Structs

struct PowerBomb {
    u8 animationState;
    u8 stage;
    u8 semiMinorAxis;
    u8 unk_3; // set to 0, never used
    u16 xPosition;
    u16 yPosition;
    s16 hitboxLeft;
    s16 hitboxRight;
    s16 hitboxTop;
    s16 hitboxBottom;
    u8 powerBombPlaced;
    u8 owner;
    u8 unk_12; // set to 0 and checked, never changes
};

extern struct PowerBomb gCurrentPowerBomb;

#endif