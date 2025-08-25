## Randomizer
- Support showing text on title screen
  - `TitleScreenInit` in [title_screen.c](src\menus\title_screen.c)
- Disable title screen demos (to avoid spoilers)
  - `TitleScreenCheckPlayEffects` in [title_screen.c](src/menus/title_screen.c)

## Fixes
- Allow laying power bombs without bombs
  - `SamusCheckNewProjectile` in [samus.c](src/samus.c)
  - `StatusScreenSetBombsVisibility` and `StatusScreenToggleItem` in [status_screen.c](src/menus/status_screen.c)
- Disable varia animation
  - `RoomLoad` in [room.c](src/room.c)
- Don't give varia automatically when getting fully powered suit
  - `ColorFadingProcess_GettingFullyPowered` in [room.c](src/color_fading.c)
  - `PauseScreenGetMinimapData` in [pause_screen.c](src\menus\pause_screen.c)
- Allow Chozo hints in all areas
  - `sElevatorRoomPairs` in [clipdata_data.c](src\data\clipdata_data.c)
  - `sMapScreenChozoStatueAreaNamesEnglishGfx` in [pause_screen_data.c](src\data\menus\pause_screen_data.c)
  - `sChozoStatueTargetPathBrinstar` and `sChozoStatueTargetPathNorfair` in [pause_screen_sub_menus_data.c](src\data\menus\pause_screen_sub_menus_data.c)
- Change charge beam OAM to work with any item (and don't spawn glow)
  - `ChargeBeamSpawnGlow`, `ChargeBeamVisibleInit`, and `ChargeBeamIdle` in [charge_beam.c](src/sprites_AI/charge_beam.c)
- Unlock Imago door when it dies (instead of waiting to collect super missiles)
  - `ImagoSetEvent` in [imago.c](src/sprites_AI/imago.c)
- Allow both escape timers to work in any order
  - `EscapeDetermineTimer` in [escape.c](src/escape.c)
- Allow glass tube to be broken any time
  - `GlassTubeCheckPowerBombCollision` in [glass_tube.c](src/sprites_AI/glass_tube.c)
- Defeating Ruins Test sets Mother Brain killed event and Zebes escaped event
  - `RuinsTestDespawn` in [ruins_test.c](src\sprites_AI\ruins_test.c)
- Fix space pirate alarm music
  - `DisableChozodiaAlarm` and `DecrementChozodiaAlarm` in [space_pirate.c](src/sprites_AI/space_pirate.c)

## Room Changes

## QoL
- Enable toggling items on status screen
  - `StatusScreenToggleItem` in [status_screen.c](src/menus/status_screen.c)
- Always show in-game timer on pause screen (but don't show items)
  - `PauseScreenDrawCompletionInfo` in [pause_screen.c](src/menus/pause_screen.c)
- Remove vines in Norfair and near varia
  - `sNorfair_4_Spriteset0`, `sNorfair_4_Spriteset1`, and `sNorfair_4_Spriteset2` in [Norfair_4.c](src/data/rooms/norfair/Norfair_4.c)
  - `sBrinstar_28_Spriteset1` and `sBrinstar_28_Spriteset2` in [Brinstar_28.c](src/data/rooms/brinstar/Brinstar_28.c)

## Options
- Allow black space pirates to be hit by any beam
  - `BlackSpacePirateProjectileCollision` in [black_space_pirate.c](src/sprites_AI/black_space_pirate.c)
- Skip door transitions
  - `ConnectionProcessDoorType` in [connection.c](src/connection.c)
- New file difficulty options
  - `FileSelectInit`, `FileSelectUpdateSubMenu`, and `FileSelectProcessFileSelection` [file_select.c](src\menus\file_select.c)
  - `sFileScreenMessagesInfo` in [file_select_data.c](src\data\menus\file_select_data.c)
  - `sEnglishText_FileScreen_DifficultyHardOnly` and `sEnglishTextPointers_FileScreen` in [text_data.c](src\data\text_data.c)
- Use ball launchers without bombs
  - `MorphBallLauncherDetectBomb` in [morph_ball_launcher.c](src/sprites_AI/morph_ball_launcher.c)
- Disable infinite bomb jumping
  - `SamusSetMidAir` in [samus.c](src/samus.c)
- Disable wall jumping
  - `SamusSpinning` in [samus.c](src/samus.c)
- Skip suitless sequence
  - `TourianEscapeSubroutine` in [cutscene_utils.c](src/cutscenes/cutscene_utils.c)
  - `UpdateMusicAfterPause` in [room_music.c](src/room_music.c)
  - `GunshipFlying` in [gunship.c](src/sprites_AI/gunship.c)
- Skip cutscenes
  - `ConnectionCheckPlayCutsceneDuringTransition` in [connection.c](src/connection.c)
  - `CheckPlayRoomMusicTrack` in [room_music.c](src/room_music.c)
  - `GunshipFlying` in [gunship.c](src/sprites_AI/gunship.c)
  - `KraidInit` and `KraidDying` in [kraid.c](src/sprites_AI/kraid.c)
  - `RidleyCheckPlayCutscene` and `RidleyDying` in [ridley.c](src/sprites_AI/ridley.c)
  - `RuinsTestDespawn` in [ruins_test.c](src\sprites_AI\ruins_test.c)
