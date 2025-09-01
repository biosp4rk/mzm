#include "data/in_game_cutscene_data.h"
#include "data/menus/pause_screen_sub_menus_data.h"
#include "data/randomizer_data.h"
#include "data/rooms_data.h"
#include "data/sprite_data.h"

#ifdef RANDOMIZER

// Existing data

static const struct TilesetEntry* sTilesetEntries_Pointer = sTilesetEntries;
static const struct ChozoStatueTarget* sChozoStatueTargets_Pointer = sChozoStatueTargets;

// Rando data

// Need to write starting area to cutscene data entry
static const struct InGameCutsceneData* sIntroCutsceneData_Pointer = &sInGameCutsceneData[IGC_CLOSE_UP];

static const struct StartingInfo* sStartingInfo_Pointer = &sStartingInfo;

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

static const u16* sEnergyTankIncreaseAmount_Pointer = &sEnergyTankIncreaseAmount;
static const u16* sMissileTankIncreaseAmount_Pointer = &sMissileTankIncreaseAmount;
static const u8* sSuperMissileTankIncreaseAmount_Pointer = &sSuperMissileTankIncreaseAmount;
static const u8* sPowerBombTankIncreaseAmount_Pointer = &sPowerBombTankIncreaseAmount;

static const u8* sRandoTitleLine1_Pointer = sRandoTitleLine1;
static const u8* sRandoTitleLine2_Pointer = sRandoTitleLine2;

#endif
