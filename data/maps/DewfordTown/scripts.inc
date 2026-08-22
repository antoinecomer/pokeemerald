@ Sailing to and from Dewford uses local IDs from different maps
@ e.g. Route 104's sail to Dewford script references local IDs from Dewford's map
@ All of these local IDs are labeled here
.equ LOCALID_BRINEY_DEWFORD, 2
.equ LOCALID_BOAT_DEWFORD, 4

.equ LOCALID_BOAT_R109, 1
.equ LOCALID_BRINEY_R109, 2

.equ LOCALID_BOAT_R104, 7
.equ LOCALID_BRINEY_R104, 8

DewfordTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, EncounterTable
	.byte 0

DewfordTown_OnTransition:
	callnative ChangeEncounterTable
	setflag FLAG_VISITED_DEWFORD_TOWN
	end

DewfordTown_EventScript_Briney::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, DewfordTown_EventScript_ReturnToPetalburgPrompt
	message DewfordTown_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 21, 6, MULTI_BRINEY_ON_DEWFORD, 2, FALSE
	switch VAR_RESULT
	case 0, DewfordTown_EventScript_ChoosePetalburg
	case 1, DewfordTown_EventScript_ChooseSlateport
	case 2, DewfordTown_EventScript_CancelSailSelect
	case MULTI_B_PRESSED, DewfordTown_EventScript_CancelSailSelect
	end

DewfordTown_EventScript_ChoosePetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	release
	end

DewfordTown_EventScript_ChooseSlateport::
	msgbox DewfordTown_Text_SlateportWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToSlateport
	release
	end

DewfordTown_EventScript_CancelSailSelect::
	msgbox DewfordTown_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
	closemessage
	release
	end

DewfordTown_EventScript_ReturnToPetalburgPrompt::
	msgbox DewfordTown_Text_SetSailBackToPetalburg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_SailBackToPetalburg
	msgbox DewfordTown_Text_GoDeliverIllBeWaiting, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailBackToPetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail2, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	end

DewfordTown_EventScript_Woman::
	msgbox DewfordTown_Text_TinyIslandCommunity, MSGBOX_NPC
	end

DewfordTown_EventScript_TownSign::
	msgbox DewfordTown_Text_TownSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_GymSign::
	msgbox DewfordTown_Text_GymSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_HallSign::
	msgbox DewfordTown_Text_HallSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, DewfordTown_EventScript_HowsFishing
	msgbox DewfordTown_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_GiveOldRod
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_NotGettingItchToFish
	end

DewfordTown_EventScript_GiveOldRod::
	msgbox DewfordTown_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox DewfordTown_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_NotGettingItchToFish::
	msgbox DewfordTown_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_HowsFishing::
	message DewfordTown_Text_HowsYourFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
	goto_if_eq VAR_RESULT, 0, DewfordTown_EventScript_FishingExcellent
	goto_if_eq VAR_RESULT, 1, DewfordTown_EventScript_FishingNotSoGood
	end

DewfordTown_EventScript_FishingExcellent::
	msgbox DewfordTown_Text_GreatHaulInSomeBigOnes, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_FishingNotSoGood::
	msgbox DewfordTown_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailToPetalburg::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN, 0
	applymovement LOCALID_BRINEY_DEWFORD, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_DEWFORD
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_DEWFORD, DewfordTown_Movement_SailToPetalburg
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_SailToPetalburg
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
	call Common_EventScript_StopBrineysBoatMusic
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_ExitBoatPetalburg
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat LOCALID_BOAT_DEWFORD, MAP_DEWFORD_TOWN
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 2
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 5, 4
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	waitstate
	release
	end

