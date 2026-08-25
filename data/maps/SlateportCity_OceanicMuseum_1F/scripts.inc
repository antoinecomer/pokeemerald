.set LOCALID_FAMILIAR_GRUNT, 13

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Welkom in 't Maritiem Museum.\p"
	.string "Den entrée is ¥50.\n"
	.string "Wildje een ticketje?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Heniet ervan é zeg.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Oh? Tspit mie zjir, ma 't museum es\n"
	.string "heslot'n vo SCHOOIERS.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Oh? Zije gie wok jin van die\n"
	.string "fanatiekeling'n?\p"
	.string "Ge zie de enihsten die te loate es.\n"
	.string "Gif ma sjette!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Wudr, van Team Aqua, wudr zin d'enige\n"
	.string "die de wjirld kunn' redd'n!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Wudr ad'n ier vergoaringe mo,\n"
	.string "kond'n we da nie via Teams doen…\p"
	.string "De hrwôtn Boas is ier toch nie.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Wa als ik ier ne pot soep\n"
	.string "over zoe kapp'n?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "'k Wit da'k ier ip klimaatmissie zin, ma\n"
	.string "'k doe wok heweun geirn museums…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Moest'n oeze colleha's in Kortrik\n"
	.string "gin prutsers zin, zoatn w'ier nie!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "'k N' ad gin ¥50 ip zak.\n"
	.string "De receptioniste noemde mie ne skooier.\p"
	.string "Zuur...$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Wistje datter ier woois ne Wailord es\n"
	.string "aanhespoeld? Dat arm bjistje..$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Minnen 'eld, daddis Kapitein Mortimer.\n"
	.string "Kwil de zji verkenn' lik em!\p"
	.string "'t Is em of, aba natuurlik, de GOAT!\n"
	.string "Mr. Pekel!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "De zji is diep.\n"
	.string "Zo…oneindih…diepe…\p"
	.string "Der moe zovjil leevn zin in onderwoatr\n"
	.string "dawe gin klôotn vanaf weetn.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "'k Wille zo geirn ne Pokémon van de zji.\p"
	.string "Meddal da woatr ier, aje gin èt,\n"
	.string "dan is jen ervarink, kzo zehhen\p"
	.string "moar een 7.8/10 woard ofzo.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Eyeyey, shh!\n"
	.string "Wuk doeje gie ier?\p"
	.string "Ik? Erkendje mie niet?\n"
	.string "Gèt mie ip me mulle heheven in 't\l"
	.string "dien tunnel achter Kortrik?\p"
	.string "Iersè!\n"
	.string "Astenblief, verheeft mie!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "That TM, it suits you more than it\n"
	.string "does me.\p"
	.string "Hope I never see you again!\n"
	.string "Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Awww, come on!\n"
	.string "You have to take this and let me go!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "A blue fluid is spiraling inside\n"
	.string "a glass vessel.\p"
	.string "“This is an experiment to create a\n"
	.string "Whirlpool artificially using wind.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "A red ball is bobbing up and down\n"
	.string "inside a glass vessel.\p"
	.string "“This is an experiment simulating a\n"
	.string "Waterfall using the ball's buoyancy.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "It's a sample of soil from the ocean\n"
	.string "floor.\p"
	.string "“Over many years, the remains of\n"
	.string "life-forms settle at the bottom of\l"
	.string "the sea, making sedimentary layers.\p"
	.string "“By analyzing these layers, the\n"
	.string "ancient past is revealed.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "It's a sample of beach sand.\p"
	.string "“Stones from mountains are washed\n"
	.string "down by rivers where they are\l"
	.string "chipped and ground down.\p"
	.string "“They are reduced to grains and end\n"
	.string "up as sand on beaches.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“Oceanic Minifact 1\n"
	.string "Why is seawater blue?\p"
	.string "“Light is composed of many colors.\p"
	.string "“When light passes through water,\n"
	.string "most kinds of light lose color.\p"
	.string "“However, blue light retains its\n"
	.string "color, making the sea appear blue.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“Oceanic Minifact 2\n"
	.string "Why is the sea salty?\p"
	.string "“Seawater contains dissolved salt in\n"
	.string "the form of sodium and chlorine ions.\p"
	.string "“These ions leech out of rocks\n"
	.string "and are carried out to sea by rain.\p"
	.string "“The concentration of dissolved salt\n"
	.string "makes the sea salty.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“Oceanic Minifact 3\n"
	.string "Which is bigger? The sea or land?\p"
	.string "“The sea covers about 70% of\n"
	.string "the planet, and the rest is land.\p"
	.string "“The sea is therefore more than twice\n"
	.string "the size of land.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "It's a fossil with wavy ridges on it.\p"
	.string "“Soil on the ocean floor gets scoured\n"
	.string "by the tide.\p"
	.string "“The flowing seawater marks the soil\n"
	.string "with small ridges and valleys.\p"
	.string "“If this soil becomes fossilized, it is\n"
	.string "called a ripple mark.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "A strange machine is rotating under\n"
	.string "a glass dome.\p"
	.string "Maybe it's for measuring the depth\n"
	.string "of something…$"

