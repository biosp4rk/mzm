#include "data/frame_data_pointers.h"

const struct FrameData* const sChozoStatueFrameDataPointers[CHOZO_STATUE_OAM_END] = {
    [CHOZO_STATUE_OAM_LEG_STANDING] = sChozoStatuePartOam_LegStanding,
    [CHOZO_STATUE_OAM_LEG_SITTING] = sChozoStatuePartOam_LegSitting,
    [CHOZO_STATUE_OAM_LEG_SEATED] = sChozoStatuePartOam_LegSeated,
    [CHOZO_STATUE_OAM_IDLE] = sChozoStatueOam_Idle,
    [CHOZO_STATUE_OAM_EYE_OPENED] = sChozoStatuePartOam_EyeOpened,
    [CHOZO_STATUE_OAM_EYE_CLOSING] = sChozoStatuePartOam_EyeClosing,
    [CHOZO_STATUE_OAM_EYE_OPENING] = sChozoStatuePartOam_EyeOpening,
    [CHOZO_STATUE_OAM_EYE_CLOSED] = sChozoStatuePartOam_EyeClosed,
    [CHOZO_STATUE_OAM_ARM_IDLE] = sChozoStatuePartOam_ArmIdle,
    [CHOZO_STATUE_OAM_ARM_GLOW] = sChozoStatuePartOam_ArmGlow,
    [CHOZO_STATUE_OAM_ARM_SAMUS_GRABBED] = sChozoStatuePartOam_ArmSamusGrabbed,
    [CHOZO_STATUE_OAM_BALL_NORMAL_CLOSED] = sChozoBallOam_NormalClosed,
    [CHOZO_STATUE_OAM_BALL_NORMAL_REVEALING] = sChozoBallOam_NormalRevealing,
    [CHOZO_STATUE_OAM_BALL_NORMAL_REVEALED] = sChozoBallOam_NormalRevealed,
    [CHOZO_STATUE_OAM_REFILL] = sChozoStatueRefillOam,
    [CHOZO_STATUE_OAM_REFILL_GLOW_IDLE] = sChozoStatuePartOam_GlowIdle,
};

const struct FrameData* const sUnknownItemChozoStatueFrameDataPointers[UNKNOWN_ITEM_CHOZO_STATUE_OAM_END] = {
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_LEG_STANDING] = sUnknownItemChozoStatuePartOam_LegStanding,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_LEG_SITTING] = sUnknownItemChozoStatuePartOam_LegSitting,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_LEG_SEATED] = sUnknownItemChozoStatuePartOam_LegSeated,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_IDLE] = sUnknownItemChozoStatueOam_Idle,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_OPENED] = sUnknownItemChozoStatuePartOam_EyeOpened,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_CLOSING] = sUnknownItemChozoStatuePartOam_EyeClosing,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_OPENING] = sUnknownItemChozoStatuePartOam_EyeOpening,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_CLOSED] = sUnknownItemChozoStatuePartOam_EyeClosed,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_ARM_IDLE] = sUnknownItemChozoStatuePartOam_ArmIdle,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_ARM_GLOW] = sUnknownItemChozoStatuePartOam_ArmGlow,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_ARM_SAMUS_GRABBED] = sUnknownItemChozoStatuePartOam_ArmSamusGrabbed,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_BALL_NORMAL_CLOSED] = sChozoBallOam_UnknownClosed,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_BALL_NORMAL_REVEALING] = sChozoBallOam_UnknownRevealing,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_BALL_NORMAL_REVEALED] = sChozoBallOam_UnknownRevealed,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_REFILL] = sUnknownItemChozoStatueRefillOam,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_REFILL_GLOW_IDLE] = sUnknownItemChozoStatuePartOam_GlowIdle
};

