#ifndef AUDIO_CONSTANTS_H
#define AUDIO_CONSTANTS_H

enum Sound {
    MUSIC_NONE, // 0x0
    MUSIC_BRINSTAR, // 0x1
    MUSIC_TITLE_SCREEN, // 0x2
    MUSIC_SAVE_ELEVATOR_ROOM, // 0x3
    MUSIC_INTRO, // 0x4
    MUSIC_CHOZO_STATUE_HINT, // 0x5
    MUSIC_NORFAIR, // 0x6
    MUSIC_KRAID, // 0x7
    MUSIC_ESCAPE, // 0x8
    MUSIC_FILE_SELECT, // 0x9
    MUSIC_STATUE_ROOM, // 0xA
    MUSIC_BOSS_KILLED, // 0xB
    MUSIC_MAP_ROOM, // 0xC
    MUSIC_CHOZO_RUINS_DEPTH, // 0xD
    MUSIC_CHOZO_RUINS, // 0xE
    MUSIC_CHOZO_RUINS_LIGHT, // 0xF
    MUSIC_RIDLEY_IN_SPACE, // 0x10
    MUSIC_RIDLEY_LANDING, // 0x11
    MUSIC_CHOZO_STATUE_HINT_DELAY, // 0x12
    MUSIC_GETTING_FULLY_POWERED_SUIT_CUTSCENE, // 0x13
    MUSIC_ESCAPING_ZEBES_CUTSCENE, // 0x14
    MUSIC_CHOZO_VOICE_1, // 0x15
    MUSIC_CHOZO_VOICE_2, // 0x16
    MUSIC_BEFORE_RUINS_TEST_UNUSED, // 0x17
    MUSIC_ELEVATOR_ROOM, // 0x18
    MUSIC_BRINSTAR_REMIX, // 0x19
    MUSIC_ESCAPE_SUCCESFUL, // 0x1A
    MUSIC_CREDITS, // 0x1B
    MUSIC_STATUE_ROOM_OPENED, // 0x1C
    MUSIC_1d, // 0x1d
    MUSIC_1e, // 0x1e
    MUSIC_1f, // 0x1f
    MUSIC_20, // 0x20
    MUSIC_21, // 0x21
    MUSIC_22, // 0x22
    MUSIC_23, // 0x23
    MUSIC_24, // 0x24
    MUSIC_25, // 0x25
    MUSIC_26, // 0x26
    MUSIC_27, // 0x27
    MUSIC_28, // 0x28
    MUSIC_29, // 0x29
    MUSIC_2a, // 0x2a
    MUSIC_2b, // 0x2b
    MUSIC_2c, // 0x2c
    MUSIC_2d, // 0x2d
    MUSIC_2e, // 0x2e
    MUSIC_2f, // 0x2f
    MUSIC_30, // 0x30
    MUSIC_31, // 0x31
    MUSIC_RIDLEY, // 0x32
    MUSIC_33, // 0x33
    MUSIC_KRAID_BATTLE_WITH_INTRO, // 0x34
    MUSIC_RIDLEY_BATTLE, // 0x35
    MUSIC_LOADING_JINGLE, // 0x36
    MUSIC_GETTING_ITEM_JINGLE, // 0x37
    MUSIC_38, // 0x38
    MUSIC_INTRO_MOTHER_BRAIN, // 0x39
    MUSIC_GETTING_TANK_JINGLE, // 0x3A
    MUSIC_TOURIAN, // 0x3B
    MUSIC_WORMS_BATTLE, // 0x3C
    MUSIC_MOTHER_BRAIN_BATTLE, // 0x3D
    MUSIC_CATTERPILLARS_BATTLE, // 0x3E
    MUSIC_IMAGO_COCOON_BATTLE, // 0x3F
    MUSIC_IMAGO_BATTLE, // 0x40
    MUSIC_MECHA_RIDLEY_BATTLE, // 0x41
    MUSIC_GETTING_UNKNOWN_ITEM_JINGLE, // 0x42
    MUSIC_RUINS_TEST_BATTLE_WITH_INTRO, // 0x43
    MUSIC_ENTERING_TOURIAN_CUTSCENE, // 0x44
    MUSIC_ALARM_ACTIVATED, // 0x45
    MUSIC_STEALTH, // 0x46
    MUSIC_47, // 0x47
    MUSIC_ENTERING_NORFAIR_CUTSCENE, // 0x48
    MUSIC_CHOZODIA_DETECTED, // 0x49
    MUSIC_GETTING_FULLY_POWERED_SUIT_JINGLE, // 0x4A
    MUSIC_KRAID_BATTLE, // 0x4B
    MUSIC_RIDLEY_BATTLE_2, // 0x4C
    MUSIC_MECHA_RIDLEY_BATTLE_2, // 0x4D
    MUSIC_RUINS_TEST_BATTLE, // 0x4E
    MUSIC_CATTERPILLARS_BATTLE_2, // 0x4F
    MUSIC_CRATERIA, // 0x50
    MUSIC_51, // 0x51
    MUSIC_52, // 0x52
    MUSIC_GAME_OVER, // 0x53
    MUSIC_54, // 0x54
    MUSIC_55, // 0x55
    MUSIC_56, // 0x56
    MUSIC_57, // 0x57
    MUSIC_58, // 0x58
    MUSIC_59, // 0x59
    MUSIC_CHOZODIA_SURFACE, // 0x5A
    MUSIC_MAP_ROOM_2, // 0x5B
    MUSIC_SAVE_ELEVATOR_ROOM_2, // 0x5C
    MUSIC_BEFORE_RUINS_TEST_ROOM, // 0x5D
    MUSIC_STEALTH_2, // 0x5E
    MUSIC_5F, // 0x5F

    SOUND_60, // 0x60
    SOUND_61, // 0x61
    SOUND_62, // 0x62
    SOUND_63, // 0x63

    SOUND_FOOTSTEPS_1, // 0x64
    SOUND_FOOTSTEPS_2, // 0x65
    SOUND_FOOTSTEPS_DUSTY_GROUND_1, // 0x66
    SOUND_FOOTSTEPS_DUSTY_GROUND_2, // 0x67
    SOUND_FOOTSTEPS_WET_GROUND_1, // 0x68
    SOUND_FOOTSTEPS_WET_GROUND_2, // 0x69
    SOUND_SPIN_JUMP, // 0x6A
    SOUND_SPACE_JUMP, // 0x6B
    SOUND_SCREW_ATTACK, // 0x6C
    SOUND_SPACE_SCREW_ATTACK, // 0x6D
    SOUND_LOW_JUMP, // 0x6E
    SOUND_HIGH_JUMP, // 0x6F
    SOUND_MORPH_BALL_JUMP, // 0x70

