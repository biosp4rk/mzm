## Randomizer
- ~~Title screen version info~~
- Draw hash on file select
- Add pointers to data needed by patcher
  - Palettes
  - Room data
  - Door data (DLR)
  - Minimap data (DLR)
- ~~Custom item messages~~
- ~~Hints for any item~~
- ~~Major locations having any item~~
- ~~Allow getting ziplines as an item~~
- ~~Allow getting item from zipline source~~
- ~~Allow getting item from ruins test~~
- Support infant metroid items?
- ~~Starting items~~
  - ~~Set hint events here for statues that don't have hints~~
- ~~Starting location~~
- Add separate normal and varia palettes for full suit
- Rooms names
- Custom credits text
- Ice trap item
- Allow negative tank increments

Original ASM:
- data
  - anim_tileset_entries.bin (add extra blank animated tilesets)
  - tileset_entries.bin (add extra blank tilesets)
- ~~tile_table_lengths.asm (store these in array in rom and add pointer to it)~~

## Fixes
- ~~Disable Varia animation~~
- ~~Fix charge beam OAM~~
- ~~Allow chozo hints in any area~~
- ~~Fix minimap updating twice when grabbing an ability at a minor location~~
- ~~Fix Samus not getting stopped when getting full suit~~
- ~~Fix obtaining unknown items~~
  - ~~Display "unknown item" if not full suit when text is loaded~~
  - ~~Don't play sound effect on status screen if full suit~~
  - Replace Chozo statue graphics
- ~~Fix ending percent calculation~~
- Include bug fixes for bugs that don't help speedrunners

## Room Changes
- Remove duplicate rooms near Ruins Test?

## QoL
- ~~Enable item toggle~~
- ~~Map screen info~~

## Options
- ~~Remove cutscenes~~
- ~~Skip door transitions~~
- ~~Skip suitless sequence~~
- Obtain unknown items?
- ~~Use ball launchers without bombs~~
- ~~Disable wall jump~~
- ~~Disable infinite bomb jump~~
- ~~New file difficulty options~~
- Default stereo
