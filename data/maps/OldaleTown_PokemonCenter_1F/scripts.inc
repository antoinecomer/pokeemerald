.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Dien PEESEE in den oek\n"
	.string "meugt iederjin hebruk'n.\p"
	.string "En voordajet vroagt...\n"
	.string "Nint, die websites marcheren niet...$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "PokéCenters zin toch ma'htih!\p"
	.string "Ge kunt ier alsan binnen\n"
	.string "ge zit direc bediend, en 't is al vo niet.\l"
	.string "De sossen èn da vree goed hereheld!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "Den Droad...waar is den Droad.\n"
	.string "Aje wok jen Droad kwit zijt...\p"
	.string "kundje ke kiekn boven.\n"
	.string "Ma kpeize da ze nog werk aan de winkel èn.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "De Droadloze Club\n"
	.string "wa noh ma juste open,\p"
	.string "echt berechic...direct kunn'n ruilen.$"

