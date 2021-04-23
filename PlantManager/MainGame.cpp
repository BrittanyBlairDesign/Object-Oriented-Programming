/*
		  Plant Manager
	Created by Brittany Blair
*/
#include <conio.h>

#include "Plant.h"
#include "View.h"
#include "Controller.h"

// This function is used to determine when the game is over, or if the game is still going on.
bool isPlaying(std::vector<Plant> plants)
{
	//Get the plant size in a variable. 
	size_t plantcount = plants.size();

	// Keep track of how many plants are alive or dead.
	size_t Deadplants = 0, Grownplants = 0;

	for (size_t i = 0; i < plantcount; ++i)
	{
		std::string state = plants[i].GetStateName();

		if (state == "Dead")
		{
			++Deadplants;
		}
		else if (state == "FullGrown")
		{
			++Grownplants;
		}
	}

	size_t allPlants = Deadplants + Grownplants;
	// Determine weather or not ALL the plants are alive or dead.
	if (allPlants == plantcount)
	{
		// Clear the screen.
		system("CLS");

		// You get a unique ending based off of how many plants survive.
		if (Grownplants == plantcount)
		{
			std::cout << "Congradulations! You beat the game with a garden full of helthy plants!";
		}
		else if (Grownplants > Deadplants)
		{
			std::cout << "You've finished the game! You beat the game with most of your plants alive!";
		}
		else if (Grownplants == Deadplants)
		{
			std::cout << "You've finished the game! Only half of your plants survived. Better luck next time.";
		}
		else if (Grownplants < Deadplants)
		{
			std::cout << "The game is now completed. More than half of your plants have died. Better luck next time.";
		}
		else if (Deadplants == plantcount)
		{
			std::cout << "Game over. All of your plants have died. Better luck next time.";
		}

		// Return false, offically ending the game loop
		return false;
	}
	else
	{
		// Return true, continuing the game loop.
		return true;
	}
}

int main()
{
	// Create my plants inside of a vector.
	std::vector<Plant> Plants;

	Plants.push_back(Plant("Sunflower", 70.0));
	Plants.push_back(Plant("Cactus", 30.0));
	Plants.push_back(Plant("Spider plant", 80.0));
	Plants.push_back(Plant("Devil's ivy", 50.0));

	// Create the main view.
	MainView MainView;

	// Create plant view.
	PlantView PlantView;
	std::vector<PlantController> PlantControllers;
	
	// Populate my plant controller vector with pointers to the plants and a plant view pointer.
	for (int i = 0; i < Plants.size(); ++i)
	{
		// Create new plant controller.
		PlantControllers.push_back(PlantController(Plants, &PlantView, i));
	}

	// Create the main menu controller.
	MainController MainController(Plants, PlantControllers, &MainView);

	// Game loop.
	// This loop will continue as long as there are plants that are not fully grown or dead.
	while (isPlaying(Plants))
	{
		// Print the main menu.
		MainController.PrintMenu();

		// Get the player's input.
		char choice = _getch();
		
		// If the player Makes a selection open the selected plant's menu.
		if (choice == ' ')
		{
			MainController.MakeSelection();
			
			size_t selection = MainController.GetSelection();

			// Stay within this sub loop as long as the player is within this plants menu.
			while (PlantControllers[selection].isInMenu())
			{
				// Get the player's input for this plant.
				char plantChoice = _getch();

				if (plantChoice == ' ')
				{
					// Make the player's selection and re-print the menu.
					PlantControllers[selection].MakeSelection();
					PlantControllers[selection].PrintMenu();
				}
				else if (plantChoice == 'w' || plantChoice == 's')
				{
					// Move the player's selection and re-print the menu.
					PlantControllers[selection].MoveSelection(plantChoice);
					PlantControllers[selection].PrintMenu();
				}
				else
				{
					// Print an error for all unexpected inputs.
					MainView.PrintError("Please follow the instructions above.");
				}
				
			}
		}
		else if (choice == 'd')
		{
			// If the player wants to move onto the next day, update everything.
			MainController.Update();
		}
		else if ( choice == 'w' || choice   == 's')
		{
			// If the player wants to Move the selection, move them in their desired direction.
			MainController.MoveSelection(choice);
		}
		else
		{
			// Print an error for all unexpected inputs.
			MainView.PrintError("Please follow the instructions above.");

			// Pause so the player can read the message printed.
			system("Pause");

		}
	}
}

