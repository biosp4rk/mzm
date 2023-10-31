#include "data/engine_pointers.h"
#include "macros.h"

#include "data/clipdata_data.h"
#include "data/animated_graphics_data.h"
#include "data/hatch_data.h"
#include "data/rooms_data.h"

#include "particle.h"
#include "projectile.h"
#include "color_fading.h"
#include "block.h"

#include "constants/animated_graphics.h"
#include "constants/haze.h"
#include "constants/connection.h"
#include "constants/room.h"
#include "constants/particle.h"
#include "constants/projectile.h"

const ProjFunc_T sProcessProjectileFunctionPointers[16] = {
    [PROJ_TYPE_BEAM] = ProjectileProcessNormalBeam,
    [PROJ_TYPE_LONG_BEAM] = ProjectileProcessLongBeam,
    [PROJ_TYPE_ICE_BEAM] = ProjectileProcessIceBeam,
    [PROJ_TYPE_WAVE_BEAM] = ProjectileProcessWaveBeam,
    [PROJ_TYPE_PLASMA_BEAM] = ProjectileProcessPlasmaBeam,
    [PROJ_TYPE_PISTOL] = ProjectileProcessPistol,
    [PROJ_TYPE_CHARGED_BEAM] = ProjectileProcessChargedNormalBeam,
    [PROJ_TYPE_CHARGED_LONG_BEAM] = ProjectileProcessChargedLongBeam,
    [PROJ_TYPE_CHARGED_ICE_BEAM] = ProjectileProcessChargedIceBeam,
    [PROJ_TYPE_CHARGED_WAVE_BEAM] = ProjectileProcessChargedWaveBeam,
    [PROJ_TYPE_CHARGED_PLASMA_BEAM] = ProjectileProcessChargedPlasmaBeam,
    [PROJ_TYPE_CHARGED_PISTOL] = ProjectileProcessChargedPistol,
    [PROJ_TYPE_MISSILE] = ProjectileProcessMissile,
    [PROJ_TYPE_SUPER_MISSILE] = ProjectileProcessSuperMissile,
    [PROJ_TYPE_BOMB] = ProjectileProcessBomb,
    [PROJ_TYPE_POWER_BOMB] = ProjectileProcessPowerBomb
};

