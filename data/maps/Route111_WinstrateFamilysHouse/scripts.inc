.set LOCALID_VIVI, 1
.set LOCALID_VICTOR, 2
.set LOCALID_VICTORIA, 3
.set LOCALID_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "You're the first Trainer I've seen who\n"
	.string "deploys Pokémon so masterfully.\p"
	.string "But, I should tell you--my son is\n"
	.string "stronger than you.\p"
	.string "He even took the Pokémon League\n"
	.string "challenge, I'll have you know.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Sta recht, me trots! Temmer!\n"
	.string "Gie zie sterk!\l"
	.string "En 't es damée,\p"
	.string "me daj oes ollemoal versloan èt,\n"
	.string "daj we u woardig ahhtn van\l"
	.string "van oeze Macho Hhhordel.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Wuddr temm'n en trainen oeze {PKMN}\n"
	.string "me een Macho Hordel, da es hwoêd vo\l"
	.string "under éévéés enal, kenje da?\p"
	.string "Zoniet, den Bulbapedia es uw vriend.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "De Chimera Ant arc is echt rete.\p"
	.string "Boruto es uthemelkt.\p"
	.string "Imu es ne niewèrt! RIP de haaip.\p"
	.string "Wuk wa da me die bankai ipt einde?\n"
	.string "De animatie van Super es MID!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Daje mahhtig zit, doar es gin twiffel an.\p"
	.string "Ma tehen ming kleinzeune?\n"
	.string "He nèt gin schyn van kans.\p"
	.string "Gin.\n"
	.string "Verhit et. Nul kans. Zero.\p"
	.string "Nouhabolln.\n"
	.string "Nietteklwôtn.\p"
	.string "Nietsnie.\n"
	.string "Nada!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Min kleinzeune is verzekers nu\n"
	.string "de Liha oant oanpakkn.\p"
	.string "Of zottie al kampioen zin?\n"
	.string "Dat ie belt é! Howzeh.$"

