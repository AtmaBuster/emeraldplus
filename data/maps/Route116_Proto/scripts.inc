Route116_Proto_MapScripts::
	.byte 0

Route116_Proto_ItemBall::
	lock
	msgbox CelebiSeq_Text_ItemBallText, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_UNUSED_0x907
	delay 10
	fadescreen FADE_FROM_BLACK
	release
	end

CelebiSeq_Text_ItemBallText::
	.string "{PLAYER} found one AMBER!\p"
	.string "…\p"
	.string "Looks important. Better leave it be.$"
