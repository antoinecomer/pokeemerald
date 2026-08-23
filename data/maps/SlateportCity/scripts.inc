.set LOCALID_FAT_MAN, 1
.set LOCALID_MAN_1, 2
.set LOCALID_RICH_BOY, 3
.set LOCALID_GRUNT_1, 5
.set LOCALID_COOK, 6
.set LOCALID_OLD_WOMAN, 7
.set LOCALID_GIRL, 8
.set LOCALID_TY, 9
.set LOCALID_GABBY, 10
.set LOCALID_CAPT_STERN, 11
.set LOCALID_GRUNT_2, 18
.set LOCALID_GRUNT_3, 19
.set LOCALID_GRUNT_4, 26
.set LOCALID_GRUNT_5, 27
.set LOCALID_GRUNT_6, 28
.set LOCALID_GRUNT_7, 29
.set LOCALID_GRUNT_8, 30
.set LOCALID_GRUNT_9, 31
.set LOCALID_GRUNT_11, 33
.set LOCALID_SCOTT, 35

@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, EncounterTable
	.byte 0

SlateportCity_OnTransition:
	callnative ChangeEncounterTable
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_COOK, 27, 16
	setobjectxyperm LOCALID_GIRL, 28, 16
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_MAN_1, 31, 14
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	setobjectxyperm LOCALID_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerk::
	goto_if_set FLAG_FINITE_TMS, SlateportCity_EventScript_PowerTMClerkFinite
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_MOON_STONE  @ OLD Hidden Power
	.2byte ITEM_SUN_STONE  @ OLD Secret Power
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerkFinite::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs2:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_MOON_STONE  @ OLD Hidden Power
	.2byte ITEM_SUN_STONE  @ OLD Secret Power
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_GABBY
	removeobject LOCALID_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Ik benne een hoeroe! Een hoeroe\n"
	.string "van de enerhie.\p"
	.string "{PLAYER}: Een 'oere?\n"
	.string "Nint. HHHHOEROE. Ne sjamaan!\l" 
	.string "Moeje ntwa kwôpn of komje slim doen?$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh?\n"
	.string "Jen {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "ie farmt aura!\p"
	.string "Dat effortke verdient e lintje.\n"
	.string "Et lintje van effort é.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} krigt de Effort Lint.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} ploatstehe et Effort Lintje\n"
	.string "ip {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Gie moe nog e bitje mjir aura farm'n.\p"
	.string "Aje da doe, goak je Pokémon\n"
	.string "ntwa spesjioals geevn.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! Jenne {STR_VAR_1}, da Effort\n"
	.string "Lintje stoat em bèregoe!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "Et licht van de vuurtwôrn rikt verre.\n"
	.string "Doe ke een hokske oeverre.\p"
	.string "Dertig zeemijln! Daddis dus\n"
	.string "Vuvvenvuftig kilometer!\p"
	.string "Ik ôpe geweun da da licht et leevn\n"
	.string "in de zji nie verstoort.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Ooh, kiek ne ké daarsie!\p"
	.string "Et zjiwier daje ier kun kriggen\n"
	.string "is vers en vul leevn.\p"
	.string "Zo levendih, aba, et zo kunn'\n"
	.string "rechtstoan! Burrp...ughh\p"
	.string "Miskien bitje tevjille gefret..$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Woarda et woatr propr es, kun frut\n"
	.string "hroeien, gôed vo e rikke oogst.\p"
	.string "Ton kwôm'n de meschn, en e\n"
	.string "marktje ontstoat.\p"
	.string "Ezo begin et einde van de\n"
	.string "beschoavinge.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "E marktje doen me die hezonde\n"
	.string "lucht van de zji…\p"
	.string "Daddis pas henietn!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Kheb oenger!\p"
	.string "Kzou der iet an kunn' doen whé.\p"
	.string "Mo kzoage liever.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Raahhhh! Kgoa mie inskrivn vo\n"
	.string "de BatterTente!\p"
	.string "Jin probljim, knè gin Pokémon\n"
	.string "en kben ne schooier!\p"
	.string "Mak nie jin van je Pokémons èn?$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Hurhhh… Huff…Huff\p"
	.string "Kzin te voete gekom'n van Knokke.\n"
	.string "Moojong toch…huff\p"
	.string "Da goak nie ip Strava zettn whé.\n"
	.string "Volhende ké pak ik de vélo!$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "Mortimer, dien die da museum ip\n"
	.string "pwôtn é gezet, es wok de leidr\l"
	.string "van een onderzji-dienst.\p"
	.string "Dus iederjin noemt em Kapt. Mortimer.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Amai.\n"
	.string "Tis da file precies…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Toendak e kind woarn, gingk\n"
	.string "af en toe ne ké na 't Museum.\p"
	.string "Ek drwômde euvr de mysteries\n"
	.string "van de zji en al z'n heheimen.$"

