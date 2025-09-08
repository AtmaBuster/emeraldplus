MeteorFallsB1F_Proto_MapScripts::
	.byte 0

MeteorFallsB1F_Proto_Boarder::
	lock
	faceplayer
	msgbox CelebiSeq_Text_BoarderText, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_UNUSED_0x90F
	delay 10
	fadescreen FADE_FROM_BLACK
	release
	end

CelebiSeq_Text_BoarderText::
	.string "I'm a SNOWBOARDER.\p"
	.string "This frozen cave has lots of my\n"
	.string "favorite ICE-type POKéMON.$"
