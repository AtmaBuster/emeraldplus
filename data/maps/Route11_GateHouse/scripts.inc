Route11_GateHouse_MapScripts::
	.byte 0

Route11_GateHouse_EventScript_StopReturnLeft::
	lockall
	applymovement LOCALID_PLAYER, Route11_GateHouse_Movement_MoveLeft
	waitmovement 0
	releaseall
	end

Route11_GateHouse_Movement_MoveLeft:
	walk_left
	step_end
