.set LOCALID_NURSE, 1

SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Moeje een battertip èn?\p"
	.string "{PLAYER}: Nink.\p"
	.string "Ah.\n"
	.string "Allez dan.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "Ik wissel 'k ik Pokémon me min\p"
	.string "moatn. 'k Loat ze ton ntwa\n"
	.string "vast'oddn! Zebben ton dubbel pris!\p"
	.string "Overloatst n'en everstone aan min\n"
	.string "Machoke hehang'n.$"

