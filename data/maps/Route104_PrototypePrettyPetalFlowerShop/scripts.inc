Route104_PrototypePrettyPetalFlowerShop_MapScripts::
	.byte 0

Route104_PrototypePrettyPetalFlowerShop_Lady::
	lock
	faceplayer
	msgbox CelebiSeq_Text_FlowerShopLady, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_UNUSED_0x90E
	delay 10
	fadescreen FADE_FROM_BLACK
	release
	end

CelebiSeq_Text_FlowerShopLady::
	.string "One of our employees used to bring her\n"
	.string "PODII into work to water the flowers.\p"
	.string "But it evolved into a TROPIUS!\l"
	.string "Can you believe it?$"
