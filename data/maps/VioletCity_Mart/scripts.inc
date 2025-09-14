VioletCity_Mart_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VioletCity_Mart_Pokemart
	release
	end

	.align 2
VioletCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	pokemartlistend
