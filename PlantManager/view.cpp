#include "View.h"
#include "Plant.h"
#include "Controller.h"

void MainView::Display(std::vector<Plant>& plants, Controller* controller)
{
	// Print the Instructions.
	std::cout << "Instructions:" << std::endl << " Use Keys W and S to move your selection.\n"
											  << " To make your selection press the space bar.\n"
											  << " To Move to the next day press D.\n";

	// Print the menu title so the player knows what the view is.
	std::cout << "\t\t" << toString() << "\n\n";

	// Print the day the player is currently on.
	std::cout << "\t\t" <<"Day " << m_Day << "\n\n";

	// Print out each plant's name and the arrow next to the selection.
	// First get the current player selection.
	size_t selection = controller->GetSelection();

	// Then print the plant names with the propper selection.
	for (size_t i = 0; i < plants.size(); ++i)
	{
		if (selection == i)
		{
			std::cout << m_Arrow;
		}
		else
		{
			std::cout << m_Empty; 
		}

		std::cout << i << ") " << plants[i].GetName() << std::endl;
	}

}


void PlantView::Display(std::vector<Plant>& plants, Controller* controller)
{
	// Print the Instructions.
	std::cout << "Instructions:" << std::endl << " Use Keys W and S to move your selection.\n"
											  << " To make your selection press the space bar.\n\n";

	// Print the menu title so the player knows what the view is.
	std::cout << '\t' << '\t' << toString() << std::endl << std::endl;

	// Print out the plant's stats.
	int index = controller->GetIndex();
	std::cout << "Name : " << plants[index].GetName() << std::endl;
	std::cout << "State : " << plants[index].GetStateName() << std::endl;
	std::cout << "Moisture : " << plants[index].GetMositure() << std::endl;
	std::cout << "Growth : " << plants[index].GetGrowth() << std::endl;
	std::cout << "Pot Size : " << plants[index].PotSize() << std::endl;

	// Print out the plant's description.
	std::cout << "\nDescription : \n";
	plants[index].Description();
	std::cout << "\n\n";

	// Print the Menu Options
	int selected = controller->GetSelection();

	for (auto i = 0; i < 3; ++i)
	{
		if (selected == i)
		{
			std::cout << m_Arrow;
		}
		else
		{
			std::cout << m_Empty;
		}

		std::cout << m_Options[i] << std::endl;
	}
}