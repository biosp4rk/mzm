#ifndef PROJECTILE_CONSTANTS_H
#define PROJECTILE_CONSTANTS_H

#define PROJ_STATUS_NONE                   0
#define PROJ_STATUS_EXISTS                 (1 << 0)
#define PROJ_STATUS_ON_SCREEN              (1 << 1)
#define PROJ_STATUS_NOT_DRAWN              (1 << 2)
#define PROJ_STATUS_HIGH_PRIORITY          (1 << 3)
#define PROJ_STATUS_CAN_AFFECT_ENVIRONMENT (1 << 4)
#define PROJ_STATUS_Y_FLIP                 (1 << 5)
#define PROJ_STATUS_X_FLIP                 (1 << 6)
#define PROJ_STATUS_UNKNOWN_80             (1 << 7)

enum ProjectileCategory {
    PROJECTILE_CATEGORY_NONE,
    PROJECTILE_CATEGORY_BEAM,
    PROJECTILE_CATEGORY_MISSILE,
    PROJECTILE_CATEGORY_SUPER_MISSILE,
    PROJECTILE_CATEGORY_BOMB,
    PROJECTILE_CATEGORY_POWER_BOMB,
    PROJECTILE_CATEGORY_CHARGED_BEAM,

    PROJECTILE_CATEGORY_END,
};

enum ProjectileType {
    PROJ_TYPE_BEAM,
    PROJ_TYPE_LONG_BEAM,
    PROJ_TYPE_ICE_BEAM,
    PROJ_TYPE_WAVE_BEAM,
    PROJ_TYPE_PLASMA_BEAM,
    PROJ_TYPE_PISTOL,
    PROJ_TYPE_CHARGED_BEAM,
    PROJ_TYPE_CHARGED_LONG_BEAM,
    PROJ_TYPE_CHARGED_ICE_BEAM,
    PROJ_TYPE_CHARGED_WAVE_BEAM,
    PROJ_TYPE_CHARGED_PLASMA_BEAM,
    PROJ_TYPE_CHARGED_PISTOL,
    PROJ_TYPE_MISSILE,
    PROJ_TYPE_SUPER_MISSILE,
    PROJ_TYPE_BOMB,
    PROJ_TYPE_POWER_BOMB,

    PROJ_TYPE_END
};

// Normal beam

#define NORMAL_BEAM_DAMAGE 2

#define CHARGED_NORMAL_BEAM_DAMAGE 8

// Long beam

#define LONG_BEAM_DAMAGE 3

#define CHARGED_LONG_BEAM_DAMAGE 12

// Ice beam

#define ICE_BEAM_DAMAGE 3 // Ice
#define ICE_LONG_BEAM_DAMAGE 4 // Ice | Long

#define CHARGED_ICE_BEAM_DAMAGE 12 // Ice (Charged)
#define CHARGED_ICE_LONG_BEAM_DAMAGE 16 // Ice | Long (Charged)

// Wave beam

#define WAVE_BEAM_DAMAGE 3 // Wave
#define WAVE_LONG_BEAM_DAMAGE 4 // Wave | Long
#define WAVE_ICE_BEAM_DAMAGE 4 // Wave | Ice
#define WAVE_ICE_LONG_BEAM_DAMAGE 5 // Wave | Ice | Long

#define CHARGED_WAVE_BEAM_DAMAGE 12 // Wave (Charged)
#define CHARGED_WAVE_LONG_BEAM_DAMAGE 16 // Wave | Long (Charged)
#define CHARGED_WAVE_ICE_BEAM_DAMAGE 16 // Wave | Ice (Charged)
#define CHARGED_WAVE_ICE_LONG_BEAM_DAMAGE 20 // Wave | Ice | Long (Charged)

// Plasma beam

#define PLASMA_BEAM_DAMAGE 3 // Plasma
#define PLASMA_LONG_BEAM_DAMAGE 4 // Plasma | Long
#define PLASMA_ICE_BEAM_DAMAGE 4 // Plasma | Ice
#define PLASMA_WAVE_BEAM_DAMAGE 4 // Plasma | Wave
#define PLASMA_ICE_LONG_BEAM_DAMAGE 5 // Plasma | Ice | Long
#define PLASMA_WAVE_LONG_BEAM_DAMAGE 5 // Plasma | Wave | Long
#define PLASMA_WAVE_ICE_BEAM_DAMAGE 5 // Plasma | Wave | Ice
#define PLASMA_WAVE_ICE_LONG_BEAM_DAMAGE 6 // Plasma | Wave | Ice | Long

