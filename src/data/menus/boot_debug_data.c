#include "data/menus/boot_debug_data.h"
#include "constants/game_state.h"
#include "oam.h"
#include "structs/cutscene.h"

const u8 sEasyHardEventActions[6] = {1, 0, 0, 0, 0, 1};

const u16 sBootDebugBgPal[128] = INCBIN_U16("debug_data/BootDebugBg.pal");
const u16 sBootDebugObjPal[48] = INCBIN_U16("debug_data/BootDebugObj.pal");
const u32 sBootDebugObjGfx[222] = INCBIN_U32("debug_data/BootDebugObj.gfx.lz");

const u16 sBootDebugOam_4185D8_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, 0x0, 0x1000
};

const u16 sBootDebugOam_4185B0_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f6, 0x2044
};

const u16 sBootDebugOam_4185B0_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f7, 0x2044
};

const u16 sBootDebugOam_4185B0_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f8, 0x2044
};

const u16 sBootDebugOam_4185D8_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0x3, 0x0, 0x2065
};

const u16 sBootDebugOam_4185F0_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0x0, 0x1fa, 0x2047,
    0x8, OBJ_Y_FLIP | 0x1fa, 0x2047,
    0x0, OBJ_X_FLIP | 0x34, 0x2047,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x34, 0x2047
};

const u16 sBootDebugOam_418600_Frame0[OAM_DATA_SIZE(45)] = {
    0x2d,
    0x0, 0x0, 0x1031,
    0x0, 0x10, 0x1021,
    0x0, 0x18, 0x1034,
    0x0, 0x20, 0x1033,
    0x0, 0x28, 0x1033,
    0x0, 0x30, 0x102e,
    0x0, 0x38, 0x102d,
    0x8, 0xd, 0x1033,
    0x8, 0x15, 0x1028,
    0x8, 0x1c, 0x1033,
    0x8, 0x24, 0x102b,
    0x8, 0x2c, 0x1024,
    0xff, 0x8, 0x100b,
    0xf8, 0x8, 0x100c,
    0xf8, 0x8, 0x100c,
    0xf8, 0x10, 0x100c,
    0xf8, 0x10, 0x100c,
    0xf8, 0x18, 0x100c,
    0xf8, 0x18, 0x100c,
    0xf8, 0x20, 0x100c,
    0xf8, 0x20, 0x100c,
    0xf8, 0x28, 0x100c,
    0xf8, 0x28, 0x100c,
    0xf8, 0x30, 0x100c,
    0xf8, 0x30, 0x100c,
    0x10, OBJ_Y_FLIP | 0x8, 0x100c,
    0x10, OBJ_Y_FLIP | 0x8, 0x100c,
    0x10, OBJ_Y_FLIP | 0x10, 0x100c,
    0x10, OBJ_Y_FLIP | 0x10, 0x100c,
    0x10, OBJ_Y_FLIP | 0x18, 0x100c,
    0x10, OBJ_Y_FLIP | 0x18, 0x100c,
    0x10, OBJ_Y_FLIP | 0x20, 0x100c,
    0x10, OBJ_Y_FLIP | 0x20, 0x100c,
    0x10, OBJ_Y_FLIP | 0x28, 0x100c,
    0x10, OBJ_Y_FLIP | 0x28, 0x100c,
    0x10, OBJ_Y_FLIP | 0x30, 0x100c,
    0x10, OBJ_Y_FLIP | 0x30, 0x100c,
    0x0, OBJ_X_FLIP | 0x1f8, 0x100e,
    0x8, OBJ_X_FLIP | 0x1f8, 0x100e,
    0x0, 0x40, 0x100e,
    0x8, 0x40, 0x100e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x38, 0x100c,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_Y_FLIP | 0x38, 0x100c,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x100c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x1f8, 0x100c
};

const u16 sBootDebugOam_418610_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfc, 0x1fc, 0x2046,
    0xfc, OBJ_X_FLIP | 0x4, 0x2046,
    0x4, OBJ_Y_FLIP | 0x1fc, 0x2046,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x2046
};

const u16 sBootDebugOam_418610_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfb, 0x1fb, 0x2046,
    0xfb, OBJ_X_FLIP | 0x5, 0x2046,
    0x5, OBJ_Y_FLIP | 0x1fb, 0x2046,
    0x5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, 0x2046
};

const u16 sBootDebugOam_418610_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfa, 0x1fa, 0x2046,
    0xfa, OBJ_X_FLIP | 0x6, 0x2046,
    0x6, OBJ_Y_FLIP | 0x1fa, 0x2046,
    0x6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x6, 0x2046
};

