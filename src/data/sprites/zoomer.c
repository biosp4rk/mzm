#include "data/sprites/zoomer.h"
#include "macros.h"

const u32 sZoomerGfx[379] = INCBIN_U32("data/sprites/Zoomer.gfx.lz");
const u16 sZoomerPal[32] = INCBIN_U16("data/sprites/Zoomer.pal");

static const u16 sZoomerOam_Falling_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xee, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xee, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x20f,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x20f
};

static const u16 sZoomerOam_Falling_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xef, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xef, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x210
};

static const u16 sZoomerOam_Falling_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x22f,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x22f
};

static const u16 sZoomerOam_OnGround_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xef, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f4, OBJ_SPRITE_OAM | 0x207,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x227
};

static const u16 sZoomerOam_OnGround_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xee, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xee, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x228
};

static const u16 sZoomerOam_OnGround_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xef, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0xef, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x227,
    0xf8, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x207
};

static const u16 sZoomerOam_OnGround_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x228,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x208
};

static const u16 sZoomerOam_TurningEdgeLeft_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf5, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1f7, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xf5, 0x7, OBJ_SPRITE_OAM | 0x21b
};

static const u16 sZoomerOam_TurningEdgeLeft_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1fb, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xf8, 0xb, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sZoomerOam_TurningEdgeLeft_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf1, 0x1fa, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf9, 0xa, OBJ_SPRITE_OAM | 0x21d
};

static const u16 sZoomerOam_OnWall_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1, OBJ_SPRITE_OAM | 0x239,
    0xf4, 0x0, OBJ_SPRITE_OAM | 0x21e,
    0x1, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x23e
};

static const u16 sZoomerOam_OnWall_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x2, OBJ_SPRITE_OAM | 0x239,
    0xf6, 0x0, OBJ_SPRITE_OAM | 0x21f,
    0x1, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x23f
};

static const u16 sZoomerOam_OnWall_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x20d,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1, OBJ_SPRITE_OAM | 0x239,
    0xf6, 0x0, OBJ_SPRITE_OAM | 0x23e,
    0x3, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x21e
};

static const u16 sZoomerOam_OnWall_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x0, OBJ_SPRITE_OAM | 0x239,
    0xf6, 0x0, OBJ_SPRITE_OAM | 0x23f,
    0x1, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x21f
};

static const u16 sZoomerOam_TurningCornerRight_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf5, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1f7, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xf5, 0x7, OBJ_SPRITE_OAM | 0x21b
};

static const u16 sZoomerOam_TurningCornerRight_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xeb, 0x1f6, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x6, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sZoomerOam_TurningCornerRight_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xe9, 0x1f5, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x5, OBJ_SPRITE_OAM | 0x21d
};

static const u16 sZoomerOam_TurningCornerLeft_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1fe, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf8, 0xe, OBJ_SPRITE_OAM | 0x21d
};

static const u16 sZoomerOam_TurningCornerLeft_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x0, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x10, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sZoomerOam_TurningCornerLeft_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1ff, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xf8, 0xf, OBJ_SPRITE_OAM | 0x21b
};

static const u16 sZoomerOam_WalkingOnLeftSlope_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x6, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x244,
    0xf6, 0x1f0, OBJ_SPRITE_OAM | 0x243
};

static const u16 sZoomerOam_WalkingOnLeftSlope_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x6, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x246
};

static const u16 sZoomerOam_WalkingOnLeftSlope_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x7, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x248
};

static const u16 sZoomerOam_WalkingOnLeftSlope_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x7, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x24a
};

static const u16 sZoomerOam_WalkingOnRightSlope_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x244,
    0xf6, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x243
};

static const u16 sZoomerOam_WalkingOnRightSlope_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x246
};

static const u16 sZoomerOam_WalkingOnRightSlope_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f1, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x248
};

static const u16 sZoomerOam_WalkingOnRightSlope_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1f1, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x24a
};

const struct FrameData sZoomerOam_Falling[5] = {
    [0] = {
        .pFrame = sZoomerOam_Falling_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZoomerOam_Falling_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZoomerOam_Falling_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZoomerOam_Falling_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_OnGround[5] = {
    [0] = {
        .pFrame = sZoomerOam_OnGround_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZoomerOam_OnGround_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZoomerOam_OnGround_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZoomerOam_OnGround_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_TurningEdgeLeft[4] = {
    [0] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_TurningEdgeRight[4] = {
    [0] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_OnWall[5] = {
    [0] = {
        .pFrame = sZoomerOam_OnWall_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZoomerOam_OnWall_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZoomerOam_OnWall_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZoomerOam_OnWall_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_TurningCornerRight[4] = {
    [0] = {
        .pFrame = sZoomerOam_TurningCornerRight_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZoomerOam_TurningCornerRight_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZoomerOam_TurningCornerRight_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_TurningCornerLeft[4] = {
    [0] = {
        .pFrame = sZoomerOam_TurningCornerLeft_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZoomerOam_TurningCornerLeft_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZoomerOam_TurningCornerLeft_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_WalkingOnLeftSlope[5] = {
    [0] = {
        .pFrame = sZoomerOam_WalkingOnLeftSlope_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZoomerOam_WalkingOnLeftSlope_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZoomerOam_WalkingOnLeftSlope_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZoomerOam_WalkingOnLeftSlope_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_WalkingOnRightSlope[5] = {
    [0] = {
        .pFrame = sZoomerOam_WalkingOnRightSlope_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZoomerOam_WalkingOnRightSlope_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZoomerOam_WalkingOnRightSlope_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZoomerOam_WalkingOnRightSlope_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};
