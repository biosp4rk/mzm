#include "samus.h"
#include "sprite.h"
#include "clipdata.h"
#include "music.h"
#include "../data/data.h"
#include "globals.h"

void SamusCheckScrewSpeedboosterAffectingEnvironment(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u8 unk_bool;
    u16 left_hitbox, right_hitbox, top_hitbox;
    u16 hitbox_top_offset;
    u16 y_pos;
    u16 action;

    action = DESTRUCTING_ACTION_NONE;
    if ((pData->pose == SPOSE_SCREW_ATTACKING) ||
        ((pData->pose == SPOSE_STARTING_SPIN_JUMP &&
        ((gEquipment.suit_misc_activation & SMF_SCREW_ATTACK) != 0x0))))
    {
        action = DESTRUCTING_ACTION_SCREW;
    }
    if (pData->speedboosting_shinesparking)
    {
        action += DESTRUCTING_ACTION_SPEED;
    }
    
    if (action != DESTRUCTING_ACTION_NONE)
    {
#ifndef NONMATCHING
        register u16 tmp_y_pos asm("r3");
        register u16 tmp_top_hitbox asm("r0");
#endif // NONMATCHING

        left_hitbox = pData->x_position + pPhysics->hitbox_left_offset;
        right_hitbox = pData->x_position + pPhysics->hitbox_right_offset;

        hitbox_top_offset = pPhysics->hitbox_top_offset;
#ifndef NONMATCHING
        tmp_y_pos = pData->y_position;
        tmp_top_hitbox = tmp_y_pos + hitbox_top_offset;
        top_hitbox = tmp_top_hitbox;
#else // NONMATCHING
        top_hitbox = pData->y_position + hitbox_top_offset;
#endif // NONMATCHING

        y_pos = (u16)pData->y_position;
        unk_bool = hitbox_top_offset << 0x10 < -0x400000;

        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(left_hitbox,  top_hitbox,  action);
        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(right_hitbox,  top_hitbox,  action);
        if (pPhysics->horizontal_moving_direction == HDMOVING_RIGHT)
        {
            if (unk_bool)
            {
                BlockSamusApplyScrewSpeedboosterDamageToEnvironment(right_hitbox,  top_hitbox + 0x40,  action);
            }
            BlockSamusApplyScrewSpeedboosterDamageToEnvironment(right_hitbox,  y_pos,  action);
        }
        else
        {
            if (unk_bool)
            {
                BlockSamusApplyScrewSpeedboosterDamageToEnvironment(left_hitbox,  top_hitbox + 0x40,  action);
            }
            BlockSamusApplyScrewSpeedboosterDamageToEnvironment(left_hitbox,  y_pos,  action);
        }
        if (pPhysics->standing_status == STANDING_GROUND)
        {
            y_pos = y_pos + 1;
            action = 4;
        }
        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(left_hitbox, y_pos, action);
        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(right_hitbox, y_pos, action);
    }
}

u8 SamusSlopeRelated(u16 x_position, u16 y_position, u16* next_x_position, u16* next_y_position, u16* next_slope_type)
{
    u32 clipdata;
    u16 slope_type;
    u16 next_x_pos, next_y_pos;
    u8 collision;

    u32 x_slope_offset;
    u16 x_begin;

#ifndef NONMATCHING
    register vu16* x_ptr asm("r2");
    register i32 x_begin__ asm("r1");
    register i32 mask_FFC0 asm("r3");
    register i32 tmp_next_x_pos asm("r1");
#else
    i32 x_begin__;
    i32 mask_FFC0;
    i32 tmp_next_x_pos;
#endif // NONMATCHING

    clipdata = process_clipdata_for_samus(y_position, x_position);
    collision = (-(clipdata & 0x1000000) >> 0x1F);

    switch (clipdata & 0xFF)
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            next_y_pos = ((y_position & 0xFFC0) + 0x3F) - (x_position & 0x3F);
            next_x_pos = ((x_position & 0xFFC0) + 0x3F) - (y_position & 0x3F);

            slope_type = SLOPE_STEEP | SLOPE_LEFT;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            next_y_pos = ((y_position & 0xFFC0) + 0x3F) - ((x_position & 0x3F) / 2);
            x_begin = x_position & 0xFFC0;

            x_slope_offset = (y_position & 0x3F) * 2 - 0x7E;
            tmp_next_x_pos = x_begin - x_slope_offset;
            next_x_pos = tmp_next_x_pos;

            slope_type = SLOPE_SLIGHT | SLOPE_LEFT;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            next_y_pos = ((y_position & 0xFFC0) + 0x1F) - ((x_position & 0x3F) / 2);
            x_begin = x_position & 0xFFC0;

            x_slope_offset = (y_position & 0x3F) * 2 - 0x3E;
            tmp_next_x_pos = x_begin - x_slope_offset;
            next_x_pos = tmp_next_x_pos;

            slope_type = SLOPE_SLIGHT | SLOPE_LEFT;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            next_y_pos = (y_position & 0xFFC0) | (x_position & 0x3F);
            next_x_pos = (x_position & 0xFFC0) | (y_position & 0x3F);

            slope_type = SLOPE_STEEP | SLOPE_RIGHT;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            mask_FFC0 = 0xFFC0;
            next_y_pos = (y_position & mask_FFC0) | ((x_position & 0x3F) / 2 + 0x1F);
            x_begin__ = x_position & mask_FFC0;

            x_slope_offset = (y_position & 0x3F) * 2 + 0xFFC1;
            next_x_pos = x_begin__ +  x_slope_offset;

            slope_type = SLOPE_SLIGHT | SLOPE_RIGHT;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            mask_FFC0 = 0xFFC0;
            next_y_pos = (y_position & mask_FFC0) | ((x_position & 0x3F) / 2);
            x_begin__ = x_position & mask_FFC0;

            x_slope_offset = (y_position & 0x3F) * 2;
            next_x_pos = x_begin__ + x_slope_offset;

            slope_type = SLOPE_SLIGHT | SLOPE_RIGHT;
            break;

        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            collision = COLLISION_PASS_THROUGH_BOTTOM;
        default:
            next_y_pos = y_position & 0xFFC0;
            next_x_pos = x_position & 0xFFC0;
            slope_type = SLOPE_NONE;
    }
    *next_y_position = next_y_pos;
#ifndef NONMATCHING
    x_ptr = next_x_position;
    *x_ptr =
#else // NONMATCHING
    *pX_position =
#endif // NONMATCHING
        next_x_pos;
    *next_slope_type = slope_type;
    return collision;
}

u8 unk_5604(struct SamusData* pData, struct SamusPhysics* pPhysics, u16 x_position, u16* next_x_position)
{

}

/**
 * @brief 56b8 | dc | Checks for the top sides blocks when jumping
 * 
 * @param pData Samus Data Pointer
 * @param pPhysics Samus Physics Pointer
 * @param x_position X Position
 * @param pPosition Pointer To X Position
 * @return u8 Collision result
 */
u8 SamusCheckTopSideCollisionMidAir(struct SamusData* pData, struct SamusPhysics* pPhysics, u16 x_position, u16* pPosition)
{
    u8 result;
    i32 clip;
    u16 y_pos;

    result = SAMUS_COLLISION_DETECTION_NONE;
    
    if (pPhysics->horizontal_moving_direction == HDMOVING_LEFT)
        *pPosition = (pData->x_position & 0xFFC0) - pPhysics->hitbox_left_offset;
    else
        *pPosition = (pData->x_position & 0xFFC0) - pPhysics->hitbox_right_offset + 0x3F;

    y_pos = pData->y_position;
    clip = ClipdataProcessForSamus(y_pos, x_position);
    if (clip & CLIPDATA_TYPE_SOLID_FLAG)
    {
        switch (clip & 0xFF)
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                result = SAMUS_COLLISION_DETECTION_SLOPE;
                break;

            default:
                result += SAMUS_COLLISION_DETECTION_LEFT_MOST;
        }
    }

    if (result == SAMUS_COLLISION_DETECTION_LEFT_MOST)
    {
        clip = ClipdataProcessForSamus(pData->y_position, pData->x_position);

        switch (clip & 0xFF)
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                result = SAMUS_COLLISION_DETECTION_LEFT_MOST | SAMUS_COLLISION_DETECTION_SLOPE;
        }
    }

    if (pPhysics->hitbox_top_offset < -0x40)
    {
        clip = ClipdataProcessForSamus(y_pos - 0x40, x_position);

        switch (clip & 0xFF)
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                break;

            default:
                if (clip & CLIPDATA_TYPE_SOLID_FLAG)
                    result += SAMUS_COLLISION_DETECTION_MIDDLE_LEFT;
        }
    }

    return result;
}

/**
 * @brief 5794 | 58 | Checks if samus is colliding with a slope when walking
 * 
 * @param pData Samus Data Pointer
 * @param x_position X Position
 * @return u8 Collision result
 */
u8 SamusCheckWalkingOnSlope(struct SamusData* pData, u16 x_position)
{
    u8 result;
    i32 clip;

    result = SAMUS_COLLISION_DETECTION_NONE;
    clip = ClipdataProcessForSamus(pData->y_position, x_position);
    if (clip & CLIPDATA_TYPE_SOLID_FLAG)
    {
        switch (clip & 0xFF)
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                result = SAMUS_COLLISION_DETECTION_SLOPE;
                break;

            default:
                result += SAMUS_COLLISION_DETECTION_LEFT_MOST;
        }
    }

    if (result == SAMUS_COLLISION_DETECTION_LEFT_MOST)
    {
        clip = ClipdataProcessForSamus(pData->y_position, pData->x_position);

        switch (clip & 0xFF)
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                result = SAMUS_COLLISION_DETECTION_LEFT_MOST | SAMUS_COLLISION_DETECTION_SLOPE;
                break;
        }
    }

    return result;
}

u8 SamusCheckCollisionAbove(struct SamusData* pData, i16 hitbox)
{

}

u8 SamusCheckWalkingSidesCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{

}

u8 unk_5AD8(struct SamusData* pData, struct SamusPhysics* pPhysics)
{

}

u8 SamusCheckStandingOnGroundCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{

}

u8 SamusCheckLandingCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{

}

u8 SamusCheckTopCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{

}

void SamusCheckCollisions(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    /*u8 new_pose;
    i16 offset;
    u32 block_prevent;
    u32 block_grabbing;
    u32 block_unk;
    struct CurrentAffectingClip clip;

    if (pPhysics->standing_status > STANDING_NOT_IN_CONTROL)
        return;

    SamusCheckScrewSpeedboosterAffectingEnvironment(pData, pPhysics);

    new_pose = SPOSE_NONE;
    if (pPhysics->vertical_moving_direction == VDMOVING_UP)
        new_pose = SamusCheckTopCollision(pData, pPhysics);
    else if (pPhysics->vertical_moving_direction == VDMOVING_DOWN)
        new_pose = SamusCheckLandingCollision(pData, pPhysics);
    else if (pPhysics->horizontal_moving_direction == HDMOVING_NONE && pPhysics->standing_status == STANDING_GROUND)
        new_pose = SamusCheckStandingOnGroundCollision(pData, pPhysics);
    else if (pPhysics->standing_status == STANDING_MIDAIR)
        new_pose = SamusCheckLandingCollision(pData, pPhysics);
    else
    {
        new_pose = SamusCheckWalkingSidesCollision(pData, pPhysics);
        if (new_pose == SPOSE_NONE)
            new_pose = unk_5AD8(pData, pPhysics);
    }

    if (new_pose == SPOSE_NONE && gEquipment.suit_misc_activation & SMF_POWER_GRIP && gButtonInput & pData->direction && pData->y_velocity < 0x1)
    {
        // Power grip code
        if (pData->direction & KEY_RIGHT)
            offset = 0x1F;
        else
            offset = -0x1F;

        // Block right above
        block_prevent = ClipdataProcessForSamus(pData->y_position + 0x20, pData->x_position);
        if (block_prevent == 0x0)
        {
            // Block below samus
            block_prevent = ClipdataProcessForSamus(pData->y_position - 0xA0, pData->x_position);
            // Block that samus will try to grab
            block_grabbing = ClipdataProcessForSamus(pData->y_position - 0x68, pData->x_position + offset);
            // Not sure what this block is
            block_unk = ClipdataProcessForSamus(pData->y_position - 0x80, pData->x_position + offset);

            switch (pData->pose)
            {
                case SPOSE_MIDAIR:
                case SPOSE_STARTING_SPIN_JUMP:
                case SPOSE_SPINNING:
                case SPOSE_STARTING_WALL_JUMP:
                case SPOSE_SPACE_JUMPING:
                case SPOSE_SCREW_ATTACKING:
                    clip = ClipdataCheckCurrentAffectingAtPosition(pData->y_position - 0x60, pData->x_position + offset);
                    // Checks if can grab block
                    if (!(block_prevent & 0x1000000) && block_grabbing & 0x1000000 && clip.movement != CLIPDATA_MOVEMENT_NON_POWER_GRIP && !(block_unk & 0x1000000))
                    {
                        if (gEquipment.suit_type == SUIT_SUITLESS)
                        {
                            new_pose = SPOSE_GRABBING_A_LEDGE_SUITLESS;
                            SoundPlay(0x9B); // Suitless grip
                        }
                        else
                        {
                            new_pose = SPOSE_HANGING_ON_LEDGE;
                            if (pPhysics->slowed_by_liquid)
                                SoundPlay(0x95); // Underwater grip
                            else
                                SoundStop(0x7A); // Normal grip
                        }
                    }
            }
        }
    }

    if (pPhysics->touching_side_block)
    {
        pData->x_velocity = 0x0;
        
        switch (pData->pose)
        {
            case SPOSE_RUNNING:
                if (gEquipment.suit_type == SUIT_SUITLESS && gSamusDataCopy.timer == 0x1)
                    new_pose = SPOSE_CROUCHING_TO_CRAWL;
                break;

            case SPOSE_SPINNING:
            case SPOSE_SCREW_ATTACKING:
                // Setup wall jump
                pData->walljump_timer = 0x8;
                pData->last_wall_touched_midair = pData->direction ^ (KEY_RIGHT | KEY_LEFT);
                break;

            case SPOSE_ON_ZIPLINE:
            case SPOSE_SHOOTING_ON_ZIPLINE:
            case SPOSE_TURNING_ON_ZIPLINE:
            case SPOSE_MORPH_BALL_ON_ZIPLINE:
                // Drop if on zipline
                new_pose = SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
    }

    if (pPhysics->standing_status != STANDING_INVALID)
    {
        if (new_pose == SPOSE_UPDATE_JUMP_VELOCITY_REQUEST)
            pData->y_position++;

        if (new_pose != SPOSE_NONE)
            SamusSetPose(new_pose);
    }*/
}