    SOUND_LANDING, // 0x71
    SOUND_MORPH_BALL_LANDING, // 0x72
    SOUND_LANDING_ON_DUSTY_GROUND, // 0x73
    SOUND_GOING_IN_LIQUID, // 0x74
    SOUND_GOING_OUT_OF_LIQUID, // 0x75
    SOUND_WALL_JUMP, // 0x76
    SOUND_MORPHING, // 0x77
    SOUND_UNMORPHING, // 0x78
    SOUND_CROUCHING, // 0x79
    SOUND_GRAB_LEDGE, // 0x7A
    SOUND_GRABBING_LEDGE, // 0x7B
    SOUND_HURT, // 0x7C
    SOUND_LIQUID_DAMAGE, // 0x7D
    SOUND_LIQUID_DAMAGE_SUBMERGED, // 0x7E
    SOUND_ROOM_DAMAGE, // 0x7F
    SOUND_BUG_LEECHING, // 0x80
    SOUND_METROID_LEECHING, // 0x81
    SOUND_LOW_HEALTH_BEEP, // 0x82
    SOUND_DYING, // 0x83
    SOUND_ARMING_WEAPON, // 0x84
    SOUND_MISSILE_TOGGLE, // 0x85
    SOUND_GETTING_SMALL_ENERGY_DROP, // 0x86
    SOUND_GETTING_LARGE_ENERGY_DROP, // 0x87
    SOUND_GETTING_MISSILE_DROP, // 0x88
    SOUND_GETTING_SUPER_MISSILE_DROP, // 0x89
    SOUND_GETTING_POWER_BOMB_DROP, // 0x8A
    SOUND_SPEEDBOOSTER_START, // 0x8B
    SOUND_SKIDDING, // 0x8C
    SOUND_SPEEDBOOSTER_CHARGE, // 0x8D
    SOUND_SHINESPARKING, // 0x8E
    SOUND_BALLSPARKING, // 0x8F
    SOUND_SHINESPARK_COLLISION, // 0x90

    SOUND_WATER_BUBBLES, // 0x91
    SOUND_WATER_SPIN_JUMP, // 0x92
    SOUND_WATER_MOVEMENT_RUNNING, // 0x93
    SOUND_WATER_MOVEMENT_GRABBING_LEDGE, // 0x94
    SOUND_WATER_MOVEMENT_WALL_JUMP, // 0x95

    SOUND_SUITLESS_FOOTSTEPS_1, // 0x96
    SOUND_SUITLESS_FOOTSTEPS_2, // 0x97
    SOUND_SUITLESS_SPIN_JUMP, // 0x98
    SOUND_SUITLESS_LANDING, // 0x99
    SOUND_SUITLESS_WALL_JUMP, // 0x9A
    SOUND_SUITLESS_GRAB_LEDGE, // 0x9B
    SOUND_SUITLESS_GRABBING_LEDGE, // 0x9C
    SOUND_SUITLESS_JUMP, // 0x9D
    SOUND_SUITLESS_CRAWL, // 0x9E
    SOUND_PISTOL_SHOT, // 0x9F
    SOUND_CHARGED_PISTOL_SHOT, // 0xA0
    SOUND_SUITLESS_FOOTSTEPS_WET_GROUND_1, // 0xA1
    SOUND_SUITLESS_FOOTSTEPS_WET_GROUND_2, // 0xA2
    SOUND_SUITLESS_LANDING_ON_WET_GROUND, // 0xA3

    SOUND_ZEBES_ESCAPE_EXPLOSION_1, // 0xA4
    SOUND_ZEBES_ESCAPE_EXPLOSION_2, // 0xA5

    SOUND_THUNDER, // 0xA6

    SOUND_CHOZO_PILLAR_FELL, // 0xA7

    SOUND_GAME_BOY_BOOT, // 0xA8
    SOUND_A9, // 0xA9

    SOUND_IMAGO_LARVA_IDLE, // 0xAA
    SOUND_IMAGO_LARVA_CRAWLING_SLOW, // 0xAB
    SOUND_IMAGO_LARVA_CRAWLING_FAST, // 0xAC
    SOUND_IMAGO_LARVA_WARNING, // 0xAD
    SOUND_IMAGO_LARVA_ATTACKING, // 0xAE
    SOUND_IMAGO_LARVA_DAMAGED, // 0xAF
    SOUND_IMAGO_LARVA_DYING, // 0xB0
    SOUND_IMAGO_LARVA_RIGHT_SIDE_SHAKING, // 0xB1
    SOUND_IMAGO_LARVA_RIGHT_SIDE_CORE_BEATING, // 0xB2

    SOUND_IMAGO_EGG_BREAKING, // 0xB3
    SOUND_IMAGO_BUZZING_FAR_LEFT, // 0xB4
    SOUND_IMAGO_BUZZING_FAR_RIGHT, // 0xB5
    SOUND_IMAGO_BUZZING_NEAR_LEFT, // 0xB6
    SOUND_IMAGO_BUZZING_NEAR_RIGHT, // 0xB7
    SOUND_IMAGO_BUZZING_CLOSE_LEFT, // 0xB8
    SOUND_IMAGO_BUZZING_CLOSE_RIGHT, // 0xB9
    SOUND_IMAGO_BURNING_FAR_LEFT, // 0xBA
    SOUND_IMAGO_BURNING_FAR_RIGHT, // 0xBB
    SOUND_IMAGO_BURNING_NEAR_LEFT, // 0xBC
    SOUND_IMAGO_BURNING_NEAR_RIGHT, // 0xBD
    SOUND_IMAGO_BURNING_CLOSE_LEFT, // 0xBE
    SOUND_IMAGO_BURNING_CLOSE_RIGHT, // 0xBF
    SOUND_IMAGO_NEEDLE_SHOT, // 0xC0
    SOUND_IMAGO_DAMAGED_STINGER_DETACHING, // 0xC1
    SOUND_IMAGO_DAMAGED_STINGER_EXPLODING, // 0xC2
    SOUND_IMAGO_DAMAGED, // 0xC3
    SOUND_IMAGO_DESTROYING_WALL, // 0xC4
    SOUND_IMAGO_DYING, // 0xC5