DewfordTown_EventScript_SailToSlateport::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN, 1
	applymovement LOCALID_BRINEY_DEWFORD, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_DEWFORD
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_DEWFORD, DewfordTown_Movement_SailToSlateport
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_SailToSlateport
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE109
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_ExitBoatSlateport
	waitmovement 0
	setobjectxyperm LOCALID_BRINEY_R109, 21, 26
	addobject LOCALID_BRINEY_R109
	setobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE109, 0
	applymovement LOCALID_BRINEY_R109, DewfordTown_Movement_BrineyExitBoat
	waitmovement 0
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	addobject LOCALID_BOAT_R109
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat LOCALID_BOAT_DEWFORD, MAP_DEWFORD_TOWN
	call_if_unset FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateportDeliverGoods
	call_if_set FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateport
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	resetobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE109
	copyobjectxytoperm LOCALID_BRINEY_R109
	release
	end

DewfordTown_EventScript_LandedSlateportDeliverGoods::
	msgbox DewfordTown_Text_BrineyLandedInSlateportDeliverGoods, MSGBOX_DEFAULT
	return

DewfordTown_EventScript_LandedSlateport::
	msgbox DewfordTown_Text_BrineyLandedInSlateport, MSGBOX_DEFAULT
	return

DewfordTown_Movement_SailToPetalburg:
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_SailToSlateport:
	walk_right
	walk_fast_right
	walk_fast_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

DewfordTown_Movement_PlayerBoardBoat:
	walk_right
	walk_up
	step_end

DewfordTown_Movement_ExitBoatPetalburg:
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_ExitBoatSlateport:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

DewfordTown_Movement_BrineyBoardBoat:
	walk_up
	step_end

DewfordTown_Movement_BrineyExitBoat:
	walk_up
	walk_up
	step_end

DewfordTown_EventScript_TrendyPhraseBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Text_XIsTheBiggestHappeningThingRight, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_ConfirmTrendyPhrase
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_RejectTrendyPhrase
	end

DewfordTown_EventScript_ConfirmTrendyPhrase::
	msgbox DewfordTown_Text_YeahDefinitionOfInRightNow, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_RejectTrendyPhrase::
	msgbox DewfordTown_Text_TellMeWhatsNewAndIn, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_EventScript_GiveNewTrendyPhrase
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_EventScript_CancelNewTrendyPhrase
	end

DewfordTown_EventScript_GiveNewTrendyPhrase::
	incrementgamestat GAME_STAT_STARTED_TRENDS
	goto_if_eq VAR_0x8004, FALSE, DewfordTown_EventScript_PhraseNotTrendyEnough
	msgbox DewfordTown_Text_OfCourseIKnowAboutThat, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_CancelNewTrendyPhrase::
	msgbox DewfordTown_Text_HearOfAnyTrendsComeShareWithMe, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_PhraseNotTrendyEnough::
	msgbox DewfordTown_Text_XHuhIThinkYIsCool, MSGBOX_DEFAULT
	release
	end

DewfordTown_Text_TinyIslandCommunity:
	.string "De Panne is een klin eilandje.\n"
	.string "En wudr zin e' hhhehhte heminschap.\l"
	.string "'Echt en echte, verstoajt?$"

DewfordTown_Text_TownSign:
	.string "De Panne\n"
	.string "“E panne is e komvormige diepte in e dunne”$"

DewfordTown_Text_GymSign:
	.string "De Panne Pokémon Gym\n"
	.string "Leider: Brawly\l"
	.string "“Een hrwôte holve ip uw mulle!”$"

DewfordTown_Text_HallSign:
	.string "De Kuppe van De Panne\n"
	.string "“Woada nieuwe trends ontstoan!”$"

Route104_Text_LandedInDewfordDeliverLetter:
	.string "Mr. Pekel: Ahoy m'n moatje!\n"
	.string "We zin wudr aangemeerd in De Panne.\p"
	.string "Gie ging algelik een brief\n"
	.string "afgeven aan, allée, uh, ah! De Steven!$"

DewfordTown_Text_SetSailBackToPetalburg:
	.string "Mr. Pekel: Eje jen brief\n"
	.string "afgegevn, mr. de postbode? Harhar!\p"
	.string "Of wildje miskien weere na\n"
	.string "Poperinge?$"

