#ifndef CHAOS_CONSTANTS_H
#define CHAOS_CONSTANTS_H

#define CHAOS_SECONDS_BETWEEN_EFFECTS 5

#define CHAOS_STATE_NONE 0
#define CHAOS_STATE_ACTIVE 1
#define CHAOS_STATE_STARTING 2
#define CHAOS_STATE_ENDING 3

// Duration effects

// Movement related
#define CHAOS_EFFECT_INVERTED_CONTROLS 0    // Inverts up/down and left/right
#define CHAOS_EFFECT_WATER_PHYSICS 1        // Sets the water movement flag
#define CHAOS_EFFECT_SLOW_HORI_MOVEMENT 2   // Cuts horizontal movement speed in half
#define CHAOS_EFFECT_FAST_HORI_MOVEMENT 3   // Doubles horizontal movement speed
#define CHAOS_EFFECT_LOW_GRAVITY 4          // Lowers Y movement deceleration
#define CHAOS_EFFECT_HIGH_GRAVITY 5         // Raises Y movement deceleration
// Samus related
#define CHAOS_EFFECT_DEACTIVATE_ABILITY 6   // Deactivates a random ability
#define CHAOS_EFFECT_SUITLESS 7             // Makes Samus suitless
// Weapon related
#define CHAOS_EFFECT_SLOW_WEAPONS 8         // Makes beams and missiles move slowly
#define CHAOS_EFFECT_ARM_MISSILES 9         // Alternates arming and unarming missiles
#define CHAOS_EFFECT_SWAP_MISSILES 10       // Swaps missile types back and forth
#define CHAOS_EFFECT_CHARGED_SHOTS 11       // Beam shots are always charged
#define CHAOS_EFFECT_SHOOT_BOMBS 12         // Shooting a beam spawns a bomb
// Screen related
#define CHAOS_EFFECT_CHANGE_BRIGHTNESS 13   // Raises or lowers background brightness
#define CHAOS_EFFECT_SCREEN_SHAKE 14        // Sets the screen shake timer
#define CHAOS_EFFECT_FORWARD_CAMERA 15      // Sets camera type to forward
// Misc
#define CHAOS_EFFECT_SHUFFLE_SOUNDS 16      // Sounds that play will be random

// One time effects
#define CHAOS_EFFECT_ONE_TIME 17

#define CHAOS_EFFECT_SPAWN_ENEMY 17         // Spawns an enemy in the spriteset near Samus
#define CHAOS_EFFECT_SPAWN_PB 18            // Spawns a power bomb near Samus
#define CHAOS_EFFECT_FREEZE_ENEMIES 19      // Freezes all freezable enemies in the room
#define CHAOS_EFFECT_KNOCKBACK_SAMUS 20     // Put Samus in knockback pose
#define CHAOS_EFFECT_SHINE_TIMER 21         // Set the shinespark timer
#define CHAOS_EFFECT_CHANGE_ENERGY_AMMO 22  // Sets energy or ammo to a random amount
#define CHAOS_EFFECT_PAUSE_GAME 23          // Pauses the game
#define CHAOS_EFFECT_RAND_SOUND 24          // Plays a random sound, like lightning or Ridley
#define CHAOS_EFFECT_END 25                 // Marks the end of all duration effects

#endif // CHAOS_CONSTANTS_H
