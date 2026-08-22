OldaleTown_PokemonCenter_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, WonderTrade_OnFrame
	.byte 0

WonderTrade_OnFrame:
	map_script_2 VAR_WONDERTRADE, 0, EventScript_FirstTimeWonder_Unlimited  @0 is unlimited
	map_script_2 VAR_WONDERTRADE, 1, EventScript_FirstTimeWonder_Limited    @1 is limited
	.2byte 0															    @2 doesn't trigger first time text

SetWonderTradeModeLimited:
	setvar VAR_WONDERTRADE, 1
	return

EventScript_FirstTimeWonder_Unlimited: @0 is unlimited
	lockall
	msgbox EventScript_FirstTimeWonder_Text_Welcome, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Wondertrade_Movement_PlayerApproachCounter
	waitmovement 0
	delay 30
	msgbox EventScript_FirstTimeWonder_Text_Unlimited, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WONDERTRADE, 2 @2 doesn't trigger first time text
	releaseall
	end

EventScript_FirstTimeWonder_Limited: @1 is limited
	lockall
	msgbox EventScript_FirstTimeWonder_Text_Welcome, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Wondertrade_Movement_PlayerApproachCounter
	waitmovement 0
	delay 30
	msgbox EventScript_FirstTimeWonder_Text, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WONDERTRADE, 2 @2 doesn't trigger first time text
	releaseall
	end

Wondertrade_Movement_PlayerApproachCounter:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

EventScript_DoWonderTrade::
	goto_if_unset FLAG_WT_ENABLED, EventScript_WTNotActiveYet_NoWT
	goto_if_set FLAG_UNLIMITIED_WONDERTRADE, EventScript_DoWonderTradeStartNoLimit
	special CheckIfRandomizerIsActive
	goto_if_unset FLAG_WT_ENABLED_RANDOMIZER, EventScript_DoWonderTradeStart
	special CheckIfChallengesAreActive
	goto_if_set FLAG_WONDERTRADE3, EventScript_NoMoreForToday
	goto_if_set FLAG_NO_WT_BECAUSE_CHALLENGE, EventScript_WTChallenges
	goto_if_unset FLAG_WONDERTRADE1, EventScript_DoWonderTradeFirstTrade
	goto_if_unset FLAG_WONDERTRADE2, EventScript_DoWonderTradeSecondTrade
	goto_if_unset FLAG_WONDERTRADE3, EventScript_DoWonderTradeThirdTrade
	end

EventScript_DoWonderTradeStart:
	goto_if_unset FLAG_BADGE05_GET, EventScript_WTNotActiveYet
	msgbox EventScript_DoWonderTrade_Text_Welcome, MSGBOX_DEFAULT
	closemessage
	special CheckIfChallengesAreActive
	goto_if_set FLAG_WONDERTRADE3, EventScript_NoMoreForToday
	goto_if_set FLAG_NO_WT_BECAUSE_CHALLENGE, EventScript_WTChallenges
	goto_if_unset FLAG_WONDERTRADE1, EventScript_DoWonderTradeFirstTrade
	goto_if_unset FLAG_WONDERTRADE2, EventScript_DoWonderTradeSecondTrade
	goto_if_unset FLAG_WONDERTRADE3, EventScript_DoWonderTradeThirdTrade
	end

EventScript_WTChallenges::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_WTChallengesCancel
	goto_if_unset FLAG_WONDERTRADE1, EventScript_DoWonderTradeFirstTrade
	goto_if_unset FLAG_WONDERTRADE2, EventScript_DoWonderTradeSecondTrade
	goto_if_unset FLAG_WONDERTRADE3, EventScript_DoWonderTradeThirdTrade
	end

EventScript_WTChallengesCancel::
	msgbox EventScript_DoWonderTrade_Text_Challenges, MSGBOX_DEFAULT
	closemessage
	end

EventScript_WTNotActiveYet::
	msgbox EventScript_DoWonderTrade_Text_FiveBadges, MSGBOX_DEFAULT
	closemessage
	end

EventScript_WTNotActiveYet_NoWT::
	msgbox EventScript_DoWonderTrade_Text_EnableAfterBeatingGame, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeFirstTrade::
	setflag FLAG_WONDERTRADE1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveFirstTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_DoWonderTradeCancelSaveFirstTrade::
	clearflag FLAG_WONDERTRADE1
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeSecondTrade::
	setflag FLAG_WONDERTRADE2
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveSecondTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_DoWonderTradeCancelSaveSecondTrade::
	clearflag FLAG_WONDERTRADE2
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeThirdTrade::
	setflag FLAG_WONDERTRADE3
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveThirdTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_DoWonderTradeCancelSaveThirdTrade::
	clearflag FLAG_WONDERTRADE3
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_DoWonderTradeStartNoLimit::
	goto_if_unset FLAG_BADGE05_GET, EventScript_WTNotActiveYet
	msgbox EventScript_DoWonderTrade_Text_Welcome, MSGBOX_DEFAULT
	closemessage
	special CheckIfChallengesAreActive
	goto_if_set FLAG_NO_WT_BECAUSE_CHALLENGE, EventScript_WTChallengesUnlimited
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, EventScript_DoWonderTradeCancelSaveThirdTrade
	special ChoosePartyMon
	waitstate
	goto EventScript_DoWonderTradeTrade

