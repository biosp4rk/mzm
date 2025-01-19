#ifndef STATUS_SCREEN_CONSTANTS_H
#define STATUS_SCREEN_CONSTANTS_H

#define ITEM_TOGGLE_CHECKING 0
#define ITEM_TOGGLE_TOGGLING 1
#define ITEM_TOGGLE_CHECKING2 2

enum AbilityGroup {
    ABILITY_GROUP_BEAMS,
    ABILITY_GROUP_BOMBS,
    ABILITY_GROUP_SUITS,
    ABILITY_GROUP_MISC,
    ABILITY_GROUP_MISSILES,
    ABILITY_GROUP_CURRENT_ENERGY,
    ABILITY_GROUP_MAX_ENERGY,
    ABILITY_GROUP_CURRENT_MISSILES,
    ABILITY_GROUP_MAX_MISSILES,
    ABILITY_GROUP_CURRENT_SUPER_MISSILES,
    ABILITY_GROUP_MAX_SUPER_MISSILES,
    ABILITY_GROUP_CURRENT_POWER_BOMBS,
    ABILITY_GROUP_MAX_POWER_BOMBS,

    ABILITY_GROUP_END
};

enum FullyPoweredItems {
    FULLY_POWERED_ITEMS_CHECK_ENABLE_SUIT,
    FULLY_POWERED_ITEMS_DELAY,
    FULLY_POWERED_ITEMS_CHECK_NEXT_SLOT,
    FULLY_POWERED_ITEMS_ACTIVATE_NORMAL_SLOT,
    FULLY_POWERED_ITEMS_SEARCH_FOR_UNKNOWN_ITEM,
    FULLY_POWERED_ITEMS_ENABLE_UNKNOWN_ITEM_INIT,
    FULLY_POWERED_ITEMS_UNKNOWN_ITEM_ACTIVATING_ANIMATION_PART1,
    FULLY_POWERED_ITEMS_UNKNOWN_ITEM_ACTIVATING_ANIMATION_PART2,
    FULLY_POWERED_ITEMS_ENABLE_UNKNOWN_ITEM,
    FULLY_POWERED_ITEMS_UNKNOWN_ITEM_DESCRIPTION,
    FULLY_POWERED_ITEMS_FINISH,
    FULLY_POWERED_ITEMS_END,
};

#endif
