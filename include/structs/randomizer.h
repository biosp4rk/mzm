#ifndef RANDOMIZER_STRUCT_H
#define RANDOMIZER_STRUCT_H

#include "types.h"

#include "constants/connection.h"
#include "constants/randomizer.h"

struct MajorLocation {
    /* 0 */ Area area; // Not needed?
    /* 1 */ u8 room; // Not needed?
    /* 2 */ RandoItemType item;
    /* 3 */ RandoItemJingle jingle;
    /* 4 */ u8* customMessage;
};

struct MinorLocation {
    // See MINOR_LOC_KEY macro
    /* 0 */ u32 key;
    /* 4 */ u16 bg1Value; // Needed for hidden items
    /* 6 */ RandoItemType item;
    /* 7 */ RandoItemJingle jingle;
    /* 8 */ u8* customMessage;
};

struct CurrentRandoItem {
    boolu8 isMinor;
    RandoItemType item;
    RandoItemJingle jingle;
    u8* customMessage;
};

extern struct CurrentRandoItem gCurrentRandoItem;

#endif // RANDOMIZER_STRUCT_H