Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} skrifdehe de heheime code\n"
	.string "ip de deure.\p"
	.string "“We love den kwibus, we do!”\n"
	.string "… … … … … … … …\p"
	.string "Moh! He hoort een klik.$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Ge zijt ver\n"
	.string "heroakt vo n'en Temmer.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Indrukwekkend…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "GIJ ZIJT DE LIGA KAMPIOEN?!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Aan U de eer om me min te battern!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string ".................!\n"
	.string "WA!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Chançard. Een miroakel.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Moetn wudr echt battern?$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Jah…\n"
	.string "'t Was te peizn.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "'t Is een eer om tegen iemand\n"
	.string "lik gie te verliezn.$"

