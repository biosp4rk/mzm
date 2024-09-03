#include "audio_wrappers.h"
#include "bg_clip.h"
#include "chaos.h"
#include "gba/keys.h"
#include "gba/memory.h"
#include "macros.h"
#include "menus/status_screen.h"
#include "particle.h"
#include "projectile.h"
#include "projectile_util.h"
#include "samus.h"
#include "screen_shake.h"
#include "sprite.h"
#include "sprite_util.h"

#include "constants/audio.h"
#include "constants/chaos.h"
#include "constants/clipdata.h"
#include "constants/color_fading.h"
#include "constants/game_state.h"
#include "constants/particle.h"
#include "constants/power_bomb_explosion.h"
#include "constants/projectile.h"
#include "constants/room.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/bg_clip.h"
#include "structs/chaos.h"
#include "structs/game_state.h"
#include "structs/in_game_timer.h"
#include "structs/power_bomb_explosion.h"
#include "structs/room.h"
#include "structs/samus.h"
#include "structs/sprite.h"

// Max positions where HUD elements can be drawn when moved
#define HUD_MAX_X (SCREEN_SIZE_X - 24)
#define HUD_MAX_Y (SCREEN_SIZE_Y - 8)
// Gets a random position on screen
#define RAND_SCREEN_X (ChaosRandU16(0, HUD_MAX_X))
#define RAND_SCREEN_Y (ChaosRandU16(0, HUD_MAX_Y))

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
        
        // Check specific effects to update
        switch (gChaosEffects[i].id)
        {
            case CHAOS_EFFECT_EXPLOSIONS:
                ChaosEffectExplosions();
                break;
        }

        gChaosEffects[i].timer--;
        if (gChaosEffects[i].timer == 0)
            ChaosEffectEnded(&gChaosEffects[i]);
    }
}

void ChaosEffectEnded(struct ChaosEffect* pEffect)
{
    switch (pEffect->id)
    {
        case CHAOS_EFFECT_DEACTIVATE_ABILITY:
            if ((pEffect->data >> 8) == 0)
            {
                gEquipment.beamBombsActivation |= (u8)pEffect->data;
                if (gMainGameMode == GM_INGAME)
                    ProjectileLoadGraphics();
            }
            else
            {
                gEquipment.suitMiscActivation |= (u8)pEffect->data;
            }
            // Play "enable" sound
            SoundPlay(SOUND_RUINS_TEST_SYMBOL_PLACED);
            break;
        case CHAOS_EFFECT_SUITLESS:
            UpdateSuitType(pEffect->data, TRUE);
            if (gMainGameMode == GM_INGAME)
                ProjectileLoadGraphics();
            gSamusWeaponInfo.chargeCounter = 0;
            break;
    }

    // Clear effect data
    gActiveChaosEffects &= ~(1 << pEffect->id);
    pEffect->exists = FALSE;
    pEffect->id = 0;
    pEffect->timer = 0;
    pEffect->data = 0;
}

/**
 * @brief Ends any chaos effects that modify equipment
 */
void ChaosEndEquipmentEffects(void)
{
    s32 i;

    for (i = 0; i < MAX_NUM_CHAOS_EFFECTS; i++)
    {
        if (!gChaosEffects[i].exists)
            continue;

        switch (gChaosEffects[i].id)
        {
            case CHAOS_EFFECT_DEACTIVATE_ABILITY:
            case CHAOS_EFFECT_SUITLESS:
                ChaosEffectEnded(&gChaosEffects[i]);
                break;
        }
    }
}

