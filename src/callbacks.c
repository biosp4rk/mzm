#include "callbacks.h"

#include "gba.h"
#include "globals.h"
#include "io.h"
#include "audio/track_internal.h"
#include "structs/game_state.h"

/**
 * @brief a98 | 4c | Calls the v-blank callback
 * 
 */
void CallbackCallVblank(void)
{
    if (gVBlankCallback)
        gVBlankCallback();

    WRITE_16(REG_IF, READ_16(REG_IF) | IF_VBLANK);
    gVBlankRequestFlag = TRUE;
    gInterruptCheckFlag |= 1;

    if (!gVblankActive)
        UpdateAudio();
}

/**
 * @brief ae4 | 1c | Sets the v-blank callback
 * 
 * @param callback Callback pointer
 */
void CallbackSetVblank(Func_T callback)
{
    gVBlankCallback = callback;

    if (callback == NULL)
    {
        // Prevent null pointer
        gVBlankCallback = Callback_Empty;
    }
}

/**
 * @brief b00 | 24 | Calls the h-blank callback
 * 
 */
void CallbackCallHblank(void)
{
    if (gHBlankCallback)
        gHBlankCallback();

    WRITE_16(REG_IF, READ_16(REG_IF) | IF_HBLANK);
}

/**
 * @brief b24 | 1c | Sets the h-blank callback
 * 
 * @param callback Callback pointer
 */
void CallbackSetHblank(Func_T callback)
{
    gHBlankCallback = callback;

    if (callback == NULL)
    {
        // Prevent null pointer
        gHBlankCallback = Callback_Empty;
    }
}

/**
 * @brief b40 | 24 | Calls the v-count callback
 * 
 */
void CallbackCallVcount(void)
{
    if (gVCountCallback)
        gVCountCallback();

    WRITE_16(REG_IF, READ_16(REG_IF) | IF_VCOUNT);
}

/**
 * @brief b64 | 1c | Sets the v-count callback
 * 
 * @param callback Callback pointer
 */
void CallbackSetVcount(Func_T callback)
{
    gVCountCallback = callback;

    if (callback == NULL)
    {
        // Prevent null pointer
        gVCountCallback = Callback_Empty;
    }
}

/**
 * @brief b80 | 24 | Calls the serial communication callback
 * 
 */
void CallbackCallSerialCommunication(void)
{
    if (gSerialCommunicationCallback)
        gSerialCommunicationCallback();

    WRITE_16(REG_IF, READ_16(REG_IF) | IF_SERIAL);
}

/**
 * @brief ba4 | 1c | Sets the serial communication callback
 * 
 * @param callback Callback pointer
 */
void CallbackSetSerialCommunication(Func_T callback)
{
    gSerialCommunicationCallback = callback;

    if (callback == NULL)
    {
        // Prevent null pointer
        gSerialCommunicationCallback = Callback_Empty;
    }
}

/**
 * @brief bc0 | 24 | Calls the timer 3 callback
 * 
 */
void CallbackCallTimer3(void)
{
    if (gTimer3Callback)
        gTimer3Callback();

    WRITE_16(REG_IF, READ_16(REG_IF) | IF_TIMER3);
}

/**
 * @brief be4 | 1c | Sets the timer 3 callback
 * 
 * @param callback Callback pointer
 */
void CallbackSetTimer3(Func_T callback)
{
    gTimer3Callback = callback;

    if (callback == NULL)
    {
        // Prevent null pointer
        gTimer3Callback = Callback_Empty;
    }
}

/**
 * @brief c00 | 4 | Empty callback
 * 
 */
void Callback_Empty(void)
{
    return;
}