const struct FrameData sBootDebugOam_4185B0[5] = {
   [0] = {
       .pFrame = sBootDebugOam_4185B0_Frame0,
       .timer = CONVERT_SECONDS(0.2f)
   },
   [1] = {
       .pFrame = sBootDebugOam_4185B0_Frame1,
       .timer = CONVERT_SECONDS(0.1f)
   },
   [2] = {
       .pFrame = sBootDebugOam_4185B0_Frame2,
       .timer = CONVERT_SECONDS(0.1f)
   },
   [3] = {
       .pFrame = sBootDebugOam_4185B0_Frame1,
       .timer = CONVERT_SECONDS(0.1f)
   },
   [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBootDebugOam_4185D8[3] = {
   [0] = {
       .pFrame = sBootDebugOam_4185D8_Frame0,
       .timer = CONVERT_SECONDS(1.f / 3)
   },
   [1] = {
       .pFrame = sBootDebugOam_4185D8_Frame1,
       .timer = CONVERT_SECONDS(4.f / 15)
   },
   [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBootDebugOam_4185F0[2] = {
   [0] = {
       .pFrame = sBootDebugOam_4185F0_Frame0,
       .timer = CONVERT_SECONDS(1.f / 15)
   },
   [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBootDebugOam_418600[2] = {
   [0] = {
       .pFrame = sBootDebugOam_418600_Frame0,
       .timer = CONVERT_SECONDS(1.f)
   },
   [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBootDebugOam_418610[5] = {
   [0] = {
       .pFrame = sBootDebugOam_418610_Frame0,
       .timer = CONVERT_SECONDS(4.f / 15)
   },
   [1] = {
       .pFrame = sBootDebugOam_418610_Frame1,
       .timer = CONVERT_SECONDS(2.f / 15)
   },
   [2] = {
       .pFrame = sBootDebugOam_418610_Frame2,
       .timer = CONVERT_SECONDS(0.2f)
   },
   [3] = {
       .pFrame = sBootDebugOam_418610_Frame1,
       .timer = CONVERT_SECONDS(2.f / 15)
   },
   [4] = FRAME_DATA_TERMINATOR
};

const u32 sBootDebugBgGfx[771] = INCBIN_U32("debug_data/BootDebugBg.gfx.lz");

const u8 sBootDebug_CutsceneB_EscapeShip_Text[8] = {0xBA, 0xB6, 0xDE, 0xC0, 0xC3, 0xB2, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_MechaRidley_Text[12] = {0xD2, 0xB6, 0x20, 0xD8, 0xC4, 0xDE, 0xD8, 0xB0, 0x00, 0x00, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_PoweredSuit_Text[12] = {0xCA, 0xDF, 0xDC, 0xB0, 0xC4, 0xDE, 0xBD, 0xB0, 0xC2, 0x00, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_ChozoMural_Text[8] = {0xCD, 0xB7, 0xB6, 0xDE, 0x00, 0x00, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_Metroids_Text[8] = {0xD2, 0xC4, 0xDB, 0xB2, 0xC4, 0xDE, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_RidleyFight_Text[8] = {0xD8, 0xC4, 0xDE, 0xD8, 0xB0, 0x00, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_MotherShipLanding_Text[8] = {0xC1, 0xAC, 0xB8, 0xD8, 0xB8, 0x00, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_MotherShipReturning_Text[12] = {0xCB, 0xB7, 0xB6, 0xB4, 0xBD, 0x20, 0xCE, 0xDE, 0xB6, 0xDD, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_BossStatues_Text[8] = {0xBE, 0xB7, 0xBF, 0xDE, 0xB3, 0x00, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_KraidFight_Text[8] = {0xB8, 0xDA, 0xB2, 0xC4, 0xDE, 0x00, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_MotherBrain_Text[12] = {0xCF, 0xBB, 0xDE, 0xB0, 0x20, 0xCC, 0xDE, 0xDA, 0xB2, 0xDD, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_ShotDownMonologue2_Text[12] = {0x4D, 0x4F, 0x4E, 0x4F, 0xB9, 0xDE, 0xB7, 0xC2, 0xB2, 0x32, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_ShotDownMonologue1_Text[12] = {0x4D, 0x4F, 0x4E, 0x4F, 0xB9, 0xDE, 0xB7, 0xC2, 0xB2, 0x31, 0x00, 0x00};
const u8 sBootDebug_CutsceneB_StartMonologue_Text[12] = {0x4D, 0x4F, 0x4E, 0x4F, 0x20, 0xBD, 0xC0, 0xB0, 0xC4, 0x00, 0x00, 0x00};
const u8 sBootDebug_Cutscene_Blank_Text[12] = "---       \0\0";
const u8 sBootDebug_CutsceneA_ShotDown_Text[8] = {0xB9, 0xDE, 0xB7, 0xC2, 0xB2, 0x00, 0x00, 0x00};
const u8 sBootDebugMenuNames_DebugConfig_Text[12] = "DEBUG CONFIG";
const u8 sBootDebugMenuNames_Section_Text[8] = "SECTION\0";
const u8 sBootDebugMenuNames_Mode_Text[4] = "MODE";
const u8 sBootDebugMenuNames_Save_Text[4] = "SAVE";
const u8 sBootDebugMenuNames_Samus_Text[8] = "SAMUS\0\0\0";
const u8 sBootDebugMenuNames_Sound_Text[8] = "Sound\0\0\0";
const u8 sBootDebugMenuNames_Demo_Text[4] = "DEMO";
const u8 sBootDebugMenuNames_Etc_Text[4] = "etc\0";
const u8 sBootDebugMenuNames_Boot_Text[4] = "boot";
const u8 sBootDebugMenuNames_Erase_Text[8] = "ERASE\0\0\0";
const u8 sBootDebugModeMenu_Language_Text[12] = "LANGUAGE \0\0\0";
const u8 sBootDebugModeMenu_Difficulty_Text[12] = "LEVEL    \0\0\0";
const u8 sBootDebugLanguage_Japanese_Text[8] = "Japanese";
const u8 sBootDebugLanguage_Hiragana_Text[8] = "hiragana";
const u8 sBootDebugLanguage_English_Text[8] = "English ";
const u8 sBootDebugLanguage_German_Text[8] = "German  ";
const u8 sBootDebugLanguage_French_Text[8] = "French  ";
const u8 sBootDebugLanguage_Italian_Text[8] = "Italian ";
const u8 sBootDebugLanguage_Spanish_Text[8] = "Spanish ";
const u8 sBootDebugDifficulty_Easy_Text[8] = "EASY  \0\0";
const u8 sBootDebugDifficulty_Normal_Text[8] = "NORMAL\0\0";
const u8 sBootDebugDifficulty_Hard_Text[8] = "HARD  \0\0";
const u8 sBootDebugSectionMenu_Brinstar_Text[8] = {0xCC, 0xDE, 0xD8, 0xDD, 0xBD, 0xC0, 0x20, 0x20};
const u8 sBootDebugSectionMenu_Kraid_Text[8] = {0xB8, 0xDA, 0xB2, 0xC4, 0xDE, 0x20, 0x20, 0x20};
const u8 sBootDebugSectionMenu_Norfair_Text[8] = {0xC9, 0xD9, 0xCC, 0xAA, 0xB1, 0x20, 0x20, 0x20};
const u8 sBootDebugSectionMenu_Ridley_Text[8] = {0xD8, 0xC4, 0xDE, 0xD8, 0xB0, 0x20, 0x20, 0x20};
const u8 sBootDebugSectionMenu_Tourian_Text[8] = {0xC2, 0xB0, 0xD8, 0xB1, 0xDD, 0x20, 0x20, 0x20};
const u8 sBootDebugSectionMenu_Crateria_Text[8] = {0xB8, 0xDA, 0xC3, 0xD8, 0xB1, 0x20, 0x20, 0x20};
const u8 sBootDebugSectionMenu_Chozodia_Text[8] = {0xC5, 0xDD, 0xCA, 0xDF, 0xBE, 0xDD, 0x20, 0x20};
const u8 sBootDebugSectionMenu_Blank_Text[8] = "        ";
const u8 sBootDebugSectionMenu_Test1_Text[8] = "TEST 1  ";
const u8 sBootDebugSectionMenu_Test2_Text[8] = "TEST 2  ";
const u8 sBootDebugSectionMenu_Test3_Text[8] = "TEST 3  ";
const u8 sBootDebugSectionMenu_Title_Text[8] = "TITLE\0\0\0";
const u8 sBootDebugSectionMenu_SaveA_Text[8] = "SAVE(A)\0";
const u8 sBootDebugSectionMenu_SaveB_Text[8] = "SAVE(B)\0";
const u8 sBootDebugSectionMenu_SaveC_Text[8] = "SAVE(C)\0";
const u8 sBootDebugSectionMenu_Select_Text[8] = "Select\0\0";
const u8 sBootDebugSamusMenu_GetMap_Text[8] = "GetMap\0\0";
const u8 sBootDebugSamusMenu_ArmWeapon_Text[8] = "H-SHOT\0\0";
const u8 sBootDebugSamusMenu_DiagonalAim_Text[8] = {0xC5, 0xC5, 0xD2, 0x2D, 0x53, 0x48, 0x4F, 0x54};
const u8 sBootDebugSamusMenu_Pause_Text[8] = "PAUSE\0\0\0";
const u8 sBootDebugSamusMenu_SwapMissiles_Text[4] = {0xD0, 0xBB, 0xB2, 0xD9};
const u8 sBootDebug_LButton_Text[8] = "L-Button";
const u8 sBootDebug_RButton_Text[8] = "R-Button";
const u8 sBootDebug_Start_Text[8] = "START \0\0";
const u8 sBootDebug_Select_Text[8] = "SELECT\0\0";
const u8 sBootDebugSaveMenu_GalleryImages_Text[20] = "POSTER   12345678\0\0\0";
const u8 sBootDebugSaveMenu_DifficultiesCleared_Text[20] = "ClearLevel  e/n/h\0\0\0";
const u8 sBootDebugSaveMenu_LinkedWithFusion_Text[16] = "Fusion   yes/no\0";
const u8 sBootDebugSaveMenu_Id_Text[20] = "ID       --------\0\0\0";
const u8 sBootDebugSaveMenu_Save_Text[4] = "SAVE";
const u8 sBootDebugSoundMenu_Bgm_Text[4] = "BGM\0";
const u8 sBootDebugSoundMenu_Test_Text[4] = "TEST";
const u8 sBootDebugSoundMenu_Mono_Text[4] = {0xD3, 0xC9, 0xD7, 0xD9};
const u8 sBootDebugSoundMenu_Stereo_Text[4] = {0xBD, 0xC3, 0xDA, 0xB5};
const u8 sBootDebugDemoMenu_CutsceneSwitch_Text[8] = "DEMO SW\0";
const u8 sBootDebugDemoMenu_CutsceneA_Text[8] = "DEMO(A)\0";
const u8 sBootDebugDemoMenu_CutsceneB_Text[8] = "DEMO(B)\0";
const u8 sBootDebugDemoMenu_DemoMode_Text[12] = {0xB5, 0xB0, 0xC4, 0xC3, 0xDE, 0xD3, 0x4D, 0x4F, 0x44, 0x45, 0x00, 0x00};
const u8 sBootDebugDemoMenu_DemoNum_Text[12] = {0xB5, 0xB0, 0xC4, 0xC3, 0xDE, 0xD3, 0x4E, 0x55, 0x4D, 0x00, 0x00, 0x00};
const u8 sBootDebugEtcMenu_Ending_Text[8] = "Ending\0\0";
const u8 sBootDebugEtcMenu_StaffRoll_Text[12] = "STAFF ROLL\0\0";
const u8 sBootDebugEtcMenu_MainEndObj_Text[12] = "Main-End OBJ";
const u8 sBootDebugEtcMenu_DoorTransition_Text[8] = {0xB9, 0xDE, 0xB0, 0xC4, 0x20, 0xBA, 0xB3, 0xB6};
const u8 sBootDebugEraseMenu_EraseSram_Text[12] = "ERASE SRAM\0\0";
const u8 sBootDebug_On_Text[4] = "ON \0";
const u8 sBootDebug_Off_Text[4] = "OFF\0";
const u8 sBootDebugEraseMenu_Yes_Text[4] = "YES\0";
const u8 sBootDebugEraseMenu_No_Text[4] = "NO \0";

const struct BootDebugText sBootDebugMenuNamesText[10] = {
    [0] = {
        .background = 3,
        .xPosition = 10,
        .yPosition = 0,
        .palette = 13,
        .size = 12,
        .text = sBootDebugMenuNames_DebugConfig_Text
    },
    [BOOT_DEBUG_SUB_MENU_SECTION] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 3,
        .palette = 13,
        .size = 7,
        .text = sBootDebugMenuNames_Section_Text
    },
    [BOOT_DEBUG_SUB_MENU_MODE] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 5,
        .palette = 13,
        .size = 4,
        .text = sBootDebugMenuNames_Mode_Text
    },
    [BOOT_DEBUG_SUB_MENU_SAVE] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 7,
        .palette = 13,
        .size = 4,
        .text = sBootDebugMenuNames_Save_Text
    },
    [BOOT_DEBUG_SUB_MENU_SAMUS] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 9,
        .palette = 13,
        .size = 5,
        .text = sBootDebugMenuNames_Samus_Text
    },
    [BOOT_DEBUG_SUB_MENU_SOUND] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 11,
        .palette = 13,
        .size = 5,
        .text = sBootDebugMenuNames_Sound_Text
    },
    [BOOT_DEBUG_SUB_MENU_DEMO] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 13,
        .palette = 13,
        .size = 4,
        .text = sBootDebugMenuNames_Demo_Text
    },
    [BOOT_DEBUG_SUB_MENU_ETC] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 15,
        .palette = 13,
        .size = 3,
        .text = sBootDebugMenuNames_Etc_Text
    },
    [BOOT_DEBUG_SUB_MENU_BOOT] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 17,
        .palette = 13,
        .size = 4,
        .text = sBootDebugMenuNames_Boot_Text
    },
    [BOOT_DEBUG_SUB_MENU_ERASE] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 19,
        .palette = 13,
        .size = 5,
        .text = sBootDebugMenuNames_Erase_Text
    }
};

const struct BootDebugText sBootDebugSectionMenuText[16] = {
    [BOOT_DEBUG_SECTION_BRINSTAR] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 4,
        .palette = 8,
        .size = 8,
        .text = sBootDebugSectionMenu_Brinstar_Text
    },
    [BOOT_DEBUG_SECTION_KRAID] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 6,
        .palette = 8,
        .size = 8,
        .text = sBootDebugSectionMenu_Kraid_Text
    },
    [BOOT_DEBUG_SECTION_NORFAIR] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 8,
        .palette = 8,
        .size = 8,
        .text = sBootDebugSectionMenu_Norfair_Text
    },
    [BOOT_DEBUG_SECTION_RIDLEY] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 10,
        .palette = 8,
        .size = 8,
        .text = sBootDebugSectionMenu_Ridley_Text
    },
    [BOOT_DEBUG_SECTION_TOURIAN] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 12,
        .palette = 8,
        .size = 8,
        .text = sBootDebugSectionMenu_Tourian_Text
    },
    [BOOT_DEBUG_SECTION_CRATERIA] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 14,
        .palette = 8,
        .size = 8,
        .text = sBootDebugSectionMenu_Crateria_Text
    },
    [BOOT_DEBUG_SECTION_CHOZODIA] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 16,
        .palette = 8,
        .size = 8,
        .text = sBootDebugSectionMenu_Chozodia_Text
    },
    [BOOT_DEBUG_SECTION_BLANK] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 18,
        .palette = 15,
        .size = 8,
        .text = sBootDebugSectionMenu_Blank_Text
    },
    [BOOT_DEBUG_SECTION_TEST_1] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 4,
        .palette = 8,
        .size = 8,
        .text = sBootDebugSectionMenu_Test1_Text
    },
    [BOOT_DEBUG_SECTION_TEST_2] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 6,
        .palette = 8,
        .size = 8,
        .text = sBootDebugSectionMenu_Test2_Text
    },
    [BOOT_DEBUG_SECTION_TEST_3] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 8,
        .palette = 8,
        .size = 8,
        .text = sBootDebugSectionMenu_Test3_Text
    },
    [BOOT_DEBUG_SECTION_TITLE] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 10,
        .palette = 10,
        .size = 5,
        .text = sBootDebugSectionMenu_Title_Text
    },
    [BOOT_DEBUG_SECTION_SAVE_A] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 12,
        .palette = 8,
        .size = 7,
        .text = sBootDebugSectionMenu_SaveA_Text
    },
    [BOOT_DEBUG_SECTION_SAVE_B] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 14,
        .palette = 8,
        .size = 7,
        .text = sBootDebugSectionMenu_SaveB_Text
    },
    [BOOT_DEBUG_SECTION_SAVE_C] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 16,
        .palette = 8,
        .size = 7,
        .text = sBootDebugSectionMenu_SaveC_Text
    },
    [15] = {
        .background = 2,
        .xPosition = 11,
        .yPosition = 2,
        .palette = 9,
        .size = 6,
        .text = sBootDebugSectionMenu_Select_Text
    }
};

