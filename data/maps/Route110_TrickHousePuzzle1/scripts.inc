Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} skrifdehe de heheime code\n"
	.string "ip de deure.\p"
	.string "“De kwibus is heweldig.”\n"
	.string "… … … … … … … …\p"
	.string "Moh! He hoort een klik.$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "CUT ier! CUT doar! CUT ip uw muil!\n"
	.string "Verliezen? Das peren me CUT!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "CUTzooi...$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Amai gie CUT er nogal wa van,\n"
	.string "nie? Njeeeee?$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Ik benkik hjil verdwoald zeg.\n"
	.string "Belt den 112…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Verdwoald en vernederd…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Toen Kurt Cobain in de shit zat,\n"
	.string "éet ie ook gin paracetamol gepakt é…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Wien es dien kwibus eihenlik?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Tel nie whé 'k was oant peizn!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Amai gie traint je Pokémons wel hoêd!\n"
	.string "Wie zije gie eihenlik?$"

