#include "menus/boot_debug.h"

#include "data/menus/boot_debug_data.h"
#include "data/shortcut_pointers.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/pause_screen_map_data.h"
#include "data/menus/internal_pause_screen_data.h"
#include "data/engine_pointers.h"
#include "data/io_transfer_data.h"
#include "data/clipdata_data.h"

#include "constants/menus/boot_debug.h"
#include "constants/event.h"

#include "structs/menus/boot_debug.h"
#include "structs/room.h"
#include "structs/display.h"
#include "structs/cable_link.h"
#include "structs/audio.h"

void BootDebugUpdateMenuOam(void)
{
    BootDebugUpdateCursorOam();
    BootDebugUpdateNonCursorOam();
    if (BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MAP_CURSOR].exists)
        BootDebugUpdateMapScreenPosition();
    gNextOamSlot = 0;
    ProcessMenuOam(4, BOOT_DEBUG_DATA.menuOam, sBootDebugOam);
    ResetFreeOam();
}

void BootDebugSetupMenuOam(void)
{
    s32 i;
    
    for (i = 0; i < 4; i++)
        BOOT_DEBUG_DATA.menuOam[i] = sMenuOamData_Empty;

    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MENU_CURSOR].exists = TRUE;

    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_SAVE_BRACKETS].oamID = 3;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_SAVE_BRACKETS].exists = TRUE;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_SAVE_BRACKETS].boundBackground = 2;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_SAVE_BRACKETS].priority = 2;

    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_R_BUTTON_TITLE].oamID = 4;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_R_BUTTON_TITLE].exists = TRUE;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_R_BUTTON_TITLE].yPosition = 0x14;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_R_BUTTON_TITLE].xPosition = 0x18;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_R_BUTTON_TITLE].priority = 2;

    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MAP_CURSOR].oamID = 5;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MAP_CURSOR].exists = FALSE;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MAP_CURSOR].priority = 1;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MAP_CURSOR].boundBackground = 0;   
}

void BootDebugUpdateCursorOam(void)
{
    u8 oamId;
    s32 xPos;
    s32 yPos;
    
    if (BOOT_DEBUG_DATA.menuDepth == BOOT_DEBUG_MENU_MAIN)
    {
        oamId = 1;
        xPos = sBootDebugMenuNamesText[BOOT_DEBUG_DATA.menuCursor].xPosition * 32;
        yPos = sBootDebugMenuNamesText[BOOT_DEBUG_DATA.menuCursor].yPosition * 32;
        yPos -= gBg3VOFS_NonGameplay;
    }
    else
    {
        switch (BOOT_DEBUG_DATA.menuCursor)
        {
            case 1:
                xPos = sBootDebugSectionMenuText[gSectionInfo.sectionIndex].xPosition;
                yPos = sBootDebugSectionMenuText[gSectionInfo.sectionIndex].yPosition;
                break;
            case 2:
            case 3:
                xPos = sBootDebugSaveMenuText[BOOT_DEBUG_DATA.subMenuOption].xPosition;
                yPos = sBootDebugSaveMenuText[BOOT_DEBUG_DATA.subMenuOption].yPosition;
                break;
            case 4:
                xPos = sBootDebugSamusMenuText[BOOT_DEBUG_DATA.subMenuOption].xPosition;
                yPos = sBootDebugSamusMenuText[BOOT_DEBUG_DATA.subMenuOption].yPosition;
                break;
            case 5:
                xPos = sBootDebugSoundMenuText[BOOT_DEBUG_DATA.subMenuOption].xPosition;
                yPos = sBootDebugSoundMenuText[BOOT_DEBUG_DATA.subMenuOption].yPosition;
                break;
            case 6:
                xPos = sBootDebugDemoMenuText[BOOT_DEBUG_DATA.subMenuOption].xPosition;
                yPos = sBootDebugDemoMenuText[BOOT_DEBUG_DATA.subMenuOption].yPosition;
                break;
            case 7:
                xPos = sBootDebugEtcMenuText[BOOT_DEBUG_DATA.subMenuOption].xPosition;
                yPos = sBootDebugEtcMenuText[BOOT_DEBUG_DATA.subMenuOption].yPosition;
                break;
            case 9:
                xPos = sBootDebugEraseMenuText[BOOT_DEBUG_DATA.subMenuOption + 1].xPosition;
                yPos = sBootDebugEraseMenuText[BOOT_DEBUG_DATA.subMenuOption + 1].yPosition;
                break;
            case 8:
                xPos = 1;
                yPos = 2;
                break;
            default:
                xPos = 10;
                yPos = 10;
                break;
        }

        if (BOOT_DEBUG_DATA.menuDepth == BOOT_DEBUG_MENU_SUB)
        {
            oamId = 1;
        }
        else
        {
            switch (BOOT_DEBUG_DATA.menuCursor)
            {
                case 2:
                    xPos += 9;
                    break;
                case 3:
                    if (BOOT_DEBUG_DATA.subMenuOption == 2)
                    {
                        if (BOOT_DEBUG_DATA.optionCursor == 0)
                            xPos += 9;
                        else
                            xPos += 13;
                    }
                    else if (BOOT_DEBUG_DATA.subMenuOption == 1)
                    {
                        xPos += 12 + (BOOT_DEBUG_DATA.optionCursor * 2);
                    }
                    else if (BOOT_DEBUG_DATA.subMenuOption == 0)
                    {
                        xPos += 9 + BOOT_DEBUG_DATA.optionCursor;
                    }
                    break;
                case 4:
                    if (BOOT_DEBUG_DATA.subMenuOption == 0)
                        xPos += 8 + BOOT_DEBUG_DATA.optionCursor;
                    else
                        xPos += 9 + BOOT_DEBUG_DATA.optionCursor;
                    break;
                case 5:
                    if (BOOT_DEBUG_DATA.subMenuOption == 0)
                    {
                        xPos = sBootDebugBgmOnOffText[0].xPosition;
                        yPos = sBootDebugBgmOnOffText[0].yPosition;
                    }
                    else if (BOOT_DEBUG_DATA.subMenuOption == 2)
                    {
                        xPos += 6 + BOOT_DEBUG_DATA.optionCursor;
                    }
                    break;
                case 6:
                    xPos = sBootDebugDemoMenuText[BOOT_DEBUG_DATA.subMenuOption].xPosition;
                    yPos = sBootDebugDemoMenuText[BOOT_DEBUG_DATA.subMenuOption].yPosition;
                    if (BOOT_DEBUG_DATA.subMenuOption == 0)
                    {
                        xPos = sBootDebugDemoOnOffText[0].xPosition;
                        yPos = sBootDebugDemoOnOffText[0].yPosition;
                    }
                    else
                    {
                        if (BOOT_DEBUG_DATA.subMenuOption == 1 || BOOT_DEBUG_DATA.subMenuOption == 2)
                            xPos += 8;
                        else if (BOOT_DEBUG_DATA.subMenuOption == 3)
                            xPos += 12;
                        else
                            xPos += 13;
                    }
                    break;
                case 7:
                    if (BOOT_DEBUG_DATA.subMenuOption == 2)
                    {
                        xPos = sBootDebugMainEndObjOnOffText[0].xPosition;
                        yPos = sBootDebugMainEndObjOnOffText[0].yPosition;
                    }
                    else if (BOOT_DEBUG_DATA.subMenuOption == 3)
                    {
                        xPos = sBootDebugDoorTransitionOnOffText[0].xPosition;
                        yPos = sBootDebugDoorTransitionOnOffText[0].yPosition;
                    }
                    break;
            }

            yPos++;
            oamId = 2;
        }

        if (BOOT_DEBUG_DATA.menuCursor == 1 && BOOT_DEBUG_DATA.subMenuOption != 0)
        {
            xPos = 0;
            if (BOOT_DEBUG_DATA.subMenuOption == 2)
                xPos = 4;
            xPos *= 8;
            xPos += 168;
            yPos = 64;
        }
        else
        {
            yPos *= 8;
            xPos *= 8;
            xPos += 88;
            yPos -= gBg2VOFS_NonGameplay / 4;
            yPos *= 4;
        }

        xPos *= 4;
    }

    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MENU_CURSOR].yPosition = yPos;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MENU_CURSOR].xPosition = xPos;

    if (BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MENU_CURSOR].oamID != oamId)
    {
        BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MENU_CURSOR].oamID = oamId;
        BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MENU_CURSOR].animationDurationCounter = 0;
        BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MENU_CURSOR].currentAnimationFrame = 0;
    }
}

void BootDebugUpdateNonCursorOam(void)
{
    if (BOOT_DEBUG_DATA.menuCursor != BOOT_DEBUG_SUB_MENU_SECTION)
        BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_SAVE_BRACKETS].exists = FALSE;
    else if (!BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_SAVE_BRACKETS].exists)
        BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_SAVE_BRACKETS].exists = OAM_ID_CHANGED_FLAG;

    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_SAVE_BRACKETS].yPosition =
        sBootDebugSectionMenuText[BOOT_DEBUG_SECTION_SAVE_A + gMostRecentSaveFile].yPosition * 32;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_SAVE_BRACKETS].xPosition =
        sBootDebugSectionMenuText[BOOT_DEBUG_SECTION_SAVE_A + gMostRecentSaveFile].xPosition * 32;

    if (BOOT_DEBUG_DATA.menuDepth > BOOT_DEBUG_MENU_MAIN)
        BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_R_BUTTON_TITLE].exists = FALSE;
    else if (!BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_R_BUTTON_TITLE].exists)
        BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_R_BUTTON_TITLE].exists = OAM_ID_CHANGED_FLAG;
}

void BootDebugUpdateMapScreenPosition(void)
{    
    s32 xOffset;
    s32 yOffset;
    struct Door* pDoor;
    struct RoomEntryROM* pRoom;
    u16 mapX;
    u16 mapY;
    //s32 flag;
    
    xOffset = 2;
    yOffset = 2;
    
    if (gSectionInfo.sectionIndex >= BOOT_DEBUG_SECTION_TEST_1)
    {
        pDoor = &sAreaDoorsPointers[gSectionInfo.sectionIndex][gLastDoorUsed];
        xOffset = pDoor->xExit;
        if (xOffset > 0)
            xOffset = 0;
        else if (xOffset < 0)
            xOffset = 4;
    }

    pRoom = &sAreaRoomEntryPointers[gSectionInfo.sectionIndex][gCurrentRoom];
    mapX = pRoom->mapX;
    mapY = pRoom->mapY;
    pDoor = &sAreaDoorsPointers[gSectionInfo.sectionIndex][gLastDoorUsed];
    mapX += (pDoor->xStart - xOffset) / 15;
    mapY += (pDoor->yStart - yOffset) / 10;
    mapX *= 0x20;
    mapY *= 0x20;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MAP_CURSOR].xPosition = mapX;
    BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MAP_CURSOR].yPosition = mapY;

    BOOT_DEBUG_DATA.bg0vofs = mapY + 0x6D0;
    BOOT_DEBUG_DATA.bg0hofs = mapX + 0x630;

    if (gBg0VOFS_NonGameplay != BOOT_DEBUG_DATA.bg0vofs)
    {
        yOffset = FALSE;
        if (gBg0VOFS_NonGameplay < BOOT_DEBUG_DATA.bg0vofs)
        {
            gBg0VOFS_NonGameplay += 8;
            if (gBg0VOFS_NonGameplay > BOOT_DEBUG_DATA.bg0vofs)
                yOffset = TRUE;
        }
        else
        {
            gBg0VOFS_NonGameplay -= 8;
            if (gBg0VOFS_NonGameplay < BOOT_DEBUG_DATA.bg0vofs)
                yOffset = TRUE;
        }

        if (yOffset)
            gBg0VOFS_NonGameplay = BOOT_DEBUG_DATA.bg0vofs;        
    }

    if (gBg0HOFS_NonGameplay != BOOT_DEBUG_DATA.bg0hofs)
    {
        yOffset = FALSE;
        if (gBg0HOFS_NonGameplay < BOOT_DEBUG_DATA.bg0hofs)
        {
            gBg0HOFS_NonGameplay += 8;
            if (gBg0HOFS_NonGameplay > BOOT_DEBUG_DATA.bg0hofs)
                yOffset = TRUE;
        }
        else
        {
            gBg0HOFS_NonGameplay -= 8;
            if (gBg0HOFS_NonGameplay < BOOT_DEBUG_DATA.bg0hofs)
                yOffset = TRUE;
        }

        if (yOffset)
            gBg0HOFS_NonGameplay = BOOT_DEBUG_DATA.bg0hofs;        
    }
}