const struct FrameData* const sKraidFrameDataPointers[KRAID_OAM_END] = {
    [KRAID_OAM_MOUTH_CLOSED] = sKraidOam_MouthClosed,
    [KRAID_OAM_MOUTH_CLOSED_BLINK] = sKraidOam_MouthClosedBlink,
    [KRAID_OAM_OPENING_MOUTH] = sKraidOam_OpeningMouth,
    [KRAID_OAM_MOUTH_OPENED] = sKraidOam_MouthOpened,
    [KRAID_OAM_RISING] = sKraidOam_Rising,
    [KRAID_OAM_CLOSING_MOUTH] = sKraidOam_ClosingMouth,
    [KRAID_OAM_2cac5c] = sKraidPartOam_2cac5c,
    [KRAID_OAM_LEFT_ARM_IDLE] = sKraidPartOam_LeftArmIdle,
    [KRAID_OAM_LEFT_ARM_DYING] = sKraidPartOam_LeftArmDying,
    [KRAID_OAM_LEFT_ARM_THROWING_NAILS] = sKraidPartOam_LeftArmThrowingNails,
    [KRAID_OAM_2cadc4] = sKraidPartOam_2cadc4,
    [KRAID_OAM_RIGHT_ARM_IDLE] = sKraidPartOam_RightArmIdle,
    [KRAID_OAM_RIGHT_ARM_Attacking] = sKraidPartOam_RightArmAttacking,
    [KRAID_OAM_RIGHT_ARM_DYING] = sKraidPartOam_RightArmDying,
    [KRAID_OAM_LEFT_FEET_RISING] = sKraidPartOam_LeftFeetRising,
    [KRAID_OAM_LEFT_FEET_IDLE_1] = sKraidPartOam_LeftFeetIdle1,
    [KRAID_OAM_LEFT_FEET_MOVING_RIGHT] = sKraidPartOam_LeftFeetMovingRight,
    [KRAID_OAM_LEFT_FEET_IDLE_2] = sKraidPartOam_LeftFeetIdle2,
    [KRAID_OAM_LEFT_FEET_MOVED_RIGHT] = sKraidPartOam_LeftFeetMovedRight,
    [KRAID_OAM_LEFT_FEET_MOVING_LEFT] = sKraidPartOam_LeftFeetMovingLeft,
    [KRAID_OAM_LEFT_FEET_MOVED_LEFT] = sKraidPartOam_LeftFeetMovedLeft,
    [KRAID_OAM_RIGHT_FEET_RISING] = sKraidPartOam_RightFeetRising,
    [KRAID_OAM_RIGHT_FEET_IDLE_1] = sKraidPartOam_RightFeetIdle1,
    [KRAID_OAM_RIGHT_FEET_MOVED_RIGHT] = sKraidPartOam_RightFeetMovedRight,
    [KRAID_OAM_RIGHT_FEET_IDLE_2] = sKraidPartOam_RightFeetIdle2,
    [KRAID_OAM_RIGHT_FEET_MOVING_RIGHT] = sKraidPartOam_RightFeetMovingRight,
    [KRAID_OAM_RIGHT_FEET_MOVED_LEFT] = sKraidPartOam_RightFeetMovedLeft,
    [KRAID_OAM_RIGHT_FEET_MOVING_LEFT] = sKraidPartOam_RightFeetMovingLeft,
    [KRAID_OAM_TOP_HOLE_LEFT] = sKraidPartOam_TopHoleLeft,
    [KRAID_OAM_TOP_HOLE_RIGHT] = sKraidPartOam_TopHoleRight,
    [KRAID_OAM_MIDDLE_HOLE_LEFT] = sKraidPartOam_MiddleHoleLeft,
    [KRAID_OAM_MIDDLE_HOLE_RIGHT] = sKraidPartOam_MiddleHoleRight,
    [KRAID_OAM_BOTTOM_HOLE_LEFT] = sKraidPartOam_BottomHoleLeft,
    [KRAID_OAM_BOTTOM_HOLE_RIGHT] = sKraidPartOam_BottomHoleRight,
    [KRAID_OAM_NAIL] = sKraidNailOam,
    [KRAID_OAM_2cb29c] = sKraidOam_2cb29c,
    [KRAID_OAM_2cb2ac] = sKraidOam_2cb2ac,
    [KRAID_OAM_SPIKE] = sKraidSpikeOam
};

