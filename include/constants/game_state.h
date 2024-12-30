#ifndef GAME_STATE_CONSTANTS_H
#define GAME_STATE_CONSTANTS_H

enum GameMode {
    GM_SOFTRESET,
    GM_INTRO,
    GM_TITLE,
    GM_FILE_SELECT,
    GM_INGAME,
    GM_MAP_SCREEN,
    GM_GAMEOVER,
    GM_CHOZODIA_ESCAPE,
    GM_CREDITS,
    GM_TOURIAN_ESCAPE,
    GM_CUTSCENE,
    GM_DEMO,
    GM_GALLERY,
    GM_FUSION_GALLERY,
    GM_START_SOFTRESET,
    GM_ERASE_SRAM,
    GM_DEBUG_MENU
};

enum Difficulty {
    DIFF_EASY,
    DIFF_NORMAL,
    DIFF_HARD,

    DIFF_END
};

enum Language {
    LANGUAGE_JAPANESE,
    LANGUAGE_HIRAGANA,
    LANGUAGE_ENGLISH,
    LANGUAGE_GERMAN,
    LANGUAGE_FRENCH,
    LANGUAGE_ITALIAN,
    LANGUAGE_SPANISH,

    LANGUAGE_END
};

enum PauseScreenFlag {
    PAUSE_SCREEN_NONE,
    PAUSE_SCREEN_UNKNOWN_1,
    PAUSE_SCREEN_PAUSE_OR_CUTSCENE,
    PAUSE_SCREEN_UNKNOWN_3,
    PAUSE_SCREEN_CHOZO_HINT,
    PAUSE_SCREEN_MAP_DOWNLOAD,
    PAUSE_SCREEN_ITEM_ACQUISITION,
    PAUSE_SCREEN_SUITLESS_ITEMS,
    PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS,
    PAUSE_SCREEN_UNKNOWN_9,
};

// For in game
enum SubGameMode {
    SUB_GAME_MODE_DOOR_TRANSITION = 1,
    SUB_GAME_MODE_PLAYING,
    SUB_GAME_MODE_LOADING_ROOM,

    SUB_GAME_MODE_DYING = 5,
    SUB_GAME_MODE_FREE_MOVEMENT,
};

#endif /* GAME_STATE_CONSTANTS_H */
