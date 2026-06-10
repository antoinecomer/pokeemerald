.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Gij…\n"
	.string "Moh, tis gij! {PLAYER}{KUN}!\p"
	.string "N'en dikke merci om onze Wally\n"
	.string "om te goan. Da doe em goe.\p"
	.string "Dien is alsan wa zwak en ziek\n"
	.string "geweest, al bie de geboorte!\p"
	.string "We hebben em gestuurd na zin tante\n"
	.string "in Veurne. 't Is omda\p"
	.string "de luchtkwaliteit\n"
	.string "doar vjille beter es.\p"
	.string "Watte? Onzne Wally?\n"
	.string "Dien is al weh.\p"
	.string "Ma 'k zeg et, da fijnstof,\n"
	.string "daddis gin lachertje whe!$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Oe zot zin me onz'ne Wally?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Onze excuses\n"
	.string "daje zo verre zie moetn terten.\p"
	.string "Onz'ne Wally is vjille hezonder\n"
	.string "hewordn sinds zinne verrus na Veurne.\p"
	.string "We zin u nog alsan stif!\p"
	.string "dankbaar daje em g'olpen èt\n"
	.string "me zin jiste Pokémon te vang'n.\p"
	.string "Daddèt em wa moed inhefluistert\n"
	.string "happy.\p"
	.string "En 'n is nie juste de Wally.\n"
	.string "Ik, zin voadre, ben wok\p"
	.string "bèèèèèèèèèèèèère content\n"
	.string "dat ie e moatje lik gie eeft.\p"
	.string "Tis nie om u om te kop'n,\n"
	.string "ma kzou wil'n daje dadier ebt.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Aje kun surfen, me al da woatr ier,\n"
	.string "ne mens geroakt algelik ergens é.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "Onz'ne Wally kom in de noaste\n"
	.string "doagn nar us. 'k Kik ernoar ut!$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Wadde? ONZ'NE WALLY?\n"
	.string "IN BRUSSEL?\p"
	.string "Hah, {PLAYER}{KUN}, das e goedje.\p"
	.string "Gij zijt gij de grappigsten thus\n"
	.string "zeker? Zo ambitieus is onze zeun\l"
	.string "totaal nie.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "Onz'ne Wally was zo content dat ie\n"
	.string "me u ne Pokémon is goan vangn, echt woa.\p"
	.string "Ie kwam thus me een berehrote hlimlach\n"
	.string "'Check et ut! Min jiste Pokémon!'.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "'k Zo willen dajetnie deurevertelt aan\n"
	.string "aan minne vint…\p"
	.string "Ma onz'ne Wally is weg-hehlipt van\n"
	.string "van z'n famille in Veurne.\p"
	.string "Witje, ie ziet er miskien soms\n"
	.string "tenger en fragiel ut ma zn karakter is \l"
	.string "iezersterk. Als odders motn we'em mjir\p"
	.string "vetrouwn schenkn en em durvn losloatn!$"

