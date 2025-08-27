#include "randomizer.h"

#include "event.h"
#include "in_game_cutscene.h"
#include "sprite.h"

#include "data/menus/pause_screen_sub_menus_data.h"
#include "data/randomizer_data.h"
#include "data/rooms_data.h"
#include "data/sprite_data.h"
#include "data/text_data.h"

#include "constants/event.h"
#include "constants/in_game_cutscene.h"
#include "constants/menus/pause_screen.h"
#include "constants/randomizer.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/text.h"

#include "structs/game_state.h"
#include "structs/samus.h"

#ifdef RANDOMIZER

// TODO: Move pointers to separate file

// Existing data
static const struct TilesetEntry* sTilesetEntries_Pointer = sTilesetEntries;
static const struct ChozoStatueTarget* sChozoStatueTargets_Pointer = sChozoStatueTargets;

// Rando data
static const struct MajorLocation* sMajorLocations_Pointer = sMajorLocations;
static const struct MinorLocation* sMinorLocations_Pointer = sMinorLocations;

// Rando options
static const u8* sRandoDifficultyOptions_Pointer = &sRandoDifficultyOptions;
static const u16* sRandoMetroidSpriteStats_Pointer = sPrimarySpriteStats[PSPRITE_METROID];
static const boolu8* sRandoBlackPiratesRequirePlasma_Pointer = &sRandoBlackPiratesRequirePlasma;
static const boolu8* sRandoSkipDoorTransitions_Pointer = &sRandoSkipDoorTransitions;
static const boolu8* sRandoBallLauncherWithoutBombs_Pointer = &sRandoBallLauncherWithoutBombs;
static const boolu8* sRandoDisableMidAirBombJump_Pointer = &sRandoDisableMidAirBombJump;
static const boolu8* sRandoDisableWallJump_Pointer = &sRandoDisableWallJump;
static const boolu8* sRandoRemoveCutscenes_Pointer = &sRandoRemoveCutscenes;
static const boolu8* sRandoSkipSuitlessSequence_Pointer = &sRandoSkipSuitlessSequence;

static const u16* sEnergyTankIncreaseAmount_Pointer = &sEnergyTankIncreaseAmount;
static const u16* sMissileTankIncreaseAmount_Pointer = &sMissileTankIncreaseAmount;
static const u8* sSuperMissileTankIncreaseAmount_Pointer = &sSuperMissileTankIncreaseAmount;
static const u8* sPowerBombTankIncreaseAmount_Pointer = &sPowerBombTankIncreaseAmount;

static const u8* sRandoTitleLine1_Pointer = sRandoTitleLine1;
static const u8* sRandoTitleLine2_Pointer = sRandoTitleLine2;

/**
 * @brief TODO
 */
const struct MinorLocation* RandoGetMinorLocation(Area area, u8 room, u8 blockX, u8 blockY)
{
    u32 key;
    u32 left;
    u32 right;
    u32 mid;

    key = MINOR_LOC_KEY(area, room, blockX, blockY);
    left = 0;
    right = MINOR_LOCATION_COUNT - 1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        
        if (sMinorLocations[mid].key < key)
            left = mid + 1;
        else if (sMinorLocations[mid].key > key)
            right = mid - 1;
        else
            return &sMinorLocations[mid];
    }

    return NULL;
}

/**
 * @brief TODO
 */
