.set LOCALID_MART_EMPLOYEE, 2
.set LOCALID_FOOTPRINTS_MAN, 3
.set LOCALID_RIVAL, 4

OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	end

@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
OldaleTown_EventScript_SetOldaleState::
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

OldaleTown_EventScript_BlockWestEntrance::
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
	return

OldaleTown_EventScript_MoveMartEmployee::
	setobjectxyperm LOCALID_MART_EMPLOYEE, 13, 14
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
	return

OldaleTown_EventScript_TownSign::
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl::
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_EventScript_InfiniteItems1::
	faceplayer
	goto_if_set FLAG_INFINITE_STUFF, OldaleTown_EventScript_InfiniteItems5
	playbgm MUS_HG_FOLLOW_ME_2, FALSE
	msgbox OldaleTown_Text_InfiniteItems1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, OldaleTown_EventScript_InfiniteItems2
	call_if_eq VAR_RESULT, NO, OldaleTown_EventScript_InfiniteItemsNo
	end

OldaleTown_EventScript_InfiniteItems2::
	msgbox OldaleTown_Text_InfiniteItems2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, OldaleTown_EventScript_InfiniteItems3
	call_if_eq VAR_RESULT, NO, OldaleTown_EventScript_InfiniteItemsNo
	end

OldaleTown_EventScript_InfiniteItems3::
	msgbox OldaleTown_Text_InfiniteItems3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, OldaleTown_EventScript_InfiniteItems4
	call_if_eq VAR_RESULT, NO, OldaleTown_EventScript_InfiniteItemsNo
	end

OldaleTown_EventScript_InfiniteItems4::
	giveitem ITEM_INFINITE_REPEL
	giveitem ITEM_INFINITE_RARE_CANDIES
	giveitem ITEM_HEALING_HEART
	msgbox OldaleTown_Text_InfiniteItems4, MSGBOX_NPC
	setflag FLAG_INFINITE_STUFF
	fadedefaultbgm
	end

OldaleTown_EventScript_InfiniteItems5::
	msgbox OldaleTown_Text_InfiniteItems4, MSGBOX_NPC
	end

OldaleTown_EventScript_InfiniteItemsNo::
	msgbox OldaleTown_Text_InfiniteItemsNo, MSGBOX_NPC
	fadedefaultbgm
	end

OldaleTown_EventScript_MartEmployee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
	setflag FLAG_TEMP_1
	playbgm MUS_FOLLOW_ME, FALSE
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
	end

OldaleTown_EventScript_GoToMartSouth::
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartNorth::
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartEast::
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_ExplainPokemonMart::
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_EventScript_BagIsFull
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	fadedefaultbgm
	release
	end

OldaleTown_EventScript_ExplainPotion::
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

OldaleTown_Movement_EmployeeEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_EmployeeSouth:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_EmployeeNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_Unknown1:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_PlayerEast:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerSouth:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_Unknown2:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_EventScript_FootprintsMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OldaleTown_EventScript_BlockedPath::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
	waitmovement 0
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
	waitmovement 0
	releaseall
	end

OldaleTown_EventScript_NotBlockingPath::
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_Rival::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_0x8009, 0
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger1::
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger2::
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger3::
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_ShowRivalMessage::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_ShowMayMessage
	goto_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_ShowBrendanMessage
	end

OldaleTown_EventScript_ShowMayMessage::
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_ShowBrendanMessage::
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_RivalFinish::
	closemessage
	call_if_eq VAR_0x8009, 0, OldaleTown_EventScript_DoExitMovement1
	call_if_eq VAR_0x8009, 1, OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	removeobject LOCALID_RIVAL
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	releaseall
	end

OldaleTown_EventScript_DoExitMovement1::
	goto_if_ne VAR_FACING, DIR_SOUTH, OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_EventScript_DoExitMovement2::
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_WatchRivalExit
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer2:
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer3:
	face_left
	step_end

OldaleTown_Movement_RivalExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Movement_WatchRivalExit:
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_PlayerStepBack:
	delay_8
	walk_right
	step_end

OldaleTown_Movement_BackUp:
	walk_fast_up
	walk_in_place_faster_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_ReturnToOriginalPosition:
	walk_down
	walk_left
	step_end

