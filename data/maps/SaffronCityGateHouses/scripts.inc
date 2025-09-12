SaffronCityGateHouses_MapScripts::
	.byte 0

SaffronCityGateHouses_EventScript_StopReturnLeft::
	lockall
	applymovement LOCALID_PLAYER, SaffronCityGateHouses_Movement_MoveLeft
	waitmovement 0
	releaseall
	end

SaffronCityGateHouses_Movement_MoveLeft:
	walk_left
	step_end

SaffronCityGateHouses_EventScript_StopReturnRight::
	lockall
	applymovement LOCALID_PLAYER, SaffronCityGateHouses_Movement_MoveRight
	waitmovement 0
	releaseall
	end

SaffronCityGateHouses_Movement_MoveRight:
	walk_right
	step_end
