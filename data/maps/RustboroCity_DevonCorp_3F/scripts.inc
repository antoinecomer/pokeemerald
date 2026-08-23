.set LOCALID_DEVON_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_EXP_SHARE_SMALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Elk zin dag, ik benne Mr. Verstichel,\n"
	.string "den Sie Ie Ooh, jazeker.\p"
	.string "'k Eb just 't 1 en 't ander over u g'oord!\p"
	.string "Gie èt ons personeel gered, nie 1 kji..\n"
	.string "MO 2 KJI! Alléhow zeg.\p"
	.string "'k Goa 'k ik u toch nog iet moet'n vroagn,\n"
	.string "'k ga mie nie generen!\p"
	.string "A'k et goe behrepen eb..\n"
	.string "moeje gie toch algelik in Nieuwpoort zin.\p"
	.string "Zoudjet zien zitn om een tussenstopke\n"
	.string "te moakn in De Panne?\p"
	.string "'k Zou geirn èn daje n'en brief\n"
	.string "afgeeft aan de Steven.\p"
	.string "Een jobke a's postduf, en goe betoald!$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "Mr. Verstichel: Nu, ge moet weetn,\n"
	.string "min hénérositeit n'è gin hrenzn.\p"
	.string "Dus ik 'è 'k ik nog 'n twa\n"
	.string "vo jen, gratis en vo niet.\p"
	.string "Nint, n' is gin twintigduusd dollar.$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} krigt den Pokénav.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "Mr. Vertsichel: Da machientje…\p"
	.string "Daddis ne 'Hé Pé Es', oftewel ne Navihator,\n"
	.string "me Poké dervoor want da klonk goêd.\p"
	.string "Gin vroagn steln, geweun oanvoardn.\n"
	.string "Elkne temmer, ELKNEN temmer è da nodig.\p"
	.string "Et é een koarte. Me stroatnam'n enal.\n"
	.string "Oe vindje anders jenne weg terug?\p"
	.string "Ma echt tot in de details enal é!\n"
	.string "Hjil Oen, allez Hoenn, in je broekzak.\p"
	.string "Daddis toch machtig...?\n"
	.string "Aja nog iets, {PLAYER},\l"
	.string "der is een vré gespuis ip de boane.\p"
	.string "Van die witi's die zich Aqua of Mahma\p"
	.string "noemn, geweune negeren en\n"
	.string "gin spel mee zoekn, verstoajt?$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "Mr. Vertsichel: En ezo, voilà se. Moh,\n"
	.string "kiek ne ke na 't uur zeg,\l" 
	.string "is 't al zo laat zeg?\p"
	.string "(Mr. Verstichel klapt in z'n handen) Jah!\p"
	.string "Allez moakt daje wegkomt,\n" 
	.string "kheb sebiet vergoaringe.\l"
	.string "Ik kun ip u rekenen!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "Mr. Verstichel: Ik reken ip u!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "Mr. Vertsichel: Gie èt min brief kun' afgeevn?\n"
	.string "Mor allez, n'en dikke merci whè!\p"
	.string "Gie é, gie goat et ver skopn int leevn.\n"
	.string "Voilà se, wa peisdje daarvan!$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "Mr. Verstichel: Eje gie woois\n"
	.string "al g'wôrd van\l"
	.string "Daart Plahies de Wijzn?\p"
	.string "Khad et al hepeist.\p"
	.string "Tè hin verhoal datie Jedi u zodn v'rtelln.\p"
	.string "Tis een lehende van de Sits.\p"
	.string "Daart Plahies wa nen dustern eer\n" 
	.string "van de Sits,\l"
	.string "ie was zo mahtih en slimme datie\l"
	.string "de Kraht è kunn'n hebruikn vo de\l"
	.string "midihlorian'n te beïnvloed'n\l"
	.string "en ezo Leevn te creëren..\p"
	.string "Ie ad zovjil kennis van de\n"
	.string "dusterre kant datie dehene kon redd'n\l"
	.string "datie heirn ad van de dood.\p"
	.string "De dusterre kant van de Kraht opent deurn\n"
	.string "tot vjille meuhlikeedn\l"
	.string "da sommihe me'sn wel onnatuurlik\l" 
	.string "zodn durvn noemn!\p"
	.string "Ie werd zo mahtih...\n"
	.string "t'eenihste datie poepers voor ad\l" 
	.string "was et verliez'n\l"
	.string "van zijn Kraht, datie, uiteindelik,\l" 
	.string "aba natuurlik, e hedoan.\p"
	.string "Spittihe zoake, ie ift zijne student\n"
	.string "oalles aanheleerd datie wist, en ton eeft\l"
	.string "diene leerjong'n em in zijne\l"
	.string "slaap afhemoakt.\p"
	.string "Ironisch e.\p"
	.string "Ie kost wel anderen van de dwood redd'n...\n"
	.string "mo nie emzelve...\p"
	.string "… … … … … … … … … … …\p"
	.string "Witje wada em gered kon ebn?\p"
	.string "Ons product, EXP SHARE! Abaja natuurlik é.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "Mr. Verstichel: Sinds min jeugd, ek mie\n"
	.string "gesmeetn in me werk.\p"
	.string "Tis just damé dak lik nie alsan mee ben\n"
	.string "me wa da nu 'hip' is. Ist nu amongus of sixseven?\p"
	.string "In minnen tid é, YugiOh, Pokémon, Dragon Ball,\n"
	.string "de Elite 4 afmoakn, daar goat et om zeg ik u!$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Dit is den derden étage\n"
	.string "in Balco.\p"
	.string "Den bureau van onzne SIE IE OH\n"
	.string "is ep 't skwon verdiep é.\p"
	.string "Kwille je nog ke stif bedanken\n"
	.string "voor al daje voor oes gedoan èt.\p"
	.string "Zeg eh… da pakketje\n"
	.string "daje èt kunn'n bemachtigen…\p"
	.string "Zojt zien zitn om da ip de skeepswerf in\n"
	.string "Nieuwpoort te gon afgeevn?\p"
	.string "Als da ellendig, miserabel krapul,\n"
	.string "da uitschot van Team Aqua en Magma,\p"
	.string "weer udder vulle pwotn…\n"
	.string "sorry whé, kmoe afkoeln.\l"
	.string "Ma serieus, kundje da rehelen?\p"
	.string "Ah en nog iet!\n"
	.string "Kundje ier een secondje wachtn?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Onzne Président zod een klaptje\n"
	.string "willen doen met u! Ge zijt vriendlik\p"
	.string "gevroagd om mie te volgen.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Ga veurt, en vermenigvuldig u!\n"
	.string "{PLAYER}: ..?!\p"
	.string "Ik neem niets terug.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Aje de skeepswerf in Nieuwpoort ga zien,\n"
	.string "zodje in principe Kap'tein Haddock moetn zien.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Ge weet, wudr verkwo'pn van die Pokéballen é.\n"
	.string "Da bring nog bitje geld binn' whé.\l"
	.string "Vervuiling? Microplastiek? Nie truntn é.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Een machtige collectie...\n"
	.string "...spittige zoake dat et stjin'n betreft.$"

