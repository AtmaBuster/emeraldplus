PewterCity_Mart_MapScripts::
	.byte 0

PewterCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PewterCity_Mart_Pokemart
	release
	end

	.align 2
PewterCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	pokemartlistend
