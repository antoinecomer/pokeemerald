GraniteCave_1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, EncounterTable
	map_script MAP_SCRIPT_ON_TRANSITION, EncounterTable
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "EEEEEEEEEEEEEEEJ!\n"
	.string "Kverskiet mien e onheluk!\l"
	.string "Tes ier stifdonkr é algelik!\p"
	.string "Davers èk tzelvde meegemoakt…\n"
	.string "Kpeize datie Steven noemdehe.\p"
	.string "Em wist al oedatie Flash\n"
	.string "moeste gebrukn, dus allégow…\p"
	.string "Wudr Wandeloars, wudr 'elpn\n"
	.string "avonturiers 'n 'andje. Das ons motto!\p"
	.string "Ierse. Iermee kundje vwôrt!.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Ge kunt Flash gebrukn aje geweune\n"
	.string "ne Pokémon ip zak èt die 't KUN aanljirn,\l"
	.string "Ge moet et dus nie per se aanljirn!\p"
	.string "Mo, gebt wel ip z'n minste\n"
	.string "Brawly ip zen mulle moetn geevn.\p"
	.string "Allez. Pakt je licht\n"
	.string "en teure moa!$"