/**
 * 6214 | 3dc | 
 * Checks if an environment effect for samus can/should spawn and spawns it
 * 
 * @param pData Samus Data Pointer
 * @param default_offset Default offset in the global array (0 means auto)
 * @param request Environmental effect requested
 */
void SamusCheckSetEnvironmentalEffect(struct SamusData* pData, u32 default_offset, u32 request)
{
    u8 found;
    u8 can_spawn;
    u8 offset;
    u16 x_position;
    u16 y_position;
    u8 effect;
    u32 current_affecting;
    u32 previous_liquid;
    u16 previous_pos;
    u16 liquid_check_pos;
    u16 offset_x;
    struct SamusPhysics* pPhysics;

    pPhysics = &gSamusPhysics;

    found = FALSE;
    can_spawn = TRUE;

    if (default_offset == 0x0)
    {
        for (offset = 0; offset < 0x3; offset++)
        {
            if (gSamusEnvirnmentalEffects[offset].type == ENV_EFFECT_NONE)
                break;
        }
        if (offset > 0x2)
            can_spawn--;
    }
    else
        offset = default_offset;

    switch (request)
    {
        case WANTING_RUNNING_EFFECT:
        case WANTING_RUNNING_EFFECT_:
            if (pData->direction & KEY_RIGHT)
                offset_x = pData->x_position + 0x4;
            else
                offset_x = pData->x_position - 0x4;

            current_affecting = ClipdataCheckGroundEffect(pData->y_position + 0x1, offset_x);

            if (current_affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_WET_GROUND;
                found++;
                if (request == WANTING_RUNNING_EFFECT)
                {
                    if (gEquipment.suit_type == SUIT_SUITLESS)
                        SoundPlay(0xA1); // Suitless wet ground
                    else
                        SoundPlay(0x68); // Wet footsteps
                }
                else
                {
                    if (gEquipment.suit_type == SUIT_SUITLESS)
                        SoundPlay(0xA2); // Suitless wet ground 2
                    else
                        SoundPlay(0x69); // Wet footsteps 2
                }
            }
            else if (current_affecting == GROUND_EFFECT_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_DUSTY_GROUND;
                found++;

                if (request == WANTING_RUNNING_EFFECT)
                    SoundPlay(0x66); // Dusty footstep
                else
                    SoundPlay(0x67); // Dusty footstep 2
            }
            else if (current_affecting == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_VERY_DUSTY_GROUND;
                found++;
                if (request == WANTING_RUNNING_EFFECT)
                    SoundPlay(0x66); // Dusty footstep
                else
                    SoundPlay(0x67); // Dusty footstep 2
            }
            x_position = offset_x;
            y_position = pData->y_position;
            break;

        case WANTING_LANDING_EFFECT:
            current_affecting = ClipdataCheckGroundEffect(pData->y_position + 0x1, pData->x_position);
            if (current_affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_WET_GROUND;
                found++;
                if (gEquipment.suit_type == SUIT_SUITLESS)
                    SoundPlay(0xA3); // Suitless landing on wet ground
                else
                    SoundPlay(0x74); // Landing on wet ground
            }
            else if (current_affecting == GROUND_EFFECT_BUBBLY_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_BUBBLY_GROUND;
                found++;
            }
            else if (current_affecting == GROUND_EFFECT_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_DUSTY_GROUND;
                found++;
                SoundPlay(0x73); // Landing on dusty ground
            }
            else if (current_affecting == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_VERY_DUSTY_GROUND;
                found++;
                SoundPlay(0x73); // Landing on dusty ground
            }
            else
            {
                if (pPhysics->slowed_by_liquid)
                    SoundPlay(0x95); // Suitless landing/ledge grip underwater
                else if (gSamusDataCopy.last_wall_touched_midair != KEY_NONE)
                    SoundPlay(0x72); // Morphball drop bounce 2?
                else if (gEquipment.suit_type != SUIT_SUITLESS)
                    SoundPlay(0x71); // Landing
                else
                    SoundPlay(0x99); // Suitless landing
            }

            x_position = pData->x_position;
            y_position = pData->y_position;
            break;

        case WANTING_GOING_OUT_OF_LIQUID_EFFECT:
        case WANTING_RUNNING_OUT_OF_LIQUID_EFFECT:
            liquid_check_pos = pData->y_position;
            previous_pos = gPreviousYPosition;
            if (effect == WANTING_GOING_OUT_OF_LIQUID_EFFECT)
            {
                liquid_check_pos -= 0x10;
                previous_pos -= 0x10;
            }

            current_affecting = ClipdataCheckCurrentAffectingAtPosition(liquid_check_pos, pData->x_position) & 0xFF;
            previous_liquid = ClipdataCheckCurrentAffectingAtPosition(previous_pos, pData->x_position) & 0xFF;

            if (liquid_check_pos < previous_pos)
            {
                if (current_affecting != HAZARD_TYPE_WATER && previous_liquid == HAZARD_TYPE_WATER)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_WATER;
                    found++;
                }
                else if (current_affecting != HAZARD_TYPE_STRONG_LAVA && previous_liquid == HAZARD_TYPE_STRONG_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (current_affecting != HAZARD_TYPE_WEAK_LAVA && previous_liquid == HAZARD_TYPE_WEAK_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (current_affecting != HAZARD_TYPE_ACID && previous_liquid == HAZARD_TYPE_ACID)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
            }
            else
            {
                if (current_affecting == HAZARD_TYPE_WATER && previous_liquid != HAZARD_TYPE_WATER)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_WATER;
                    found++;
                }
                else if (current_affecting == HAZARD_TYPE_STRONG_LAVA && previous_liquid != HAZARD_TYPE_STRONG_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (current_affecting == HAZARD_TYPE_WEAK_LAVA && previous_liquid != HAZARD_TYPE_WEAK_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (current_affecting == HAZARD_TYPE_ACID && previous_liquid != HAZARD_TYPE_ACID)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
            }

            if (request == WANTING_RUNNING_OUT_OF_LIQUID_EFFECT)
                effect++;

            x_position = pData->x_position;
            if (gEffectYPosition != 0x0)
                y_position = gEffectYPosition;
            else
            {
                if (previous_pos < liquid_check_pos)
                    y_position = gPreviousYPosition & 0xFFC0;
                else
                    y_position = pData->y_position & 0xFFC0;
            }
            break;

        case WANTING_BREATHING_BUBBLES:
            if (pData->standing_status != STANDING_MIDAIR)
            {
                effect = ENV_EFFECT_BREATHING_BUBBLES;
                found++;
                if (pData->direction & KEY_RIGHT)
                    x_position = pData->x_position + 0xC;
                else
                    x_position = pData->x_position - 0xC;

                y_position = pData->y_position + pPhysics->draw_distance_top_offset + 0x10;
                SoundPlay(0x91); // Breathing bubbles
            }
            break;

        case WANTING_SKIDDING_EFFECT:
            current_affecting = ClipdataCheckGroundEffect(pData->y_position + 0x1, pData->x_position);
            if (current_affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_SKIDDING_ON_WET_GROUND;
                found++;
            }
            else if (current_affecting - 0x2 < 0x2) // Both dusty and very dusty
            {
                effect = ENV_EFFECT_SKIDDING_ON_DUSTY_GROUND;
                found++;
            }
            x_position = pData->x_position;
            y_position = pData->y_position;
            break;

        case WANTING_RUNNING_ON_WET_GROUND:
            current_affecting = ClipdataCheckGroundEffect(pData->y_position + 0x1, pData->x_position);
            if (current_affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_WET_GROUND;
                x_position = pData->x_position;
                y_position = pData->y_position;
                found++;
            }
            break;
    }

    if (found & can_spawn)
    {
        gSamusEnvirnmentalEffects[offset].type = effect;
        gSamusEnvirnmentalEffects[offset].curr_animation_frame = 0x0;
        gSamusEnvirnmentalEffects[offset].anim_duration_counter = 0x0;
        gSamusEnvirnmentalEffects[offset].x_position = x_position;
        gSamusEnvirnmentalEffects[offset].y_position = y_position;
    }
}

void SamusUpdateEnvironmentalEffect(struct SamusData* pData)
{

}

/**
 * 6950 | 2dc | 
 * Updates the jump velocity of samus depending on the previous pose
 * 
 * @param pData Samus Data Pointer
 * @param pCopy Samus Data Copy Pointer
 * @param pWeapon Samus Weapon Info Pointer
 */
void SamusUpdateJumpVelocity(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    /*struct Equipment* pEquipment;

    pEquipment = &gEquipment;
    pData->x_velocity = pCopy->x_velocity;
    pData->arm_cannon_direction = pCopy->arm_cannon_direction;
    pData->speedboosting_shinesparking = pCopy->speedboosting_shinesparking;
    switch (pCopy->pose)
    {
        case SPOSE_RUNNING:
            if (pCopy->forced_movement != 0x1)
                pData->pose = SPOSE_MIDAIR;
            else
            {
                pData->pose = SPOSE_STARTING_SPIN_JUMP;
                if (pEquipment->suit_type == SUIT_SUITLESS)
                    pData->y_velocity = 0xD4;
                else if (pEquipment->suit_misc_activation & SMF_HIGH_JUMP)
                    pData->y_velocity = 0xE8;
                else
                    pData->y_velocity = 0xC0;
            }
            break;

        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
            pData->pose = SPOSE_MIDAIR;
            pData->x_velocity = 0x0;
            if (pCopy->forced_movement == 0x2)
                pData->y_velocity = pCopy->y_velocity;

            if (SamusCheckCollisionAbove(pData, samus_hitbox_data[0x0][0x2]) << 0x18)
                pData->y_position += 0x20;
            break;

        case SPOSE_STARTING_WALL_JUMP:
            if (pCopy->forced_movement == 0x0)
                pData->pose = SPOSE_MIDAIR;
            else
            {
                pData->pose = SPOSE_SPINNING;
                if (pCopy->forced_movement == 0x1)
                {
                    if (pEquipment->suit_misc_activation & SMF_HIGH_JUMP)
                        pData->y_velocity = 0xE8;
                    else
                        pData->y_velocity = 0xC0;
                }
                if (gSamusPhysics.slowed_by_liquid)
                {
                    pData->y_velocity = 0x74;
                    SoundPlay(0x95);
                }
                else
                {
                    if (gEquipment.suit_type != SUIT_SUITLESS)
                        SoundPlay(0x76);
                    else
                        SoundPlay(0x9A);
                }
            }
            break;

        case SPOSE_MORPH_BALL_MIDAIR:
            if (pCopy->forced_movement == 0xA)
            {
                pData->direction = KEY_RIGHT;
                pData->x_velocity = 0x30;
                pData->y_velocity = 0xA4;
                pData->forced_movement = 0x1;
            }
            else if (pCopy->forced_movement == 0xB)
            {
                pData->x_velocity = 0x0;
                pData->y_velocity = 0xA4;
                pData->forced_movement = 0x1;
            }
            else if (pCopy->forced_movement == 0xC)
            {
                pData->direction = KEY_LEFT;
                pData->x_velocity = -0x30;
                pData->y_velocity = 0xA4;
                pData->forced_movement = 0x1;
            }
            break;

        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
            pData->curr_anim_frame = pCopy->curr_anim_frame;
            pData->anim_duration_counter = pCopy->anim_duration_counter;
        case SPOSE_MORPHING:
            if (pCopy->forced_movement == 0xA)
            {
                pData->direction = KEY_RIGHT;
                pData->x_velocity = 0x30;
                pData->y_velocity = 0xA4;
                pData->forced_movement = 0x1;
            }
            else if (pCopy->forced_movement == 0xB)
            {
                pData->x_velocity = 0x0;
                pData->y_velocity = 0xA4;
                pData->forced_movement = 0x1;
            }
            else if (pCopy->forced_movement == 0xC)
            {
                pData->direction = KEY_LEFT;
                pData->x_velocity = -0x30;
                pData->y_velocity = 0xA4;
                pData->forced_movement = 0x1;
            }
            else
            {
                pData->x_velocity >>= 0x1;
                if (pCopy->forced_movement == 0x1)
                    pData->y_velocity = 0xD4;
            }
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
        case SPOSE_BALLSPARK_COLLISION:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
            pData->pose = SPOSE_MORPH_BALL_MIDAIR;
            break;

        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
            if (SamusCheckCollisionAbove(pData, samus_hitbox_data[0x0][0x2]) << 0x18)
                pData->y_position += 0x20;
        default:
            pData->pose = SPOSE_MIDAIR;
            if (pCopy->forced_movement == 0x1)
            {
                if (gButtonInput & (KEY_RIGHT | KEY_LEFT))
                    pData->pose = SPOSE_STARTING_SPIN_JUMP;
                else
                    pData->pose = SPOSE_MIDAIR;

                if (pEquipment->suit_type == SUIT_SUITLESS)
                    pData->y_velocity = 0xD4;
                else if (pEquipment->suit_misc_activation & SMF_HIGH_JUMP)
                    pData->y_velocity = 0xE8;
                else
                    pData->y_velocity = 0xC0;
            }
            else if (pCopy->forced_movement == 0x2)
                pData->y_velocity = pCopy->y_velocity;
    }

    if (pCopy->forced_movement == 0x1)
    {
        if (pData->pose == SPOSE_MIDAIR)
        {
            if (!gSamusPhysics.slowed_by_liquid)
            {
                if (pData->y_velocity == 0xC0)
                    SoundPlay(0x6E);
                else if (pData->y_velocity == 0xE8)
                    SoundPlay(0x6F);
                else if (pData->y_velocity == 0xD4)
                    SoundPlay(0x9D);
            }
            else
                SoundPlay(0x94);
        }
        else if (pData->pose == SPOSE_MORPH_BALL_MIDAIR)
        {
            if (gSamusPhysics.slowed_by_liquid)
                SoundPlay(0x94);
            else
                SoundPlay(0x70);
        }
    }*/
}

void SamusSetLandingPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    /*u8 collision;
    
    pCopy->last_wall_touched_midair = KEY_NONE;

    switch (pCopy->pose)
    {
        case SPOSE_MIDAIR:
            collision = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
            if (collision)
                pData->pose = SPOSE_CROUCHING;
            else
            {
                if (pCopy->x_velocity == 0x0)
                    pData->pose = SPOSE_LANDING;
                else
                {
                    if (pCopy->speedboosting_shinesparking)
                    {
                        pData->pose = SPOSE_RUNNING;
                        pData->speedboosting_shinesparking = TRUE;
                    }
                    else
                        pData->pose = SPOSE_STANDING;
                }
            }
            break;

        case SPOSE_MORPH_BALL_MIDAIR:
            pCopy->last_wall_touched_midair++;

            if (gButtonInput & KEY_A && gEquipment.suit_misc_activation & SMF_HIGH_JUMP)
            {
                // /!\ Invalid cast
                collision = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
                collision &= SAMUS_COLLISION_DETECTION_MIDDLE_LEFT | SAMUS_COLLISION_DETECTION_MIDDLE_RIGHT;
                if (!(collision))
                    pData->forced_movement = 0x14;
            }
            else
            {
                if (pCopy->y_velocity < -0xC0 && !gSamusPhysics.slowed_by_liquid && ClipdataCheckGroundEffect(pData->y_position + 0x1, pData->x_position) != GROUND_EFFECT_VERY_DUSTY_GROUND)
                {
                    pData->forced_movement = 0x1;
                    pData->y_velocity = 0x32;
                    break;
                }
            }

        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            pData->pose = SPOSE_MORPH_BALL;
            break;

        case SPOSE_SHINESPARKING:
        case SPOSE_BALLSPARKING:
            if (gButtonInput & pData->direction)
            {
                if (pData->direction & KEY_RIGHT)
                    pData->x_velocity = 0xA0;
                else
                    pData->x_velocity = -0xA0;

                if (pCopy->pose == SPOSE_SHINESPARKING)
                    pData->pose = SPOSE_RUNNING;
                else
                {
                    pData->pose = SPOSE_ROLLING;
                    pData->shinespark_timer = 0x6;
                }

                pData->speedboosting_shinesparking = TRUE;
                pData->timer = 0xA0;

                SoundPlay(0x8B); // Speedbooster start
            }
            else
            {
                ScreenShakeStartHorizontal(0x1E, 0x1);
                if (pCopy->pose == SPOSE_SHINESPARKING)
                    pData->pose = SPOSE_SHINESPARK_COLLISION;
                else
                    pData->pose = SPOSE_BALLSPARK_COLLISION;

                pData->forced_movement = pCopy->forced_movement;
                pData->curr_anim_frame = 0x1;
                SoundPlay(0x90); // Shinespark collision
            }
            break;

        default:
            collision = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
            if (collision)
                pData->pose = SPOSE_CROUCHING;
            else if (pCopy->x_velocity == 0x0)
                pData->pose = SPOSE_LANDING;
            else
                pData->pose = SPOSE_STANDING;
    }

    pData->arm_cannon_direction = pCopy->arm_cannon_direction;

    switch (pData->pose)
    {
        case SPOSE_LANDING:
            if (gSamusPhysics.has_new_projectile != 0x0)
                pData->curr_anim_frame = 0x1;
            if (pCopy->arm_cannon_direction == ACD_DOWN)
                pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
            break;
        
        case SPOSE_RUNNING:
            if (pCopy->arm_cannon_direction == ACD_UP)
                pData->arm_cannon_direction = ACD_DIAGONALLY_UP;
        
        case SPOSE_STANDING:
            if (pCopy->arm_cannon_direction == ACD_DOWN)
                pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
            break;
    }


    SamusCheckSetEnvironmentalEffect(pData, 0x0, WANTING_LANDING_EFFECT);*/
}

void SamusChangeToHurtPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    i16 new_x_velo; 
    i16 new_y_velo; 
    u8 y_pos_related;

    if (gEquipment.current_energy != 0x0)
    {
        y_pos_related = 0x0;
        switch (pCopy->pose)
        {
            case SPOSE_MORPHING:
            case SPOSE_MORPH_BALL:
            case SPOSE_ROLLING:
            case SPOSE_MORPH_BALL_MIDAIR:
            case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
            case SPOSE_DELAY_BEFORE_BALLSPARKING:
            case SPOSE_BALLSPARK_COLLISION:
            case SPOSE_MORPH_BALL_ON_ZIPLINE:
            case SPOSE_GETTING_HURT_IN_MORPH_BALL:
            case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
                pData->pose = SPOSE_GETTING_HURT_IN_MORPH_BALL;
                break;

            case SPOSE_CRAWLING_STOPPED:
            case SPOSE_STARTING_TO_CRAWL:
            case SPOSE_CRAWLING:
            case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
            case SPOSE_SHOOTING_WHILE_CRAWLING:
                pData->pose = SPOSE_CRAWLING_STOPPED;
                pData->x_velocity = 0x0;
                break;

            default:
                y_pos_related = SamusCheckCollisionAbove(pData, samus_hitbox_data[0x0][0x2]);
                pData->pose = SPOSE_GETTING_HURT;
        }

        if (y_pos_related != 0x0)
            pData->y_position |= 0x3F;

        if (pCopy->forced_movement == 0xFF)
            pData->forced_movement = 0x1;

        pData->y_velocity = 0x70;
        if (pCopy->standing_status == STANDING_MIDAIR)
            pData->y_velocity = 0x38;

        pData->arm_cannon_direction = pCopy->arm_cannon_direction;
        SoundPlay(0x7C);
    }
    else
    {
        gDisableScrolling = 0x1;
        gMonochromeBGFading = 0x1;
        pData->pose = SPOSE_DYING;
        new_x_velo = ((gBG1XPosition + 0x1E0) - pData->x_position);
        new_x_velo >>= 0x1;
        pData->x_velocity = new_x_velo;
        new_y_velo = ((gBG1YPosition + 0x190) - pData->y_position);
        new_y_velo >>= 0x4;
        pData->y_velocity = new_y_velo;
        gGameModeSub1 = 0x5;
    }

    pData->invincibility_timer = 0x30;
    pData->shinespark_timer = 0x0;
    pData->standing_status = STANDING_MIDAIR;
    pWeapon->new_projectile = PROJECTILE_NONE;
    pWeapon->beam_release_palette_timer = 0x0;
}

void SamusChangeToKnockbackPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    u8 y_pos_related;

    y_pos_related = 0x0;
    switch (pCopy->pose)
    {
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
        case SPOSE_BALLSPARK_COLLISION:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
            pData->pose = SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL;
            break;

        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
            pData->pose = SPOSE_CRAWLING_STOPPED;
            break;

        default:
            y_pos_related = SamusCheckCollisionAbove(pData, samus_hitbox_data[0x0][0x2]);
            pData->pose = SPOSE_GETTING_KNOCKED_BACK;
    }
    
    if (y_pos_related != 0x0)
        pData->y_position |= 0x3F;

    pData->y_velocity = 0x70;
    if (pCopy->standing_status == STANDING_MIDAIR)
        pData->y_velocity = 0x38;

    pData->arm_cannon_direction = pCopy->arm_cannon_direction;
    pData->shinespark_timer = 0x0;
    pData->standing_status = STANDING_MIDAIR;
    pWeapon->new_projectile = PROJECTILE_NONE;
    pWeapon->beam_release_palette_timer = 0x0;
}

/**
 * @brief 7164 | 384 | Carries what should be carried from the samus data copy, also handles shinespark direction selection
 * 
 * @param pData Samus Data Pointer
 * @param pCopy Samus Data Copy Pointer
 * @param pWeapon Samus Weapon Info Pointer
 */
void SamusCheckCarryFromCopy(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    // https://decomp.me/scratch/1VwJS

    switch (pData->pose)
    {
        case SPOSE_RUNNING:
            if (gButtonInput & gButtonAssignments.diagonal_aim || gButtonInput & gButtonAssignments.arm_missiles)
                pData->arm_cannon_direction = pCopy->arm_cannon_direction;
            else
                pData->arm_cannon_direction = ACD_NONE;
            break;

        case SPOSE_STANDING:
            pData->arm_cannon_direction = pCopy->arm_cannon_direction;
            if (pCopy->pose == SPOSE_CROUCHING || pCopy->pose == SPOSE_SHOOTING_AND_CROUCHING)
                // Timer to ignore input for arm cannon direction, prevents immediatly aiming up after uncrouching
                pData->timer = 0x6;
            break;

        case SPOSE_CROUCHING:
            pData->arm_cannon_direction = pCopy->arm_cannon_direction;
            pData->curr_anim_frame = 0x1;
            if (pData->arm_cannon_direction < ACD_UP)
                break;
            pData->arm_cannon_direction = ACD_FORWARD;
            break;

        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
            pData->timer = gSamusPhysics.slowed_by_liquid;
            if (gSamusPhysics.slowed_by_liquid)
                SoundPlay(0x94); // Underwater mantling
            else if (gEquipment.suit_type != SUIT_SUITLESS)
                SoundPlay(0x7B); // Mantling
            else
                SoundPlay(0x9C); // Suitless mantling
            
        case SPOSE_MORPH_BALL:
            if (pCopy->speedboosting_shinesparking)
                pData->timer = 0x6;
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            break;

        case SPOSE_SKIDDING:
            pData->x_velocity = pCopy->x_velocity;
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            SamusCheckSetEnvironmentalEffect(pData, 0x0, WANTING_SKIDDING_EFFECT);
            SoundPlay(0x8C); // Skidding
            break;


        case SPOSE_DELAY_BEFORE_SHINESPARKING:
            pData->shinespark_timer = 0x32;
            SoundPlay(0x8E); // Shinesparking
            break;

        case SPOSE_SHINESPARKING:
        case SPOSE_BALLSPARKING:
            if (pCopy->forced_movement == FORCED_MOVEMENT_LAUNCHED_BY_CANNON)
                pData->y_velocity = 0xC0;
            else
            {
                if (gButtonInput & gButtonAssignments.diagonal_aim)
                {
                    pData->forced_movement = FORCED_MOVEMENT_DIAGONAL_SHINESPARK;
                    if (pData->direction & KEY_RIGHT)
                        pData->x_velocity = 0xA0;
                    else
                        pData->x_velocity = -0xA0;

                    pData->y_velocity = 0x60;
                }
                else if (gButtonInput & pData->direction)
                {
                    if (gButtonInput & KEY_UP)
                    {
                        pData->forced_movement = FORCED_MOVEMENT_DIAGONAL_SHINESPARK;
                        if (pData->direction & KEY_RIGHT)
                            pData->x_velocity = 0xA0;
                        else
                            pData->x_velocity = -0xA0;
                        
                        pData->y_velocity = 0x60;
                    }
                    else
                    {
                        pData->forced_movement += FORCED_MOVEMENT_SIDEWARDS_SHINESPARK;
                        if (pData->direction & KEY_RIGHT)
                            pData->x_velocity = 0xC0;
                        else
                            pData->x_velocity = -0xC0;
                    }
                }
                else
                {
                    pData->y_velocity = 0xC0;
                }
            }

            pData->speedboosting_shinesparking++;
            pData->shinespark_timer = 0x0;
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_SHINESPARKING;
            break;

        case SPOSE_SHINESPARK_COLLISION:
            pData->forced_movement = pCopy->forced_movement;
            pData->curr_anim_frame = 0x1;

        case SPOSE_BALLSPARK_COLLISION:
            pData->invincibility_timer = 0x30;
            SoundPlay(0x90); // Shinespark collision
            break;

        case SPOSE_DELAY_BEFORE_BALLSPARKING:
            if (pCopy->forced_movement == FORCED_MOVEMENT_LAUNCHED_BY_CANNON)
                pData->forced_movement = FORCED_MOVEMENT_LAUNCHED_BY_CANNON;
            else
                gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_SHINESPARKING;
            SoundPlay(0x8F); // Ballspark
            break;

        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_GRABBING_A_LEDGE_SUITLESS:
            if ((pData->y_position & 0x3F) < 0x1F)
                pData->y_position = (pData->y_position & 0xFFC0) + 0x8;
            else
                pData->y_position = (pData->y_position & 0xFFC0) + 0x48;
            pWeapon->diagonal_aim = DIAG_AIM_NONE;

            gSamusEcho.active = FALSE;
            gSamusEcho.timer = 0x0;
            break;

        case SPOSE_USING_AN_ELEVATOR:
            pData->elevator_direction = pCopy->elevator_direction;
            if (pData->elevator_direction & KEY_UP)
                pData->y_velocity = 0x8;
            else
                pData->y_velocity = -0x8;
            
            SoundPlay(0x10E); // Elevator
            break;

        case SPOSE_TURNING_FROM_FACING_THE_FOREGROUND:
            pData->elevator_direction = pCopy->elevator_direction;
            
            #ifndef NONMATCHING
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            #else
            goto DiagNone;
            #endif
            break;

        case SPOSE_ON_ZIPLINE:
            if ((u8)(pCopy->pose - 0x29) > 0x1)
            {
                pWeapon->diagonal_aim = DIAG_AIM_NONE;
                if (gEquipment.suit_type == SUIT_SUITLESS)
                    SoundPlay(0x9B);
                else
                    SoundPlay(0x7A);
            }
            else
                pData->arm_cannon_direction = pCopy->arm_cannon_direction;

            break;

        case SPOSE_SAVING_LOADING_GAME:
            pData->last_wall_touched_midair = pCopy->last_wall_touched_midair;
        
        case SPOSE_DOWNLOADING_MAP_DATA:
            pData->timer = 0x1;

        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_FACING_THE_FOREGROUND:
        case SPOSE_CROUCHING_TO_CRAWL:
            DiagNone:
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            break;

        case SPOSE_CRAWLING_STOPPED:
            if (pCopy->pose == SPOSE_SHOOTING_WHILE_CRAWLING)
                pData->forced_movement = FORCED_MOVEMENT_CROUCHING_ARM_CANNON_UP;
            break;

        case SPOSE_FACING_THE_BACKGROUND_SUITLESS:
            pData->last_wall_touched_midair = 0x1;
            pData->arm_cannon_direction = pCopy->arm_cannon_direction;
            break;

        case SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP:
            pData->turning = TRUE;
            break;
        
        case SPOSE_TURNING_AROUND_MIDAIR:
            pData->y_velocity = pCopy->y_velocity;

        case SPOSE_TURNING_AROUND:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_TURNING_ON_ZIPLINE:
        case SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
            pData->turning = TRUE;
            pData->arm_cannon_direction = pCopy->arm_cannon_direction;
            break;

        case SPOSE_IN_ESCAPE_SHIP:
            break;
        
        default:
            pData->arm_cannon_direction = pCopy->arm_cannon_direction;
    }
}

