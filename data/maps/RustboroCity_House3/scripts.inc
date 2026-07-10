RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Ik geve min Pokémons echt\n"
	.string "machtige koosnoamkes!\p"
	.string "'t Is een expressie van, uh…\n"
	.string "min orihinaliteit, ja, daddist!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Pekachu.\n"
	.string "Meendjem. Pekachu.\p"
	.string "Ik e wok nen bijnoam voor u.\n"
	.string "'Mutn'…$"

RustboroCity_House3_Text_Pekachu:
	.string "Pekachu: Peka!$"

