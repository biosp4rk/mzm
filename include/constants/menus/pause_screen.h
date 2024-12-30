#ifndef PAUSE_SCREEN_CONSTANTS_H
#define PAUSE_SCREEN_CONSTANTS_H

enum PauseScreenSubroutine {
    PAUSE_SCREEN_SUBROUTINE_MAP_SCREEN,
    PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN,

    PAUSE_SCREEN_SUBROUTINE_SUITLESS_ITEMS = 4,

    PAUSE_SCREEN_SUBROUTINE_FULLY_POWERED_ITEMS = 6,

    PAUSE_SCREEN_SUBROUTINE_CHOZO_STATUE_HINT = 8,
    PAUSE_SCREEN_SUBROUTINE_MAP_DOWNLOAD,
    PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP,
    PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN_INIT,
    PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN_LEAVING,

    PAUSE_SCREEN_SUBROUTINE_CHOZO_STATUE_HINT_INIT = 15,
    PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP_INIT,
    PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP_LEAVING,

    PAUSE_SCREEN_SUBROUTINE_SUITLESS_ITEMS_INIT = 19,
    PAUSE_SCREEN_SUBROUTINE_FULLY_POWERED_ITEMS_INIT
};

#define PAUSE_SCREEN_TYPE_NONE                  0
#define PAUSE_SCREEN_TYPE_DEBUG                 (1 << 0)
#define PAUSE_SCREEN_TYPE_ON_MAP_SCREEN         (1 << 1)
#define PAUSE_SCREEN_TYPE_UNKNOWN               (1 << 3)
#define PAUSE_SCREEN_TYPE_CHOZO_STATUE_HINT     (1 << 4)
#define PAUSE_SCREEN_TYPE_DOWNLOADING_MAP       (1 << 5)
#define PAUSE_SCREEN_TYPE_ON_STATUS_SCREEN      (1 << 7)
#define PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM      (1 << 8)
#define PAUSE_SCREEN_TYPE_GETTING_SUITLESS      (1 << 9)
#define PAUSE_SCREEN_TYPE_GETTING_FULLY_POWERED (1 << 10)

enum ItemAcquisition {
    ITEM_ACQUISITION_MISSILES = 3,

    ITEM_ACQUISITION_SUPER_MISSILES = 5,

    ITEM_ACQUISITION_POWER_BOMB = 7,
    ITEM_ACQUISITION_LONG_BEAM,
    ITEM_ACQUISITION_CHARGE_BEAM,
    ITEM_ACQUISITION_ICE_BEAM,
    ITEM_ACQUISITION_WAVE_BEAM,
    ITEM_ACQUISITION_PLASMA_BEAM,
    ITEM_ACQUISITION_BOMBS,
    ITEM_ACQUISITION_VARIA,
    ITEM_ACQUISITION_GRAVITY,
    ITEM_ACQUISITION_MORPH_BALL,
    ITEM_ACQUISITION_SPEEDBOOSTER,
    ITEM_ACQUISITION_HIGH_JUMP,
    ITEM_ACQUISITION_SCREW_ATTACK,
    ITEM_ACQUISITION_SPACE_JUMP,
    ITEM_ACQUISITION_POWER_GRIP,

    ITEM_ACQUISITION_END
};

enum PauseScreenFading {
    PAUSE_SCREEN_FADING_IN_INIT = 2,
    PAUSE_SCREEN_FADING_IN,
    PAUSE_SCREEN_FADING_OUT_INIT,
    PAUSE_SCREEN_FADING_OUT,
};

enum ChozoStatueTargetLocation {
    TARGET_LONG_BEAM,
    TARGET_BOMBS,
    TARGET_ICE_BEAM,
    TARGET_SPEED_BOOSTER,
    TARGET_HIGH_JUMP,
    TARGET_VARIA,
    TARGET_WAVE_BEAM,
    TARGET_SCREW_ATTACK,
    TARGET_KRAID_FLAME,
    TARGET_RIDLEY_FLAME,

    TARGET_END = 16
};

#define CHOZO_STATUE_HINT_CONDITION_TYPE_BEAM_BOMBS 0
#define CHOZO_STATUE_HINT_CONDITION_TYPE_SUIT_MISC 1
#define CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT 2

