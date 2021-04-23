#include "Controller.h"
#include "View.h"
#include "Plant.h"
#include <conio.h>

///////////////////////////////
///		MAIN CONTROLLER
///////////////////////////////
void MainController::Update()
{
	//First update all the controllers and reset their bools.
	for (auto i = 0; i < m_PlantMenus.size() ; i++)
	{
		m_PlantMenus[i].Update();
	}

	// Next update all of the plants for the next round.
	for (auto i = 0; i < m_Plants.size(); i++)
	{
		m_Plants[i].Update();
	}

	// Then increase the day displayed on the main menu.
	m_pMainMenu->ChangeDay();

	// Finally reset the selection for the main controller
	m_Selection = 0;
}

void MainController::PrintMenu()
{
	// Clear the screen.
	system("CLS");

	// Display the Main menu.
	m_pMainMenu->Display(m_Plants, this);
}

void MainController::MoveSelection(char move)
{
	// Increase or decrease selection as long as it's within the menu.

	size_t PlantSize = m_Plants.size() - 1;

	if (move == 'w')
	{
		if (m_Selection - 1 >= 0)
		{
			--m_Selection;
		}
	}
	else if (move == 's')
	{
		if ((m_Selection + 1) <= PlantSize)
		{
			++m_Selection;
		}
	}
}

void MainController::MakeSelection()
{
	// Open the selected plant's menu.
	m_PlantMenus[m_Selection].PrintMenu();
}

///////////////////////////////
///		PLANT CONTROLLER
///////////////////////////////

void PlantController::Update()
{
	m_isInMenu = true;
}

void PlantController::PrintMenu()
{
	// Clear the screen.
	system("CLS");

	// Display this plant's menu.
	m_pPlantView->Display(m_Plants, this);
}

void PlantController::MoveSelection(char move)
{
	// Increase or decrease selection as long as it's within the menu.
	if (move == 'w')
	{
		if (m_Selection - 1 >= 0)
		{
			--m_Selection;
		}
	}
	else if (move == 's')
	{
		if (m_Selection + 1 <= 2)
		{
			++m_Selection;
		}
	}
}

void PlantController::MakeSelection()
{
	// Run a function based off of the selection.
	if (m_Selection == 0)
	{
		WaterPlant();
	}
	else if (m_Selection == 1)
	{
		RepotPlant();
	}
	else if (m_Selection == 2)
	{
		m_isInMenu = false;
	}
}

void PlantController::WaterPlant()
{
	// Only water if the plant has not already been watered.
	while (!m_Plants[m_Index].IsWatered())
	{
		// Ask the player what amount of water they would like to add.
		std::cout << "How much water would you like to add to this plant?\n";
		double amount;
		std::cin >> amount;

		// as Long as the player chooses less than 100 and more than zero they can continue.
		if (amount <= 100 && amount > 0)
		{
			m_Plants[m_Index].ChangeMoisture(amount);
			m_Plants[m_Index].Watered();
		}
		else
		{
			std::cout << "Please choose a number between 1 and 100.";
		}
	}

}

void PlantController::RepotPlant()
{
	// Only allowed to re-pot the plant if it has not already been re-potted within this turn.
	if (!m_Plants[m_Index].IsRePotted())
	{
		m_Plants[m_Index].RePot();
		m_Plants[m_Index].RePotted();
	}
}