const ParticleFunc_T sProcessParticleFunctionPointers[61] = {
    [PE_SPRITE_SPLASH_WATER_SMALL] = ParticleSpriteSplashWaterSmall,
    [PE_SPRITE_SPLASH_WATER_BIG] = ParticleSpriteSplashWaterBig,
    [PE_SPRITE_SPLASH_WATER_HUGE] = ParticleSpriteSplashWaterHuge,
    [PE_SPRITE_SPLASH_LAVA_SMALL] = ParticleSpriteSplashLavaSmall,
    [PE_SPRITE_SPLASH_LAVA_BIG] = ParticleSpriteSplashLavaBig,
    [PE_SPRITE_SPLASH_LAVA_HUGE] = ParticleSpriteSplashLavaHuge,
    [PE_SPRITE_SPLASH_ACID_SMALL] = ParticleSpriteSplashAcidSmall,
    [PE_SPRITE_SPLASH_ACID_BIG] = ParticleSpriteSplashAcidBig,
    [PE_SPRITE_SPLASH_ACID_HUGE] = ParticleSpriteSplashAcidHuge,
    [PE_SHOOTING_BEAM_LEFT] = ParticleShootingBeamLeft,
    [PE_SHOOTING_BEAM_DIAG_UP_LEFT] = ParticleShootingBeamDiagUpLeft,
    [PE_SHOOTING_BEAM_DIAG_DOWN_LEFT] = ParticleShootingBeamDiagDownLeft,
    [PE_SHOOTING_BEAM_UP_LEFT] = ParticleShootingBeamUpLeft,
    [PE_SHOOTING_BEAM_DOWN_LEFT] = ParticleShootingBeamDownLeft,
    [PE_SHOOTING_BEAM_RIGHT] = ParticleShootingBeamRight,
    [PE_SHOOTING_BEAM_DIAG_UP_RIGHT] = ParticleShootingBeamDiagUpRight,
    [PE_SHOOTING_BEAM_DIAG_DOWN_RIGHT] = ParticleShootingBeamDiagDownRight,
    [PE_SHOOTING_BEAM_UP_RIGHT] = ParticleShootingBeamUpRight,
    [PE_SHOOTING_BEAM_DOWN_RIGHT] = ParticleShootingBeamDownRight,
    [PE_BOMB] = ParticleBomb,
    [PE_MISSILE_TRAIL] = ParticleMissileTrail,
    [PE_SUPER_MISSILE_TRAIL] = ParticleSuperMissileTrail,
    [PE_BEAM_TRAILING_RIGHT] = ParticleBeamTrailingRight,
    [PE_BEAM_TRAILING_LEFT] = ParticleBeamTrailingLeft,
    [PE_CHARGED_LONG_BEAM_TRAIL] = ParticleChargedLongBeamTrail,
    [PE_CHARGED_ICE_BEAM_TRAIL] = ParticleChargedIceBeamTrail,
    [PE_CHARGED_WAVE_BEAM_TRAIL] = ParticleChargedWaveBeamTrail,
    [PE_CHARGED_PLASMA_BEAM_TRAIL] = ParticleChargedPlasmaBeamTrail,
    [PE_CHARGED_FULL_BEAM_TRAIL] = ParticleChargedFullBeamTrail,
    [PE_CHARGED_PISTOL_TRAIL] = ParticleChargedPistolTrail,
    [PE_SPRITE_EXPLOSION_HUGE] = ParticleSpriteExplosionHuge,
    [PE_SPRITE_EXPLOSION_SMALL] = ParticleSpriteExplosionSmall,
    [PE_SPRITE_EXPLOSION_MEDIUM] = ParticleSpriteExplosionMedium,
    [PE_SPRITE_EXPLOSION_BIG] = ParticleSpriteExplosionBig,
    [PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG] = ParticleSpriteExplosionSingleThenBig,
    [PE_SCREW_ATTACK_DESTROYED] = ParticleScrewAttackDestroyed,
    [PE_SHINESPARK_DESTROYED] = ParticleShinesparkDestroyed,
    [PE_SUDO_SCREW_DESTROYED] = ParticleSudoScrewDestroyed,
    [PE_SPEEDBOOSTER_DESTROYED] = ParticleSpeedboosterDestroyed,
    [PE_MAIN_BOSS_DEATH] = ParticleMainBossDeath,
    [PE_FREEZING_SPRITE_WITH_ICE] = ParticleFreezingSpriteWithIce,
    [PE_FREEZING_SPRITE_WITH_CHARGED_ICE] = ParticleFreezingSpriteWithChargedIce,
    [PE_HITTING_SOMETHING_WITH_NORMAL_BEAM] = ParticleHittingSomethingWithNormalBeam,
    [PE_HITTING_SOMETHING_WITH_LONG_BEAM] = ParticleHittingSomethingWithLongBeam,
    [PE_HITTING_SOMETHING_WITH_ICE_BEAM] = ParticleHittingSomethingWithIceBeam,
    [PE_HITTING_SOMETHING_WITH_WAVE_BEAM] = ParticleHittingSomethingWithWaveBeam,
    [PE_HITTING_SOMETHING_WITH_PLASMA_BEAM] = ParticleHittingSomethingWithPlasmaBeam,
    [PE_HITTING_SOMETHING_INVINCIBLE] = ParticleHittingSomethingInvincible,
    [PE_HITTING_SOMETHING_WITH_MISSILE] = ParticleHittingSomethingWithMissile,
    [PE_HITTING_SOMETHING_WITH_SUPER_MISSILE] = ParticleHittingSomethingWithSuperMissile,
    [PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA] = ParticleHittingSomethingWithFullBeamNoPlasma,
    [PE_HITTING_SOMETHING_WITH_FULL_BEAM] = ParticleHittingSomethingWithFullBeam,
    [PE_SMALL_DUST] = ParticleSmallDust,
    [PE_MEDIUM_DUST] = ParticleMediumDust,
    [PE_TWO_MEDIUM_DUST] = ParticleTwoMediumDust,
    [PE_SECOND_SMALL_DUST] = ParticleSecondSmallDust,
    [PE_SECOND_MEDIUM_DUST] = ParticleSecondMediumDust,
    [PE_SECOND_TWO_MEDIUM_DUST] = ParticleSecondTwoMediumDust,
    [PE_SAMUS_REFLECTION] = ParticleSamusReflection,
    [PE_CHARGING_BEAM] = ParticleChargingBeam,
    [PE_ESCAPE] = ParticleEscape,
};

