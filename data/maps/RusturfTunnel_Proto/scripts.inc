RusturfTunnel_Proto_MapScripts::
	.byte 0

RusturfTunnel_Proto_BlackBelt::
	lock
	faceplayer
	msgbox CelebiSeq_Text_BlackBeltText, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_UNUSED_0x908
	delay 10
	fadescreen FADE_FROM_BLACK
	release
	end

CelebiSeq_Text_BlackBeltText::
	.string "It's a straight shot from here to\n"
	.string "VERDANTURF TOWN.\p"
	.string "That is, it would be if these rocks\n"
	.string "weren't in the way.$"

RusturfTunnel_Proto_StuckRock::
	lock
	msgbox CelebiSeq_Text_StuckRock, MSGBOX_DEFAULT
	release
	end

CelebiSeq_Text_StuckRock::
	.string "The rock is stuck fast.\n"
	.string "There's no way through.$"
