#include "data/menus/pause_screen_sub_menus_data.h"

#include "constants/event.h"
#include "constants/connection.h"
#include "constants/samus.h"

const struct ChozoStatueTarget sChozoStatueTargets[TARGET_END] = {
    [TARGET_LONG_BEAM] = {
        .statueArea = AREA_BRINSTAR,
        .statueXStart = 9,
        .statueXEnd = 9,
        .statueYStart = 15,
        .statueYEnd = 15,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_BRINSTAR,
        .targetX = 6,
        .targetY = 6,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_BOMBS] = {
        .statueArea = AREA_BRINSTAR,
        .statueXStart = 9,
        .statueXEnd = 9,
        .statueYStart = 3,
        .statueYEnd = 3,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_BRINSTAR,
        .targetX = 24,
        .targetY = 6,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_ICE_BEAM] = {
        .statueArea = AREA_BRINSTAR,
        .statueXStart = 18,
        .statueXEnd = 18,
        .statueYStart = 10,
        .statueYEnd = 10,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_NORFAIR,
        .targetX = 18,
        .targetY = 3,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_SPEED_BOOSTER] = {
        .statueArea = AREA_NORFAIR,
        .statueXStart = 18,
        .statueXEnd = 18,
        .statueYStart = 1,
        .statueYEnd = 1,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_KRAID,
        .targetX = 8,
        .targetY = 15,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_HIGH_JUMP] = {
        .statueArea = AREA_BRINSTAR,
        .statueXStart = 8,
        .statueXEnd = 8,
        .statueYStart = 18,
        .statueYEnd = 18,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_NORFAIR,
        .targetX = 19,
        .targetY = 8,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_VARIA] = {
        .statueArea = AREA_NORFAIR,
        .statueXStart = 21,
        .statueXEnd = 21,
        .statueYStart = 10,
        .statueYEnd = 10,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_BRINSTAR,
        .targetX = 14,
        .targetY = 2,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_WAVE_BEAM] = {
        .statueArea = AREA_BRINSTAR,
        .statueXStart = 26,
        .statueXEnd = 26,
        .statueYStart = 4,
        .statueYEnd = 4,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_NORFAIR,
        .targetX = 10,
        .targetY = 12,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_SCREW_ATTACK] = {
        .statueArea = AREA_NORFAIR,
        .statueXStart = 19,
        .statueXEnd = 19,
        .statueYStart = 13,
        .statueYEnd = 13,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_NORFAIR,
        .targetX = 6,
        .targetY = 7,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_KRAID_FLAME] = {
        .statueArea = AREA_KRAID,
        .statueXStart = 9,
        .statueXEnd = 10,
        .statueYStart = 14,
        .statueYEnd = 15,
        .startIcon = TARGET_OAM_GREEN_FLAME_SPAWNING,
        .targetArea = AREA_BRINSTAR,
        .targetX = 3,
        .targetY = 3,
        .endIcon = TARGET_OAM_GREEN_FLAME_MOVING
    },
    [TARGET_RIDLEY_FLAME] = {
        .statueArea = AREA_RIDLEY,
        .statueXStart = 7,
        .statueXEnd = 8,
        .statueYStart = 6,
        .statueYEnd = 7,
        .startIcon = TARGET_OAM_PURPLE_FLAME_SPAWNING,
        .targetArea = AREA_BRINSTAR,
        .targetX = 2,
        .targetY = 3,
        .endIcon = TARGET_OAM_PURPLE_FLAME_MOVING
    },
    [10] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
    [11] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
    [12] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
    [13] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
    [14] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
    [15] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
};

/**
 * Indicates when a hint should no longer be displayed on the map
 */
const u8 sChozoStatueTargetConditions[TARGET_END][2] = {
// Use events for each hint condition instead of checking equipment
#ifdef RANDOMIZER
    [TARGET_LONG_BEAM] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_COLLECTED_LONG_BEAM_HINT
    },
    [TARGET_BOMBS] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_COLLECTED_BOMBS_HINT
    },
    [TARGET_ICE_BEAM] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_COLLECTED_ICE_BEAM_HINT
    },
    [TARGET_SPEED_BOOSTER] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_COLLECTED_SPEED_BOOSTER_HINT
    },
    [TARGET_HIGH_JUMP] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_COLLECTED_HI_JUMP_HINT
    },
    [TARGET_VARIA] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_COLLECTED_VARIA_SUIT_HINT
    },
    [TARGET_WAVE_BEAM] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_COLLECTED_WAVE_BEAM_HINT
    },
    [TARGET_SCREW_ATTACK] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_COLLECTED_SCREW_ATTACK_HINT
    },
