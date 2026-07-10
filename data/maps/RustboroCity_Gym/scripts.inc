RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	goto_if_set FLAG_FINITE_TMS, RustboroCity_Gym_EventScript_GiveRockTombFinite
	msgbox RustboroCity_Gym_Text_ExplainRockTombInfinite, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GiveRockTombFinite::
	msgbox RustboroCity_Gym_Text_ExplainRockTomb MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Yeeps, ça va?\p"
	.string "Kgoa je ke wa zeggen é!\n"
	.string "Eje ambitie om Kampioen van Oen te wordn?\p"
	.string "De kampi-oen dus, hehehe. Snapjem.\n"
	.string "A-hum! Der is jin probleem damee.\p"
	.string "Der zin al die Gym Leiders...\n"
	.string "waaronder uw voadre, jaja!\p"
	.string "Ma Temmers roakn gewoonlik nie verre\n"
	.string "me geweune ne nepobaby te zin whé!\p"
	.string "En tussens ons hezegd en hezweehen,\p"
	.string "die gym leiders, past er ma van ip!\n"
	.string "Roxanne bievoorbeeld, zie gebrukt enkel\p"
	.string "mo Pokémons vant type Stjin.\n"
	.string "Waroem? Daaroem. Hin vroagn stelln.\p"
	.string "Stjin is een beeeeregoe type...\n"
	.string "ma aanhezien alles heweun bladsteenschaar es,\l"
	.string "kundje tactisch me Woatr of Hes aanvalln.\p"
	.string "Aje aar een pandoering verkwopt,\n"
	.string "komt me zien.\p"
	.string "Allez, skart em, en 't beste e!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Godmiljaar! Wa een onverwinning!\n"
	.string "Ke kik u toch wel hoed aanhemoedigd é!\p"
	.string "Juij!\n"
	.string "Check jen Temmer Koarte.\p"
	.string "Jen Stjin Medaille zot er moetn ipstoan\n"
	.string "normaal hezien toch.\p"
	.string "'t Is te zehhen…\p"
	.string "Gie èt nu je jiste stap hezet\n"
	.string "in het wordn van de Kampi-Oen!\p"
	.string "Machtig é!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Wudr Gym Temmers,\n"
	.string "wudr zin van een ander 'otje gesneedn whé!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Fak, gij zijt gij uit een nog beter 'out hesneedn…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Blad, steen, schaar.\n"
	.string "Woois al ne stjin tegen u mulle ghad?$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Aje al tehen ik verliest,\n"
	.string "ton zieje gie echt geskeetn tehen Roxanne!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Ja wadde dadde!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "Roxanne is MINSTENS vier kjirs..\n"
	.string "nint, VUF kjirs...\p"
	.string "MINSTENS ZEEVN kjirn sterker dan ik!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Lustert, vindje da nu wok hinne zjivr,\n"
	.string "min Pokés zin van Stjin, joat. Kverstoat.\p"
	.string "Daddeet RUIMTE nodig, ja.\n"
	.string "Kzit me een hasboete omdak een voetpad é vernield!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Fak maat!\n"
	.string "'k Ging 'k ik min hasboete ip u verhoaln! MILJAAR!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Een berewijze man zei ooit ne ke\p"
	.string "'De winnoar die bluvt zjivrn tehen de verliezer,\n"
	.string "krigt weldra ne stjin ip zn mulle.'$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Hoeidag, ik ben Roxanne,\n"
	.string "De Gym Leider van Kortrik.\p"
	.string "Das ier min flexijob, 'k geef wok les\n"
	.string "van wadak ljir ipt veld aan ons\l"
	.string "skoole vo Temmers verderip.\p"
	.string "En nu ist tid dak u ne ke\n"
	.string "een lesje ljir. Zet je schrap!$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Ah…\n"
	.string "Duidelik versloahen…\p"
	.string "'k E nog precies zelve vjille bie te\n"
	.string "te ljirn…\p"
	.string "Boodskap oanhekomn.\p"
	.string "Volhens de rehels eje gie rechte\n"
	.string "ip je Medaille.\l"
	.string "Aanvaard et.\p"
	.string "Skouders recht. Ge zie sterk.\n"
	.string "En woardig van min Stjinnen Medaille.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} kreeg de Stjinnen Medaille\n"
	.string "van Roxanne.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "Die medaille, da dwingt wa respect af\n"
	.string "van u bjistjes, uw Pokémons.\p"
	.string "Under Attak is een pak 'oher,\n"
	.string "en ge kunt nu CUT gebrukn.\p"
	.string "Names de Kortrikzanen excuseer ik mij vo\n"
	.string "dien absoluten debiel die CUT geeft.\pak
	.string "Ah, en ierse, nog iet.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Dit Technisch Machine, TM39,\n"
	.string "bevat Rock Tomb.\p"
	.string "Ak et in jin woord zou motn beskrivn,\n"
	.string "'t is mahhtig.\p"
	.string "Past ip, ge kun een TM\n"
	.string "ma jin ke aanljirn.$"
	.string "Ajet dus gebrukt, ist weh.\n"
	.string "Verstoajt?$"

