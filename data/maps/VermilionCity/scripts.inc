VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, VermilionCity_OnResume
	.byte 0

VermilionCity_OnTransition:
	setflag FLAG_VISITED_VERMILION_CITY
	end

VermilionCity_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VermilionCity_TryRemoveSnorlax
	end

VermilionCity_TryRemoveSnorlax:
	removeobject LOCALID_VERMILION_SNORLAX
	removeobject LOCALID_SNORLAX_INTERACT_1
	removeobject LOCALID_SNORLAX_INTERACT_2
	removeobject LOCALID_SNORLAX_INTERACT_3
	return

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

VermilionCity_EventScript_DEBUG_Flute::
	giveitem ITEM_POKE_FLUTE
	release
	end

VermilionCity_EventScript_Snorlax::
	lockall
	checkitem ITEM_POKE_FLUTE
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_EventScript_NoPokeFlute
	msgbox VermilionCity_Text_AskPokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_DontUseFlute
	msgbox VermilionCity_Text_PlayedPokeFlute, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_RG_POKE_FLUTE
	waitfanfare
	msgbox VermilionCity_Text_SnorlaxWokeUp, MSGBOX_DEFAULT
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VermilionCity_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VermilionCity_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VermilionCity_EventScript_FoughtSnorlax
	releaseall
	end

VermilionCity_EventScript_DontUseFlute:
	closemessage
	releaseall
	end

VermilionCity_EventScript_NoPokeFlute::
	msgbox VermilionCity_Text_SleepingSnorlax, MSGBOX_DEFAULT
	releaseall
	end

VermilionCity_EventScript_FoughtSnorlax:
	msgbox VermilionCity_Text_SnorlaxLeft, MSGBOX_DEFAULT
	releaseall
	end

VermilionCity_Text_SleepingSnorlax:
	.string "A sleeping POKéMON blocks the way.$"

VermilionCity_Text_AskPokeFlute:
	.string "A sleeping POKéMON blocks the way.\p"
	.string "Want to use the POKé FLUTE?$"

VermilionCity_Text_PlayedPokeFlute:
	.string "{PLAYER} played the POKé FLUTE.$"

VermilionCity_Text_SnorlaxWokeUp:
	.string "SNORLAX woke up!\p"
	.string "It attacked in a grumpy rage!$"

VermilionCity_Text_SnorlaxLeft:
	.string "SNORLAX calmed down.\n"
	.string "It gave a huge yawn…\l"
	.string "And returned to the mountains.$"
