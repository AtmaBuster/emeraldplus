VermilionCity_Mart_MapScripts::
	.byte 0

VermilionCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VermilionCity_Mart_Pokemart
	release
	end

	.align 2
VermilionCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	pokemartlistend
