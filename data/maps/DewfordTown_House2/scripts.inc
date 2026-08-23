DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Moet daddier nu ke zien!\p"
	.string "Voilà! Een Zijdn Foulard!!\n"
	.string "Aje ook ma een bitje modebewust zyt,\p"
	.string "ton zije toch direc' verkocht?\n"
	.string "Ik é jen drip direct hezien en ERKEND.\p"
	.string "Gie..gie farmt aura!\n"
	.string "Iere. Gie zijt et woardig!$"

DewfordTown_House2_Text_NoRoom:
	.string "Gebt gin ploatse in uwe zak?\p"
	.string "Moakt ploats of doeddem oan!\n"
	.string "Ik zou een hypotheek pakk'n vo\l"
	.string "deze foulard!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "De Zijdn Foulard moakt 'Normoale'\n"
	.string "aanvalln beter.\p"
	.string "Letterlik gelik welkne Pokémon\n"
	.string "kun em aandoen.\p"
	.string "En et ver'oogt jen aura!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Moh. Gie zijt de zee overhestookn\n"
	.string "om De Panne te bezoekn?\p"
	.string "Est omdaje zovjille gwôrd é van\n"
	.string "onzne Brawly?\p"
	.string "Daddis mijne moat…\n"
	.string "Allez. Toekomstihe moat.$"

