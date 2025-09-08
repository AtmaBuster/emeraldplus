RustboroCity_Proto_MapScripts::
	.byte 0

RustboroCity_Proto_Gentleman::
	lock
	faceplayer
	msgbox CelebiSeq_Text_GentlemanText, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_UNUSED_0x906
	delay 10
	fadescreen FADE_FROM_BLACK
	release
	end

CelebiSeq_Text_GentlemanText::
	.string "The leader of DEVON's pharmacy branch\n"
	.string "is a man named MAXIE.\p"
	.string "Personally, I think he's up to no good.\p"
	.string "Wherever he goes, TEAM TUNNEL shows up\n"
	.string "not too long after.$"
