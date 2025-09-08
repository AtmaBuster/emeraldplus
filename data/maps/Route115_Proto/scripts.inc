Route115_Proto_MapScripts::
	.byte 0

Route115_Proto_Adventurer::
	lock
	faceplayer
	msgbox CelebiSeq_Text_AdventurerText, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_UNUSED_0x909
	delay 10
	fadescreen FADE_FROM_BLACK
	release
	end

CelebiSeq_Text_AdventurerText::
	.string "I'm something of an expert on\n"
	.string "SECRET BASES.\p"
	.string "There's all sorts of spots to make one\n"
	.string "right here on this hill.$"
