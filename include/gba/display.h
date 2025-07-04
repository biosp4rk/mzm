#ifndef GBA_DISPLAY_H
#define GBA_DISPLAY_H

#include "gba/memory.h"

#define REG_DISPCNT (REG_BASE + 0x000)

#define REG_BG0CNT (REG_BASE + 0x008)
#define REG_BG1CNT (REG_BASE + 0x00A)
#define REG_BG2CNT (REG_BASE + 0x00C)
#define REG_BG3CNT (REG_BASE + 0x00E)

#define REG_BG0HOFS (REG_BASE + 0x010)
#define REG_BG0VOFS (REG_BASE + 0x012)

#define REG_BG1HOFS (REG_BASE + 0x014)
#define REG_BG1VOFS (REG_BASE + 0x016)

#define REG_BG2HOFS (REG_BASE + 0x018)
#define REG_BG2VOFS (REG_BASE + 0x01A)

#define REG_BG3HOFS (REG_BASE + 0x01C)
#define REG_BG3VOFS (REG_BASE + 0x01E)

#define REG_BG2PA (REG_BASE + 0x020)
#define REG_BG2PB (REG_BASE + 0x022)
#define REG_BG2PC (REG_BASE + 0x024)
#define REG_BG2PD (REG_BASE + 0x026)

#define REG_BG2X_L (REG_BASE + 0x028)
#define REG_BG2X_H (REG_BASE + 0x02A)
#define REG_BG2Y_L (REG_BASE + 0x02C)
#define REG_BG2Y_H (REG_BASE + 0x02E)

#define REG_DISPSTAT (REG_BASE + 0x004)
#define REG_WIN0H    (REG_BASE + 0x040)
#define REG_WIN1H    (REG_BASE + 0x042)
#define REG_WIN0V    (REG_BASE + 0x044)
#define REG_WIN1V    (REG_BASE + 0x046)
#define REG_WININ    (REG_BASE + 0x048)
#define REG_WINOUT   (REG_BASE + 0x04A)
#define REG_MOSAIC   (REG_BASE + 0x04C)
#define REG_BLDCNT   (REG_BASE + 0x050)
#define REG_BLDALPHA (REG_BASE + 0x052)
#define REG_BLDY     (REG_BASE + 0x054)

#define DCNT_MODE_1 1
#define DCNT_MODE_2 2
#define DCNT_MODE_3 3
#define DCNT_MODE_4 4
#define DCNT_MODE_5 5

#define DCNT_CGB     (1 << 3)
#define DCNT_PAGE    (1 << 4)
#define DCNT_OAM_HBL (1 << 5)
#define DCNT_OBJ_1D  (1 << 6)
#define DCNT_BLANK   (1 << 7)

#define DCNT_BG0    (1 << 8)
#define DCNT_BG1    (1 << 9)
#define DCNT_BG2    (1 << 10)
#define DCNT_BG3    (1 << 11)
#define DCNT_OBJ    (1 << 12)
#define DCNT_WIN0   (1 << 13)
#define DCNT_WIN1   (1 << 14)
#define DCNT_WINOBJ (1 << 15)

#define DSTAT_IN_VBLANK    (1 << 0)
#define DSTAT_IN_HBLANK    (1 << 1)
#define DSTAT_VCOUNT_MATCH (1 << 2)
#define DSTAT_IF_VBLANK    (1 << 3)
#define DSTAT_IF_HBLANK    (1 << 4)
#define DSTAT_IF_VCOUNT    (1 << 5)

#define BGCNT_HIGH_PRIORITY     0
#define BGCNT_HIGH_MID_PRIORITY 1
#define BGCNT_LOW_MID_PRIORITY  2
#define BGCNT_LOW_PRIORITY      3

#define BGCNT_SIZE_256x256 0
#define BGCNT_SIZE_512x256 1
#define BGCNT_SIZE_256x512 2
#define BGCNT_SIZE_512x512 3

#define BGCNT_MOSAIC          (1 << 6)
#define BGCNT_SCREEN_OVERFLOW (1 << 13)

#define BGCNT_CHAR_BASE_BLOCK_SHIFT 2
#define BGCNT_SCREEN_BASE_BLOCK_SHIFT 8
#define BGCNT_SCREEN_SIZE_SHIFT 14

#define BGCNT_VRAM_CHAR_SIZE 0x4000
#define BGCNT_VRAM_TILE_SIZE 0x800

#define BGCNT_TO_VRAM_CHAR_BASE(val) (VRAM_BASE + (val) * BGCNT_VRAM_CHAR_SIZE)
#define BGCNT_TO_VRAM_TILE_BASE(val) (VRAM_BASE + (val) * BGCNT_VRAM_TILE_SIZE)

