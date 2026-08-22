.set LOCALID_EXPERT_M, 4
.set LOCALID_TWIN, 5
.set LOCALID_SCHOOL_KID_M, 7
.set LOCALID_PSYCHIC_M, 8

DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Wuk dat de nieuwen trend is?\n"
	.string "Kgoat je ké zehhen é.\l"
	.string "“{STR_VAR_1}”!\p"
	.string "Wuk zou me leevn nog woard zin\n"
	.string "zonder de hlorie van “{STR_VAR_1}”?$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Wuk da de nieuwste rage is?\n"
	.string "Moeje gie da zelve nog vroagn?\l"
	.string "“{STR_VAR_1}”!\p"
	.string "Aba natuurlik da.\p"
	.string "Wuk peisdje dat er na ga komm'n?$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "'k Lere minne Zigzagoon alles ovr\n"
	.string "“{STR_VAR_1},”\l"
	.string "mo ie verstoat er gin klootn van.\p"
	.string "Den onzen is e bitje hardleers.\n"
	.string "Mo ie kun al iptelln!$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Ik wille olles weetn\n"
	.string "euvr “{STR_VAR_1}”.\p"
	.string "Mo ge moe verdr kiekn daje neuze\n"
	.string "lang es. Denk heweun ke na.\p"
	.string "Pakt nu ke “{STR_VAR_1}”\n"
	.string "En ton “{STR_VAR_2}”.\p"
	.string "Zyn jen ohen al op'n? Ziejet licht?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Moh!\n"
	.string "Ik èt alsan heweten!\p"
	.string "Min populariteit goat hin\n"
	.string "hrenzn mé kenn'n!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "WUKDADDE?!\n"
	.string "Aja?! Allez gie. Mohow zeg.\p"
	.string "'t Es godverdomme moeilik om vandoag\n"
	.string "den dag nog mee te zin whè!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Kenkik da histern hwêurd ip TV!\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Meugn ze da wel zehhen?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Over den oceaan…\p"
	.string "Zou “{STR_VAR_1}”\n"
	.string "noh populairder zin?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "'k Verkwôpe 'k ik officiële\n"
	.string "“{STR_VAR_1}”\l"
	.string "tshirts, 'imdjes, bandjes.\p"
	.string "Noem moar ip.\n"
	.string "“{STR_VAR_1}” popp'n, joat…\p"
	.string "Officiële “{STR_VAR_1}”\n"
	.string "koss'n, tzal wel zin…\p"
	.string "En helicensieerde\n"
	.string "“{STR_VAR_1}”\l"
	.string "kleurboekn, aja é.\p"
	.string "Zo...dus giij wilt een aandeel?\p"
	.string "Mag niet!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "KEN HET VERSCHIL!\n"
	.string "“{STR_VAR_1}” &\l"
	.string "Slechte “{STR_VAR_1}”…\p"
	.string "De link tussen\n"
	.string "“{STR_VAR_1}” en\l"
	.string "Pokémon…\p"
	.string "Nuttige\n"
	.string "“{STR_VAR_1}”…\p"
	.string "{PLAYER}: Aje dien bucht leest\n"
	.string "over “{STR_VAR_1}” keldert\p"
	.string "jen IQ..$"

DewfordTown_Hall_Text_TrendsScream:
	.string "“De lokkreet van {STR_VAR_1}”\n"
	.string "is den titel.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "De skwone hlimlach van\n"
	.string "“{STR_VAR_1}”\l"
	.string "is den titel.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Den titel es “De loatste\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Den titel es\n"
	.string "“De jammerlike heboorte van\l"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "'k Ekkik “{STR_VAR_1}” hezien\n"
	.string "Bjistig é.\p"
	.string "'t Is, lik, et coolste datter is!\p"
	.string "Twas demax! Zoalig.\n"
	.string "'k Valle bikan achtrovr amai zeg!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Nint, nint, nint.\p"
	.string "Da daje davers zag..\n"
	.string "“{STR_VAR_1}”,\l"
	.string "da wast nie eihenlik.\p"
	.string "Et échte artikel was mjir…\n"
	.string "Oe moek et zehhen? Allez.\l"
	.string "Et 'ad een..eh..\p"
	.string "Jenesaisquoi. Iets mahhtig.$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Ey, lustert, 'k eb e liedje hemoakt\n"
	.string "vo “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}”\n"
	.string "is de nieuwste rage é.\p"
	.string "Oké! Lustert hôed é!\n"
	.string "… …\p"
	.string "Oh!\n"
	.string "{STR_VAR_1}!\p"
	.string "Machtig!\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "'k Goat je ke zeggen é.\n"
	.string "Aje nog jin ki zingt,\l"
	.string "tga “{STR_VAR_1}.”\l"
	.string "ip uw mulle zin. Verstoan?!$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Oe dan ook, ti lik dak zeije,\n"
	.string "we zoddn moetn twôpekom'n en een\l"
	.string "“{STR_VAR_1}” fjistjeuh\l"
	.string "orhaniseren ip ons eiland.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Een mahhtig vwôrstel al zehhiket zelve!\p"
	.string "Da goa definitief beslecht'n\n"
	.string "wiendadde den bestn es in\l"
	.string "“{STR_VAR_1}.”\l"
	.string "Joat, daddis mahhtig!\p"
	.string "Zeg dakkik et gezegd é,\n"
	.string "et leven draait om\l"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "'k Was 'k ik aant peizen é…\p"
	.string "Vindje wok nie da\n"
	.string "“{STR_VAR_1}” hehroeid\l"
	.string "es van ntwa onbenulligs\l"
	.string "tot ntwa van oes doaheliks leevn?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Wadde?\n"
	.string "WUK ZEG JE?\p"
	.string "Ik zin HHHARD. HOORS.\n"
	.string "“{STR_VAR_1}”???\l"
	.string "Aaaah ma zegt da ton!\l"
	.string "Kbenkik nie gans doof.\p"
	.string "Enkel selectief. En vo\n"
	.string "“{STR_VAR_1}”\l"
	.string "zet ik min oren open whé!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Als wuddr een team vorm'n é,\n"
	.string "dan zyn we toch nie te stopn?\l"
	.string "en zjikr wanneer da 't aankomt ip\l"
	.string "dingn lik “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Boenk derip moat!\p"
	.string "Wudr, wudr zyn et\n"
	.string "“{STR_VAR_1}” Duo!\p"
	.string "Is da hin mahhtig beeld?\n"
	.string "Hahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Die eilandbewoners ier\n"
	.string "zin echt geskift.\p"
	.string "Oe noemdje zelf ntwien van De Panne?\n"
	.string "N'en Depanneur? E pannenkoek?\p"
	.string "Kzie daje je lach moe in'oddn.\n"
	.string "Ierse, das een cadeautje.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "“{STR_VAR_1}” is ça va.\p"
	.string "Ma yow, Sludge Bomb,\n"
	.string "daddis pas ntwadde.\l"
	.string "Njie..?$"