const struct Door* const sAreaDoorsPointers[MAX_AMOUNT_OF_AREAS - 1] = {
    [AREA_BRINSTAR] = sBrinstarDoors,
    [AREA_KRAID] = sKraidDoors,
    [AREA_NORFAIR] = sNorfairDoors,
    [AREA_RIDLEY] = sRidleyDoors,
    [AREA_TOURIAN] = sTourianDoors,
    [AREA_CRATERIA] = sCrateriaDoors,
    [AREA_CHOZODIA] = sChozodiaDoors
};

const struct RoomEntryROM* const sAreaRoomEntryPointers[MAX_AMOUNT_OF_AREAS - 1] = {
    (const struct RoomEntryROM*)0x8340ad4,
    (const struct RoomEntryROM*)0x83414ac,
    (const struct RoomEntryROM*)0x8341e84,
    (const struct RoomEntryROM*)0x8342be0,
    (const struct RoomEntryROM*)0x834339c,
    (const struct RoomEntryROM*)0x834384c,
    (const struct RoomEntryROM*)0x8343d74,
};

static const u8* const sScrollPointer_Empty[] = {
    sScroll_Empty
};

static const u8* const sBrinstarScrolls[] = {
    (const u8* const)0x860c630,
    (const u8* const)0x860cd64,
    (const u8* const)0x860d46c,
    (const u8* const)0x860fcf4,
    (const u8* const)0x86100d8,
    (const u8* const)0x861093c,
    (const u8* const)0x8610d54,
    (const u8* const)0x8611bec,
    (const u8* const)0x8611f14,
    (const u8* const)0x8612478,
    (const u8* const)0x86137d4,
    (const u8* const)0x8613f44,
    (const u8* const)0x8614318,
    (const u8* const)0x8614a60,
    (const u8* const)0x8614e50,
    (const u8* const)0x86150d8,
    (const u8* const)0x861599c,
    (const u8* const)0x8615df0,
    (const u8* const)0x8616930,
    sScroll_Empty
};

static const u8* const sKraidScrolls[] = {
    (const u8* const)0x862fc0c,
    (const u8* const)0x8630a2c,
    (const u8* const)0x86318b8,
    (const u8* const)0x8631f80,
    (const u8* const)0x863248c,
    (const u8* const)0x8632e6c,
    (const u8* const)0x8635324,
    (const u8* const)0x8635704,
    (const u8* const)0x8636d9c,
    (const u8* const)0x8636f7c,
    (const u8* const)0x8637a20,
    sScroll_Empty
};

static const u8* const sNorfairScrolls[] = {
    (const u8* const)0x866bbf0,
    (const u8* const)0x866c8d8,
    (const u8* const)0x866dbb4,
    (const u8* const)0x866fe74,
    (const u8* const)0x8671070,
    (const u8* const)0x8671d84,
    (const u8* const)0x8672a08,
    (const u8* const)0x8673854,
    (const u8* const)0x8673e94,
    (const u8* const)0x8674714,
    (const u8* const)0x86766c8,
    (const u8* const)0x8676a9c,
    (const u8* const)0x8677318,
    (const u8* const)0x86778a8,
    (const u8* const)0x8679138,
    (const u8* const)0x867c4e0,
    (const u8* const)0x867cc54,
    sScroll_Empty
};