void BootDebugReadSram(void)
{
    u8 invalid;
    s32 i;
    struct SaveBootDebug* pSave;

    pSave = &gSram.bootDebugSave;
    invalid = FALSE;
    for (i = 0; i < 8; i++)
    {
        if (pSave->zeroSaveText[i] != sZeroSaveText[i])
        {
            invalid = TRUE;
            break;
        }
    }

    if (invalid)
    {
        for (i = 0; i < 8; i++)
            pSave->zeroSaveText[i] = sZeroSaveText[i];
    
        gDebugFlag = 2;
        gCurrentArea = 8;
        pSave->debugFlag = gDebugFlag;
        pSave->sectionIndex = gCurrentArea;
    }
    else
    {
        gDebugFlag = pSave->debugFlag;
        gCurrentArea = pSave->sectionIndex;
    }
}

void BootDebugWriteSram(u8 selectSaveFile)
{
    u8* dst;

    dst = gSram.bootDebugSave.zeroSaveText;
    DMATransfer(3, &sZeroSaveText, dst, 8, 8);
    gSram.bootDebugSave.debugFlag = gDebugFlag;

    if (selectSaveFile) {
        if (gMostRecentSaveFile == 0)
            gSram.bootDebugSave.sectionIndex = BOOT_DEBUG_SECTION_SAVE_A;
        else if (gMostRecentSaveFile == 1)
            gSram.bootDebugSave.sectionIndex = BOOT_DEBUG_SECTION_SAVE_B;
        else if (gMostRecentSaveFile == 2)
            gSram.bootDebugSave.sectionIndex = BOOT_DEBUG_SECTION_SAVE_C;
        else
            gSram.bootDebugSave.sectionIndex = BOOT_DEBUG_SECTION_BRINSTAR;
    }
    else
    {
        gSram.bootDebugSave.sectionIndex = gCurrentArea;
    }
    
    DoSramOperation(SRAM_OPERATION_SAVE_BOOT_DEBUG_RAM);
}

s32 BootDebugSubroutine(void)
{
    s32 result;
    s32 inputResult;

    result = FALSE;

    switch (gGameModeSub1)
    {
        case 0:
            BootDebugSetupMenu();
            gGameModeSub1++;
            break;
        case 1:
            if (gWrittenToBLDY_NonGameplay != 0)
            {
                if (gWrittenToBLDY_NonGameplay > 4)
                    gWrittenToBLDY_NonGameplay -= 4;
                else
                    gWrittenToBLDY_NonGameplay = 0;
            }
            else
            {
                gGameModeSub1++;
            }
            break;
        case 2:
            inputResult = BootDebugHandleInput();
            if (inputResult != 0)
            {
                if (inputResult == 2)
                {
                    write16(REG_BLDCNT, 0xBF);
                    gGameModeSub1 = 4;
                }
                else
                {
                    switch (gGameModeSub2)
                    {
                        case 1:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        default:
                            gCurrentCutscene = 0;
                            gTourianEscapeCutsceneStage = 0;
                            break;
                        case 2:
                            gCurrentCutscene = 0;
                            gTourianEscapeCutsceneStage = 0;
                            gDebugFlag = 0;
                            break;
                        case 7:
                        case 8:
                            break;
                    }
                    
                    BootDebugWriteSram(0);

                    if (gGameModeSub2 == 1)
                    {
                        if (gIsLoadingFile == 1)
                        {
                            SramLoadFile();
                            gLanguage = gGameCompletion.language;
                        }
                        else
                        {
                            gGameCompletion.completedGame = gSaveFilesInfo[gMostRecentSaveFile].completedGame;
                            gGameCompletion.introPlayed = gSaveFilesInfo[gMostRecentSaveFile].introPlayed;
                            gGameCompletion.language = gLanguage;
                        }
                    }
                    
                    gGameModeSub1++;
                }
            }
            break;
        case 3:
            if (gWrittenToBLDY_NonGameplay <= 0xF)
            {
                if (gWrittenToBLDY_NonGameplay <= 0xB)
                    gWrittenToBLDY_NonGameplay += 4;
                else
                    gWrittenToBLDY_NonGameplay = 0x10;
            }
            else
            {
                write16(PALRAM_BASE, 0);
                result = TRUE;
                gGameModeSub1 = 0;
            }
            break;
        case 4:
            if (gWrittenToBLDY_NonGameplay <= 0xF)
            {
                if (gWrittenToBLDY_NonGameplay <= 0xB)
                    gWrittenToBLDY_NonGameplay += 4;
                else
                    gWrittenToBLDY_NonGameplay = 0x10;
            }
            else
            {
                BOOT_DEBUG_DATA.dispcnt = 0x80;
                unk_33dc();
                EraseSram();
                gResetGame = TRUE;
                write16(PALRAM_BASE, 0);
                result = TRUE;
                gGameModeSub1 = 0;
            }
            break;
    }

    BootDebugUpdateMenuOam();
    return result;
}

void BootDebugSetVBlankCodePtr(void)
{
    SetVBlankCodePtr(VBlankCodeDuringBootDebug);
}

void VBlankCodeDuringBootDebug(void)
{
    if (gIoTransferInfo.linkInProgress)
        unk_8a730();
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);
    write16(REG_BG3VOFS, SUB_PIXEL_TO_PIXEL(gBg3VOFS_NonGameplay) & 0x1FF);
    write16(REG_BG2VOFS, SUB_PIXEL_TO_PIXEL(gBg2VOFS_NonGameplay) & 0x1FF);
    write16(REG_BG0VOFS, SUB_PIXEL_TO_PIXEL(gBg0VOFS_NonGameplay) & 0x1FF);
    write16(REG_BG0HOFS, SUB_PIXEL_TO_PIXEL(gBg0HOFS_NonGameplay) & 0x1FF);
    write16(REG_DISPCNT, BOOT_DEBUG_DATA.dispcnt);
}

// TODO: Replace numbers with constants
void BootDebugSetupMenu(void)
{
    write16(REG_IE, read16(REG_IE) ^ 1);
    write16(REG_IME, 0);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & 0xFFEF);
    write16(REG_IE, read16(REG_IE) & 0xFFFD);
    write16(REG_IF, 2);
    write16(REG_IME, 1);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = 0x10);
    write16(REG_BLDCNT, 0xFF);
    write16(REG_DISPCNT, 0);

    StopAllMusicAndSounds();
    sub_2988(0x194F780);
    UpdateMusicPriority(0);

    gGameModeSub2 = 0;
    gNextOamSlot = 0;
    ResetFreeOam();
    FillBytes(3, 0, &gNonGameplayRAM, 0x628, 32);
    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;
    
    WriteFileInfo();
    sub_BootDebug_7881c();
    gSramErrorFlag = 0;
    sub_7584C(2);
    LoadSoundModeFromSram();
    ApplyStereo();

    gBg3VOFS_NonGameplay = BOOT_DEBUG_DATA.unk_05 * 0x40;
    gBg2VOFS_NonGameplay = BOOT_DEBUG_DATA.unk_06 * 0x40 - 0x10;
    gBg2HOFS_NonGameplay = 0xFEA0;
    
    LZ77UncompVRAM(sBootDebugObjGfx, VRAM_OBJ);
    LZ77UncompVRAM(sBootDebugBgGfx, VRAM_BASE);
    DMA_SET(3, sMinimapTilesGfx, VRAM_BASE + 0x4000, C_32_2_16(DMA_ENABLE, 0x1800));
    DMA_SET(3, sMinimapTilesPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, 0x50));
    DMA_SET(3, sBootDebugBgPal, PALRAM_BASE + 0x100, C_32_2_16(DMA_ENABLE, 0x80));
    DMA_SET(3, sBootDebugObjPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, 0x30));

    FillBytes(3, 0xD040, VRAM_BASE + 0xF000, 0x1000, 16);
    FillBytes(3, 0x8040, VRAM_BASE + 0xE000, 0x1000, 16);
    FillBytes(3, 0xE040, VRAM_BASE + 0xD000, 0x1000, 16);
    FillBytes(3, 0x1140, VRAM_BASE + 0xB800, 0x1800, 16);

    gWrittenToBLDY_NonGameplay = 0x10;
    write16(REG_BG0VOFS, 0);
    write16(REG_BG0HOFS, 0);
    write16(REG_BG1VOFS, 0xFFF0);
    write16(REG_BG1HOFS, 0xFF58);
    write16(REG_BG2VOFS, (gBg2VOFS_NonGameplay / 4) & 0x1FF);
    write16(REG_BG2HOFS, (gBg2HOFS_NonGameplay / 4) & 0x1FF);
    write16(REG_BG3VOFS, (gBg3VOFS_NonGameplay / 4) & 0x1FF);
    write16(REG_BG3HOFS, 0);

    gIoTransferInfo = sIoTransferInfo_Empty;
    gIoTransferInfo.pFunction = BootDebugUpdateMenuOam;
    sub_BootDebug_782f0();
    BootDebugUpdateMenuOam();

    if (BOOT_DEBUG_DATA.menuCursor == 0)
    {
        BOOT_DEBUG_DATA.menuCursor = BOOT_DEBUG_SUB_MENU_SECTION;
        BOOT_DEBUG_DATA.subMenuOption = BOOT_DEBUG_SECTION_BRINSTAR;
        BOOT_DEBUG_DATA.optionCursor = 0;
        BOOT_DEBUG_DATA.subMenu = BOOT_DEBUG_DATA.menuCursor;
    }

    BootDebugDrawMenuNames();
    write16(REG_WIN1H, 0x54EC);
    write16(REG_WIN1V, 0x149C);
    write16(REG_WINOUT, 0x39);
    write8(REG_WININ + 1, 0x3D);
    write8(REG_WININ, 0x32);
    write16(REG_BG3CNT, 0x9E03);
    write16(REG_BG2CNT, 0x9C02);
    write16(REG_BG1CNT, 0x9A00);
    write16(REG_BG0CNT, 0xF605);
    BOOT_DEBUG_DATA.dispcnt = 0x5C00;
    write16(REG_DISPCNT, 0x5C00);

    if (BOOT_DEBUG_DATA.menuCursor == BOOT_DEBUG_SUB_MENU_SECTION &&
        BOOT_DEBUG_DATA.subMenuOption != BOOT_DEBUG_SECTION_BRINSTAR)
        sub_BootDebug_SECTION_MapRelated2(0);

    BootDebugSetVBlankCodePtr();
    write16(REG_IE, read16(REG_IE) | 1);
}

