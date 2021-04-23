/*
	Factory Homework 
	Brittany Blair
*/

#include <iostream>
#include "factory.h"
#include "Unit.h"

int main()
{
	YumanFactory Yumans;

	HorkFactory Horks;

	UnitFactory UnitFactory;

	std::cout << "Welcome to the Factory " << std::endl;
	int type, kind;
	while (true)
	{
		std::cout << "Choose a character Type : [1] Hork	[2]Yuman " << std::endl;
		std::cin >> type;

		std::cout << "Choose Your Specilization :  [1] Worker	[2] Melee	[3] Ranged " << std::endl;
		std::cin >> kind;

		if (type < 3 && type > 0)
		{
			if (kind > 0 && kind < 4)
			{
				Unit *pCharacter = UnitFactory.CreateUnit(type, kind);
				std::cout << pCharacter->GetUnitName() << " was created. Health -"<< pCharacter->GetHP() << "\n Behavior :" << pCharacter->GetBehavior();
			}
		}


	}
}