#ifndef SPRITE_H
#define SPRITE_H

#include "types.h"
#include "oam.h"

enum __attribute__((packed)) sprite_status {
    SPRITE_STATUS_NONE = 0x0,
    SPRITE_STATUS_EXISTS = 0x1,
    SPRITE_STATUS_ONSCREEN = 0x2,
    SPRITE_STATUS_NOT_DRAWN = 0x4,
    SPRITE_STATUS_ROTATION_SCALING = 0x8,
    SPRITE_STATUS_UNKNOWN = 0x10,
    SPRITE_STATUS_MOSAIC = 0x20,
    SPRITE_STATUS_XFLIP = 0x40,
    SPRITE_STATUS_YFLIP = 0x80,
    SPRITE_STATUS_FACING_DOWN = 0x100,
    SPRITE_STATUS_FACING_RIGHT = 0x200,
    SPRITE_STATUS_ON_VERTICAL_WALL = 0x400,
    SPRITE_STATUS_SAMUS_COLLIDING = 0x800,
    SPRITE_STATUS_SAMUS_ON_TOP = 0x1000,
    SPRITE_STATUS_UNKNOWN4 = 0x4000,
    SPRITE_STATUS_UNKNOWN3 = 0x8000
};

enum __attribute__((packed)) p_sprite_id {
    PSPRITE_UNUSED0 = 0x0,
    PSPRITE_UNUSED1 = 0x1,
    PSPRITE_UNUSED2 = 0x3,
    PSPRITE_UNUSED3 = 0x3,
    PSPRITE_UNUSED4 = 0x4,
    PSPRITE_UNUSED5 = 0x5,
    PSPRITE_UNUSED6 = 0x6,
    PSPRITE_UNUSED7 = 0x7,
    PSPRITE_UNUSED8 = 0x8,
    PSPRITE_UNUSED9 = 0x9,
    PSPRITE_UNUSED10 = 0xA,
    PSPRITE_UNUSED11 = 0xB,
    PSPRITE_UNUSED12 = 0xC,
    PSPRITE_UNUSED13 = 0xD,
    PSPRITE_UNUSED14 = 0xE,
    PSPRITE_UNUSED15 = 0xF,
    PSPRITE_UNUSED16 = 0x10,
    PSPRITE_ITEM_BANNER = 0x11,
    PSPRITE_ZOOMER_YELLOW = 0x12,
    PSPRITE_ZOOMER_RED = 0x13,
    PSPRITE_ZEELA = 0x14,
    PSPRITE_ZEELA_RED = 0x15,
    PSPRITE_RIPPER_BROWN = 0x16,
    PSPRITE_RIPPER_PURPLE = 0x17,
    PSPRITE_ZEB = 0x18,
    PSPRITE_ZEB_BLUE = 0x19,
    PSPRITE_LARGE_ENERGY_DROP = 0x1A,
    PSPRITE_SMALL_ENERGY_DROP = 0x1B,
    PSPRITE_MISSILE_DROP = 0x1C,
    PSPRITE_SUPER_MISSILE_DROP = 0x1D,
    PSPRITE_POWER_BOMB_DROP = 0x1E,
    PSPRITE_SKREE_GREEN = 0x1F,
    PSPRITE_SKREE_BLUE = 0x20,
    PSPRITE_MORPH_BALL = 0x21,
    PSPRITE_CHOZO_STATUE_LONG_HINT = 0x22,
    PSPRITE_CHOZO_STATUE_LONG = 0x23,
    PSPRITE_CHOZO_STATUE_ICE_HINT = 0x24,
    PSPRITE_CHOZO_STATUE_ICE = 0x25,
    PSPRITE_CHOZO_STATUE_WAVE_HINT = 0x26,
    PSPRITE_CHOZO_STATUE_WAVE = 0x27,
    PSPRITE_CHOZO_STATUE_BOMB_HINT = 0x28,
    PSPRITE_CHOZO_STATUE_BOMB = 0x29,
    PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT = 0x2A,
    PSPRITE_CHOZO_STATUE_SPEEDBOOSTER = 0x2B,
    PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT = 0x2C,
    PSPRITE_CHOZO_STATUE_HIGH_JUMP = 0x2D,
    PSPRITE_CHOZO_STATUE_SCREW_HINT = 0x2E,
    PSPRITE_CHOZO_STATUE_SCREW = 0x2F,
    PSPRITE_CHOZO_STATUE_VARIA_HINT = 0x30,
    PSPRITE_CHOZO_STATUE_VARIA = 0x31,
    PSPRITE_SOVA_PURPLE = 0x32,
    PSPRITE_SOVA_ORANGE = 0x33,
    PSPRITE_MULTIVIOLA = 0x34,
    PSPRITE_MULTIPLE_LARGE_ENERGY = 0x35,
    PSPRITE_GERUTA_RED = 0x36,
    PSPRITE_GERUTA_GREEN = 0x37,
    PSPRITE_SQUEEPT = 0x38,
    PSPRITE_SQUEEPT_UNUSED = 0x39,
    PSPRITE_MAP_STATION = 0x3A,
    PSPRITE_DRAGON = 0x3B,
    PSPRITE_DRAGON_UNUSED = 0x3C,
    PSPRITE_ZIPLINE = 0x3D,
    PSPRITE_ZIPLINE_BUTTON = 0x3E,
    PSPRITE_REO_GREEN_WINGS = 0x3F,
    PSPRITE_REO_PURPLE_WINGS = 0x40,
    PSPRITE_GUNSHIP = 0x41,
    PSPRITE_DEOREM = 0x42,
    PSPRITE_DEOREM_SECOND_LOCATION = 0x43,
    PSPRITE_CHARGE_BEAM = 0x44,
    PSPRITE_SKULTERA = 0x45,
    PSPRITE_DESSGEEGA = 0x46,
    PSPRITE_DESSGEEGA_AFTER_LONG_BEAM = 0x47,
    PSPRITE_WAVER = 0x48,
    PSPRITE_WAVER_UNUSED = 0x49,
    PSPRITE_MELLOW = 0x4A,
    PSPRITE_HIVE = 0x4B,
    PSPRITE_POWER_GRIP = 0x4C,
    PSPRITE_IMAGO_LARVA_RIGHT = 0x4D,
    PSPRITE_MORPH_BALL_LAUNCHER = 0x4E,
    PSPRITE_IMAGO_COCOON = 0x4F,
    PSPRITE_ELEVATOR_PAD = 0x50,
    PSPRITE_SPACE_PIRATE = 0x51,
    PSPRITE_SPACE_PIRATE_WAITING1 = 0x52,
    PSPRITE_SPACE_PIRATE_WAITING2 = 0x53,
    PSPRITE_SPACE_PIRATE_WAITING3 = 0x54,
    PSPRITE_SPACE_PIRATE2 = 0x55,
    PSPRITE_GAMET_BLUE_SINGLE = 0x56,
    PSPRITE_GAMET_RED_SINGLE = 0x57,
    PSPRITE_CHOZO_STATUE_GRAVITY = 0x58,
    PSPRITE_CHOZO_STATUE_SPACE_JUMP = 0x59,
    PSPRITE_SECURITY_GATE_DEFAULT_OPEN = 0x5A,
    PSPRITE_ZEBBO_GREEN = 0x5B,
    PSPRITE_ZEBBO_YELLOW = 0x5C,
    PSPRITE_WORKER_ROBOT = 0x5D,
    PSPRITE_PARASITE_MULTIPLE = 0x5E,
    PSPRITE_PARASITE = 0x5F,
    PSPRITE_PISTON = 0x60,
    PSPRITE_RIDLEY = 0x61,
    PSPRITE_SECURITY_GATE_DEFAULT_CLOSED = 0x62,
    PSPRITE_ZIPLINE_GENERATOR = 0x63,
    PSPRITE_METROID = 0x64,
    PSPRITE_FROZEN_METROID = 0x65,
    PSPRITE_RINKA_ORANGE = 0x66,
    PSPRITE_POLYP = 0x67,
    PSPRITE_VIOLA_BLUE = 0x68,
    PSPRITE_VIOLA_ORANGE = 0x69,
    PSPRITE_GERON_NORFAIR = 0x6A,
    PSPRITE_HOLTZ = 0x6B,
    PSPRITE_GEKITAI_MACHINE = 0x6C,
    PSPRITE_RUINS_TEST = 0x6D,
    PSPRITE_SAVE_PLATFORM = 0x6E,
    PSPRITE_KRAID = 0x6F,
    PSPRITE_IMAGO_COCOON_AFTER_FIGHT = 0x70,
    PSPRITE_RIPPERII = 0x71,
    PSPRITE_MELLA = 0x72,
    PSPRITE_ATOMIC = 0x73,
    PSPRITE_AREA_BANNER = 0x74,
    PSPRITE_MOTHER_BRAIN = 0x75,
    PSPRITE_FAKE_POWER_BOMB_EVENT_TRIGGER = 0x76,
    PSPRITE_ACID_WORM = 0x77,
    PSPRITE_ESCAPE_SHIP = 0x78,
    PSPRITE_SIDEHOPPER = 0x79,
    PSPRITE_GEEGA = 0x7A,
    PSPRITE_GEEGA_WHITE = 0x7B,
    PSPRITE_RINKA_MOTHER_BRAIN = 0x7C,
    PSPRITE_ZEBETITE_ONE_AND_THREE = 0x7D,
    PSPRITE_CANNON = 0x7E,
    PSPRITE_IMAGO_LARVA_RIGHT_SIDE = 0x7F,
    PSPRITE_TANGLE_VINE_TALL = 0x80,
    PSPRITE_TANGLE_VINE_MEDIUM = 0x81,
    PSPRITE_TANGLE_VINE_CURVED = 0x82,
    PSPRITE_TANGLE_VINE_SHORT = 0x83,
    PSPRITE_MELLOW_SWARM = 0x84,
    PSPRITE_MELLOW_SWARM_HEALTH_BASED = 0x85,
    PSPRITE_IMAGO = 0x86,
    PSPRITE_ZEBITITE_TWO_AND_FOUR = 0x87,
    PSPRITE_CANNON2 = 0x88,
    PSPRITE_CANNON3 = 0x89,
    PSPRITE_CROCOMIRE = 0x8A,
    PSPRITE_IMAGO_LARVA_LFT = 0x8B,
    PSPRITE_GERON_BRINSTAR_ROOM_15 = 0x8C,
    PSPRITE_GERON_BRINSTAR_ROOM_1C = 0x8D,
    PSPRITE_GERON_VARIA1 = 0x8E,
    PSPRITE_GERON_VARIA2 = 0x8F,
    PSPRITE_GERON_VARIA3 = 0x90,
    PSPRITE_GLASS_TUBE = 0x91,
    PSPRITE_SAVE_PLATFORM_CHOZODIA = 0x92,
    PSPRITE_BARISTUTE = 0x93,
    PSPRITE_CHOZO_STATUE_PLASMA_BEAM = 0x94,
    PSPRITE_KRAID_ELEVATOR_STATUE = 0x95,
    PSPRITE_RIDLEY_ELEVATOR_STATUE = 0x96,
    PSPRITE_RISING_CHOZO_PILLAR = 0x97,
    PSPRITE_SECURITY_LASER_VERTICAL = 0x98,
    PSPRITE_SECURITY_LASER_HORIZONTAL = 0x99,
    PSPRITE_SECURITY_LASER_VERTICAL2 = 0x9A,
    PSPRITE_SECURITY_LASER_HORIZONTAL2 = 0x9B,
    PSPRITE_LOCK_UNLOCK_METROID_DOORS_UNUSED = 0x9C,
    PSPRITE_GAMET_BLUE_LEADER = 0x9D,
    PSPRITE_GAMET_BLUE_FOLLOWER = 0x9E,
    PSPRITE_GEEGA_LEADER = 0x9F,
    PSPRITE_GEEGA_FOLLOWER = 0xA0,
    PSPRITE_ZEBBO_GREEN_LEADER = 0xA1,
    PSPRITE_ZEBBO_GREEN_FOLLOWER = 0xA2,
    PSPRITE_KRAID_STATUE = 0xA3,
    PSPRITE_RIDLEY_STATUE = 0xA4,
    PSPRITE_RINKA_GREEN = 0xA5,
    PSPRITE_SEARCHLIGHT_EYE = 0xA6,
    PSPRITE_SEARCHLIGHT_EYE2 = 0xA7,
    PSPRITE_STEAM_LARGE = 0xA8,
    PSPRITE_STEAM_SMALL = 0xA9,
    PSPRITE_PLASMA_BEAM_BLOCK = 0xAA,
    PSPRITE_GRAVITY_SUIT_BLOCK = 0xAB,
    PSPRITE_SPACE_JUMP_BLOCK = 0xAC,
    PSPRITE_GADORA_KRAID = 0xAD,
    PSPRITE_GADORA_RIDLEY = 0xAE,
    PSPRITE_SEARCHLIGHT = 0xAF,
    PSPRITE_SEARCHLIGHT2 = 0xB0,
    PSPRITE_SEARCHLIGHT3 = 0xB1,
    PSPRITE_SEARCHLIGHT4 = 0xB2,
    PSPRITE_MAYBE_SEARCHLIGHT_TRIGGER = 0xB3,
    PSPRITE_DISCOVERED_IMAGO_PASSAGE_EVENT_TRIGGER = 0xB4,
    PSPRITE_FAKE_POWER_BOMB = 0xB5,
    PSPRITE_SPACE_PIRATE_CARRYING_POWER_BOMB = 0xB6,
    PSPRITE_TANGLE_VINE_RED_GARUTA = 0xB7,
    PSPRITE_TANGLE_VINE_GERUTA = 0xB8,
    PSPRITE_TANGLE_VINE_LARVA_RIGHT = 0xB9,
    PSPRITE_TANGLE_VINE_LARVA_LEFT = 0xBA,
    PSPRITE_WATER_DROP = 0xBB,
    PSPRITE_FALLING_CHOZO_PILLAR = 0xBC,
    PSPRITE_MECHA_RIDLEY = 0xBD,
    PSPRITE_EXPLOSION_ZEBES_ESCAPE = 0xBE,
    PSPRITE_STEAM_LARGE_DIAGONAL_UP = 0xBF,
    PSPRITE_STEAM_SMALL_DIAGONAL_UP = 0xC0,
    PSPRITE_STEAM_LARGE_DIAGONAL_DOWN = 0xC1,
    PSPRITE_STEAM_SMALL_DIAGONAL_DOWN = 0xC2,
    PSPRITE_BARISTUTE_KRAID_UPPER = 0xC3,
    PSPRITE_ESCAPE_GATE1 = 0xC4,
    PSPRITE_ESCAPE_GATE2 = 0xC5,
    PSPRITE_BLACK_SPACE_PIRATE = 0xC6,
    PSPRITE_ESCAPE_SHIP_SPACE_PIRATE = 0xC7,
    PSPRITE_BARISTUTE_KRAID_LOWER = 0xC8,
    PSPRITE_RINKA_MOTHER_BRAIN2 = 0xC9,
    PSPRITE_RINKA_MOTHER_BRAIN3 = 0xCA,
    PSPRITE_RINKA_MOTHER_BRAIN4 = 0xCB,
    PSPRITE_RINKA_MOTHER_BRAIN5 = 0xCC,
    PSPRITE_RINKA_MOTHER_BRAIN6 = 0xCD
};