const struct BootDebugText sBootDebugModeMenuText[2] = {
    [BOOT_DEBUG_MODE_LANGUAGE] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = 8,
        .size = 9,
        .text = sBootDebugModeMenu_Language_Text
    },
    [BOOT_DEBUG_MODE_DIFFICULTY] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = 8,
        .size = 9,
        .text = sBootDebugModeMenu_Difficulty_Text
    }
};

const struct BootDebugText sBootDebugLanguageText[7] = {
    [LANGUAGE_JAPANESE] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = 9,
        .size = 8,
        .text = sBootDebugLanguage_Japanese_Text
    },
    [LANGUAGE_HIRAGANA] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = 12,
        .size = 8,
        .text = sBootDebugLanguage_Hiragana_Text
    },
    [LANGUAGE_ENGLISH] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = 10,
        .size = 8,
        .text = sBootDebugLanguage_English_Text
    },
    [LANGUAGE_GERMAN] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = 10,
        .size = 8,
        .text = sBootDebugLanguage_German_Text
    },
    [LANGUAGE_FRENCH] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = 10,
        .size = 8,
        .text = sBootDebugLanguage_French_Text
    },
    [LANGUAGE_ITALIAN] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = 10,
        .size = 8,
        .text = sBootDebugLanguage_Italian_Text
    },
    [LANGUAGE_SPANISH] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = 10,
        .size = 8,
        .text = sBootDebugLanguage_Spanish_Text
    }
};

