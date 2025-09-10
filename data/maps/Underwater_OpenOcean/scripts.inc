Underwater_OpenOcean_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Underwater_OpenOcean_OnLoad
	.byte 0

Underwater_OpenOcean_OnLoad:
	call_if_unset FLAG_ENCOUNTERED_LUGIA, Underwater_OpenOcean_CloseIsland
	end

Underwater_OpenOcean_CloseIsland:
	setmetatile 57, 60, 0x22F, TRUE
	setmetatile 58, 60, 0x22F, TRUE
	setmetatile 59, 60, 0x22F, TRUE
	setmetatile 60, 60, 0x22F, TRUE
	setmetatile 57, 61, 0x22F, TRUE
	setmetatile 58, 61, 0x22F, TRUE
	setmetatile 59, 61, 0x22F, TRUE
	setmetatile 60, 61, 0x22F, TRUE
	setmetatile 57, 62, 0x22F, TRUE
	setmetatile 58, 62, 0x22F, TRUE
	setmetatile 59, 62, 0x22F, TRUE
	setmetatile 60, 62, 0x22F, TRUE
	return
