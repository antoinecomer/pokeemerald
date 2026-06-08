.set LOCALID_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Jist..de kompioeter...\n"
	.string "Ton Hoehel…mo nu?\p"
	.string "Zjéminie? Kloot? Zjat-giepietie?\n"
	.string "Wo goat de weirld natoe?$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Ik e just beslot'n\n"
	.string "dak min Pokémons véhétaries zin!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Oeveel types Pokémons?\p"
	.string "Bereveel. Oeveel zeg je?\n"
	.string "Geskift veel. Oeveel?\p"
	.string "HIHANTIES VEEL...\n"
	.string "Ting mie daje nog vjille moe ljirn.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Bievoorbeeld, jen Treecko\n"
	.string "is van 't type Hes.\p"
	.string "Beresterk tehen Woatr en\n"
	.string "Hrond.\p"
	.string "Ma rete tegen alles dat em\n"
	.string "in de fik kun steekn.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Bievoorbeeld, jen Torchic\n"
	.string "is van 't type Fikn.\p"
	.string "Alles da Hes of Insectn stikt\n"
	.string "ie maklik in de fik.\p"
	.string "Mo tehen Woatr-Pokémon moej\n"
	.string "ipletn whé.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Bievoorbeeld, jen Mudkip\n"
	.string "is van 't type Woatr.\p"
	.string "Beresterk tegen dedie da Fikn.\p"
	.string "Ma rete tehen dedie me Elektriek\n"
	.string "of Hes.$"