const struct BootDebugText sBootDebugDifficultyText[3] = {
    [DIFF_EASY] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 5,
        .palette = 12,
        .size = 6,
        .text = sBootDebugDifficulty_Easy_Text
    },
    [DIFF_NORMAL] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 5,
        .palette = 10,
        .size = 6,
        .text = sBootDebugDifficulty_Normal_Text
    },
    [DIFF_HARD] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 5,
        .palette = 9,
        .size = 6,
        .text = sBootDebugDifficulty_Hard_Text
    }
};

const struct BootDebugText sBootDebugSaveMenuText[5] = {
    [BOOT_DEBUG_SAVE_GALLERY_IMAGES] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = 8,
        .size = 17,
        .text = sBootDebugSaveMenu_GalleryImages_Text
    },
    [BOOT_DEBUG_SAVE_DIFFICULTIES_CLEARED] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = 8,
        .size = 17,
        .text = sBootDebugSaveMenu_DifficultiesCleared_Text
    },
    [BOOT_DEBUG_SAVE_LINKED_WITH_FUSION] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 7,
        .palette = 8,
        .size = 15,
        .text = sBootDebugSaveMenu_LinkedWithFusion_Text
    },
    [BOOT_DEBUG_SAVE_ID] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 9,
        .palette = 8,
        .size = 17,
        .text = sBootDebugSaveMenu_Id_Text
    },
    [BOOT_DEBUG_SAVE_SAVE] = {
        .background = 2,
        .xPosition = 2,
        .yPosition = 11,
        .palette = 15,
        .size = 4,
        .text = sBootDebugSaveMenu_Save_Text
    }
};

