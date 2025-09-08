MtSilverOutside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilverOutside_OnTransition
	.byte 0

MtSilverOutside_OnTransition:
	setflag FLAG_VISITED_MT_SILVER
	end