static const u8* const sRidleyScrolls[] = {
    (const u8* const)0x869b058,
    (const u8* const)0x869bf38,
    (const u8* const)0x869c4c8,
    (const u8* const)0x869d12c,
    (const u8* const)0x869d3c8,
    (const u8* const)0x869d840,
    (const u8* const)0x869dce4,
    (const u8* const)0x869e328,
    (const u8* const)0x869e6b8,
    (const u8* const)0x869edac,
    (const u8* const)0x869f8ac,
    (const u8* const)0x86a10a4,
    (const u8* const)0x86a18d8,
    (const u8* const)0x86a2290,
    sScroll_Empty
};

static const u8* const sTourianScrolls[] = {
    (const u8* const)0x86ba8d4,
    (const u8* const)0x86bb58c,
    (const u8* const)0x86bbb94,
    (const u8* const)0x86bc740,
    (const u8* const)0x86bd500,
    (const u8* const)0x86be788,
    sScroll_Empty
};

static const u8* const sCrateriaScrolls[] = {
    (const u8* const)0x86dc2d8,
    (const u8* const)0x86dd068,
    (const u8* const)0x86ddc74,
    (const u8* const)0x86ddf04,
    (const u8* const)0x86de19c,
    (const u8* const)0x86defa8,
    (const u8* const)0x86e0818,
    (const u8* const)0x86e2604,
    (const u8* const)0x86e2c80,
    (const u8* const)0x86e3260,
    (const u8* const)0x86e38e4,
    sScroll_Empty
};

static const u8* const sChozodiaScrolls[] = {
    (const u8* const)0x872de24,
    (const u8* const)0x872e390,
    (const u8* const)0x872ea8c,
    (const u8* const)0x872efe0,
    (const u8* const)0x872f470,
    (const u8* const)0x872f894,
    (const u8* const)0x872fd38,
    (const u8* const)0x8730050,
    (const u8* const)0x87301ac,
    (const u8* const)0x87306fc,
    (const u8* const)0x8731710,
    (const u8* const)0x87322c8,
    (const u8* const)0x87325ec,
    (const u8* const)0x8732bec,
    (const u8* const)0x8733d7c,
    (const u8* const)0x8734044,
    (const u8* const)0x8734934,
    (const u8* const)0x873540c,
    (const u8* const)0x87359a0,
    (const u8* const)0x87360a4,
    (const u8* const)0x8736804,
    (const u8* const)0x8736d50,
    (const u8* const)0x8737314,
    (const u8* const)0x8737910,
    (const u8* const)0x8737aec,
    (const u8* const)0x8739594,
    (const u8* const)0x873a1c4,
    (const u8* const)0x873abc4,
    (const u8* const)0x873b248,
    (const u8* const)0x873b980,
    (const u8* const)0x873bb84,
    (const u8* const)0x873c4d0,
    (const u8* const)0x873c7ac,
    (const u8* const)0x873d5a4,
    (const u8* const)0x873d964,
    (const u8* const)0x873de48,
    (const u8* const)0x873e770,
    (const u8* const)0x873eb18,
    (const u8* const)0x874170c,
    (const u8* const)0x8741a80,
    (const u8* const)0x8741ea4,
    (const u8* const)0x8743044,
    (const u8* const)0x87436c8,
    (const u8* const)0x8743ca8,
    (const u8* const)0x87445a4,
    (const u8* const)0x8744d64,
    (const u8* const)0x874531c,
    (const u8* const)0x87455d4,
    (const u8* const)0x87458c4,
    (const u8* const)0x8745d00,
    (const u8* const)0x87467f4,
    (const u8* const)0x8746b3c,
    (const u8* const)0x8747430,
    (const u8* const)0x874827c,
    (const u8* const)0x8748580,
    (const u8* const)0x8748fec,
    (const u8* const)0x87492c0,
    (const u8* const)0x874a8bc,
    (const u8* const)0x874b6a4,
    (const u8* const)0x874b7ec,
    sScroll_Empty
};

