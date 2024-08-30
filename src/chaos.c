#include "audio_wrappers.h"
#include "chaos.h"
#include "menus/status_screen.h"
#include "projectile.h"
#include "projectile_util.h"
#include "samus.h"
#include "screen_shake.h"
#include "sprite.h"
#include "sprite_util.h"

#include "constants/chaos.h"
#include "constants/power_bomb_explosion.h"
#include "constants/projectile.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/chaos.h"
#include "structs/game_state.h"
#include "structs/in_game_timer.h"
#include "structs/power_bomb_explosion.h"
#include "structs/samus.h"
#include "structs/sprite.h"

u32 ChaosIsEffectActive(u32 flags)
{
    return gActiveChaosEffects & flags;
}

u8 ChaosEmptyEffectIndex(void)
{
    u8 i;

    for (i = 0; i < MAX_NUM_CHAOS_EFFECTS; i++)
    {
        if (!gChaosEffects[i].exists)
            return i;
    }

    return 0xFF;
}

void ChaosUpdate(void)
{
    // Update active effects
    ChaosUpdateEffects();

    // Check create new effect
    if (gInGameTimer.frames == 0 &&
        gInGameTimer.seconds % CHAOS_SECONDS_BETWEEN_EFFECTS == 0)
        ChaosCreateEffect();
}

void ChaosUpdateEffects(void)
{
    s32 i;

    for (i = 0; i < MAX_NUM_CHAOS_EFFECTS; i++)
    {
        if (!gChaosEffects[i].exists)
            continue;
        
        gChaosEffects[i].timer--;
        if (gChaosEffects[i].timer == 0)
            ChaosEffectEnded(&gChaosEffects[i]);
    }
}

void ChaosEffectEnded(struct ChaosEffect* pEffect)
{
    switch (pEffect->id)
    {
        case CHAOS_EFFECT_SUITLESS:
            UpdateSuitType(pEffect->data);
            ProjectileLoadGraphics();
            break;
    }

    // Clear effect data
    gActiveChaosEffects &= ~(1 << pEffect->id);
    pEffect->exists = FALSE;
    pEffect->id = 0;
    pEffect->timer = 0;
    pEffect->data = 0;
}

void ChaosCreateEffect(void)
{
    u8 effectIdx;
    u8 start;
    u8 tries;
    u8 id;

    effectIdx = ChaosEmptyEffectIndex();
    start = effectIdx != 0xFF ? 0 : CHAOS_EFFECT_ONE_TIME;
    //start = CHAOS_EFFECT_ONE_TIME;

    for (tries = 0; tries < 5; tries++)
    {
        id = ChaosRandU16(start, CHAOS_EFFECT_END - 1);
        
        // Try again if duration effect is already active
        if (id < CHAOS_EFFECT_ONE_TIME && ChaosIsEffectActive(1 << id))
            continue;

        switch (id)
        {
            // Duration effects
            case CHAOS_EFFECT_INVERTED_CONTROLS:
                break; // No checks or setup required
            case CHAOS_EFFECT_WATER_PHYSICS:
                break; // No checks or setup required
            case CHAOS_EFFECT_SLOW_HORI_MOVEMENT:
                if (ChaosIsEffectActive(CHAOS_FLAG_FAST_HORI_MOVEMENT))
                    continue;
                break;
            case CHAOS_EFFECT_FAST_HORI_MOVEMENT:
                if (ChaosIsEffectActive(CHAOS_FLAG_SLOW_HORI_MOVEMENT))
                    continue;
                break;
            case CHAOS_EFFECT_LOW_GRAVITY:
                if (ChaosIsEffectActive(CHAOS_FLAG_HIGH_GRAVITY))
                    continue;
                break;
            case CHAOS_EFFECT_HIGH_GRAVITY:
                if (ChaosIsEffectActive(CHAOS_FLAG_LOW_GRAVITY))
                    continue;
                break;
            case CHAOS_EFFECT_DEACTIVATE_ABILITY: continue;
            case CHAOS_EFFECT_SUITLESS:
                if (gEquipment.suitType == SUIT_SUITLESS)
                    continue;
                gChaosEffects[effectIdx].data = gEquipment.suitType;
                UpdateSuitType(SUIT_SUITLESS);
                ProjectileLoadGraphics();
                break;
            case CHAOS_EFFECT_SLOW_WEAPONS: continue;
            case CHAOS_EFFECT_ARM_MISSILES: continue;
            case CHAOS_EFFECT_SWAP_MISSILES: continue;
            case CHAOS_EFFECT_CHARGED_SHOTS:
                if (ChaosIsEffectActive(CHAOS_FLAG_SHOOT_BOMBS))
                    continue;
                break;
            case CHAOS_EFFECT_SHOOT_BOMBS:
                if (ChaosIsEffectActive(CHAOS_FLAG_CHARGED_SHOTS))
                    continue;
                break;
            case CHAOS_EFFECT_CHANGE_BRIGHTNESS: continue;
            case CHAOS_EFFECT_FORWARD_CAMERA: continue;
            case CHAOS_EFFECT_SHUFFLE_SOUNDS: continue;
            // One time effects
            case CHAOS_EFFECT_SPAWN_ENEMY:
                if (!ChaosEffectSpawnEnemy())
                    continue;
                break;
            case CHAOS_EFFECT_SPAWN_PB:
                if (!ChaosEffectSpawnPB())
                    continue;
                break;
            case CHAOS_EFFECT_FREEZE_ENEMIES:
                ChaosEffectFreezeEnemies();
                break;
            case CHAOS_EFFECT_SCREEN_SHAKE:
                ChaosEffectScreenShake();
                break;
            case CHAOS_EFFECT_KNOCKBACK_SAMUS:
                SamusSetPose(SPOSE_KNOCKBACK_REQUEST);
                break;
            case CHAOS_EFFECT_SHINE_TIMER:
                gSamusData.shinesparkTimer = 180;
                break;
            case CHAOS_EFFECT_CHANGE_ENERGY_AMMO:
                ChaosEffectChangeEnergyAmmo();
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
            // Setup new duration effect
            gActiveChaosEffects |= 1 << id;
            gChaosEffects[effectIdx].exists = TRUE;
            gChaosEffects[effectIdx].id = id;
            gChaosEffects[effectIdx].timer = ChaosRandU16(CHAOS_EFFECT_FRAMES_MIN, CHAOS_EFFECT_FRAMES_MAX);
        }

        break;
    }
}

