#include "data/sprites/item_banner.h"
#include "macros.h"

const u32 sItemBannerGfx[139] = INCBIN_U32("data/sprites/ItemBanner.gfx.lz");
const u16 sItemBannerPal[32] = INCBIN_U16("data/sprites/ItemBanner.pal");

const u16 sSaveYesNoCursorOAM_Idle_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x21e
};

const u16 sSaveYesNoCursorOAM_Idle_Frame1[4] = {
    0x1,
    0xfc, 0x1fd, OBJ_SPRITE_OAM | 0x21e
};

const u16 sSaveYesNoCursorOAM_Idle_Frame2[4] = {
    0x1,
    0xfc, 0x1fe, OBJ_SPRITE_OAM | 0x21e
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, OBJ_SPRITE_OAM | 0x25c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, OBJ_SPRITE_OAM | 0x25c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame2[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x28, OBJ_SPRITE_OAM | 0x25c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame3[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1a8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x48, OBJ_SPRITE_OAM | 0x25c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame4[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x188, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1a8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x48, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x68, OBJ_SPRITE_OAM | 0x25c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame5[49] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x264,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x268,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x26c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x270,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x274,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x278,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21f
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame6[49] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x264,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x268,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x26c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x270,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x274,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x278,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame7[61] = {
    0x14,
    0xf6, 0x188, OBJ_SPRITE_OAM | 0x21c,
    0x2, 0x188, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x248,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x250,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x258,
    0xf6, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c,
    0x2, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame8[61] = {
    0x14,
    0xf4, 0x188, OBJ_SPRITE_OAM | 0x21c,
    0x4, 0x188, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x248,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x250,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x258,
    0xf4, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c,
    0x4, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame9[61] = {
    0x14,
    0xf2, 0x188, OBJ_SPRITE_OAM | 0x21c,
    0x6, 0x188, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x248,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x250,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x258,
    0xf2, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c,
    0x6, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d
};

const u16 sItemBannerOAM_TwoLinesStatic_Frame0[31] = {
    0xa,
    0xf0, 0x188, OBJ_SPRITE_OAM | 0x21c,
    0x8, 0x188, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x10, OBJ_SPRITE_OAM | 0x210,
    0xf0, OBJ_SIZE_32x32 | 0x50, OBJ_SPRITE_OAM | 0x218,
    0xf0, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c,
    0x8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d
};

const u16 sItemBannerOAM_OneLineSpawn_Frame5[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x188, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1a8, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c8, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x48, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x68, OBJ_SPRITE_OAM | 0x27c
};

const u16 sItemBannerOAM_OneLineSpawn_Frame6[55] = {
    0x12,
    0xfa, 0x188, OBJ_SPRITE_OAM | 0x21f,
    0xfa, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x264,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x268,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x26c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x270,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x274,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x278,
    0xfe, 0x188, OBJ_SPRITE_OAM | 0x23f,
    0xfe, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x23f
};

const u16 sItemBannerOAM_OneLineSpawn_Frame7[49] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x234,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21f
};

const u16 sItemBannerOAM_OneLineStatic_Frame0[49] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x234,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c
};

const struct FrameData sSaveYesNoCursorOAM_Idle[5] = {
    sSaveYesNoCursorOAM_Idle_Frame0,
    0x8,
    sSaveYesNoCursorOAM_Idle_Frame1,
    0x4,
    sSaveYesNoCursorOAM_Idle_Frame2,
    0x8,
    sSaveYesNoCursorOAM_Idle_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sItemBannerOAM_TwoLinesSpawn[11] = {
    sItemBannerOAM_TwoLinesSpawn_Frame0,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame1,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame2,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame3,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame4,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame5,
    0x2,
    sItemBannerOAM_TwoLinesSpawn_Frame6,
    0x2,
    sItemBannerOAM_TwoLinesSpawn_Frame7,
    0x2,
    sItemBannerOAM_TwoLinesSpawn_Frame8,
    0x3,
    sItemBannerOAM_TwoLinesSpawn_Frame9,
    0x3,
    NULL,
    0x0
};

const struct FrameData sItemBannerOAM_TwoLinesRemoving[11] = {
    sItemBannerOAM_TwoLinesSpawn_Frame9,
    0x3,
    sItemBannerOAM_TwoLinesSpawn_Frame8,
    0x3,
    sItemBannerOAM_TwoLinesSpawn_Frame7,
    0x2,
    sItemBannerOAM_TwoLinesSpawn_Frame6,
    0x2,
    sItemBannerOAM_TwoLinesSpawn_Frame5,
    0x2,
    sItemBannerOAM_TwoLinesSpawn_Frame4,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame3,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame2,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame1,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame0,
    0x1,
    NULL,
    0x0
};

const struct FrameData sItemBannerOAM_TwoLinesStatic[2] = {
    sItemBannerOAM_TwoLinesStatic_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sItemBannerOAM_OneLineSpawn[9] = {
    sItemBannerOAM_TwoLinesSpawn_Frame0,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame1,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame2,
    0x1,
    sItemBannerOAM_TwoLinesSpawn_Frame3,
    0x2,
    sItemBannerOAM_TwoLinesSpawn_Frame4,
    0x2,
    sItemBannerOAM_OneLineSpawn_Frame5,
    0x2,
    sItemBannerOAM_OneLineSpawn_Frame6,
    0x3,
    sItemBannerOAM_OneLineSpawn_Frame7,
    0x3,
    NULL,
    0x0
};

const struct FrameData sItemBannerOAM_OneLineRemoving[9] = {
    sItemBannerOAM_OneLineSpawn_Frame7,
    3,
    sItemBannerOAM_OneLineSpawn_Frame6,
    3,
    sItemBannerOAM_OneLineSpawn_Frame5,
    2,
    sItemBannerOAM_TwoLinesSpawn_Frame4,
    2,
    sItemBannerOAM_TwoLinesSpawn_Frame3,
    2,
    sItemBannerOAM_TwoLinesSpawn_Frame2,
    1,
    sItemBannerOAM_TwoLinesSpawn_Frame1,
    1,
    sItemBannerOAM_TwoLinesSpawn_Frame0,
    1,
    NULL,
    0
};

const struct FrameData sItemBannerOAM_OneLineStatic[2] = {
    sItemBannerOAM_OneLineStatic_Frame0,
    0xFF,
    NULL,
    0x0
};
