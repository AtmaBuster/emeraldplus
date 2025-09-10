Underwater_OpenOcean_2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_OpenOcean_2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Underwater_OpenOcean_2_OnResume
	.byte 0

Underwater_OpenOcean_2_OnTransition:
	call_if_unset FLAG_GOT_SILVER_WING, Underwater_OpenOcean_2_SetLayoutBlocked
	call_if_set FLAG_CAUGHT_LUGIA, Underwater_OpenOcean_2_HideLugia
	call_if_unset FLAG_CAUGHT_LUGIA, Underwater_OpenOcean_2_TryShowLugia
	end

Underwater_OpenOcean_2_SetLayoutBlocked:
	setmaplayoutindex LAYOUT_UNDERWATER_OPEN_OCEAN_2_BLOCKED_LAYOUT

Underwater_OpenOcean_2_HideLugia:
	setflag FLAG_HIDE_LUGIA
	return

Underwater_OpenOcean_2_TryShowLugia:
	goto_if_set FLAG_DEFEATED_LUGIA, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_LUGIA
	return

Underwater_OpenOcean_2_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Underwater_OpenOcean_2_TryRemoveLugia
	end

Underwater_OpenOcean_2_TryRemoveLugia::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_UNDERWATER_LUGIA
	return

Underwater_OpenOcean_2_EventScript_Lugia::
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_LUGIA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_ENCOUNTERED_LUGIA
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Underwater_OpenOcean_2_DefeatedLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Underwater_OpenOcean_2_RanFromLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Underwater_OpenOcean_2_RanFromLugia
	setflag FLAG_CAUGHT_LUGIA
	release
	end

Underwater_OpenOcean_2_DefeatedLugia::
	setflag FLAG_DEFEATED_LUGIA
Underwater_OpenOcean_2_RanFromLugia::
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway
	end
