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

const u16 sEnergyTankIncreaseAmount = 100;
const u16 sMissileTankIncreaseAmount = 5;
const u8 sSuperMissileTankIncreaseAmount = 2;
const u8 sPowerBombTankIncreaseAmount = 2;

const struct MajorLocation sMajorLocations[ITEM_SOURCE_COUNT] = {0};
const struct MinorLocation sMinorLocations[MINOR_LOCATION_COUNT] = {
    { // Brinstar 0x1 at 13, 7
        .key = 0x1070D,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0x2 at 28, 2
        .key = 0x2021C,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0xC at 54, 6
        .key = 0xC0636,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0xE at 14, 23
        .key = 0xE170E,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0xF at 4, 6
        .key = 0xF0604,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0x13 at 39, 6
        .key = 0x130627,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0x13 at 11, 10
        .key = 0x130A0B,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0x15 at 39, 5
        .key = 0x150527,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0x17 at 18, 16
        .key = 0x171012,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0x19 at 11, 5
        .key = 0x19050B,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0x1D at 4, 10
        .key = 0x1D0A04,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0x28 at 7, 4
        .key = 0x280407,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0x29 at 5, 18
        .key = 0x291205,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Brinstar 0x29 at 5, 25
        .key = 0x291905,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Kraid 0x1 at 24, 4
        .key = 0x1010418,
        .item = RIT_FULLY_POWERED,
        .jingle = RIJ_MINOR,
        .customMessage = NULL
    },
    { // Kraid 0x2 at 9, 33
        .key = 0x1022109,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Kraid 0x4 at 22, 6
        .key = 0x1040616,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Kraid 0x7 at 38, 14
        .key = 0x1070E26,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Kraid 0x8 at 74, 20
        .key = 0x108144A,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Kraid 0x9 at 60, 9
        .key = 0x109093C,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Kraid 0xA at 9, 9
        .key = 0x10A0909,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Kraid 0x11 at 2, 4
        .key = 0x1110402,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Kraid 0x15 at 20, 3
        .key = 0x1150314,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Kraid 0x1A at 7, 10
        .key = 0x11A0A07,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Kraid 0x26 at 5, 4
        .key = 0x1260405,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x1 at 65, 4
        .key = 0x2010441,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x3 at 72, 4
        .key = 0x2030448,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x4 at 74, 9
        .key = 0x204094A,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x5 at 14, 79
        .key = 0x2054F0E,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x5 at 8, 111
        .key = 0x2056F08,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0xA at 11, 4
        .key = 0x20A040B,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x11 at 17, 4
        .key = 0x2110411,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x1C at 28, 3
        .key = 0x21C031C,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x1C at 54, 4
        .key = 0x21C0436,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x20 at 45, 3
        .key = 0x220032D,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x20 at 4, 5
        .key = 0x2200504,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x25 at 21, 3
        .key = 0x2250315,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x26 at 5, 6
        .key = 0x2260605,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x2A at 33, 5
        .key = 0x22A0521,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x2E at 33, 5
        .key = 0x22E0521,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x2F at 24, 3
        .key = 0x22F0318,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x37 at 8, 14
        .key = 0x2370E08,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Norfair 0x37 at 30, 23
        .key = 0x237171E,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x4 at 6, 8
        .key = 0x3040806,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x6 at 8, 33
        .key = 0x3062108,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x9 at 9, 4
        .key = 0x3090409,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0xA at 27, 6
        .key = 0x30A061B,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0xA at 15, 15
        .key = 0x30A0F0F,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0xD at 8, 7
        .key = 0x30D0708,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0xE at 27, 9
        .key = 0x30E091B,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x10 at 54, 6
        .key = 0x3100636,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x11 at 28, 20
        .key = 0x311141C,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x12 at 72, 6
        .key = 0x3120648,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x13 at 7, 21
        .key = 0x3131507,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x16 at 11, 6
        .key = 0x316060B,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x16 at 8, 16
        .key = 0x3161008,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x17 at 8, 4
        .key = 0x3170408,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x17 at 13, 13
        .key = 0x3170D0D,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x1D at 24, 3
        .key = 0x31D0318,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x1D at 20, 15
        .key = 0x31D0F14,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x1E at 4, 13
        .key = 0x31E0D04,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Ridley 0x1F at 42, 7
        .key = 0x31F072A,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Tourian 0x7 at 14, 8
        .key = 0x407080E,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Tourian 0x8 at 11, 109
        .key = 0x4086D0B,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Crateria 0x5 at 20, 37
        .key = 0x5052514,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Crateria 0x7 at 3, 27
        .key = 0x5071B03,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Crateria 0x9 at 90, 9
        .key = 0x509095A,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Crateria 0x9 at 64, 34
        .key = 0x5092240,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Crateria 0xE at 8, 10
        .key = 0x50E0A08,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0xA at 19, 4
        .key = 0x60A0413,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0xE at 13, 5
        .key = 0x60E050D,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x18 at 10, 13
        .key = 0x6180D0A,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x1A at 44, 8
        .key = 0x61A082C,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x22 at 34, 14
        .key = 0x6220E22,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x2F at 9, 17
        .key = 0x62F1109,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x31 at 10, 7
        .key = 0x631070A,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x36 at 59, 20
        .key = 0x636143B,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x41 at 9, 3
        .key = 0x6410309,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x42 at 16, 13
        .key = 0x6420D10,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x47 at 59, 19
        .key = 0x647133B,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x49 at 9, 6
        .key = 0x6490609,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x4E at 44, 8
        .key = 0x64E082C,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x57 at 18, 18
        .key = 0x6571212,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x59 at 6, 27
        .key = 0x6591B06,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x5A at 56, 24
        .key = 0x65A1838,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x5A at 56, 40
        .key = 0x65A2838,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
    { // Chozodia 0x5F at 24, 6
        .key = 0x65F0618,
        .item = RIT_WAVE_BEAM,
        .jingle = RIJ_DEFAULT,
        .customMessage = NULL
    },
};

#endif // RANDOMIZER