OldaleTown_Text_SavingMyProgress:
	.string "Aje moe kak'n moeje kak'n,\n"
	.string "en aje moe ipsloan moej ipsloan.$"

OldaleTown_Text_IWorkAtPokemonMart:
	.string "Yeeps!\n"
	.string "Ik werke in de Liedel.\p"
	.string "Davers, bacht'n den bwôm, moej zien?$"

OldaleTown_Text_ThisIsAPokemonMart:
	.string "Voilà se, ier zin we dan.\n"
	.string "Mahtih, ne Liedel...\p"
	.string "Vjille beter dan dien 'Ollandsen bucht.\n"
	.string "En de prizzn vall'n allichte mee.\p"
	.string "Moeje een schelleke èn?\n"
	.string "Of wachte, ke noh iet beters.$"

OldaleTown_Text_PotionExplanation:
	.string "Overdah, 's nachts, 's middahs...\n"
	.string "Zupn is nu...zupn is morhen...\l"
	.string "*glug*..dadis..*glug*..toch ma'htig?$"

OldaleTown_Text_WaitDontComeInHere:
	.string "ELA! GIJ GOAT WACHTEN!\n"
	.string "Wachten zegiku!!\p"
	.string "'k Enkik juste voetspwôrn hevondn\n"
	.string "van ne zeldzoamn...nen blinker!\p"
	.string "Gie goat skwône wachtn todak gerjid\n"
	.string "zin, eje da goe verstoan?$"

OldaleTown_Text_DiscoveredFootprints:
	.string "'k Enkik juste voetspwôrn hevondn\n"
	.string "van ne zeldzoamn...nen blinker!\p"
	.string "Bluvven wacht'n...ja?\n"
	.string "Of moek der e tekeningske bie moakn?$"

OldaleTown_Text_FinishedSketchingFootprints:
	.string "'k Èn e ontdekkinge hedoan van\n"
	.string "die voetspwôrn...\p"
	.string "'k Peisdehe dak ip n'en blinker zat\n"
	.string "'t Woaren wel de minne zeker?…$"

OldaleTown_Text_MayLetsGoBack:
	.string "{RIVAL}: {PLAYER}{KUN}!\n"
	.string "Iere!\l"
	.string "We zin zjirre na'r us!$"

OldaleTown_Text_BrendanLetsGoBack:
	.string "{RIVAL}: Ik kere min kar, 'k ga nar us,\n"
	.string "noar et Lab.\l"
	.string "{PLAYER}, gaje gie ton sebiet ook weere?$"

OldaleTown_Text_TownSign:
	.string "Oostrozebeke\n"
	.string "“'t Hebeurt ier gin klwôtn mo 't is hezellig.”$"

OldaleTown_Text_InfiniteItems1:
	.string "Hallowkes! VG Toney ier...\n"
	.string "en 'k eb iet beters ontdekt dan de vrouwkes\p"
	.string "Nen Infinite Repel, een Doze hevuld me\n"
	.string "Poepsnoepjes (Rare Candies), en een Healing Heart\l"
	.string "om je {PKMN} oneindig te henezen!\p"
	.string "Mo 't is noh nie hedoan. Aje akkoord zijt\n"
	.string "ga je wok jen IVs en EVs kunn'n\l"
	.string "aanpass'n in je Menu!\p"
	.string "Daddis toch ma'htih?\n"
	.string "Zijdje geïnteresseerd?$"

OldaleTown_Text_InfiniteItems2:
	.string "Hmm… weet hewoon da, aje ze pakt,\n"
	.string "zije ne valsspeler, n'en bedrieher…\p"
	.string "Zijdje ZEKER daje ze wilt 'ebben?$"

OldaleTown_Text_InfiniteItems3:
	.string "'k Haat je nog jin ke vroagn.\n"
	.string "Geweun vo 't zjikkerste…\p"
	.string "Ge kun die items NIET wegsmitn.$"

OldaleTown_Text_InfiniteItems4:
	.string "Mutn...$"

OldaleTown_Text_InfiniteItemsNo:
	.string "Daddis hesproken!$"
