#include "data/randomizer_data.h"
#include "data/sprite_data.h"

#include "constants/sprite.h"

#ifdef RANDOMIZER

static const u8* sRandoDifficultyOptions_Pointer = &sRandoDifficultyOptions;

static const u16* sRandoMetroidSpriteStats_Pointer = sPrimarySpriteStats[PSPRITE_METROID];

static const boolu8* sRandoBlackPiratesRequirePlasma_Pointer = &sRandoBlackPiratesRequirePlasma;

static const boolu8* sRandoSkipDoorTransitions_Pointer = &sRandoSkipDoorTransitions;

static const boolu8* sRandoBallLauncherWithoutBombs_Pointer = &sRandoBallLauncherWithoutBombs;

#endif // RANDOMIZER