static void RandoCollectItem(RandoItemType item, u8 hintedBy)
{
    boolu8 isFirstTank;
    // message is for spawning the message banner, the actual text can be
    // overridden with custom text
    s32 message;

    isFirstTank = FALSE;
    message = MESSAGE_NONE;

    // Update equipment
    switch (item)
    {
        case RIT_ENERGY_TANK:
            message = MESSAGE_ENERGY_TANK_ACQUIRED;

            gEquipment.maxEnergy += sEnergyTankIncreaseAmount;
            if (gEquipment.maxEnergy > MAX_ENERGY_CAPACITY)
                gEquipment.maxEnergy = MAX_ENERGY_CAPACITY;

            gEquipment.currentEnergy = gEquipment.maxEnergy;
            break;

        case RIT_MISSILE_TANK:
            message = MESSAGE_MISSILE_TANK_ACQUIRED;
            if (gEquipment.maxMissiles == 0)
                isFirstTank = TRUE;

            gEquipment.maxMissiles += sMissileTankIncreaseAmount;
            if (gEquipment.maxMissiles > MAX_MISSILE_CAPACITY)
                gEquipment.maxMissiles = MAX_MISSILE_CAPACITY;

            gEquipment.currentMissiles += sMissileTankIncreaseAmount;
            if (gEquipment.currentMissiles > MAX_MISSILE_CAPACITY)
                gEquipment.currentMissiles = MAX_MISSILE_CAPACITY;
            break;

        case RIT_SUPER_MISSILE_TANK:
            message = MESSAGE_SUPER_MISSILE_TANK_ACQUIRED;
            if (gEquipment.maxSuperMissiles == 0)
                isFirstTank = TRUE;

            gEquipment.maxSuperMissiles += sSuperMissileTankIncreaseAmount;
            if (gEquipment.maxSuperMissiles > MAX_SUPER_MISSILE_CAPACITY)
                gEquipment.maxSuperMissiles = MAX_SUPER_MISSILE_CAPACITY;

            gEquipment.currentSuperMissiles += sSuperMissileTankIncreaseAmount;
            if (gEquipment.currentSuperMissiles > MAX_SUPER_MISSILE_CAPACITY)
                gEquipment.currentSuperMissiles = MAX_SUPER_MISSILE_CAPACITY;
            break;

        case RIT_POWER_BOMB_TANK:
            message = MESSAGE_POWER_BOMB_TANK_ACQUIRED;
            if (gEquipment.maxPowerBombs == 0)
                isFirstTank = TRUE;

            gEquipment.maxPowerBombs += sPowerBombTankIncreaseAmount;
            if (gEquipment.maxPowerBombs > MAX_POWER_BOMB_CAPACITY)
                gEquipment.maxPowerBombs = MAX_POWER_BOMB_CAPACITY;

            gEquipment.currentPowerBombs += sPowerBombTankIncreaseAmount;
            if (gEquipment.currentPowerBombs > MAX_POWER_BOMB_CAPACITY)
                gEquipment.currentPowerBombs = MAX_POWER_BOMB_CAPACITY;
            break;
        
        case RIT_LONG_BEAM:
            message = MESSAGE_LONG_BEAM;
            gEquipment.beamBombs |= BBF_LONG_BEAM;
            break;

        case RIT_CHARGE_BEAM:
            message = MESSAGE_CHARGE_BEAM;
            gEquipment.beamBombs |= BBF_CHARGE_BEAM;
            break;

        case RIT_ICE_BEAM:
            message = MESSAGE_ICE_BEAM;
            gEquipment.beamBombs |= BBF_ICE_BEAM;
            break;

        case RIT_WAVE_BEAM:
            message = MESSAGE_WAVE_BEAM;
            gEquipment.beamBombs |= BBF_WAVE_BEAM;
            break;

        case RIT_PLASMA_BEAM:
            message = MESSAGE_UKNOWN_ITEM_PLASMA;
            gEquipment.beamBombs |= BBF_PLASMA_BEAM;
            break;

        case RIT_BOMBS:
            message = MESSAGE_BOMB;
            gEquipment.beamBombs |= BBF_BOMBS;
            break;

        case RIT_VARIA_SUIT:
            message = MESSAGE_VARIA_SUIT;
            gEquipment.suitMisc |= SMF_VARIA_SUIT;
            break;

        case RIT_GRAVITY_SUIT:
            message = MESSAGE_UNKNOWN_ITEM_GRAVITY;
            gEquipment.suitMisc |= SMF_GRAVITY_SUIT;
            break;

        case RIT_MORPH_BALL:
            message = MESSAGE_MORPH_BALL;
            gEquipment.suitMisc |= SMF_MORPH_BALL;
            break;

        case RIT_SPEED_BOOSTER:
            message = MESSAGE_SPEED_BOOSTER;
            gEquipment.suitMisc |= SMF_SPEEDBOOSTER;
            break;

        case RIT_HI_JUMP:
            message = MESSAGE_HIGH_JUMP;
            gEquipment.suitMisc |= SMF_HIGH_JUMP;
            break;

        case RIT_SCREW_ATTACK:
            message = MESSAGE_SCREW_ATTACK;
            gEquipment.suitMisc |= SMF_SCREW_ATTACK;
            break;

        case RIT_SPACE_JUMP:
            message = MESSAGE_UNKNOWN_ITEM_SPACE_JUMP;
            gEquipment.suitMisc |= SMF_SPACE_JUMP;
            break;

        case RIT_POWER_GRIP:
            message = MESSAGE_POWER_GRIP;
            gEquipment.suitMisc |= SMF_POWER_GRIP;
            break;

        case RIT_FULLY_POWERED:
            message = MESSAGE_FULLY_POWERED_SUIT;
            gEquipment.suitType = SUIT_FULLY_POWERED;
            // Activate unknown items if obtained
            gEquipment.beamBombsActivation |= gEquipment.beamBombs & BBF_PLASMA_BEAM;
            gEquipment.suitMiscActivation |= gEquipment.suitMisc & (SMF_SPACE_JUMP | SMF_GRAVITY_SUIT);
            break;

        case RIT_ZIPLINES:
            message = MESSAGE_ZIPLINES;
            EventFunction(EVENT_ACTION_SETTING, EVENT_ZIPLINES_ACTIVATED);
            break;

        case RIT_INFANT_METROID:
            message = MESSAGE_INFANT_METROID;
            // TODO: Add RAM value to increment
            break;
    }

    // Spawn the message banner
    if (isFirstTank)
        message++;

    if (message != MESSAGE_NONE)
    {
        SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, message, SPRITE_GFX_SLOT_SPECIAL,
            gSamusData.yPosition, gSamusData.xPosition, 0);
    }

    if (hintedBy != 0xFF && hintedBy < TARGET_ITEM_END)
    {
        EventFunction(EVENT_ACTION_SETTING, sRandoHintEvents[hintedBy][0]);
        EventFunction(EVENT_ACTION_SETTING, sRandoHintEvents[hintedBy][1]);

        if (hintedBy == TARGET_LONG_BEAM)
            InGameCutsceneCheckFlag(TRUE, IGC_LONG_BEAM_HINT);
    }
}