SlateportCity_Text_QuitPushing:
	.string "EEEEEJ! NIE DUWN.\n"
	.string "Ziej gie blind ofwa?$"

SlateportCity_Text_AquaHasPolicy:
	.string "Kzin ier ip bevel van\n"
	.string "oher'and. Mo...\l"
	.string "hoherhand zo beter congé geevn.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Oeze chef is heniaal.\p"
	.string "Ma wuk wilze zie in godsnoam\n"
	.string "vant Museum?\p"
	.string "Kun ze nie geweune\n"
	.string "de Wikipedia leezn?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Kvroag mie af wada we ier doen?\p"
	.string "Ting mie dat er vo de communicoatie in\n"
	.string "Team Aqua werk oan de winkel es…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "A's er iet es in 't Museum da we\n"
	.string "moetn 'ebn, waaroem rippen we\l"
	.string "et nie geweune!$"

SlateportCity_Text_DontButtIn:
	.string "Ej, gie doa!\n"
	.string "Moeit u nie!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Lange file, é?\p"
	.string "Tdoe mie denkn an die kji dak in\n"
	.string "de file ston vo Skyrim…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Ze noemn oes 'eco-terroristn'…\n"
	.string "ma we doen toch algelik brave de rij…$"

SlateportCity_Text_WhatDoYouWant:
	.string "Wuk?\n"
	.string "Wa wildje?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Ge wilt da bordje ier leezn?\n"
	.string "Kgoat vo je veureleezn!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Ke kikn é…\p"
	.string "Um… der stoa lik iets op, lik,\n"
	.string "“'t leevn in de zji is eindeloos'.”\p"
	.string "Yup, daddis exact wadatter ier\n"
	.string "stoat.\p"
	.string "Kbenkik ne literaire mensch é.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Zucht…\p"
	.string "'k A beetr min Game Boy\n"
	.string "meegepakt in de file…\p"
	.string "Twjide zucht…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Na ne zwoarn dag, èk'ik e\n"
	.string "massageke en een spa verdiend!\p"
	.string "Oezen boas é da gezei.\n"
	.string "Kgoa eur deran odn!$"

SlateportCity_Text_SeaIsSoWet:
	.string "De zji…zo hrwôt, zo diepe…\p"
	.string "Peisdje da al da woatr kom van\n"
	.string "de troan' van Pokémon?\p"
	.string "{PLAYER}: Joat zeker. Mutn.$"

SlateportCity_Text_SinkOldBoats:
	.string "Witje wada ze doen me odde schepen\n"
	.string "da nie mji de zji ipkunn'?\p"
	.string "Ze zinkn ze in de zji zoda ze\n"
	.string "e habitat kunn' word'n vo de\p"
	.string "bjistjes onderwoatr!$"

SlateportCity_Text_BuyTooMuch:
	.string "Wanjir dak ier ip bezoek benne,\n"
	.string "ik krig de kwôopziekte.\p"
	.string "Kmoe mie ljirn in'oddn. Kdoe men beste!$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Aje e nieuw koosnoamke vo je Pokémon\n"
	.string "wilt, eje de Koosnoam Expert nweudig.\l"
	.string "Witje wadakik et echt HET mee è?\p" 
	.string "Al die vurte 'expertn'.\n"
	.string "Geldexpert, Relatie-expert,\l"
	.string "Preparé-expert, Steakexpert,\l"
	.string "Defensie-expert, Sexpert...\p"
	.string "Die witi's noemekik 'HLN',\n"
	.string "Hodverdomske Luntetrekkers en\l"
	.string "Nietsnuttn.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Aje ne Pokémon wisselt, ton kundje zin\n"
	.string "koosnoamke nie verandern.\p"
	.string "Waaroem da?\n"
	.string "Moe nie noar ik kiekn whé.\p"
	.string "Ik èn die rehels nie gemoakt.\p"
	.string "Mo zeg nu toch zelve.\n"
	.string "Stel, g'adoptjirt jin van 't asiel,\l"
	.string "en de vorihen é zin Pokémon\l"
	.string "de hrwôotte van e chihuahua\l"
	.string "'Ganondorf' henoemd...\p"
	.string "Das e sligt voorbeeld, want die\n"
	.string "noam es bjistig. Mo ge snapt\l"
	.string "min punt wel é?$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Recentelik èn ze hoedkeuringe\n"
	.string "hekreegn vo die BatterTente iere\l"
	.string "te bouwn.\p"
	.string "Webben al Gyms, wuk es et verskil?\n"
	.string "Kgoat je ké zeggn wukdat es.\p"
	.string "Nieuwpoort a gin verhunninge\n"
	.string "gekregen vo een Gym...\l"
	.string "dus zèn e Battle Tent hezet!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Ze zeidn ollemolle datter een\n"
	.string "bekende sterre ging afkom'n.\p"
	.string "Taylor Swift? Shakira? Nint.\n"
	.string "Tis onzne lokale kapitein.$"