    SOUND_C6, // 0xC6
    SOUND_C7, // 0xC7

    SOUND_BEAM_SHOT, // 0xC8
    SOUND_BEAM_LONG_SHOT, // 0xC9
    SOUND_BEAM_ICE_SHOT, // 0xCA
    SOUND_BEAM_LONG_ICE_SHOT, // 0xCB
    SOUND_BEAM_WAVE_SHOT, // 0xCC
    SOUND_BEAM_WAVE_LONG_SHOT, // 0xCD
    SOUND_BEAM_WAVE_ICE_SHOT, // 0xCE
    SOUND_BEAM_WAVE_LONG_ICE_SHOT, // 0xCF
    SOUND_BEAM_PLASMA_SHOT, // 0xD0
    SOUND_BEAM_PLASMA_LONG_SHOT, // 0xD1
    SOUND_BEAM_PLASMA_ICE_SHOT, // 0xD2
    SOUND_BEAM_PLASMA_LONG_ICE_SHOT, // 0xD3
    SOUND_BEAM_PLASMA_WAVE_SHOT, // 0xD4
    SOUND_BEAM_PLASMA_WAVE_LONG_SHOT, // 0xD5
    SOUND_BEAM_PLASMA_WAVE_ICE_SHOT, // 0xD6
    SOUND_BEAM_PLASMA_WAVE_LONG_ICE_SHOT, // 0xD7

    SOUND_SHORT_CHARGE_INIT, // 0xD8
    SOUND_SHORT_CHARGE_LOOP, // 0xD9
    SOUND_LONG_CHARGE_INIT, // 0xDA
    SOUND_LONG_CHARGE_LOOP, // 0xDB
    SOUND_WAVE_CHARGE_INIT, // 0xDC
    SOUND_WAVE_CHARGE_LOOP, // 0xDD
    SOUND_WAVE_LONG_CHARGE_INIT, // 0xDE
    SOUND_WAVE_LONG_CHARGE_LOOP, // 0xDF
    SOUND_PLASMA_CHARGE_INIT, // 0xE0
    SOUND_PLASMA_CHARGE_LOOP, // 0xE1
    SOUND_PLASMA_LONG_CHARGE_INIT, // 0xE2
    SOUND_PLASMA_LONG_CHARGE_LOOP, // 0xE3
    SOUND_ICE_CHARGE_INIT, // 0xE4
    SOUND_ICE_CHARGE_LOOP, // 0xE5
    SOUND_ICE_LONG_CHARGE_INIT, // 0xE6
    SOUND_ICE_LONG_CHARGE_LOOP, // 0xE7

    SOUND_CHARGED_BEAM_SHOT, // 0xE8
    SOUND_CHARGED_BEAM_LONG_SHOT, // 0xE9
    SOUND_CHARGED_BEAM_ICE_SHOT, // 0xEA
    SOUND_CHARGED_BEAM_LONG_ICE_SHOT, // 0xEB
    SOUND_CHARGED_BEAM_WAVE_SHOT, // 0xEC
    SOUND_CHARGED_BEAM_WAVE_LONG_SHOT, // 0xED
    SOUND_CHARGED_BEAM_WAVE_ICE_SHOT, // 0xEE
    SOUND_CHARGED_BEAM_WAVE_LONG_ICE_SHOT, // 0xEF
    SOUND_CHARGED_BEAM_PLASMA_SHOT, // 0xF0
    SOUND_CHARGED_BEAM_PLASMA_LONG_SHOT, // 0xF1
    SOUND_CHARGED_BEAM_PLASMA_ICE_SHOT, // 0xF2
    SOUND_CHARGED_BEAM_PLASMA_LONG_ICE_SHOT, // 0xF3
    SOUND_CHARGED_BEAM_PLASMA_WAVE_SHOT, // 0xF4
    SOUND_CHARGED_BEAM_PLASMA_WAVE_LONG_SHOT, // 0xF5
    SOUND_CHARGED_BEAM_PLASMA_WAVE_ICE_SHOT, // 0xF6
    SOUND_CHARGED_BEAM_PLASMA_WAVE_LONG_ICE_SHOT, // 0xF7

    SOUND_MISSILE_SHOT, // 0xF8
    SOUND_MISSILE_THRUST, // 0xF9
    SOUND_MISSILE_EXPLOSION, // 0xFA

    SOUND_SUPER_MISSILE_SHOT, // 0xFB
    SOUND_SUPER_MISSILE_THRUST, // 0xFC
    SOUND_SUPER_MISSILE_EXPLOSION, // 0xFD

    SOUND_BOMB_SET, // 0xFE
    SOUND_BOMB_EXPLOSION, // 0xFF
    SOUND_POWER_BOMB_SET, // 0x100
    SOUND_POWER_BOMB_EXPLOSION, // 0x101

    SOUND_BEAM_IMPACT, // 0x102
    SOUND_LONG_BEAM_IMPACT, // 0x103
    SOUND_ICE_BEAM_IMPACT, // 0x104
    SOUND_WAVE_BEAM_IMPACT, // 0x105
    SOUND_PLASMA_BEAM_IMPACT, // 0x106
    SOUND_INVINCIBLE_IMPACT, // 0x107

    SOUND_108, // 0x108

    SOUND_SECURITY_GATE_CLOSING, // 0x109
    SOUND_SECURITY_LASER_TRIPPED, // 0x10A
    SOUND_CHOZO_PILLAR_FALLING, // 0x10B

    SOUND_DOOR_OPENING, // 0x10C
    SOUND_DOOR_CLOSING, // 0x10D

    SOUND_ELEVATOR, // 0x10E

    SOUND_CHOZO_STATUE_REFILL, // 0x10F
    SOUND_ZIPLING_MOVING, // 0x110
    SOUND_ZIPLING_CALLED, // 0x111
    SOUND_SAVE_PLATFORM_OPENING, // 0x112
    SOUND_SAVE_PLATFORM_CLOSING, // 0x113
    SOUND_SAVING, // 0x114
    SOUND_SAVE_PLATFORM_RETRACTING, // 0x115
    SOUND_DOORS_UNLOCKING, // 0x116
    SOUND_DOORS_LOCKING, // 0x117
    SOUND_GUNSHIP_OPENING, // 0x118
    SOUND_GUNSHIP_CLOSING, // 0x119
    SOUND_GUNSHIP_PLATFORM_MOVING, // 0x11A
    SOUND_CHOZO_STATUE_HINT, // 0x11B
    SOUND_CHOZO_STATUE_SITTING_DOWN, // 0x11C
    SOUND_CHOZO_BALL_REVEALING, // 0x11D

