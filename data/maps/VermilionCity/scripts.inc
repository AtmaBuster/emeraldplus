VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	.byte 0

VermilionCity_OnTransition:
	setflag FLAG_VISITED_VERMILION_CITY
	end

VermilionCity_EventScript_FerryTrigger::
	setvar VAR_0x8003, 0
	goto VermilionCity_EventScript_Ferry

VermilionCity_EventScript_Sailor::
	setvar VAR_0x8003, 1
VermilionCity_EventScript_Ferry::
	lockall
	applymovement LOCALID_VERMILION_CITY_SAILOR, Common_Movement_FacePlayer
	msgbox VermilionCity_Text_SailBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_AsYouLike
	msgbox VermilionCity_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	delay 10
	call_if_eq VAR_0x8003, 0, VermilionCity_EventScript_MoveToFerryTrigger
	call_if_eq VAR_0x8003, 1, VermilionCity_EventScript_MoveToFerryTalk
	delay 30
	hideobjectat LOCALID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_VERMILION_CITY_SS_TIDAL
	call Common_EventScript_FerryDepart
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	releaseall
	end

VermilionCity_EventScript_AsYouLike::
	msgbox VermilionCity_Text_AsYouLike, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_0x8003, 1, Common_EventScript_NopReturn
	applymovement LOCALID_PLAYER, VermilionCity_Movement_LeaveFerry
	waitmovement 0
	release
	end

VermilionCity_EventScript_MoveToFerryTrigger:
	applymovement LOCALID_PLAYER, VermilionCity_Movement_MoveToFerryTrigger
	waitmovement 0
	return

VermilionCity_EventScript_MoveToFerryTalk:
	applymovement LOCALID_PLAYER, VermilionCity_Movement_MoveToFerryTalk
	waitmovement 0
	return

VermilionCity_Movement_MoveToFerryTalk:
	walk_left
	walk_up
VermilionCity_Movement_MoveToFerryTrigger:
	walk_up
	step_end

VermilionCity_Movement_LeaveFerry:
	walk_down
	step_end

VermilionCity_Text_SailBack:
	.string "Sail Back?$"
VermilionCity_Text_AsYouLike:
	.string "Ok$"
VermilionCity_Text_SailHome:
	.string "Sail Home$"
