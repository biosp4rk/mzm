## Randomizer
- ~~Title screen version info~~
- Draw hash on file select
- Add pointers to data needed by patcher
  - Palettes
  - Room data
  - Door data (DLR)
  - Minimap data (DLR)
- Custom item messages
- ~~Major locations having any item~~
- ~~Allow getting ziplines as an item~~
- Allow getting item from zipline source
- Allow getting item from ruins test
- Support infant metroid items
- Starting items
- Starting location
- Add separate normal and varia palettes for full suit

Original ASM:
- data
  - anim_tileset_entries.bin (add extra blank animated tilesets)
  - tileset_entries.bin (add extra blank tilesets)
- unk_items
- abilities.asm
- assign_item.asm
- clipdata_new.asm
- items_new.asm
- random_items.asm
- tile_table_lengths.asm (store these in the patcher)
- tilesets_new.asm
- touching_tank.asm

## Fixes
- ~~Disable Varia animation~~
- ~~Fix charge beam OAM~~
- ~~Allow chozo hints in any area~~
- ~~Fix minimap updating twice when grabbing an ability at a minor location~~
- ~~Fix Samus not getting stopped when getting full suit~~
- ~~Fix obtaining unknown items~~
  - ~~Display "unknown item" if not full suit when text is loaded~~
  - ~~Don't play sound effect on status screen if full suit~~

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