    SOUND_KRAID_ELEVATOR_STATUE_CRUMBLING, // 0x11E
    SOUND_RIDLEY_ELEVATOR_STATUE_CRUMBLING, // 0x11F

    SOUND_ESCAPE_BEEP, // 0x120
    SOUND_RAIN, // 0x121
    SOUND_RAIN_HITTING_GROUND, // 0x122

    SOUND_USING_MAP_STATION, // 0x123
    SOUND_MAP_STATION_RETRACTING, // 0x124
    SOUND_RISING_CHOZO_PILLAR_RISING, // 0x125
    SOUND_RISING_CHOZO_PILLAR_PLATFORM_SPAWNING, // 0x126

    SOUND_CHOZODIA_SAVE_PLATFORM_OPENING, // 0x127
    SOUND_CHOZODIA_SAVE_PLATFORM_CLOSING, // 0x128
    SOUND_CHOZODIA_SAVE_PLATFORM_REFILL, // 0x129

    SOUND_BOSS_STATUES_EYE_TURNING_ON, // 0x12A
    SOUND_BOSS_STATUES_KRAID_STATUE_OPENING, // 0x12B

    SOUND_SPRITE_EXPLOSION_SMALL, // 0x12C
    SOUND_SPRITE_EXPLOSION_MEDIUM, // 0x12D
    SOUND_SPRITE_EXPLOSION_BIG, // 0x12E
    SOUND_SPRITE_EXPLOSION_SINGLE_THEN_BIG, // 0x12F
    SOUND_SCREW_ATTACK_DESTROYED, // 0x130
    SOUND_SHINESPARK_DESTROYED, // 0x131
    SOUND_SUDO_SCREW_DESTROYED, // 0x132
    SOUND_SPEEDBOOSTER_DESTROYED, // 0x133

    SOUND_SKREE_EXPLODING, // 0x134

    SOUND_BLOCK_DESTROYED_WITH_SPEEDBOOSTER, // 0x135
    SOUND_BOMB_CHAIN, // 0x136
    SOUND_SQUARE_BLOCK_DESTROYED, // 0x137

    SOUND_138, // 0x138
    SOUND_BLOCK_DESTROYED_WITH_SCREW_ATTACK, // 0x139

    SOUND_DESSGEEGA_DESTROYING_FLOOR, // 0x13A
    SOUND_UNKNOWN_ITEM_BLOCK_BREAKING, // 0x13B

    SOUND_13C, // 0x13C
    SOUND_13D, // 0x13D
    SOUND_13E, // 0x13E
    SOUND_13F, // 0x13F

    SOUND_FREEZING_SPRITE, // 0x140

    SOUND_SKREE_GOING_DOWN, // 0x141
    SOUND_SKREE_CRASHING, // 0x142
    SOUND_SKREE_DAMAGED, // 0x143

    SOUND_ZEB_RISING, // 0x144
    SOUND_ZEB_MOVING, // 0x145
    SOUND_ZEB_DAMAGED, // 0x146

    SOUND_ZOOMER_DAMAGED, // 0x147
    SOUND_ZEELA_DAMAGED, // 0x148

    SOUND_RIPPER_DAMAGED, // 0x149

    SOUND_14A, // 0x14A
    SOUND_14B, // 0x14A

    SOUND_DRAGON_SPITTING, // 0x14C
    SOUND_DRAGON_DAMAGED, // 0x14D

    SOUND_GERUTA_GOING_DOWN, // 0x14E
    SOUND_GERUTA_GOING_UP, // 0x14F
    SOUND_GERUTA_WARNING, // 0x150
    SOUND_GERUTA_DAMAGED, // 0x151

    SOUND_MULTIVIOLA_BOUNCING, // 0x152
    SOUND_MULTIVIOLA_DAMAGED, // 0x153

    SOUND_SOVA_DAMAGED, // 0x154

    SOUND_SQUEEPT_LEAVING_LAVA, // 0x155
    SOUND_SQUEEPT_ENTERING_LAVA, // 0x156
    SOUND_SQUEEPT_DAMAGED, // 0x157

    SOUND_REO_MOVING, // 0x158
    SOUND_REO_DAMAGED, // 0x159

    SOUND_DESSGEEGA_JUMPING, // 0x15A
    SOUND_DESSGEEGA_LANDING, // 0x15B
    SOUND_DESSGEEGA_SCREAMING, // 0x15C
    SOUND_DESSGEEGA_DAMAGED, // 0x15D

    SOUND_MELLOW_MOVING, // 0x15E
    SOUND_MELLOW_DAMAGED, // 0x15F
    SOUND_HIVE_SHRINKING, // 0x160
    SOUND_HIVE_DEAD, // 0x161

    SOUND_ZEBBO_RISING, // 0x162
    SOUND_ZEBBO_MOVING, // 0x163
    SOUND_ZEBBO_DAMAGED, // 0x164

    SOUND_SPACE_PIRATE_FOOTSTEPS, // 0x165
    SOUND_SPACE_PIRATE_JUMPING, // 0x166
    SOUND_SPACE_PIRATE_LANDING, // 0x167
    SOUND_SPACE_PIRATE_FIRING_LASER, // 0x168
    SOUND_SPACE_PIRATE_GETTING_ALERTED, // 0x169
    SOUND_SPACE_PIRATE_DYING, // 0x16A
    SOUND_SPACE_PIRATE_CRAWLING, // 0x16B
    SOUND_SPACE_PIRATE_CLIMBING, // 0x16C

    SOUND_METROID_SUCKING_NO_SUIT, // 0x16D
    SOUND_METROID_SUCKING_ONE_SUIT, // 0x16E
    SOUND_METROID_SUCKING_ALL_SUITS, // 0x16F
    SOUND_METROID_MOVING, // 0x170
    SOUND_METROID_DETACHED, // 0x171
    SOUND_METROID_DAMAGED, // 0x172

    SOUND_PISTON_EXTENDING, // 0x173

    SOUND_PARASITE_JUMPING_1, // 0x174
    SOUND_PARASITE_JUMPING_2, // 0x175
    SOUND_PARASITE_JUMPING_3, // 0x176

    SOUND_WAVER_DAMAGED, // 0x177

    SOUND_VIOLA_DAMAGED, // 0x178