// Returns 1 if leaving menu, 2 if erasing SRAM, 0 otherwise
s32 BootDebugHandleInput(void)
{
    s32 result;
    s32 subMenuResult;
    s32 tempResult;
    u8 doorId;
    s8 sgm2;

    result = 0;
    subMenuResult = TRUE;
    tempResult = 0;

    CheckSustainedInputForScrolling();

    if (BOOT_DEBUG_DATA.menuDepth == BOOT_DEBUG_MENU_MAIN && gChangedInput & KEY_R)
    {
        gGameModeSub2 = 2;
        return 1;
    }

    if (gChangedInput & KEY_START ||
       (BOOT_DEBUG_DATA.menuCursor == 1 && gChangedInput & KEY_A &&
       BOOT_DEBUG_DATA.menuDepth != BOOT_DEBUG_MENU_MAIN))
    {
        if (gSectionInfo.sectionIndex == BOOT_DEBUG_SECTION_TITLE)
        {
            gGameModeSub2 = 2;
            result = 1;
        }
        else if (gSectionInfo.sectionIndex >= BOOT_DEBUG_SECTION_SAVE_A
            && gSectionInfo.sectionIndex <= BOOT_DEBUG_SECTION_SAVE_C)
        {
            if (gSectionInfo.sectionIndex == BOOT_DEBUG_SECTION_SAVE_C)
                gMostRecentSaveFile = 2;
            else if (gSectionInfo.sectionIndex == BOOT_DEBUG_SECTION_SAVE_B)
                gMostRecentSaveFile = 1;
            else
                gMostRecentSaveFile = 0;
    
            if (gSaveFilesInfo[gMostRecentSaveFile].exists == 1)
            {
                gCurrentArea = gSectionInfo.sectionIndex;
                gIsLoadingFile = 1;
                gGameModeSub2 = 1;
                result = 1;
            }
        }
        else if (gSectionInfo.sectionIndex != BOOT_DEBUG_SECTION_BLANK)
        {
            result = 1;
            gGameModeSub2 = 1;
            gIsLoadingFile = 0;
        
            if (gCurrentArea != gSectionInfo.sectionIndex && !gSectionInfo.onMapScreen)
            {
                gCurrentRoom = 0;
                doorId = gLastDoorUsed;
                if (gSectionInfo.sectionIndex <= BOOT_DEBUG_SECTION_TEST_1)
                    doorId = 1;
                else
                    doorId = 0;
                gLastDoorUsed = doorId;
            }
        
            gCurrentArea = gSectionInfo.sectionIndex;
        }
    }
    else if (BOOT_DEBUG_DATA.menuDepth == BOOT_DEBUG_MENU_MAIN)
    {
        tempResult = 0;
        if (gChangedInput & KEY_A)
        {
            BOOT_DEBUG_DATA.menuDepth = BOOT_DEBUG_MENU_SUB;

            if (BOOT_DEBUG_DATA.subMenu != BOOT_DEBUG_DATA.menuCursor)
            {
                BOOT_DEBUG_DATA.subMenuOption = 0;
                BOOT_DEBUG_DATA.optionCursor = 0;
            }

            BOOT_DEBUG_DATA.subMenu = BOOT_DEBUG_DATA.menuCursor;
            
            if (BOOT_DEBUG_DATA.menuCursor == BOOT_DEBUG_SUB_MENU_SAVE)
            {
                BOOT_DEBUG_DATA.fileScreenOptions = gFileScreenOptionsUnlocked;
                BootDebugDrawText(sBootDebugSaveMenuText[BOOT_DEBUG_SAVE_SAVE].background,
                    sBootDebugSaveMenuText[BOOT_DEBUG_SAVE_SAVE].xPosition,
                    sBootDebugSaveMenuText[BOOT_DEBUG_SAVE_SAVE].yPosition,
                    sBootDebugSaveMenuText[BOOT_DEBUG_SAVE_SAVE].palette,
                    sBootDebugSaveMenuText[BOOT_DEBUG_SAVE_SAVE].size,
                    sBootDebugSaveMenuText[BOOT_DEBUG_SAVE_SAVE].text);
            }
        }
        else if (gChangedInput & KEY_UP)
        {
            if (BOOT_DEBUG_DATA.menuCursor > 1)
            {
                BOOT_DEBUG_DATA.menuCursor--;
                tempResult = 1;
            }
            else
            {
                BOOT_DEBUG_DATA.menuCursor = BOOT_DEBUG_SUB_MENU_COUNT - 1;
                tempResult = 1;
            }
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (BOOT_DEBUG_DATA.menuCursor + 1 < BOOT_DEBUG_SUB_MENU_COUNT)
            {
                BOOT_DEBUG_DATA.menuCursor++;
                tempResult = 1;
            }
            else
            {
                BOOT_DEBUG_DATA.menuCursor = 1;
                tempResult = 1;
            }
        }

        if (BOOT_DEBUG_DATA.menuCursor - BOOT_DEBUG_DATA.unk_05 > 8)
            BOOT_DEBUG_DATA.unk_05 = BOOT_DEBUG_DATA.menuCursor - 8;
        else if (BOOT_DEBUG_DATA.unk_05 > BOOT_DEBUG_DATA.menuCursor - 1)
            BOOT_DEBUG_DATA.unk_05 = BOOT_DEBUG_DATA.menuCursor - 1;
        
        gBg3VOFS_NonGameplay = BOOT_DEBUG_DATA.unk_05 * 0x40;

        if (tempResult != 0)
            BootDebugDrawSubMenuText();
    }
    else
    {
        switch (BOOT_DEBUG_DATA.menuCursor)
        {
            case BOOT_DEBUG_SUB_MENU_SECTION:
                subMenuResult = BootDebugSectionSubroutine();
                break;
            case BOOT_DEBUG_SUB_MENU_MODE:
                BootDebugModeSubroutine();
                subMenuResult = FALSE;
                break;
            case BOOT_DEBUG_SUB_MENU_SAVE:
                BootDebugSaveSubroutine();
                subMenuResult = FALSE;
                break;
            case BOOT_DEBUG_SUB_MENU_SAMUS:
                BootDebugSamusSubroutine();
                if (BOOT_DEBUG_DATA.subMenuOption - BOOT_DEBUG_DATA.unk_06 > 7)
                    BOOT_DEBUG_DATA.unk_06 = BOOT_DEBUG_DATA.subMenuOption - 7;   
                else if (BOOT_DEBUG_DATA.unk_06 > BOOT_DEBUG_DATA.subMenuOption)
                    BOOT_DEBUG_DATA.unk_06 = BOOT_DEBUG_DATA.subMenuOption;   
                gBg2VOFS_NonGameplay = (BOOT_DEBUG_DATA.unk_06 * 0x40) - 0x10;
                break;
            case BOOT_DEBUG_SUB_MENU_SOUND:
                BootDebugSoundSubroutine();
                break;
            case BOOT_DEBUG_SUB_MENU_DEMO:
                tempResult = BootDebugDemoSubroutine();
                if (tempResult != 0)
                {
                    if (tempResult == 1)
                    {
                        gGameModeSub2 = 7;
                        gSramErrorFlag = 0x10;
                    }
                    else if (tempResult == 2)
                    {
                        gGameModeSub2 = 8;
                        gSramErrorFlag = 0x10;
                    }
                    else
                    {
                        gCurrentDemo.noDemoShuffle = 1;
                        DemoInit();
                        // Written this way to produce matching code
                        sgm2 = gGameModeSub2;
                        sgm2 = gDemoState != 0 ? 6 : 1;
                        gGameModeSub2 = sgm2;
                    }
                    result = 1;
                }
                break;
            case BOOT_DEBUG_SUB_MENU_ETC:
                gSramErrorFlag = BootDebugEtcSubroutine();
                if (gSramErrorFlag != 0)
                {
                    // Written this way to produce matching code
                    sgm2 = gGameModeSub2;
                    sgm2 = gSramErrorFlag == 1 ? 4 : 5;
                    gGameModeSub2 = sgm2;
                    gSramErrorFlag = 1;
                    result = 1;
                }
                break;
            case BOOT_DEBUG_SUB_MENU_BOOT:
                subMenuResult = FALSE;
                gSramErrorFlag = 1;
                
                if (gIoTransferInfo.active == 0)
                {
                    if (gChangedInput & KEY_A)
                        gIoTransferInfo.active = 1;
                    else
                        subMenuResult = TRUE;
                }
                else if (gIoTransferInfo.active == 1)
                {
                    tempResult = sub_808E490();
                }
                else if (gIoTransferInfo.active == 2)
                {
                    tempResult = sub_8089E30();
                }
    
                if (tempResult == 4 || tempResult == 2)
                {
                    if (!(gChangedInput & KEY_B))
                        return result;
    
                    BOOT_DEBUG_DATA.menuDepth = BOOT_DEBUG_MENU_MAIN;
                    gIoTransferInfo = sIoTransferInfo_Empty;
                    gIoTransferInfo.pFunction = BootDebugUpdateMenuOam;
                    BootDebugDrawSubMenuText();
                }
                else if (tempResult == 1)
                {
                    if (!(gChangedInput & KEY_B))
                        return result;
    
                    BOOT_DEBUG_DATA.menuDepth = BOOT_DEBUG_MENU_MAIN;
                    gIoTransferInfo = sIoTransferInfo_Empty;
                    gIoTransferInfo.pFunction = BootDebugUpdateMenuOam;
                    BootDebugDrawSubMenuText();
                }
                break;
            case BOOT_DEBUG_SUB_MENU_ERASE:
                if (BOOT_DEBUG_DATA.subMenuOption > 0)
                {
                    if (gChangedInput & KEY_UP)
                        BOOT_DEBUG_DATA.subMenuOption = 0;
                    else if (gChangedInput & KEY_A)
                        result = 2;
                }
                else if (gChangedInput & KEY_DOWN)
                {
                    BOOT_DEBUG_DATA.subMenuOption = 1;
                }
                else if (gChangedInput & KEY_A)
                {
                    BOOT_DEBUG_DATA.menuDepth = BOOT_DEBUG_MENU_MAIN;
                }
    
                if (gChangedInput & KEY_B || BOOT_DEBUG_DATA.menuDepth == BOOT_DEBUG_MENU_MAIN)
                    BOOT_DEBUG_DATA.subMenuOption = 0;
                break;
        }
    
        if (gChangedInput & KEY_B && subMenuResult && BOOT_DEBUG_DATA.menuDepth > BOOT_DEBUG_MENU_MAIN)
            BOOT_DEBUG_DATA.menuDepth--;
    }

    return result;
}

