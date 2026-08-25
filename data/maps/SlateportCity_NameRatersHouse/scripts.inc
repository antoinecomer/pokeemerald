SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Yo, yo, yo! W fit!!\n"
	.string "Ik benne de Koosnoam-expert!\p"
	.string "Stoa min toe va je koosnoamkes\n"
	.string "te bwoordjiln.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Wukn koosnoamke moek\n"
	.string "bekikkn?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "{STR_VAR_1} … … … …\n"
	.string "Et is een W!\p"
	.string "Ma! Ik peize, allez,\n"
	.string "howja, ge kunt ermee na butn\l"
	.string "komm'n, ma 't kun zelf nog bet'r.\p"
	.string "Wa peisdje?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ahh, kwist daje joa ginge zeggen..\n"
	.string "Wa wurd zin nieuw koosoamke?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Voilà se! Loat et heweten zyn.\n"
	.string "Vanaf nu zuldje gie hekend zyn\l"
	.string "als {STR_VAR_1}!\p"
	.string "Helukzak daje zyt!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Ahh, kwist daje nin ginge zeggen..\n"
	.string "Me die noam'n, ge farmt gie al aura!$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Voilà se! Loat et heweten zyn.\n"
	.string "Vanaf nu zuldje gie hekend zyn\l"
	.string "als {STR_VAR_1}!\p"
	.string "Tes krak etzelfde als davers, ma ip\n"
	.string "e bepoalde manier toch superieur!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "{STR_VAR_1}……………!\p"
	.string "{STR_VAR_1}! {STR_VAR_1}!!!!\n"
	.string "Dit...dit es houd! Me een hee na beneden.\p"
	.string "Droag ma hoêd zorh vo\n"
	.string "{STR_VAR_1}! Nu en altid!$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Daddis een Ei.\n"
	.string "Just lik gij! Pipo!$"

