#ifndef RANDOMIZER_STRUCT_H
#define RANDOMIZER_STRUCT_H

#include "types.h"

#include "constants/connection.h"
#include "constants/randomizer.h"

struct MajorLocation {
    Area area;
    u8 room;
    RandoItemType item;
    // Ziplines and fully powered don't have a sprite
    RandoItemSprite sprite;
    RandoItemJingle jingle;
    u8* message;
};

struct MinorLocation {
    // (area << 24) | (room << 16) | (blockY << 8) | blockX
    u32 sortValue;
    // Area area;
    // u8 room;
    // u8 blockX;
    // u8 blockY;
    u16 bg1Value;
    boolu8 hidden; // possibly not needed?
    RandoItemType item;
    RandoItemSprite sprite;
    RandoItemJingle jingle;
    u8* message;
};

#endif // RANDOMIZER_STRUCT_H