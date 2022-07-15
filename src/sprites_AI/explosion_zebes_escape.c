#include "explosion_zebes_escape.h"
#include "screen_shake.h"
#include "particle.h"
#include "sprite_debris.h"
#include "globals.h"

void ExplosionZebesEscape(void)
{
    u32 rng;
    u32 rng_;
    u32 x_position;
    u32 y_position;
    u8 array_offset;
    u8 variable;
    u32 y_offset;
    u32 x_offset;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.draw_distance_top_offset = 0x1;
        gCurrentSprite.draw_distance_bottom_offset = 0x1;
        gCurrentSprite.draw_distance_horizontal_offset = 0x1;
        gCurrentSprite.hitbox_top_offset = 0x0;
        gCurrentSprite.hitbox_bottom_offset = 0x0;
        gCurrentSprite.hitbox_left_offset = 0x0;
        gCurrentSprite.hitbox_right_offset = 0x0;
        gCurrentSprite.samus_collision = SSC_NONE;
        gCurrentSprite.oam_pointer = large_energy_oam_data_2b2750;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.array_offset = 0x7;
        gCurrentSprite.workVariable2 = 0x0;
        gCurrentSprite.y_position_spawn = gCurrentSprite.y_position;
        gCurrentSprite.x_position_spawn = gCurrentSprite.x_position;
        return;
    }

    y_position = gCurrentSprite.y_position_spawn;
    x_position = (u16)(gBG1XPosition + 0x1E0);
    rng = gSpriteRNG;
    rng_ = rng & 0x3;
    array_offset = gCurrentSprite.array_offset;
    gCurrentSprite.array_offset++;
    variable = gCurrentSprite.workVariable2;
    gCurrentSprite.workVariable2++;

    y_position = gCurrentSprite.y_position_spawn;
    if (gSamusData.y_position < (gCurrentSprite.y_position_spawn - 0xA0))
        y_position = (u16)(gSamusData.y_position + 0x64);

    if ((array_offset & 0xF) == 0x0 && rng >= 0x8)
    {
        if ((array_offset & 0x10) != 0x0)
        {
            if (rng >= 0xC)
            {
                if ((rng & 0x1) != 0x0)
                {
                    y_position += (rng * 0x8) - 0xE6;
                    x_position += (rng << rng_);
                    ParticleSet(y_position, x_position, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                    unk_2b20(0x276);
                }
                else
                {
                    y_position += (rng * 0x8) - 0xDC;
                    x_position += (rng << rng_) + 0xA0;
                    ParticleSet(y_position, x_position, PE_SPRITE_EXPLOSION_HUGE);
                    unk_2b20(0xA4);
                }
            }
            else
            {
                if ((rng & 0x1) != 0x0)
                {
                    y_position += (rng * 0x8) - 0xDC;
                    x_position -= (rng << rng_);
                    ParticleSet(y_position, x_position, PE_SPRITE_EXPLOSION_HUGE);
                    unk_2b20(0xA4);
                }
                else
                {
                    y_position += (rng * 0x8) - 0xE6;
                    x_position -= (rng << rng_) + 0xA0;
                    ParticleSet(y_position, x_position, PE_SPRITE_EXPLOSION_BIG);
                    unk_2b20(0x276);
                }
            }
        }
        else
        {
            ScreenShakeStartVertical(0xA, 0x81);
            ScreenShakeStartHorizontal(0xA, 0x81);
            if (rng >= 0xC)
            {
                if ((rng & 0x1) != 0x0)
                {
                    ParticleSet(y_position + (rng * 0x10 - 0x140), x_position + rng << rng_, PE_TWO_MEDIUM_DUST);
                    unk_2b20(0xA5);
                }
                else
                {
                    y_offset = (rng * 0x10) - 0x118;
                    x_offset = rng << rng_;
                }
            }
            else
            {
                y_offset = (rng * 0x10) - 0x168;
                x_offset = (rng << rng_) + 0xC0;
            }

            ParticleSet(y_position + y_offset, x_position + x_offset, PE_MEDIUM_DUST);
            unk_2b20(0x277);
        }
    }

    y_position = (u16)(gBG1YPosition - 0x40);
    if ((variable & 0x1F) == 0x0)
    {
        if ((variable & 0x20) != 0x0)
        {
            SpriteDebrisInit(0x0, 0x5, y_position, x_position - (rng * 0x10) - 0x78);
            SpriteDebrisInit(0x0, 0x8, y_position, x_position + (rng * 0x8) - 0x190);
        }
        else
        {
            SpriteDebrisInit(0x0, 0x7, y_position, x_position - (rng * 0x10) - 0x78);
            SpriteDebrisInit(0x0, 0x5, y_position, x_position + (rng * 0x8) - 0x12C);
        }
    }

    if ((array_offset & 0xF) == 0x0)
    {
        if (rng >= 0x8)
        {
            SpriteDebrisInit(0x0, 0x8, y_position, x_position + (rng * 0x20) - 0x1C2);
            SpriteDebrisInit(0x0, 0x6, y_position, x_position - (rng * 0x20) - 0x24E);
        }
        else
        {
            SpriteDebrisInit(0x0, 0x6, y_position, x_position - (rng * 0x20) - 0x17C);
            SpriteDebrisInit(0x0, 0x8, y_position, x_position + (rng * 0x8) - 0x278);
        }
    }
}