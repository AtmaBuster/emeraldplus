EcruteakCity_Mart_MapScripts::
	.byte 0

EcruteakCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EcruteakCity_Mart_Pokemart
	release
	end

	.align 2
EcruteakCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	pokemartlistend
