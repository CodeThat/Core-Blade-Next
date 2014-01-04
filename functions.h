//functions.h

void move()
{
	switch(location)
	{
		case INTRO : intro();
			break;
		case C1 : center1(); 
			break;     
		case QUIT : 
			break;
		default : cout << "Invalid value in switchboard.\n"; 
			break;      
	}
}

/*--------------------------------------------------------------*/
void create_character()
{
	std::cout << "setup your character\n";
}

/*--------------------------------------------------------------*/
void load_character()
{
	std::cout << "loading character...\n";
}

/*--------------------------------------------------------------*/
void intro()
{
	std::cout << "You awaken, groggy, in the center of a labryinth
		<< ",you must escape this foul dungeon."; 
	location =  C1;
}

/*--------------------------------------------------------------*/
void InitializeStats()
      {
           HP = 50;
           ATK = 1;
           DEF = 1;
           EXP = 0;
           score = 0;
           NAME = "No_Name_Yet"; 
           WeaponChoice = nothing;
           MagicChoice = nomagic;
           ArmorChoice = NO_ARMOR;
           INV_count = 0;
           MagicEnergy = 20;           
      }
/*--------------------------------------------------------------*/
