Route102_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EncounterTable
	map_script MAP_SCRIPT_ON_RESUME, EncounterTable
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon:
	.string "Wally: {PLAYER}…\n"
	.string "Pokémon verstopp'n zich in't,\l"
	.string "da hes ier zekers?\p"
	.string "Zoudje een oogje in't zeil\n"
	.string "kunn' od'n vo mie?\p"
	.string "…Wow!$"

Route102_Text_WallyIDidIt:
	.string "Wally: Amai… Min jiste…\n"
	.string "Min jiste Pokémon!$"

Route102_Text_LetsGoBack:
	.string "{PLAYER}, echt merci whe!\n"
	.string "Keren we ons karre weer na de Gym?$"

Route102_Text_ImNotVeryTall:
	.string "'k Ben 'k ik ne kleinen e,\n"
	.string "da hes kom bijkanst tot min neuse!\p"
	.string "Ge kun mie bikan nie meer zien!\n"
	.string "Fwafwafwafwafwa…\p"
	.string "ATCHOE!$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "Ik ga echt. Mo echt. Geskift veel\n"
	.string "Pokémon vang'n!$"

Route102_Text_RouteSignOldale:
	.string "Boane 102\n"
	.string "{RIGHT_ARROW} Oostrozebeke$"

Route102_Text_RouteSignPetalburg:
	.string "Boane 102\n"
	.string "{LEFT_ARROW} Poperinge$"