enum __attribute__((packed)) s_sprite_id {
    SSPRITE_CHOZO_BALL = 0x0,
    SSPRITE_CHOZO_STATUE_BODY = 0x1,
    SSPRITE_CHOZO_STATUE_REFILL = 0x2,
    SSPRITE_KRAID_MOUTH = 0x3,
    SSPRITE_CHOZO_STATUE_MOVEMENT = 0x4,
    SSPRITE_CHARGE_BEAM_GLOW = 0x5,
    SSPRITE_RIPPER_IMAGO = 0x6,
    SSPRITE_MULTIVIOLA_UNUSED = 0x7,
    SSPRITE_DRAGON_FIREBALL = 0x8,
    SSPRITE_DEOREM_SEGMENT = 0x9,
    SSPRITE_DEOREM_EYE = 0xA,
    SSPRITE_DEOREM_THORN = 0xB,
    SSPRITE_SKREE_EXPLOSION = 0xC,
    SSPRITE_SAVE_PLATFORM_TOP = 0xD,
    SSPRITE_SAVE_YES_NO_CURSOR = 0xE,
    SSPRITE_BLUE_SKREE_EXPLOSION = 0xF,
    SSPRITE_ZEELA_EYES = 0x10,
    SSPRITE_HIVE_ROOTS = 0x11,
    SSPRITE_IMAGO_LARVA_OUTSIDE = 0x12,
    SSPRITE_MORPH_BALL_OUTSIDE = 0x13,
    SSPRITE_IMAGO_COCOON_VINE = 0x14,
    SSPRITE_IMAGO_COCOON_SPORE = 0x15,
    SSPRITE_SPACE_PIRATE_LASER = 0x16,
    SSPRITE_RIDLEY_BODY = 0x17,
    SSPRITE_RIDLEY_TAIL = 0x18,
    SSPRITE_SEARCHLIGHT_EYE_BEAM = 0x19,
    SSPRITE_METROID_SHELL = 0x1A,
    SSPRITE_POLYP_PROJECTILE = 0x1B,
    SSPRITE_KRAID_SPIKE = 0x1C,
    SSPRITE_KRAID_NAIL = 0x1D,
    SSPRITE_ZIPLINE_BUTTON_INITIALIZE_MORPH_SYMBOL = 0x1E,
    SSPRITE_ATOMIC_ELECTRICITY = 0x1F,
    SSPRITE_MOTHER_BRAIN_EYE = 0x20,
    SSPRITE_RIDLEY_FIREBALL = 0x21,
    SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_BODY = 0x22,
    SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_REFILL = 0x23,
    SSPRITE_MORPH_BALL_LAUNCHER_BACK = 0x24,
    SSPRITE_ACID_WORM_BODY = 0x25,
    SSPRITE_ACID_WORM_SPIT = 0x26,
    SSPRITE_CANNON_BULLET = 0x27,
    SSPRITE_CROCOMIRE_BODY = 0x28,
    SSPRITE_IMAGO_BODY = 0x29,
    SSPRITE_DEFEATED_IMAGO_COCOON = 0x2A,
    SSPRITE_IMAGO_CEILING_VINE = 0x2B,
    SSPRITE_SEARCHLIGHT_EYE_BEAM2 = 0x2C,
    SSPRITE_GERUTA_TANGLE_VINE = 0x2D,
    SSPRITE_CHOZODIA_SAVE_PLATFORM_TOP = 0x2E,
    SSPRITE_IMAGO_NEEDLE = 0x2F,
    SSPRITE_ELEVATOR_STATUE_DEBRIS = 0x30,
    SSPRITE_IMAGO_DAMAGED_STINGER = 0x31,
    SSPRITE_GUNSHIP_PART = 0x32,
    SSPRITE_IMAGO_EGG = 0x33,
    SSPRITE_MAP_STATION_SCREEN = 0x34,
    SSPRITE_CHOZO_PILLAR_PLATFORM = 0x35,
    SSPRITE_GADORA_EYE = 0x36,
    SSPRITE_GADORA_BEAM = 0x37,
    SSPRITE_UNKNOWN_ITEM_BLOCK_LIGHT = 0x38,
    SSPRITE_SEARCHLIGHT_EYE_PROJECTILE = 0x39,
    SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW = 0x3A,
    SSPRITE_RUINS_TEST_SYMBOL = 0x3B,
    SSPRITE_RUINS_TEST_SAMUS_REFLECTION_START = 0x3C,
    SSPRITE_RUINS_TEST_REFLECTION_COVER = 0x3D,
    SSPRITE_RUINS_TEST_GHOST_OUTLINE = 0x3E,
    SSPRITE_RUINS_TEST_GHOST = 0x3F,
    SSPRITE_RUINS_TEST_SHOOTABLE_SYMBOL = 0x40,
    SSPRITE_RUINS_TEST_SAMUS_REFLECTION_END = 0x41,
    SSPRITE_RUINS_TEST_LIGHTNING = 0x42,
    SSPRITE_RIDLEY_BIG_FIREBALL = 0x43,
    SSPRITE_MECHA_RIDLEY_PART = 0x44,
    SSPRITE_ESCAPE_SHIP_PART = 0x45,
    SSPRITE_POWER_GRIP_GLOW = 0x46,
    SSPRITE_MECHA_RIDLEY_LASER = 0x47,
    SSPRITE_MECHA_RIDLEY_MISSILE = 0x48,
    SSPRITE_MECHA_RIDLEY_FIREBALL = 0x49,
    SSPRITE_MOTHER_BRAIN_BEAM = 0x4A,
    SSPRITE_MOTHER_BRAIN_BLOCK = 0x4B,
    SSPRITE_MOTHER_BRAIN_GLASS_BREAKING = 0x4C
};

