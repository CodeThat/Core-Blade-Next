//globals.h

/* function prototypes */
void create_character();
void load_character();
void intro();

int location;

enum LOCATIONS{QUIT,INTRO,C1};


/* Class prototypes */
class player;

/* Objects for characters and monsters */
character * player;
