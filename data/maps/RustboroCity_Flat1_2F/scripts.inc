.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Elknen dag is lastig…\p"
	.string "Wuk datter lastig ès?\n"
	.string "Kgoat je ke zehhen é.\p"
	.string "Utzoekn wuk dak iederen dag moe\n"
	.string "fretten. Tkan toch alledoagn gin\p"
	.string "'utsepot zin zeker?\n"
	.string "Alhoewel...$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Hoi!\n"
	.string "Welkom bij familie Peper.\p"
	.string "Ke een vroagsje.\n"
	.string "Ejegie woois al gebabysit?\p"
	.string "Kzinkik een nieuwe voader é, enneh,\n"
	.string "et hele 'babygebeuren', is nieuw voor ik.\p"
	.string "Kzit met iets. Min dochter,\n"
	.string "Walda, ze lacht nie genoeg.\p"
	.string "Kpeize da ze zou lachen moest ik\n"
	.string "ntwa geestig zeggen.\p"
	.string "Kendje gie gin olijk woordje\n"
	.string "daddeur miskien zou doen lachen?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "De loatsten tid zit ik “{STR_VAR_1}”\n"
	.string "te zeggen om eur te plezieren.\p"
	.string "Kendje miskien nog een beter woord of\n"
	.string "zinneke da ze vort mee zou lihhen?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Ah, bere.\n"
	.string "Allez, laat maar oren é.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Allez?\p"
	.string "Ewel, moest je toch nog ip ntwa\n"
	.string "komn, loat ma herust weetn é.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Allez dan.\n"
	.string "Kzin jin en al oor.$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Ahaha! Ze ligt hjil vort!\n"
	.string "Kmoe der zelve van lachen! Hahaha!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, I see.\n"
	.string "Well, let's give it a try, shall we?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… ze kiekt bere serieus algelik.\n"
	.string "Miskien is Walda een serieus kind…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Dus ge kunt ip niet komn.\n"
	.string "Kgoa ton zelve iet uitkiezen é.\p"
	.string "Hmm…\n"
	.string "Wuk peisdje van “{STR_VAR_1}”?\l"
	.string "Ke proberen e.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… nint, nint...\n"
	.string "Miskien is Walda een serieus kind…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Ah, dus ge kent gie gin goei woordn.\n"
	.string "Kga ton zelve de zinnekes gebrukn\l"
	.string "da ze geestig vindt.\p"
	.string "Ma, kzehhet, moest er nog ntwa\n"
	.string "binn'skietn, loat ma weetn é.$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Merci whé!\p"
	.string "Tis dankzij u da min Walda\n"
	.string "eindelik zo lief lacht!\p"
	.string "Moej ke wa weetn, kzie der nie\n"
	.string "specioal ut ma, ik werk ier in\l"
	.string "Balco, al hjil mn leven.\p"
	.string "Jen PC, ie draai verzekers nog\n"
	.string "Rutte Achteneehntig?\p"
	.string "Den dag van vandoage, al die DOZEN\n"
	.string "ip PC, die folders é, da is jin pot nat.\l"
	.string "Me min programma, goa je\p"
	.string "de achtergrond van je Dozn kunn\n"
	.string "aanpass'n. Machtig é.\p"
	.string "Ge moet et zoekn int menu waardat er\n"
	.string "'Moatn' sta'.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "Nen immens ljlijke knuffel genaamd 'Honnepon'!$"

