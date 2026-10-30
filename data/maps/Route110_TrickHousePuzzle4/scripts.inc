Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} skrifdehe de heheime code\n"
	.string "ip de deure.\p"
	.string "“De kwibus es stoer.”\n"
	.string "… … … … … … … …\p"
	.string "Moh! He hoort een klik.$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Peizen peizen peizen.\n"
	.string "'k Moe 'k ik godganse doagn peizen!\p"
	.string "'k Goat u ke twôn'n wukdak peis!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Amai, ikke verloren?\n"
	.string "Daddak nie gepeist!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Hmmmmmmmmm...\$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Heh! Die rotsen duwen.\n"
	.string "Ik é da gin Pokémon vo nodig whé!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "'k Zou beter ke min brein trainen\n"
	.string "in plekke van men arms…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Gebrukt u koppeke zei min pa…\n"
	.string "Mja. En sebiet leg day ook zeker!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "Ik HOATTE PUZZELS.\n"
	.string "En FUCK Sudoku's!$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaak! Fuck Wordle!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "De hrwôtste kutpuzzel van allemolle?\n"
	.string "Blad stjin schoar!$"