#define CHARGED_PLASMA_BEAM_DAMAGE 12 // Plasma (Charged)
#define CHARGED_PLASMA_LONG_BEAM_DAMAGE 16 // Plasma | Long (Charged)
#define CHARGED_PLASMA_ICE_BEAM_DAMAGE 16 // Plasma | Ice (Charged)
#define CHARGED_PLASMA_WAVE_BEAM_DAMAGE 16 // Plasma | Wave (Charged)
#define CHARGED_PLASMA_ICE_LONG_BEAM_DAMAGE 20 // Plasma | Ice | Long (Charged)
#define CHARGED_PLASMA_WAVE_LONG_BEAM_DAMAGE 20 // Plasma | Wave | Long (Charged)
#define CHARGED_PLASMA_WAVE_ICE_BEAM_DAMAGE 20 // Plasma | Wave | Ice (Charged)
#define CHARGED_PLASMA_WAVE_ICE_LONG_BEAM_DAMAGE 24 // Plasma | Wave | Ice | Long (Charged)

// Pistol

#define CHARGED_PISTOL_DAMAGE 12

// Missile

#define MISSILE_DAMAGE 20

// Super missile

#define SUPER_MISSILE_DAMAGE 100

// Bomb

#define BOMB_DAMAGE 8

enum ProjectileBombStage {
    BOMB_STAGE_INIT,
    BOMB_STAGE_FIRST_SPIN,
    BOMB_STAGE_FAST_SPIN,
    BOMB_STAGE_EXPLODING,
    BOMB_STAGE_PLACED_ON_LAUNCHER,
    BOMB_STAGE_FIRST_SPIN_ON_LAUNCHER,
    BOMB_STAGE_FAST_SPIN_ON_LAUNCHER,
    BOMB_STAGE_EXPLODING_ON_LAUNCHER,

    BOMB_STAGE_END
};

#define BOMB_EXPLOSION_TIMER (CONVERT_SECONDS(.25f) + 1 * DELTA_TIME)

// Power bomb

#define POWER_BOMB_DAMAGE 50

enum ProjectilePowerBombStage {
    POWER_BOMB_STAGE_INIT,
    POWER_BOMB_STAGE_FIRST_SPIN,
    POWER_BOMB_STAGE_FAST_SPIN,

    POWER_BOMB_STAGE_END
};

// Charge beam thresholds

#define CHARGE_BEAM_START_THRESHOLD 16
#define CHARGE_BEAM_UNCHARGED_THRESHOLD 25
#define CHARGE_BEAM_THRESHOLD 64
#define CHARGE_BEAM_MAX_THRESHOLD (CHARGE_BEAM_THRESHOLD + 15)

#define CHARGE_PISTOL_THRESHOLD 112
#define CHARGE_PISTOL_MAX_THRESHOLD (CHARGE_PISTOL_THRESHOLD + 15)

// Projectiles limit

#define PROJ_LIMIT_BEAM 6
#define PROJ_LIMIT_CHARGED_BEAM 2
#define PROJ_LIMIT_PISTOL 6
#define PROJ_LIMIT_CHARGED_PISTOL 2
#define PROJ_LIMIT_MISSILE 4
#define PROJ_LIMIT_SUPER_MISSILE 4
#define PROJ_LIMIT_BOMB 4
#define PROJ_LIMIT_POWER_BOMB 1


#define PROJ_SHORT_BEAM_LIFETIME (CONVERT_SECONDS(.2f))

enum ProjectileStage {
    PROJECTILE_STAGE_INIT,
    PROJECTILE_STAGE_SPAWNING,
    PROJECTILE_STAGE_MOVING,

    PROJECTILE_STAGE_TUMBLING = 7
};


#define WAVE_BEAM_HITBOX_TOP (BLOCK_SIZE)
#define WAVE_BEAM_HITBOX_BOTTOM (BLOCK_SIZE)
#define WAVE_BEAM_HITBOX_LEFT (QUARTER_BLOCK_SIZE + PIXEL_SIZE)
#define WAVE_BEAM_HITBOX_RIGHT (QUARTER_BLOCK_SIZE + PIXEL_SIZE)

#define CHARGED_WAVE_BEAM_HITBOX_TOP (BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
#define CHARGED_WAVE_BEAM_HITBOX_BOTTOM (BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
#define CHARGED_WAVE_BEAM_HITBOX_LEFT (QUARTER_BLOCK_SIZE + PIXEL_SIZE)
#define CHARGED_WAVE_BEAM_HITBOX_RIGHT (QUARTER_BLOCK_SIZE + PIXEL_SIZE)

#endif /* PROJECTILE_CONSTANTS_H */
