//classes.h
#include "functions.h"

class Entity
{
      public:
             
      Entity() 
      { 
                cout << "\n\tCreating Entity object."; 
                InitializeStats();
      }
      
      ~Entity() { cout << "\n\tDestroying Entity Object."; }
      
 //------------------------------------------------------------------------

      void DisplayStats() 
      { 
           char x[10];
           string STATS = 
"\n\n     -------------------------------STATS--------------------------------\n";
           STATS = STATS + "      PLAYER: " + NAME; 
           STATS = STATS + " SEX:" + gender; 
           itoa(HP,x,10);
           STATS = STATS + " HP:" + x;
           itoa(ATK,x,10);
           STATS = STATS + " ATK:" + x;
           itoa(DEF,x,10);
           
           STATS = STATS + " DEF:" + x;
           itoa(EXP,x,10);
           STATS = STATS + " EXP:" + x;
           itoa(score,x,10);
           STATS = STATS + " SCR:" + x;
           STATS = STATS + " CLS:";

           switch(Entity_CLASS)
           {
               case DRAGON : STATS = STATS + "Dragon"; break;
               case GIANT : STATS = STATS + "Giant"; break;
               case SHAMAN : STATS = STATS + "Shaman"; break;
               case WARRIOR : STATS = STATS + "Warrior"; break;
               case MAGE : STATS = STATS + "Mage"; break;
               case FIGHTER : STATS = STATS + "Fighter"; break;
               case ELF : STATS = STATS + "Elf"; break;
               default : cout << "\n     Error. Bad input!";                         
           }
           
           STATS = STATS + "\n      WEAPON:";
           
           switch(WeaponChoice)
           {
                case nothing : STATS = STATS + "Nothing but ";
                               if(gender == "Male") 
                               { STATS = STATS + "his"; }
                               else
                               { STATS = STATS + "her"; }
                               STATS = STATS + " fists!"; 
                               break;
                case broadsword : STATS = STATS + "BroadSword"; break;
                case dagger : STATS = STATS + "Dagger"; break;
                case staff : STATS = STATS + "Staff"; break;
                case crossbow : STATS = STATS + "CrossBow"; break;
                case longbow : STATS = STATS + "LongBow"; break;
                default : cout << "\n     Bad Input!"; break;                    
           }   

           STATS = STATS + " ARMOR:";
           
           switch(ArmorChoice)
           {
                case NO_ARMOR : STATS = STATS + " Nothing"; break;
                case CHAIN_MAIL : STATS = STATS + "Chain"; break;
                case PLATE_MAIL : STATS = STATS + "Plate"; break;
                default : cout << "\n     Bad Input!"; break;                    
           }   
           
           STATS = STATS + " MAGIC:";
           
           switch(MagicChoice)
           {
                    case nomagic : STATS = STATS + 
                                   "None";
                                   break;
                    case fire : STATS = STATS + 
                                "Fire";
                                break;
                    case ice : STATS = STATS + 
                               "Ice";
                               break;
                    case lightning : STATS = STATS + 
                                     "Lightning";
                                     break;
                    case telekinetic_force : STATS = STATS + 
                                             "Telekinesis";
                                             break;
                    case invisibility :  STATS = STATS + 
                                         "Invisibility";
                                         break;
                    case healing : STATS = STATS + 
                                   "Healing";
                                   break;               
                    default : STATS = STATS + "\n     Invalid input.\n"; break;      
           }   
           itoa(MagicEnergy,x,10);
           STATS = STATS + "  ME:" + x;
                   
           STATS = STATS + 
           "\n     --------------------------------------------------------------------\n";
           
           cout << STATS;     
      }

//------------------------------------------------------------------------

