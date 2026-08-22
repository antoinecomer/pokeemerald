Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "AHOY.\n"
	.string "Ik...ik zin Meneer De Zji!\p"
	.string "De zji, den dik..\n"
	.string "tafels en stoeln..\p"
	.string "en me'sn me ljilijke smoeln..\p"
	.string "Harnaaln en kroketten,\n"
	.string "en wuvn me dikke te-\p"
	.string "Ahum. Kwoarn ant wegdrômn.\p"
	.string "Ge zit welgekommen in oes 'us\n"
	.string "oan zji, doagt oes ut, wudr\l"
	.string "zin heer en meester ipt strand!$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Jit zand!\p"
	.string "Jitte batteringe!\n"
	.string "Jit weer! Fuck!\l"
	.string "Ik bluf binn' whé. Kzin verbrand!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Uw batterstijl!\n"
	.string "Nog jitter dan de zunne!\l"
	.string "Da dèk nog nwôois gezien!\p"
	.string "Als e bedankingsje,\n"
	.string "meug je dit 'ebbn van ik.\p"
	.string "N'en 'alven bak! Zuppn ga je!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Je zak zit vul moat.\n"
	.string "Kgoa ze vo je koel oddn.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Wildje e frisdrankske?\n"
	.string "Zelfs Pokémons zin der zot ip!\p"
	.string "Just 3 miljoen miljard veur e fles!\n"
	.string "Kwôpt jintje!\p"
	.string ".............\p"
	.string "Allez dan. Vo jou ma ¥300.$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Iersè!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Gie zie blut. Skooier!$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Njih?\n"
	.string "Mohowzeh.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Ip zoek noar iet?\n"
	.string "Ik zin ep zoek na jitte poezen!\l"
	.string "Mo d'enigste jitte poeze\l"
	.string "da benkik!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Ting mie datter nog e jitte poeze\n"
	.string "in the house es!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Witje wadat er goe es me e kod drankske\n"
	.string "Aba natuurlik! E jitte batteringe!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Zorg daje mie nie vervjilt.\p"
	.string "Echte temmers ljivn veur et\n"
	.string "jitst van de strid!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Jit. POEPJIT!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Whew, I'm all thirsty.\n"
	.string "Maybe I'll have a Soda Pop.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Check m'n Pokémon! Cool é?\n"
	.string "Kgoa probjirn niet te bleitn!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…Ke verlorn, mo kgon nie bleitn…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Ip een dag goak kunn' surf'n\n"
	.string "me m'en Pokémon! En ton kunk\l"
	.string "die achterlike zwemband wegsmitn.$"