const struct FrameData* const sImagoLarvaFrameDataPointers[IMAGO_LARVA_OAM_END] = {
    [IMAGO_LARVA_OAM_SHELL_ATTACKING] = sImagoLarvaPartOam_ShellAttacking,
    [IMAGO_LARVA_OAM_SHELL_IDLE] = sImagoLarvaPartOam_ShellIdle,
    [IMAGO_LARVA_OAM_SHELL_RETREATING] = sImagoLarvaPartOam_ShellRetreating,
    [IMAGO_LARVA_OAM_SHELL_DYING] = sImagoLarvaPartOam_ShellDying,
    [IMAGO_LARVA_OAM_CLAWS_ATTACKING] = sImagoLarvaPartOam_ClawsAttacking,
    [IMAGO_LARVA_OAM_CLAWS_IDLE] = sImagoLarvaPartOam_ClawsIdle,
    [IMAGO_LARVA_OAM_CLAWS_RETREATING] = sImagoLarvaPartOam_ClawsRetreating,
    [IMAGO_LARVA_OAM_CLAWS_TAKING_DAMAGE] = sImagoLarvaPartOam_ClawsTakingDamage,
    [IMAGO_LARVA_OAM_LEFT_DOT_APPEARING] = sImagoLarvaPartOam_LeftDotAppearing,
    [IMAGO_LARVA_OAM_MIDDLE_DOT_APPEARING] = sImagoLarvaPartOam_MiddleDotAppearing,
    [IMAGO_LARVA_OAM_RIGHT_DOT_APPEARING] = sImagoLarvaPartOam_RightDotAppearing,
    [IMAGO_LARVA_OAM_LEFT_DOT_VISIBLE] = sImagoLarvaPartOam_LeftDotVisible,
    [IMAGO_LARVA_OAM_MIDDLE_DOT_VISIBLE] = sImagoLarvaPartOam_MiddleDotVisible,
    [IMAGO_LARVA_OAM_RIGHT_DOT_VISIBLE] = sImagoLarvaPartOam_RightDotVisible,
    [IMAGO_LARVA_OAM_LEFT_DOT_DISAPPEARING] = sImagoLarvaPartOam_LeftDotDisappearing,
    [IMAGO_LARVA_OAM_MIDDLE_DOT_DISAPPEARING] = sImagoLarvaPartOam_MiddleDotDisappearing,
    [IMAGO_LARVA_OAM_RIGHT_DOT_DISAPPEARING] = sImagoLarvaPartOam_RightDotDisappearing,
    [IMAGO_LARVA_OAM_SHELL_WARNING] = sImagoLarvaPartOam_ShellWarning,
    [IMAGO_LARVA_OAM_IDLE] = sImagoLarvaOam_Idle,
    [IMAGO_LARVA_OAM_CLAWS_WARNING_FIRST_PART] = sImagoLarvaPartOam_ClawsWarningFirstPart,
    [IMAGO_LARVA_OAM_CLAWS_WARNING_SECOND_PART] = sImagoLarvaPartOam_ClawsWarningSecondPart,
    [IMAGO_LARVA_OAM_WARNING] = sImagoLarvaOam_Warning,
    [IMAGO_LARVA_OAM_SHELL_TAKING_DAMAGE] = sImagoLarvaPartOam_ShellTakingDamage
};

const struct FrameData* const sImagoCocoonFrameDataPointers[IMAGO_COCOON_OAM_END] = {
    [IMAGO_COCOON_OAM_CEILING_VINE_MOTIONLESS] = sImagoCocoonOam_CeilingVineMotionless,
    [IMAGO_COCOON_OAM_CEILING_VINE_MOVING] = sImagoCocoonOam_CeilingVineMoving,
    [IMAGO_COCOON_OAM_CEILING_VINE_BROKEN] = sImagoCocoonOam_CeilingVineBroken,
    [IMAGO_COCOON_OAM_DECORATIVE_VINE_LEFT] = sImagoCocoonOam_DecorativeVinesLeft,
    [IMAGO_COCOON_OAM_DECORATIVE_VINE_RIGHT] = sImagoCocoonOam_DecorativeVinesRight,
    [IMAGO_COCOON_OAM_VINE_LEFT_MIDDLE] = sImagoCocoonVineOam_LeftMiddle,
    [IMAGO_COCOON_OAM_VINE_RIGHT_MIDDLE] = sImagoCocoonVineOam_RightMiddle,
    [IMAGO_COCOON_OAM_VINE_LEFT_RIGHT] = sImagoCocoonVineOam_LeftRight,
    [IMAGO_COCOON_OAM_VINE_RIGT_RIGHT] = sImagoCocoonVineOam_RightRight,
    [IMAGO_COCOON_OAM_VINE_LEFT_LEFT] = sImagoCocoonVineOam_LeftLeft,
    [IMAGO_COCOON_OAM_VINE_RIGHT_LEFT] = sImagoCocoonVineOam_RightLeft,
    [IMAGO_COCOON_OAM_IDLE] = sImagoCocoonOam_Idle,
    [IMAGO_COCOON_OAM_2e0bb0] = sImagoCocoonOam_2e0bb0,
    [IMAGO_COCOON_OAM_STATIC] = sImagoCocoonOam_Static,
    [IMAGO_COCOON_OAM_SPORE_SPAWNING] = sImagoCocoonSporeOam_Spawning,
    [IMAGO_COCOON_OAM_SPORE_NEST] = sImagoCocoonSpore_Nest,
    [IMAGO_COCOON_OAM_SPORE_MOVING] = sImagoCocoonSpore_Moving,
    [IMAGO_COCOON_OAM_SPORE_EXPLODING] = sImagoCocoonSpore_Exploding,
    [IMAGO_COCOON_OAM_WINGED_RIPPER_MOVING] = sWingedRipperOam_Moving,
    [IMAGO_COCOON_OAM_WINGED_RIPPER_TURNING_AROUND] = sWingedRipperOam_TurningAround,
    [IMAGO_COCOON_OAM_DEFEATED_COCOON] = sDefeatedImagoCocoonOam
};