      void Attack(Entity * opponent)
      {
           char x[10];
           string OUTPUT = "";
           DisplayStats();  
           OUTPUT = OUTPUT + 
                    "\n\n\t-------------------- Attack for " + NAME + " --------------------"
                    + "\n\t" + opponent->GetNAME() + "'s hitpoints BEFORE " 
                    + NAME + "'s attack: ";

           itoa(opponent->GetHP(),x,10);
           OUTPUT = OUTPUT +  x + "\t\n";
          
           int damage = ((rand()%MaxDamage) + 1);
           
           //Note: Need to write separate behavior and if clause for each
           //character class, for now just using same for all 4.
           if(Entity_CLASS == WARRIOR ||
              Entity_CLASS == MAGE ||
              Entity_CLASS == FIGHTER ||
              Entity_CLASS == ELF ||
              Entity_CLASS == SHAMAN)
           {
              OUTPUT = OUTPUT + "\n\tWeapon Attack: " + NAME;
           
              switch(WeaponChoice)
              {
                  case nothing : OUTPUT = OUTPUT + " fights with bare fists of fury!\n\t"; 
                                 break;
                  case dagger : damage = damage + DaggerDamage;
                                OUTPUT = OUTPUT + " stabs with the dagger!\n\t" 
                                + "This weapon increases ";
                                if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                else { OUTPUT = OUTPUT + "her"; }
                                OUTPUT = OUTPUT + " attack by ";
                                itoa(DaggerDamage,x,10); 
                                OUTPUT = OUTPUT + x + 
                                " for a total of\n\t";
                                itoa(damage,x,10); 
                                OUTPUT = OUTPUT + x + " damage.\n";
                                break;
                  case staff : damage = damage + StaffDamage;
                                OUTPUT = OUTPUT + " twirls the bo staff. Crack!\n\t" 
                                + "This weapon increases ";
                                if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                else { OUTPUT = OUTPUT + "her"; }
                                OUTPUT = OUTPUT + " attack by ";
                                itoa(StaffDamage,x,10); 
                                OUTPUT = OUTPUT + x + 
                                " for a total of\n\t";
                                itoa(damage,x,10); 
                                OUTPUT = OUTPUT + x + " damage.\n";
                                break;                                 
                 case longbow : damage = damage + LongBowDamage;
                                OUTPUT = OUTPUT + " fires an arrow from the long bow!\n\t" 
                                + "This weapon increases ";
                                if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                else { OUTPUT = OUTPUT + "her"; }
                                OUTPUT = OUTPUT + " attack by ";
                                itoa(LongBowDamage,x,10); 
                                OUTPUT = OUTPUT + x + 
                                " for a total of\n\t";
                                itoa(damage,x,10);
                                OUTPUT = OUTPUT + x + " damage.\n";
                                break;                                
                  case crossbow : damage = damage + CrossBowDamage;
                                  OUTPUT = OUTPUT + " fires a bolt from the crossbow!\n\t" 
                                  + "This weapon increases ";
                                  if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                  else { OUTPUT = OUTPUT + "her"; }
                                  OUTPUT = OUTPUT + " attack by ";
                                  itoa(CrossBowDamage,x,10); 
                                  OUTPUT = OUTPUT + x + 
                                  " for a total of\n\t";
                                  itoa(damage,x,10);
                                  OUTPUT = OUTPUT + x + " damage.\n";
                                  break;            
                  case broadsword : damage = damage + BroadSwordDamage;
                                    OUTPUT = OUTPUT + " swings the mighty broadsword!\n\t" 
                                    + "This weapon increases ";
                                    if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                    else { OUTPUT = OUTPUT + "her"; }
                                    OUTPUT = OUTPUT + " attack by ";
                                    itoa(BroadSwordDamage,x,10); 
                                    OUTPUT = OUTPUT + x + 
                                    " for a total of\n\t";
                                    itoa(damage,x,10); 
                                    OUTPUT = OUTPUT + x + " damage.\n";
                                    break;
                  default : cout << "Invalid Input!"; break;                    
              } 
           }  
           
           if(Entity_CLASS == MAGE ||
              Entity_CLASS == SHAMAN ||
              Entity_CLASS == ELF) 
           {
                switch(MagicChoice)
                {
                    case nomagic : OUTPUT = OUTPUT + 
                                   "\n\tNo magic is being used now.\n";
                                   break;
                    case fire : damage = damage + Magic_FireDamage;
                                OUTPUT = OUTPUT + 
                                "\n\tMagic Attack: " + NAME + 
                                " blasts a fire ball at ";
                                if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                else { OUTPUT = OUTPUT + "her"; }
                                OUTPUT = OUTPUT + 
                                " opponent \n\t"
                                "burning ";
                                itoa(Magic_FireDamage,x,10); 
                                OUTPUT = OUTPUT + x +
                                " points of damage into them!\n";
                                MagicChoice = nomagic;
                                break;
                    case ice : damage = damage + Magic_IceDamage;
                               OUTPUT = OUTPUT + 
                               "\n\tMagic Attack: " + NAME + 
                               " lowers the ambient temperature of ";
                               if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                               else { OUTPUT = OUTPUT + "her"; }
                               OUTPUT = OUTPUT + 
                               " opponent \n\t"
                               "freezing them with ";
                               itoa(Magic_IceDamage,x,10); 
                               OUTPUT = OUTPUT + x +
                               " points of damage!\n";
                               MagicChoice = nomagic;
                               break;
                    case lightning : damage = damage + Magic_LightningDamage;
                                     OUTPUT = OUTPUT + 
                                     "\n\tMagic Attack: " + NAME + 
                                     " blasts the opponent with  ";
                                     if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                     else { OUTPUT = OUTPUT + "her"; }
                                     OUTPUT = OUTPUT + 
                                     " lightning bolt! \n\t"
                                     "This electrifies them, doing ";
                                     itoa(Magic_LightningDamage,x,10); 
                                     OUTPUT = OUTPUT + x +
                                     " points of damage!\n";
                                     MagicChoice = nomagic;
                                     break;
                    case telekinetic_force : damage = damage + Magic_TelekineticDamage;
                                             OUTPUT = OUTPUT + 
                                             "\n\tMagic Attack: " + NAME + 
                                             " telekinetically throws and object at\n\t";
                                             if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                             else { OUTPUT = OUTPUT + "her"; }
                                             OUTPUT = OUTPUT + 
                                             " opponent, doing a massive ";
                                             itoa(Magic_TelekineticDamage,x,10); 
                                             OUTPUT = OUTPUT + x +
                                             " points of damage!\n";
                                             MagicChoice = nomagic;
                                             break;
                    case invisibility :  //After 5 rounds, invisibility wears off and restores DEF
                                         if(INV_count == 0)
                                         {
                                                DEF = DEF + Magic_InvisibilityDefense;
                                                INV_count = 5;
                                         }  
                                         
                                         if(INV_count > 1)
                                         {
                                               INV_count--; 
                                               OUTPUT = OUTPUT + 
                                               "\n\tMagic Defense: " + NAME 
                                               + " employs invisibility, bending\n\t"
                                               + "the light around ";
                                               if(gender == "Male") { OUTPUT = OUTPUT + "him"; }
                                               else { OUTPUT = OUTPUT + "her"; }
                                               OUTPUT = OUTPUT + "self and increasing ";
                                               if(gender == "Male") { OUTPUT = OUTPUT + "his"; }
                                               else { OUTPUT = OUTPUT + "her"; }
                                               OUTPUT = OUTPUT + 
                                               " defensive\n\tcapability by 1 for 5 rounds.\n\t";
                                               itoa(INV_count,x,10); 
                                               OUTPUT = OUTPUT + "\n\tThere are " + x + " round(s) of "
                                               + "invisibility left.\n";
                                               cout << "\n\n\tCOUNT = " << INV_count << "\n\n";
                                          }
                                          else
                                          { 
                                              INV_count = 0;
                                              DEF = DEF - Magic_InvisibilityDefense;
                                              MagicChoice = nomagic;
                                          }
                                        break;
                    case healing : break;               
                    default : OUTPUT = OUTPUT + "\n\tInvalid input.\n"; break;
                }                                       
           }                              

           if(damage > opponent->GetDEF())
           { damage = damage - opponent->GetDEF(); }
           else { damage = 0; }

           if(opponent->GetHP() - damage > 0)
           { opponent->SetHP(opponent->GetHP() - damage); }
           else { opponent->SetHP(0); }

           OUTPUT = OUTPUT + "\n\t" + opponent->GetNAME() + "'s hitpoints AFTER " 
                    + NAME + "'s attack: ";
           
           itoa(opponent->GetHP(),x,10);
           OUTPUT = OUTPUT +  x + "\t";
           
           OUTPUT = OUTPUT + "\n\t----------------------------------------------------------\n\n";
              
           cout << OUTPUT;
      }