const struct BootDebugText sBootDebugSamusMenuText[5] = {
    [BOOT_DEBUG_SAMUS_GET_MAP] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = 8,
        .size = 6,
        .text = sBootDebugSamusMenu_GetMap_Text
    },
    [BOOT_DEBUG_SAMUS_ARM_WEAPON] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = 8,
        .size = 6,
        .text = sBootDebugSamusMenu_ArmWeapon_Text
    },
    [BOOT_DEBUG_SAMUS_DIAGONAL_AIM] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 7,
        .palette = 8,
        .size = 8,
        .text = sBootDebugSamusMenu_DiagonalAim_Text
    },
    [BOOT_DEBUG_SAMUS_PAUSE] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 9,
        .palette = 8,
        .size = 5,
        .text = sBootDebugSamusMenu_Pause_Text
    },
    [BOOT_DEBUG_SAMUS_SWAP_MISSILES] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 11,
        .palette = 8,
        .size = 4,
        .text = sBootDebugSamusMenu_SwapMissiles_Text
    }
};

const struct BootDebugText sBootDebugArmWeaponButtonText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 5,
        .palette = 12,
        .size = 8,
        .text = sBootDebug_LButton_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 5,
        .palette = 10,
        .size = 8,
        .text = sBootDebug_RButton_Text
    }
};

