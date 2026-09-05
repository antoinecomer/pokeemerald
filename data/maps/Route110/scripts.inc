.set LOCALID_CHALLENGE_BIKER, 21
.set LOCALID_RIVAL, 28
.set LOCALID_RIVAL_ON_BIKE, 29
.set LOCALID_BIRCH, 36

Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume:
	callnative ChangeEncounterTable
	special UpdateCyclingRoadState
	end

Route110_OnTransition:
	callnative ChangeEncounterTable
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
	end

Route110_EventScript_SaveCyclingMusic::
	savebgm MUS_CYCLING
	return

Route110_OnFrame:
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
	.2byte 0

Route110_EventScript_BeginCylcingRoadChallenge::
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

Route110_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_Boy1::
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
	end

Route110_EventScript_CyclingGirl1::
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy1::
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
	end

Route110_EventScript_OldMan::
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
	end

Route110_EventScript_OldWoman::
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy2::
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
	end

Route110_EventScript_Boy2::
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
	end

Route110_EventScript_SlateportCitySign::
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadSign::
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route110_EventScript_VandalizedSign::
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
	end

Route110_EventScript_Route103Sign::
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
	end

Route110_EventScript_SeasideParkingSign::
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
	end

Route110_EventScript_MauvilleCitySign::
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsPrlzSleep::
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsRegisterItems::
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route110_EventScript_TrickHouseSign::
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadResultsSign::
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_NoRecordSet::
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_ChallengeGuy::
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerNotRidingBike::
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerRidingAcroBike::
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_Edward::
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn::
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin::
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_EDWIN_1
	release
	end

Route110_EventScript_EdwinRematch::
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale::
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob::
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin::
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end

Route110_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail::
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABIGAIL_1
	release
	end

Route110_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel::
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISABEL_1
	release
	end

Route110_EventScript_IsabelRematch::
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy::
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Unused::
	end

Route110_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa::
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_CyclingChallengeEnd::
	lockall
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call Route110_EventScript_CyclingChallengeResults
	releaseall
	end

Route110_EventScript_CyclingChallengeResults::
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Route110_EventScript_ChallengeReactionBest
	case 9, Route110_EventScript_ChallengeReactionGood
	case 8, Route110_EventScript_ChallengeReactionGood
	case 7, Route110_EventScript_ChallengeReactionGood
	case 6, Route110_EventScript_ChallengeReactionOk
	case 5, Route110_EventScript_ChallengeReactionOk
	case 4, Route110_EventScript_ChallengeReactionOk
	case 3, Route110_EventScript_ChallengeReactionBad
	case 2, Route110_EventScript_ChallengeReactionBad
	case 1, Route110_EventScript_ChallengeReactionBad
	case 0, Route110_EventScript_ChallengeReactionWorst
	end

Route110_EventScript_ChallengeReactionBest::
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionGood::
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionOk::
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionBad::
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionWorst::
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_EndChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_RivalTrigger1::
	setvar VAR_0x8008, 1
	setflag FLAG_INCREASE_DIFFICULTY
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger2::
	setvar VAR_0x8008, 2
	setflag FLAG_INCREASE_DIFFICULTY
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger3::
	setvar VAR_0x8008, 3
	setflag FLAG_INCREASE_DIFFICULTY
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalScene::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
	releaseall
	end

Route110_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route110_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route110_EventScript_MayBattle::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_MayBattleTreecko
	case 1, Route110_EventScript_MayBattleTorchic
	case 2, Route110_EventScript_MayBattleMudkip
	end

Route110_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayDefeated::
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BrendanBattle::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_BrendanBattleTreecko
	case 1, Route110_EventScript_BrendanBattleTorchic
	case 2, Route110_EventScript_BrendanBattleMudkip
	end

Route110_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanDefeated::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_GiveItemfinder::
	giveitem ITEM_ITEMFINDER
	return

Route110_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 45
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_ROUTE110_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer3::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_RivalExit1::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	waitmovement 0
	return

Route110_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	waitmovement 0
	return

Route110_EventScript_RivalExit3::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	waitmovement 0
	return

Route110_EventScript_MoveRival1::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 33, 55
	return

Route110_EventScript_MoveRival2::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 34, 55
	return

Route110_EventScript_MoveRival3::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 35, 55
	return

Route110_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalApproachPlayer2:
	walk_down
	step_end

