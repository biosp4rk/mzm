#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include "types.h"

#include "constants/connection.h"

#include "structs/randomizer.h"

#define MINOR_LOC_KEY(area, room, blockX, blockY) ((area << 24) | (room << 16) | (blockY << 8) | blockX)

#define IN_RUINS_TEST_ROOM (gCurrentArea == AREA_CHOZODIA && gCurrentRoom == 0x2A)

const struct MinorLocation* RandoGetMinorLocation(Area area, u8 room, u8 blockX, u8 blockY);
void RandoCollectMajorLocationItem(ItemSource source);
void RandoCollectMinorLocationItem(const struct MinorLocation* loc);
void RandoSetHintEvents(u8 hint);
boolu8 RandoIsItemMessage(u8 message);
const u16* RandoGetMessageText(u8 message);

#endif /* RANDOMIZER_H */
