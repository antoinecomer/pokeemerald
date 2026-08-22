.set LOCALID_NURSE, 1

DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

DewfordTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_EventScript_Man::
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_Text_StoneCavern:
	.string "Aje tend'n lwôpt ier bitje verder,\n"
	.string "goaje e hrotte tegenkom'n.\p"
	.string "'t Skint daje da nog bitje zeldzoame\n"
	.string "stjinn'n vindt.\p"
	.string "{PLAYER} peist: Alégow miskien vindje\n"
	.string "wok een HOBBY!$"

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
	.string "Zelf als n'en Pokémon bezwijkt,\n"
	.string "kundje nog alsan een HM in zin strot\l"
	.string "duwen! Wist je da?\p"
	.string "{PLAYER}: Nink..gij psychopoat!$"