SlateportCity_Text_InterviewerSoCool:
	.string "Ik kiek ip na die journaliste,\n"
	.string "en dabie, tis een prente.\p"
	.string "Akkik een carrière moe kiez'n,\n"
	.string "ton wil ik wok journalist zin\l"
	.string "met et verskil dakkik interessantere\l"
	.string "onderwerp'n zo kiez'n.$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "Kapt. Mortimer zegt da ze ntwa\n"
	.string "gevond'n èn ip de bodem van de\p"
	.string "oceaan. Kvroag mie af wuk.\n"
	.string "Vuftig kilo plastiek?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Wuk gebeurt er ier?\p"
	.string "Eeft de kapitein iet ipgevist?\n"
	.string "Miskien zin hezond verstand?$"

SlateportCity_Text_AmIOnTV:
	.string "Ey! Ziej oant kiekn?\n"
	.string "Benk ip TV?\p"
	.string "'t Es 'twôpn zondr ondertitels!$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Een TV interview! Iere!\n"
	.string "De kapitein es e Vie Aai Pie!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY: Oké, Kapt. Mortimer, een grote\n"
	.string "glimlach voor de camera!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "Gabby: Ah zo, u zwemt onwaarschijnlijk\n"
	.string "in ervaring…figuurlijk dan.$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "Kapt. M.: Joak, 't zal wel zin.\n"
	.string "Allée, duizend bommen en den bwôm in.\l"
	.string "Pretendeer nie daje geïnteresseerd zit!$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "Gabby: Wat een reactie!\n"
	.string "Dit zal massaal kliks genereren!\l"
	.string "Bedankt voor uw tijd, Kapitein.\p"
	.string "We hopen u binnenkort opnieuw te\n"
	.string "mogen interviewen!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "Kapt. M.: Fieuw…\p"
	.string "Min jiste interview. Kvond dat nog\n"
	.string "algelik meeviel. Khad gin stress.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Oh! {PLAYER}{KUN}!\n"
	.string "'K èn ne goeie mop!\p"
	.string "Twee tetn in e envelop!\n"
	.string "Ma serieus efkes,\p"
	.string "w'ebben e HIHANTISCHE ontdekkinge\n"
	.string "gedoan ip Boane 128.\p"
	.string "We peizn dattet de 'abitat es\n"
	.string "da zohezehd allange zou motn\l"
	.string "dwôd zin..$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Aha…\n"
	.string "Kapt. Mortimer, nim ik oan.\p"
	.string "Wudr, Team Aqua, nimm'n jen\n"
	.string "onderzjiër in beslag!\p"
	.string "Oanvoard et. Loat et hebeurn.\n"
	.string "'t Is vo jen eihen gôed!\p"
	.string "'Ahaha…\n"
	.string "De wjirld goa 'ardandig ljirn\l"
	.string "da ze nie me de klwôtn van\l"
	.string "Moedr Oarde moetn spjiln!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "Kapt. M: Wuk was da ollemolle?\p"
	.string "'t Klink precies lik ne mehafoon\n"
	.string "me e bitje prétense…\p"
	.string "Vanwoar kommet?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "'t Es van...!!\p"
	.string "HODVERTOMMETOCHTZALHINWOARZIN\p"
	.string "In de Haven..!!!\p"
	.string "Den onderzjiër!\n"
	.string "Ze goan em koapn!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}!\n"
	.string "Kom! Astenblief!$"

SlateportCity_Text_BattleTentSign:
	.string "BatterTente van Nieuwpoort\n"
	.string "“Wudr rehelen ethische batteringen\l"
	.string "alsof ze voor onszelf zyn.”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "Scheepswerf van Mortimer\p"
	.string "“WE ZOEKEN: COMPETENTE ZEILERS\n"
	.string "KAN MINSTENS EEN PLATTE KNOOP.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "De scheepswerf van Morris\p"
	.string "“De ferry S.S. Het Ei es\n"
	.string "bikan gerjid en zal binn'kort\l"
	.string "voarn tuss'n ier en ZeeBruhhe.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "De scheepswerf van Morris\p"
	.string "“De Nieuwpoort-Brugge ferry\n"
	.string "S.S. Het Ei: de snelste navette\l"
	.string "tussen hier en Zeebrugge.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "Pokémon Fan Club\n"
	.string "“E warme iproep aan alle fans!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“De eindeloze zee voedt\n"
	.string "voortdurend het eindige leven.”\p"
	.string "Maritiem museum$"