s32 BootDebugSectionSubroutine(void)
{
    s32 index;
    u8 prevStarIndex;
    
    if (BOOT_DEBUG_DATA.subMenuOption == 0)
    {
        if (gChangedInput & KEY_SELECT && gSectionInfo.sectionIndex < BOOT_DEBUG_SECTION_TITLE)
        {
            BOOT_DEBUG_DATA.subMenuOption++;
            BootDebugSectionMapRoomOrDoorUpdated(BOOT_DEBUG_DATA.subMenuOption - 1);
            BootDebugSectionMapDrawRoomAndDoorIds(0);
            gSectionInfo.onMapScreen = TRUE;
            return FALSE;
        }
        index = 0;
        prevStarIndex = gSectionInfo.starIndex;
        
        if (gChangedInput & KEY_RIGHT)
            index = 1;
        else if (gChangedInput & KEY_LEFT)
            index = 2;
        else if (gChangedInput & KEY_UP)
            index = 3;
        else if (gChangedInput & KEY_DOWN)
            index = 4;

        if (index != 0)
        {
            index = sBootDebugSectionCursorMovement[gSectionInfo.sectionIndex][index - 1];
            if (index == 0x80)
            {
                index = FALSE;
            }
            else
            {
                gSectionInfo.sectionIndex = index;
                index = TRUE;
                gSectionInfo.starIndex = gSectionInfo.sectionIndex;
                BootDebug_SECTION_DrawStar(prevStarIndex);
            }
        }

        if (gChangedInput & KEY_B)
            index = TRUE;

        return index;
    }

    if (BOOT_DEBUG_DATA.subMenuOption == 1 || BOOT_DEBUG_DATA.subMenuOption == 2)
    {
        if (gChangedInput & (KEY_B | KEY_SELECT))
        {
            write16(REG_WIN0H, 0);
            write16(REG_WIN0V, 0);
            BOOT_DEBUG_DATA.dispcnt ^= 0x2300;
            BOOT_DEBUG_DATA.menuOam[3].exists = 0;
            BOOT_DEBUG_DATA.subMenuOption = 0;
            gSectionInfo.onMapScreen = FALSE;
            return FALSE;
        }
        
        if (gChangedInput & KEY_RIGHT)
            BOOT_DEBUG_DATA.subMenuOption = 2;
        else if (gChangedInput & KEY_LEFT)
            BOOT_DEBUG_DATA.subMenuOption = 1;

        if (BOOT_DEBUG_DATA.subMenuOption == 1)
        {
            if (gChangedInput & KEY_UP)
            {
                if (gCurrentRoom > 0)
                    gCurrentRoom--;
            }
            else if (gChangedInput & KEY_DOWN)
            {
                if (gCurrentRoom < 0xFE)
                    gCurrentRoom++;
            }
        }
        else
        {
            if (gChangedInput & KEY_UP)
            {
                if (gLastDoorUsed > 0)
                    gLastDoorUsed--;
            }
            else if (gChangedInput & KEY_DOWN)
            {
                if (gLastDoorUsed < 0xFE)
                    gLastDoorUsed++;
            }
        }

        if ((gChangedInput & (KEY_UP | KEY_DOWN)))
        {
            gPauseScreenFlag = 0;
            BootDebugSectionMapRoomOrDoorUpdated(BOOT_DEBUG_DATA.subMenuOption - 1);
            BootDebugSectionMapDrawRoomAndDoorIds(1);
        }

        return FALSE;
    }
}

// roomOrDoor: -1 = loading, 0 = room, 1 = door
void BootDebugSectionMapRoomOrDoorUpdated(u8 roomOrDoor)
{
    s32 doorCount;
    s32 highestRoomId;
    struct Door* pDoor;
    s32 elevator;
    s32 doorId;

    // Get door count and highest room ID
    pDoor = sAreaDoorsPointers[gSectionInfo.sectionIndex];
    doorCount = 0;
    highestRoomId = 0;
    while (pDoor->type != 0)
    {
        if (highestRoomId <= pDoor->sourceRoom)
            highestRoomId = pDoor->sourceRoom;
        doorCount++;
        pDoor++;
    }

    if (gCurrentRoom > highestRoomId)
    {
        gCurrentRoom = highestRoomId;
        gPauseScreenFlag = PAUSE_SCREEN_NONE;
    }

    if (gLastDoorUsed > doorCount - 1)
    {
        gLastDoorUsed = doorCount - 1;
        gPauseScreenFlag = PAUSE_SCREEN_NONE;
    }

    if (roomOrDoor == 0) // Room
    {
        // Find a door that's in the current room
        pDoor = sAreaDoorsPointers[gSectionInfo.sectionIndex];
        doorId = 0;
        while (pDoor->type != 0)
        {
            if (pDoor->sourceRoom == gCurrentRoom)
            {
                // We don't want to spawn Samus next to an elevator transition, so
                // skip this door if it's an elevator to the current room
                elevator = 1;
                while (sElevatorRoomPairs[elevator].area1 != gSectionInfo.sectionIndex ||
                    sElevatorRoomPairs[elevator].room1 != gCurrentRoom)
                {
                    if (sElevatorRoomPairs[elevator].area2 == gSectionInfo.sectionIndex &&
                        sElevatorRoomPairs[elevator].room2 == gCurrentRoom)
                        break;

                    elevator++;
                    if (elevator >= ELEVATOR_ROUTE_COUNT)
                    {
                        // No elevator to this room
                        gLastDoorUsed = doorId;
                        break; // FIXME: asm jumps to return
                    }
                }

                // FIXME: first condition jumps to line 58
                if (elevator >= ELEVATOR_ROUTE_COUNT || (pDoor->type & 0xF) >= DOOR_TYPE_OPEN_HATCH)
                {
                    // No elevator to this room, or the door is a hatch
                    gLastDoorUsed = doorId;
                    break;
                }
            }

            pDoor++;
            doorId++;
        }
    }
    else // Door
    {
        // Set room ID to the current door's room
        pDoor = sAreaDoorsPointers[gSectionInfo.sectionIndex];
        pDoor = pDoor + gLastDoorUsed;
        gCurrentRoom = pDoor->sourceRoom;
    }
}

void BootDebugSectionMapDrawRoomAndDoorIds(u8 initialized)
{
    u16* dst;
    s32 i;
    s32 number;
    s32 offset;
    s32 divisor;
    s32 drawDigit;
    s32 tile;

    if (!initialized)
    {
        CallLz77UnComp16Bit(sMinimapDataPointers[gSectionInfo.sectionIndex], VRAM_BASE + 0xB000);
        BootDebugUpdateMapScreenPosition();
        gBg0VOFS_NonGameplay = BOOT_DEBUG_DATA.bg0vofs;
        gBg0HOFS_NonGameplay = BOOT_DEBUG_DATA.bg0hofs;
        write16(REG_WIN0H, 0x9CEC);
        write16(REG_WIN0V, 0x1020);
        BOOT_DEBUG_DATA.dispcnt |= 0x2300;
        BOOT_DEBUG_DATA.menuOam[BOOT_DEBUG_OAM_MAP_CURSOR].exists = OAM_ID_CHANGED_FLAG;
    }

    dst = VRAM_BASE + 0xD000;
    tile = 0xE0C8;
    dst[0] = tile;
    dst[0x20] = tile + 0x20;
    
    tile = 0xE0C7;
    dst[4] = tile;
    dst[0x24] = tile + 0x20;

    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            // Draw room ID number
            number = gCurrentRoom + 1;
            offset = 1;
            divisor = 10;
        }
        else
        {
            // Draw door ID number
            number = gLastDoorUsed;
            offset = 5;
            divisor = 100;
        }

        dst = VRAM_BASE + 0xD000;
        drawDigit = FALSE;
        
        if (divisor <= 0)
            continue;
        
        while (divisor > 0)
        {
            tile = (number / divisor) % 10;
            if (divisor == 1)
                drawDigit = TRUE; // Always draw ones place

            if (tile == 0 && !drawDigit)
                tile = 0xE040; // Blank
            else
                drawDigit = TRUE;

            if (tile < 10)
                tile += 0xE050;
            
            dst[offset] = tile;
            dst[offset + 0x20] = tile + 0x20;
            divisor /= 10;
            offset++;
        }
    }
}

void BootDebugModeSubroutine(void)
{
    s32 updateTextAndEvents;

    if (BOOT_DEBUG_DATA.menuDepth == BOOT_DEBUG_MENU_SUB)
    {
        if (gChangedInput & KEY_A)
        {
            BOOT_DEBUG_DATA.menuDepth = BOOT_DEBUG_MENU_OPTION;
        }
        else if (gChangedInput & KEY_B)
        {
            BOOT_DEBUG_DATA.menuDepth--;
        }
        else if (gChangedInput & KEY_UP)
        {
            if (BOOT_DEBUG_DATA.subMenuOption != BOOT_DEBUG_MODE_LANGUAGE)
                BOOT_DEBUG_DATA.subMenuOption--;
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (BOOT_DEBUG_DATA.subMenuOption == BOOT_DEBUG_MODE_LANGUAGE)
                BOOT_DEBUG_DATA.subMenuOption++;
        }
    }
    else // menuDepth == BOOT_DEBUG_MENU_OPTION
    {
        updateTextAndEvents = FALSE;
        switch (BOOT_DEBUG_DATA.subMenuOption)
        {
            case BOOT_DEBUG_MODE_LANGUAGE:
                if (gChangedInput & KEY_B)
                {
                    SramWrite_Language();
                    BOOT_DEBUG_DATA.menuDepth--;
                }
                else if (gChangedInput & KEY_UP)
                {
                    gLanguage++;
                    if (gLanguage >= LANGUAGE_END)
                        gLanguage = LANGUAGE_JAPANESE;
                    updateTextAndEvents = TRUE;
                }
                else if (gChangedInput & KEY_DOWN)
                {
                    if (gLanguage != LANGUAGE_JAPANESE)
                        gLanguage--;
                    else
                        gLanguage = LANGUAGE_SPANISH;
                    updateTextAndEvents = TRUE;
                }
                break;
            case BOOT_DEBUG_MODE_DIFFICULTY:
                if (gChangedInput & KEY_B)
                {
                    BOOT_DEBUG_DATA.menuDepth--;
                }
                else if (gChangedInput & KEY_UP)
                {
                    gDifficulty++;
                    if (gDifficulty >= DIFF_END)
                        gDifficulty = DIFF_EASY;
                    updateTextAndEvents = TRUE;
                }
                else if (gChangedInput & KEY_DOWN)
                {
                    if (gDifficulty != DIFF_EASY)
                        gDifficulty--;
                    else
                        gDifficulty = DIFF_HARD;
                    updateTextAndEvents = TRUE;
                }
                break;
        }
    }

    // BUG: updateTextAndEvents is only initialized when menuDepth == 2 
    if (updateTextAndEvents)
    {
        BootDebugUpdateSingleText(BOOT_DEBUG_SUB_MENU_MODE, BOOT_DEBUG_DATA.subMenuOption);
        // Clear or set easy event
        EventFunction(sEasyHardEventActions[gDifficulty][0], EVENT_EASY);
        // Clear or set hard event
        EventFunction(sEasyHardEventActions[gDifficulty][1], EVENT_HARD);
    }
}