enum MiscOamId {
    MISC_OAM_ID_SAMUS_ICON_SUIT = 1,
    MISC_OAM_ID_RIGHT_CURSOR,
    MISC_OAM_ID_DOWN_CURSOR,
    MISC_OAM_ID_TEXT_MARKER_DOWN,
    MISC_OAM_ID_TEXT_MARKER_UP,
    MISC_OAM_ID_ITEM_CURSOR_FOCUSING,
    MISC_OAM_ID_ITEM_CURSOR_IDLE,
    MISC_OAM_ID_AREA_UP_ARROW,
    MISC_OAM_ID_AREA_DOWN_ARROW,
    MISC_OAM_ID_MAP_DOWNLOAD_LINE_TRAIL,
    MISC_OAM_ID_MAP_DOWNLOAD_LINE,
    MISC_OAM_ID_MAP_DOWNLOAD_LINE_BLINKING,
    MISC_OAM_ID_ITEM_CURSOR_FOCUSING_DESTROY,
    MISC_OAM_ID_IN_GAME_TIMER,
    MISC_OAM_ID_ENERGY_TANKS,
    MISC_OAM_ID_MISSILE_TANKS,
    MISC_OAM_ID_SUPER_MISSILE_TANKS,
    MISC_OAM_ID_POWER_BOMB_TANKS,

    MISC_OAM_ID_ENERGY_HEADER = 23,

    MISC_OAM_ID_BEAM_HEADER = 26,
    MISC_OAM_ID_BEAM_LINKER,

    MISC_OAM_ID_MISSILE_HEADER = 29,
    MISC_OAM_ID_MISSILE_LINKER,

    MISC_OAM_ID_BOMB_HEADER = 32,
    MISC_OAM_ID_BOMB_LINKER,

    MISC_OAM_ID_SUIT_HEADER = 35,
    MISC_OAM_ID_SUIT_LINKER,

    MISC_OAM_ID_MISC_HEADER = 38,
    MISC_OAM_ID_MISC_LINKER,

    MISC_OAM_ID_GUN_HEADER = 41,
    MISC_OAM_ID_GUN_LINKER,

    MISC_OAM_ID_SAMUS_POWER_SUIT_WIREFRAME = 44,
    MISC_OAM_ID_SAMUS_FULL_SUIT_WIREFRAME,
    MISC_OAM_ID_SAMUS_SUITLESS_WIREFRAME,
    MISC_OAM_ID_PLASMA_UNKNOWN,
    MISC_OAM_ID_PLASMA_KNOWN,
    MISC_OAM_ID_SPACE_JUMP_UNKNOWN,
    MISC_OAM_ID_SPACE_JUMP_KNOWN,
    MISC_OAM_ID_GRAVITY_UNKNOWN,
    MISC_OAM_ID_GRAVITY_KNOWN,
    MISC_OAM_ID_DEBUG_CURSOR,
    MISC_OAM_ID_DEBUG_SELECTOR,
    MISC_OAM_ID_DEBUG_SAMUS_HEAD_AND_ARROWS,

    MISC_OAM_ID_END
};