    SOUND_GAMET_RISING, // 0x179
    SOUND_GAMET_MOVING, // 0x17A
    SOUND_GAMET_DAMAGED, // 0x17B

    SOUND_POLYP_WARNING, // 0x17C
    SOUND_POLYP_SPITTING, // 0x17D
    SOUND_POLYP_PROJECTILE_EXPLODING, // 0x17E

    SOUND_SIDEHOPPER_JUMPING, // 0x17F
    SOUND_SIDEHOPPER_LANDING, // 0x180
    SOUND_SIDEHOPPER_SHAKING_HEAD, // 0x181
    SOUND_SIDEHOPPER_DAMAGED, // 0x182

    SOUND_GEEGA_RISING, // 0x183
    SOUND_GEEGA_MOVING, // 0x184
    SOUND_GEEGA_DAMAGED, // 0x185

    SOUND_HOLTZ_GOING_DOWN, // 0x186
    SOUND_HOLTZ_GOING_UP, // 0x187
    SOUND_HOLTZ_DAMAGED, // 0x188

    SOUND_MELLA_MOVING, // 0x189
    SOUND_18A, // 0x18A
    SOUND_MELLA_DAMAGED, // 0x18B

    SOUND_BARISTUTE_JUMP_WARNING, // 0x18C
    SOUND_BARISTUTE_JUMPING, // 0x18D
    SOUND_BARISTUTE_LANDING, // 0x18E
    SOUND_BARISTUTE_MOVING_SLOW, // 0x18F

    SOUND_190, // 0x190
    SOUND_DEOREM_SPAWN_GOING_DOWN, // 0x191
    SOUND_DEOREM_LEAVING, // 0x192
    SOUND_DEOREM_MOVING, // 0x193
    SOUND_DEOREM_MOVEMENT_SMALL, // 0x194
    SOUND_DEOREM_RETRACTED, // 0x195
    SOUND_DEOREM_THROWING_THORNS, // 0x196
    SOUND_DEOREM_THORN_EJECTING, // 0x197
    SOUND_DEOREM_OPENING_JAW, // 0x198
    SOUND_DEOREM_CLOSING_JAW, // 0x199
    SOUND_DEOREM_CLOSING_JAW_FAST, // 0x19A
    SOUND_DEOREM_DYING, // 0x19B
    SOUND_DEOREM_SCREAMING, // 0x19C
    SOUND_DEOREM_WARNING, // 0x19D
    SOUND_DEOREM_MOVEMENT_LONG, // 0x19E

    SOUND_IMAGO_COCOON_IDLE, // 0x19F
    SOUND_IMAGO_COCOON_SPORE_SPAWNING, // 0x1A0
    SOUND_IMAGO_COCOON_SPORE_NEST_SPAWNING, // 0x1A1
    SOUND_IMAGO_COCOON_VINE_DAMAGED, // 0x1A2
    SOUND_IMAGO_COCOON_VINES_CRACKING, // 0x1A3
    SOUND_IMAGO_COCOON_DESTROYING_BLOCKS, // 0x1A4
    SOUND_IMAGO_COCOON_CRASHING, // 0x1A5
    SOUND_IMAGO_COCOON_IN_GROUND, // 0x1A6

    SOUND_ACID_WORM_DESTROYING_BLOCKS, // 0x1A7
    SOUND_ACID_WORM_STRAIGHT_EXTEND, // 0x1A8
    SOUND_ACID_WORM_STRAIGHT_GOING_DOWN, // 0x1A9
    SOUND_ACID_WORM_SCREAM, // 0x1AA
    SOUND_ACID_WORM_EXTEND_TO_SPIT, // 0x1AB
    SOUND_ACID_WORM_RETRACT_FROM_SPIT, // 0x1AC
    SOUND_ACID_WORM_EXTEND_SLOW, // 0x1AD
    SOUND_ACID_WORM_EXTEND_NORMAL, // 0x1AE
    SOUND_ACID_WORM_EXTEND_FAST, // 0x1AF
    SOUND_ACID_WORM_RETRACT, // 0x1B0
    SOUND_ACID_WORM_CRASHING_SLOW, // 0x1B1
    SOUND_ACID_WORM_CRASHING_NORMAL, // 0x1B2
    SOUND_ACID_WORM_CRASHING_FAST, // 0x1B3
    SOUND_ACID_WORM_HOOKED_ON_BLOCK, // 0x1B4
    SOUND_ACID_WORM_OPENING_MOUTH, // 0x1B5
    SOUND_ACID_WORM_OPENING_MOUTH_TO_SPIT, // 0x1B6
    SOUND_ACID_WORM_SPITTING, // 0x1B7
    SOUND_ACID_WORM_SPIT_EXPLODING, // 0x1B8
    SOUND_ACID_WORM_RAISING_ACID, // 0x1B9
    SOUND_ACID_WORM_LOWERING_ACID, // 0x1BA
    SOUND_ACID_WORM_SPLASHING, // 0x1BB
    SOUND_ACID_WORM_HURT, // 0x1BC
    SOUND_ACID_WORM_DYING, // 0x1BD
    SOUND_ACID_WORM_DEAD, // 0x1BE

    SOUND_KRAID_RISING, // 0x1BF
    SOUND_KRAID_LEFT_ARM_DYING_1, // 0x1C0
    SOUND_KRAID_LEFT_ARM_DYING_2, // 0x1C1
    SOUND_KRAID_RIGHT_ARM_DYING_1, // 0x1C2
    SOUND_KRAID_RIGHT_ARM_DYING_2, // 0x1C3
    SOUND_KRAID_LEFT_ARM_ATTACKING_1, // 0x1C4
    SOUND_KRAID_LEFT_ARM_ATTACKING_2, // 0x1C5
    SOUND_KRAID_LEFT_ARM_ATTACKING_3, // 0x1C6
    SOUND_KRAID_SPIKE_SPAWNING, // 0x1C7
    SOUND_KRAID_SPIKE_EMERGING, // 0x1C8
    SOUND_KRAID_SPIKE_DESTROYING_PLATFORM, // 0x1C9
    SOUND_KRAID_SPIKE_DESTROYING_BLOCKS, // 0x1CA
    SOUND_KRAID_SPIKE_HITTING_WALL, // 0x1CB
    SOUND_KRAID_STOMPING_FEET, // 0x1CC
    SOUND_1CD, // 0x1CD
    SOUND_KRAID_OPENING_MOUTH, // 0x1CE
    SOUND_KRAID_DAMAGED, // 0x1CF
    SOUND_KRAID_DYING_1, // 0x1D0
    SOUND_KRAID_DYING_2, // 0x1D1
    SOUND_KRAID_DYING_3, // 0x1D2

