DarkCaveBlackthornEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DarkCaveBlackthornEntrance_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCaveBlackthornEntrance_OnTransition
	.byte 0

DarkCaveBlackthornEntrance_OnLoad::
	call_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_1, 1, DarkCaveBlackthornEntrance_SetLight1Tile
	call_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_2, 1, DarkCaveBlackthornEntrance_SetLight2Tile
	call_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_3, 1, DarkCaveBlackthornEntrance_SetLight3Tile
	call_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_4, 1, DarkCaveBlackthornEntrance_SetLight4Tile
	call_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_5, 1, DarkCaveBlackthornEntrance_SetLight5Tile
	call_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_6, 1, DarkCaveBlackthornEntrance_SetLight6Tile
	end

DarkCaveBlackthornEntrance_SetLight1Tile:
	setmetatile 4, 29, 0x389, TRUE
	return

DarkCaveBlackthornEntrance_SetLight2Tile:
	setmetatile 6, 29, 0x389, TRUE
	return

DarkCaveBlackthornEntrance_SetLight3Tile:
	setmetatile 8, 29, 0x389, TRUE
	return

DarkCaveBlackthornEntrance_SetLight4Tile:
	setmetatile 10, 29, 0x389, TRUE
	return

DarkCaveBlackthornEntrance_SetLight5Tile:
	setmetatile 12, 29, 0x389, TRUE
	return

DarkCaveBlackthornEntrance_SetLight6Tile:
	setmetatile 14, 29, 0x389, TRUE
	return

DarkCaveBlackthornEntrance_OnTransition::
	call DarkCaveBlackthornEntrance_DisableRandomLight
	call DarkCaveBlackthornEntrance_ResetLightLevel
	end

DarkCaveBlackthornEntrance_DisableRandomLight::
	random 8
	switch VAR_RESULT
	case 0, DarkCaveBlackthornEntrance_DisableLight1
	case 1, DarkCaveBlackthornEntrance_DisableLight2
	case 2, DarkCaveBlackthornEntrance_DisableLight3
	case 3, DarkCaveBlackthornEntrance_DisableLight4
	case 4, DarkCaveBlackthornEntrance_DisableLight5
	case 5, DarkCaveBlackthornEntrance_DisableLight6
	return

DarkCaveBlackthornEntrance_DisableLight1:
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_1, 0
	return

DarkCaveBlackthornEntrance_DisableLight2:
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_2, 0
	return

DarkCaveBlackthornEntrance_DisableLight3:
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_3, 0
	return

DarkCaveBlackthornEntrance_DisableLight4:
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_4, 0
	return

DarkCaveBlackthornEntrance_DisableLight5:
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_5, 0
	return

DarkCaveBlackthornEntrance_DisableLight6:
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_6, 0
	return

DarkCaveBlackthornEntrance_ResetLightLevel::
	setvar VAR_TEMP_3, 0
	goto_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_1, 0, DarkCaveBlackthornEntrance_ResetLightLevel_2
	addvar VAR_TEMP_3, 1
DarkCaveBlackthornEntrance_ResetLightLevel_2:
	goto_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_2, 0, DarkCaveBlackthornEntrance_ResetLightLevel_3
	addvar VAR_TEMP_3, 1
DarkCaveBlackthornEntrance_ResetLightLevel_3:
	goto_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_3, 0, DarkCaveBlackthornEntrance_ResetLightLevel_4
	addvar VAR_TEMP_3, 1
DarkCaveBlackthornEntrance_ResetLightLevel_4:
	goto_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_4, 0, DarkCaveBlackthornEntrance_ResetLightLevel_5
	addvar VAR_TEMP_3, 1
DarkCaveBlackthornEntrance_ResetLightLevel_5:
	goto_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_5, 0, DarkCaveBlackthornEntrance_ResetLightLevel_6
	addvar VAR_TEMP_3, 1
DarkCaveBlackthornEntrance_ResetLightLevel_6:
	goto_if_eq VAR_DARK_CAVE_BLACKTHORN_LIGHT_6, 0, DarkCaveBlackthornEntrance_ResetLightLevel_Done
	addvar VAR_TEMP_3, 1
DarkCaveBlackthornEntrance_ResetLightLevel_Done:
	goto DarkCave_UpdateLightLevel
	return

DarkCaveBlackthornEntrance_EventScript_FlashTrigger1::
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_1, 1
	call DarkCaveBlackthornEntrance_SetLight1Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

DarkCaveBlackthornEntrance_EventScript_FlashTrigger2::
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_2, 1
	call DarkCaveBlackthornEntrance_SetLight2Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

DarkCaveBlackthornEntrance_EventScript_FlashTrigger3::
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_3, 1
	call DarkCaveBlackthornEntrance_SetLight3Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

DarkCaveBlackthornEntrance_EventScript_FlashTrigger4::
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_4, 1
	call DarkCaveBlackthornEntrance_SetLight4Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

DarkCaveBlackthornEntrance_EventScript_FlashTrigger5::
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_5, 1
	call DarkCaveBlackthornEntrance_SetLight5Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

DarkCaveBlackthornEntrance_EventScript_FlashTrigger6::
	setvar VAR_DARK_CAVE_BLACKTHORN_LIGHT_6, 1
	call DarkCaveBlackthornEntrance_SetLight6Tile
	special DrawWholeMapView
	call DarkCave_IncrementFlashLevel
	end