void BootDebugSaveSubroutine(void)
{
    s32 value;
    
    if (BOOT_DEBUG_DATA.menuDepth == BOOT_DEBUG_MENU_SUB)
    {
        if (gChangedInput & KEY_A)
        {
            if (BOOT_DEBUG_DATA.subMenuOption == BOOT_DEBUG_SAVE_SAVE)
            {
                gFileScreenOptionsUnlocked = BOOT_DEBUG_DATA.fileScreenOptions;
                SramWrite_FileScreenOptionsUnlocked();
                BootDebugSaveSetSaveTextColor();
            }
            else if (BOOT_DEBUG_DATA.subMenuOption != BOOT_DEBUG_SAVE_ID)
            {
                BOOT_DEBUG_DATA.optionCursor = 0;
                BOOT_DEBUG_DATA.menuDepth = BOOT_DEBUG_MENU_OPTION;
            }
        }
        else if (gChangedInput & KEY_B)
        {
            for (value = BOOT_DEBUG_SAVE_GALLERY_IMAGES; value <= BOOT_DEBUG_SAVE_SAVE; value++)
                BootDebugSaveUpdateText(value, &gFileScreenOptionsUnlocked);
            
            BOOT_DEBUG_DATA.menuDepth--;
        }
        else if (gChangedInput & KEY_UP)
        {
            if (BOOT_DEBUG_DATA.subMenuOption > BOOT_DEBUG_SAVE_GALLERY_IMAGES)
                BOOT_DEBUG_DATA.subMenuOption--;
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (BOOT_DEBUG_DATA.subMenuOption < BOOT_DEBUG_SAVE_SAVE)
                BOOT_DEBUG_DATA.subMenuOption++;
        }
    }
    else // menuDepth == BOOT_DEBUG_MENU_OPTION
    {
        value = FALSE;

        switch (BOOT_DEBUG_DATA.subMenuOption)
        {
            case BOOT_DEBUG_SAVE_GALLERY_IMAGES:
                if (gChangedInput & KEY_B)
                {
                    BOOT_DEBUG_DATA.menuDepth--;
                }
                else if (gChangedInput & KEY_A)
                {
                    BOOT_DEBUG_DATA.fileScreenOptions.galleryImages ^=
                        1 << BOOT_DEBUG_DATA.optionCursor;
                    value = TRUE;
                }
                else if (gChangedInput & KEY_RIGHT)
                {
                    if (BOOT_DEBUG_DATA.optionCursor < 7)
                        BOOT_DEBUG_DATA.optionCursor++;
                }
                else if (gChangedInput & KEY_LEFT)
                {
                    if (BOOT_DEBUG_DATA.optionCursor > 0)
                        BOOT_DEBUG_DATA.optionCursor--;
                }
                break;
            case BOOT_DEBUG_SAVE_DIFFICULTIES_CLEARED:
                if (gChangedInput & KEY_B)
                {
                    BOOT_DEBUG_DATA.menuDepth--;
                }
                else if (gChangedInput & KEY_A)
                {
                    BOOT_DEBUG_DATA.fileScreenOptions.soundTestAndOgMetroid ^=
                        1 << BOOT_DEBUG_DATA.optionCursor;
                    value = TRUE;
                }
                else if (gChangedInput & KEY_RIGHT)
                {
                    if (BOOT_DEBUG_DATA.optionCursor < 2)
                        BOOT_DEBUG_DATA.optionCursor++;
                }
                else if (gChangedInput & KEY_LEFT)
                {
                    if (BOOT_DEBUG_DATA.optionCursor > 0)
                        BOOT_DEBUG_DATA.optionCursor--;
                }
                break;
            case BOOT_DEBUG_SAVE_LINKED_WITH_FUSION:
                if (gChangedInput & KEY_B)
                {
                    BOOT_DEBUG_DATA.menuDepth--;
                }
                else if (gChangedInput & KEY_A)
                {
                    BOOT_DEBUG_DATA.fileScreenOptions.fusionGalleryImages =
                        BOOT_DEBUG_DATA.optionCursor ? 0 : 0x10;
                    value = TRUE;
                }
                else if (gChangedInput & KEY_RIGHT)
                {
                    if (BOOT_DEBUG_DATA.optionCursor == 0)
                        BOOT_DEBUG_DATA.optionCursor++;
                }
                else if (gChangedInput & KEY_LEFT)
                {
                    if (BOOT_DEBUG_DATA.optionCursor != 0)
                        BOOT_DEBUG_DATA.optionCursor = 0;
                }
                break;
        }

        if (value)
        {
            BootDebugTimeAttackRelated(BOOT_DEBUG_DATA.subMenuOption,
                &BOOT_DEBUG_DATA.fileScreenOptions);
        }
    }
}

void BootDebugSaveUpdateText(u8 subMenuOption, struct FileScreenOptionsUnlocked* fileScreenOptions)
{
    u16* dst;
    s32 offset;
    s32 i;
    s32 index;
    u8 idText[9];

    dst = VRAM_BASE + 0xE000;
    offset = sBootDebugSaveMenuText[subMenuOption].yPosition * 0x20 +
        sBootDebugSaveMenuText[subMenuOption].xPosition;

    switch (subMenuOption)
    {
        case BOOT_DEBUG_SAVE_GALLERY_IMAGES:
            offset += 9;
            for (i = 0; i < 8; i++, offset++)
            {
                index = (fileScreenOptions->galleryImages >> i) & 1;
                dst[offset] = (dst[offset] & 0x3FF) | (sBootDebugTextToggleColors[index][0] << 12);
                dst[offset + 0x20] = (dst[offset + 0x20] & 0x3FF) | (sBootDebugTextToggleColors[index][0] << 12);
            }
            break;
        case BOOT_DEBUG_SAVE_DIFFICULTIES_CLEARED:
            offset += 12;
            for (i = 0; i < 3; i++, offset += 2)
            {
                index = (fileScreenOptions->soundTestAndOgMetroid >> i) & 1;
                dst[offset] = (dst[offset] & 0x3FF) | (sBootDebugTextToggleColors[index][0] << 12);
                dst[offset + 0x20] = (dst[offset + 0x20] & 0x3FF) | (sBootDebugTextToggleColors[index][0] << 12);
            }
            break;
        case BOOT_DEBUG_SAVE_LINKED_WITH_FUSION:
            offset += 9;
            index = fileScreenOptions->fusionGalleryImages ? 1 : 0;
            for (i = 0; i < 3; i++, offset++)
            {
                dst[offset] = (dst[offset] & 0x3FF) | (sBootDebugTextToggleColors[index][0] << 12);
                dst[offset + 0x20] = (dst[offset + 0x20] & 0x3FF) | (sBootDebugTextToggleColors[index][0] << 12);
            }
            offset++;
            for (i = 0; i < 2; i++, offset++)
            {
                dst[offset] = (dst[offset] & 0x3FF) | (sBootDebugTextToggleColors[index][1] << 12);
                dst[offset + 0x20] = (dst[offset + 0x20] & 0x3FF) | (sBootDebugTextToggleColors[index][1] << 12);
            }
            break;
        case BOOT_DEBUG_SAVE_ID:
            for (i = 0; i < 9; i++)
                idText[i] = 0;
            unk_7f60c(idText);
            BootDebugDrawLine(dst + 9 + offset, idText, 0xC);
            break;
    }
}

void BootDebugSaveSetSaveTextColor(void)
{
    s32 offset;
    u16* dst;
    s32 i;

    offset = sBootDebugSaveMenuText[4].xPosition + (sBootDebugSaveMenuText[4].yPosition * 0x20);
    dst = VRAM_BASE + 0xE000;
    for (i = 0; i < 4; i++, offset++)
    {
        dst[offset] = (dst[offset] & 0x3FF) | 0x9000;
        dst[offset + 32] = (dst[offset + 32] & 0x3FF) | 0x9000;
    }
}

void BootDebugSamusSubroutine(void)
{
    s32 option;
    u16 flagOrButton;
    
    if (BOOT_DEBUG_DATA.menuDepth == BOOT_DEBUG_MENU_SUB)
    {
        if (gChangedInput & (KEY_A | KEY_RIGHT))
        {
            BOOT_DEBUG_DATA.menuDepth = BOOT_DEBUG_MENU_OPTION;
        }
        else if (gChangedInput & KEY_UP)
        {
            if (BOOT_DEBUG_DATA.subMenuOption > 0)
                BOOT_DEBUG_DATA.subMenuOption--;
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (BOOT_DEBUG_DATA.subMenuOption < BOOT_DEBUG_SAMUS_COUNT - 1)
                BOOT_DEBUG_DATA.subMenuOption++;
        }
    }
    else
    {
        option = BOOT_DEBUG_DATA.subMenuOption == 0 ? 6 : 2;

        if (gChangedInput & KEY_RIGHT)
        {
            if (BOOT_DEBUG_DATA.optionCursor < option)
                BOOT_DEBUG_DATA.optionCursor++;
        }
        else if (gChangedInput & KEY_LEFT)
        {
            if (BOOT_DEBUG_DATA.optionCursor > 0)
                BOOT_DEBUG_DATA.optionCursor--;
            else
                BOOT_DEBUG_DATA.menuDepth--;
        }

        option = 0;

        switch (BOOT_DEBUG_DATA.subMenuOption)
        {
            case BOOT_DEBUG_SAMUS_GET_MAP:
                flagOrButton = 0x40;
                flagOrButton >>= BOOT_DEBUG_DATA.optionCursor;
                if (gChangedInput & KEY_UP)
                {
                    gEquipment.downloadedMapStatus |= flagOrButton;
                    option = 1;
                }
                else if (gChangedInput & KEY_DOWN)
                {
                    gEquipment.downloadedMapStatus &= ~flagOrButton;
                    option = 1;
                }
                else if (gChangedInput & KEY_A)
                {
                    gEquipment.downloadedMapStatus ^= flagOrButton;
                    option = 1;
                }
                else if (gChangedInput & KEY_R)
                {
                    gEquipment.downloadedMapStatus = 0xFF;
                    option = 1;
                }
                else if (gChangedInput & KEY_L)
                {
                    gEquipment.downloadedMapStatus = 0;
                    option = 1;
                }
                gSectionInfo.downloadedMaps = gEquipment.downloadedMapStatus;
                break;
            case BOOT_DEBUG_SAMUS_ARM_WEAPON:
                flagOrButton = gButtonAssignments.armWeapon;
                if (gChangedInput & KEY_A)
                    gButtonAssignments.armWeapon = gButtonAssignments.armWeapon == KEY_L ? KEY_R : KEY_L;
                else if (gChangedInput & KEY_L)
                    gButtonAssignments.armWeapon = KEY_L;
                else if (gChangedInput & KEY_R)
                    gButtonAssignments.armWeapon = KEY_R;

                gButtonAssignments.diagonalAim = gButtonAssignments.armWeapon == KEY_L ? KEY_R : KEY_L;
                if (flagOrButton != gButtonAssignments.armWeapon)
                    option = 2;
                break;
            case BOOT_DEBUG_SAMUS_DIAGONAL_AIM:
                flagOrButton = gButtonAssignments.diagonalAim;
                if (gChangedInput & KEY_A)
                    gButtonAssignments.diagonalAim = gButtonAssignments.diagonalAim == KEY_L ? KEY_R : KEY_L;
                else if (gChangedInput & KEY_L)
                    gButtonAssignments.diagonalAim = KEY_L;
                else if (gChangedInput & KEY_R)
                    gButtonAssignments.diagonalAim = KEY_R;

                gButtonAssignments.armWeapon = gButtonAssignments.diagonalAim == KEY_L ? KEY_R : KEY_L;
                if (flagOrButton != gButtonAssignments.diagonalAim)
                    option = 3;
                break;
            case BOOT_DEBUG_SAMUS_PAUSE:
                flagOrButton = gButtonAssignments.pause;
                if (gChangedInput & KEY_A)
                    gButtonAssignments.pause = gButtonAssignments.pause == KEY_START ? KEY_SELECT : KEY_START;

                gButtonAssignments.swapMissiles = gButtonAssignments.pause == KEY_START ? KEY_SELECT : KEY_START;
                if (flagOrButton != gButtonAssignments.pause)
                    option = 2;
                break;
            case BOOT_DEBUG_SAMUS_SWAP_MISSILES:
                flagOrButton = gButtonAssignments.swapMissiles;
                if (gChangedInput & KEY_A)
                    gButtonAssignments.swapMissiles = gButtonAssignments.swapMissiles == KEY_START ? KEY_SELECT : KEY_START;

                gButtonAssignments.pause = gButtonAssignments.swapMissiles == KEY_START ? KEY_SELECT : KEY_START;
                if (flagOrButton != gButtonAssignments.swapMissiles)
                    option = 3;
                break;
        }

        if (option != 0)
            BootDebugDrawSubMenuOptionText(BOOT_DEBUG_SUB_MENU_SAMUS, BOOT_DEBUG_DATA.subMenuOption);

        if (option == 2)
            BootDebugDrawSubMenuOptionText(BOOT_DEBUG_SUB_MENU_SAMUS, BOOT_DEBUG_DATA.subMenuOption + 1);
        else if (option == 3)
            BootDebugDrawSubMenuOptionText(BOOT_DEBUG_SUB_MENU_SAMUS, BOOT_DEBUG_DATA.subMenuOption - 1);
    }
}

