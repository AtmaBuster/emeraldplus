Route32_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route32_PokemonCenter_1F_OnTransition:
	setflag FLAG_LANDMARK_ROUTE_32_POKECENTER
	setrespawn HEAL_LOCATION_ROUTE32
	end

Route32_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_ROUTE_32_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
