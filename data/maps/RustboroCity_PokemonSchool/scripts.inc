RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Et bord lijst alle statussen ip\n"
	.string "da Pokémon tiddes baterringe kunn iploopn.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Wuk eje zin om te lezen\n"
	.string "in vreselik Standoard Njiderlans?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Als uw Pokémon vergiftigd is,\n"
	.string "stop met hem opgewarmde macaroni te voeden.\p"
	.string "En ga onmiddellijk naar een Pokécenter,\n"
	.string "DIERENBEUL!\p"
	.string "Gif knaagt aan de organen van een Pokémon,\n"
	.string "tot het bezwijkt. Neem daarom altijd\p"
	.string "een 'Paracetamolleke' (Antidote) mee.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Als uw Pokémon geparalyseerd is,\n"
	.string "is hij minder Snel.\p"
	.string "Hoe zou je zelf zijn?\n"
	.string "Ooit al iets gebroken? Dacht het al.\p"
	.string "Begeef u naar een Pokécenter of\n"
	.string "gebruik een Paralyz Heal.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Als uw Pokémon slaapt tijdens een gevecht,\n"
	.string "dan is het een luiaard.\p"
	.string "Komt dat u niet bekend voor?\n"
	.string "Slapen op het werk?\l"
	.string "Het schijnt dat er een fluit bestaat\p"
	.string "die Pokémons meteen wakkerschudt.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Als uw Pokémon in brand staat,\n"
	.string "zakt zijn Aanval.\p"
	.string "Als uw Zigzagoon in brand staat,\n"
	.string "dan heeft u een 'hot dog'.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Als uw Pokémon bevroren is,\n"
	.string "vergeet het.\p"
	.string "Ga naar huis.\n"
	.string "Zoek een pikhouweel of Ice Heal.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Aje goe blokt, eje een A-attest.\n"
	.string "Aje ça va blokt, een B-attest.\p"
	.string "Ma aje een lehende zit,\n"
	.string "ton eje een C-attest. Witje wada die C is?\l"
	.string "Allez gij. De C van Quick Claw natuurlik!$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Lustert,  \n"
	.string "occasionally speed up and get to move\l"
	.string "before its opponent.\p"
	.string "There are many other items that are\n"
	.string "meant to be held by Pokémon.\p"
	.string "Just those alone will give you many\n"
	.string "topics to study!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Kben echt drie Pokémons aant ruilen vo jin.\n"
	.string "Tis mn favorieten, dus tis de moeite é.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Die keirl wil bèèèère graag een Kadabra.\n"
	.string "Kga em zjirre jin geven. Lik da ze zegn, lmao.$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Pokémons kunnen dingen vastoddn,\n"
	.string "mo ge moet gie niet verwachtn da ze zudder\l"
	.string "zelve under Paracetamolleke gon pakkn whé.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Als ne Pokémon 'in de war' es,\n"
	.string "ton zie je geskeetn whe.\p"
	.string "Sommigste kjirn goan ze een djoef ip\n"
	.string "under eigen mulle geevn. Nie gezeverd.\p"
	.string "Ik zweir em. Ge helovet toch?\n"
	.string "Ik zweeiiiiiiiiir em.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Een Pokémon die een Bes vastod,\n"
	.string "kun et zelve hebrukn…\p"
	.string "Kweenie waroem da da speshioal es.\n"
	.string "Ik ete 'k ik wok min appels ip…\p"
	.string "Mmm...ke lik een ongerke.\n"
	.string "Een goestingske…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "'t Zin de notities van ne student…\p"
	.string "… … … … … … … … … … … …\n"
	.string "… … … … … … … … … … … …\p"
	.string "{PLAYER}: D'ndien ier goat nie verre\n"
	.string "skoppn int leevn algelik.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Hallo? Ken ik u?\n"
	.string "Ah, dat groentje van Poperinge wellicht?\p"
	.string "Ik ben Scott, onaangenaam.\n"
	.string "Ik zoek Temmers met 'potentieel'.\p"
	.string "Sleutelwoorden zijn 'MET' en 'POTENTIEEL'.\n"
	.string "Jij mist helaas beide.\p"
	.string "Hier zitten sommige jonge talenten daarentegen..\n"
	.string "Ik reis Hoenn rond om talent te zoeken.\p"
	.string "Het is HOENN, spreek de H uit trouwens.\n"
	.string "En, wat doe jij hier?\p"
	.string "Misschien kan je nog iets bijleren hier.\n"
	.string "Als je een tip wilt van een expert,\p"
	.string "iemand in dit dorp kan 'CUT' aan\n"
	.string "je Pokémon aanleren. Graag gedaan..eehehe.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "Scott: Hmm… Laat me even.\p"
	.string "Het niveau en het talent van deze jongeren\n"
	.string "moet bestudeerd worden. Er is potentieel...$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "Scott: Oh, toon eens?\p"
	.string "Da is de 'Stenen Medaille' toch?\n"
	.string "Jaja, 'stjinnen medaille', goed.\p"
	.string "Hoe zal ik het zeggen. Het is...\n"
	.string "verrassend...dat jij Roxanne versloeg.\p"
	.string "Maar goed, ook het beste paard struikelt eens toch?\n"
	.string "Maak je geen illusies.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Hallo? Kenk ik u?\n"
	.string "Ah, dat groentje van Poperinge wellicht?\p"
	.string "Ik ben Scott, onaangenaam.\n"
	.string "Ik zoek Temmers met 'potentieel'.\p"
	.string "Sleutelwoorden zijn 'MET' en 'POTENTIEEL'.\n"
	.string "Jij mist helaas beide.\p"
	.string "Hier zitten sommige jonge talenten daarentegen..\n"
	.string "Ik reis Hoenn rond om talent te zoeken.\p"
	.string "Het is HOENN, spreek de H uit trouwens.\n"
	.string "En, wat doe jij hier?\p"
	.string "Misschien kan je nog iets bijleren hier.\n"
	.string "Oh, toon eens?\p"
	.string "Da is de 'Stenen Medaille' toch?\n"
	.string "Jaja, 'stjinnen medaille', goed.\p"
	.string "Hoe zal ik het zeggen. Het is...\n"
	.string "verrassend...dat jij Roxanne versloeg.\p"
	.string "Maar goed, ook het beste paard struikelt eens toch?\n"
	.string "Maak je geen illusies.$"