const u8* const * const sAreaScrollPointers[AREA_END] = {
    [AREA_BRINSTAR] = sBrinstarScrolls,
    [AREA_KRAID] = sKraidScrolls,
    [AREA_NORFAIR] = sNorfairScrolls,
    [AREA_RIDLEY] = sRidleyScrolls,
    [AREA_TOURIAN] = sTourianScrolls,
    [AREA_CRATERIA] = sCrateriaScrolls,
    [AREA_CHOZODIA] = sChozodiaScrolls,
    [AREA_DEBUG_1] = sScrollPointer_Empty,
    [AREA_DEBUG_2] = sScrollPointer_Empty,
    [AREA_DEBUG_3] = sScrollPointer_Empty,
    [AREA_DEBUG_4] = sScrollPointer_Empty
};

const s8 sWaterLoopCounterArray[8][2] = {
    [0] = {
        0, 9
    },
    [1] = {
        1, 9
    },
    [2] = {
        2, 21
    },
    [3] = {
        1, 9
    },
    [4] = {
        0, 9
    },
    [5] = {
        -1, 12
    },
    [6] = {
        -2, 99
    },
    [7] = {
        -1, 12
    }
};

const BlockFunc_T sNonReformDestroyFunctionPointers[5] = {
    BlockDestroySingleBreakableBlock,
    BlockDestroySquareBlock,
    BlockDestroySingleBreakableBlock,
    BlockDestroySquareBlock,
    BlockDestroyBombChainBlock
};

const ColorFadingFunc_T sColorFadingSubroutinePointers[4] = {
    ColorFadingSubroutine_Empty,
    unk_5bd58,
    unk_5bdc8,
    unk_5be7c
};

/**
 * @brief Haze data for each room effect
 * 0 : Haze value
 * 1 : Damage effect
 * 2 : BG0 water moving flag
 * 3 : Power bomb related
 */
FORCE_RODATA
u8 sHazeData[13][4] = {
    [EFFECT_NONE] = {
        HAZE_VALUE_NONE, EFFECT_NONE, FALSE, 0
    },
    [EFFECT_WATER] = {
        HAZE_VALUE_BG3, EFFECT_WATER, TRUE, 1
    },
    [EFFECT_STRONG_LAVA] = {
        HAZE_VALUE_BG3, EFFECT_STRONG_LAVA, FALSE, 1
    },
    [EFFECT_WEAK_LAVA] = {
        HAZE_VALUE_BG3, EFFECT_WEAK_LAVA, FALSE, 1
    },
    [EFFECT_STRONG_LAVA_HEAT_HAZE] = {
        HAZE_VALUE_BG3_STRONG_WEAK, EFFECT_STRONG_LAVA_HEAT_HAZE, FALSE, 1
    },
    [EFFECT_ACID] = {
        HAZE_VALUE_BG3, EFFECT_ACID, FALSE, 1
    },
    [EFFECT_SNOWFLAKES_COLD_KNOCKBACK] = {
        HAZE_VALUE_COLD, EFFECT_SNOWFLAKES_COLD_KNOCKBACK, FALSE, 1
    },
    [EFFECT_SNOWFLAKES_COLD] = {
        HAZE_VALUE_COLD, EFFECT_SNOWFLAKES_COLD, FALSE, 1
    },
    [EFFECT_HEAT_BG3_HAZE] = {
        HAZE_VALUE_BG3_NONE_WEAK, EFFECT_NONE, FALSE, 0
    },
    [EFFECT_HEAT_BG2_BG3_HAZE] = {
        HAZE_VALUE_BG3_BG2_STRONG_WEAK_MEDIUM, EFFECT_NONE, FALSE, 0
    },
    [EFFECT_BG3_GRADIENT] = {
        HAZE_VALUE_GRADIENT, EFFECT_NONE, FALSE, 2
    },
    [EFFECT_BG2_GRADIENT] = {
        HAZE_VALUE_GRADIENT, EFFECT_NONE, FALSE, 2
    },
    [EFFECT_HAZE_BG1_BG2_BG3] = {
        HAZE_VALUE_BG3_BG2_BG1, EFFECT_NONE, FALSE, 0
    }
};