enum __attribute__((packed)) sprite_samus_collision {
    SSC_NONE = 0x0,
    SSC_SOLID = 0x1,
    SSC_ESCAPE_SHIP = 0x2,
    SSC_HURTS_SAMUS = 0x4,
    SSC_ATOMIC_DISCHARGE = 0x5,
    SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT = 0x6,
    SSC_KNOCKS_BACK_SAMUS = 0x7,
    SSC_KRAID = 0xA,
    SSC_HURTS_SAMUS_NO_PASS_THROUGH = 0xB,
    SSC_ZEBETITE = 0xC,
    SSC_IMAGO_STINGER = 0xD,
    SSC_MELLOW = 0x12,
    SSC_SPACE_PIRATE_LASER = 0x13,
    SSC_SPACE_PIRATE = 0x14,
    SSC_ACID_WORM = 0x15,
    SSC_ACID_WORM_MOUTH = 0x16,
    SSC_BUG = 0x17,
    SSC_METROID = 0x18,
    SSC_KRAID_SPIKE = 0x19,
    SSC_ZIPLINE = 0x1A,
    SSC_IMAGO_EGG = 0x1B,
    SSC_RIDLEY_CLAW = 0x1C,
    SSC_MECHA_RIDLEY = 0x1D,
    SSC_ABILITY_LASER_SEARCHLIGHT = 0x1E,
    SSC_SMALL_ENERGY_DROP = 0x1F,
    SSC_LARGE_ENERGY_DROP = 0x20,
    SSC_MISSILE_DROP = 0x21,
    SSC_SUPER_MISSILE_DROP = 0x22,
    SSC_POWER_BOMB_DROP = 0x23,
    SSC_MULTIPLE_LARGE_ENERGY_DROP = 0x24
};