    SOUND_RUINS_TEST_SPAWNING, // 0x1D3
    SOUND_RUINS_TEST_SYMBOLS_MERGING, // 0x1D4
    SOUND_RUINS_TEST_TURNING_INTO_FIRST_REFLECTION, // 0x1D5
    SOUND_RUINS_TEST_OUTLINE_SPAWNING, // 0x1D6
    SOUND_RUINS_TEST_GHOST_SPANWING, // 0x1D7
    SOUND_RUINS_TEST_SHOOTABLE_SYMBOL, // 0x1D8
    SOUND_RUINS_TEST_SHOOTABLE_SYMBOL_SHOT, // 0x1D9
    SOUND_RUINS_TEST_SYMBOL_PLACED, // 0x1DA
    SOUND_RUINS_TEST_LIGHTNING_WARNING, // 0x1DB
    SOUND_RUINS_TEST_SHOOTING_LIGHTNING, // 0x1DC
    SOUND_RUINS_TEST_STATIC_LIGHTNING_HITTING_GROUND, // 0x1DD
    SOUND_RUINS_TEST_GROUND_LIGHTNING_MOVING, // 0x1DE
    SOUND_RUINS_TEST_GHOST_FADING_OUT, // 0x1DF
    SOUND_RUINS_TEST_SYMBOLS_LIGHTING_UP, // 0x1E0

    SOUND_RIDLEY_WINGS_FLAPPING, // 0x1E1
    SOUND_RIDLEY_WINGS_FLAPPING_FAST, // 0x1E2
    SOUND_RIDLEY_GRABBING_SAMUS, // 0x1E3
    SOUND_RIDLEY_LIFTING_SAMUS, // 0x1E4
    SOUND_RIDLEY_OPENING_MOUTH, // 0x1E5
    SOUND_RIDLEY_HITTING_GROUND, // 0x1E6
    SOUND_RIDLEY_SPITTING_FIREBALLS, // 0x1E7
    SOUND_RIDLEY_SPITTING_FIREBALLS_ON_SAMUS, // 0x1E8
    SOUND_RIDLEY_SPITTING_BIG_FIREBALLS, // 0x1E9
    SOUND_RIDLEY_TAIL_SPINNING, // 0x1EA
    SOUND_RIDLEY_TAIL_DIAGONAL_SWIPE, // 0x1EB
    SOUND_RIDLEY_TAIL_VERTICAL_SWIPE, // 0x1EC
    SOUND_RIDLEY_DAMAGED, // 0x1ED
    SOUND_RIDLEY_DYING_1, // 0x1EE
    SOUND_RIDLEY_DYING_2, // 0x1EF
    SOUND_RIDLEY_TAIL_DYING, // 0x1F0
    SOUND_RIDLEY_FIREBALL_EXPLODING, // 0x1F1
    SOUND_RIDLEY_EXPLODING_GROUND, // 0x1F2

    SOUND_1F3, // 0x1F3

    SOUND_OPENING_STATUS_SCREEN, // 0x1F4
    SOUND_LEAVING_STATUS_SCREEN, // 0x1F5
    SOUND_STATUS_SCREEN_CURSOR_MOVING, // 0x1F6
    SOUND_TOGGLING_ITEM_ON, // 0x1F7
    SOUND_TOGGLING_ITEM_OFF, // 0x1F8

    SOUND_MENU_CURSOR, // 0x1F9
    SOUND_SUB_MENU_CURSOR, // 0x1FA
    SOUND_FILE_SELECT, // 0x1FB
    SOUND_ACCEPT_CONFIRM_MENU, // 0x1FC
    SOUND_OPEN_SUB_MENU, // 0x1FD
    SOUND_CLOSE_SUB_MENU, // 0x1FE
    SOUND_START_GAME, // 0x1FF
    SOUND_MOVING_MAP, // 0x200
    SOUND_MOVING_MAP_MUFFLED, // 0x201
    SOUND_OPENING_WORLD_MAP, // 0x202
    SOUND_CLOSING_WORLD_MAP, // 0x203
    SOUND_MAP_SCREEN_CHANGE_MAP, // 0x204
    SOUND_OPENING_EASY_SLEEP_SCREEN, // 0x205
    SOUND_CLOSING_EASY_SLEEP_SCREEN, // 0x206
    SOUND_YES_NO_CURSOR_MOVING, // 0x207
    SOUND_YES_NO_CURSOR_SELECTING_YES, // 0x208
    SOUND_REFUSE_MENU, // 0x209
    SOUND_FILE_SELECT_COPY_DELETE, // 0x20A
    SOUND_FILE_SELECT_COPY_MOVING, // 0x20B
    SOUND_FILE_SELECT_COPY_CONFIRM, // 0x20C
    SOUND_FILE_DELETE, // 0x20D
    SOUND_SOUND_TEST_CURSOR_MOVING, // 0x20E
    SOUND_UNKNOWN_ITEM_ACQUISITION, // 0x20F
    SOUND_SELECTING_FILE_TO_DELETE, // 0x210
    SOUND_CHANGE_TIME_ATTACK_PANEL, // 0x211

    SOUND_IMAGO_COCOON_IN_GROUND_IDLE, // 0x212

    SOUND_TITLE_SCREEN_PRESSING_START, // 0x213
    SOUND_ENABLING_UNKNOWN_ITEM, // 0x214
    SOUND_ENABLING_NORMAL_ITEM, // 0x215

    SOUND_216, // 0x216
    SOUND_217, // 0x217
    SOUND_218, // 0x218
    SOUND_219, // 0x219
    SOUND_21A, // 0x21A
    SOUND_21B, // 0x21B

    SOUND_BOSS_STATUES_RIDLEY_STATUE_OPENING, // 0x21C
    SOUND_ACTIVATING_ZIPLINES, // 0x21D

    SOUND_GUNSHIP_REFILL, // 0x21E
    SOUND_GUNSHIP_SAVING, // 0x21F

    SOUND_DESSGEEGA_LONG_BEAM_SPAWNING, // 0x220
    SOUND_DEOREM_SPAWNING_CHARGE_BEAM, // 0x221

