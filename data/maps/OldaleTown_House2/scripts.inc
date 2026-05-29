OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Pokémon battrn en wôrn sterker...\n"
	.string "Ik batter en 'k belandde in 't ziekenus...$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Als jen {PKMN} sterken wôrdn\n"
	.string "kundje verre heroakn in deze wjireld.\l"
	.string "'t Is echt 't absurde voorbie.$"

