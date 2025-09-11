SaffronCityGateHouses_MapScripts::
	.byte 0

SaffronCityGateHouses_EventScript_StopReturnLeft::
	lockall
	applymovement LOCALID_PLAYER, .MoveLeft
	waitmovement 0
	releaseall
	end

.MoveLeft:
	walk_left
	step_end

SaffronCityGateHouses_EventScript_StopReturnRight::
	lockall
	applymovement LOCALID_PLAYER, .MoveRight
	waitmovement 0
	releaseall
	end

.MoveRight:
	walk_right
	step_end