const struct BootDebugText sBootDebugDiagonalAimButtonText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 7,
        .palette = 12,
        .size = 8,
        .text = sBootDebug_LButton_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 7,
        .palette = 10,
        .size = 8,
        .text = sBootDebug_RButton_Text
    }
};

const struct BootDebugText sBootDebugPauseButtonText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 9,
        .palette = 9,
        .size = 6,
        .text = sBootDebug_Start_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 9,
        .palette = 11,
        .size = 6,
        .text = sBootDebug_Select_Text
    }
};

const struct BootDebugText sBootDebugSwapMissilesButtonText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 11,
        .palette = 9,
        .size = 6,
        .text = sBootDebug_Start_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 11,
        .palette = 11,
        .size = 6,
        .text = sBootDebug_Select_Text
    }
};

const struct BootDebugText sBootDebugSoundMenuText[4] = {
    [0] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = 8,
        .size = 3,
        .text = sBootDebugSoundMenu_Bgm_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = 8,
        .size = 4,
        .text = sBootDebugSoundMenu_Mono_Text
    },
    [2] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 7,
        .palette = 8,
        .size = 4,
        .text = sBootDebugSoundMenu_Test_Text
    },
    [3] = {
        .background = 2,
        .xPosition = 5,
        .yPosition = 5,
        .palette = 8,
        .size = 4,
        .text = sBootDebugSoundMenu_Stereo_Text
    }
};

