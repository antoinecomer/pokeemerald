OldaleTown_Mart_MapScripts::
	.byte 0

OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_ExpandedItems::
	@pokemart OldaleTown_Mart_Pokemart_Expanded
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

@	.align 2
@OldaleTown_Mart_Pokemart_Expanded:
@	.2byte ITEM_POKE_BALL
@	.2byte ITEM_POTION
@	.2byte ITEM_ANTIDOTE
@	.2byte ITEM_PARALYZE_HEAL
@	.2byte ITEM_AWAKENING
@	.2byte ITEM_NONE
@	release
@	end

OldaleTown_Mart_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock::
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy::
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Text_PokeBallsAreSoldOut:
	.string "Z'ebben ier godvertoeme hin\n"
	.string "Ballen meer.\p"
	.string "...............Wuk.\n"
	.string "PokéBallen éh, TJOETN.\p"
	.string "Oallemoalle utverkoht, kundjet heloven?$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "'k Zin beeeeeeeeeere content\n"
	.string "en witje waaroem?\p"
	.string "'k Ekkik wel juste de loatste Pokéball hekocht!$"

OldaleTown_Mart_Text_RestoreHPWithPotion:
	.string "'k Zin beeeeeeeeeere content\n"
	.string "en witje waaroem?\p"
	.string "'k Ekkik wel juste de loatste Pokéball hekocht!$"