enum __attribute__((packed)) sprite_properties {
    SP_NONE = 0x0,
    SP_ALWAYS_ACTIVE = 0x1,
    SP_UNKNOWN = 0x2,
    SP_PROJECTILE = 0x4,
    SP_SOLID_FOR_PROJECTILES = 0x8,
    SP_MAYBE_DESTROYED = 0x10,
    SP_MESSAGE_BANNER = 0x20,
    SP_IMMUNE_TO_PROJECTILES = 0x40,
    SP_SECONDARY_SPRITE = 0x80
};

enum __attribute__((packed)) sprite_weakness_flags {
    WEAKNESS_NONE = 0x0,
    WEAKNESS_CHARGE_BEAM_PISTOL = 0x1,
    WEAKNESS_BEAM_BOMBS = 0x2,
    WEAKNESS_SUPER_MISSILES = 0x4,
    WEAKNESS_MISSILES = 0x8,
    WEAKNESS_POWER_BOMB = 0x10,
    WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK = 0x20,
    WEAKNESS_CAN_BE_FROZEN = 0x40,
    WEAKNESS_LIMIT = 0xFFFF
};

struct __attribute__((packed)) enemy_room_data {
    u8 y_position;
    u8 x_position;
    u8 spriteset_slot;
};

struct sub_sprite_data {
    struct frame_data* oam_pointer;
    u16 curr_anim_frame;
    u16 y_position;
    u16 x_position;
    u16 health;
    u8 anim_duration_counter;
    u8 maybe_status;
    u8 timer;
    u8 unknown;
    u8 maybe_room_slot;
    u8 maybe_ram_slot;
    u8 unknown2;
    u8 unknown3;
};

