#ifndef RANDOMIZER_DATA_H
#define RANDOMIZER_DATA_H

#include "types.h"

#include "constants/menus/pause_screen.h"

#include "structs/randomizer.h"

// New data

// extern const u8 sRandoEnergyTankGfx[384];
// extern const u8 sRandoMissileTankGfx[384];
// extern const u8 sRandoSuperMissileTankGfx[384];
// extern const u8 sRandoPowerBombTankGfx[384];
extern const u8 sRandoLongBeamGfx[384];
extern const u8 sRandoChargeBeamGfx[384];
extern const u8 sRandoIceBeamGfx[384];
extern const u8 sRandoWaveBeamGfx[384];
extern const u8 sRandoPlasmaBeamGfx[384];
extern const u8 sRandoBombsGfx[384];
extern const u8 sRandoVariaSuitGfx[384];
extern const u8 sRandoGravitySuitGfx[384];
extern const u8 sRandoMorphBallGfx[384];
extern const u8 sRandoSpeedBoosterGfx[384];
extern const u8 sRandoHiJumpGfx[384];
extern const u8 sRandoScrewAttackGfx[384];
extern const u8 sRandoSpaceJumpGfx[384];
extern const u8 sRandoPowerGripGfx[384];
// extern const u8 sRandoFullyPoweredGfx[384];
// extern const u8 sRandoZiplinesGfx[384];
// extern const u8 sRandoInfantMetroidGfx[384];
// extern const u8 sRandoAnonymousGfx[384];

// From patcher

extern const u8 sRandoDifficultyOptions;
extern const boolu8 sRandoBlackPiratesRequirePlasma;
extern const boolu8 sRandoSkipDoorTransitions;
extern const boolu8 sRandoBallLauncherWithoutBombs;
extern const boolu8 sRandoDisableMidAirBombJump;
extern const boolu8 sRandoDisableWallJump;
extern const boolu8 sRandoRemoveCutscenes;
extern const boolu8 sRandoSkipSuitlessSequence;

extern const u8 sRandoTitleLine1[31];
extern const u8 sRandoTitleLine2[31];

extern const u16 sEnergyTankIncreaseAmount;
extern const u16 sMissileTankIncreaseAmount;
extern const u8 sSuperMissileTankIncreaseAmount;
extern const u8 sPowerBombTankIncreaseAmount;

extern const struct StartingInfo sStartingInfo;

extern const struct MajorLocation sMajorLocations[ITEM_SOURCE_COUNT];
extern const struct MinorLocation sMinorLocations[MINOR_LOCATION_COUNT];

#endif // RANDOMIZER_DATA_H
