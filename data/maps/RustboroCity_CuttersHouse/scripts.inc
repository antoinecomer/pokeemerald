RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Iederjin noemt mie de KUTKEIRL…\n"
	.string "Min NOAME IS LEIPE GUIDO…\l"
	.string "Joa, ik ambeteer min buren constant…\p"
	.string "En joa, ik kun n'en onbeschoften oap zin!\p"
	.string "En JOA. Ik kun echt goe zoagn.\n"
	.string "En JOA...Ik pis soms neffest de pot.\p"
	.string "EN JOA..IK DOE IEDERJIN EEN PROCES AN.\n"
	.string "IEDERJIN HOAT MIE.\p"
	.string "EN GIE? KZIET AL. JUST LIK DE RESTE.\n"
	.string "MOEJE KUT EBBEN? IERE!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "M'n leven, daddis KUT me peren!\n"
	.string "Me KUT kundje bwomn hakkn.\p"
	.string "Allez, ge loat u Pokémon da doen.\n"
	.string "MA! EN DADIS BELANGRIK!\p"
	.string "Ge mot gewoon jin ebn die et KAN doene,\n"
	.string "dus ge moet et under nie per sé aanljirn,\l"
	.string "gebt wok de jiste medaille nodig.\p"
	.string "En loat mie nu ma gerust, kga zjirre nog\n"
	.string "een bitje min buren goan ambeteren.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Ik zweirem, der is gin lot da zieliger\n"
	.string "is dan et kind zijn van de 'Kut Keirl'.\p"
	.string "Ik word doar nog altijd mee gepest, ma mensen\n"
	.string "snapn nie dak em wok wil pesten.$"

