ViridianCity_Mart_MapScripts::
	.byte 0

ViridianCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart ViridianCity_Mart_Pokemart
	release
	end

	.align 2
ViridianCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	pokemartlistend
