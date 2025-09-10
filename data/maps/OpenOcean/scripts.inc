OpenOcean_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, OpenOcean_OnLoad
	.byte 0

OpenOcean_OnLoad:
	call_if_set FLAG_ENCOUNTERED_LUGIA, OpenOcean_OpenIsland
	end

OpenOcean_OpenIsland:
	setmetatile 76, 44, METATILE_General_CalmWater, FALSE
	setmetatile 77, 44, METATILE_General_CalmWater, FALSE
	setmetatile 76, 45, METATILE_General_CalmWater, FALSE
	setmetatile 77, 45, METATILE_General_CalmWater, FALSE
	setmetatile 78, 45, METATILE_General_CalmWater, FALSE
	setmetatile 79, 45, METATILE_General_CalmWater, FALSE
	setmetatile 78, 46, METATILE_General_CalmWater, FALSE
	setmetatile 79, 46, METATILE_General_CalmWater, FALSE
	return

OOEVTEST::
	setflag FLAG_ENCOUNTERED_LUGIA
	end