#define BGCNT_GET_PRIORITY(val) ((val) & 3)

#define CREATE_BGCNT(charBase, screenBase, prio, size) ((size) << BGCNT_SCREEN_SIZE_SHIFT | (screenBase) << BGCNT_SCREEN_BASE_BLOCK_SHIFT | (charBase) << BGCNT_CHAR_BASE_BLOCK_SHIFT | (prio))

#define BLDCNT_BG0_FIRST_TARGET_PIXEL       (1 << 0)
#define BLDCNT_BG1_FIRST_TARGET_PIXEL       (1 << 1)
#define BLDCNT_BG2_FIRST_TARGET_PIXEL       (1 << 2)
#define BLDCNT_BG3_FIRST_TARGET_PIXEL       (1 << 3)
#define BLDCNT_OBJ_FIRST_TARGET_PIXEL       (1 << 4)
#define BLDCNT_BACKDROP_FIRST_TARGET_PIXEL  (1 << 5)
#define BLDCNT_ALPHA_BLENDING_EFFECT        (1 << 6)
#define BLDCNT_BRIGHTNESS_INCREASE_EFFECT   (1 << 7)
#define BLDCNT_BG0_SECOND_TARGET_PIXEL      (1 << 8)
#define BLDCNT_BG1_SECOND_TARGET_PIXEL      (1 << 9)
#define BLDCNT_BG2_SECOND_TARGET_PIXEL      (1 << 10)
#define BLDCNT_BG3_SECOND_TARGET_PIXEL      (1 << 11)
#define BLDCNT_OBJ_SECOND_TARGET_PIXEL      (1 << 12)
#define BLDCNT_BACKDROP_SECOND_TARGET_PIXEL (1 << 13)

#define BLDCNT_SCREEN_FIRST_TARGET (BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL)
#define BLDCNT_SCREEN_SECOND_TARGET (BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL)
#define BLDCNT_BRIGHTNESS_DECREASE_EFFECT (BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT)

#define BLDY_MAX_VALUE 16
#define BLDALPHA_MAX_VALUE 16

#define WIN0_BG0          (1 << 0)
#define WIN0_BG1          (1 << 1)
#define WIN0_BG2          (1 << 2)
#define WIN0_BG3          (1 << 3)
#define WIN0_OBJ          (1 << 4)
#define WIN0_COLOR_EFFECT (1 << 5)
#define WIN1_BG0          (1 << 8)
#define WIN1_BG1          (1 << 9)
#define WIN1_BG2          (1 << 10)
#define WIN1_BG3          (1 << 11)
#define WIN1_OBJ          (1 << 12)
#define WIN1_COLOR_EFFECT (1 << 13)

#define WIN0_ALL_NO_COLOR_EFFECT (WIN0_BG0 | WIN0_BG1 | WIN0_BG2 | WIN0_BG3 | WIN0_OBJ)
#define WIN0_ALL (WIN0_BG0 | WIN0_BG1 | WIN0_BG2 | WIN0_BG3 | WIN0_OBJ | WIN0_COLOR_EFFECT)
#define WIN1_ALL_NO_COLOR_EFFECT (WIN1_BG0 | WIN1_BG1 | WIN1_BG2 | WIN1_BG3 | WIN1_OBJ)
#define WIN1_ALL (WIN1_BG0 | WIN1_BG1 | WIN1_BG2 | WIN1_BG3 | WIN1_OBJ | WIN1_COLOR_EFFECT)

#define PIXEL_DRAW_TIME 4 // cycles
#define HBLANK_PIXEL_COUNT 68
#define VBLANK_LINE_COUNT 68

#define HORIZONTAL_PIXEL_COUNT (SCREEN_SIZE_X + HBLANK_PIXEL_COUNT)
#define VERTICAL_LINE_COUNT (SCREEN_SIZE_Y + VBLANK_LINE_COUNT)

#define HORIZONTAL_DRAW_TIME (HORIZONTAL_PIXEL_COUNT * PIXEL_DRAW_TIME)
#define FRAME_DRAW_CYCLES (VERTICAL_LINE_COUNT * HORIZONTAL_DRAW_TIME)

#define CLOCKRATE (16.f * 1024 * 1024)
#define REFRESH_RATE (CLOCKRATE / FRAME_DRAW_CYCLES)

#define SAMPLES_PER_SECOND(s) (REFRESH_RATE * (s) + 1.f/2)

#endif /* GBA_DISPLAY_H */
