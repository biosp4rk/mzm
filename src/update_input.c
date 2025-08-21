#include "update_input.h"
#include "gba.h"
#include "types.h"
#include "chaos.h"

#include "structs/game_state.h"

#include "constants/chaos.h"
#include "constants/game_state.h"

/**
 * @brief 968 | 38 | Updates the input
 * 
 */
void UpdateInput(void)
{
    u16 keys;
    u16 origKeys;

    keys = KEY_MASK & ~READ_16(REG_KEY_INPUT);

#ifdef CHAOS
    if (gMainGameMode == GM_INGAME && ChaosIsEffectActive(CHAOS_FLAG_INVERTED_CONTROLS))
    {
        origKeys = keys;
        if (origKeys & KEY_RIGHT)
            keys = (keys & ~KEY_RIGHT) | KEY_LEFT;
        if (origKeys & KEY_LEFT)
            keys = (keys & ~KEY_LEFT) | KEY_RIGHT;
    }
#endif // CHAOS

    gChangedInput = keys & ~gPreviousButtonInput;
    gButtonInput = keys;
    gPreviousButtonInput = keys;
}