const struct FrameData* const sRidleyFrameDataPointers[RIDLEY_OAM_END] = {
    [RIDLEY_OAM_IDLE] = sRidleyOAM_Idle,
    [RIDLEY_OAM_SPITTING_FIREBALLS] = sRidleyOAM_SpittingFireballs,
    [RIDLEY_OAM_TURNING_AROUND_FIRST_PART] = sRidleyOAM_TurningAroundFirstPart,
    [RIDLEY_OAM_TURNING_AROUND_SECOND_PART] = sRidleyOAM_TurningAroundSecondPart,
    [RIDLEY_OAM_HEAD_IDLE] = sRidleyPartOam_HeadIdle,
    [RIDLEY_OAM_OPENING_MOUTH] = sRidleyPartOam_OpeningMouth,
    [RIDLEY_OAM_MOUTH_OPENED] = sRidleyPartOam_MouthOpened,
    [RIDLEY_OAM_HEAD_DYING] = sRidleyPartOam_HeadDying,
    [RIDLEY_OAM_HEAD_TURNING_AROUND] = sRidleyPartOam_HeadTurningAround,
    [RIDLEY_OAM_CLAW_IDLE] = sRidleyPartOam_ClawIdle,
    [RIDLEY_OAM_CLAW_SPITTING_FIREBALLS] = sRidleyPartOam_ClawSpittingFireballs,
    [RIDLEY_OAM_CLAW_TURNING_AROUND_FIRST_PART] = sRidleyPartOam_ClawTurningAroundFirstPart,
    [RIDLEY_OAM_CLAW_TURNING_AROUND_SECOND_PART] = sRidleyPartOam_ClawTurningAroundSecondPart,
    [RIDLEY_OAM_CLAW_CARRYING_SAMUS] = sRidleyPartOam_ClawCarryingSamus,
    [RIDLEY_OAM_CLAW_LIFTING_SAMUS] = sRidleyPartOam_ClawLiftingSamus,
    [RIDLEY_OAM_CLAW_SAMUS_LIFTED] = sRidleyPartOam_ClawSamusLifted,
    [RIDLEY_OAM_CLAW_RELEASING_SAMUS] = sRidleyPartOam_ClawReleasingSamus,
    [RIDLEY_OAM_LEFT_WING_IDLE] = sRidleyPartOam_LeftWingIdle,
    [RIDLEY_OAM_RIGHT_WING_IDLE] = sRidleyPartOam_RightWingIdle,
    [RIDLEY_OAM_LEFT_WING_UNUSED] = sRidleyPartOam_LeftWing_Unused,
    [RIDLEY_OAM_RIGHT_WING_UNUSED] = sRidleyPartOam_RightWing_Unused,
    [RIDLEY_OAM_LEFT_WING_SPITTING_FIREBALLS] = sRidleyPartOam_LeftWingSpittingFireballs,
    [RIDLEY_OAM_RIGHT_WING_SPITTING_FIREBALLS] = sRidleyPartOam_RightWingSpittingFireballs,
    [RIDLEY_OAM_TAIL_PART] = sRidleyTailOAM_Part,
    [RIDLEY_OAM_TAIL_TIP_POINTING_DOWN] = sRidleyTailOAM_TipPointingDown,
    [RIDLEY_OAM_TAIL_TIP_POINTING_UP] = sRidleyTailOAM_TipPointingUp,
    [RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_DOWN_RIGHT] = sRidleyTailOAM_TipPointingDiagonallyDownRight,
    [RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_UP_RIGHT] = sRidleyTailOAM_TipPointingDiagonallyUpRight,
    [RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_DOWN_LEFT] = sRidleyTailOAM_TipPointingDiagonallyDownLeft,
    [RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_UP_LEFT] = sRidleyTailOAM_TipPointingDiagonallyUpLeft,
    [RIDLEY_OAM_SQUARE] = sRidleyOAM_Square,
    [RIDLEY_OAM_FIREBALL_SMALL] = sRidleyFireballOam_Small,
    [RIDLEY_OAM_FIREBALL_BIG] = sRidleyFireballOam_Big
};