const struct BootDebugText sBootDebugBgmOnOffText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 6,
        .yPosition = 3,
        .palette = 9,
        .size = 3,
        .text = sBootDebug_On_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 6,
        .yPosition = 3,
        .palette = 11,
        .size = 3,
        .text = sBootDebug_Off_Text
    }
};

const struct BootDebugText sBootDebugDemoMenuText[5] = {
    [BOOT_DEBUG_DEMO_CUTSCENE_SWITCH] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = 8,
        .size = 7,
        .text = sBootDebugDemoMenu_CutsceneSwitch_Text
    },
    [BOOT_DEBUG_DEMO_CUTSCENE_A] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = 8,
        .size = 7,
        .text = sBootDebugDemoMenu_CutsceneA_Text
    },
    [BOOT_DEBUG_DEMO_CUTSCENE_B] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 7,
        .palette = 8,
        .size = 7,
        .text = sBootDebugDemoMenu_CutsceneB_Text
    },
    [BOOT_DEBUG_DEMO_DEMO_MODE] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 11,
        .palette = 8,
        .size = 10,
        .text = sBootDebugDemoMenu_DemoMode_Text
    },
    [BOOT_DEBUG_DEMO_DEMO_NUM] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 13,
        .palette = 8,
        .size = 9,
        .text = sBootDebugDemoMenu_DemoNum_Text
    }
};

const struct BootDebugText sBootDebugDemoOnOffText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 3,
        .palette = 9,
        .size = 3,
        .text = sBootDebug_On_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 3,
        .palette = 11,
        .size = 3,
        .text = sBootDebug_Off_Text
    }
};

const struct BootDebugText sBootDebugEtcMenuText[4] = {
    [BOOT_DEBUG_ETC_ENDING] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = 8,
        .size = 6,
        .text = sBootDebugEtcMenu_Ending_Text
    },
    [BOOT_DEBUG_ETC_STAFF_ROLL] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = 8,
        .size = 10,
        .text = sBootDebugEtcMenu_StaffRoll_Text
    },
    [BOOT_DEBUG_ETC_MAIN_END_OBJ] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 7,
        .palette = 8,
        .size = 12,
        .text = sBootDebugEtcMenu_MainEndObj_Text
    },
    [BOOT_DEBUG_ETC_DOOR_TRANSITION] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 9,
        .palette = 8,
        .size = 8,
        .text = sBootDebugEtcMenu_DoorTransition_Text
    }
};

const struct BootDebugText sBootDebugMainEndObjOnOffText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 14,
        .yPosition = 7,
        .palette = 9,
        .size = 3,
        .text = sBootDebug_On_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 14,
        .yPosition = 7,
        .palette = 11,
        .size = 3,
        .text = sBootDebug_Off_Text
    }
};

const struct BootDebugText sBootDebugDoorTransitionOnOffText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 14,
        .yPosition = 9,
        .palette = 9,
        .size = 3,
        .text = sBootDebug_On_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 14,
        .yPosition = 9,
        .palette = 11,
        .size = 3,
        .text = sBootDebug_Off_Text
    }
};

const struct BootDebugText sBootDebugEraseMenuText[3] = {
    [0] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = 12,
        .size = 10,
        .text = sBootDebugEraseMenu_EraseSram_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 2,
        .yPosition = 5,
        .palette = 8,
        .size = 3,
        .text = sBootDebugEraseMenu_No_Text
    },
    [2] = {
        .background = 2,
        .xPosition = 2,
        .yPosition = 7,
        .palette = 8,
        .size = 3,
        .text = sBootDebugEraseMenu_Yes_Text
    }
};