void BootDebugSoundSubroutine(void)
{
    s32 updateText;
    s32 value;
    
    if (BOOT_DEBUG_DATA.menuDepth == BOOT_DEBUG_MENU_SUB)
    {
        if (gChangedInput & (KEY_RIGHT | KEY_A))
        {
            BOOT_DEBUG_DATA.menuDepth = BOOT_DEBUG_MENU_OPTION;
        }
        else if (gChangedInput & KEY_UP)
        {
            if (BOOT_DEBUG_DATA.subMenuOption > 0)
                BOOT_DEBUG_DATA.subMenuOption--;
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (BOOT_DEBUG_DATA.subMenuOption < BOOT_DEBUG_SOUND_COUNT - 1)
                BOOT_DEBUG_DATA.subMenuOption++;
        }
    }
    else
    {
        updateText = FALSE;

        switch (BOOT_DEBUG_DATA.subMenuOption)
        {
            case BOOT_DEBUG_SOUND_BGM:
                if (gChangedInput & KEY_A)
                {
                    gDisableMusic ^= TRUE;
                    value = gDisableMusic ? 0x80 : 0xFF;
                    UpdateMusicPriority(value);
                    updateText = TRUE;
                }
                break;
            case BOOT_DEBUG_SOUND_TEST:
                if (gChangedInput & KEY_RIGHT)
                {
                    if (BOOT_DEBUG_DATA.optionCursor < 2)
                        BOOT_DEBUG_DATA.optionCursor++;
                }
                else if (gChangedInput & KEY_LEFT)
                {
                    if (BOOT_DEBUG_DATA.optionCursor > 0)
                        BOOT_DEBUG_DATA.optionCursor--;
                }
                else
                {
                    value = 100;
                    if (BOOT_DEBUG_DATA.optionCursor == 1)
                        value = 10;
                    else if (BOOT_DEBUG_DATA.optionCursor == 2)
                        value = 1;

                    if (gChangedInput & KEY_UP)
                    {
                        if (BOOT_DEBUG_DATA.soundTestId >= value)
                            BOOT_DEBUG_DATA.soundTestId -= value;
                        updateText = TRUE;
                    }
                    else if (gChangedInput & KEY_DOWN)
                    {
                        BOOT_DEBUG_DATA.soundTestId += value;
                        if (BOOT_DEBUG_DATA.soundTestId > 999)
                            BOOT_DEBUG_DATA.soundTestId = 999;
                        updateText = TRUE;
                    }
                    else if (gChangedInput & (KEY_R | KEY_A))
                    {
                        PlaySound(BOOT_DEBUG_DATA.soundTestId);
                        BootDebugSetSoundTestIdColor();
                    }
                    else if (gChangedInput & KEY_L)
                    {
                        StopSound(BOOT_DEBUG_DATA.soundTestId);
                        updateText = TRUE;
                    }
                }
                break;
            case BOOT_DEBUG_SOUND_STEREO:
                if (gChangedInput & KEY_A)
                {
                    updateText = TRUE;
                    gStereoFlag ^= TRUE;
                    ApplyStereo();
                    SramWrite_SoundMode();
                }
                break;
        }
    }

    // BUG: updateText is only initialized when menuDepth == 2
    if (updateText)
    {
        BootDebugUpdateSingleText(BOOT_DEBUG_SUB_MENU_SOUND,
            BOOT_DEBUG_DATA.subMenuOption);
    }
}

void BootDebugSetSoundTestIdColor(void)
{
    u16* dst;
    s32 offset;

    dst = VRAM_BASE + 0xE040;
    offset = sBootDebugSoundMenuText[BOOT_DEBUG_SOUND_TEST].yPosition * 32 +
        sBootDebugSoundMenuText[BOOT_DEBUG_SOUND_TEST].xPosition + 6;
    dst[offset] |= 0xC000;
    dst[offset + 1] |= 0xC000;
    dst[offset + 2] |= 0xC000;
}

s32 BootDebugDemoSubroutine(void)
{
    s32 result;
    s32 updateText;

    result = 0;
    updateText = FALSE;
    
    if (BOOT_DEBUG_DATA.menuDepth == BOOT_DEBUG_MENU_SUB)
    {
        if (gChangedInput & (KEY_A | KEY_RIGHT))
        {
            BOOT_DEBUG_DATA.menuDepth = BOOT_DEBUG_MENU_OPTION;
            updateText = TRUE;
        }
        else if (gChangedInput & KEY_UP)
        {
            if (BOOT_DEBUG_DATA.subMenuOption > 0)
                BOOT_DEBUG_DATA.subMenuOption--;
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (BOOT_DEBUG_DATA.subMenuOption < BOOT_DEBUG_DEMO_COUNT - 1)
                BOOT_DEBUG_DATA.subMenuOption++;
        }
    }
    else
    {
        switch (BOOT_DEBUG_DATA.subMenuOption)
        {
            case 0:
                if (gChangedInput & KEY_A)
                {
                    gDisableCutscenes_Unused ^= TRUE;
                    updateText = TRUE;
                }
                break;
            case 1:
                if (gChangedInput & KEY_UP)
                {
                    if (gTourianEscapeCutsceneStage != 0)
                    {
                        gTourianEscapeCutsceneStage--;
                        updateText = TRUE;
                    }
                }
                else if (gChangedInput & KEY_DOWN)
                {
                    if (gTourianEscapeCutsceneStage <= 0)
                    {
                        gTourianEscapeCutsceneStage++;
                        updateText = TRUE;
                    }
                }
                else if (gChangedInput & KEY_A)
                {
                    if (gTourianEscapeCutsceneStage != 0)
                        result = 1;
                }
                break;
            case 2:
                if (gChangedInput & KEY_UP)
                {
                    if (gCurrentCutscene != 0)
                    {
                        gCurrentCutscene--;
                        updateText = TRUE;
                    }
                }
                else if (gChangedInput & KEY_DOWN)
                {
                    if (gCurrentCutscene <= 0xD)
                    {
                        gCurrentCutscene++;
                        updateText = TRUE;
                    }
                }
                else if (gChangedInput & KEY_A)
                {
                    if (gCurrentCutscene != 0)
                        result = 2;
                }
                break;
            case 3:
                if (gChangedInput & KEY_UP)
                {
                    if (gDemoState != 0)
                    {
                        gDemoState--;
                        updateText = TRUE;
                    }
                }
                else if (gChangedInput & KEY_DOWN)
                {
                    if (gDemoState <= 2)
                    {
                        gDemoState++;
                        updateText = TRUE;
                    }
                }
                else if (gChangedInput & KEY_A)
                {
                    result = 3;
                }
                break;
            case 4:
                if (gChangedInput & KEY_UP)
                {
                    if (gCurrentDemo.number != 0)
                    {
                        gCurrentDemo.number--;
                        updateText = TRUE;
                    }
                }
                else if (gChangedInput & KEY_DOWN)
                {
                    if (gCurrentDemo.number <= 0xE)
                    {
                        gCurrentDemo.number++;
                        updateText = TRUE;
                    }
                }
                else if (gChangedInput & KEY_A)
                {
                    result = 3;
                }
                break;
        }
    }

    if (updateText)
        BootDebugDrawSubMenuOptionText(BOOT_DEBUG_SUB_MENU_DEMO, BOOT_DEBUG_DATA.subMenuOption);

    return result;
}

s32 BootDebugEtcSubroutine(void)
{
    s32 result;
    u8 updateText;
    
    result = 0;
    updateText = FALSE;

    if (BOOT_DEBUG_DATA.menuDepth == BOOT_DEBUG_MENU_SUB)
    {
        if (gChangedInput & (KEY_RIGHT | KEY_A))
        {
            BOOT_DEBUG_DATA.menuDepth = BOOT_DEBUG_MENU_OPTION;
        }
        else if (gChangedInput & KEY_UP)
        {
            if (BOOT_DEBUG_DATA.subMenuOption > 0)
                BOOT_DEBUG_DATA.subMenuOption--;
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (BOOT_DEBUG_DATA.subMenuOption < BOOT_DEBUG_ETC_COUNT - 1)
                BOOT_DEBUG_DATA.subMenuOption++;
        }
    }
    else
    {
        switch (BOOT_DEBUG_DATA.subMenuOption)
        {
            case BOOT_DEBUG_ETC_MAIN_END_OBJ:
                if (gChangedInput & KEY_A)
                {
                    gDebugFlag ^= 3;
                    updateText = TRUE;
                }
                break;
            case BOOT_DEBUG_ETC_DOOR_TRANSITION:
                if (gChangedInput & KEY_A)
                {
                    if (gSkipDoorTransition)
                        gSkipDoorTransition = FALSE;
                    else
                        gSkipDoorTransition = TRUE;
                    updateText = TRUE;
                }
                break;
            case BOOT_DEBUG_ETC_ENDING:
                if (gChangedInput & KEY_A)
                    result = 1;
                break;
            case BOOT_DEBUG_ETC_STAFF_ROLL:
                if (gChangedInput & KEY_A)
                    result = 2;
                break;
        }
    }

    if (updateText)
    {
        BootDebugDrawSubMenuOptionText(BOOT_DEBUG_SUB_MENU_ETC,
            BOOT_DEBUG_DATA.subMenuOption);
    }
    
    return result;
}

