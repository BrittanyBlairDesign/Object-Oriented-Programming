#pragma once
#include <vector>

// Forward Declarations for Controller classes.
class Plant;
class MainView;
class PlantView;

///////////////////////////////
///		CONTROLLER BASE
///////////////////////////////

// A class for all controller types to inherit from.
class Controller
{
public:
	// Updates the controller.
	virtual void Update() = 0;

	//Prints the controller's view pointer.
	virtual void PrintMenu() = 0;

	// Allows the player to move around the plant menu to decide what to do.
	virtual void MoveSelection(char move) = 0;

	// Lets the player make a selection and modify the plant's data.
	virtual void MakeSelection() = 0;

	// Returns the current menu's selection.
	int GetSelection() { return m_Selection; }

	// Returns a plant index.
	int GetIndex() { return m_Index; }

protected:
	 int m_Selection = 0;
	 int m_Index = 0;
};

///////////////////////////////
///		PLANT CONTROLLER
///////////////////////////////

// Plant controller handles the player interaction with each plant's menu.
class PlantController : public Controller
{
public:
	// Plant Controllers take in the plant they cokntrol as well as the view they are managing.
	PlantController(std::vector<Plant>& plants, PlantView* View, int Index) 
		: m_Plants(plants)
		, m_pPlantView(View)
	{
		m_Index = Index;
	}

	// Sets all controller bools back to Default false values when the day ends.
	void Update() override;

	void PrintMenu() override;

	void MoveSelection(char move) override;

	void MakeSelection() override;

	// Changes the plant's moisture based on player input.
	void WaterPlant();

	// Re-pots the plant.
	void RepotPlant();

	// Set Menu Bool to false.
	void Exit() { m_isInMenu = false; }
	
	// Return m_isInMenu bool
	bool isInMenu() { return m_isInMenu; }

private:
	std::vector<Plant> m_Plants;
	PlantView* m_pPlantView;
	bool m_isInMenu = true;
};
///////////////////////////////
///		MAIN CONTROLLER
///////////////////////////////

//The Main Controller does alot of the heavy lifting for the function of the game.
//It controls the main menu selections and opens all the other plant menus.
class MainController : public Controller
{
public:
	// The main menu needs the vector of plants, a vector of plant controllers, and a pointer to the main view.
	MainController(std::vector<Plant>& Plants, std::vector<PlantController>& PlantMenus, MainView* Main)
		: m_Plants(Plants)
		, m_PlantMenus(PlantMenus)
		, m_pMainMenu(Main)
	{}

	// Updates all Plants, Controllers, and the main view.
	void Update() override;

	void PrintMenu() override;

	void MoveSelection(char move) override;

	void MakeSelection() override;

private:
	std::vector<Plant>& m_Plants;
	std::vector<PlantController>& m_PlantMenus;
	MainView* m_pMainMenu;
};



