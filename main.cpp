//Core Blade Next.cpp

#include <iostream>
#include <string>
#include "classes.h"
#include "functions.h"
#include "globals.h"

using namespace std;

int main()
{
	cout << "\n\n\n\tCORE BLADE NEXT v1.0\n\n\n";

	string selection = "";
	location = INTRO;

	while(selection[0] != 'q')
	{
		cout << "\tMenu Options\n\n";
		cout << "\t(N)New Game\n\n";
		cout << "\t(L)Load Game\n\n";
		cout << "\t(Q)Quit\n";

		cin >> selection;
		selection[0] = tolower(selection[0]);
	}

	switch(selection[0])
	{
	case 'n' : create_character();
			   {
				   if(player)
				   {
					   delete player;

					   while(location != QUIT)
					   {
						   move();
					   }
					   cout << "Game Over";
					   location = INTRO;
				   }
			   }
			   break;

	case 'l' : load_character();
			   {
				   if(player)
				   {

					   while(location != QUIT)
					   {
						   move();
					   }
				   }
				   else
					   cout << "Character not found";

				   break;
			   }

	case 'q' : break;
	default  : cout << "Invalid character!";
	}

	return 0;
}