const u8 sBootDebug_DemoState_RomRun_Text[8] = "ROMRUN\0\0";
const u8 sBootDebug_DemoState_RamRun_Text[8] = "RAMRUN\0\0";
const u8 sBootDebug_DemoState_GetKey_Text[8] = "GETKEY\0\0";
const u8 sBootDebug_DemoState_Free_Text[8] = "FREE\0\0\0\0";
const u8 sBootDebug_DemoState_Blank_Text[7] = "      \0";

const u8 sBootDebugSectionCursorMovement[BOOT_DEBUG_SECTION_COUNT][4] = {
    [BOOT_DEBUG_SECTION_BRINSTAR] = {0x08, 0x80, 0x80, 0x01},
    [BOOT_DEBUG_SECTION_KRAID] = {0x09, 0x80, 0x00, 0x02},
    [BOOT_DEBUG_SECTION_NORFAIR] = {0x0A, 0x80, 0x01, 0x03},
    [BOOT_DEBUG_SECTION_RIDLEY] = {0x0B, 0x80, 0x02, 0x04},
    [BOOT_DEBUG_SECTION_TOURIAN] = {0x0C, 0x80, 0x03, 0x05},
    [BOOT_DEBUG_SECTION_CRATERIA] = {0x0D, 0x80, 0x04, 0x06},
    [BOOT_DEBUG_SECTION_CHOZODIA] = {0x0E, 0x80, 0x05, 0x80},
    [BOOT_DEBUG_SECTION_BLANK] = {0x80, 0x80, 0x06, 0x80},
    [BOOT_DEBUG_SECTION_TEST_1] = {0x80, 0x00, 0x80, 0x09},
    [BOOT_DEBUG_SECTION_TEST_2] = {0x80, 0x01, 0x08, 0x0A},
    [BOOT_DEBUG_SECTION_TEST_3] = {0x80, 0x02, 0x09, 0x0B},
    [BOOT_DEBUG_SECTION_TITLE] = {0x80, 0x03, 0x0A, 0x0C},
    [BOOT_DEBUG_SECTION_SAVE_A] = {0x80, 0x04, 0x0B, 0x0D},
    [BOOT_DEBUG_SECTION_SAVE_B] = {0x80, 0x05, 0x0C, 0x0E},
    [BOOT_DEBUG_SECTION_SAVE_C] = {0x80, 0x06, 0x0D, 0x80}
};

const struct OamArray sBootDebugOam[6] = {
    [0] = {
        .pOam = sBootDebugOam_4185B0,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [1] = {
        .pOam = sBootDebugOam_4185B0,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [2] = {
        .pOam = sBootDebugOam_4185D8,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [3] = {
        .pOam = sBootDebugOam_4185F0,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [4] = {
        .pOam = sBootDebugOam_418600,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [5] = {
        .pOam = sBootDebugOam_418610,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
};

const u8 sZeroSaveText[8] = "ZEROSAVE";

const u8* sBootDebugCutsceneBTextPointers[15] = {
    sBootDebug_Cutscene_Blank_Text,
    sBootDebug_CutsceneB_StartMonologue_Text,
    sBootDebug_CutsceneB_ShotDownMonologue1_Text,
    sBootDebug_CutsceneB_ShotDownMonologue2_Text,
    sBootDebug_CutsceneB_MotherBrain_Text,
    sBootDebug_CutsceneB_KraidFight_Text,
    sBootDebug_CutsceneB_BossStatues_Text,
    sBootDebug_CutsceneB_MotherShipReturning_Text,
    sBootDebug_CutsceneB_MotherShipLanding_Text,
    sBootDebug_CutsceneB_RidleyFight_Text,
    sBootDebug_CutsceneB_Metroids_Text,
    sBootDebug_CutsceneB_ChozoMural_Text,
    sBootDebug_CutsceneB_PoweredSuit_Text,
    sBootDebug_CutsceneB_MechaRidley_Text,
    sBootDebug_CutsceneB_EscapeShip_Text
};

const u8* sBootDebugCutsceneATextPointers[2] = {
    sBootDebug_Cutscene_Blank_Text,
    sBootDebug_CutsceneA_ShotDown_Text
};

const u8* sBootDebugDemoStateTextPointers[5] = {
    sBootDebug_DemoState_Blank_Text,
    sBootDebug_DemoState_Free_Text,
    sBootDebug_DemoState_GetKey_Text,
    sBootDebug_DemoState_RamRun_Text,
    sBootDebug_DemoState_RomRun_Text
};

extern const u8 sBootDebugTextToggleColors[2][2] = {
    [0] = {0xF, 0xC},
    [1] = {0xC, 0xF}
};