void BootDebugDrawMenuNames(void)
{
    s32 i;

    for (i = 0; i < 10; i++)
    {
        BootDebugDrawText(sBootDebugMenuNamesText[i].background,
            sBootDebugMenuNamesText[i].xPosition,
            sBootDebugMenuNamesText[i].yPosition,
            sBootDebugMenuNamesText[i].palette,
            sBootDebugMenuNamesText[i].size,
            sBootDebugMenuNamesText[i].text);
    }

    if (gPauseScreenFlag == 0)
    {
        // BUG?: sBootDebugMenuNamesText only has 10 entries
        BootDebugDrawText(sBootDebugMenuNamesText[10].background,
            sBootDebugMenuNamesText[10].xPosition,
            sBootDebugMenuNamesText[10].yPosition,
            sBootDebugMenuNamesText[10].palette,
            sBootDebugMenuNamesText[10].size,
            sBootDebugMenuNamesText[10].text);
    }

    BootDebugDrawSubMenuText();

    if (BOOT_DEBUG_DATA.menuCursor == BOOT_DEBUG_SUB_MENU_SECTION &&
        BOOT_DEBUG_DATA.subMenuOption != 0)
    {
        BootDebugSectionMapDrawRoomAndDoorIds(1);
    }
}

void BootDebugDrawSubMenuText(void)
{
    u16* dst;
    s32 i;

    // Clear all text
    dst = VRAM_BASE + 0xE000;
    for (i = 0; i < 0x280; i++)
        *dst++ = 0x8040;

    switch (BOOT_DEBUG_DATA.menuCursor)
    {
        case BOOT_DEBUG_SUB_MENU_SECTION:
            for (i = 0; i < ARRAY_SIZE(sBootDebugSectionMenuText); i++)
            {
                BootDebugDrawText(sBootDebugSectionMenuText[i].background, sBootDebugSectionMenuText[i].xPosition,
                    sBootDebugSectionMenuText[i].yPosition, sBootDebugSectionMenuText[i].palette,
                    sBootDebugSectionMenuText[i].size, sBootDebugSectionMenuText[i].text);
            }
            BootDebugSectionDrawStar(0x80);
            BootDebugSectionSetFilesColor();
            break;
        case BOOT_DEBUG_SUB_MENU_MODE:
            // BUG: 2 extra entries are drawn
            for (i = 0; i < ARRAY_SIZE(sBootDebugModeMenuText) + 2; i++)
            {
                BootDebugDrawText(sBootDebugModeMenuText[i].background, sBootDebugModeMenuText[i].xPosition,
                    sBootDebugModeMenuText[i].yPosition, sBootDebugModeMenuText[i].palette,
                    sBootDebugModeMenuText[i].size, sBootDebugModeMenuText[i].text);
            }
            for (i = 0; i < BOOT_DEBUG_MODE_COUNT + 1; i++)
                BootDebugDrawSubMenuOptionText(BOOT_DEBUG_DATA.menuCursor, i);
            break;
        case BOOT_DEBUG_SUB_MENU_SAVE:
            for (i = 0; i < ARRAY_SIZE(sBootDebugSaveMenuText); i++)
            {
                BootDebugDrawText(sBootDebugSaveMenuText[i].background, sBootDebugSaveMenuText[i].xPosition,
                    sBootDebugSaveMenuText[i].yPosition, sBootDebugSaveMenuText[i].palette,
                    sBootDebugSaveMenuText[i].size, sBootDebugSaveMenuText[i].text);
            }
            for (i = 0; i < BOOT_DEBUG_SAVE_COUNT + 1; i++)
                BootDebugSaveUpdateText(i, &gFileScreenOptionsUnlocked);
            break;
        case BOOT_DEBUG_SUB_MENU_SAMUS:
            for (i = 0; i < ARRAY_SIZE(sBootDebugSamusMenuText); i++)
            {
                BootDebugDrawText(sBootDebugSamusMenuText[i].background, sBootDebugSamusMenuText[i].xPosition,
                    sBootDebugSamusMenuText[i].yPosition, sBootDebugSamusMenuText[i].palette,
                    sBootDebugSamusMenuText[i].size, sBootDebugSamusMenuText[i].text);
            }
            for (i = 0; i < BOOT_DEBUG_SAMUS_COUNT; i++)
                BootDebugDrawSubMenuOptionText(BOOT_DEBUG_DATA.menuCursor, i);
            break;
        case BOOT_DEBUG_SUB_MENU_SOUND:
            for (i = 0; i < ARRAY_SIZE(sBootDebugSoundMenuText); i++)
            {
                BootDebugDrawText(sBootDebugSoundMenuText[i].background, sBootDebugSoundMenuText[i].xPosition,
                    sBootDebugSoundMenuText[i].yPosition, sBootDebugSoundMenuText[i].palette,
                    sBootDebugSoundMenuText[i].size, sBootDebugSoundMenuText[i].text);
            }
            for (i = 0; i < BOOT_DEBUG_SOUND_COUNT; i++)
                BootDebugDrawSubMenuOptionText(BOOT_DEBUG_DATA.menuCursor, i);
            break;
        case BOOT_DEBUG_SUB_MENU_DEMO:
            for (i = 0; i < ARRAY_SIZE(sBootDebugDemoMenuText); i++)
            {
                BootDebugDrawText(sBootDebugDemoMenuText[i].background, sBootDebugDemoMenuText[i].xPosition,
                    sBootDebugDemoMenuText[i].yPosition, sBootDebugDemoMenuText[i].palette,
                    sBootDebugDemoMenuText[i].size, sBootDebugDemoMenuText[i].text);
            }
            for (i = 0; i < BOOT_DEBUG_DEMO_COUNT; i++)
                BootDebugDrawSubMenuOptionText(BOOT_DEBUG_DATA.menuCursor, i);
            break;
        case BOOT_DEBUG_SUB_MENU_ETC:
            for (i = 0; i < ARRAY_SIZE(sBootDebugEtcMenuText); i++)
            {
                BootDebugDrawText(sBootDebugEtcMenuText[i].background, sBootDebugEtcMenuText[i].xPosition,
                    sBootDebugEtcMenuText[i].yPosition, sBootDebugEtcMenuText[i].palette,
                    sBootDebugEtcMenuText[i].size, sBootDebugEtcMenuText[i].text);
            }
            for (i = 0; i < BOOT_DEBUG_ETC_COUNT; i++)
                BootDebugDrawSubMenuOptionText(BOOT_DEBUG_DATA.menuCursor, i);
            break;
        case BOOT_DEBUG_SUB_MENU_ERASE:
            for (i = 0; i < ARRAY_SIZE(sBootDebugEraseMenuText); i++)
            {
                BootDebugDrawText(sBootDebugEraseMenuText[i].background, sBootDebugEraseMenuText[i].xPosition,
                    sBootDebugEraseMenuText[i].yPosition, sBootDebugEraseMenuText[i].palette,
                    sBootDebugEraseMenuText[i].size, sBootDebugEraseMenuText[i].text);
            }
            break;
    }
}

void BootDebugDrawText(u8 background, u8 xPosition, u8 yPosition,
    u8 palette, u8 size, u8 *text)
{
    u16* dst;
    u32 tile;
    s32 i;
    s32 j;

    if (background == 0)
        dst = VRAM_BASE + 0xB000;
    else if (background == 1)
        dst = VRAM_BASE + 0xD000;
    else if (background == 2)
        dst = VRAM_BASE + 0xE000;
    else if (background == 3)
        dst = VRAM_BASE + 0xF000;
    else
        return;
    
    dst += xPosition + (yPosition * 0x20);

    for (i = 0, j = 0; i < size; i++, j++)
    {
        tile = *text;
        tile = ((tile & 0xE0) << 1) | (tile & 0x1F) | (palette << 0xC);
        dst[j] = tile;
        dst[j + 32] = tile + 0x20;
        text++;
    }
}

void BootDebugSectionDrawStar(u8 prevIndex)
{
    s32 i;
    u8 index;
    u16* dst;
    s32 offset;
        
    for (i = 0; i < 2; i++)
    {
        if (i == 0)
            index = prevIndex;
        else
            index = gSectionInfo.starIndex;

        if (index != 0x80)
        {
            dst = VRAM_BASE + 0xE000;
            offset = sBootDebugSectionMenuText[index].yPosition * 0x20 +
                sBootDebugSectionMenuText[index].xPosition - 1;
            
            if (i != 0)
            {
                // Draw star
                dst[offset] = 0xC04A;
                dst[offset + 0x20] = 0xC06A;
            }
            else
            {
                // Remove previous star
                dst[offset] = 0x8040;
                dst[offset + 0x20] = 0x8040;
            }
        }
    }
}

void BootDebugSectionSetFilesColor(void)
{
    u16* dst;
    s32 offset;
    s32 color;
    s32 i;

    dst = VRAM_BASE + 0xE000;
    
    // File A
    offset = sBootDebugSectionMenuText[BOOT_DEBUG_SECTION_SAVE_A].xPosition +
        sBootDebugSectionMenuText[BOOT_DEBUG_SECTION_SAVE_A].yPosition * 0x20;
    color = gSaveFilesInfo[0].exists ? 8 : 0xF;
    for (i = 0; i < sBootDebugSectionMenuText[BOOT_DEBUG_SECTION_SAVE_A].size; i++, offset++)
    {
        dst[offset] = (dst[offset] & 0xFFF) | (color << 12);
        dst[offset + 0x20] = (dst[offset + 0x20] & 0xFFF) | (color << 12);
    }

    // File B
    offset = sBootDebugSectionMenuText[BOOT_DEBUG_SECTION_SAVE_B].xPosition +
        sBootDebugSectionMenuText[BOOT_DEBUG_SECTION_SAVE_B].yPosition * 0x20;
    color = gSaveFilesInfo[1].exists ? 8 : 0xF;
    for (i = 0; i < sBootDebugSectionMenuText[BOOT_DEBUG_SECTION_SAVE_B].size; i++, offset++)
    {
        dst[offset] = (dst[offset] & 0xFFF) | (color << 12);
        dst[offset + 0x20] = (dst[offset + 0x20] & 0xFFF) | (color << 12);
    }

    // File C
    offset = sBootDebugSectionMenuText[BOOT_DEBUG_SECTION_SAVE_C].xPosition +
        sBootDebugSectionMenuText[BOOT_DEBUG_SECTION_SAVE_C].yPosition * 0x20;
    color = gSaveFilesInfo[2].exists ? 8 : 0xF;
    for (i = 0; i < sBootDebugSectionMenuText[BOOT_DEBUG_SECTION_SAVE_C].size; i++, offset++)
    {
        dst[offset] = (dst[offset] & 0xFFF) | (color << 12);
        dst[offset + 0x20] = (dst[offset + 0x20] & 0xFFF) | (color << 12);
    }

    // Current area
    offset = sBootDebugSectionMenuText[gCurrentArea].yPosition * 0x20 +
        sBootDebugSectionMenuText[gCurrentArea].xPosition;
    for (i = 0; i < sBootDebugSectionMenuText[gCurrentArea].size; i++, offset++)
    {
        dst[offset] = (dst[offset] & 0xFFF) | (0xC << 12);
        dst[offset + 0x20] = (dst[offset + 0x20] & 0xFFF) | (0xC << 12);
    }
}