enum OverlayOamId {
    OVERLAY_OAM_ID_BRINSTAR = 1,
    OVERLAY_OAM_ID_BRINSTAR_SPAWNING,
    OVERLAY_OAM_ID_KRAID,
    OVERLAY_OAM_ID_KRAID_SPAWNING,
    OVERLAY_OAM_ID_NORFAIR,
    OVERLAY_OAM_ID_NORFAIR_SPAWNING,
    OVERLAY_OAM_ID_RIDLEY,
    OVERLAY_OAM_ID_RIDLEY_SPAWNING,
    OVERLAY_OAM_ID_TOURIAN,
    OVERLAY_OAM_ID_TOURIAN_SPAWNING,
    OVERLAY_OAM_ID_CRATERIA,
    OVERLAY_OAM_ID_CRATERIA_SPAWNING,
    OVERLAY_OAM_ID_CHOZODIA,
    OVERLAY_OAM_ID_CHOZODIA_SPAWNING,
    OVERLAY_OAM_ID_R_PROMPT_PRESSED,
    OVERLAY_OAM_ID_L_PROMPT_PRESSED,
    OVERLAY_OAM_ID_SELECT_ON,
    OVERLAY_OAM_ID_SELECT_OFF,
    OVERLAY_OAM_ID_BRINSTAR_OUTLINE,
    OVERLAY_OAM_ID_KRAID_OUTLINE,
    OVERLAY_OAM_ID_NORFAIR_OUTLINE,
    OVERLAY_OAM_ID_RIDLEY_OUTLINE,
    OVERLAY_OAM_ID_TOURIAN_OUTLINE,
    OVERLAY_OAM_ID_CRATERIA_OUTLINE,
    OVERLAY_OAM_ID_CHOZODIA_OUTLINE,
    OVERLAY_OAM_ID_CHOZO_HINT_BRINSTAR,
    OVERLAY_OAM_ID_CHOZO_HINT_KRAID,
    OVERLAY_OAM_ID_CHOZO_HINT_NORFAIR,
    OVERLAY_OAM_ID_CHOZO_HINT_RIDLEY,
    OVERLAY_OAM_ID_CHOZO_HINT_TOURIAN,
    OVERLAY_OAM_ID_CHOZO_HINT_CRATERIA,
    OVERLAY_OAM_ID_CHOZO_HINT_CHOZODIA,

    OVERLAY_OAM_ID_END
};

enum BorderArrowOamId {
    BORDER_ARROW_OAM_ID_UP = 1,
    BORDER_ARROW_OAM_ID_DOWN,
    BORDER_ARROW_OAM_ID_LEFT,
    BORDER_ARROW_OAM_ID_RIGHT,

    BORDER_ARROW_OAM_ID_END
};

enum SamusIconOamId {
    SAMUS_ICON_OAM_ID_SUIT = 1,
    SAMUS_ICON_OAM_ID_SUITLESS,

    SAMUS_ICON_OAM_ID_END
};

enum BossIconOamId {
    BOSS_ICON_OAM_ID_KRAID = 1,
    BOSS_ICON_OAM_ID_RIDLEY,
    BOSS_ICON_OAM_ID_CROSSMARK,
    BOSS_ICON_OAM_ID_SHIP,

    BOSS_ICON_OAM_ID_END
};

enum PauseScreenTargetOamId {
    TARGET_OAM_ID_TARGET = 1,
    TARGET_OAM_ID_UP_ARROW,
    TARGET_OAM_ID_DOWN_ARROW,

    TARGET_OAM_GREEN_FLAME_SPAWNING = 8,
    TARGET_OAM_GREEN_FLAME,
    TARGET_OAM_GREEN_FLAME_MOVING,

    TARGET_OAM_PURPLE_FLAME_SPAWNING = 12,
    TARGET_OAM_PURPLE_FLAME,
    TARGET_OAM_PURPLE_FLAME_MOVING,

    TARGET_OAM_END = 16
};

enum WorldMapOamId {
    WORLD_MAP_OAM_ID_NAME_BRINSTAR = 1,
    WORLD_MAP_OAM_ID_NAME_KRAID,
    WORLD_MAP_OAM_ID_NAME_NORFAIR,
    WORLD_MAP_OAM_ID_NAME_RIDLEY,
    WORLD_MAP_OAM_ID_NAME_TOURIAN,
    WORLD_MAP_OAM_ID_NAME_CRATERIA,
    WORLD_MAP_OAM_ID_NAME_CHOZODIA,
    WORLD_MAP_OAM_ID_OUTLINED_BRINSTAR,
    WORLD_MAP_OAM_ID_OUTLINED_KRAID,
    WORLD_MAP_OAM_ID_OUTLINED_NORFAIR,
    WORLD_MAP_OAM_ID_OUTLINED_RIDLEY,
    WORLD_MAP_OAM_ID_OUTLINED_TOURIAN,
    WORLD_MAP_OAM_ID_OUTLINED_CRATERIA,
    WORLD_MAP_OAM_ID_OUTLINED_CHOZODIA,
    WORLD_MAP_OAM_ID_TARGET,
    WORLD_MAP_OAM_ID_SAMUS_ICON_SUIT,
    WORLD_MAP_OAM_ID_SAMUS_ICON_SUITLESS,

    WORLD_MAP_OAM_ID_END
};

#endif
