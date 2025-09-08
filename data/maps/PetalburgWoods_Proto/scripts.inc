PetalburgWoods_Proto_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CelebiEvent_OnResume
	.byte 0

CelebiEvent_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CelebiEvent_RemoveCelebi
	end

CelebiEvent_RemoveCelebi:
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

PetalburgWoods_Proto_Celebi::
	lock
	goto_if_unset FLAG_UNUSED_0x911, CelebiEvent_FirstTalk
	goto_if_set FLAG_UNUSED_0x904, CelebiEvent_AllDoneReturn
	goto_if_unset FLAG_UNUSED_0x905, CelebiEvent_Unfinished
	goto_if_unset FLAG_UNUSED_0x906, CelebiEvent_Unfinished
	goto_if_unset FLAG_UNUSED_0x907, CelebiEvent_Unfinished
	goto_if_unset FLAG_UNUSED_0x908, CelebiEvent_Unfinished
	goto_if_unset FLAG_UNUSED_0x909, CelebiEvent_Unfinished
	goto_if_unset FLAG_UNUSED_0x90A, CelebiEvent_Unfinished
	goto_if_unset FLAG_UNUSED_0x90E, CelebiEvent_Unfinished
	goto_if_unset FLAG_UNUSED_0x90F, CelebiEvent_Unfinished
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CELEBI, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CelebiEvent_RanFrom
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CelebiEvent_RanFrom
	setflag FLAG_UNUSED_0x904
CelebiEvent_RanFrom:
	warpteleport MAP_PETALBURG_WOODS, 35, 24
	release
	end

CelebiEvent_FirstTalk::
	msgbox CelebiSeq_WantsToPlay, MSGBOX_DEFAULT
	setflag FLAG_UNUSED_0x911
	release
	end

CelebiEvent_Unfinished::
	msgbox CelebiSeq_MoreToFind, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CelebiEvent_RanFrom
	release
	end

CelebiEvent_AllDoneReturn::
	msgbox CelebiSeq_AllDone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CelebiEvent_RanFrom
	release
	end

CelebiSeq_WantsToPlay::
	.string "CELEBI wants to play.\p"
	.string "It seems to want you to explore.$"

CelebiSeq_MoreToFind::
	.string "CELEBI isn't done playing yet.\n"
	.string "You have more to find.\p"
	.string "Would you like to go back?$"

CelebiSeq_AllDone:
	.string "CELEBI is satisfied.\p"
	.string "Would you like to go back?$"
