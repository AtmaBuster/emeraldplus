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
	end

VermilionCity_EventScript_Sailor::
	setvar VAR_0x8003, 1
VermilionCity_EventScript_Ferry::
	lockall
	applymovement LOCALID_VERMILION_CITY_SAILOR, Common_Movement_FacePlayer
	msgbox VermilionCity_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_EventScript_NoTicket
	message VermilionCity_Text_WhereWouldYouLikeToGo
	waitmessage
	goto VermilionCity_EventScript_ChooseDestination
	end

VermilionCity_EventScript_ChooseDestination:
	checkitem ITEM_BUENAS_PIN
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_ChooseDestinationFull
	multichoicedefault 18, 8, MULTI_VERMILION_FERRY, 1, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_FerryToLilycove
	case 1, VermilionCity_EventScript_CancelFerry
	case MULTI_B_PRESSED, VermilionCity_EventScript_CancelFerry
	end

VermilionCity_EventScript_ChooseDestinationFull:
	multichoicedefault 18, 6, MULTI_VERMILION_FERRY_2, 2, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_FerryToLilycove
	case 1, VermilionCity_EventScript_FerryToGoldenrod
	case 2, VermilionCity_EventScript_CancelFerry
	case MULTI_B_PRESSED, VermilionCity_EventScript_CancelFerry
	end

VermilionCity_EventScript_FerryToLilycove:
	msgbox VermilionCity_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_ChooseNewDestination
	msgbox VermilionCity_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call VermilionCity_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	releaseall
	end

VermilionCity_EventScript_FerryToGoldenrod:
	msgbox VermilionCity_Text_GoldenrodItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_ChooseNewDestination
	msgbox VermilionCity_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call VermilionCity_EventScript_BoardFerry
	warp MAP_GOLDENROD_CITY, 2, 19
	waitstate
	releaseall
	end

VermilionCity_EventScript_CancelFerry:
	msgbox VermilionCity_Text_SailAnotherTime, MSGBOX_DEFAULT
	closemessage
	goto VermilionCity_EventScript_LeaveFerry
	end

VermilionCity_EventScript_ChooseNewDestination:
	message VermilionCity_Text_ThenWhere
	waitmessage
	goto VermilionCity_EventScript_ChooseDestination
	end

VermilionCity_EventScript_BoardFerry:
	closemessage
	delay 10
	call_if_eq VAR_0x8003, 0, VermilionCity_EventScript_BoardFerryTrigger
	call_if_eq VAR_0x8003, 1, VermilionCity_EventScript_BoardFerryTalk
	delay 30
	hideobjectat LOCALID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_VERMILION_CITY_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

VermilionCity_EventScript_BoardFerryTrigger:
	applymovement LOCALID_PLAYER, VermilionCity_Movement_MoveToFerryTrigger
	waitmovement 0
	return

VermilionCity_EventScript_BoardFerryTalk:
	applymovement LOCALID_PLAYER, VermilionCity_Movement_MoveToFerryTalk
	waitmovement 0
	return

VermilionCity_EventScript_NoTicket:
	msgbox VermilionCity_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
VermilionCity_EventScript_LeaveFerry:
	goto_if_eq VAR_0x8003, 1, Common_EventScript_NopReturn
	applymovement LOCALID_PLAYER, VermilionCity_Movement_LeaveFerry
	waitmovement 0
	releaseall
	end

VermilionCity_Movement_MoveToFerryTalk:
	walk_left
	walk_up
VermilionCity_Movement_MoveToFerryTrigger:
	walk_up
	step_end

VermilionCity_Movement_LeaveFerry:
	walk_down
	step_end

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

VermilionCity_Text_MayISeeYourTicket:
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your ticket?$"

VermilionCity_Text_NoTicket:
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"

VermilionCity_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

VermilionCity_Text_LilycoveItIs:
	.string "LILYCOVE CITY it is, then!$"

VermilionCity_Text_GoldenrodItIs:
	.string "GOLDENROD CITY it is, then!$"

VermilionCity_Text_ThenWhere:
	.string "Then, where would you like to go?$"

VermilionCity_Text_PleaseBoardFerry:
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

VermilionCity_Text_SailAnotherTime:
	.string "Please sail with us another time!$"
