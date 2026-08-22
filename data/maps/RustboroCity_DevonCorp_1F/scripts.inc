.set LOCALID_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Ge zijt welhekomn in\n"
	.string "BALCO.\p"
	.string "Wudr moakn vanalles\n"
	.string "daje leevn verbeterd of in elk\p"
	.string "ons bakkn held doe skeppn.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Jin van onze mindr competente\n"
	.string "onderzoekers es wel bestoln zeker...\p"
	.string "..wiedat er diene witi aanhenomn èt..$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Eyy, die lwopskoen'!\n"
	.string "Da is ons product!\p"
	.string "Twôn ke je Strava?\n"
	.string "Nie mis, nie mis...\p"
	.string "Fak gij kunt sjette heevn.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Da hestoln pakske…\p"
	.string "Tes wel belangrik..mo\n"
	.string "enkel wudr kunn' da hebrukn..\p"
	.string "Ik peizekik, da dien dief\n"
	.string "nie et skerpste mes es..$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Tskint da da hestoln pakske\n"
	.string "terug is? Aba daddis hoe nieuws!$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Tspit mie zjir, ma enkel\n"
	.string "hemahhtihd personeel mah ier binn'.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Echt hat-ahhterlik..\n"
	.string "WUDDR? BESTOLEN?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Ah, tis GIJ!\n"
	.string "Gie é!\p"
	.string "Gie..gie zie ier alsan welkom!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Stukkn van stjinnen en stukkn\n"
	.string "metoal wôr'n tenteunhesteld.\p"
	.string "Der stoat een plakkoat\n"
	.string "me een pak tekst…\p"
	.string "“Balco is begonnen in 19-..”\n"
	.string "{PLAYER}{KUN}: Soai!$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Prototypn en testproductn wôrdn\n"
	.string "tenteunhesteld achter 't hlas.\p"
	.string "Me een beskrivingske natuurlik…\p"
	.string "“Balco heeft z'n industrieel gamma\n"
	.string "uitgebreid naar allerlei\l"
	.string "levensstijl-producten zoals\p"
	.string "loopschoenen of gereeschap voor Temmers.\n"
	.string "Zoals Poké Balls en Smartphones.”\l"
	.string "{PLAYER}{KUN}: Amai zeg!$"