void ChaosUpdateRng(void)
{
    gChaosRng = (gChaosRng * 0x41C64E6D) + 0x3039;
}

u16 ChaosRandU16(u16 min, u16 max)
{
    u16 seed;
    u16 mod;

    ChaosUpdateRng();
    seed = gChaosRng >> 16;
    mod = max - min + 1;
    return (seed % mod) + min;
}

u16 ChaosPositionNearSamus(u16 samusPos, u16 max)
{
    u16 pos;

    pos = ChaosRandU16(CHAOS_NEAR_SAMUS_MIN, max);

    // TODO: Check if out of bounds?
    if (CHAOS_RAND_BOOL)
        return (u16)(samusPos + pos);
    else
        return (u16)(samusPos - pos);
}

u16 ChaosPositionNearSamusX(void)
{
    return ChaosPositionNearSamus(gSamusData.xPosition, CHAOS_NEAR_SAMUS_MAX_X);
}

u16 ChaosPositionNearSamusY(void)
{
    return ChaosPositionNearSamus(gSamusData.yPosition, CHAOS_NEAR_SAMUS_MAX_Y);
}

// Duration effects

// One time effects

s32 ChaosEffectSpawnEnemy(void)
{
    u8 spriteCount;
    struct SpriteData* pSprite;
    u8 idCount;
    u8 spritesetIdx;
    u8 spriteId;
    u8 spriteSlot;

    // Count number of active sprites
    spriteCount = 0;
    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS)
            spriteCount++;
    }

    // Only spawn a sprite if there are at least 4 slots open
    if (spriteCount > MAX_AMOUNT_OF_SPRITES - 4)
        return FALSE;

    // Count number of sprite IDs in spriteset
    idCount = 0;
    while (idCount < MAX_AMOUNT_OF_SPRITE_TYPES)
    {
        if (gSpritesetSpritesID[idCount] <= 0x10)
            break;
        idCount++;
    }

    if (idCount == 0)
        return FALSE;
    
    // Pick a random sprite ID to spawn
    spritesetIdx = ChaosRandU16(0, idCount - 1);
    spriteId = gSpritesetSpritesID[spritesetIdx];
    // TODO: Get list of sprite IDs to exclude
    spriteSlot = SpriteSpawnPrimary(spriteId, 0, gSpritesetGfxSlots[spritesetIdx],
        ChaosPositionNearSamusY(), ChaosPositionNearSamusX(), 0);

    if (spriteSlot == 0xFF)
        return FALSE;
    
    gSpriteData[spriteSlot].status &= ~SPRITE_STATUS_NOT_DRAWN;
    return TRUE;
}

s32 ChaosEffectSpawnPB(void)
{
    if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_POWER_BOMB, 1) &&
        gCurrentPowerBomb.animationState == PB_STATE_NONE &&
        ProjectileInit(PROJ_TYPE_POWER_BOMB, ChaosPositionNearSamusY(), ChaosPositionNearSamusX()))
    {
        // Don't decrement power bombs if Samus has any
        if (gEquipment.currentPowerBombs > 0)
            gEquipment.currentPowerBombs++;
        return TRUE;
    }

    return FALSE;
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

void ChaosEffectScreenShake(void)
{
    if (CHAOS_RAND_BOOL)
        ScreenShakeStartHorizontal(240, 1);
    else
        ScreenShakeStartVertical(240, 1);
}

void ChaosEffectChangeEnergyAmmo(void)
{
    u8 max;

    max = 0;
    if (gEquipment.maxMissiles > 0)
        max++;
    if (gEquipment.maxSuperMissiles > 0)
        max++;
    if (gEquipment.maxPowerBombs > 0)
        max++;

    switch (ChaosRandU16(0, max))
    {
        case 0:
            gEquipment.currentEnergy = ChaosRandU16(1, gEquipment.maxEnergy);
            break;
        case 1:
            gEquipment.currentMissiles = ChaosRandU16(1, gEquipment.maxMissiles);
            break;
        case 2:
            gEquipment.currentSuperMissiles = ChaosRandU16(1, gEquipment.maxSuperMissiles);
            break;
        case 3:
            gEquipment.currentPowerBombs = ChaosRandU16(1, gEquipment.maxPowerBombs);
            break;
    }
}

void ChaosEffectRandSound(void)
{
    switch (ChaosRandU16(0, 2))
    {
        case 0:
            SoundPlay(0xA6); // Thunder
            break;
        case 1:
            SoundPlay(0x1BF); // Kraid
            break;
        case 2:
            SoundPlay(0x24C); // Ridley
            break;
    }
}
