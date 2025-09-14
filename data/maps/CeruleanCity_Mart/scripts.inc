CeruleanCity_Mart_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeruleanCity_Mart_Pokemart
	release
	end

	.align 2
CeruleanCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	pokemartlistend
