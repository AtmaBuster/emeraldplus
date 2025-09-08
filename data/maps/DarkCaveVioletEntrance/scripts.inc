DarkCaveVioletEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DarkCaveVioletEntrance_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCaveVioletEntrance_OnTransition
	.byte 0

DarkCaveVioletEntrance_OnLoad::
	call_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_1, 1, DarkCaveVioletEntrance_SetLight1Tile
	call_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_2, 1, DarkCaveVioletEntrance_SetLight2Tile
	call_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_3, 1, DarkCaveVioletEntrance_SetLight3Tile
	call_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_4, 1, DarkCaveVioletEntrance_SetLight4Tile
	call_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_5, 1, DarkCaveVioletEntrance_SetLight5Tile
	call_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_6, 1, DarkCaveVioletEntrance_SetLight6Tile
	end

DarkCaveVioletEntrance_SetLight1Tile:
	setmetatile 4, 13, 0x389, TRUE
	return

DarkCaveVioletEntrance_SetLight2Tile:
	setmetatile 6, 13, 0x389, TRUE
	return

DarkCaveVioletEntrance_SetLight3Tile:
	setmetatile 8, 13, 0x389, TRUE
	return

DarkCaveVioletEntrance_SetLight4Tile:
	setmetatile 10, 13, 0x389, TRUE
	return

DarkCaveVioletEntrance_SetLight5Tile:
	setmetatile 12, 13, 0x389, TRUE
	return

DarkCaveVioletEntrance_SetLight6Tile:
	setmetatile 14, 13, 0x389, TRUE
	return

DarkCaveVioletEntrance_OnTransition::
	call DarkCaveVioletEntrance_DisableRandomLight
	call DarkCaveVioletEntrance_ResetLightLevel
	end

DarkCaveVioletEntrance_DisableRandomLight::
	random 8
	switch VAR_RESULT
	case 0, DarkCaveVioletEntrance_DisableLight1
	case 1, DarkCaveVioletEntrance_DisableLight2
	case 2, DarkCaveVioletEntrance_DisableLight3
	case 3, DarkCaveVioletEntrance_DisableLight4
	case 4, DarkCaveVioletEntrance_DisableLight5
	case 5, DarkCaveVioletEntrance_DisableLight6
	return

DarkCaveVioletEntrance_DisableLight1:
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_1, 0
	return

DarkCaveVioletEntrance_DisableLight2:
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_2, 0
	return

DarkCaveVioletEntrance_DisableLight3:
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_3, 0
	return

DarkCaveVioletEntrance_DisableLight4:
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_4, 0
	return

DarkCaveVioletEntrance_DisableLight5:
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_5, 0
	return

DarkCaveVioletEntrance_DisableLight6:
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_6, 0
	return

DarkCaveVioletEntrance_ResetLightLevel::
	setvar VAR_TEMP_3, 0
	goto_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_1, 0, DarkCaveVioletEntrance_ResetLightLevel_2
	addvar VAR_TEMP_3, 1
DarkCaveVioletEntrance_ResetLightLevel_2:
	goto_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_2, 0, DarkCaveVioletEntrance_ResetLightLevel_3
	addvar VAR_TEMP_3, 1
DarkCaveVioletEntrance_ResetLightLevel_3:
	goto_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_3, 0, DarkCaveVioletEntrance_ResetLightLevel_4
	addvar VAR_TEMP_3, 1
DarkCaveVioletEntrance_ResetLightLevel_4:
	goto_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_4, 0, DarkCaveVioletEntrance_ResetLightLevel_5
	addvar VAR_TEMP_3, 1
DarkCaveVioletEntrance_ResetLightLevel_5:
	goto_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_5, 0, DarkCaveVioletEntrance_ResetLightLevel_6
	addvar VAR_TEMP_3, 1
DarkCaveVioletEntrance_ResetLightLevel_6:
	goto_if_eq VAR_DARK_CAVE_VIOLET_LIGHT_6, 0, DarkCaveVioletEntrance_ResetLightLevel_Done
	addvar VAR_TEMP_3, 1
DarkCaveVioletEntrance_ResetLightLevel_Done:
	goto DarkCave_UpdateLightLevel
	return

DarkCaveVioletEntrance_EventScript_FlashTrigger1::
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_1, 1
	call DarkCaveVioletEntrance_SetLight1Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

DarkCaveVioletEntrance_EventScript_FlashTrigger2::
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_2, 1
	call DarkCaveVioletEntrance_SetLight2Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

DarkCaveVioletEntrance_EventScript_FlashTrigger3::
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_3, 1
	call DarkCaveVioletEntrance_SetLight3Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

DarkCaveVioletEntrance_EventScript_FlashTrigger4::
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_4, 1
	call DarkCaveVioletEntrance_SetLight4Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

DarkCaveVioletEntrance_EventScript_FlashTrigger5::
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_5, 1
	call DarkCaveVioletEntrance_SetLight5Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

DarkCaveVioletEntrance_EventScript_FlashTrigger6::
	setvar VAR_DARK_CAVE_VIOLET_LIGHT_6, 1
	call DarkCaveVioletEntrance_SetLight6Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

DarkCave_IncrementFlashLevel::
	goto_if_eq VAR_TEMP_3, 6, DarkCave_SetFlash_Cancel
	addvar VAR_TEMP_3, 1
DarkCave_UpdateLightLevel::
	goto_if_eq VAR_TEMP_3, 0, DarkCave_SetFlash7
	goto_if_eq VAR_TEMP_3, 1, DarkCave_SetFlash6
	goto_if_eq VAR_TEMP_3, 2, DarkCave_SetFlash5
	goto_if_eq VAR_TEMP_3, 3, DarkCave_SetFlash4
	goto_if_eq VAR_TEMP_3, 4, DarkCave_SetFlash3
	goto_if_eq VAR_TEMP_3, 5, DarkCave_SetFlash2
	goto_if_eq VAR_TEMP_3, 6, DarkCave_SetFlash1
DarkCave_SetFlash_Cancel:
	return

DarkCave_SetFlash1::
	animateflash 1
	setflashlevel 1
	return

DarkCave_SetFlash2::
	animateflash 2
	setflashlevel 2
	return

DarkCave_SetFlash3::
	animateflash 3
	setflashlevel 3
	return

DarkCave_SetFlash4::
	animateflash 4
	setflashlevel 4
	return

DarkCave_SetFlash5::
	animateflash 5
	setflashlevel 5
	return

DarkCave_SetFlash6::
	animateflash 6
	setflashlevel 6
	return

DarkCave_SetFlash7::
	animateflash 7
	setflashlevel 7
	return
