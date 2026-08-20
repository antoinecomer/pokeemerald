DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "'t Valt iets te zehhen over 't leevn\n"
	.string "ip een klin eilandje. 't Is ier skwône.\l"
	.string "Mo aje jinne roarn ipt eiland 'ebt,\l"
	.string "Ge ziet dendien dus ieder'n dag é.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "'k En den 'aven van Nieuwpoort\n"
	.string "verloatn vo de liefde. Skwon é.\p"
	.string "Den tyd ga troage voorut ip een\n"
	.string "eilandje. En omringd zin door\l"
	.string "'t zeetje. Daddis gelukkig zyn.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "Zigzagoon: Guguuh!\n"
	.string "(skart an zin balln)$"