Route110_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalExit1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_RivalExit2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_RivalExit3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_BirchScene1::
	lockall
	setvar VAR_0x8008, 1
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene2::
	lockall
	setvar VAR_0x8008, 2
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene3::
	lockall
	setvar VAR_0x8008, 3
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene4::
	lockall
	setvar VAR_0x8008, 4
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene::
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, Route110_Movement_BirchEntrance
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
	removeobject LOCALID_BIRCH
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_BirchApproachPlayer1::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer2::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer3::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer4::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer4
	waitmovement 0
	return

Route110_EventScript_BirchExit1::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit1
	waitmovement 0
	return

Route110_EventScript_BirchExit2::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit2
	waitmovement 0
	return

Route110_EventScript_BirchExit3::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit3
	waitmovement 0
	return

Route110_EventScript_BirchExit4::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit4
	waitmovement 0
	return

Route110_Movement_BirchEntrance:
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer2:
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer3:
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer4:
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_BirchExit1:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_WeCantTalkAboutAquaActivities:
	.string "Dus giiij wilt weten wada…\n"
	.string "Team Aqua van plan es……\p"
	.string "… … … … … … … …\p"
	.string "Meuh nie.$"

Route110_Text_KickUpARuckus:
	.string "Blikboar est hank in Nieuwpoort.\n"
	.string "Min post is ier! Soai.\p"
	.string "Hjilsan WACHT'N! 'k Kom ZOT!$"

Route110_Text_MyFirstJobInAqua:
	.string "Dit es min jiste jobke.\n"
	.string "De voorwoard'n bie Team Aqua zin hoe.\p"
	.string "'t Es me hroepsverzekering.$"

Route110_Text_AquaActionsBringSmiles:
	.string "Meschn noemen oes terrorist'n\n"
	.string "of vorte hippies mo..\l"
	.string "'t es toch 't jin of 't ander?$"

Route110_Text_MayLetsBattle:
	.string "{RIVAL}: Moh, {PLAYER}{KUN}!\n"
	.string "Das lang heleden sè!\p"
	.string "Lukt et vang'n van Pokémons\n"
	.string "bie u? 'k Eb 'k ik zelf\l"
	.string "al jin blinker…\p"
	.string "… … … … … … … … …\p"
	.string "{RIVAL}: (Klapt in oar 'and'n)\n"
	.string "Hwoêd. Henoeh bijheproat.\p"
	.string "Batteringske?$"

Route110_Text_MayDefeated:
	.string "Jawadde!\n"
	.string "'k Ad niets mind'r verwacht!$"

Route110_Text_MayTakeThis:
	.string "{RIVAL}: {PLAYER}{KUN}, jen\n"
	.string "Pokémons zin duddelik in topconditie.\p"
	.string "Kzie da geirn!\n"
	.string "Iere, vang!$"

Route110_Text_MayExplainItemfinder:
	.string "{RIVAL}: Da es een DingVindr.\p"
	.string "Lik da zen noame et zegt,\n"
	.string "et vindt dingen. Ma wok\l"
	.string "dingn die onzichtboar zin!\p"
	.string "Lik da Wally me z'n klitoren zoe zehhen,\n"
	.string "Check et ut!\p"
	.string "En bluvt trainen, of zie herust\n"
	.string "dak u goan in'oal'n!\p"
	.string "Tshow é!$"

Route110_Text_BrendanLetsBattle:
	.string "{RIVAL}: Moh, {PLAYER}{KUN}!\n"
	.string "Das lang heleden sè!\p"
	.string "Lukt et vang'n van Pokémons\n"
	.string "bie u? 'k Eb 'k ik zelf\l"
	.string "al jin blinker…\p"
	.string "… … … … … … … … …\p"
	.string "{RIVAL}: (Klapt in zin 'and'n)\n"
	.string "Hwoêd. Henoeh bijheproat.\p"
	.string "Batteringske?$"

Route110_Text_BrendanDefeated:
	.string "Jawadde!\n"
	.string "'k Ad niets mind'r verwacht!$"

Route110_Text_BrendanTakeThis:
	.string "{RIVAL}: {PLAYER}{KUN}, jen\n"
	.string "Pokémons zin duddelik in topconditie.\p"
	.string "Kzie da geirn!\n"
	.string "Iere, vang!$"

Route110_Text_BrendanExplainItemfinder:
	.string "{RIVAL}: Da es een DingVindr.\p"
	.string "Lik da zen noame et zegt,\n"
	.string "et vindt dingen. Ma wok\l"
	.string "dingn die onzichtboar zin!\p"
	.string "Lik da Wally me z'n klitoren zoe zehhen,\n"
	.string "Check et ut!\p"
	.string "En bluvt trainen, of zie herust\n"
	.string "dak u goan in'oal'n!\p"
	.string "Tshow é!$"

