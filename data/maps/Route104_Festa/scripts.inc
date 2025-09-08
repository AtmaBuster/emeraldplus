Route104_Festa_MapScripts::
	.byte 0

Route104_Festa_Hiker::
	lock
	faceplayer
	msgbox CelebiSeq_Text_HikerText, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_UNUSED_0x905
	delay 10
	fadescreen FADE_FROM_BLACK
	release
	end

CelebiSeq_Text_HikerText::
	.string "I'm heading off to MAUVILLE CITY to\n"
	.string "see a friend of mine.\p"
	.string "PROF. COZMO researches METEORITES\n"
	.string "that fall from the sky.$"
