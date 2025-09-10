#include "data/in_game_cutscene_data.h"
#include "data/menus/pause_screen_sub_menus_data.h"
#include "data/randomizer_data.h"
#include "data/rooms_data.h"
#include "data/sprite_data.h"

#ifdef RANDOMIZER

extern const struct RoomEntryRom* sAreaRoomEntryPointers[AREA_ENTRY_COUNT];

// The pointers in this file are written to 0x7D0000 (see linker.ld)

// --------------------------------
// Existing data
// --------------------------------

/* ?? */ static const struct RoomEntryRom* sAreaRoomEntryPointers_Pointer = sAreaRoomEntryPointers;
/* 00 */ static const struct TilesetEntry* sTilesetEntries_Pointer = sTilesetEntries;
/* 04 */ static const struct ChozoStatueTarget* sChozoStatueTargets_Pointer = sChozoStatueTargets;

/* 08 */ static const u32* sRandoTilesetTilemapSizes_Pointer = sRandoTilesetTilemapSizes;

// --------------------------------
// Rando data
// --------------------------------

// Need to write starting area to cutscene data entry
/* 0C */ static const struct InGameCutsceneData* sIntroCutsceneData_Pointer = &sInGameCutsceneData[IGC_CLOSE_UP];

/* 10 */ static const struct StartingInfo* sStartingInfo_Pointer = &sStartingInfo;

/* 14 */ static const struct MajorLocation* sMajorLocations_Pointer = sMajorLocations;
/* 18 */ static const struct MinorLocation* sMinorLocations_Pointer = sMinorLocations;

// --------------------------------
// Rando options
// --------------------------------

/* 1C */ static const u8* sRandoDifficultyOptions_Pointer = &sRandoDifficultyOptions;
/* 20 */ static const u16* sRandoMetroidSpriteStats_Pointer = sPrimarySpriteStats[PSPRITE_METROID];
/* 24 */ static const boolu8* sRandoBlackPiratesRequirePlasma_Pointer = &sRandoBlackPiratesRequirePlasma;
/* 28 */ static const boolu8* sRandoSkipDoorTransitions_Pointer = &sRandoSkipDoorTransitions;
/* 2C */ static const boolu8* sRandoBallLauncherWithoutBombs_Pointer = &sRandoBallLauncherWithoutBombs;
/* 30 */ static const boolu8* sRandoDisableMidAirBombJump_Pointer = &sRandoDisableMidAirBombJump;
/* 34 */ static const boolu8* sRandoDisableWallJump_Pointer = &sRandoDisableWallJump;
/* 38 */ static const boolu8* sRandoRemoveCutscenes_Pointer = &sRandoRemoveCutscenes;
/* 3C */ static const boolu8* sRandoSkipSuitlessSequence_Pointer = &sRandoSkipSuitlessSequence;

/* 40 */ static const u16* sEnergyTankIncreaseAmount_Pointer = &sEnergyTankIncreaseAmount;
/* 44 */ static const u16* sMissileTankIncreaseAmount_Pointer = &sMissileTankIncreaseAmount;
/* 48 */ static const u8* sSuperMissileTankIncreaseAmount_Pointer = &sSuperMissileTankIncreaseAmount;
/* 4C */ static const u8* sPowerBombTankIncreaseAmount_Pointer = &sPowerBombTankIncreaseAmount;

/* 50 */ static const u8* sRandoTitleLine1_Pointer = sRandoTitleLine1;
/* 54 */ static const u8* sRandoTitleLine2_Pointer = sRandoTitleLine2;

#endif
