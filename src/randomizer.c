#include "data/menus/pause_screen_sub_menus_data.h"
#include "data/randomizer_data.h"
#include "data/rooms_data.h"
#include "data/sprite_data.h"

#include "constants/sprite.h"

#ifdef RANDOMIZER

// Data
static const struct TilesetEntry* sTilesetEntries_Pointer = sTilesetEntries;
static const struct ChozoStatueTarget* sChozoStatueTargets_Pointer = sChozoStatueTargets;

// Options
static const u8* sRandoDifficultyOptions_Pointer = &sRandoDifficultyOptions;
static const u16* sRandoMetroidSpriteStats_Pointer = sPrimarySpriteStats[PSPRITE_METROID];
static const boolu8* sRandoBlackPiratesRequirePlasma_Pointer = &sRandoBlackPiratesRequirePlasma;
static const boolu8* sRandoSkipDoorTransitions_Pointer = &sRandoSkipDoorTransitions;
static const boolu8* sRandoBallLauncherWithoutBombs_Pointer = &sRandoBallLauncherWithoutBombs;
static const boolu8* sRandoDisableMidAirBombJump_Pointer = &sRandoDisableMidAirBombJump;
static const boolu8* sRandoDisableWallJump_Pointer = &sRandoDisableWallJump;
static const boolu8* sRandoRemoveCutscenes_Pointer = &sRandoRemoveCutscenes;
static const boolu8* sRandoSkipSuitlessSequence_Pointer = &sRandoSkipSuitlessSequence;

#endif // RANDOMIZER