void BootDebugDrawSubMenuOptionText(u8 subMenu, u8 subMenuOption)
{
    u16* dst;
    s32 offset;
    s32 flag;
    s32 i;
    s32 tile;
    s32 index;

    switch (subMenu)
    {
        case BOOT_DEBUG_SUB_MENU_MODE:
            if (subMenuOption == BOOT_DEBUG_MODE_LANGUAGE)
            {
                BootDebugDrawText(sBootDebugLanguageText[gLanguage].background,
                    sBootDebugLanguageText[gLanguage].xPosition,
                    sBootDebugLanguageText[gLanguage].yPosition,
                    sBootDebugLanguageText[gLanguage].palette,
                    sBootDebugLanguageText[gLanguage].size,
                    sBootDebugLanguageText[gLanguage].text);
            }
            else if (subMenuOption == BOOT_DEBUG_MODE_DIFFICULTY)
            {
                BootDebugDrawText(sBootDebugDifficultyText[gDifficulty].background,
                    sBootDebugDifficultyText[gDifficulty].xPosition,
                    sBootDebugDifficultyText[gDifficulty].yPosition,
                    sBootDebugDifficultyText[gDifficulty].palette,
                    sBootDebugDifficultyText[gDifficulty].size,
                    sBootDebugDifficultyText[gDifficulty].text);
            }
            break;
        case BOOT_DEBUG_SUB_MENU_SAMUS:
            dst = VRAM_BASE + 0xE000;
            offset = (sBootDebugSamusMenuText[subMenuOption].yPosition * 0x20) +
                sBootDebugSamusMenuText[subMenuOption].xPosition;
            if (subMenuOption == BOOT_DEBUG_SAMUS_GET_MAP)
            {
                offset = (sBootDebugSamusMenuText[0].yPosition * 0x20) +
                    sBootDebugSamusMenuText[0].xPosition + sBootDebugSamusMenuText[0].size + 8;
                flag = 1;
                for (i = 0; i < 7; i++)
                {
                    if (gEquipment.downloadedMapStatus & flag)
                        index = 0xC0CF;
                    else
                        index = 0xC04D;
                    dst[offset] = index;
                    dst[offset + 0x20] = index + 0x20;
                    flag <<= 1;
                    offset--;
                }
            }
            else if (subMenuOption == BOOT_DEBUG_SAMUS_ARM_WEAPON)
            {
                index = gButtonAssignments.armWeapon ^ KEY_L ? 1 : 0;
                BootDebugDrawText(sBootDebugArmWeaponButtonText[index].background,
                    sBootDebugArmWeaponButtonText[index].xPosition,
                    sBootDebugArmWeaponButtonText[index].yPosition,
                    sBootDebugArmWeaponButtonText[index].palette,
                    sBootDebugArmWeaponButtonText[index].size,
                    sBootDebugArmWeaponButtonText[index].text);
            }
            else if (subMenuOption == BOOT_DEBUG_SAMUS_DIAGONAL_AIM)
            {
                index = gButtonAssignments.diagonalAim ^ KEY_L ? 1 : 0;
                BootDebugDrawText(sBootDebugDiagonalAimButtonText[index].background,
                    sBootDebugDiagonalAimButtonText[index].xPosition,
                    sBootDebugDiagonalAimButtonText[index].yPosition,
                    sBootDebugDiagonalAimButtonText[index].palette,
                    sBootDebugDiagonalAimButtonText[index].size,
                    sBootDebugDiagonalAimButtonText[index].text);
            }
            else if (subMenuOption == BOOT_DEBUG_SAMUS_PAUSE)
            {
                index = gButtonAssignments.pause ^ KEY_START ? 1 : 0;
                BootDebugDrawText(sBootDebugPauseButtonText[index].background,
                    sBootDebugPauseButtonText[index].xPosition,
                    sBootDebugPauseButtonText[index].yPosition,
                    sBootDebugPauseButtonText[index].palette,
                    sBootDebugPauseButtonText[index].size,
                    sBootDebugPauseButtonText[index].text);
            }
            else if (subMenuOption == BOOT_DEBUG_SAMUS_SWAP_MISSILES)
            {
                index = gButtonAssignments.swapMissiles ^ KEY_START ? 1 : 0;
                BootDebugDrawText(sBootDebugSwapMissilesButtonText[index].background,
                    sBootDebugSwapMissilesButtonText[index].xPosition,
                    sBootDebugSwapMissilesButtonText[index].yPosition,
                    sBootDebugSwapMissilesButtonText[index].palette,
                    sBootDebugSwapMissilesButtonText[index].size,
                    sBootDebugSwapMissilesButtonText[index].text);
            }
            break;
        case BOOT_DEBUG_SUB_MENU_SOUND:
            dst = VRAM_BASE + 0xE000;
            offset = (sBootDebugSoundMenuText[subMenuOption].yPosition * 0x20) +
                sBootDebugSoundMenuText[subMenuOption].xPosition + 6;
            if (subMenuOption == BOOT_DEBUG_SOUND_BGM)
            {
                BootDebugDrawText(sBootDebugBgmOnOffText[gDisableMusic].background,
                    sBootDebugBgmOnOffText[gDisableMusic].xPosition,
                    sBootDebugBgmOnOffText[gDisableMusic].yPosition,
                    sBootDebugBgmOnOffText[gDisableMusic].palette,
                    sBootDebugBgmOnOffText[gDisableMusic].size,
                    sBootDebugBgmOnOffText[gDisableMusic].text);
            }
            else if (subMenuOption == BOOT_DEBUG_SOUND_TEST)
            {
                tile = (BOOT_DEBUG_DATA.soundTestId / 100) % 10;
                dst[offset + 0x20] = 0x8000 | tile;
                tile = (BOOT_DEBUG_DATA.soundTestId / 10) % 10;
                dst[offset + 0x21] = 0x8000 | tile;
                tile = BOOT_DEBUG_DATA.soundTestId % 10;
                dst[offset + 0x22] = 0x8000 | tile;
            }
            else if (subMenuOption == BOOT_DEBUG_SOUND_STEREO)
            {
                offset -= 6;
                // Set mono text color
                tile = gStereoFlag ? 0xF000 : 0x8000;
                i = 0;
                while (i < 4)
                {
                    dst[offset] = (dst[offset] & 0x3FF) | tile;
                    dst[offset + 0x20] = (dst[offset + 0x20] & 0x3FF) | tile;
                    i++;
                    offset++;
                }
                // Set stereo text color
                tile = !gStereoFlag ? 0xF000 : 0x8000;
                while (i < 9)
                {
                    dst[offset] = (dst[offset] & 0x3FF) | tile;
                    dst[offset + 0x20] = (dst[offset + 0x20] & 0x3FF) | tile;
                    i++;
                    offset++;
                }
            }
            break;
        case BOOT_DEBUG_SUB_MENU_DEMO:
            dst = VRAM_BASE + 0xE000;
            offset = (sBootDebugDemoMenuText[subMenuOption].yPosition * 0x20) +
                sBootDebugDemoMenuText[subMenuOption].xPosition;
            switch (subMenuOption)
            {
                case BOOT_DEBUG_DEMO_CUTSCENE_SWITCH:
                    BootDebugDrawText(sBootDebugDemoOnOffText[gDisableCutscenes_Unused].background,
                        sBootDebugDemoOnOffText[gDisableCutscenes_Unused].xPosition,
                        sBootDebugDemoOnOffText[gDisableCutscenes_Unused].yPosition,
                        sBootDebugDemoOnOffText[gDisableCutscenes_Unused].palette,
                        sBootDebugDemoOnOffText[gDisableCutscenes_Unused].size,
                        sBootDebugDemoOnOffText[gDisableCutscenes_Unused].text);
                    break;
                case BOOT_DEBUG_DEMO_CUTSCENE_A:
                    dst += offset + 8;
                    BootDebugDrawLine(dst, sBootDebugCutsceneATextPointers[0], 0xC);
                    BootDebugDrawLine(dst, sBootDebugCutsceneATextPointers[gTourianEscapeCutsceneStage], 0xC);
                    break;
                case BOOT_DEBUG_DEMO_CUTSCENE_B:
                    dst += offset + 8;
                    BootDebugDrawLine(dst, sBootDebugCutsceneBTextPointers[0], 0xC);
                    BootDebugDrawLine(dst, sBootDebugCutsceneBTextPointers[gCurrentCutscene], 0xC);
                    break;
                case BOOT_DEBUG_DEMO_DEMO_MODE:
                    dst += offset + 0xC;
                    BootDebugDrawLine(dst, sBootDebugDemoStateTextPointers[0], 0xC);
                    BootDebugDrawLine(dst, sBootDebugDemoStateTextPointers[gDemoState + 1], 0xC);
                    break;
                case BOOT_DEBUG_DEMO_DEMO_NUM:
                    dst += offset + 0x2C;
                    BootDebugDrawNumber(dst, gCurrentDemo.number + 1, 2, 0xC);
                    break;
            }
            break;
        case BOOT_DEBUG_SUB_MENU_ETC:
            if (subMenuOption == BOOT_DEBUG_ETC_MAIN_END_OBJ)
            {
                index = gDebugFlag - 1;
                BootDebugDrawText(sBootDebugMainEndObjOnOffText[index].background,
                    sBootDebugMainEndObjOnOffText[index].xPosition,
                    sBootDebugMainEndObjOnOffText[index].yPosition,
                    sBootDebugMainEndObjOnOffText[index].palette,
                    sBootDebugMainEndObjOnOffText[index].size,
                    sBootDebugMainEndObjOnOffText[index].text);
            }
            else if (subMenuOption == BOOT_DEBUG_ETC_DOOR_TRANSITION)
            {
                index = gSkipDoorTransition ? 1 : 0;
                BootDebugDrawText(sBootDebugDoorTransitionOnOffText[index].background,
                    sBootDebugDoorTransitionOnOffText[index].xPosition,
                    sBootDebugDoorTransitionOnOffText[index].yPosition,
                    sBootDebugDoorTransitionOnOffText[index].palette,
                    sBootDebugDoorTransitionOnOffText[index].size,
                    sBootDebugDoorTransitionOnOffText[index].text);
            }
            break;        
    }
}

void BootDebugDrawNumber(u16 *dst, u8 number, u8 numDigits, u8 color)
{
    s32 value;
    s32 divisor;
    u8 prevWasNonZero;

    value = numDigits - 1;
    divisor = 1;
    while (value != 0)
    {
        divisor *= 10;
        value--;
    }

    prevWasNonZero = FALSE;
    while (divisor > 0)
    {
        value = (number / divisor) % 10;
        if (value == 0)
        {
            if (prevWasNonZero || (divisor == 1))
                value = color << 0xC;
            else
                value = 0x8040; // Blank
        }
        else
        {
            value |= color << 0xC;
            prevWasNonZero = TRUE;
        }
        *dst = value;
        divisor /= 10;
        dst++;
    }
}

void BootDebugDrawLine(u16 *dst, u8 *text, u8 color)
{
    u32 tile;
    
    while (*text != '\0')
    {
        if (*text == ' ')
            tile = 0x40;
        else
            tile = ((*text & 0xE0) << 1) | (*text & 0x1F);

        dst[0] = color << 0xC | tile;
        dst[32] = color << 0xC | (tile + 0x20);

        dst++;
        text++;
    }
}
