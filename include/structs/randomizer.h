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
}; // Size: 8

struct MinorLocation {
    // See MINOR_LOC_KEY macro
    /* 0 */ u32 key;
    /* 4 */ u16 bg1Value; // Needed for hidden items
    /* 6 */ RandoItemType item;
    /* 7 */ RandoItemJingle jingle;
    /* 8 */ const u16* customMessage;
    /* C */ u8 hintedBy;
}; // Size: 0x10

struct CurrentRandoItem {
    /* 0 */ boolu8 isMinor;
    /* 1 */ RandoItemType item;
    /* 2 */ RandoItemJingle jingle;
    /* 4 */ const u16* customMessage;
}; // Size: 8

struct StartingInfo {
    // Location
    /* 00 */ Area area;
    /* 01 */ u8 room;
    /* 02 */ u8 door;
    /* 03 */ u8 blockX;
    /* 04 */ u8 blockY;
    // Equipment
    /* 06 */ u16 maxEnergy;
    /* 08 */ u16 maxMissiles;
    /* 0A */ u8 maxSuperMissiles;
    /* 0B */ u8 maxPowerBombs;
    /* 0C */ BeamBombFlags beamBombs;
    /* 0D */ SuitMiscFlags suitMisc;
    /* 0E */ u8 downloadedMapStatus;
    /* 0F */ SuitType suitType;
    /* 10 */ boolu8 ziplinesActivated;
    // Disabled hints
    /* 11 */ u8 disabledHints;
};

extern struct CurrentRandoItem gCurrentRandoItem;

#endif // RANDOMIZER_STRUCT_H