RustboroCity_Gym_Text_ExplainRockTombInfinite:
	.string "Dit Technisch Machine, TM39,\n"
	.string "bevat Rock Tomb.\p"
	.string "Ak et in jin woord zou motn beskrivn,\n"
	.string "'t is mahhtig.\p"
	.string "Aje een TM gebrukt, vjil mesn peizen\n"
	.string "miljaar, m'en TM is na de klutn.$"
	.string "Niets in mindr woar, ge kunt da oneindig\n"
	.string "gebrukn, aja é.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "'t Leevn is lik e rondpunt,'\n"
	.string "ge pakt n'en afslag, en ge mist er drie!\p"
	.string "Gie èt dudelik talent. Doagt Brawly ut in De Panne,\n"
	.string "en mist uwen afslag niet!$"

RustboroCity_Gym_Text_GymStatue:
	.string "Kortrijkse Pokémon Gym$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "Pokémon Gym van Kortrijk\p"
	.string "Temmers gecertificeerd door Roxanne:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Biep!\p"
	.string "Roxanne: Ah, allo, {PLAYER}?\n"
	.string "Tis ier me Roxanne van Kortrik!\p"
	.string "Seg, kekkik gwôrd van den Brawly daj\n"
	.string "serieus vooruthang oant moakn zie,\l"
	.string "en daje ne serieuze sprong hemoakt é.\p"
	.string "Awel, gebt mie echt hemotiveerd vo\n"
	.string "min Gym te erpakkn, en mezelve wok.\p"
	.string "'k Wille kik nie helovn dakkik u nie kunne\n"
	.string "versloan. Dus komt gerust een dezer nog ke\p"
	.string "terug na Kortrik, ik kik der alleszins naar ut\n"
	.string "om je were te zien! En 'k hope gie wok!\p"
	.string "… … … … … …Salutjes é!\n"
	.string "… … … … … Klik!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Et nummer van Gym Leider Roxanne\n"
	.string "is toehoevoegd in den Pokénav.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "Roxanne: Kzin bere content je were te zien.\n"
	.string "Ik, Roxanne, Gym Leider zijnde,\p"
	.string "zin vet betoald om u af te kusn.?\n"
	.string "En kzin nog bitje verbeterd whe\p"
	.string "sinds de loatste ke.\n"
	.string "Odje ma vast!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Eens te meer…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "Roxanne: Miskien moek min stratehie\n"
	.string "erzien wanneer dat ip Pokémons aankomt.\p"
	.string "Ik zie et licht nu....amai zo fel,\n"
	.string "wuk blinkt er ier in min ogen?!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "Roxanne: Kzin bere content je were te zien.\n"
	.string "Ik, Roxanne, Gym Leider zijnde,\p"
	.string "zin vet betoald om u af te kusn.?\n"
	.string "En kzin nog bitje verbeterd whe\p"
	.string "sinds de loatste ke.\n"
	.string "Odje ma vast!$"
	.string "Mo meendje gie da nu…\n"
	.string "Wie n'èt er nu ma JIN Pokémon ip zak?\p"
	.string "How, goat u ne Zigzagoon gan vangn.\n"
	.string "En kom ma zjirre me MINSTENS 2 terug.$"
