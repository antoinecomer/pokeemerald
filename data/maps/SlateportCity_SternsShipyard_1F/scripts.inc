.set LOCALID_DOCK, 1

SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Umm… hmmm…\n"
	.string "da rond stukske, past perfect…\p"
	.string "in da vierkant hatje.\n"
	.string "En da drie'oekih stuk?\p"
	.string "Da goa wok in et vierkant hat.\n"
	.string "Erhert mie da? Banin.$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hm?\n"
	.string "Aa hoeidaag, ik ben Mr. Pongtong.\p"
	.string "Kapt. Mortimer é mie hevroagd van\n"
	.string "ne ferry t'ontwerp'n.\p"
	.string "Moh! Daddès…\n"
	.string "Is da van Balco?\p"
	.string "Mo, hmm…\n"
	.string "Nint…da ga nie goan.\p"
	.string "Kapt. Mortimer es wjir goan zant'n.\n"
	.string "Dju é.\p"
	.string "Zoudje Kapt. Mortimer kunn' vind'n\n"
	.string "en em da gon afgeevn? Merci whé.$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "Pongtong: Kapt. Mortimer es wjirre\n"
	.string "gon zant'n.\p"
	.string "Zoudjem kunn' vind'n en em da\n"
	.string "pakketje kunn' afgeevn? Merci whé.$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "Pongtong: N'en bwôt, daddis e kunstwerk.\p"
	.string "Ge kun nie olles weetn met et geweune\n"
	.string "ut te reken'n.\p"
	.string "'k Zou 'k ik stiff heholp'n zin\n"
	.string "deur ntwien daddecht de zji kent…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "Pongtong: Elk zinnen h'ndag!\n"
	.string "Kzin beeeere content.\p"
	.string "En witje waaroem?\p"
	.string "De jinnigste echte Mr. Pekel komt\n"
	.string "elp'n om de ferry af te werk'n.\p"
	.string "Mahhtig toch.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "Pongtong: De ferry is gerji!\p"
	.string "De speksplinternieuwe S.S. Het Ei\n"
	.string "is e wonder van technolohie!\p"
	.string "En toch èk et hevoel\n"
	.string "dak et zelve NOH beter kun moakn.\p"
	.string "Witje é, technolohie é, dat stopt\n"
	.string "nwoois me vorutgoan.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "Mr. Pekel: Ah, {PLAYER}{KUN}!\n"
	.string "AHOI M'N MOATJE!\p"
	.string "Aye, kzinkik n'en odd'n zji-ond, mo\n"
	.string "sin's daje gie min Pico hered é,\l"
	.string "bloast er wjirre wind in me zeil'n!\p"
	.string "Damée dak beslot'n eb voor oes moatje\n"
	.string "ier, Mr. Pongtong, wuk e noame trouwes,\l"
	.string "'n andje t'elp'n. Want anders\l"
	.string "zitt'n wudr ier volhend joar noh!\p"
	.string "Me zin kennis van de nieuwste tech-\n"
	.string "nolohie en min ervoaringe,\l"
	.string "goan we den bouw van de ferry\l"
	.string "zjirre kun afwerk'n!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Seizoenen, 't wjir, de wind,\n"
	.string "de moane en zin reflectie…\p"
	.string "Die verandrn ollemolle\n"
	.string "et hezicht van de zji.\p"
	.string "Tès zjuste dadde!\n"
	.string "De zji es iet levends!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "'k Wordn hemakkelik zjiziek.\n"
	.string "Dus ik moak min ier nuttih\p"
	.string "vo de heminskap.$"