struct sprite_data {
    enum sprite_status status;
    u16 y_position;
    u16 x_position;
    u16 y_position_spawn;
    u16 x_position_spawn;
    i16 hitbox_top_offset;
    i16 hitbox_bottom_offset;
    i16 hitbox_left_offset;
    i16 hitbox_right_offset;
    u16 oam_scaling;
    u16 health;
    u16 curr_anim_frame;
    struct frame_data* oam_pointer;
    u8 anim_duration_counter;
    enum p_sprite_id sprite_id;
    u8 room_slot;
    u8 spriteset_gfx_slot;
    u8 palette_row;
    u8 bg_priority;
    u8 draw_order;
    u8 primary_sprite_ram_slot;
    u8 pose;
    enum sprite_samus_collision samus_collision;
    u8 ignore_samus_collision_timer;
    u8 draw_distance_top_offset;
    u8 draw_distance_bottom_offset;
    u8 draw_distance_horizontal_offset;
    u8 oam_rotation;
    u8 invicibility_stun_flash_timer;
    u8 timer1;
    u8 timer2;
    u8 maybe_variable;
    u8 array_offset;
    u8 freeze_timer;
    u8 standing_on_sprite;
    enum sprite_properties properties;
    u8 frozen_palette_row_offset;
    u8 maybe_absolute_palette_row;
};