void SamusSetPose(u8 pose)
{
    struct WeaponInfo* pWeapon;
    struct SamusData* pData;
    struct SamusData* pCopy;

    pData = &gSamusData;
    pCopy = &gSamusDataCopy;
    pWeapon = &gSamusWeaponInfo;

    if ((u8)(pose + 0x7) < 0x2)
        pData->turning = FALSE;

    SamusCopyData(pData);

    if (pCopy->arm_cannon_direction == ACD_NONE)
        pCopy->arm_cannon_direction = ACD_FORWARD;

    switch (pCopy->pose)
    {
        case SPOSE_DELAY_BEFORE_SHINESPARKING:
            if (pose != SPOSE_SHINESPARKING)
                play_sound(0x8E);
            break;
        
        case SPOSE_SHINESPARKING:
            if (pose != SPOSE_SHINESPARK_COLLISION)
                play_sound(0x8E);
            break;
        
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
            if (pose != SPOSE_BALLSPARKING)
                SoundStop(0x8F);
            break;
        
        case SPOSE_BALLSPARKING:
            if (pose != SPOSE_BALLSPARK_COLLISION)
                SoundStop(0x8F);
            break;
    }

    switch (pose)
    {
        case SPOSE_UPDATE_JUMP_VELOCITY_REQUEST:
            SamusUpdateJumpVelocity(pData, pCopy, pWeapon);
            break;
        
        case SPOSE_LANDING_REQUEST:
            SamusSetLandingPose(pData, pCopy, pWeapon);
            break;
        
        case SPOSE_HURT_REQUEST:
            SamusChangeToHurtPose(pData, pCopy, pWeapon);
            break;
        
        case SPOSE_KNOCKBACK_REQUEST:
            SamusChangeToKnockbackPose(pData, pCopy, pWeapon);
            break;

        default:
            pData->pose = pose;
            SamusCheckCarryFromCopy(pData, pCopy, pWeapon);
    }
}

/**
 * 75bc | 60 | Copies samus data to the samus data copy and resets samus data 
 * 
 * @param pData_ Samus Data Pointer (unused)
 */
void SamusCopyData(struct SamusData* pData_)
{
    struct SamusData* pData;
    struct ScrewSpeedAnimation* pScrew;
    struct SamusData* pCopy;

    pData = &gSamusData;
    pScrew = &gScrewSpeedAnimation;
    pCopy = &gSamusDataCopy;

    *pCopy = *pData;
    if (pData->turning != FALSE)
    {
        pData->direction ^= (KEY_LEFT | KEY_RIGHT);
        pData->turning = FALSE;
    }

    pData->arm_cannon_direction = ACD_FORWARD;
    pData->forced_movement = 0x0;
    pData->speedboosting_shinesparking = FALSE;
    pData->walljump_timer = 0x0;
    pData->timer = 0x0;
    pData->last_wall_touched_midair = 0x0;
    pData->elevator_direction = 0x0;
    pData->x_velocity = 0x0;
    pData->y_velocity = 0x0;
    pData->anim_duration_counter = 0x0;
    pData->curr_anim_frame = 0x0;

    if (pData->shinespark_timer != 0xB4)
        pScrew->flag = SCREW_SPEED_FLAG_NONE;

    pScrew->anim_duration_counter = 0x0;
    pScrew->curr_anim_frame = 0x0;
}

void SamusUpdatePhysics(struct SamusData* pData)
{

}

i16 SamusChangeVelocityOnSlope(struct SamusData* pData)
{
    i32 velocity, decreased_velocity;

    velocity = (i32)pData->x_velocity;
    if (pData->direction & pData->current_slope)
    {
        if (pData->current_slope & SLOPE_STEEP)
        {
            decreased_velocity = velocity * 3 / 5;
        }
        else
        {
            decreased_velocity = velocity * 4 / 5;
        }
        velocity = (i16)decreased_velocity;
    }
    else
    {
        if (velocity > 0xA0)
        {
            velocity = 0xA0;
        }
        else if (velocity < -0xA0)
        {
            velocity = -0xA0;
        }
    }
    return velocity;
}

void SamusCopyPalette(u16* src, i32 offset, i32 nbr_colors)
{
    /*u16* pPalette;
    u32 size;

    if (offset < offset + nbr_colors)
    {
        pPalette = gSamusPalette;
        pPalette += offset;
        size = nbr_colors - offset;
        do {
           *pPalette++ = *src++;
            size--;
        } while (size != 0x0);
    }*/
}

void SamusUpdate(void)
{
    u8 new_pose;
    struct SamusData* pData;

    pData = &gSamusData;

    if (0x1 < gGameModeSub1)
        pData->anim_duration_counter++;
    
    SamusUpdatePhysics(pData);
    new_pose = SamusExecutePoseSubroutine(pData);
    if (new_pose != SPOSE_NONE)
        SamusSetPose(new_pose);
    SamusUpdateDrawDistanceAndStandingStatus(pData, &gSamusPhysics);
    SamusUpdateVelocityPosition(pData);
}

void SamusUpdateHitboxMovingDirection(void)
{
    struct SamusData* pData;
    struct SamusPhysics* pPhysics;
    u8* pDirection;

    pData = &gSamusData;
    pPhysics = &gSamusPhysics;

    pPhysics->touching_side_block = FALSE;
    pPhysics->touching_top_block = FALSE;
    pPhysics->unknown = 0x0;
    pDirection = &pPhysics->horizontal_moving_direction;
    *pDirection = HDMOVING_NONE;
    pPhysics->vertical_moving_direction = VDMOVING_NONE;
    
    if (pData->x_position > gPreviousXPosition)
        *pDirection = HDMOVING_RIGHT;
    else if (pData->x_position < gPreviousXPosition)
        *pDirection = HDMOVING_LEFT;

    if (gUnk_03004fc9 == 0x0)
    {
        if (pData->y_position > gPreviousYPosition)
            pPhysics->vertical_moving_direction = VDMOVING_DOWN;
        else if (pData->y_position < gPreviousYPosition)
            pPhysics->vertical_moving_direction = VDMOVING_UP;
    }
    
    pPhysics->standing_status = samus_visual_data[pData->pose][0x2];
    pPhysics->hitbox_left_offset = samus_hitbox_data[pPhysics->hitbox_array_offset][0x0];
    pPhysics->hitbox_right_offset = samus_hitbox_data[pPhysics->hitbox_array_offset][0x1];
    pPhysics->hitbox_top_offset = samus_hitbox_data[pPhysics->hitbox_array_offset][0x2];
    if (pPhysics->standing_status == STANDING_NOT_IN_CONTROL)
        pPhysics->vertical_moving_direction = VDMOVING_DOWN;

    SamusCheckCollisions(pData, pPhysics);
    SamusUpdateDrawDistanceAndStandingStatus(pData, pPhysics);
}

/**
 * 78e0 | 3c | Calls functions related to updating samus' graphics
 * 
 */
void SamusCallGFXFunctions(void)
{
    struct SamusData* pData;
    u8 direction;
    u16 flag;

    pData = &gSamusData;

    if (gGameModeSub1 == 0x2)
        SamusUpdateEnvironmentalEffect(pData);

    flag = pData->direction & KEY_RIGHT;
    direction = TRUE;
    if (flag)
        direction = FALSE;
    
    SamusUpdateGraphicsOAM(pData, direction);
    SamusUpdatePalette(pData);
}

void SamusCallCheckLowHealth(void)
{
    SamusCheckPlayLowHealthSound();
}

void SamusCallUpdateArmCannonPositionOffset(void)
{
    u8 flag;
    u8 direction;

    flag = gSamusData.direction & KEY_RIGHT;
    direction = TRUE;
    if (flag)
        direction = FALSE;
    SamusUpdateArmCannonPositionOffset(direction);
}

void SamusBombBounce(u8 direction)
{
    /*u8 can_bounce;

    if (gSamusPhysics.slowed_by_liquid)
        return;

    can_bounce = FALSE;
    if ((direction & 0x7F) > 0x9)
    {
        switch (gSamusData.pose)
        {
            case SPOSE_MORPH_BALL_MIDAIR:
                if (gSamusData.y_velocity <= 0x0 && (direction & 0x80) == 0x0)
                    can_bounce = TRUE;
            
            default:
                if (!can_bounce)
                    return;

            case SPOSE_ROLLING:
            case SPOSE_MORPHING:
            case SPOSE_MORPH_BALL:
                gSamusData.forced_movement = direction & 0x7F;
                SamusSetPose(SPOSE_UPDATE_JUMP_VELOCITY_REQUEST);
        }
    }*/
}

void SamusAimCannon(struct SamusData* pData)
{
    /*struct WeaponInfo* pWeapon;
    u16 direction;

    pWeapon = &gSamusWeaponInfo;

    if (gButtonInput & gButtonAssignments.diagonal_aim)
    {
        switch (pData->pose)
        {
            case SPOSE_RUNNING:
            case SPOSE_STANDING:
            case SPOSE_SHOOTING:
            case SPOSE_CROUCHING:
            case SPOSE_SHOOTING_AND_CROUCHING:
            case SPOSE_MIDAIR:
            case SPOSE_LANDING:
            case SPOSE_STARTING_SPIN_JUMP:
            case SPOSE_SPACE_JUMPING:
            case SPOSE_SCREW_ATTACKING:
            case SPOSE_AIMING_WHILE_HANGING:
            case SPOSE_UNCROUCHING_SUITLESS:
            case SPOSE_CROUCHING_SUITLESS:
                if (gButtonInput & KEY_DOWN)
                {
                    pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
                    pWeapon->diagonal_aim = DIAG_AIM_DOWN;
                }
                else if (DIAG_AIM_UP >= pWeapon->diagonal_aim || gButtonInput & KEY_UP)
                {
                    pData->arm_cannon_direction = ACD_DIAGONALLY_UP;
                    pWeapon->diagonal_aim = DIAG_AIM_UP;
                }
                return;

            default:
                return;

            case SPOSE_ON_ZIPLINE:
                pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
                pWeapon->diagonal_aim = DIAG_AIM_DOWN;
                return;            
        }
    }

    switch (pData->pose)
    {
        case SPOSE_RUNNING:
            if (gButtonInput & KEY_UP)
                pData->arm_cannon_direction = ACD_DIAGONALLY_UP;
            else
            {
                direction = gButtonInput & KEY_DOWN;
                if (direction)
                    pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
                else
                {
                    if (pData->arm_cannon_direction < ACD_NONE)
                        pData->arm_cannon_direction = direction;
                }
            }

            if (gEquipment.suit_type == SUIT_SUITLESS || pData->arm_cannon_direction != ACD_NONE || (pWeapon->weapon_highlighted == WH_NONE && pWeapon->charge_counter == 0x0))
                pWeapon->diagonal_aim = DIAG_AIM_NONE;
            else
                pData->arm_cannon_direction = ACD_FORWARD;

            break;
        
        case SPOSE_STANDING:
        case SPOSE_SHOOTING:
        case SPOSE_LANDING:
        case SPOSE_UNCROUCHING_SUITLESS:
            if (pData->timer == 0x0 && gButtonInput & KEY_UP)
                    pData->arm_cannon_direction = ACD_UP;
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            break;

        case SPOSE_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_CROUCHING_SUITLESS:
            pData->arm_cannon_direction = ACD_FORWARD;
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            break;

        case SPOSE_MIDAIR:
        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
        case SPOSE_AIMING_WHILE_HANGING:
            if (gButtonInput & KEY_UP)
            {
                if (pData->direction & gButtonInput)
                    pData->arm_cannon_direction = ACD_DIAGONALLY_UP;
                else
                    pData->arm_cannon_direction = ACD_UP;
            }
            else
            {
                direction = gButtonInput & KEY_DOWN;
                if (direction)
                {
                    if ((pData->direction & gButtonInput) == 0x0)
                        pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
                    else
                        pData->arm_cannon_direction = ACD_DOWN;
                }
                else
                {
                    if (pData->arm_cannon_direction & gButtonInput)
                        pData->arm_cannon_direction = direction;
                    else
                    {
                        if ((u8)(pData->arm_cannon_direction - 0x3) > 0x2)
                            pData->arm_cannon_direction = pData->direction;
                    }
                }
            }
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            break;

        case SPOSE_ON_ZIPLINE:
            direction = gButtonInput & KEY_DOWN;
            if (direction)
            {
                if (pData->direction & gButtonInput)
                    pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
                else
                    pData->arm_cannon_direction = ACD_DOWN;
                pWeapon->diagonal_aim = DIAG_AIM_NONE;
            }
            else
            {
                if ((pData->direction & gButtonInput) == 0x0 && pData->arm_cannon_direction != ACD_DOWN)
                    pWeapon->diagonal_aim = DIAG_AIM_NONE;
                else
                {
                    pData->arm_cannon_direction = direction;
                    pWeapon->diagonal_aim = DIAG_AIM_NONE;
                }
            }
        default:
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            break;
    }*/
}

