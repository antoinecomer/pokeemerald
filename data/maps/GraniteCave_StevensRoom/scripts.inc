.set LOCALID_STEVEN, 1

GraniteCave_StevensRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, EncounterTable
	map_script MAP_SCRIPT_ON_TRANSITION, EncounterTable
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "Jabeja gie, gadverdamme.\p"
	.string "Daddis nog e bitje ne zeldzoame stjin..\n"
	.string "Ik ben Steven, oangenoame.\p"
	.string "Steven: Vroagsje!\p"
	.string "Wuk est er zwoarder?\p"
	.string "E kilo patatn, of e kilo stoal?\n"
	.string "Aba e kilo stoal natuurlik!\l"
	.string "Want stoal is zwoarder dan patatn!\p"
	.string "… … … … … … … … … … … … … … … … … …"
	.string "Wuk? 't Es tzelfste?  
	.string "Steven: Oh?\n"
	.string "N'en brief veur ik?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "Steven: Ah, merci.\p"
	.string "Kzin content dat gin belastingn zin.\n"
	.string "Die geldzakn me udder zes regeringn.\p"
	.string "Ke kikn é…\n"
	.string "Kga jen min favorieten\p"
	.string "oanval geevn in e TM'ke,\n"
	.string "Stoaln Vleuhel.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "Steven: Oan je Pokémon te ziene,\n"
	.string "zieje gie wel lik n'en deftigen Temmer.\p"
	.string "Aje zo bluvt goan,\n"
	.string "moeje u smitn vo 't Kampioenschap\l"
	.string "van Oen. Zeg dakkik et gezeit è.\p"
	.string "Nieuw vroagsje.\n"
	.string "Bicky of Mexicano?\l"
	.string "… … … … … … … … … … … … … … … … … …\l"
	.string "Hôed antwoord joegne.\p"
	.string "Wudr zien mekoar were é, ier,\p"
	.string "min numéro. $"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Steven rehistreerdehe\n"
	.string "zichzelve in jen Pokénav.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Allez. Kzin deure. Tchow é.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Mohow jong je zak zit vul…\n"
	.string "Los et ip.$"