DewfordTown_Text_PetalburgWereSettingSail2:
	.string "Mr. Pekel: AHOY M'N MOATJES!\p"
	.string "LICHT ET ANKER! IP NA POPERINGEU!\n"
	.string "Pico! Hijs et zeil, min kleintje!\p"
	.string "Pico: Piiiiiiiiii!!$"

DewfordTown_Text_GoDeliverIllBeWaiting:
	.string "Mr. Pekel: 'k Goa 'k ik ier me Pico\n"
	.string "de wacht 'odn totdaje die brief\p"
	.string "'et verstuurd.$"

DewfordTown_Text_BrineyLandedInDewford:
	.string "Mr. Pekel: Ahoy m'n moatjes!\n"
	.string "We zin oan wal gekomen!\p"
	.string "Gif mie 'n seintje é,\n"
	.string "wanneer da de zee u roept!$"

DewfordTown_Text_WhereAreWeBound:
	.string "Mr. Pekel: Ahoy m'n moatje!\n"
	.string "De zee roept...ik voel et, Pico wok!\p"
	.string "M'n moatje, nawa goan we?$"

DewfordTown_Text_PetalburgWereSettingSail:
	.string "Mr. Pekel: AHOY M'N MOATJES!\p"
	.string "LICHT ET ANKER! IP NA POEPERINGE!\n"
	.string "Pico! Hijs et zeil, min kleintje!\p"
	.string "Pico: Piiiiiiiiii!!$"

DewfordTown_Text_SlateportWereSettingSail:
	.string "Mr. Pekel: AHOY M'N MOATJES!\p"
	.string "LICHT ET ANKER! IP NA NIEUWPOORT!\n"
	.string "Pico! Hijs et zeil, min kleintje!\p"
	.string "Pico: Piiiiiiiiii!!$"

DewfordTown_Text_JustTellMeWhenYouNeedToSetSail:
	.string "Mr. Pekel: Gif mie 'n seintje é,\n"
	.string "wanneer da de zee u roept!$"

DewfordTown_Text_GettingItchToFish:
	.string "Vissn is bjistig.\n"
	.string "Ist bij u ook fris aan de vis?$"

DewfordTown_Text_GiveYouOneOfMyRods:
	.string "Daddis hesproken, een woar'id\n"
	.string "lik een zeekoe godvertoeme!\p"
	.string "Witje wa da mie ipwarmt? Abaja. Vissn!\p"
	.string "Iere, n'en 'engel van dezen engel.$"

DewfordTown_Text_ThrowInFishingAdvice:
	.string "A's een bonus, hratis en vo niet,\n"
	.string "een bitje advies vo goe te vissen!\p"
	.string "Jist, stoart na de zji,\n"
	.string "en hebrukt ton jen 'engel.\p"
	.string "Moakt je koppeke leeg…\n"
	.string "In min heval is da snel hedoan, ahaha!\p"
	.string "Ma serieus, me klinne visjes\n"
	.string "moej ma jin ke trekkn.\l"
	.string "Ma me hrwôte vissn moeje lettn ip uw\l"
	.string "ritme en ipt juste moment trekkn.\p"
	.string "Ah en belangrik, aje 'kettingvist'\n"
	.string "kundje Pokémon van 'n ander kleurke\l"
	.string "vinden! Machtig é..\p"
	.string "Kettingvissn betekent daje de\n"
	.string "wilde Pokémon versloat en direct\l"
	.string "ipnieuw vist ip dezelfde ploatse.\p"
	.string "Aje weglwôpt of zelve versloan wurd,\n"
	.string "versliesdje jen combo!$"

DewfordTown_Text_ThatsTooBadThen:
	.string "Wuk zegdje gij nu.\n"
	.string "Voeldje die wind niet?$"

DewfordTown_Text_HowsYourFishing:
	.string "Yo!\n"
	.string "Oe ist me 't vissn?$"

