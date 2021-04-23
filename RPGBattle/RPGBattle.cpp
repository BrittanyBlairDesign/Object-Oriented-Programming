#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stdlib.h>
//Header files
#include "Stat.h"
#include "RPG_Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Items.h"



// Runs the main game loop.
int main()
{
	std::cout << "RPG Battle!\n";

	// A warrior and mage shall battle.
	//Berzerker warrior;
	//Mage mage;

	Knight Knight;
	DarkMagician DarkMage;
	std::cout << "You are a mage fighting a warrior.\n";

	while (true) {
		DarkMage.Update();
		DarkMage.Display();
		Knight.Update();
		Knight.Display();

		std::cout << "Enter command: ";

		std::string command;
		std::getline(std::cin, command);
		if (command == "attack") {
			Knight.Attack(DarkMage);
		}
		else if (command == "block") {
			Knight.Block();
		}
		DarkMage.Attack(Knight);
	}

return 0;
}