u8 SamusCheckFireBeamMissile(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment)
{
    /*u8 has_proj;
    u8 new_proj;

    has_proj = FALSE;
    if (pWeapon->cooldown == 0x0 && pWeapon->new_projectile == PROJECTILE_NONE && (gChangedInput & KEY_B) != 0x0)
    {
        if ((pWeapon->weapon_highlighted & WH_MISSILE) != 0x0)
            pWeapon->new_projectile = PROJECTILE_MISSILE;
        else if ((pWeapon->weapon_highlighted & WH_SUPER_MISSILE) != 0x0)
            pWeapon->new_projectile = PROJECTILE_SUPER_MISSILE;
        else
            pWeapon->new_projectile = PROJECTILE_BEAM;
        has_proj++;
    }

    if (has_proj)
    {
        if (pData->arm_cannon_direction == ACD_NONE)
            pData->arm_cannon_direction = ACD_FORWARD;
        return has_proj;
    }

    if (pWeapon->weapon_highlighted == WH_NONE)
    {
        if ((gButtonInput & KEY_B) != 0x0)
        {
            if ((pEquipment->beam_bombs_activation & BBF_CHARGE_BEAM) == 0x0)
                pWeapon->charge_counter = 0x0;
            else
            {
                if (pWeapon->charge_counter < 0x4F)
                    pWeapon->charge_counter++;
                else
                    pWeapon->charge_counter = 0x40;
            }
        }
        else
        {
            if (pWeapon->charge_counter >= 0x40)
            {
                new_proj = PROJECTILE_CHARGED_BEAM;
                pWeapon->new_projectile = new_proj;
                has_proj = TRUE;
            }
            else
            {
                if (0x19 < pWeapon->charge_counter)
                {
                    new_proj = PROJECTILE_BEAM;
                    pWeapon->new_projectile = new_proj;
                    has_proj = TRUE;
                }
            }
            pWeapon->charge_counter = 0x0;
        }
    }
    else
        pWeapon->charge_counter = 0x0;

    if (has_proj)
    {
        if (pData->arm_cannon_direction == ACD_NONE)
            pData->arm_cannon_direction = ACD_FORWARD;
    }

    return has_proj;*/
}

u8 SamusCheckFirePistol(struct SamusData* pData, struct WeaponInfo* pWeapon)
{
    u8 new_proj;

    new_proj = 0x0;

    if (pWeapon->charge_counter < 0x7F)
        pWeapon->charge_counter++;
    else
        pWeapon->charge_counter = 0x70;

    if (pWeapon->cooldown == 0x0 && pWeapon->new_projectile == PROJECTILE_NONE && (gChangedInput & KEY_B) != 0x0)
    {
        if (pWeapon->charge_counter >= 0x70)
        {
            pWeapon->new_projectile = PROJECTILE_CHARGED_BEAM;
            pWeapon->charge_counter = 0x0;
            new_proj++;
        }
        else
            pWeapon->new_projectile = PROJECTILE_BEAM;

        pWeapon->charge_counter = 0x0;
        new_proj++;
    }

    if (new_proj != PROJECTILE_NONE && pData->arm_cannon_direction == ACD_NONE)
        pData->arm_cannon_direction = ACD_FORWARD;

    return new_proj;
}

void SamusCheckNewProjectile(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment)
{
    struct SamusPhysics* pPhysics;

    pPhysics = &gSamusPhysics;

    pPhysics->has_new_projectile = 0x0;

    if (pEquipment->suit_type == SUIT_SUITLESS)
    {
        switch (pData->pose)
        {
            case SPOSE_FACING_THE_FOREGROUND:
            case SPOSE_SAVING_LOADING_GAME:
            case SPOSE_DOWNLOADING_MAP_DATA:
            case SPOSE_DYING:
            case SPOSE_FACING_THE_BACKGROUND_SUITLESS:
                pWeapon->charge_counter = 0x0;
                break;

            default:
                pPhysics->has_new_projectile = SamusCheckFirePistol(pData, pWeapon);
                break;

            case SPOSE_GETTING_HURT:
            case SPOSE_GETTING_KNOCKED_BACK:
                pWeapon->charge_counter = 0x0;
                break;
        }
    }
    else
    {
        switch (pData->pose)
        {
            case SPOSE_RUNNING:
            case SPOSE_STANDING:
            case SPOSE_TURNING_AROUND:
            case SPOSE_SHOOTING:
            case SPOSE_CROUCHING:
            case SPOSE_TURNING_AROUND_AND_CROUCHING:
            case SPOSE_SHOOTING_AND_CROUCHING:
            case SPOSE_MIDAIR:
            case SPOSE_TURNING_AROUND_MIDAIR:
            case SPOSE_LANDING:
            case SPOSE_STARTING_SPIN_JUMP:
            case SPOSE_SPINNING:
            case SPOSE_SPACE_JUMPING:
            case SPOSE_SCREW_ATTACKING:
            case SPOSE_HANGING_ON_LEDGE:
            case SPOSE_HIDING_ARM_CANNON_WHILE_HANGING:
            case SPOSE_AIMING_WHILE_HANGING:
            case SPOSE_ON_ZIPLINE:
            case SPOSE_SHOOTING_ON_ZIPLINE:
                pPhysics->has_new_projectile = SamusCheckFireBeamMissile(pData, pWeapon, pEquipment);
                break;

            case SPOSE_MORPH_BALL:
            case SPOSE_ROLLING:
            case SPOSE_MORPH_BALL_MIDAIR:
            case SPOSE_MORPH_BALL_ON_ZIPLINE:
                if ((gChangedInput & KEY_B) != 0x0 && pWeapon->cooldown == 0x0 && (pEquipment->beam_bombs_activation & BBF_BOMBS) != 0x0)
                {
                    if ((pWeapon->weapon_highlighted & WH_POWER_BOMB) != 0x0)
                        pWeapon->new_projectile = PROJECTILE_POWER_BOMB;
                    else
                        pWeapon->new_projectile = PROJECTILE_BOMB;
                }
            case SPOSE_MORPHING:
                if (0x3F < pWeapon->charge_counter)
                    pWeapon->new_projectile = PROJECTILE_CHARGED_BEAM;
                pWeapon->charge_counter = 0x0;
                break;
            
            case SPOSE_USING_AN_ELEVATOR:
            case SPOSE_SAVING_LOADING_GAME:
            case SPOSE_DOWNLOADING_MAP_DATA:
            case SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA:
            case SPOSE_DYING:
            case SPOSE_IN_ESCAPE_SHIP:
            case SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP:
                pWeapon->charge_counter = 0x0;
        }
    }
}

u8 SamusCheckAButtonPressed(struct SamusData* pData)
{
    u8 return_value;
    
    return_value = 0x0;
    if ((gChangedInput & KEY_A) != 0x0)
    {
        pData->forced_movement = 0x1;
        return_value = 0x1;
    }
    return return_value;
}

void SamusSetHighlightedWeapon(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment)
{
    /*u8 weapon_high;

    weapon_high = WH_NONE;
    if (pEquipment->current_super_missiles == 0x0)
        pWeapon->missiles_selected = weapon_high;
    else if (pEquipment->current_missiles == 0x0)
        pWeapon->missiles_selected = TRUE;
    else if ((gChangedInput & KEY_SELECT) != 0x0)
    {
        pWeapon->missiles_selected ^= 0x1;
        SoundPlay(0x85);
    }

    switch (pData->pose)
    {
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            if ((gButtonInput & gButtonAssignments.arm_missiles) == 0x0 || pEquipment->gCurrentPowerBombs != 0x0)
            {
                weapon_high = WH_POWER_BOMB;
                if (pWeapon->weapon_highlighted == WH_NONE)
                {
                    pWeapon->charge_counter = 0x0;
                    SoundPlay(0x84);
                }
            }
            else
            {
                if (weapon_high != WH_NONE)
                {
                    if (pWeapon->weapon_highlighted == WH_NONE)
                    {
                        pWeapon->charge_counter = 0x0;
                        SoundPlay(0x84);
                    }
                }
            }
            break;
        
        default:
            if ((gButtonInput & gButtonAssignments.arm_missiles) != 0x0)
            {
                if (pWeapon->missiles_selected == TRUE)
                {
                    if (pEquipment->current_missiles != 0x0)
                    {
                        weapon_high = WH_MISSILE;
                        if (pWeapon->weapon_highlighted == WH_NONE)
                        {
                            pWeapon->charge_counter = 0x0;
                            SoundPlay(0x84);
                        }
                    }
                }
                else
                {
                    weapon_high = WH_SUPER_MISSILE;
                    if (pEquipment->current_missiles != 0x0)
                    {
                        weapon_high = WH_MISSILE;
                        if (pWeapon->weapon_highlighted == WH_NONE)
                        {
                            pWeapon->charge_counter = 0x0;
                            SoundPlay(0x84);
                        }
                    }
                }
            }
            break;

        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_USING_AN_ELEVATOR:
        case SPOSE_FACING_THE_FOREGROUND:
        case SPOSE_TURNING_FROM_FACING_THE_FOREGROUND:
        case SPOSE_GRABBED_BY_CHOZO_STATUE:
        case SPOSE_DELAY_BEFORE_SHINESPARKING:
        case SPOSE_SHINESPARKING:
        case SPOSE_SHINESPARK_COLLISION:
        case SPOSE_DELAY_AFTER_SHINESPARKING:
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
        case SPOSE_BALLSPARKING:
        case SPOSE_BALLSPARK_COLLISION:
        case SPOSE_SAVING_LOADING_GAME:
            if (pWeapon->weapon_highlighted != WH_NONE)
            {
                if (pWeapon->weapon_highlighted == WH_NONE)
                {
                    pWeapon->charge_counter = 0x0;
                    SoundPlay(0x84);
                }
            }

    }

    pWeapon->weapon_highlighted = weapon_high;*/
}

void SamusSetSpinningPose(struct SamusData* pData, struct Equipment* pEquipment)
{
    u8 flag;

    switch (pData->pose)
    {
        case SPOSE_SPINNING:
            if (gSamusPhysics.slowed_by_liquid != FALSE)
                break;

            if ((pEquipment->suit_misc_activation & SMF_SCREW_ATTACK) == 0x0)
            {
                if (pEquipment->suit_misc_activation & SMF_SPACE_JUMP)
                    pData->pose = SPOSE_SPACE_JUMPING;
                break;
            }
            pData->pose = SPOSE_SCREW_ATTACKING;
            break;

        case SPOSE_SPACE_JUMPING:
            flag = pEquipment->suit_misc_activation & SMF_SCREW_ATTACK;
            if (flag != 0x0)
                pData->pose = SPOSE_SCREW_ATTACKING;
            else
            {
                if (pEquipment->suit_misc_activation & SMF_SPACE_JUMP && !gSamusPhysics.slowed_by_liquid)
                    break;
                pData->pose = SPOSE_SPINNING;
                pData->curr_anim_frame = flag;
            }
            break;

        case SPOSE_SCREW_ATTACKING:
            if (gSamusPhysics.slowed_by_liquid != FALSE)
            {
                pData->pose = SPOSE_SPINNING;
                pData->curr_anim_frame = 0x0;
            }
            else
            {
                if ((pEquipment->suit_misc_activation & SMF_SCREW_ATTACK) == 0x0)
                {
                    if (pEquipment->suit_misc_activation & SMF_SPACE_JUMP)
                        pData->pose = SPOSE_SPACE_JUMPING;
                    else
                        pData->pose = SPOSE_SPINNING;
                    pData->curr_anim_frame = 0x0;
                }
            }
            gScrewSpeedAnimation.flag = FALSE;
    }
}

void SamusApplyXAcceleration(i16 acceleration, i16 velocity, struct SamusData* pData)
{

}