DewfordTown_Text_GreatHaulInSomeBigOnes:
	.string "Allez gij! Mahhtig!\n"
	.string "Gij vangt ze zeker? Vissen é! Ahahah!$"

DewfordTown_Text_FishingAdvice:
	.string "Momomo. Nie truntn! Gie kunt da!\n"
	.string "Een bitje advies vo goe te vissen:\p"
	.string "Jist, stoart na de zji,\n"
	.string "en hebrukt ton jen 'engel.\p"
	.string "Moakt je koppeke leeg…\n"
	.string "In min heval is da snel hedoan, ahaha!\p"
	.string "Ma serieus, me klinne visjes\n"
	.string "moej ma jin ke trekkn.\l"
	.string "Ma me hrwôte vissn moeje lettn ip uw\l"
	.string "ritme en ipt juste moment trekkn.\p"
	.string "Ah en belangrik, aje 'kettingvist'\n"
	.string "kundje Pokémon van 'n ander kleurke\l"
	.string "vinden! Machtig é..\p"
	.string "Kettingvissn betekent daje de\n"
	.string "wilde Pokémon versloat en direct ipnieuw\l"
	.string "vist ip dezelfde ploatse.\p"
	.string "Aje weglwôpt of zelve versloan wurd,\n"
	.string "versliesdje jen combo!$"

DewfordTown_Text_XIsTheBiggestHappeningThingRight:
	.string "'k Zin zot van wa da de mode is. Wa da 'ip is.\n"
	.string "Allez. Hhhip é!\p"
	.string "Lustert, eje gie al gwôrd van\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Bajoat!\n"
	.string "Tuurlik dajt kent!\p"
	.string "Kbedoel, howzeg,\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Tis echt wel..hhhet van hhhet é!\p"
	.string "Vanwoar daje ook zit,\n"
	.string "“{STR_VAR_1}”\l"
	.string "is echt wel dé shit toch?$"

DewfordTown_Text_TellMeWhatsNewAndIn:
	.string "Hunh?\n"
	.string "'t Is nie wada nu 'in' is?\p"
	.string "Ik smeek u, zeg et mie.\n"
	.string "Wuk goan de me'sn peizn over ik\p"
	.string "moestn ze wjitn dak ne fraudeur zin?$"

DewfordTown_Text_OfCourseIKnowAboutThat:
	.string "Hunh?\n"
	.string "“{STR_VAR_2}”?\p"
	.string "… …\p"
	.string "…Uh… Joat! Ti woa!\n"
	.string "Joak, 'k Wiste da whé! Alsan heweten!\p"
	.string "Tuurlik da!\n"
	.string "“{STR_VAR_2},” é?\p"
	.string "Joat, joat, daddist!\n"
	.string "“{STR_VAR_2}” is ma'hhtig\l"
	.string "kzegge da hjilsan!\p"
	.string "Letterlik olle doagn zelf!\n"
	.string "Peisdje gie dak da nie zou kenn'?\p"
	.string "“{STR_VAR_1}”…das lik…\n"
	.string "zoooo passé. Da wa 5 min geleden.\p"
	.string "Mo, “{STR_VAR_2}”?\n"
	.string "Daddist er boenk op!$"

DewfordTown_Text_XHuhIThinkYIsCool:
	.string "Hmm…\n"
	.string "“{STR_VAR_2},” é?\p"
	.string "Ma ik, persoonlik\n"
	.string "“{STR_VAR_1}”\l"
	.string "daddis woar min erte liht.$"

DewfordTown_Text_HearOfAnyTrendsComeShareWithMe:
	.string "Zeggeh, aje een nieuwe trend 'oort,\n"
	.string "gie loat et mie als jiste weetn é, toch?$"

DewfordTown_Text_YeahDefinitionOfInRightNow:
	.string "Joat, tis juste!\p"
	.string "“{STR_VAR_1}” es echt\n"
	.string "DE definitie van “in” ipt moment.$"
