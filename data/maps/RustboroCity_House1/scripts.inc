RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Huh? Min Pokémon is koddig?\n"
	.string "Da moeje mie nie vertelln whé.\p"
	.string "Ma omdajet gie zijt, wil ik u wel n'en\n"
	.string "deal doen. 'k Doe da nie alledoagn whe.\p"
	.string "Mijnen {STR_VAR_2} vo\n"
	.string "jun {STR_VAR_1}, wuk peisdje?$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Eheheh…\n"
	.string "Brave zin é me min Pokémon.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Huh? Peisdje gie nu serieus, doodserieus,\n"
	.string "da DA, n'en {STR_VAR_1} is?\p"
	.strong "Lemayonnaise lik da ze zeggn$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Oh, ajem nie moe ebbn, gin probleem.\n"
	.string "Ma min Pokémon is beeere koddig, ti ma ke zeggen…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Gelik welkne Pokémon kun koddig zin\n"
	.string "aje ze me genoeg liefde ipvoedt.\p"
	.string "Behalve Mr. Mime. Da zin vullards.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Nieuwe ploatsn, nieuwe Pokémons,\n"
	.string "ma wok, nieuwe mensn, helaas.\p"
	.string "En ze komen ton uw 'us binn',\n"
	.string "en beginnen te tetteren lik gin ander.$"

