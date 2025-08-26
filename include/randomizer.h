#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include "types.h"

#include "constants/connection.h"

#define MINOR_LOC_KEY(area, room, blockX, blockY) ((area << 24) | (room << 16) | (blockY << 8) | blockX)

const struct MinorLocation* RandoGetMinorLocation(Area area, u8 room, u8 blockX, u8 blockY);
void RandoCollectMinorLocationItem(const struct MinorLocation* loc);

#endif /* RANDOMIZER_H */
