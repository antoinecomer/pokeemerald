Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} skrifdehe de heheime code\n"
	.string "ip de deure.\p"
	.string "“Kwibus is love. Kwibus es LAAIF.”\n"
	.string "… … … … … … … …\p"
	.string "Moh! He hoort een klik.$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Een roar us,\n"
	.string "doar oor ik tus.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "Gie zijt ier ook tus! In 't ZotUs!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Aaah...niets beters dan\n"
	.string "mentoal hestoorde puzzels.\p"
	.string "Oost west,\n"
	.string "us best!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Miskien kunn min vohels\n"
	.string "hewone euver de muur vliehen…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Gwaaah! DJU E! GODVERDOMME!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Ehehehe… kèn verzekers verloren\n"
	.string "omdak ne valsspeler ben.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Die droaiende deuren moat,\n"
	.string "moakn mie gans mulle…bueerk$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Eje gie nen emmer?\n"
	.string "Ughhh…please…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Fuck. Ugh.\n"
	.string "Spaghetti histern, ughhh..$"

