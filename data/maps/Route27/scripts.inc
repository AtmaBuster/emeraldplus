Route27_MapScripts::
	.byte 0

Route27_EventScript_FirstStepToKanto1::
	setvar VAR_0x8008, 0
	goto Route27_EventScript_FirstStepToKanto
	end

Route27_EventScript_FirstStepToKanto2::
	setvar VAR_0x8008, 1
	goto Route27_EventScript_FirstStepToKanto
	end

Route27_EventScript_FirstStepToKanto::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROUTE27_KANTO_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE27_KANTO_MAN, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 0, Route27_EventScript_Approach1
	call_if_eq VAR_0x8008, 1, Route27_EventScript_Approach2
	msgbox Route27_Text_FirstSteps, MSGBOX_DEFAULT
	closemessage
	delay 48
	msgbox Route27_Text_AlreadyDone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE27_KANTO_MAN, Route27_Movement_KantoManReturn_Part1
	waitmovement 0
	delay 48
	msgbox Route27_Text_Sigh, MSGBOX_DEFAULT
	closemessage
	delay 48
	call_if_eq VAR_0x8008, 0, Route27_EventScript_Return1
	call_if_eq VAR_0x8008, 1, Route27_EventScript_Return2
	setvar VAR_ROUTE27_STATE, 1
	releaseall
	end

Route27_EventScript_Approach1:
	applymovement LOCALID_ROUTE27_KANTO_MAN, Route27_Movement_KantoManApproach1
	waitmovement 0
	return

Route27_EventScript_Approach2:
	applymovement LOCALID_ROUTE27_KANTO_MAN, Route27_Movement_KantoManApproach2
	waitmovement 0
	return

Route27_EventScript_Return1:
	applymovement LOCALID_ROUTE27_KANTO_MAN, Route27_Movement_KantoManReturn1
	waitmovement 0
	return

Route27_EventScript_Return2:
	applymovement LOCALID_ROUTE27_KANTO_MAN, Route27_Movement_KantoManReturn2
	waitmovement 0
	return

Route27_Movement_KantoManApproach2:
	walk_down
Route27_Movement_KantoManApproach1:
	walk_down
	walk_left
	walk_left
	step_end

Route27_Movement_KantoManReturn_Part1:
	walk_right
	step_end

Route27_Movement_KantoManReturn1:
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

Route27_Movement_KantoManReturn2:
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

Route27_EventScript_KantoGuy::
	msgbox Route27_Text_Disappointed, MSGBOX_NPC
	end

Route27_Text_FirstSteps:
	.string "Do you know what you just did?\p"
	.string "You've taken your first step into\n"
	.string "KANTO!$"

Route27_Text_AlreadyDone:
	.string "What? You've already been to KANTO?\p"
	.string "Oh, I see. That's fine, I suppose.$"

Route27_Text_Disappointed:
	.string "Me? Oh no, I'm fine.\p"
	.string "It's my whole thing to welcome people\n"
	.string "to KANTO, but I'm not disappointed or\l"
	.string "anything. Not at all.$"

Route27_Text_Sigh:
	.string "Sigh…$"