void ChaosCreateEffect(void)
{
    u8 effectIdx;
    u8 start;
    u8 tries;
    u8 id;

    effectIdx = ChaosEmptyEffectIndex();
    start = effectIdx != 0xFF ? 0 : CHAOS_EFFECT_ONE_TIME;

    for (tries = 0; tries < 5; tries++)
    {
        id = ChaosRandU16(start, CHAOS_EFFECT_END + 1);
        
        // Extra chance for deactivate ability and spawn sprite
        if (id >= CHAOS_EFFECT_END)
        {
            if (effectIdx != 0xFF && id == CHAOS_EFFECT_END)
                id = CHAOS_EFFECT_DEACTIVATE_ABILITY;
            else
                id = CHAOS_EFFECT_SPAWN_ENEMY;
        }

        // Try again if duration effect is already active
        if (id < CHAOS_EFFECT_ONE_TIME && ChaosIsEffectActive(1 << id))
            continue;

        switch (id)
        {
            // Duration effects
            case CHAOS_EFFECT_INVERTED_CONTROLS:
                break; // No extra checks or setup required
            case CHAOS_EFFECT_WATER_PHYSICS:
                break; // No extra checks or setup required
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
            case CHAOS_EFFECT_DEACTIVATE_ABILITY:
                if (!ChaosEffectDeactivateAbility(&gChaosEffects[effectIdx]))
                    continue;
                break;
            case CHAOS_EFFECT_SUITLESS:
                if (!ChaosEffectSuitless(&gChaosEffects[effectIdx]))
                    continue;
                break;
            case CHAOS_EFFECT_SLOW_WEAPONS:
                break; // No extra checks or setup required
            case CHAOS_EFFECT_ARM_WEAPON:
                if (gEquipment.suitType == SUIT_SUITLESS ||
                    (gEquipment.currentMissiles == 0 && gEquipment.currentSuperMissiles == 0))
                    continue;
                break;
            case CHAOS_EFFECT_SWAP_MISSILES:
                if (gEquipment.suitType == SUIT_SUITLESS ||
                    gEquipment.currentMissiles == 0 || gEquipment.currentSuperMissiles == 0)
                    continue;
                break;
            case CHAOS_EFFECT_CHARGED_SHOTS:
                if (ChaosIsEffectActive(CHAOS_FLAG_SHOOT_BOMBS))
                    continue;
                break;
            case CHAOS_EFFECT_SHOOT_BOMBS:
                if (ChaosIsEffectActive(CHAOS_FLAG_CHARGED_SHOTS))
                    continue;
                break;
            case CHAOS_EFFECT_MOVE_HUD:
                ChaosEffectMoveHud();
                break;
            case CHAOS_EFFECT_SLOW_SCROLLING:
                break; // No extra checks or setup required
            case CHAOS_EFFECT_EXPLOSIONS:
                break; // No extra checks or setup required
            // One time effects
            case CHAOS_EFFECT_SPAWN_ENEMY:
                if (!ChaosEffectSpawnEnemy())
                    continue;
                break;
            case CHAOS_EFFECT_SPAWN_PB:
                if (!ChaosEffectSpawnPB())
                    continue;
                break;
            case CHAOS_EFFECT_SHOT_BLOCK:
                ChaosEffectShotBlock();
                break;
            case CHAOS_EFFECT_FREEZE_ENEMIES:
                if (!ChaosEffectFreezeEnemies())
                    continue;
                break;
            case CHAOS_EFFECT_SCREEN_SHAKE:
                ChaosEffectScreenShake();
                break;
            case CHAOS_EFFECT_KNOCKBACK_SAMUS:
                if (!ChaosEffectKnockback())
                    continue;
                break;
            case CHAOS_EFFECT_SHINE_TIMER:
                gSamusData.shinesparkTimer = 180;
                break;
            case CHAOS_EFFECT_CHANGE_ENERGY_AMMO:
                ChaosEffectChangeEnergyAmmo();
                break;
            case CHAOS_EFFECT_PAUSE_GAME:
                if (!ProcessPauseButtonPress())
                    continue;
                gGameModeSub1++;
                break;
            case CHAOS_EFFECT_RAND_SOUND:
                ChaosEffectRandSound();
                break;
            case CHAOS_EFFECT_COLOR_EFFECT:
                ChaosEffectColorEffect();
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
        else
        {
            // Track this for the lua script
            gPrevOneTimeChaosEffect = id;
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

s32 ChaosEffectDeactivateAbility(struct ChaosEffect* pEffect)
{
    u8 beamBombsCount;
    u8 beamBombsAct;
    u8 suitMiscCount;
    u8 suitMiscAct;
    u8 itemIdx;

    if (gEquipment.suitType == SUIT_SUITLESS)
        return FALSE;

    // Count active abilities
    beamBombsCount = 0;
    beamBombsAct = gEquipment.beamBombsActivation;
    while (beamBombsAct != 0)
    {
        beamBombsCount += beamBombsAct & 1;
        beamBombsAct >>= 1;
    }

    suitMiscCount = 0;
    suitMiscAct = gEquipment.suitMiscActivation;
    while (suitMiscAct != 0)
    {
        suitMiscCount += suitMiscAct & 1;
        suitMiscAct >>= 1;
    }

    if (beamBombsCount + suitMiscCount == 0)
        return FALSE;

    // Get ability to deactivate
    itemIdx = ChaosRandU16(0, beamBombsCount + suitMiscCount - 1);
    if (itemIdx < beamBombsCount)
    {
        beamBombsCount = 0;
        beamBombsAct = 1;
        while (TRUE)
        {
            if (gEquipment.beamBombsActivation & beamBombsAct)
            {
                beamBombsCount++;
                if (beamBombsCount == itemIdx + 1)
                    break;
            }
            beamBombsAct <<= 1;
        }
        pEffect->data = beamBombsAct;
        gEquipment.beamBombsActivation &= ~beamBombsAct;
        ProjectileLoadGraphics();
    }
    else
    {
        itemIdx -= beamBombsCount;
        suitMiscCount = 0;
        suitMiscAct = 1;
        while (TRUE)
        {
            if (gEquipment.suitMiscActivation & suitMiscAct)
            {
                suitMiscCount++;
                if (suitMiscCount == itemIdx + 1)
                    break;
            }
            suitMiscAct <<= 1;
        }
        pEffect->data = suitMiscAct | 0x100;
        gEquipment.suitMiscActivation &= ~suitMiscAct;
    }

    // Play "disable" sound
    SoundPlay(SOUND_UNKNOWN_ITEM_ACQUISITION);
    return TRUE;
}

s32 ChaosEffectSuitless(struct ChaosEffect* pEffect)
{
    if (gEquipment.suitType == SUIT_SUITLESS)
        return FALSE;

    pEffect->data = gEquipment.suitType;
    UpdateSuitType(SUIT_SUITLESS, TRUE);
    ProjectileLoadGraphics();
    gSamusWeaponInfo.chargeCounter = 0;
    return TRUE;
}

void ChaosEffectMoveHud(void)
{
    gHudPositions.energyX = RAND_SCREEN_X;
    gHudPositions.energyY = RAND_SCREEN_Y;
    gHudPositions.chargeBarX = RAND_SCREEN_X;
    gHudPositions.chargeBarY = RAND_SCREEN_Y;
    gHudPositions.missileX = RAND_SCREEN_X;
    gHudPositions.missileY = RAND_SCREEN_Y;
    gHudPositions.superMissileX = RAND_SCREEN_X;
    gHudPositions.superMissileY = RAND_SCREEN_Y;
    gHudPositions.powerBombX = RAND_SCREEN_X;
    gHudPositions.powerBombY = RAND_SCREEN_Y;
    gHudPositions.minimapX = RAND_SCREEN_X;
    gHudPositions.minimapY = RAND_SCREEN_Y;
}

void ChaosEffectExplosions(void)
{
    u8 pe;
    u16 sound;

    if (ChaosRandU16(0, 11) != 0)
        return;

    switch (ChaosRandU16(0, 8))
    {
        case 0:
            pe = PE_SPRITE_EXPLOSION_HUGE;
            break;
        case 1:
            pe = PE_SPRITE_EXPLOSION_MEDIUM;
            break;
        case 2:
            pe = PE_SPRITE_EXPLOSION_BIG;
            break;
        case 3:
            pe = PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG;
            break;
        case 4:
            pe = PE_SCREW_ATTACK_DESTROYED;
            break;
        case 5:
            pe = PE_SHINESPARK_DESTROYED;
            break;
        case 6:
            pe = PE_SUDO_SCREW_DESTROYED;
            break;
        case 7:
            pe = PE_SPEEDBOOSTER_DESTROYED;
            break;
        case 8:
            pe = PE_MAIN_BOSS_DEATH;
            break;
    }

    switch (ChaosRandU16(0, 4))
    {
        // 301-303
        // 312
        // 403
        // 457: Kraid
        // 496: Ridley death
        case 0:
            sound = 253;
            break;
        case 1:
            sound = 630;
            break;
        case 2:
            sound = 705;
            break;
        case 3:
            sound = 706;
            break;
        case 4:
            sound = 707;
            break;
    }

    ParticleSet(ChaosPositionNearSamusY(), ChaosPositionNearSamusX(), pe);
    SoundPlayNotAlreadyPlaying(sound);
}

// One time effects

s32 ChaosEffectSpawnEnemy(void)
{
    u8 spriteCount;
    struct SpriteData* pSprite;
    u8 idCount;
    u8 spritesetStartIdx;
    u8 i;
    u8 spritesetIdx;
    u8 spriteId;
    u16 spriteX;
    u16 spriteY;
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
    
    // Pick a random starting index
    spritesetStartIdx = ChaosRandU16(0, idCount - 1);

    // Try each sprite ID until one can spawn
    for (i = 0; i < idCount; i++)
    {
        spritesetIdx = (spritesetStartIdx + i) % idCount;
        spriteId = gSpritesetSpritesID[spritesetIdx];

        // Check if this sprite ID is excluded
        switch (spriteId)
        {
            case PSPRITE_ITEM_BANNER:
            case PSPRITE_LARGE_ENERGY_DROP:
            case PSPRITE_SMALL_ENERGY_DROP:
            case PSPRITE_MISSILE_DROP:
            case PSPRITE_SUPER_MISSILE_DROP:
            case PSPRITE_POWER_BOMB_DROP:
            case PSPRITE_CHOZO_STATUE_LONG_HINT:
            case PSPRITE_CHOZO_STATUE_LONG:
            case PSPRITE_CHOZO_STATUE_ICE_HINT:
            case PSPRITE_CHOZO_STATUE_ICE:
            case PSPRITE_CHOZO_STATUE_WAVE_HINT:
            case PSPRITE_CHOZO_STATUE_WAVE:
            case PSPRITE_CHOZO_STATUE_BOMB_HINT:
            case PSPRITE_CHOZO_STATUE_BOMB:
            case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT:
            case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
            case PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT:
            case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
            case PSPRITE_CHOZO_STATUE_SCREW_HINT:
            case PSPRITE_CHOZO_STATUE_SCREW:
            case PSPRITE_CHOZO_STATUE_VARIA_HINT:
            case PSPRITE_CHOZO_STATUE_VARIA:
            case PSPRITE_MULTIPLE_LARGE_ENERGY:
            case PSPRITE_GUNSHIP:
            case PSPRITE_DEOREM:
            case PSPRITE_DEOREM_SECOND_LOCATION:
            case PSPRITE_IMAGO_LARVA_RIGHT:
            case PSPRITE_IMAGO_COCOON:
            case PSPRITE_CHOZO_STATUE_GRAVITY:
            case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            case PSPRITE_RIDLEY:
            case PSPRITE_FROZEN_METROID:
            case PSPRITE_GEKITAI_MACHINE:
            case PSPRITE_RUINS_TEST:
            case PSPRITE_KRAID:
            case PSPRITE_AREA_BANNER:
            case PSPRITE_MOTHER_BRAIN:
            case PSPRITE_FAKE_POWER_BOMB_EVENT_TRIGGER:
            case PSPRITE_ACID_WORM:
            case PSPRITE_ESCAPE_SHIP:
            case PSPRITE_IMAGO_LARVA_RIGHT_SIDE:
            case PSPRITE_IMAGO:
            case PSPRITE_CROCOMIRE:
            case PSPRITE_IMAGO_LARVA_LEFT:
            case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            case PSPRITE_LOCK_UNLOCK_METROID_DOORS_UNUSED:
            case PSPRITE_MAYBE_SEARCHLIGHT_TRIGGER:
            case PSPRITE_DISCOVERED_IMAGO_PASSAGE_EVENT_TRIGGER:
            case PSPRITE_FALLING_CHOZO_PILLAR:
            case PSPRITE_MECHA_RIDLEY:
            case PSPRITE_EXPLOSION_ZEBES_ESCAPE:
                continue;
        }

        // Get X and Y positions on a block boundary
        spriteX = ChaosPositionNearSamusX() / BLOCK_SIZE * BLOCK_SIZE;
        spriteY = ChaosPositionNearSamusY() / BLOCK_SIZE * BLOCK_SIZE;

        // Try spawning sprite (on bottom middle of block)
        spriteSlot = SpriteSpawnPrimary(spriteId, 0, gSpritesetGfxSlots[spritesetIdx],
            spriteY + BLOCK_SIZE, spriteX + HALF_BLOCK_SIZE, 0);

        // Spawning should always succeed, but check just in case
        if (spriteSlot == 0xFF)
            return FALSE;
        
        gSpriteData[spriteSlot].status &= ~SPRITE_STATUS_NOT_DRAWN;
        return TRUE;
    }

    // None of the sprite IDs worked
    return FALSE;
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

void ChaosEffectShotBlock(void)
{
    u16 xPos;
    u16 yPos;

    xPos = (ChaosPositionNearSamusX() + HALF_BLOCK_SIZE) / BLOCK_SIZE;
    yPos = (ChaosPositionNearSamusY() + HALF_BLOCK_SIZE) / BLOCK_SIZE;

    BgClipSetClipdataBlockValue(CLIPDATA_SHOT_BLOCK_REFORM, yPos, xPos);
    BgClipSetBg1BlockValue(0x46, yPos, xPos);
}

s32 ChaosEffectFreezeEnemies(void)
{
    s32 success;
    u8 i;

    success = FALSE;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (gSpriteData[i].status & SPRITE_STATUS_EXISTS &&
            !(gSpriteData[i].properties & SP_SECONDARY_SPRITE) &&
            ProjectileGetSpriteWeakness(&gSpriteData[i]) & WEAKNESS_CAN_BE_FROZEN)
        {
            ProjectileFreezeSprite(&gSpriteData[i], 0xF0);
            success = TRUE;
        }
    }

    return success;
}

void ChaosEffectScreenShake(void)
{
    if (CHAOS_RAND_BOOL)
        ScreenShakeStartHorizontal(240, 1);
    else
        ScreenShakeStartVertical(240, 1);
}

s32 ChaosEffectKnockback(void)
{
    if (gSamusData.pose == SPOSE_USING_AN_ELEVATOR)
        return FALSE;

    SamusSetPose(SPOSE_KNOCKBACK_REQUEST);

    if (gSamusData.direction & KEY_RIGHT)
        gSamusData.xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
    else
        gSamusData.xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
    
    return TRUE;
}

void ChaosEffectChangeEnergyAmmo(void)
{
    u8 max;
    s32 missileIdx;
    s32 superIdx;
    u16 rand;

    max = 0;
    missileIdx = -1;
    superIdx = -1;

    if (gEquipment.maxMissiles > 0)
        missileIdx = ++max;
    if (gEquipment.maxSuperMissiles > 0)
        superIdx = ++max;
    if (gEquipment.maxPowerBombs > 0)
        ++max;

    rand = ChaosRandU16(0, max);

    if (rand == 0)
        gEquipment.currentEnergy = ChaosRandU16(1, gEquipment.maxEnergy);
    else if (rand == missileIdx)
        gEquipment.currentMissiles = ChaosRandU16(1, gEquipment.maxMissiles);
    else if (rand == superIdx)
        gEquipment.currentSuperMissiles = ChaosRandU16(1, gEquipment.maxSuperMissiles);
    else
        gEquipment.currentPowerBombs = ChaosRandU16(1, gEquipment.maxPowerBombs);
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

void ChaosEffectColorEffect(void)
{
    u8 effect;
    u16* pPalette;
    s32 i;
    u8 r;
    u8 g;
    u8 b;
    u8 result;

    effect = ChaosRandU16(0, 2);
    pPalette = (u16*)PALRAM_BASE;

    for (i = 0; i < 256; i++, pPalette++)
    {
        if (i % 16 == 0)
            continue;

        r = RED(*pPalette);
        g = GREEN(*pPalette);
        b = BLUE(*pPalette);

        switch (effect)
        {
            case 0:
                // Lower brightness
                r /= 2;
                g /= 2;
                b /= 2;
                break;
            case 1:
                // Raise brightness
                r = r * 3 / 2;
                g = g * 3 / 2;
                b = b * 3 / 2;
                if (r > COLOR_MASK)
                    r = COLOR_MASK;
                if (g > COLOR_MASK)
                    g = COLOR_MASK;
                if (b > COLOR_MASK)
                    b = COLOR_MASK;
                break;
            case 2:
                // Monochrome
                result = (r + g + b) / 3;
                r = result;
                g = result;
                b = result;
                break;
        }

        *pPalette = COLOR(r, g, b);
    }
}