SlateportCity_Text_CitySign:
	.string "Nieuwpoort\p"
	.string "“DÉ (ENIGSTE ECHTE) stad aan zee.\n"
	.string "Zelf ons bad is e stad!\l"
	.string "(Fuck you Oostende!).”$"

SlateportCity_Text_MarketSign:
	.string "Nieuwpoort Markt\n"
	.string "“Doe e batje! 't Is crisis!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "Haven van Nieuwpoort\p"
	.string "“De ferry S.S. Het Ei is\n"
	.string "momenteel nog niet af.\p"
	.string "“Binnenkort treedt deze in\n"
	.string "dienst.”$"

SlateportCity_Text_HarborSign:
	.string "Haven van Nieuwpoort\p"
	.string "“Geniet van een zalige boottocht\n"
	.string "op de ferry S.S. Het Ei.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "'t Us van de Koosnoamexpert\n"
	.string "“Is uw koosnoamke e W of een L?”$"

SlateportCity_Text_ExplainBerries:
	.string "Wistjeda?\p"
	.string "Als e wilde Pokémon gewond es,\n"
	.string "goat ie Bessen frettn om te henezen.\p"
	.string "En wistjeda?\p"
	.string "Iemand ad da hezien en ie é\n"
	.string "ton heneesmiddln hemoakt ermee.\p"
	.string "Eeeeen wistjeda?\p"
	.string "Om van Bessn medicijnen te moakn,\n"
	.string "moeje ze plettn tot poeier.\p"
	.string "Eeeeeeen wiiiiistjeda?\p"
	.string "Gie zie lik precies stifcurieus\n"
	.string "noar alles wada me Bessn te moakn èt!\p"
	.string "'k Ekkik juste iet\n"
	.string "voor iemand lik gie.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Wist je da?\p"
	.string "'k Eb recentelik machienen loatn\n"
	.string "ploatsn in Pokécenters.\p"
	.string "Spesjoale machienen vo Bessen mee\n"
	.string "te plettn! Handih é.\p"
	.string "Aje mie wa Bessenpoeier bringt\n"
	.string "deur die machienen te hebrukn,\l"
	.string "kunkik voor u allerlie swôrtn\l"
	.string "medicijnen moakn. Kzweiret.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Eje mie wa BessenPoeier\n"
	.string "hebracht?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Wa zoeje der mee will'n\n"
	.string "utwisseln?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Oké, gie wilt je BessenPoeier\n"
	.string "utwisseln vo jin {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Uh, oh.\p"
	.string "Wist je da?\p"
	.string "Gie zie te blut.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Daddis nog e bitje kwaliteit zeg.\n"
	.string "Da hoa hoei medicijn'n heevn.\p"
	.string "Wildje nog e bitje BessenPoeier\n"
	.string "me me utwisseln?\l"
	.string "Wist je da...BessenPoeier\l"
	.string "ge kunta wok ipsnuvvn.\p"
	.string "Sssssssssssssnif.$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Oké! Aje nog mjir BessenPoeier\n"
	.string "vindt, bring et..PLEASE!\l"
	.string "Sniff..$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Kom gerust were aje je BessenPoeier\n"
	.string "wilt inruiln vo medicijnen.\p"
	.string "Of, heh, 'medicijn'en'. E?\p"
	.string "Nog e wistjedatje..ssnif.?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "Scott: Huh?\n"
	.string "I'm sure I met you somewhere before.\p"
	.string "Have I introduced myself to you?\n"
	.string "If not, my name's Scott.\p"
	.string "I just saw Team Aqua run away from\n"
	.string "here like they were stung.\p"
	.string "Let me guess--you drove them away?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "Scott: Hmm…\n"
	.string "Misschien toch, deze Temmer…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "Scott: Oké dan! Soms moet ik\n"
	.string "erkennen dat ik een fout heb gemaakt.\p"
	.string "Jij vertoont potentieel.\n"
	.string "Geef eens je Pokénav?.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Dien onbeskoftn oap (Scott)\n"
	.string "é zichzelve heréhistreerd.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "Scott: Tot nu toe heb je gelu-\n"
	.string "...-kig veel strategisch gespeeld.\l"
	.string "Wanneer je eindel- , ik bedoel,\p"
	.string "mocht je helaas komen te verliezen\n"
	.string "in de komende Gym...\p"
	.string "Bel me zeker op, {PLAYER}{KUN}!\n"
	.string "Ik zal je wat moed influisteren..\p"
	.string "Hehe...tot de volgende?$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "Scott: Ah! Alweer jij.\n"
	.string "{PLAYER}{KUN}!\p"
	.string "Als ik jou was, zou ik ook\n"
	.string "wat oefenen in die Tent.\p"
	.string "Je kan de ervaring gebruiken hé!\n"
	.string "En ik bedoel dat enkel positief!\p"
	.string "Doe je best!\p"
	.string "{PLAYER}{KUN}: ...mutn.$"