// palette, palette timer
const u8 sAtomicDynamicPaletteData[33][2] = {
    // mild flashing
    { 0, CONVERT_SECONDS(1.f / 15) },
    { 2, CONVERT_SECONDS(1.f / 15) },
    { 0, CONVERT_SECONDS(1.f / 15) },
    { 2, CONVERT_SECONDS(1.f / 15) },
    { 0, CONVERT_SECONDS(1.f / 15) },
    { 2, CONVERT_SECONDS(1.f / 15) },
    { 0, CONVERT_SECONDS(1.f / 15) },
    { 2, CONVERT_SECONDS(1.f / 15) },
    { 3, CONVERT_SECONDS(1.f / 15) },
    { 2, CONVERT_SECONDS(1.f / 15) },
    { 3, CONVERT_SECONDS(1.f / 15) },
    { 2, CONVERT_SECONDS(1.f / 15) },
    { 3, CONVERT_SECONDS(1.f / 15) },
    { 2, CONVERT_SECONDS(1.f / 15) },
    { 3, CONVERT_SECONDS(1.f / 15) },
    { 2, CONVERT_SECONDS(1.f / 15) },
    // offset == 16, intense flashing
    { 3, CONVERT_SECONDS(1.f / 30) },
    { 2, CONVERT_SECONDS(1.f / 30) },
    { 3, CONVERT_SECONDS(1.f / 30) },
    { 2, CONVERT_SECONDS(1.f / 30) },
    { 3, CONVERT_SECONDS(1.f / 30) },
    { 2, CONVERT_SECONDS(1.f / 30) },
    { 3, CONVERT_SECONDS(1.f / 30) },
    { 2, CONVERT_SECONDS(1.f / 30) },
    { 3, CONVERT_SECONDS(1.f / 30) },
    { 2, CONVERT_SECONDS(1.f / 30) },
    { 3, CONVERT_SECONDS(1.f / 30) },
    { 2, CONVERT_SECONDS(1.f / 30) },
    { 3, CONVERT_SECONDS(1.f / 30) },
    { 2, CONVERT_SECONDS(1.f / 30) },
    { 3, CONVERT_SECONDS(1.f / 30) },
    { 2, CONVERT_SECONDS(1.f / 30) },
    { 0, 0 }
};

const struct FrameData* const sMotheBrainFrameDataPointers[MOTHER_BRAIN_OAM_END] = {
    [MOTHER_BRAIN_OAM_IDLE] = sMotherBrainOam_Idle,
    [MOTHER_BRAIN_OAM_CHARGING_BEAM] = sMotherBrainOam_ChargingBeam,
    [MOTHER_BRAIN_OAM_EYE_CLOSED] = sMotherBrainPartOam_EyeClosed,
    [MOTHER_BRAIN_OAM_2fa934] = sMotherBrainPartOam_2fa934,
    [MOTHER_BRAIN_OAM_EYE_OPENING] = sMotherBrainPartOam_EyeOpening,
    [MOTHER_BRAIN_OAM_2fa984] = sMotherBrainPartOam_2fa984,
    [MOTHER_BRAIN_OAM_EYE_DYING] = sMotherBrainPartOam_EyeDying,
    [MOTHER_BRAIN_OAM_BOTTOM] = sMotherBrainPartOam_Bottom,
    [MOTHER_BRAIN_OAM_BEAM_SPAWNING] = sMotherBrainPartOam_BeamSpawning,
    [MOTHER_BRAIN_OAM_BEAM_MOVING] = sMotherBrainBeamOam_Moving
};

const struct FrameData* const sTangleVineFrameDataPointers[TANGLE_VINE_OAM_END] = {
    [TANGLE_VINE_OAM_TALL_ON_GROUND] = sTangleVineTallOam_OnGround,
    [TANGLE_VINE_OAM_MEDIUM_ON_GROUND] = sTangleVineMediumOam_OnGround,
    [TANGLE_VINE_OAM_SHORT_ON_GROUND] = sTangleVineShortOam_OnGround,
    [TANGLE_VINE_OAM_CURVED_ON_GROUND] = sTangleVineCurvedOam_OnGround,
    [TANGLE_VINE_OAM_TALL_ON_CEILING] = sTangleVineTallOam_OnCeiling,
    [TANGLE_VINE_OAM_MEDIUM_ON_CEILING] = sTangleVineMediumOam_OnCeiling,
    [TANGLE_VINE_OAM_SHORT_ON_CEILING] = sTangleVineShortOam_OnCeiling,
    [TANGLE_VINE_OAM_CURVED_ON_CEILING] = sTangleVineCurvedOam_OnCeiling,
    [TANGLE_VINE_OAM_GERUTA_GRIP] = sTangleVineGerutaPartOam_Grip,
    [TANGLE_VINE_OAM_GERUTA_ROOT] = sTangleVineGerutaOam_Root,
    [TANGLE_VINE_OAM_GERUTA_FULL] = sTangleVineGerutaOam_Full,
    [TANGLE_VINE_OAM_RED_GERUTA_OAM] = sTangleVineRedGerutaOam,
    [TANGLE_VINE_OAM_GERUTA] = sTangleVineGerutaPartOam_Geruta
};

