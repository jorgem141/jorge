FallarborTown_PokemonCenter_1F_MapScripts:: @ 8200BCD
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition: @ 8200BD8
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

@ VAR_0x800B is the Nurse's object event id
FallarborTown_PokemonCenter_1F_EventScript_Nurse:: @ 8200BE1
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl:: @ 8200BEF
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM:: @ 8200BF8
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette:: @ 8200C01
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth:: @ 8200C28
	applymovement 4, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest:: @ 8200C38
	applymovement 4, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited:: @ 8200C48
	playse SE_JIDO_DOA
	removeobject 4
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth: @ 8200C53
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest: @ 8200C60
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting: @ 8200C6B
	.string "Oh, hello.\n"
	.string "You are?\p"
	.string "Okay, your name's {PLAYER}{KUN}.\n"
	.string "I can see that you're a TRAINER.\p"
	.string "So that means you use the POKéMON\n"
	.string "Storage System I developed.\p"
	.string "How I arrived at that conclusion is\n"
	.string "a simple deductive process.\p"
	.string "You spoke to me because you wanted\n"
	.string "to access something on this PC.\p"
	.string "Oh, I'm sorry. I'm LANETTE.\p"
	.string "Honestly, I'm glad to meet you--it's\n"
	.string "great you're using the Storage System.\p"
	.string "If you could, please visit me at home.\n"
	.string "My house is on ROUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown: @ 8200E22
	.string "I wonder what POKéMON looked like\n"
	.string "long, long ago?\p"
	.string "Maybe the FOSSIL MANIAC at the edge\n"
	.string "of town will know.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees: @ 8200E8B
	.string "In the fields of FALLARBOR, we plant\n"
	.string "seedlings of hardy trees that thrive\l"
	.string "even in volcanic ash.$"

FallarborTown_PokemonCenter_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_DELIBIRD_NPC_TRADE_COMPLETED, FallarborTown_PokemonCenter_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_DELIBIRD
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FallarborTown_PokemonCenter_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_PokemonCenter_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq FallarborTown_PokemonCenter_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne FallarborTown_PokemonCenter_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox FallarborTown_PokemonCenter_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_DELIBIRD_NPC_TRADE_COMPLETED
	release
	end

FallarborTown_PokemonCenter_EventScript_DeclineTrade::
	msgbox FallarborTown_PokemonCenter_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

FallarborTown_PokemonCenter_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox FallarborTown_PokemonCenter_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

FallarborTown_PokemonCenter_EventScript_TradeCompleted::
	msgbox FallarborTown_PokemonCenter_Text_TradeComplete, MSGBOX_DEFAULT
	release
	end

FallarborTown_PokemonCenter_Text_IllTradeIfYouWant:
	.string "Skarmory are just the coolest..\n"
	.string "Do you have one?\l"
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you do!$"

FallarborTown_PokemonCenter_Text_PleaseBeGoodToMyPokemon:
	.string "Thank you so much!$"

FallarborTown_PokemonCenter_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

FallarborTown_PokemonCenter_Text_YouDontWantToThatsOkay:
	.string "Oh, if you're not up to it, that's okay.\n"
	.string "But I really do love Skarmory…$"
	
FallarborTown_PokemonCenter_Text_TradeComplete:
	.string "Delibird is a really rare\n"
	.string "Pokémon from the Johto region!$"