Route110_Text_RideBikeAtFullSpeed:
	.string "Met de vélo vullen bak hoan.\n"
	.string "Daddist 't leevn, niewoar?$"

Route110_Text_HairStreamsBehindMe:
	.string "Kèn men oar loatn uthroein.\n"
	.string "De wind derdeur goat. Zalih hewoon.\p"
	.string "Kletskopp'n miss'n toch ntwadde.$"

Route110_Text_YouGotBikeFromRydel:
	.string "Moh, ès da ne vélo van KwikStep?\p"
	.string "'t Zal wel ziiiiiiiiin.\n"
	.string "'t Merk stoat ip je vélo…\p"
	.string "KwikStep, KwikStep, KwikStep, KwikStep,\n"
	.string "KwikStep, KwikStep, KwikStep, KwikStep,\p"
	.string "KwikStep, KwikStep, KwikStep, KwikStep,\n"
	.string "KwikStep, KwikStep, KwikStep, KwikStep,\p"
	.string "KwikStep, KwikStep, KwikStep, KwikStep,\n"
	.string "KwikStep, KwikStep, KwikStep, KwikStep,\p"
	.string "KwikStep, KwikStep, KwikStep, KwikStep,\n"
	.string "KwikStep, KwikStep, KwikStep, KwikStep,\p"
	.string "Kunt er nie neffest lwôpn.\p"
	.string "Of fietsen é! Hah!\n"
	.string "Vré hoei recloame wel!$"

Route110_Text_TwoRoads:
	.string "Twee boan'n, jin bov'n, jin ond'r…\p"
	.string "Jin vo de meschn, jin vo de Pokémons.\n"
	.string "Miskien es da juste. En rehhtvoardig.$"

Route110_Text_WalkOnTheLowRoad:
	.string "'k Nè ginne vélo. Dus ik pakke\n"
	.string "de lange weg ip me hemak.$"

Route110_Text_BikeTechniques:
	.string "Op n'en odde fiets moeje ljirn rieën.\n"
	.string "Ik en m'en vrouwe,\p"
	.string "we schelen acht joar.\n"
	.string "En ik ben de joengsten.\p"
	.string "Miskiene moek min kandidoat stell'n,\n"
	.string "om president van Frankrik te word'n?$"

Route110_Text_WhichShouldIChoose:
	.string "Wuk zok 'k ik kiez'n?\p"
	.string "Tjeezn ip de vélo na Knokke\n"
	.string "of de lage wandelweh pakk'n\l"
	.string "en tsjollen deur ol die Pokémons?$"

Route110_Text_CyclingChallengeResultSummary:
	.string "Oantal botsingen:\n"
	.string "… … {STR_VAR_1}!\p"
	.string "Totalen tid:\n"
	.string "… … {STR_VAR_2}!$"

Route110_Text_ChallengeReactionBest:
	.string "BRAVO! Da wa MAHHTIG.\p"
	.string "Uw liefde voor et fiets'n\n"
	.string "komt diep van uw 'erte.\l"
	.string "Kieksè, ben der echt ontroerd van!$"

Route110_Text_ChallengeReactionGood:
	.string "Nie slecht.\p"
	.string "Probjirt nog e bitje snellid\n"
	.string "te pakk'n zonder te bots'n.$"

Route110_Text_ChallengeReactionOk:
	.string "'T es nie mis...\n"
	.string "ma 't is wok nie al da.\p"
	.string "Me de vélo rieën, ge moe da\n"
	.string "nie enkel voel'n in u' kietn,\l"
	.string "ma wok in u' 'erte.$"

Route110_Text_ChallengeReactionBad:
	.string "Mo gie absolute mutn…\n"
	.string "Moeje gin steunwieletjes èn?\p"
	.string "Astenblief, oefent e bitje voorda\n"
	.string "je uzelve en ons als fietsers\l"
	.string "hjil belachelik moakt.$"

Route110_Text_ChallengeReactionWorst:
	.string "…Gie…\n"
	.string "geeft uw Haarmin moar af.\p"
	.string "De wjirld is beter af aje gie nwoois\n"
	.string "te nimmer nog ne vélo oanroakt.\l"
	.string "Ga na Kwikstep en verkwôpt em.$"

