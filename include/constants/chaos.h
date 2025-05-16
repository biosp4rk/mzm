#ifndef CHAOS_CONSTANTS_H
#define CHAOS_CONSTANTS_H

#define CHAOS_SECONDS_BETWEEN_EFFECTS 4
#define CHAOS_EFFECT_FRAMES_MIN (5 * FRAMES_PER_SECOND)
#define CHAOS_EFFECT_FRAMES_MAX (20 * FRAMES_PER_SECOND)

// The minimum distance something should spawn from Samus
#define CHAOS_NEAR_SAMUS_MIN (1 * BLOCK_SIZE)
// The maximum X distance something should spawn from Samus
#define CHAOS_NEAR_SAMUS_MAX_X (6 * BLOCK_SIZE)
// The maximum Y distance something should spawn from Samus
#define CHAOS_NEAR_SAMUS_MAX_Y (4 * BLOCK_SIZE)

enum ChaosEffect {
    // # Duration effects

    // ## Movement related

    // Inverts left/right buttons
    CHAOS_EFFECT_INVERTED_CONTROLS,
    // Sets the water movement flag
    CHAOS_EFFECT_WATER_PHYSICS,
    // Cuts horizontal movement speed in half
    CHAOS_EFFECT_SLOW_HORI_MOVEMENT,
    // Doubles horizontal movement speed
    CHAOS_EFFECT_FAST_HORI_MOVEMENT,
    // Lowers Y movement deceleration
    CHAOS_EFFECT_LOW_GRAVITY,
    // Raises Y movement deceleration
    CHAOS_EFFECT_HIGH_GRAVITY,
    // Draws long Samus echoes at all times
    CHAOS_EFFECT_LONG_ECHO,
    // Runs enemy code every other frame
    CHAOS_EFFECT_SLOW_ENEMIES,

    // ## Samus related

    // Deactivates a random ability
    CHAOS_EFFECT_DEACTIVATE_ABILITY,
    // Activates a random new ability
    CHAOS_EFFECT_GIVE_ABILITY,
    // Makes Samus suitless
    CHAOS_EFFECT_SUITLESS,

    // ## Weapon related

    // Makes beams and missiles move slowly
    CHAOS_EFFECT_SLOW_WEAPONS,
    // Alternates arming and unarming weapon
    CHAOS_EFFECT_ARM_WEAPON,
    // Swaps missile types back and forth
    CHAOS_EFFECT_SWAP_MISSILES,
    // Beam shots are always charged
    CHAOS_EFFECT_CHARGED_SHOTS,
    // Shooting a beam spawns a bomb
    CHAOS_EFFECT_SHOOT_BOMBS,

    // ## Misc

    // Draws HUD elements in random positions
    CHAOS_EFFECT_MOVE_HUD,
    // Makes scrolling slow
    CHAOS_EFFECT_SLOW_SCROLLING,
    // Spawns explosion particles around Samus
    CHAOS_EFFECT_EXPLOSIONS,

    // # One time effects

    CHAOS_EFFECT_ONE_TIME,

    // Spawns an enemy in the spriteset near Samus
    CHAOS_EFFECT_SPAWN_ENEMY = CHAOS_EFFECT_ONE_TIME,
    // Displays a message box with a random text entry
    CHAOS_EFFECT_MESSAGE_BOX,
    // Spawns a power bomb near Samus
    CHAOS_EFFECT_SPAWN_PB,
    // Makes a block near Samus a shot block
    CHAOS_EFFECT_SHOT_BLOCK,
    // Makes all solid blocks wet ground
    CHAOS_EFFECT_WET_GROUND,
    // Makes most ground blocks slow crumble blocks
    CHAOS_EFFECT_CRUMBLE_CITY,
    // Freezes all freezable enemies in the room
    CHAOS_EFFECT_FREEZE_ENEMIES,
    // Sets the screen shake timer
    CHAOS_EFFECT_SCREEN_SHAKE,
    // Put Samus in knockback pose
    CHAOS_EFFECT_KNOCKBACK_SAMUS,
    // Set the shinespark timer
    CHAOS_EFFECT_SHINE_TIMER,
    // Sets energy or ammo to a random amount
    CHAOS_EFFECT_CHANGE_ENERGY_AMMO,
    // Pauses the game
    CHAOS_EFFECT_PAUSE_GAME,
    // Plays a random sound, like lightning or Ridley
    CHAOS_EFFECT_RAND_SOUND,
    // Changes the background colors (brightness, monochrome)
    CHAOS_EFFECT_COLOR_EFFECT,
    // Plays a random cutscene
    CHAOS_EFFECT_CUTSCENE,

    // Marks the end of all effects
    CHAOS_EFFECT_END
};

// Bit flags for duration effects
#define CHAOS_FLAG_INVERTED_CONTROLS (1 << CHAOS_EFFECT_INVERTED_CONTROLS)
#define CHAOS_FLAG_WATER_PHYSICS (1 << CHAOS_EFFECT_WATER_PHYSICS)
#define CHAOS_FLAG_SLOW_HORI_MOVEMENT (1 << CHAOS_EFFECT_SLOW_HORI_MOVEMENT)
#define CHAOS_FLAG_FAST_HORI_MOVEMENT (1 << CHAOS_EFFECT_FAST_HORI_MOVEMENT)
#define CHAOS_FLAG_LOW_GRAVITY (1 << CHAOS_EFFECT_LOW_GRAVITY)
#define CHAOS_FLAG_HIGH_GRAVITY (1 << CHAOS_EFFECT_HIGH_GRAVITY)
#define CHAOS_FLAG_LONG_ECHO (1 << CHAOS_EFFECT_LONG_ECHO)
#define CHAOS_FLAG_SLOW_ENEMIES (1 << CHAOS_EFFECT_SLOW_ENEMIES)
#define CHAOS_FLAG_DEACTIVATE_ABILITY (1 << CHAOS_EFFECT_DEACTIVATE_ABILITY)
#define CHAOS_FLAG_GIVE_ABILITY (1 << CHAOS_EFFECT_GIVE_ABILITY)
#define CHAOS_FLAG_SUITLESS (1 << CHAOS_EFFECT_SUITLESS)
#define CHAOS_FLAG_SLOW_WEAPONS (1 << CHAOS_EFFECT_SLOW_WEAPONS)
#define CHAOS_FLAG_ARM_WEAPON (1 << CHAOS_EFFECT_ARM_WEAPON)
#define CHAOS_FLAG_SWAP_MISSILES (1 << CHAOS_EFFECT_SWAP_MISSILES)
#define CHAOS_FLAG_CHARGED_SHOTS (1 << CHAOS_EFFECT_CHARGED_SHOTS)
#define CHAOS_FLAG_SHOOT_BOMBS (1 << CHAOS_EFFECT_SHOOT_BOMBS)
#define CHAOS_FLAG_MOVE_HUD (1 << CHAOS_EFFECT_MOVE_HUD)
#define CHAOS_FLAG_SLOW_SCROLLING (1 << CHAOS_EFFECT_SLOW_SCROLLING)
#define CHAOS_FLAG_EXPLOSIONS (1 << CHAOS_EFFECT_EXPLOSIONS)

#endif // CHAOS_CONSTANTS_H