u8 SamusTakeHazardDamage(struct SamusData* pData, struct Equipment* pEquipment, struct HazardDamage* pHazard)
{

}

void SamusCheckShinesparking(struct SamusData* pData)
{
    /*u8 pose;

    pose = pData->pose;

    switch (pose)
    {
        case SPOSE_SHINESPARKING:
            pData->speedboosting_shinesparking = TRUE;
            break;
        case SPOSE_BALLSPARKING:
            pData->speedboosting_shinesparking = TRUE;
            break;
        default:
            if ((u16)(pData->x_velocity + 0x9F) >= 0x13F)
            {
                if (pData->speedboosting_shinesparking != FALSE) return;
                if (pose != SPOSE_SKIDDING)
                {
                    pData->speedboosting_shinesparking = TRUE;
                    SoundPlay(0x8B);
                }
                break;
            }
            else
            {
                if (pData->speedboosting_shinesparking == FALSE)
                    SoundStop(0x8B);
                return;
            }

        case SPOSE_DYING:
            pData->speedboosting_shinesparking = FALSE;
    }

    if (pData->speedboosting_shinesparking == FALSE)
        SoundStop(0x8B);*/
}

u8 SamusInactivity(struct SamusData* pData)
{
    return SPOSE_NONE;
}

u8 SamusUpdateAnimation(struct SamusData* pData, u8 slowed)
{

}

u8 SamusRunning(struct SamusData* pData)
{
    /*u8 new_pose;
    i32 x_velocity;

    if ((gChangedInput & KEY_A) != 0x0)
    {
        pData->forced_movement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    x_velocity = gSamusPhysics.x_velocity_cap;
    if ((gEquipment.suit_misc_activation & SMF_SPEED_BOOSTER) != 0x0 && gSamusPhysics.slowed_by_liquid == FALSE)
    {
        if (pData->timer >= 0x8C)
            x_velocity = 0xA0;
        else
        {
            if (0x77 < pData->timer)
                x_velocity = 0x8C;
        }

        if ((u16)((u16)pData->x_velocity + 0x5F) >= 0xBF)
        {
            if (0x9F >= (u8)pData->timer)
                pData->timer++;
        }
    }
    else
        pData->timer = 0x0;


    if ((gButtonInput & pData->direction) != 0x0)
    {
        SamusApplyXAcceleration(gSamusPhysics.x_acceleration, x_velocity, pData);
        SamusAimCannon(pData);
        return SPOSE_NONE;
    }
    else
    {
        if (pData->speedboosting_shinesparking != FALSE)
            return SPOSE_SKIDDING;
        else if (gSamusPhysics.has_new_projectile != 0x0)
            return SPOSE_SHOOTING;
        else if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput) == 0x0)
            return SPOSE_STANDING;
        else
            return SPOSE_TURNING_AROUND;
    }*/
}

u8 SamusRunningGFX(struct SamusData* pData)
{

}

u8 SamusStanding(struct SamusData* pData)
{

}

u8 SamusStandingGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
        pData->curr_anim_frame = 0x0;

    return SPOSE_NONE;
}

u8 SamusTurningAround(struct SamusData* pData)
{
    u8 new_pose;

    if ((gButtonInput & (KEY_RIGHT | KEY_LEFT)) == 0x0 && (gChangedInput & KEY_A) != 0x0 && pData->shinespark_timer != 0x0 && SamusCheckCollisionAbove(pData, (i16)((u16)samus_hitbox_data[0x0][0x2] - 0x20)) << 0x18 == 0x0)
    {
        pData->y_position -= 0x20;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }
    else
    {
        if (SamusCheckAButtonPressed(pData) << 0x18 != FALSE)
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        else
        {
            if ((gChangedInput & KEY_DOWN) != 0x0 && (gSamusWeaponInfo.diagonal_aim == DIAG_AIM_NONE || pData->arm_cannon_direction == ACD_DIAGONALLY_DOWN))
            {
                pData->pose = SPOSE_TURNING_AROUND_AND_CROUCHING;
                if (gEquipment.suit_type != SUIT_SUITLESS)
                    SoundPlay(0x79);
            }
            if (gSamusPhysics.has_new_projectile != 0x0)
            {
                if (pData->pose == SPOSE_TURNING_AROUND_AND_CROUCHING)
                    return SPOSE_SHOOTING_AND_CROUCHING;
                else
                    return SPOSE_SHOOTING;
            }
            else
                return SPOSE_NONE;
        }
    }
}

u8 SamusTurningAroundGFX(struct SamusData* pData)
{
    u8 unk;
    u16* input;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        input = &gButtonInput;
        if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & *input) != 0x0)
            return SPOSE_RUNNING;
        else if (gEquipment.suit_type == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

u8 samus_shooting_gfx(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_STANDING;
    else
        return SPOSE_NONE;
}

u8 SamusCrouching(struct SamusData* pData)
{
    /*u8 unk;
    u16 x_position;
    struct WeaponInfo* pWeapon;
    u16* input;
    u32 timer;

    if ((gButtonInput & (KEY_RIGHT | KEY_LEFT)) == 0x0 && (gChangedInput & KEY_A) != 0x0 && pData->shinespark_timer != 0x0 && SamusCheckCollisionAbove(pData, (i16)((u16)array_23a554[0x2] - 0x20)) << 0x18 == 0x0)
    {
        pData->y_position -= 0x20;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }

    unk = SamusCheckCollisionAbove(pData, array_23a554[0x2]);
    if (unk == 0x1)
        x_position = (pData->x_position & 0xFFC0) - (u16)array_23a554[0];
    else if (unk == 0x8)
        x_position = (pData->x_position & 0xFFC0) - (u16)array_23a554[0] + 0x3F;

    if (SamusCheckAButtonPressed(pData) << 0x18 != FALSE && (unk & 0x6) == 0x0)
    {
        if (unk == 0x1 || unk == 0x8)
            pData->x_position = x_position;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if ((gChangedInput & KEY_UP) == 0x0 || (unk & 0x6) != 0x0 || gSamusWeaponInfo.diagonal_aim == DIAG_AIM_NONE || pData->arm_cannon_direction == ACD_DIAGONALLY_UP)
    {
        if (unk == 0x1 || unk == 0x8)
            pData->x_position = x_position;
        pData->last_wall_touched_midair = 0x6;
        
        if (gEquipment.suit_type == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
    {
        if ((gChangedInput & KEY_DOWN) != 0x0 && (gEquipment.suit_misc_activation & SMF_MORPH_BALL) != 0x0 && (gSamusWeaponInfo.diagonal_aim == DIAG_AIM_NONE || pData->arm_cannon_direction == ACD_DIAGONALLY_DOWN))
        {
            SoundPlay(0x77);
            return SPOSE_MORPHING;
        }

        SamusAimCannon(pData);
        if (pData->arm_cannon_direction == ACD_UP)
            pData->arm_cannon_direction = ACD_FORWARD;

        if (gSamusPhysics.has_new_projectile != PROJECTILE_NONE)
            return SPOSE_SHOOTING_AND_CROUCHING;
        
        input = &gButtonInput;
        if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & *input) != 0x0)
            return SPOSE_TURNING_AROUND_AND_CROUCHING;

        if ((gButtonInput & pData->direction) != 0x0)
        {
            if ((unk & 0x6) == 0x0)
            {
                timer = pData->timer;
                pData->timer = timer + 1;
                if (0x5 < (u8)timer)
                {
                    if (unk == 0x1 || unk == 0x8)
                        pData->x_position = x_position;

                    if (gEquipment.suit_type == SUIT_SUITLESS)
                        return SPOSE_UNCROUCHING_SUITLESS;
                    else
                        return SPOSE_STANDING; 
                }
            }
        }
        else
            pData->timer = 0x0;

        return SPOSE_NONE;
    }*/
}

u8 SamusTurningAroundAndCrouching(struct SamusData* pData)
{
    u8 unk;
    u16 x_position;

    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gChangedInput & KEY_A && pData->shinespark_timer != 0x0 && SamusCheckCollisionAbove(pData, (i16)((u16)samus_hitbox_data[0x0][0x2] - 0x20)) << 0x18 == 0x0)
    {
        pData->y_position -= 0x20;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }
    else
    {
        unk = SamusCheckCollisionAbove(pData, samus_hitbox_data[0x0][0x2]);
        if (unk == 0x1)
            x_position = (pData->x_position & 0xFFC0) - (u16)samus_hitbox_data[0x0][0x0];
        else if (unk == 0x8)
            x_position = (pData->x_position & 0xFFC0) - (u16)samus_hitbox_data[0x0][0x0] + 0x3F;

        if (SamusCheckAButtonPressed(pData) << 0x18 != FALSE && (unk & 0x6) == 0x0)
        {
            if (unk == 0x1 || unk == 0x8)
                pData->x_position = x_position;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        else
        {
            if ((gChangedInput & KEY_UP) != 0x0 && (unk & 0x6) == 0x0 && (gSamusWeaponInfo.diagonal_aim == 0x0 || pData->arm_cannon_direction == ACD_DIAGONALLY_UP))
            {
                if (unk == 0x1 || unk == 0x8)
                    pData->x_position = x_position;
                pData->pose = SPOSE_TURNING_AROUND;

            }

            if (gSamusPhysics.has_new_projectile != 0x0)
            {
                if (pData->pose == SPOSE_TURNING_AROUND)
                    return SPOSE_SHOOTING;
                else
                    return SPOSE_SHOOTING_AND_CROUCHING;
            }
            else
                return SPOSE_NONE;
        }
    }
}

u8 SamusTurningAroundAndCrouchingGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
    {
        if (gEquipment.suit_type == SUIT_SUITLESS)
            return SPOSE_CROUCHING_SUITLESS;
        else
            return SPOSE_CROUCHING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusShootingAndCrouchingGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_CROUCHING;
    else
        return SPOSE_NONE;
}

u8 SamusSkidding(struct SamusData* pData)
{
    i32 velocity;

    if ((gChangedInput & KEY_A) != 0x0)
    {
        pData->forced_movement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    
    if ((gButtonInput & pData->direction) != 0x0)
        return SPOSE_RUNNING;
    else
    {
        if ((gButtonInput & (KEY_RIGHT | KEY_LEFT | KEY_UP | KEY_DOWN)) == KEY_DOWN)
        {
            pData->shinespark_timer = 0xB4;
            gScrewSpeedAnimation.flag = 0x8;
            if (gEquipment.suit_type == SUIT_SUITLESS)
                return SPOSE_CROUCHING_SUITLESS;
            else
                return SPOSE_CROUCHING;
        }

        if ((pData->direction & KEY_RIGHT) != 0x0)
        {
            velocity = (u16)pData->x_velocity - 0xA;
            pData->x_velocity = velocity;
            if (0x0 >= (velocity << 0x10))
                return SPOSE_STANDING;
        }
        else
        {
            velocity = (u16)pData->x_velocity + 0xA;
            pData->x_velocity = velocity;
            if ((velocity << 0x10) >= 0x0)
                return SPOSE_STANDING;
        }
        
        return SPOSE_NONE;
    }
}

u8 SamusMidAir(struct SamusData* pData)
{

}

u8 SamusMidAirGFX(struct SamusData* pData)
{
    u8 unk;

    if (pData->y_velocity >= 0x0)
    {
        if (pData->curr_anim_frame == 0x2)
            pData->anim_duration_counter = 0x0;
    }
    else
    {
        if (pData->curr_anim_frame < 0x2)
            pData->curr_anim_frame = 0x2;
    }

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        pData->curr_anim_frame = 0x4;

    return SPOSE_NONE;
}

u8 SamusTurningAroundMidAir(struct SamusData* pData)
{
    if (gChangedInput & KEY_A)
    {
        if (pData->shinespark_timer != 0x0)
            return SPOSE_DELAY_BEFORE_SHINESPARKING;

        if (!(gButtonInput & (KEY_UP | KEY_DOWN)))
        {
            pData->pose = SPOSE_SPINNING;
            pData->direction ^= (KEY_RIGHT | KEY_LEFT);
            pData->curr_anim_frame = 0x0;
            pData->anim_duration_counter = 0x0;
            pData->turning = FALSE;
            return SPOSE_NONE;
        }
    }

    if (gSamusPhysics.has_new_projectile != 0x0)
    {
        pData->forced_movement = 0x2;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
    {
        if (!(gButtonInput & KEY_A) && 0x0 < pData->y_velocity)
            pData->y_velocity = 0x0;
        return SPOSE_NONE;
    }
}

u8 SamusTurningAroundMidAirGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
    {
        pData->forced_movement = 0x2;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
        return SPOSE_NONE;
}

u8 SamusStartingSpinJumpGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
    {
        pData->pose = SPOSE_SPINNING;
        pData->curr_anim_frame = 0x0;
    }

    return SPOSE_NONE;
}

u8 SamusSpinning(struct SamusData* pData)
{
    /*i32 acceleration;
    u16 direction;
    u16* input;

    if (gSamusPhysics.has_new_projectile != 0x0)
    {
        pData->forced_movement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
    {
        if ((gButtonInput & (KEY_RIGHT | KEY_LEFT)) == 0x0 && (gButtonInput & (KEY_UP | KEY_DOWN)) != 0x0)
        {
            pData->forced_movement = 0x2;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        else
        {
            SamusAimCannon(pData);
            acceleration = gSamusPhysics.midair_x_acceleration;
            if ((gEquipment.suit_misc_activation & SMF_SPACE_JUMP) != 0x0 && gSamusPhysics.slowed_by_liquid == FALSE)
            {
                if ((gChangedInput & KEY_A) != 0x0 && pData->y_velocity <= -0x40)
                {
                    if ((gEquipment.suit_misc_activation & SMF_HIGH_JUMP) != 0x0)
                        pData->y_velocity = 0xE8;
                    else
                        pData->y_velocity = 0xC0;
                    
                    return SPOSE_NONE;
                }
            }
            else
            {
                if (pData->walljump_timer != 0x0)
                {
                    pData->walljump_timer--;
                    if ((pData->direction & pData->last_wall_touched_midair) != 0x0)
                    {
                        if ((gChangedInput & KEY_A) != 0x0)
                        {
                            
                            if ((pData->last_wall_touched_midair & KEY_RIGHT) != 0x0)
                                acceleration = -0x28;
                            else
                                acceleration = 0x28;
                            
                            if ((ClipdataProcessForSamus(pData->y_position, (u16)(pData->x_position + acceleration)) & 0x1000000) != 0x0)
                            {
                                pData->direction = pData->last_wall_touched_midair;
                                return SPOSE_STARTING_WALL_JUMP;
                            }
                        }
                        acceleration = 0x1;
                    }
                }
            }

            input = &gButtonInput;
            direction = pData->direction ^ (KEY_RIGHT | KEY_LEFT);
            if ((direction & *input) != 0x0)
            {
                pData->direction = direction;
                pData->x_velocity = 0x0;
            }
            else
                SamusApplyXAcceleration(acceleration, gSamusPhysics.midair_x_velocity_cap, pData);

            if ((gButtonInput & KEY_A) == 0x0 && 0x0 < pData->y_velocity)
                pData->y_velocity = 0x0;

            return SPOSE_NONE;
        }
    }*/
}

u8 SamusSpinningGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, gSamusPhysics.slowed_by_liquid);
    if (unk == 0x2)
        pData->curr_anim_frame = 0x0;

    if (*(u16*)&pData->anim_duration_counter == 0x1)
    {
        if (gSamusPhysics.slowed_by_liquid != FALSE)
            SoundPlay(0x92);
        else if (gEquipment.suit_type != SUIT_SUITLESS)
            SoundPlay(0x6A);
        else
            SoundPlay(0x98);
    }

    return SPOSE_NONE;
}