const struct FrameData* const sImagoFrameDataPointers[IMAGO_OAM_END] = {
    [IMAGO_OAM_BODY_IDLE] = sImagoPartOam_BodyIdle,
    [IMAGO_OAM_BODY_GROWLING] = sImagoPartOam_BodyGrowling,
    [IMAGO_OAM_BROKEN_STINGER] = sImagoOam_BrokenStinger,
    [IMAGO_OAM_LEFT_WING_IDLE] = sImagoPartOam_LeftWingIdle,
    [IMAGO_OAM_LEFT_WING_SHOOTING_NEEDLES] = sImagoPartOam_LeftWingShootingNeedles,
    [IMAGO_OAM_LEFT_WING_DYING] = sImagoPartOam_LeftWingDying,
    [IMAGO_OAM_RIGHT_WING_IDLE] = sImagoPartOam_RightWingIdle,
    [IMAGO_OAM_RIGHT_WING_SHOOTING_NEEDLES] = sImagoPartOam_RightWingShootingNeedles,
    [IMAGO_OAM_RIGHT_WING_DYING] = sImagoPartOam_RightWingDying,
    [IMAGO_OAM_CORE] = sImagoPartOam_Core,
    [IMAGO_OAM_FLYING] = sImagoOam_Flying,
    [IMAGO_OAM_SHOOTING_NEEDLES] = sImagoOam_ShootingNeedles,
    [IMAGO_OAM_RECHARGING_NEEDLES] = sImagoOam_RechargingNeedles,
    [IMAGO_OAM_DAMAGED_STINGER] = sImagoDamagedStingerOam,
    [IMAGO_OAM_NEEDLE] = sImagoNeedleOam,
    [IMAGO_OAM_DAMAGED_STINGER_UNUSED] = sImagoDamagedStingerOam_Unused,
    [IMAGO_OAM_EGG_BREAKING] = sImagoEggOam_Breaking
};

const struct FrameData* const sCrocomireFrameDataPointers[CROCOMIRE_OAM_END] = {
    [CROCOMIRE_OAM_PART_BODY_IDLE] = sCrocomirePartOam_BodyIdle,
    [CROCOMIRE_OAM_PART_BODY_ANGRY] = sCrocomirePartOam_BodyAngry,
    [CROCOMIRE_OAM_IDLE] = sCrocomireOam_Idle,
    [CROCOMIRE_OAM_SCREAMING] = sCrocomireOam_Screaming,
    [CROCOMIRE_OAM_DYING] = sCrocomireOam_Dying,
    [CROCOMIRE_OAM_PART_RIGHT_ARM_IDLE] = sCrocomirePartOam_RightArmIdle,
    [CROCOMIRE_OAM_PART_LEFT_ARM_IDLE] = sCrocomirePartOam_LeftArmIdle,
    [CROCOMIRE_OAM_PART_LEFT_ARM_SCREAMING] = sCrocomirePartOam_LeftArmScreaming,
    [CROCOMIRE_OAM_PART_RIGHT_ARM_WALKING_FORWARD] = sCrocomirePartOam_RightArmWalkingForward,
    [CROCOMIRE_OAM_PART_LEFT_ARM_WALKING_FORWARD] = sCrocomirePartOam_LeftArmWalkingForward,
    [CROCOMIRE_OAM_PART_RIGHT_ARM_WALKING_BACKWARDS] = sCrocomirePartOam_RightArmWalkingBackwards,
    [CROCOMIRE_OAM_PART_LEFT_ARM_WALKING_BACKWARDS] = sCrocomirePartOam_LeftArmWalkingBackwards,
    [CROCOMIRE_OAM_PART_RIGHT_ARM_DYING] = sCrocomirePartOam_RightArmDying,
    [CROCOMIRE_OAM_PART_LEFT_ARM_DYING] = sCrocomirePartOam_LeftArmDying,
    [CROCOMIRE_OAM_PART_LEGS_IDLE] = sCrocomirePartOam_LegsIdle,
    [CROCOMIRE_OAM_PART_LEGS_WALKING_FORWARD] = sCrocomirePartOam_LegsWalkingForward,
    [CROCOMIRE_OAM_PART_LEGS_WALKING_BACKWARDS] = sCrocomirePartOam_LegsWalkingBackwards,
    [CROCOMIRE_OAM_PART_LEGS_DYING] = sCrocomirePartOam_LegsDying,
    [CROCOMIRE_OAM_PART_TONGUE] = sCrocomirePartOam_Tongue,
    [CROCOMIRE_OAM_PART_TONGUE_DYING] = sCrocomirePartOam_TongueDying,
    [CROCOMIRE_OAM_PROJECTILE] = sCrocomireProjectileOAM,
    [CROCOMIRE_OAM_PART_307028] = sCrocomirePartOam_307028,
    [CROCOMIRE_OAM_PART_307058] = sCrocomirePartOam_307058,
    [CROCOMIRE_OAM_PART_307088] = sCrocomirePartOam_307088,
    [CROCOMIRE_OAM_PART_3070b8] = sCrocomirePartOam_3070b8,
};

