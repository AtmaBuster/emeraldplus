MeteorFalls_Proto_MapScripts::
	.byte 0

MeteorFalls_Proto_Lass::
	lock
	faceplayer
	msgbox CelebiSeq_Text_LassText, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_UNUSED_0x90A
	delay 10
	fadescreen FADE_FROM_BLACK
	release
	end

CelebiSeq_Text_LassText::
	.string "Look at these amazing columns!\p"
	.string "Apparently the shape comes from eons\n"
	.string "of water eroding the limestone walls.$"