u8 SamusStartingWallJump(struct SamusData* pData)
{
    u16 input;

    if (gSamusPhysics.has_new_projectile != 0x0)
    {
        pData->forced_movement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else 
    {
        input = gButtonInput & (KEY_RIGHT | KEY_LEFT);
        if (input == 0x0 && (gButtonInput & (KEY_UP | KEY_DOWN)) != 0x0)
        {
            pData->forced_movement = input;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        else
            return SPOSE_NONE;
    }
}

u8 SamusStartingWallJumpGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        pData->forced_movement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
        return SPOSE_NONE;
}

u8 SamusSpaceJumpingGFX(struct SamusData* pData)
{
    u8 unk;

    if (*(u16*)&pData->anim_duration_counter == 0x1)
    {
        if (gSamusPhysics.slowed_by_liquid != FALSE)
            SoundPlay(0x6B);
        else
            SoundPlay(0x6B);
    }

    unk = SamusUpdateAnimation(pData, gSamusPhysics.slowed_by_liquid);
    if (unk == 0x2)
        pData->curr_anim_frame = 0x0;

    return SPOSE_NONE;
}

u8 SamusCrewAttackingGFX(struct SamusData* pData)
{

}

u8 SamusMorphing(struct SamusData* pData)
{
    if ((gChangedInput & KEY_UP) != 0x0)
        pData->pose = SPOSE_UNMORPHING;

    return SPOSE_NONE;
}

u8 SamusMorphingGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_MORPH_BALL;
    else
        return SPOSE_NONE;
}

u8 SamusMorphball(struct SamusData* pData)
{
    /*u8 forced_movement;

    forced_movement = pData->forced_movement;
    if (0x15 < forced_movement)
    {
        pData->forced_movement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (forced_movement >= 0x14)
        pData->forced_movement = forced_movement + 0x1;
    else
    {
        if ((gChangedInput & KEY_A) != 0x0 && (gEquipment.suit_misc_activation & SMF_HIGH_JUMP) != 0x0 & pData->shinespark_timer != 0x0 && SamusCheckCollisionAbove(pData, (i16)((u16)array_23a554[0x5] - 0x40)) << 0x18 == 0x0)
        {
            pData->y_position -= 0x20;
            return SPOSE_DELAY_BEFORE_BALLSPARKING;
        }

        if (SamusCheckAButtonPressed(pData) << 0x18 != FALSE)
        {
            if (pData->forced_movement != 0x1)
                return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;

            if ((gEquipment.suit_misc_activation & SMF_HIGH_JUMP) != 0x0)
                return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;

            pData->forced_movement = 0x0;
        }

        if ((gButtonInput & (KEY_RIGHT | KEY_LEFT)) != 0x0)
        {
            pData->direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);
            return SPOSE_ROLLING;
        }

        if ((gChangedInput & KEY_UP) != 0x0)
        {
            forced_movement = SamusCheckCollisionAbove(pData, array_23a554[0x2]);
            if (forced_movement == 0x1)
            {
                pData->x_position = (u16)(pData->x_position + array_23a554[0x0] & 0xFFC0) - array_23a554[0x0] + 0x40;
                gPreviousXPosition = pData->x_position;

                if (gSamusPhysics.slowed_by_liquid != FALSE)
                    SoundPlay(0x78);
                else
                    SoundPlay(0x78);

                return SPOSE_UNMORPHING;
            }

            if (forced_movement == 0x8)
            {
                pData->x_position = (u16)(pData->x_position + array_23a554[0x0] & 0xFFC0) - array_23a554[0x0] + 0x40;
                gPreviousXPosition = pData->x_position;
                forced_movement = 0x0;
            }

            if (forced_movement == 0x0)
            {
                if (gSamusPhysics.slowed_by_liquid != FALSE)
                    SoundPlay(0x78);
                else
                    SoundPlay(0x78);

                return SPOSE_UNMORPHING;
            }
        }

        if (pData->timer != 0x0)
        {
            pData->timer--;
            if ((gButtonInput & (KEY_RIGHT | KEY_LEFT | KEY_UP | KEY_DOWN)) == KEY_DOWN)
            {
                pData->shinespark_timer = 0xB4;
                pData->timer = 0x0;
                gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_STORING_SHINESPARK;
            }
        }
    }

    return SPOSE_NONE;*/
}

u8 SamusRolling(struct SamusData* pData)
{
    /*i32 velocity;

    if ((gChangedInput & KEY_A) != 0x0 && (gEquipment.suit_misc_activation & SMF_HIGH_JUMP) != 0x0)
    {
        pData->forced_movement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
    {
        if (SamusCheckCollisionAbove(pData, array_23a554[0x2]) << 0x18 == 0x0 && (gChangedInput & KEY_UP) != 0x0)
        {
            if (gSamusPhysics.slowed_by_liquid != FALSE)
                SoundPlay(0x78);
            else
                SoundPlay(0x78);

            return SPOSE_UNMORPHING;
        }
        else
        {
            if ((gButtonInput & pData->direction) != 0x0)
            {
                velocity = gSamusPhysics.x_velocity_cap;
                if (pData->speedboosting_shinesparking != FALSE)
                {
                    velocity = 0xA0;
                    pData->shinespark_timer = 0x6;
                }
                SamusApplyXAcceleration(gSamusPhysics.x_acceleration, velocity, pData);
                return SPOSE_NONE;
            }
            else
            {
                if ((((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput) << 0x10) != 0x0)
                    pData->turning = TRUE;

                return SPOSE_MORPH_BALL;
            }
        }
    }*/
}

u8 SamusRollingGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
        pData->curr_anim_frame = 0x0;
    else if (animState == SAMUS_ANIM_STATE_SUB_ENDED && (pData->curr_anim_frame == 0x1 || pData->curr_anim_frame == 0x5))
        SamusCheckSetEnvironmentalEffect(pData, 0x0, WANTING_RUNNING_ON_WET_GROUND);

    return SPOSE_NONE;
}

u8 SamusUnmorphing(struct SamusData* pData)
{
    u8 unk;

    unk = SamusCheckCollisionAbove(pData, samus_hitbox_data[0x0][0x2]);
    if (unk == 0x0)
    {
        if ((gChangedInput & KEY_A) != 0x0)
        {
            pData->forced_movement = 0x1;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        if ((gChangedInput & KEY_DOWN) == 0x0)
            return SPOSE_NONE;
    }
    pData->pose = SPOSE_MORPHING;
    return SPOSE_NONE;
}

u8 SamusUnmorphingGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        pData->unmorph_palette_timer = 0xF;
        return SPOSE_CROUCHING;
    }
    return SPOSE_NONE;
}

u8 SamusMorphballMidAir(struct SamusData* pData)
{
    /*u16 direction;

    if ((gChangedInput & KEY_UP) != 0x0 && SamusCheckCollisionAbove(pData, array_23a554[0x2]) << 0x18 == 0x0)
    {
        if (gSamusPhysics.slowed_by_liquid == TRUE)
            SoundPlay(0x78);
        else
            SoundPlay(0x78);
        
        pData->unmorph_palette_timer = 0xF;
        return SPOSE_MIDAIR;
    }

    if (pData->forced_movement == 0x0)
    {
        if ((gButtonInput & KEY_A) == 0x0 && 0x0 < pData->y_velocity)
            pData->y_velocity = 0x0;
    }
    else
    {
        if (pData->y_velocity < 0x7)
            pData->forced_movement = 0x0;
    }

    if (pData->y_velocity >= 0x0 && (pData->x_velocity != 0x0 || (gButtonInput & pData->direction) != 0x0))
        SamusApplyXAcceleration(gSamusPhysics.midair_x_acceleration, gSamusPhysics.midair_morphed_x_velocity_cap, pData);
    else
    {
        direction = pData->direction ^ (KEY_RIGHT | KEY_LEFT);
        if ((direction & gButtonInput) != 0x0)
            pData->direction = direction;
        pData->x_velocity = 0x0;
    }

    return SPOSE_NONE;*/
}

u8 SamusHangingOnLedge(struct SamusData* pData)
{
    /*
    // /!\ Wrong code order
    u16 x_position;
    u32 block_above;
    u32 block_above_offset;
    u8 acd;
    u8 forced_movement;
    u16 direction;

    if (gScreenShakeX.timer > 0x1D)
    {
        // Release if screen shake active
        pData->forced_movement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (pData->direction & KEY_RIGHT)
        x_position = pData->x_position + 0x20;
    else
        x_position = pData->x_position - 0x20;

    // Check blocks above samus, and with solid flag
    block_above_offset = ClipdataProcessForSamus(pData->y_position - 0xD0, x_position) & 0x1000000;
    block_above = ClipdataProcessForSamus(pData->y_position - 0xD0, pData->x_position) & 0x1000000;

    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & pData->direction)
        {
            if (!block_above_offset && !block_above)
                return SPOSE_PULLING_YOURSELF_UP_FROM_HANGING;
            
            if (gEquipment.suit_misc_activation & SMF_MORPH_BALL)
                return SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL;
        }

        direction = pData->direction ^ (KEY_RIGHT | KEY_LEFT); // Get opposite direction
        if (direction & gButtonInput)
        {
            pData->direction = direction;
            pData->forced_movement = 0x1;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }

        if (gButtonInput & KEY_DOWN)
        {
            pData->forced_movement = 0x0;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }

        pData->forced_movement = 0x2;
        pData->y_velocity = 0x90;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (gSamusPhysics.has_new_projectile != 0x0)
    {
        pData->direction ^= (KEY_RIGHT | KEY_LEFT); // Set opposite direction
        if (gButtonInput & KEY_DOWN)
            pData->arm_cannon_direction = ACD_DOWN;
        else
            pData->arm_cannon_direction = ACD_UP;

        return SPOSE_SHOOTING_WHILE_HANGING;
    }

    if (gEquipment.suit_type != SUIT_SUITLESS && gSamusWeaponInfo.charge_counter != 0x0)
    {
        pData->direction ^= (KEY_RIGHT | KEY_LEFT); // Set opposite direction
        if (gButtonInput & KEY_DOWN)
            pData->arm_cannon_direction = ACD_DOWN;
        else
            pData->arm_cannon_direction = ACD_UP;
            
        return SPOSE_AIMING_WHILE_HANGING;
    }

    if (gButtonInput & gButtonAssignments.diagonal_aim || gButtonInput & (KEY_UP | KEY_DOWN) || (pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput)
    {
        pData->direction ^= (KEY_RIGHT | KEY_LEFT); // Set opposite direction
        return SPOSE_TURNING_TO_AIM_WHILE_HANGING;
    }

    return SPOSE_NONE;*/
}

u8 SamusHangingOnLedgeGFX(struct SamusData* pData)
{
    u8 anim_state;

    anim_state = SamusUpdateAnimation(pData, gSamusPhysics.slowed_by_liquid);
    if (anim_state == SAMUS_ANIM_STATE_ENDED)
        pData->curr_anim_frame = 0x0;

    return SPOSE_NONE;
}

u8 SamusTurningToAimWhileHanging(struct SamusData* pData)
{

}

u8 SamusTurningToAimWhileHangingGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, gSamusPhysics.slowed_by_liquid);
    if (unk == 0x2)
        return SPOSE_AIMING_WHILE_HANGING;
    else
        return SPOSE_NONE;
}

u8 SamusHidingArmCannonWhileHangingGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, gSamusPhysics.slowed_by_liquid);
    if (unk == 0x2)
    {
        pData->direction ^= (KEY_RIGHT | KEY_LEFT);
        return SPOSE_HANGING_ON_LEDGE;
    }
    else
        return SPOSE_NONE;
}