Route110_Text_RatedForNumberOfCollisions:
	.string "Ip de fietsboane moet et rap goan.\p"
	.string "Ip u hemak, da kenn' z'ier nie.\n"
	.string "Allez, past ip, daje gin accidenten\l"
	.string "veroorzoakt, of de flikk'n goan wel\l"
	.string "'ip 't hemak' e pv'ke ipstell'n.$"

Route110_Text_AlwaysAimHigher:
	.string "Bluv'n knalln.\n"
	.string "Bluv'n goan.\l"
	.string "De skaai is de limit é zeg!$"

Route110_Text_AcroBikesDoNotQualify:
	.string "On this Cycling Road, those riding\n"
	.string "Mach Bikes are rated for their number\l"
	.string "of collisions and their total times.\p"
	.string "Acro Bikes do not qualify for rating.\n"
	.string "They are easy to turn, so it's not fair.$"

Route110_Text_SlateportCitySign:
	.string "Boane 110\n"
	.string "{DOWN_ARROW} Nieuwpoort$"

Route110_Text_CyclingRoadSign:
	.string "Fietsboane langs de zji$"

Route110_Text_AquaWasHere:
	.string "Der stond ier “Temmer Tips”\p"
	.string "ma propahandist'n van Team Aqua en Mahma\n"
	.string "ènt hans beklad.\p"
	.string "{PLAYER}: Ting mie dak nie den\n"
	.string "enihsten zin die z'n hat veegt\l"
	.string "aan die miserabele tips.$"

Route110_Text_Route103Sign:
	.string "Boane 110\n"
	.string "{LEFT_ARROW} Boane 103$"

Route110_Text_SeasideParkingSign:
	.string "Parking oan de Zji$"

Route110_Text_MauvilleCitySign:
	.string "Boane 110\n"
	.string "{UP_ARROW} Knokke$"

Route110_Text_TrainerTipsPrlzSleep:
	.string "Temmer Tips\p"
	.string "Aje de batteringe oant verliez'n zyt,\n"
	.string "kundje wok geweune den Temmer zelf\l"
	.string "ip zen mulle geevn.\p"
	.string "{PLAYER}: 'k Goa vooral den oteur\n"
	.string "van die achterlike tips ip zen\l"
	.string "vunzige mulle geven.$"

Route110_Text_TrainerTipsRegisterItems:
	.string "Temmer Tips\p"
	.string "Sorteert dingen in uwe zak met SELECT.\p"
	.string "{PLAYER}: Ahzo, en nu goan we\n"
	.string "e bitje de vierde muur breekn, joa?$"

Route110_Text_TrickHouseSign:
	.string "“Drie na {RIGHT_ARROW} en twji na {UP_ARROW}\n"
	.string "om in et FopUs te kom'n.”$"

Route110_Text_BestRecord:
	.string "De HOOHSTE score…\p"
	.string "Aantal accident'n: {STR_VAR_1}\p"
	.string "Tid hebrukt: {STR_VAR_2}$"

Route110_Text_ThereIsNoRecord:
	.string "De HOOHSTE score…\p"
	.string "N'es noh niemand die et\n"
	.string "heprobjird è…$"

Route110_Text_ImagineSeeingYouHere:
	.string "Prof. Gerrit C.: Moh, {PLAYER}{KUN}!\n"
	.string "Wien da wier èn!\p"
	.string "En woar es min {RIVAL}?$"

Route110_Text_HeardYouInstallMatchCall:
	.string "Ah, 'k verstoat!\n"
	.string "Ge lwôpt nie twope.\l"
	.string "Das vré wel.\p"
	.string "Seg eh. En oe skit da me jen\n"
	.string "Pokédex? Nie verheetn daje\p"
	.string "utterst woardevol onderzoek vo\n"
	.string "min iplevert é!\p"
	.string "Kgoa je min nummer heven,\n"
	.string "ton kank zehhen wada jen\l"
	.string "vooruthank es. Allez 't beste é.\p"
	.string "Ah wachte, gif ke je numéro.\p"
	.string "… … … … … …$"

Route110_Text_RegisteredBirchInPokenav:
	.string "Prof. Gerrit Callewaert\n"
	.string "es herehistreerd in je Pokénav.$"

Route110_Text_KeepAnEyeOutForRival:
	.string "Prof. C.: {PLAYER}{KUN}…\p"
	.string "Od een oogske in 't zeil vo {RIVAL}.\n"
	.string "… … … … … …\p"
	.string "Allez, kzin deure. Nu voor echte.\n"
	.string "'t Beste é, {PLAYER}{KUN}!$"

