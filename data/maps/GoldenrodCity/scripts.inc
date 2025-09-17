GoldenrodCity_MapScripts::
	.byte 0

GoldenrodCity_EventScript_FerryTrigger::
	setvar VAR_0x8003, 0
	goto GoldenrodCity_EventScript_Ferry
	end

GoldenrodCity_EventScript_FerryTalk::
	setvar VAR_0x8003, 1
GoldenrodCity_EventScript_Ferry:
	lockall
	applymovement LOCALID_GOLDENROD_CITY_SAILOR, Common_Movement_FacePlayer
	checkitem ITEM_BUENAS_PIN
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_EventScript_NoFerry
	msgbox GoldenrodCity_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_EventScript_NoTicket
	message GoldenrodCity_Text_WhereWouldYouLikeToGo
	waitmessage
	goto GoldenrodCity_EventScript_ChooseDestination
	end

GoldenrodCity_EventScript_ChooseDestination:
	multichoicedefault 18, 6, MULTI_GOLDENROD_FERRY, 2, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_EventScript_FerryToLilycove
	case 1, GoldenrodCity_EventScript_FerryToVermilion
	case 2, GoldenrodCity_EventScript_CancelFerry
	case MULTI_B_PRESSED, GoldenrodCity_EventScript_CancelFerry
	end

GoldenrodCity_EventScript_FerryToLilycove:
	msgbox GoldenrodCity_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_EventScript_ChooseNewDestination
	msgbox GoldenrodCity_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call GoldenrodCity_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	releaseall
	end

GoldenrodCity_EventScript_FerryToVermilion:
	msgbox GoldenrodCity_Text_VermilionItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_EventScript_ChooseNewDestination
	msgbox GoldenrodCity_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call GoldenrodCity_EventScript_BoardFerry
	warp MAP_VERMILION_CITY, 37, 46
	waitstate
	releaseall
	end

GoldenrodCity_EventScript_CancelFerry:
	msgbox GoldenrodCity_Text_SailAnotherTime, MSGBOX_DEFAULT
	closemessage
	goto GoldenrodCity_EventScript_LeaveFerry
	end

GoldenrodCity_EventScript_ChooseNewDestination:
	message GoldenrodCity_Text_ThenWhere
	waitmessage
	goto GoldenrodCity_EventScript_ChooseDestination
	end

GoldenrodCity_EventScript_BoardFerry:
	closemessage
	delay 10
	call_if_eq VAR_0x8003, 0, GoldenrodCity_EventScript_BoardFerryTrigger
	call_if_eq VAR_0x8003, 1, GoldenrodCity_EventScript_BoardFerryTalk
	delay 30
	hideobjectat LOCALID_PLAYER, 0
	delay 60
	applymovement LOCALID_GOLDENROD_CITY_SS_TIDAL, GoldenrodCity_Movement_FerryDepart
	waitmovement 0
	return

GoldenrodCity_EventScript_BoardFerryTrigger:
	applymovement LOCALID_PLAYER, GoldenrodCity_Movement_BoardFerryTrigger
	waitmovement 0
	return

GoldenrodCity_EventScript_BoardFerryTalk:
	applymovement LOCALID_PLAYER, GoldenrodCity_Movement_BoardFerryTalk
	waitmovement 0
	return

GoldenrodCity_EventScript_NoTicket:
	msgbox GoldenrodCity_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
	goto GoldenrodCity_EventScript_LeaveFerry
	end

GoldenrodCity_EventScript_NoFerry:
	msgbox GoldenrodCity_Text_FerryClosed, MSGBOX_DEFAULT
	closemessage
GoldenrodCity_EventScript_LeaveFerry:
	goto_if_eq VAR_0x8003, 1, Common_EventScript_NopReturn
	applymovement LOCALID_PLAYER, GoldenrodCity_Movement_LeaveFerry
	waitmovement 0
	releaseall
	end

GoldenrodCity_Movement_BoardFerryTalk:
	walk_left
	walk_down
GoldenrodCity_Movement_BoardFerryTrigger:
	walk_down
	step_end

GoldenrodCity_Movement_LeaveFerry:
	walk_up
	step_end

GoldenrodCity_Movement_FerryDepart:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_Text_MayISeeYourTicket:
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your ticket?$"

GoldenrodCity_Text_NoTicket:
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"

GoldenrodCity_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

GoldenrodCity_Text_LilycoveItIs:
	.string "LILYCOVE CITY it is, then!$"

GoldenrodCity_Text_VermilionItIs:
	.string "VERMILION CITY it is, then!$"

GoldenrodCity_Text_ThenWhere:
	.string "Then, where would you like to go?$"

GoldenrodCity_Text_PleaseBoardFerry:
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

GoldenrodCity_Text_SailAnotherTime:
	.string "Please sail with us another time!$"

GoldenrodCity_Text_FerryClosed:
	.string "Ferry closed for now.$"

GoldenrodTest_GiveItems::
	giveitem ITEM_BUENAS_PIN
	release
	end