u8 SamusAimingWhileHanging(struct SamusData* pData)
{

}

u8 SamusPullingSelfUp(struct SamusData* pData)
{
    u16 offset;

    offset = SamusPullingSelfUp_velocity[pData->curr_anim_frame];
    if (pData->timer != 0x0)
        offset >>= 0x1;

    pData->y_position -= offset;
    return SPOSE_NONE;
}

u8 SamusPullingSelfUpGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, pData->timer);
    if (unk == 0x2)
    {
        pData->y_position = (pData->y_position & 0xFFC0) - 0x1;
        return SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusPullingSelfForward(struct SamusData* pData)
{
    if ((pData->direction & KEY_RIGHT) != 0x0)
        pData->x_position += 0x4;
    else
        pData->x_position -= 0x4;

    return SPOSE_NONE;
}

u8 SamusPullingSelfForwardGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);

    if (unk == 0x2)
    {
        if (gEquipment.suit_type == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusPullingSelfIntoMorphballTunnelGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, pData->timer);
    if (unk == 0x2)
    {
        if ((pData->direction & KEY_RIGHT) != 0x0)
            pData->x_position += 0x6;
        else
            pData->x_position -= 0x6;

        pData->y_position = (pData->y_position & 0xFFC0) - 0x1;
        play_sound(0x77);
        return SPOSE_MORPH_BALL;
    }
    else
        return SPOSE_NONE;
}

u8 SamusUsingAnElevator(struct SamusData* pData)
{
    // https://decomp.me/scratch/ZYuqG
}

u8 SamusUsingAnElevatorGFX(struct SamusData* pData)
{

}

u8 SamusFacingTheForeground(struct SamusData* pData)
{
    u16 direction;

    direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);

    if (direction != 0x0 && pData->last_wall_touched_midair == 0x0)
    {
        pData->direction = direction;
        return SPOSE_TURNING_FROM_FACING_THE_FOREGROUND;
    }
    else
        return SPOSE_NONE;
}

u8 SamusTurningFromFacningForegroundGFX(struct SamusData* pData)
{
    if (pData->anim_duration_counter >= 0x2)
    {
        if (pData->elevator_direction != 0x0)
            return SPOSE_USING_AN_ELEVATOR;
        else if (pData->timer != 0x0)
            return SPOSE_SAVING_LOADING_GAME;
        else if (gEquipment.suit_type == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusDelayBeforeShinesparkingGFX(struct SamusData* pData)
{
    u8 unk;
    u16* input;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        input = &gButtonInput;
        if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & *input) != 0x0)
            pData->turning = TRUE;
        return SPOSE_SHINESPARKING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusShinesparking(struct SamusData* pData)
{

}

u8 SamusShinesparkingGFX(struct SamusData* pData)
{

}

u8 SamusShinesparkCollisionGFX(struct SamusData* pData)
{
    if (pData->anim_duration_counter >= 0x11)
        return SPOSE_DELAY_AFTER_SHINESPARKING;
    else
        return SPOSE_NONE;
}

u8 SamusDelayAfterShinesparkingGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else
        return SPOSE_NONE;
}

u8 SamusDelayBeforeBallsparking(struct SamusData* pData)
{

}

u8 SamusDelayBeforeBallsparkingGFX(struct SamusData* pData)
{

}

u8 SamusBallsparkingGFX(struct SamusData* pData)
{

}

u8 SamusBallsparkCollisionGFX(struct SamusData* pData)
{
    if (pData->anim_duration_counter >= 0x11)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else
        return SPOSE_NONE;
}

u8 SamusOnZipline(struct SamusData* pData)
{
    u16* input;

    if ((gChangedInput & KEY_A) != 0x0)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else if (gSamusPhysics.has_new_projectile != 0x0)
        return SPOSE_SHOOTING_ON_ZIPLINE;
    else if (pData->pose != SPOSE_ON_ZIPLINE)
        return SPOSE_NONE;
    else
    {
        input = &gButtonInput;
        if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & *input) == 0x0)
        {
            SamusAimCannon(pData);
            return SPOSE_NONE;
        }
        return SPOSE_TURNING_ON_ZIPLINE;
    }
}

u8 SamusShootingOnZiplineGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_ON_ZIPLINE;
    else
        return SPOSE_NONE;
}

u8 SamusMorphballOnZipline(struct SamusData* pData)
{
    u16 direction;

    if ((gChangedInput & KEY_A) != 0x0)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else
    {
        direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);
        if (direction != 0x0)
            pData->direction = direction;
        return SPOSE_NONE;
    }
}

u8 SamusSavingLoadingGame(struct SamusData* pData)
{
    if (pData->timer != 0x0)
    {
        pData->curr_anim_frame = 0x0;
        pData->anim_duration_counter = 0x0;
    }

    return SPOSE_NONE;
}

u8 SamusTurningAround_to_download_map_data_gfx(struct SamusData* pData)
{
    u8 anim_state;

    anim_state = SamusUpdateAnimation(pData, FALSE);
    if (anim_state == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_DOWNLOADING_MAP_DATA; // Set downloading if turning around ended
    else
        return SPOSE_NONE;
}

/**
 * @brief Subroutine for the getting hurt pose
 * 
 * @param pData Samus Data Pointer
 * @return u8 New Pose
 */
u8 SamusGettingHurt(struct SamusData* pData)
{
    u8 forced_movement;

    forced_movement = 0x0;
    if (pData->forced_movement != 0x0 && (u16)(pData->y_velocity + 0x7) < 0xF && pData->last_wall_touched_midair++ < 0xA)
    {
        gSamusPhysics.y_acceleration = 0x0;
        forced_movement = 0x1;
    }

    if (forced_movement == 0x0 && pData->timer++ > 0xC && pData->y_velocity < -0x10)
    {
        pData->forced_movement = forced_movement;

        if (pData->pose == SPOSE_GETTING_HURT) // Set mid air pose
            return SPOSE_MIDAIR;

        return SPOSE_MORPH_BALL_MIDAIR;
    }
    return SPOSE_NONE;
}

u8 SamusGettingHurtGFX(struct SamusData* pData)
{
    u8 anim_state;

    anim_state = SamusUpdateAnimation(pData, FALSE);
    if (anim_state == SAMUS_ANIM_STATE_ENDED)
        pData->curr_anim_frame--; // Alternate between last frames

    return SPOSE_NONE;
}

u8 SamusGettingKnockedBack(struct SamusData* pData)
{
    if (pData->timer >= 0xD)
    {
        if (pData->y_velocity < -0x20)
        {
            if (pData->pose == SPOSE_GETTING_KNOCKED_BACK)
                return SPOSE_MIDAIR;
        }
        return SPOSE_MORPH_BALL_MIDAIR;
    }
    else
        pData->timer++;
    return SPOSE_NONE;
}

u8 SamusDying(struct SamusData* pData)
{

}

u8 SamusCrouchingToCrawlGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        if ((pData->direction & KEY_RIGHT) != 0x0)
            pData->x_position += 0x4;
        else
            pData->x_position -= 0x4;
        
        return SPOSE_STARTING_TO_CRAWL;
    }
    else
        return SPOSE_NONE;
}

u8 SamusCrawlingStopped(struct SamusData* pData)
{
    pData->x_velocity = 0x0;
    if (SamusCheckCollisionAbove(pData, samus_hitbox_data[0x0][0x2]) << 0x18 == 0x0)
        return SPOSE_UNCROUCHING_FROM_CRAWLING;
    else if (gSamusPhysics.has_new_projectile != 0x0)
        return SPOSE_SHOOTING_WHILE_CRAWLING;
    else if ((gButtonInput & pData->direction) != 0x0)
        return SPOSE_CRAWLING;
    else if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput) == 0x0)
        return SPOSE_NONE;
    else
        return SPOSE_TURNING_AROUND_WHILE_CRAWLING;
}

u8 SamusStartingToCrawlGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_CRAWLING_STOPPED;
    else
        return SPOSE_NONE;
}

u8 SamusCrawling(struct SamusData* pData)
{
    if (SamusCheckCollisionAbove(pData, samus_hitbox_data[0x0][0x2]) << 0x18 == 0x0)
        return SPOSE_UNCROUCHING_FROM_CRAWLING;
    else
    {
        if (gSamusPhysics.has_new_projectile != 0x0)
            return SPOSE_SHOOTING_WHILE_CRAWLING;
        else
        {
            if ((gButtonInput & pData->direction) != 0x0)
            {
                SamusApplyXAcceleration(gSamusPhysics.x_acceleration, 0x20, pData);
                return SPOSE_NONE;
            }
            else
            {
                if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput) != 0x0)
                    pData->turning = TRUE;

                return SPOSE_CRAWLING_STOPPED;
            }
        }
    }
}

u8 SamusDyingGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        pData->curr_anim_frame = 0x0;
    else if (unk == 0x1 && (pData->curr_anim_frame == 0x1 || pData->curr_anim_frame == 0x4))
        SamusCheckSetEnvironmentalEffect(pData, 0x0, WANTING_RUNNING_ON_WET_GROUND);

    if (*(u16*)&pData->anim_duration_counter == 0x1)
        SoundPlay(0x9E);

    return SPOSE_NONE;
}

u8 SamusTurningAroundWhileCrawling(struct SamusData* pData)
{
    if (gSamusPhysics.has_new_projectile != 0x0)
        return SPOSE_SHOOTING_WHILE_CRAWLING;
    else
        return SPOSE_NONE;
}

u8 SamusCrawlingGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (unk == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_STARTING_TO_CRAWL;
    else
        return SPOSE_NONE;
}

u8 SamusGrabbingALedgeSuitlessGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_HANGING_ON_LEDGE;
    else
        return SPOSE_NONE;
}

u8 SamusFacingTheBackground(struct SamusData* pData)
{
    u16 direction;

    direction = (gButtonInput & (KEY_RIGHT | KEY_LEFT));
    if (direction != 0x0 && pData->last_wall_touched_midair == 0x0)
    {
        pData->direction = direction;
        return SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS;
    }
    else
        return SPOSE_NONE;
}

u8 SamusTurningFromFacingTheBackgroundGFX(struct SamusData* pData)
{
    u8 unk;
    u16* input;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        input = &gButtonInput;
        if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & *input) != 0x0)
            return SPOSE_RUNNING;
        else if (pData->last_wall_touched_midair != 0x0)
            return SPOSE_FACING_THE_BACKGROUND_SUITLESS;
        else if (gEquipment.suit_type == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusTurningToEnterEscapeShipGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_IN_ESCAPE_SHIP;
    else
        return SP_NONE;
}

u8 SamusExecutePoseSubroutine(struct SamusData* pData)
{
    u8 pose;
    u8 timer;
    struct WeaponInfo* pWeapon;
    struct Equipment* pEquipment;
    struct HazardDamage* pHazard;

    pWeapon = &gSamusWeaponInfo;
    pEquipment = &gEquipment;
    pHazard = &gSamusHazardDamage;

    if (SamusTakeHazardDamage(pData, pEquipment, pHazard) << 0x18)
        return SPOSE_HURT_REQUEST;
    else
    {
        if (pWeapon->cooldown != 0x0)
            pWeapon->cooldown--;

        if (pData->shinespark_timer != 0x0 && pData->pose != SPOSE_DELAY_BEFORE_SHINESPARKING && pData->pose != SPOSE_DELAY_BEFORE_BALLSPARKING)
        {
            timer = pData->shinespark_timer;
            if ((timer & 0xF) == 0x4)
                play_sound(0x8D);
            pData->shinespark_timer--;
        }
        if (pEquipment->suit_type != SUIT_SUITLESS)
            SamusSetHighlightedWeapon(pData, pWeapon, pEquipment);

        SamusSetSpinningPose(pData, pEquipment);
        samus_spawn_new_projectile(pData, pWeapon, pEquipment);
        samus_pose_functions_pointers[pData->pose](pData);
        if (pose == SPOSE_NONE)
            samus_pose_gfx_functions_pointers[pData->pose](pData);
        SamusCheckShinesparking(pData);
    }

    return pose;
}

/**
 * @brief Updates the position and the vecolity of samus
 * 
 * @param pData Samus Data Pointer
 */
void SamusUpdateVelocityPosition(struct SamusData* pData)
{

}

void SamusUpdateGraphicsOAM(struct SamusData* pData, u8 direction)
{

}

void SamusUpdatePalette(struct SamusData* pData)
{

}

void SamusCheckPlayLowHealthSound(void)
{
    struct SamusData* pData;
    struct Equipment* pEquipment;

    pData = &gSamusData;
    pEquipment = &gEquipment;

    if (pEquipment->low_health && pData->pose != SPOSE_DYING && gPreventMovementTimer == 0x0 && !(gFrameCounter8Bit & 0xF))
        SoundPlay(0x82);
}

void SamusUpdateDrawDistanceAndStandingStatus(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u8 offset;
    u8 standing;
    
    offset = samus_visual_data[pData->pose][0x0];
    pPhysics->draw_distance_left_offset = samus_draw_distance_offsets[offset][0x0];
    pPhysics->draw_distance_top_offset = samus_draw_distance_offsets[offset][0x1];
    pPhysics->draw_distance_right_offset = samus_draw_distance_offsets[offset][0x2];
    pPhysics->draw_distance_bottom_offset = samus_draw_distance_offsets[offset][0x3];
    standing = samus_visual_data[pData->pose][0x2];
    if (pData->standing_status != STANDING_ENEMY)
        pData->standing_status = standing;
}

void SamusUpdateArmCannonPositionOffset(u8 direction)
{

}

void SamusInit(void)
{

}

void SamusDraw(void)
{

}
