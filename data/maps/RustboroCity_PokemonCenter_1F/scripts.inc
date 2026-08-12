.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_ProbopassEvo::
	msgbox RustboroCity_PokemonCenter_1F_ProbopassEvo_Text, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_ProbopassEvo_Text:
	.string "Kenje dendien? Nosepass?\n"
	.string "Dien evolueert in Stjin en Stoal.\p"
	.string "In tidde, aje een sterk mahneetisch\n"
	.string "veld nwôdig om em t'evolueern.\p"
	.string "Ma in Oenn, medol da woatr ier,\n"
	.string "en die wetenskapprs ntwa gevonden.\l"
	.string "Thunderstjin ip uw mulleeee.\l"
	.string "Lik alle probljimn int leevn,\l"
	.string "niets da gin stjin ip e mulle kun oplossn!\p"
	.string "'k Vroage min af vanwa dadde\n"
	.string "gemoakt es…$"

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Min mons zin 'naïef' en die van min\n"
	.string "moatn zin 'ophewekt' qua natuur.\p"
	.string "Peisdje da da woar es,\n"
	.string "'soort zoekt soort'? Nin toch. Ofwel..?$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Just like people, there are male and\n"
	.string "female Pokémon.\p"
	.string "But no one seems to have any idea how\n"
	.string "they're different.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "The man next door gave me an HM!\p"
	.string "I used it to teach my Pokémon how to\n"
	.string "Cut down skinny trees.$"