/**
 * @brief Updates equipment, spawns a message banner, and stores the item,
 * jingle, and custom message for a major location item
 */
void RandoCollectMajorLocationItem(ItemSource source)
{
    const struct MajorLocation* loc;

    loc = &sMajorLocations[source];
    gCurrentRandoItem.isMinor = FALSE;
    gCurrentRandoItem.item = loc->item;
    gCurrentRandoItem.jingle = loc->jingle;
    gCurrentRandoItem.customMessage = loc->customMessage;

    RandoCollectItem(loc->item, loc->hintedBy);
}

/**
 * @brief Updates equipment, spawns a message banner, and stores the item,
 * jingle, and custom message for a minor location item
 */
void RandoCollectMinorLocationItem(const struct MinorLocation* loc)
{
    gCurrentRandoItem.isMinor = TRUE;
    gCurrentRandoItem.item = loc->item;
    gCurrentRandoItem.jingle = loc->jingle;
    gCurrentRandoItem.customMessage = loc->customMessage;

    RandoCollectItem(loc->item, loc->hintedBy);
}

/**
 * @brief TODO
 */
boolu8 RandoIsItemMessage(u8 message)
{
    switch (message)
    {
        case MESSAGE_ENERGY_TANK_ACQUIRED:
        case MESSAGE_MISSILE_TANK_ACQUIRED:
        case MESSAGE_FIRST_MISSILE_TANK:
        case MESSAGE_SUPER_MISSILE_TANK_ACQUIRED:
        case MESSAGE_FIRST_SUPER_MISSILE_TANK:
        case MESSAGE_POWER_BOMB_TANK_ACQUIRED:
        case MESSAGE_FIRST_POWER_BOMB_TANK:
        case MESSAGE_LONG_BEAM:
        case MESSAGE_CHARGE_BEAM:
        case MESSAGE_ICE_BEAM:
        case MESSAGE_WAVE_BEAM:
        case MESSAGE_UKNOWN_ITEM_PLASMA:
        case MESSAGE_BOMB:
        case MESSAGE_VARIA_SUIT:
        case MESSAGE_UNKNOWN_ITEM_GRAVITY:
        case MESSAGE_MORPH_BALL:
        case MESSAGE_SPEED_BOOSTER:
        case MESSAGE_HIGH_JUMP:
        case MESSAGE_SCREW_ATTACK:
        case MESSAGE_UNKNOWN_ITEM_SPACE_JUMP:
        case MESSAGE_POWER_GRIP:
        case MESSAGE_FULLY_POWERED_SUIT:
        case MESSAGE_ZIPLINES:
        case MESSAGE_INFANT_METROID:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief TODO
 */
const u16* RandoGetMessageText(u8 message)
{
    if (RandoIsItemMessage(message))
    {
        if (gCurrentRandoItem.customMessage != NULL)
            return gCurrentRandoItem.customMessage;
        
        if (gEquipment.suitType != SUIT_FULLY_POWERED)
        {
            switch (message)
            {
                case MESSAGE_UKNOWN_ITEM_PLASMA:
                case MESSAGE_UNKNOWN_ITEM_GRAVITY:
                case MESSAGE_UNKNOWN_ITEM_SPACE_JUMP:
                    message = MESSAGE_UNKNOWN_ITEM;
                    break;
            }
        }
    }

    return sMessageTextPointers[gLanguage][message];
}

#endif // RANDOMIZER