    SOUND_ACQUIRING_VARIA, // 0x222
    SOUND_ACQUIRING_GRAVITY, // 0x223

    SOUND_224, // 0x224

    SOUND_SECURITY_GATE_OPENING, // 0x225

    SOUND_INTRO_TEXT_LETTER, // 0x226
    SOUND_INTRO_SHIP_FLYING_TOWARDS_CAMERA, // 0x227
    SOUND_INTRO_SHIP_INTERIOR, // 0x228
    SOUND_INTRO_SHIP_FLYING_DOWN, // 0x229
    SOUND_INTRO_MOTHER_BRAIN_JAR, // 0x22A
    SOUND_INTRO_FUZZ, // 0x22B

    SOUND_KRAID_RISING_EYES_OPENING, // 0x22C
    SOUND_KRAID_RISING_SCREAMS, // 0x22D

    SOUND_MOTHER_BRAIN_CLOSE_UP_BUBBLES, // 0x22E
    SOUND_MOTHER_BRAIN_CLOSE_UP_EYE_OPENING, // 0x22F
    SOUND_MOTHER_BRAIN_CLOSE_UP_EYE_FOCUSING, // 0x230

    SOUND_STATUE_OPENING_STATUE_ACTIVATING, // 0x231
    SOUND_GUNSHIP_LANDING, // 0x232
    SOUND_INTRO_TEXT_LANDING, // 0x233
    SOUND_GUNSHIP_FLYING_OFF, // 0x234

    SOUND_TOURIAN_ESCAPE_SAMUS_FLYING_IN, // 0x235
    SOUND_TOURIAN_ESCAPE_SAMUS_FLEEING_RIGHT_TO_LEFT, // 0x236
    SOUND_TOURIAN_ESCAPE_SAMUS_FLEEING_LEFT_TO_RIGHT, // 0x237
    SOUND_TOURIAN_ESCAPE_PIRATES_CHASING_RIGHT_TO_LEFT, // 0x238
    SOUND_TOURIAN_ESCAPE_PIRATES_CHASING_LEFT_TO_RIGHT, // 0x239
    SOUND_TOURIAN_ESCAPE_SAMUS_DODGING_SHOTS, // 0x23A
    SOUND_TOURIAN_ESCAPE_SAMUS_FLYING_AFTER_SHOTS, // 0x23B
    SOUND_TOURIAN_ESCAPE_DECISIVE_SHOT, // 0x23C
    SOUND_TOURIAN_ESCAPE_SHIP_FREE_FALLING, // 0x23D
    SOUND_TOURIAN_ESCAPE_FIRST_ROOM_EXPLODING, // 0x23E
    SOUND_23F, // 0x23F
    SOUND_TOURIAN_ESCAPE_OTHER_ROOMS_EXPLODING, // 0x240
    SOUND_241, // 0x241
    SOUND_242, // 0x242
    SOUND_243, // 0x243
    SOUND_TOURIAN_ESCAPE_SAMUS_LEAVING_PLANET, // 0x244
    SOUND_TOURIAN_ESCAPE_SAMUS_REMOVING_SUIT_1, // 0x245
    SOUND_TOURIAN_ESCAPE_SAMUS_REMOVING_SUIT_2, // 0x246
    SOUND_TOURIAN_ESCAPE_SAMUS_REMOVING_SUIT_3, // 0x247
    SOUND_TOURIAN_ESCAPE_PIRATES_FIRING, // 0x248
    SOUND_TOURIAN_ESCAPE_SAMUS_CRASHING_FALLING, // 0x249
    SOUND_TOURIAN_ESCAPE_SAMUS_CRASHING_COLLISION, // 0x24A
    SOUND_TOURIAN_ESCAPE_PIRATES_FLYING_OVER, // 0x24B

    SOUND_RIDLEY_SPAWN_ROAR, // 0x24C

    SOUND_ESCAPE_GATE_OPENING, // 0x24D
    SOUND_ESCAPE_SHIP_OPENING, // 0x24E
    SOUND_ESCAPE_SHIP_CLOSING, // 0x24F
    SOUND_ESCAPE_SHIP_FLYING, // 0x250
    SOUND_ESCAPE_SHIP_SHUTTER_OPENING, // 0x251
    SOUND_ESCAPE_SHIP_FLYING_FAST, // 0x252

    SOUND_BLUE_SHIP_TURNING_ON, // 0x253
    SOUND_BLUE_SHIP_POWERING_UP, // 0x254

    SOUND_CHOZODIA_ESCAPE_MOTHER_SHIP_DOOR_OPENING, // 0x255
    SOUND_CHOZODIA_ESCAPE_BLUE_SHIP_TAKING_OFF, // 0x256
    SOUND_CHOZODIA_ESCAPE_MOTHER_SHIP_HEATING_UP, // 0x257

    SOUND_BARISTUTE_MOVING_FAST, // 0x258
    SOUND_BARISTUTE_DAMAGED, // 0x259

    SOUND_GADORA_OPENING_EYE, // 0x25A
    SOUND_GADORA_CLOSING_EYE, // 0x25B
    SOUND_GADORA_BEAM_EMERGING, // 0x25C
    SOUND_GADORA_BEAM_MOVING, // 0x25D
    SOUND_GADORA_EYE_DAMAGED, // 0x25E

    SOUND_SPACE_PIRATE_LASER_EXPLODING, // 0x25F

    SOUND_260, // 0x260
    SOUND_ATOMIC_ELECTRICITY_SHOOTING, // 0x261
    SOUND_ATOMIC_ELECTRICITY_EXPLODING, // 0x262
    SOUND_ATOMIC_DAMAGED, // 0x263

    SOUND_TANGLE_VINE_DAMAGE, // 0x264

    SOUND_ZEBETITE_HURT_1, // 0x265
    SOUND_ZEBETITE_HURT_2, // 0x266

    SOUND_RIPPER2_TURNING_AROUND, // 0x267
    SOUND_RIPPER2_DAMAGED, // 0x268

    SOUND_SKULTERA_TURNING_AROUND, // 0x269
    SOUND_SKULTERA_DAMAGED, // 0x26A

    SOUND_GERON_SHAKING, // 0x26B
    SOUND_GERON_BREAKING, // 0x26C

    SOUND_SEARCHLIGHT_EYE_PROJECTILE_EMERGING, // 0x26D

