#ifndef RANDOMIZER_STRUCT_H
#define RANDOMIZER_STRUCT_H

#include "types.h"

#include "constants/connection.h"
#include "constants/randomizer.h"

struct MajorLocation {
    /* 0 */ RandoItemType item;
    /* 1 */ RandoItemJingle jingle;
    /* 4 */ const u16* customMessage;
};

struct MinorLocation {
    // See MINOR_LOC_KEY macro
    /* 0 */ u32 key;
    /* 4 */ u16 bg1Value; // Needed for hidden items
    /* 6 */ RandoItemType item;
    /* 7 */ RandoItemJingle jingle;
    /* 8 */ const u16* customMessage;
};

struct CurrentRandoItem {
    boolu8 isMinor;
    RandoItemType item;
    RandoItemJingle jingle;
    const u16* customMessage;
};

extern struct CurrentRandoItem gCurrentRandoItem;

#endif // RANDOMIZER_STRUCT_H