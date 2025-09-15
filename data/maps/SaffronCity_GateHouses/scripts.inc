SaffronCity_GateHouses_MapScripts::
	.byte 0

SaffronCity_GateHouses_EventScript_StopReturnLeft::
	lockall
	applymovement LOCALID_PLAYER, SaffronCity_GateHouses_Movement_MoveLeft
	waitmovement 0
	releaseall
	end

SaffronCity_GateHouses_Movement_MoveLeft:
	walk_left
	step_end

SaffronCity_GateHouses_EventScript_StopReturnRight::
	lockall
	applymovement LOCALID_PLAYER, SaffronCity_GateHouses_Movement_MoveRight
	waitmovement 0
	releaseall
	end

SaffronCity_GateHouses_Movement_MoveRight:
	walk_right
	step_end