// FIXME use pointer to u16[3]
const u16* const sBackgroundEffectBehaviorPointers[9] = {
    [0] = (const u16* const)sBackgroundEffectBehavior_Lightning,
    [BACKGROUND_EFFECT_LIGHTNING] = (const u16* const)sBackgroundEffectBehavior_Lightning,
    [BACKGROUND_EFFECT_SLIGHT_YELLOW] = (const u16* const)sBackgroundEffectBehavior_SlightYellow,
    [BACKGROUND_EFFECT_HEAVY_YELLOW] = (const u16* const)sBackgroundEffectBehavior_HeavyYellow,
    [BACKGROUND_EFFECT_EXIT_ZEBES_FADE] = (const u16* const)sBackgroundEffectBehavior_ExitZebes,
    [BACKGROUND_EFFECT_INTRO_TEXT_FADE] = (const u16* const)sBackgroundEffectBehavior_IntroText,
    [BACKGROUND_EFFECT_QUICK_FLASH] = (const u16* const)sBackgroundEffectBehavior_QuickFlash,
    [BACKGROUND_EFFECT_ALL_BLACK] = (const u16* const)sBackgroundEffectBehavior_AllBlackWhite,
    [BACKGROUND_EFFECT_ALL_WHITE] = (const u16* const)sBackgroundEffectBehavior_AllBlackWhite,
};

const struct HatchLockEvent* const sHatchLockEventsPointers[MAX_AMOUNT_OF_AREAS - 1] = {
    [AREA_BRINSTAR] = sHatchLockEventsBrinstar,
    [AREA_KRAID] = sHatchLockEventsKraid,
    [AREA_NORFAIR] = sHatchLockEventsNorfair,
    [AREA_RIDLEY] = sHatchLockEventsNorfair,
    [AREA_TOURIAN] = sHatchLockEventsNorfair,
    [AREA_CRATERIA] = sHatchLockEventsNorfair,
    [AREA_CHOZODIA] = sHatchLockEventsChozodia
};

const struct SaveDemo* const sDemoRamDataPointers[MAX_AMOUNT_OF_DEMOS] = {
    [0] = &sDemo0_Ram,
    [1] = &sDemo1_Ram,
    [2] = &sDemo2_Ram,
    [3] = &sDemo3_Ram,
    [4] = &sDemo4_Ram,
    [5] = &sDemo5_Ram,
    [6] = &sDemo6_Ram,
    [7] = &sDemo7_Ram,
    [8] = &sDemo8_Ram,
    [9] = &sDemo9_Ram,
    [10] = &sDemo10_Ram,
    [11] = &sDemo11_Ram,
    [12] = &sDemo12_Ram,
    [13] = &sDemo13_Ram,
    [14] = &sDemo14_Ram,
    [15] = &sDemo15_Ram,
};

const TourianEscapeFunc_T sTourianEscapeFunctionPointers[2] = {
    (TourianEscapeFunc_T)0x8060e29,
    (TourianEscapeFunc_T)0x8084715,
};

const s8 sCutsceneScreenShakeOffsets_Set0[2] = {
    -1, 1
};

const s8* const sCutsceneScreenShakeOffsetSetPointers[4] = {
    sCutsceneScreenShakeOffsets_Set0,
    sCutsceneScreenShakeOffsets_Set0,
    sCutsceneScreenShakeOffsets_Set0,
    sCutsceneScreenShakeOffsets_Set0
};

const u8 sCutsceneScreenShakeOffsetSetSizes[4] = {
    ARRAY_SIZE(sCutsceneScreenShakeOffsets_Set0),
    ARRAY_SIZE(sCutsceneScreenShakeOffsets_Set0),
    ARRAY_SIZE(sCutsceneScreenShakeOffsets_Set0),
    ARRAY_SIZE(sCutsceneScreenShakeOffsets_Set0)
};