#else // !RANDOMIZER
    [TARGET_LONG_BEAM] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_BEAM_BOMBS,
        BBF_LONG_BEAM
    },
    [TARGET_BOMBS] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_BEAM_BOMBS,
        BBF_BOMBS
    },
    [TARGET_ICE_BEAM] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_BEAM_BOMBS,
        BBF_ICE_BEAM
    },
    [TARGET_SPEED_BOOSTER] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_SUIT_MISC,
        SMF_SPEEDBOOSTER
    },
    [TARGET_HIGH_JUMP] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_SUIT_MISC,
        SMF_HIGH_JUMP
    },
    [TARGET_VARIA] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_SUIT_MISC,
        SMF_VARIA_SUIT
    },
    [TARGET_WAVE_BEAM] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_BEAM_BOMBS,
        BBF_WAVE_BEAM
    },
    [TARGET_SCREW_ATTACK] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_SUIT_MISC,
        SMF_SCREW_ATTACK
    },
#endif // RANDOMIZER
    [TARGET_KRAID_FLAME] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_KRAID_STATUE_OPENED
    },
    [TARGET_RIDLEY_FLAME] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_RIDLEY_STATUE_OPENED
    },
    [10] = {
        UCHAR_MAX,
        0
    },
    [11] = {
        UCHAR_MAX,
        0
    },
    [12] = {
        UCHAR_MAX,
        0
    },
    [13] = {
        UCHAR_MAX,
        0
    },
    [14] = {
        UCHAR_MAX,
        0
    },
    [15] = {
        UCHAR_MAX,
        0
    }
};

/**
 * Indicates which event should be set for a hint to be active
 */
const Event sChozoStatueHintEvents[TARGET_END] = {
    [TARGET_LONG_BEAM] = EVENT_STATUE_LONG_BEAM_GRABBED,
    [TARGET_BOMBS] = EVENT_STATUE_BOMBS_GRABBED,
    [TARGET_ICE_BEAM] = EVENT_STATUE_ICE_BEAM_GRABBED,
    [TARGET_SPEED_BOOSTER] = EVENT_STATUE_SPEEDBOOSTER_GRABBED,
    [TARGET_HIGH_JUMP] = EVENT_STATUE_HIGH_JUMP_GRABBED,
    [TARGET_VARIA] = EVENT_STATUE_VARIA_SUIT_GRABBED,
    [TARGET_WAVE_BEAM] = EVENT_STATUE_WAVE_BEAM_GRABBED,
    [TARGET_SCREW_ATTACK] = EVENT_STATUE_SCREW_ATTACK_GRABBED,
    [TARGET_KRAID_FLAME] = EVENT_KRAID_KILLED,
    [TARGET_RIDLEY_FLAME] = EVENT_RIDLEY_KILLED,
    [10] = UCHAR_MAX,
    [11] = UCHAR_MAX,
    [12] = UCHAR_MAX,
    [13] = UCHAR_MAX,
    [14] = UCHAR_MAX,
    [15] = UCHAR_MAX
};

