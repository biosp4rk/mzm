## Randomizer
- ~~Title screen version info~~
- Draw hash on file select
- Add pointers to all palettes that can be randomized

Original ASM:
- ~~anim_gfx~~
- data
  - ~~anim_gfx_entries.bin~~
  - anim_tileset_entries.bin
  - clipdata_behavior_types.bin
  - clipdata_behavior_types_400.bin
  - clipdata_collision_types.bin
  - clipdata_collision_types_400.bin
  - tank_collection_info.bin
  - tile_table_400.bin
  - tileset_entries.bin
- unk_items
- abilities.asm
- assign_item.asm
- clipdata_new.asm
- items_new.asm
- ~~misc.asm~~
  - "modify code that checks for hidden tanks"
  - "fix call to RemoveCollectedAbility"
- random_items.asm
- tile_table_lengths.asm (store these in the patcher)
- tilesets_new.asm
- touching_tank.asm

## Fixes
- ~~Disable Varia animation~~
- ~~Fix charge beam OAM~~
- ~~Allow chozo hints in any area~~
- Add event for Ruins Test defeated and fix checks for fully powered suit

## Room Changes
- Remove duplicate rooms near Ruins Test

## QoL
- ~~Enable item toggle~~
- ~~Map screen info~~

## Options
- Disable chozo hints?
- ~~Remove cutscenes~~
- ~~Skip door transitions~~
- ~~Skip suitless sequence~~
- Obtain unknown items
- ~~Use ball launchers without bombs~~
- ~~Disable wall jump~~
- ~~Disable infinite bomb jump~~
- ~~New file difficulty options~~
