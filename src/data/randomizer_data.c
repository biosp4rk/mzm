#include "data/randomizer_data.h"

#include "constants/randomizer.h"

#ifdef RANDOMIZER

// New data

// const u8 sRandoEnergyTankGfx[384] = INCBIN_U8("data_rando/animated_gfx/EnergyTank.gfx");
// const u8 sRandoMissileTankGfx[384] = INCBIN_U8("data_rando/animated_gfx/MissileTank.gfx");
// const u8 sRandoSuperMissileTankGfx[384] = INCBIN_U8("data_rando/animated_gfx/SuperMissileTank.gfx");
// const u8 sRandoPowerBombTankGfx[384] = INCBIN_U8("data_rando/animated_gfx/PowerBombTank.gfx");
const u8 sRandoLongBeamGfx[384] = INCBIN_U8("data_rando/animated_gfx/LongBeam.gfx");
const u8 sRandoChargeBeamGfx[384] = INCBIN_U8("data_rando/animated_gfx/ChargeBeam.gfx");
const u8 sRandoIceBeamGfx[384] = INCBIN_U8("data_rando/animated_gfx/IceBeam.gfx");
const u8 sRandoWaveBeamGfx[384] = INCBIN_U8("data_rando/animated_gfx/WaveBeam.gfx");
const u8 sRandoPlasmaBeamGfx[384] = INCBIN_U8("data_rando/animated_gfx/PlasmaBeam.gfx");
const u8 sRandoBombsGfx[384] = INCBIN_U8("data_rando/animated_gfx/Bombs.gfx");
const u8 sRandoVariaSuitGfx[384] = INCBIN_U8("data_rando/animated_gfx/VariaSuit.gfx");
const u8 sRandoGravitySuitGfx[384] = INCBIN_U8("data_rando/animated_gfx/GravitySuit.gfx");
const u8 sRandoMorphBallGfx[384] = INCBIN_U8("data_rando/animated_gfx/MorphBall.gfx");
const u8 sRandoSpeedBoosterGfx[384] = INCBIN_U8("data_rando/animated_gfx/SpeedBooster.gfx");
const u8 sRandoHiJumpGfx[384] = INCBIN_U8("data_rando/animated_gfx/HiJump.gfx");
const u8 sRandoScrewAttackGfx[384] = INCBIN_U8("data_rando/animated_gfx/ScrewAttack.gfx");
const u8 sRandoSpaceJumpGfx[384] = INCBIN_U8("data_rando/animated_gfx/SpaceJump.gfx");
const u8 sRandoPowerGripGfx[384] = INCBIN_U8("data_rando/animated_gfx/PowerGrip.gfx");
// const u8 sRandoFullyPoweredGfx[384] = INCBIN_U8("data_rando/animated_gfx/FullyPowered.gfx");
// const u8 sRandoZiplinesGfx[384] = INCBIN_U8("data_rando/animated_gfx/Ziplines.gfx");
// const u8 sRandoInfantMetroidGfx[384] = INCBIN_U8("data_rando/animated_gfx/InfantMetroid.gfx");
// const u8 sRandoAnonymousGfx[384] = INCBIN_U8("data_rando/animated_gfx/Anonymous.gfx");

// From patcher

const u8 sRandoDifficultyOptions = DIFF_OPT_UNCHANGED;
const boolu8 sRandoBlackPiratesRequirePlasma = TRUE;
const boolu8 sRandoSkipDoorTransitions = FALSE;
const boolu8 sRandoBallLauncherWithoutBombs = FALSE;
const boolu8 sRandoDisableMidAirBombJump = FALSE;
const boolu8 sRandoDisableWallJump = FALSE;
const boolu8 sRandoRemoveCutscenes = FALSE;
const boolu8 sRandoSkipSuitlessSequence = FALSE;

const u8 sRandoTitleLine1[31] = "RANDOMIZER LINE 1";
const u8 sRandoTitleLine2[31] = "RANDOMIZER LINE 2";

const struct MajorLocation sMajorLocations[ITEM_SOURCE_COUNT] = {0};
const struct MinorLocation sMinorLocations[MINOR_LOCATION_COUNT] = {0};

#endif // RANDOMIZER