    SOUND_WORKER_ROBOT_FOOTSTEPS, // 0x26E
    SOUND_WORKER_ROBOT_WAKING_UP, // 0x26F
    SOUND_WORKER_ROBOT_FALLING_ASLEEP, // 0x270
    SOUND_WORKER_ROBOT_LANDING, // 0x271

    SOUND_272, // 0x272
    SOUND_273, // 0x273
    SOUND_274, // 0x274
    SOUND_275, // 0x275

    SOUND_ZEBES_ESCAPE_EXPLOSION_3, // 0x276
    SOUND_ZEBES_ESCAPE_EXPLOSION_4, // 0x277

    SOUND_STEAM_LARGE, // 0x278
    SOUND_STEAM_SMALL, // 0x279

    SOUND_GLASS_TUBE_BREAKING, // 0x27A

    SOUND_27B, // 0x27B
    SOUND_27C, // 0x27C
    SOUND_27D, // 0x27D
    SOUND_27E, // 0x27E
    SOUND_27F, // 0x27F
    SOUND_280, // 0x280
    SOUND_281, // 0x281
    SOUND_282, // 0x282
    SOUND_283, // 0x283
    SOUND_284, // 0x284
    SOUND_285, // 0x285
    SOUND_286, // 0x286
    SOUND_287, // 0x287
    SOUND_288, // 0x288
    SOUND_289, // 0x289
    SOUND_28A, // 0x28A

    SOUND_CHOZODIA_ESCAPE_MOTHER_SHIP_BLOWING_AURA, // 0x28B
    SOUND_CHOZODIA_ESCAPE_MOTHER_SHIP_BLOWING_UP, // 0x28C

    SOUND_RIDLEY_IN_SPACE_SHIPS_APPEARING, // 0x28D
    SOUND_RIDLEY_IN_SPACE_MOTHER_SHIP_FLYING, // 0x28E

    SOUND_RIDLEY_LANDING_SHIP_FLYING, // 0x28F
    SOUND_RIDLEY_LANDING_SHIP_LOWERING, // 0x290
    SOUND_RIDLEY_LANDING_SHIP_LANDING, // 0x291
    SOUND_RIDLEY_LANDING_RIDLEY_SCREAMING, // 0x292

    SOUND_MECHA_SEES_SAMUS_EYE_OPENING, // 0x293
    SOUND_MECHA_SEES_SAMUS_EYE_FOCUSING, // 0x294

    SOUND_ENTER_TOURIAN_METROIDS_SUCKING, // 0x295
    SOUND_ENTER_TOURIAN_METROIDS_FLYING, // 0x296
    SOUND_ENTER_TOURIAN_METROID_JUMPSCARE, // 0x297

    SOUND_298, // 0x298
    SOUND_299, // 0x299
    SOUND_29A, // 0x29A
    SOUND_29B, // 0x29B
    SOUND_29C, // 0x29C
    SOUND_29D, // 0x29D

    SOUND_MECHA_RIDLEY_CLAW_ATTACK, // 0x29E
    SOUND_MECHA_RIDLEY_CRAWLING_BACKWARDS, // 0x29F
    SOUND_MECHA_RIDLEY_ARM_SWIPE_HITTING_GROUND, // 0x2A0
    SOUND_MECHA_RIDLEY_NECK_LOW_TO_HIGH, // 0x2A1
    SOUND_MECHA_RIDLEY_NECK_HIGH_TO_LOW, // 0x2A2
    SOUND_MECHA_RIDLEY_HOLDING_UP_ARM, // 0x2A3
    SOUND_MECHA_RIDLEY_ARM_SWIPE_PREPARING, // 0x2A4
    SOUND_MECHA_RIDLEY_ARM_SWIPE, // 0x2A5
    SOUND_MECHA_RIDLEY_OPENING_MISSILE_LAUNCHER, // 0x2A6
    SOUND_MECHA_RIDLEY_FIRING_MISSILE_LAUNCHER, // 0x2A7
    SOUND_MECHA_RIDLEY_OPENING_MOUTH, // 0x2A8
    SOUND_MECHA_RIDLEY_SPITTING_FIREBALL, // 0x2A9
    SOUND_MECHA_RIDLEY_PREPARING_LASER, // 0x2AA
    SOUND_MECHA_RIDLEY_NECK_MIDDLE_UP_MOVEMENT, // 0x2AB
    SOUND_MECHA_RIDLEY_NECK_MIDDLE_DOWN_MOVEMENT, // 0x2AC
    SOUND_2AD, // 0x2AD
    SOUND_MECA_RIDLEY_POWERING_OFF, // 0x2AE
    SOUND_MECHA_RIDLEY_DAMAGED, // 0x2AF
    SOUND_MECHA_RIDLEY_DEATH_EXPLOSIONS, // 0x2B0
    SOUND_MECHA_RIDLEY_EYE_BEEPING, // 0x2B1
    SOUND_MECHA_RIDLEY_RIGHT_ARM_CRAWLING, // 0x2B2
    SOUND_MECHA_RIDLEY_ENTRANCE_CRAWL, // 0x2B3
    SOUND_MECHA_RIDLEY_FIREBALL_EXPLODING, // 0x2B4

    SOUND_MOTHER_BRAIN_JAR_DAMAGE_1, // 0x2B5
    SOUND_MOTHER_BRAIN_JAR_DAMAGE_2, // 0x2B6
    SOUND_MOTHER_BRAIN_JAR_DAMAGE_3, // 0x2B7
    SOUND_MOTHER_BRAIN_JAR_SHATTER, // 0x2B8
    SOUND_MOTHER_BRAIN_EYE_OPENING, // 0x2B9
    SOUND_MOTHER_BRAIN_EYE_CLOSING, // 0x2BA
    SOUND_MOTHER_BRAIN_CHARGING, // 0x2BB
    SOUND_MOTHER_BRAIN_SHOOTING, // 0x2BC
    SOUND_MOTHER_BRAIN_IDLE, // 0x2BD
    SOUND_MOTHER_BRAIN_DAMAGED, // 0x2BE
    SOUND_MOTHER_BRAIN_DYING, // 0x2BF
    SOUND_MOTHER_BRAIN_DEATH_EXPLOSION, // 0x2C0

    SOUND_MECHA_RIDLEY_LASER_EXPLODING, // 0x2C1
    SOUND_MECHA_RIDLEY_MISSILE_EXPLODING, // 0x2C2

    SOUND_MOTHER_BRAIN_LASER_EXPLODING, // 0x2C3


    SOUND_END
};

#endif /* AUDIO_CONSTANTS_H */