EventScript_WTChallengesUnlimited::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_WTChallengesCancel
	return

EventScript_DoWonderTradeTrade::
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge EventScript_End
	copyvar VAR_0x8005, VAR_0x8004
	special CreateWonderTradePokemon
	special DoInGameTradeScene
	waitstate
	special ForceSaveGame
	waitstate
	msgbox EventScript_DoWonderTrade_Text_Done, MSGBOX_DEFAULT
	closemessage
	end

EventScript_NoMoreForToday::
	msgbox EventScript_NoMoreForToday_Text, MSGBOX_DEFAULT
	closemessage
	end

EventScript_End::
	end

EventScript_FirstTimeWonder_Text_Welcome:
	.string "Yeeps!\p"
	.string "Is 't jen eerste keer\n"
	.string "ier? Joat zeker?\p"
	.string "'k Goa jen ker utlehhen\n"
	.string "Oeda WonderTrade algelik marcheert.\p"
	.string "Komme keer iere\n"
	.string "me je dwoaze mulle.\p"
	.string "Ja, khebbet tegen u.$"

EventScript_FirstTimeWonder_Text:
	.string "Oké. Dus. WonderWissel.\n"
	.string "Wuk is da. Oe marcheert da.\p"
	.string "WonderWissel is hjil nieuwe\n"
	.string "tehnolohie, ontworpen door Balco.\l"
	.string "Ge kunt er anoniem mee\p"
	.string "Pokémon wissln en jin kriegn.\n"
	.string "Wa schuift et? Tis vo niet! Baja gij.\p"
	.string "Ge wit nwoois wada je ga kriegen\n"
	.string "en zudder wok niet.\l"
	.string "Da moakt et bjistig!\p"
	.string "Om de server nie na de klwôtn 't elpen\n"
	.string "kundje ma 3 WonderTrades per dah doen.\p"
	.string "Smoakelik! Uh ik bedoeldehe, veel plezier!$"

EventScript_FirstTimeWonder_Text_Unlimited:
	.string "Oké. Dus. WonderWissel.\n"
	.string "Wuk is da. Oe marcheert da.\p"
	.string "WonderWissel is hjil nieuwe.\n"
	.string "tehnolohie, ontworpen door Balco.\l"
	.string "Ge kunt er anoniem mee\p"
	.string "Pokémon wissln en jin kriegn.\n"
	.string "Wa schuift et? Tis vo niet! Baja gij.\p"
	.string "Ge wit nwoois wada je ga kriegen\n"
	.string "en zudder wok niet.\l"
	.string "Da moakt et bjistig!\p"
	.string "Smoakelik! Uh ik bedoeldehe, veel plezier!$"

EventScript_DoWonderTrade_Text_Welcome:
	.string "Welgekomen aan et loket WonderWissel\n"
	.string "van et Pokécenter!\p"
	.string "Voordaje een Pokémon kiest\n"
	.string "om te WonderWisseln, moek je\l"
	.string "spel ier jist ke ipsloan.$"

EventScript_NoMoreForToday_Text:
	.string "Seg, profiteurke...\n"
	.string "Ge zit gie al aan je maximum van drie.\p"
	.string "Morhen meug je werekommen!$"

EventScript_DoWonderTrade_Text_Done:
	.string "We hopen daje vree hoet èt\n"
	.string "geWonderWisseld!$"

EventScript_DoWonderTrade_Text_Challenges:
	.string "Gie èt bepoalde Utdoagingn\n"
	.string "gevroagd. Ge meugt werekommen\l"
	.string "aje de Pokémon Liga versloan èt.$"

EventScript_DoWonderTrade_Text_FiveBadges:
	.string "Dju, et WonderWissel systeem\n"
	.string "marcheert noh niet. Ge goat 'n andere\l"
	.string "ki moeten wjirre kommen.$"

EventScript_DoWonderTrade_Text_EnableAfterBeatingGame:
    .string "Et WonderWissel systeem werkt nog nie.\n"
    .string "Enkel erkende Kampioenen\l"
    .string "zin welgekommen!$"