void sprite_update(void);
void sprite_update_animation(struct sprite_data* pSprite);
void sprite_draw_all_2(void);
void sprite_draw_all(void);
void sprite_draw_all_3(void);
void sprite_draw(struct sprite_data* pSprite, u32 slot);
void sprite_check_on_screen(struct sprite_data* pSprite);
void sprite_load_all_data(void);
void sprite_load_spriteset(void);
void sprite_load_gfx(enum p_sprite_id sprite_id, u8 gfx_row);
void sprite_load_pal(enum p_sprite_id sprite_id, u8 gfx_row, u32 len);
void sprite_clear_data(void);
void sprite_load_room_sprites(void);
void sprite_init_primary(u8 spriteset_slot, u16 y_position, u16 x_position, u8 room_slot);
u8 sprite_spawn_secondary(enum s_sprite_id sprite_id, u8 room_slot, u8 gfx_slot, u8 ram_slot, u16 y_position, u16 x_position, enum sprite_status status_to_add);
u8 sprite_spawn_primary(enum p_sprite_id sprite_id, u8 room_slot, u8 gfx_slot, u16 y_position, u16 x_position, enum sprite_status status_to_add);
u8 sprite_spawn_drop_followers(enum p_sprite_id sprite_id, u8 room_slot, u8 gfx_slot, u8 ram_slot, u16 y_position, u16 x_position, enum sprite_status status_to_add);

#endif /* SPRITE_H */