const struct FrameData* const sMechaRidleyFrameDataPointers[MECHA_RIDLEY_OAM_END] = {
    [MECHA_RIDLEY_OAM_TAIL] = sMechaRidleyPartOam_Tail,
    [MECHA_RIDLEY_OAM_RING] = sMechaRidleyPartOam_Ring,
    [MECHA_RIDLEY_OAM_COVER] = sMechaRidleyPartOam_Cover,
    [MECHA_RIDLEY_OAM_TORSO] = sMechaRidleyPartOam_Torso,
    [MECHA_RIDLEY_OAM_CORE_IDLE] = sMechaRidleyOam_Idle,
    [MECHA_RIDLEY_OAM_HEAD_IDLE] = sMechaRidleyPartOam_HeadIdle,
    [MECHA_RIDLEY_OAM_HEAD_OPENING_MOUTH] = sMechaRidleyPartOam_HeadOpeningMouth,
    [MECHA_RIDLEY_OAM_HEAD_SPITTING_FIREBALLS] = sMechaRidleyPartOam_HeadSpittingFireballs,
    [MECHA_RIDLEY_OAM_HEAD_CLOSING_MOUTH] = sMechaRidleyPartOam_HeadClosingMouth,
    [MECHA_RIDLEY_OAM_EYE_IDLE] = sMechaRidleyPartOam_EyeIdle,
    [MECHA_RIDLEY_OAM_EYE_GLOWING] = sMechaRidleyPartOam_EyeGlowing,
    [MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_FORWARD] = sMechaRidleyPartOam_EyeShootingLaserForward,
    [MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_SLIGHTLY_DOWN] = sMechaRidleyPartOam_EyeShootingLaserSlightlyDown,
    [MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_DOWN] = sMechaRidleyPartOam_EyeShootingLaserDown,
    [MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_SLIGHTLY_UP] = sMechaRidleyPartOam_EyeShootingLaserSlightlyUp,
    [MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_UP] = sMechaRidleyPartOam_EyeShootingLaserUp,
    [MECHA_RIDLEY_OAM_EYE_INACTIVE] = sMechaRidleyPartOam_EyeInactive,
    [MECHA_RIDLEY_OAM_LEFT_ARM_CRAWLING_FORWARD] = sMechaRidleyPartOam_LeftArmCrawlingForward,
    [MECHA_RIDLEY_OAM_RIGHT_ARM_CRAWLING_FORWARD] = sMechaRidleyPartOam_RightArmCrawlingForward,
    [MECHA_RIDLEY_OAM_LEFT_ARM_HOLDING_UP] = sMechaRidleyPartOam_LeftArmHoldingUp,
    [MECHA_RIDLEY_OAM_RIGHT_ARM_HOLDING_UP] = sMechaRidleyPartOam_RightArmHoldingUp,
    [MECHA_RIDLEY_OAM_LEFT_ARM_HELD_UP] = sMechaRidleyPartOam_LeftArmHeldUp,
    [MECHA_RIDLEY_OAM_RIGHT_ARM_HELD_UP] = sMechaRidleyPartOam_RightArmHeldUp,
    [MECHA_RIDLEY_OAM_LEFT_ARM_LAYING_DOWN] = sMechaRidleyPartOam_LeftArmLayingDown,
    [MECHA_RIDLEY_OAM_RIGHT_ARM_LAYING_DOWN] = sMechaRidleyPartOam_RightArmLayingDown,
    [MECHA_RIDLEY_OAM_LEFT_ARM_TREMBLING] = sMechaRidleyPartOam_LeftArmTrembling,
    [MECHA_RIDLEY_OAM_RIGHT_ARM_TREMBLING] = sMechaRidleyPartOam_RightArmTrembling,
    [MECHA_RIDLEY_OAM_LEFT_ARM_IDLE] = sMechaRidleyPartOam_LeftArmIdle,
    [MECHA_RIDLEY_OAM_RIGHT_ARM_IDLE] = sMechaRidleyPartOam_RightArmIdle,
    [MECHA_RIDLEY_OAM_LEFT_ARM_SWINGING] = sMechaRidleyPartOam_LeftArmSwinging,
    [MECHA_RIDLEY_OAM_NECK_LOW] = sMechaRidleyPartOam_NeckLow,
    [MECHA_RIDLEY_OAM_NECK_MIDDLE] = sMechaRidleyPartOam_NeckMiddle,
    [MECHA_RIDLEY_OAM_NECK_HIGH] = sMechaRidleyPartOam_NeckHigh,
    [MECHA_RIDLEY_OAM_NECK_ROTATE_LOW] = sMechaRidleyPartOam_NeckRotateLow,
    [MECHA_RIDLEY_OAM_NECK_ROTATE_MIDDLE] = sMechaRidleyPartOam_NeckRotateMiddle,
    [MECHA_RIDLEY_OAM_NECK_ROTATE_HIGH] = sMechaRidleyPartOam_NeckRotateHigh,
    [MECHA_RIDLEY_OAM_NECK_LOW_TO_MIDDLE] = sMechaRidleyPartOam_NeckLowToMiddle,
    [MECHA_RIDLEY_OAM_NECK_MIDDLE_TO_HIGH] = sMechaRidleyPartOam_NeckMiddleToHigh,
    [MECHA_RIDLEY_OAM_NECK_HIGH_TO_MIDDLE] = sMechaRidleyPartOam_NeckHighToMiddle,
    [MECHA_RIDLEY_OAM_NECK_MIDDLE_TO_LOW] = sMechaRidleyPartOam_NeckMiddleToLow,
    [MECHA_RIDLEY_OAM_NECK_LOW_TO_HIGH] = sMechaRidleyPartOam_NeckLowToHigh,
    [MECHA_RIDLEY_OAM_NECK_HIGH_TO_LOW] = sMechaRidleyPartOam_NeckHighToLow,
    [MECHA_RIDLEY_OAM_NECK_LOW_2] = sMechaRidleyPartOam_NeckLow_2,
    [MECHA_RIDLEY_OAM_NECK_MIDDLE_2] = sMechaRidleyPartOam_NeckMiddle_2,
    [MECHA_RIDLEY_OAM_NECK_HIGH_2] = sMechaRidleyPartOam_NeckHigh_2,
    [MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_CLOSED] = sMechaRidleyPartOam_MissileLauncherClosed,
    [MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_OPENING] = sMechaRidleyPartOam_MissileLauncherOpening,
    [MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_OPENED] = sMechaRidleyPartOam_MissileLauncherOpened,
    [MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_CLOSING] = sMechaRidleyPartOam_MissileLauncherClosing,
    [MECHA_RIDLEY_OAM_MISSILE] = sMechaRidleyMissileOam,
    [MECHA_RIDLEY_OAM_FIREBALL] = sMechaRidleyFireballOam,
    [MECHA_RIDLEY_OAM_LASER_FORWARD] = sMechaRidleyLaserOam_Forward,
    [MECHA_RIDLEY_OAM_LASER_SLIGHTLY_DOWN] = sMechaRidleyLaserOam_SlightlyDown,
    [MECHA_RIDLEY_OAM_LASER_DOWN] = sMechaRidleyLaserOam_Down,
    [MECHA_RIDLEY_OAM_LASER_SLIGHTLY_UP] = sMechaRidleyLaserOam_SlightlyUp,
    [MECHA_RIDLEY_OAM_LASER_UP] = sMechaRidleyLaserOam_Up,
    [MECHA_RIDLEY_OAM_LEFT_ARM_DYING] = sMechaRidleyPartOam_LeftArmDying,
    [MECHA_RIDLEY_OAM_RIGHT_ARM_DYING] = sMechaRidleyPartOam_RightArmDying,
    [MECHA_RIDLEY_OAM_NECK_DYING] = sMechaRidleyPartOam_NeckDying,
    [MECHA_RIDLEY_OAM_LEFT_ARM_CRAWLING_BACKWARDS] = sMechaRidleyPartOam_LeftArmCrawlingBackwards,
    [MECHA_RIDLEY_OAM_RIGHT_ARM_CRAWLING_BACKWARDS] = sMechaRidleyPartOam_RightArmCrawlingBackwards,
    [MECHA_RIDLEY_OAM_LEFT_ARM_SWINGING_AT_GROUND] = sMechaRidleyPartOam_LeftArmSwingingAtGround,
    [MECHA_RIDLEY_OAM_LEFT_ARM_SWINGING_AT_CLOSE_GROUND] = sMechaRidleyPartOam_LeftArmSwingingAtCloseGround
};