#ifdef RANDOMIZER
const s8 sChozoStatueTargetPathBrinstar[21][2] = {
#else // !RANDOMIZER
const s8 sChozoStatueTargetPathBrinstar[9][2] = {
#endif // RANDOMIZER
    [0] = { // Brinstar/Brinstar 1
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [1] = { // Brinstar/Brinstar 2
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [2] = { // Brinstar/Brinstar 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [3] = { // Brinstar/Kraid 1
        ELEVATOR_ROUTE_BRINSTAR_TO_KRAID, 0x40
    },
    [4] = { // Brinstar/Kraid 2
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [5] = { // Brinstar/Kraid 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [6] = { // Brinstar/Norfair 1
        ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR, 0x40
    },
    [7] = { // Brinstar/Norfair 2
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [8] = { // Brinstar/Norfair 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
#ifdef RANDOMIZER
    [9] = { // Brinstar/Ridley 1
        ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR, 0x40
    },
    [10] = { // Brinstar/Ridley 2
        ELEVATOR_ROUTE_NORFAIR_TO_RIDLEY, 0x40
    },
    [11] = { // Brinstar/Ridley 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [12] = { // Brinstar/Tourian 1
        ELEVATOR_ROUTE_BRINSTAR_TO_TOURIAN, 0x40
    },
    [13] = { // Brinstar/Tourian 2
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [14] = { // Brinstar/Tourian 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [15] = { // Brinstar/Crateria 1
        ELEVATOR_ROUTE_CRATERIA_TO_BRINSTAR, -0x40
    },
    [16] = { // Brinstar/Crateria 2
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [17] = { // Brinstar/Crateria 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [18] = { // Brinstar/Chozodia 1
        ELEVATOR_ROUTE_CRATERIA_TO_BRINSTAR, -0x40
    },
    [19] = { // Brinstar/Chozodia 2
        ELEVATOR_ROUTE_CRATERIA_TO_CHOZODIA, -0x40
    },
    [20] = { // Brinstar/Chozodia 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
#endif // RANDOMIZER
};

const s8 sChozoStatueTargetPathKraid[9][2] = {
    [0] = {
        ELEVATOR_ROUTE_BRINSTAR_TO_KRAID, -0x40
    },
    [1] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [2] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [3] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [4] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [5] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [6] = {
        ELEVATOR_ROUTE_BRINSTAR_TO_KRAID, -0x40
    },
    [7] = {
        ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR, 0x40
    },
    [8] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
};

#ifdef RANDOMIZER
const s8 sChozoStatueTargetPathNorfair[21][2] = {
#else // !RANDOMIZER
const s8 sChozoStatueTargetPathNorfair[9][2] = {
#endif // RANDOMIZER
    [0] = { // Norfair/Brinstar 1
        ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR, -0x40
    },
    [1] = { // Norfair/Brinstar 2
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [2] = { // Norfair/Brinstar 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [3] = { // Norfair/Kraid 1
        ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR, -0x40
    },
    [4] = { // Norfair/Kraid 2
        ELEVATOR_ROUTE_BRINSTAR_TO_KRAID, 0x40
    },
    [5] = { // Norfair/Kraid 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [6] = { // Norfair/Norfair 1
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [7] = { // Norfair/Norfair 2
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [8] = { // Norfair/Norfair 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
#ifdef RANDOMIZER
    [9] = { // Norfair/Ridley 1
        ELEVATOR_ROUTE_NORFAIR_TO_RIDLEY, 0x40
    },
    [10] = { // Norfair/Ridley 2
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [11] = { // Norfair/Ridley 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [12] = { // Norfair/Tourian 1
        ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR, -0x40
    },
    [13] = { // Norfair/Tourian 2
        ELEVATOR_ROUTE_BRINSTAR_TO_TOURIAN, 0x40
    },
    [14] = { // Norfair/Tourian 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [15] = { // Norfair/Crateria 1
        ELEVATOR_ROUTE_CRATERIA_TO_NORFAIR, -0x40
    },
    [16] = { // Norfair/Crateria 2
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [17] = { // Norfair/Crateria 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [18] = { // Norfair/Chozodia 1
        ELEVATOR_ROUTE_CRATERIA_TO_NORFAIR, -0x40
    },
    [19] = { // Norfair/Chozodia 2
        ELEVATOR_ROUTE_CRATERIA_TO_CHOZODIA, -0x40
    },
    [20] = { // Norfair/Chozodia 3
        ELEVATOR_ROUTE_NONE, 0x40
    },
#endif // RANDOMIZER
};

const s8 sChozoStatueTargetPathRidley[9][2] = {
    [0] = {
        ELEVATOR_ROUTE_NORFAIR_TO_RIDLEY, -0x40
    },
    [1] = {
        ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR, -0x40
    },
    [2] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [3] = {
        ELEVATOR_ROUTE_NORFAIR_TO_RIDLEY, -0x40
    },
    [4] = {
        ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR, -0x40
    },
    [5] = {
        ELEVATOR_ROUTE_BRINSTAR_TO_KRAID, 0x40
    },
    [6] = {
        ELEVATOR_ROUTE_NORFAIR_TO_RIDLEY, -0x40
    },
    [7] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [8] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
};

const s8 sChozoStatueTargetPathCrateria[9][2] = {
    [0] = {
        ELEVATOR_ROUTE_CRATERIA_TO_NORFAIR, 0x40
    },
    [1] = {
        ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR, -0x40
    },
    [2] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [3] = {
        ELEVATOR_ROUTE_CRATERIA_TO_NORFAIR, 0x40
    },
    [4] = {
        ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR, -0x40
    },
    [5] = {
        ELEVATOR_ROUTE_BRINSTAR_TO_KRAID, 0x40
    },
    [6] = {
        ELEVATOR_ROUTE_CRATERIA_TO_NORFAIR, 0x40
    },
    [7] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
    [8] = {
        ELEVATOR_ROUTE_NONE, 0x40
    },
};