 //------------------------------------------------------------------------
           
      //Accessor Methods
      void SetHP(int x) { HP = x; }
      void SetATK(int x) { ATK = x; }
      void SetDEF(int x) { DEF = x; }
      void SetEXP(int x) { EXP = x; }
      void SetScore(int x) { score = x; }
      void SetWeaponChoice(int x) { WeaponChoice = x; }      
      void SetMagicChoice(int x) { MagicChoice = x; }
      void SetArmorChoice(int x) { ArmorChoice = x; }
      void SetEntity_CLASS(int x) { Entity_CLASS = x; }       
      void SetNAME(string x) { NAME = x; }
      void SetGender(string x) { gender = x; }
      void SetMagicEnergy(int x) { MagicEnergy = x; }    
      
      int GetHP() { return HP; }
      int GetATK() { return ATK; }
      int GetDEF() { return DEF; }
      int GetEXP() { return EXP; }
      int GetScore() { return score; } 
      int GetWeaponChoice() { return WeaponChoice; }
      int GetMagicChoice() { return MagicChoice; }
      int GetArmorChoice() { return ArmorChoice; }      
      int GetEntity_CLASS() { return Entity_CLASS; }
      string GetNAME() { return NAME; }
      string GetGender() { return gender; }
      int GetMagicEnergy() { return MagicEnergy; }

      
      private:
      int HP;
      int ATK;
      int DEF;
      int EXP;
      int score;
      int WeaponChoice;
      int MagicChoice;
      int ArmorChoice;
      int Entity_CLASS;
      string NAME;
      string gender;
      int INV_count; 
      int MagicEnergy;          
};

/*--------------------------------------------------------------*/
class character
{
	public:
		player() {std::cout << "Creating a player\n";}
		~player() {std::cout << "Destroying a player\n";}
};

/*--------------------------------------------------------------*/
class monster
{
	public
		monster() {std::cout << "Creating a monster\n";}
	~monster() {std::cout << "Destroying a monster\n";}

};


/*--------------------------------------------------------------*/
void center1()
{

}

/*--------------------------------------------------------------*/


