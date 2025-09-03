#ifndef RANDOMIZER_STRUCT_H
#define RANDOMIZER_STRUCT_H

#include "types.h"

#include "constants/connection.h"
#include "constants/randomizer.h"
#include "constants/samus.h"

struct MajorLocation {
    /* 0 */ RandoItemType item;
    /* 1 */ RandoItemJingle jingle;
    /* 2 */ u8 hintedBy;
    /* 4 */ const u16* customMessage;
};

struct MinorLocation {
    // See MINOR_LOC_KEY macro
    /* 0 */ u32 key;
    /* 4 */ u16 bg1Value; // Needed for hidden items
    /* 6 */ RandoItemType item;
    /* 7 */ RandoItemJingle jingle;
    /* 8 */ const u16* customMessage;
    /* C */ u8 hintedBy;
};

struct CurrentRandoItem {
    boolu8 isMinor;
    RandoItemType item;
    RandoItemJingle jingle;
    const u16* customMessage;
};

struct StartingInfo {
    // Location
    Area area;
    u8 room;
    u8 door;
    u8 blockX;
    u8 blockY;
    // Equipment
    u16 maxEnergy;
    u16 maxMissiles;
    u8 maxSuperMissiles;
    u8 maxPowerBombs;
    BeamBombFlags beamBombs;
    SuitMiscFlags suitMisc;
    u8 downloadedMapStatus;
    SuitType suitType;
    // Disabled hints
    u8 disabledHints;
};

extern struct CurrentRandoItem gCurrentRandoItem;

#endif // RANDOMIZER_STRUCT_H