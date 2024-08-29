#include "audio_wrappers.h"
#include "chaos.h"
#include "projectile.h"
#include "projectile_util.h"
#include "samus.h"
#include "sprite_util.h"

#include "constants/chaos.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/chaos.h"
#include "structs/game_state.h"
#include "structs/in_game_timer.h"
#include "structs/samus.h"
#include "structs/sprite.h"

s32 ChaosIsEffectActive(u8 id)
{
    return (gActiveChaosEffects & (1 << id)) != 0 ? 1 : 0;
}

u8 ChaosEmptyEffectIndex(void)
{
    u8 i;

    for (i = 0; i < MAX_NUM_CHAOS_EFFECTS; i++)
    {
        if (gChaosEffects[i].status == CHAOS_STATE_NONE)
            return i;
    }

    return 0xFF;
}

void ChaosUpdate(void)
{
    ChaosUpdateEffects();

    if (gInGameTimer.frames == 0 &&
        gInGameTimer.seconds % CHAOS_SECONDS_BETWEEN_EFFECTS == 0)
        ChaosCreateEffect();
}

void ChaosUpdateEffects(void)
{
    s32 i;

    for (i = 0; i < MAX_NUM_CHAOS_EFFECTS; i++)
    {
        if (gChaosEffects[i].status == CHAOS_STATE_NONE)
            continue;
        
        if (gChaosEffects[i].status & CHAOS_STATE_ENDING)
        {
            gActiveChaosEffects &= ~(1 << gChaosEffects[i].id);
            gChaosEffects[i].status = CHAOS_STATE_NONE;
            gChaosEffects[i].id = 0;
            gChaosEffects[i].timer = 0;
            gChaosEffects[i].data = 0;
        }
        else
        {
            gChaosEffects[i].timer--;
            if (gChaosEffects[i].timer == 0)
                gChaosEffects[i].status |= CHAOS_STATE_ENDING;
            else
                gChaosEffects[i].status |= ~CHAOS_STATE_STARTING;
        }
    }
}

void ChaosCreateEffect(void)
{
    u8 effectIdx;
    u8 start;
    u8 id;

    effectIdx = ChaosEmptyEffectIndex();
    //start = effectIdx != 0xFF ? 0 : CHAOS_EFFECT_ONE_TIME;
    start = CHAOS_EFFECT_ONE_TIME;

    while (TRUE)
    {
        id = (u8)ChaosRandUint(start, CHAOS_EFFECT_END - 1);
        
        switch (id)
        {
            // Duration effects
            case CHAOS_EFFECT_INVERTED_CONTROLS: break;
            case CHAOS_EFFECT_WATER_PHYSICS: break;
            case CHAOS_EFFECT_SLOW_HORI_MOVEMENT: break;
            case CHAOS_EFFECT_FAST_HORI_MOVEMENT: break;
            case CHAOS_EFFECT_LOW_GRAVITY: break;
            case CHAOS_EFFECT_HIGH_GRAVITY: break;
            case CHAOS_EFFECT_DEACTIVATE_ABILITY: break;
            case CHAOS_EFFECT_SUITLESS: break;
            case CHAOS_EFFECT_SLOW_WEAPONS: break;
            case CHAOS_EFFECT_ARM_MISSILES: break;
            case CHAOS_EFFECT_SWAP_MISSILES: break;
            case CHAOS_EFFECT_CHARGED_SHOTS: break;
            case CHAOS_EFFECT_SHOOT_BOMBS: break;
            case CHAOS_EFFECT_CHANGE_BRIGHTNESS: break;
            case CHAOS_EFFECT_SCREEN_SHAKE: break;
            case CHAOS_EFFECT_FORWARD_CAMERA: break;
            case CHAOS_EFFECT_SHUFFLE_SOUNDS: break;
            // One time effects
            case CHAOS_EFFECT_SPAWN_ENEMY: break;
            case CHAOS_EFFECT_SPAWN_PB: break;
            case CHAOS_EFFECT_FREEZE_ENEMIES:
                ChaosEffectFreezeEnemies();
                break;
            case CHAOS_EFFECT_KNOCKBACK_SAMUS:
                SamusSetPose(SPOSE_KNOCKBACK_REQUEST);
                break;
            case CHAOS_EFFECT_SHINE_TIMER:
                gSamusData.shinesparkTimer = 180;
                break;
            case CHAOS_EFFECT_CHANGE_ENERGY_AMMO:
                gEquipment.currentMissiles = 420;
                gEquipment.currentSuperMissiles = 69;
                break;
            case CHAOS_EFFECT_PAUSE_GAME:
                if (ProcessPauseButtonPress())
                    gGameModeSub1++;
                break;
            case CHAOS_EFFECT_RAND_SOUND:
                ChaosEffectRandSound();
                break;
        }

        if (id < CHAOS_EFFECT_ONE_TIME)
        {
            gActiveChaosEffects |= 1 << id;
            gChaosEffects[effectIdx].status = CHAOS_STATE_ACTIVE | CHAOS_STATE_STARTING;
            gChaosEffects[effectIdx].id = id;
            gChaosEffects[effectIdx].timer = ChaosRandUint(5 * 60, 20 * 60);
        }

        break;
    }
}

void ChaosUpdateRng(void)
{
    gChaosRng = (gChaosRng * 0x41C64E6D) + 0x3039;
}

u32 ChaosRandUint(u32 min, u32 max)
{
    u32 mod;

    ChaosUpdateRng();
    mod = max - min + 1;
    return (gChaosRng % mod) + min;
}

void ChaosEffectFreezeEnemies(void)
{
    u8 i;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (gSpriteData[i].status & SPRITE_STATUS_EXISTS &&
            !(gSpriteData[i].properties & SP_SECONDARY_SPRITE) &&
            ProjectileGetSpriteWeakness(&gSpriteData[i]) & WEAKNESS_CAN_BE_FROZEN)
            ProjectileFreezeSprite(&gSpriteData[i], 0xF0);
    }
}

void ChaosEffectRandSound(void)
{
    u8 rn;

    rn = ChaosRandUint(0, 29);

    if (rn < 10)
        SoundPlay(0xA6); // Thunder
    else if (rn < 20)
        SoundPlay(0x1BF); // Kraid
    else
        SoundPlay(0x24C); // Ridley
}
