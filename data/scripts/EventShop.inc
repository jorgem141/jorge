clearflag FLAG_BADGE08_GET
showobject at 6, LilyCoveCity_Harbor

Script_PokemartExample::
	lock
	faceplayer
	message Text_EventShopGreeting
	waitmessage
	pokemart Pokemart_EventShop
	msgbox Text_EventShopEnd, MSGBOX_DEFAULT
	release
	end

	.align2
Pokemart_EventShop:
	.2byte ITEM_AURORA_TICKET
	.2byte ITEM_EON_TICKET
	.2byte ITEM_MYSTIC_TICKET
	.2byte ITEM_OLD_SEA_MAP
	.2byte ITEM_NONE
	release
	end
	
Text_EventShopGreeting:
	.string "I see you're a strong trainer...\n"
	.string "Perhaps these would be of use to you?$"
	
Text_EventShopEnd:
	.string "Good luck on your adventure.$"