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

// Duration effects

// Movement related
#define CHAOS_EFFECT_INVERTED_CONTROLS 0    // Inverts up/down and left/right
#define CHAOS_EFFECT_WATER_PHYSICS 1        // Sets the water movement flag
#define CHAOS_EFFECT_SLOW_HORI_MOVEMENT 2   // Cuts horizontal movement speed in half
#define CHAOS_EFFECT_FAST_HORI_MOVEMENT 3   // Doubles horizontal movement speed
#define CHAOS_EFFECT_LOW_GRAVITY 4          // Lowers Y movement deceleration
#define CHAOS_EFFECT_HIGH_GRAVITY 5         // Raises Y movement deceleration
#define CHAOS_EFFECT_LONG_ECHO 6            // Draws long Samus echoes at all times
// Samus related
#define CHAOS_EFFECT_DEACTIVATE_ABILITY 7   // Deactivates a random ability
#define CHAOS_EFFECT_SUITLESS 8             // Makes Samus suitless
// Weapon related
#define CHAOS_EFFECT_SLOW_WEAPONS 9         // Makes beams and missiles move slowly
#define CHAOS_EFFECT_ARM_WEAPON 10          // Alternates arming and unarming weapon
#define CHAOS_EFFECT_SWAP_MISSILES 11       // Swaps missile types back and forth
#define CHAOS_EFFECT_CHARGED_SHOTS 12       // Beam shots are always charged
#define CHAOS_EFFECT_SHOOT_BOMBS 13         // Shooting a beam spawns a bomb
// Misc
#define CHAOS_EFFECT_FORWARD_CAMERA 14      // Sets camera type to forward
#define CHAOS_EFFECT_EXPLOSIONS 15          // Spawns explosion particles around Samus

// One time effects
#define CHAOS_EFFECT_ONE_TIME 16            // Marks the start of one time effects

#define CHAOS_EFFECT_SPAWN_ENEMY 16         // Spawns an enemy in the spriteset near Samus
#define CHAOS_EFFECT_SPAWN_PB 17            // Spawns a power bomb near Samus
#define CHAOS_EFFECT_FREEZE_ENEMIES 18      // Freezes all freezable enemies in the room
#define CHAOS_EFFECT_SCREEN_SHAKE 19        // Sets the screen shake timer
#define CHAOS_EFFECT_KNOCKBACK_SAMUS 20     // Put Samus in knockback pose
#define CHAOS_EFFECT_SHINE_TIMER 21         // Set the shinespark timer
#define CHAOS_EFFECT_CHANGE_ENERGY_AMMO 22  // Sets energy or ammo to a random amount
#define CHAOS_EFFECT_PAUSE_GAME 23          // Pauses the game
#define CHAOS_EFFECT_RAND_SOUND 24          // Plays a random sound, like lightning or Ridley
#define CHAOS_EFFECT_COLOR_EFFECT 25        // Changes the background colors (brightness, monochrome)
#define CHAOS_EFFECT_END 26                 // Marks the end of all duration effects

#define CHAOS_FLAG_INVERTED_CONTROLS (1 << CHAOS_EFFECT_INVERTED_CONTROLS)
#define CHAOS_FLAG_WATER_PHYSICS (1 << CHAOS_EFFECT_WATER_PHYSICS)
#define CHAOS_FLAG_SLOW_HORI_MOVEMENT (1 << CHAOS_EFFECT_SLOW_HORI_MOVEMENT)
#define CHAOS_FLAG_FAST_HORI_MOVEMENT (1 << CHAOS_EFFECT_FAST_HORI_MOVEMENT)
#define CHAOS_FLAG_LOW_GRAVITY (1 << CHAOS_EFFECT_LOW_GRAVITY)
#define CHAOS_FLAG_HIGH_GRAVITY (1 << CHAOS_EFFECT_HIGH_GRAVITY)
#define CHAOS_FLAG_LONG_ECHO (1 << CHAOS_EFFECT_LONG_ECHO)
#define CHAOS_FLAG_DEACTIVATE_ABILITY (1 << CHAOS_EFFECT_DEACTIVATE_ABILITY)
#define CHAOS_FLAG_SUITLESS (1 << CHAOS_EFFECT_SUITLESS)
#define CHAOS_FLAG_SLOW_WEAPONS (1 << CHAOS_EFFECT_SLOW_WEAPONS)
#define CHAOS_FLAG_ARM_WEAPON (1 << CHAOS_EFFECT_ARM_WEAPON)
#define CHAOS_FLAG_SWAP_MISSILES (1 << CHAOS_EFFECT_SWAP_MISSILES)
#define CHAOS_FLAG_CHARGED_SHOTS (1 << CHAOS_EFFECT_CHARGED_SHOTS)
#define CHAOS_FLAG_SHOOT_BOMBS (1 << CHAOS_EFFECT_SHOOT_BOMBS)
#define CHAOS_FLAG_FORWARD_CAMERA (1 << CHAOS_EFFECT_FORWARD_CAMERA)
#define CHAOS_FLAG_EXPLOSIONS (1 << CHAOS_EFFECT_EXPLOSIONS)

#endif // CHAOS_CONSTANTS_H
