#include "randomizer.h"

#include "data/menus/pause_screen_sub_menus_data.h"
#include "data/randomizer_data.h"
#include "data/rooms_data.h"
#include "data/sprite_data.h"

#include "constants/randomizer.h"
#include "constants/sprite.h"

#ifdef RANDOMIZER

// Existing data
static const struct TilesetEntry* sTilesetEntries_Pointer = sTilesetEntries;
static const struct ChozoStatueTarget* sChozoStatueTargets_Pointer = sChozoStatueTargets;

// Rando data
static const struct MajorLocation* sMajorLocations_Pointer = sMajorLocations;
static const struct MinorLocation* sMinorLocations_Pointer = sMinorLocations;

// Rando options
static const u8* sRandoDifficultyOptions_Pointer = &sRandoDifficultyOptions;
static const u16* sRandoMetroidSpriteStats_Pointer = sPrimarySpriteStats[PSPRITE_METROID];
static const boolu8* sRandoBlackPiratesRequirePlasma_Pointer = &sRandoBlackPiratesRequirePlasma;
static const boolu8* sRandoSkipDoorTransitions_Pointer = &sRandoSkipDoorTransitions;
static const boolu8* sRandoBallLauncherWithoutBombs_Pointer = &sRandoBallLauncherWithoutBombs;
static const boolu8* sRandoDisableMidAirBombJump_Pointer = &sRandoDisableMidAirBombJump;
static const boolu8* sRandoDisableWallJump_Pointer = &sRandoDisableWallJump;
static const boolu8* sRandoRemoveCutscenes_Pointer = &sRandoRemoveCutscenes;
static const boolu8* sRandoSkipSuitlessSequence_Pointer = &sRandoSkipSuitlessSequence;

static const u8* sRandoTitleLine1_Pointer = sRandoTitleLine1;
static const u8* sRandoTitleLine2_Pointer = sRandoTitleLine2;

const struct MinorLocation* GetMinorLocation(Area area, u8 room, u8 blockX, u8 blockY)
{
    u32 sortValue;
    u32 left;
    u32 right;
    u32 mid;

    sortValue = (area << 24) | (room << 16) | (blockY << 8) | blockX;
    left = 0;
    right = MINOR_LOCATION_COUNT - 1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        
        if (sMinorLocations[mid].sortValue < sortValue)
            left = mid + 1;
        else if (sMinorLocations[mid].sortValue > sortValue)
            right = mid - 1;
        else
            return &sMinorLocations[mid];
    }

    return NULL;
}

#endif // RANDOMIZER
