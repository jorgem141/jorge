AlteringCave_MapScripts:: @ 823B177
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition: @ 823B17D
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

AlteringCave_OnLoad:
	call_if_unset FLAG_ARTICUNO_CAVE, Hide_IceCave_Script
	
Hide_IceCave_Script::
	setmetatile 27, 11, 0x266, 1