#pragma once
#include <iostream>
#include <string>

// Plant Base Class.
// Contains all the basic information for each plant in the game.
class Plant
{
private:

	// Plant Stragety Base class is an interface for all other strategies.
	// Determines how the plant behaves, based off of the Current plant status.
	class PlantState
	{
	public:
		// PlantState needs a name for the constructor.
		PlantState(std::string name) : m_name(name) {}

		// Updates the plant based on the state the plant is currently in.
		virtual void Update(Plant* plant) = 0;

		// Prints the name of the state that the plant is currently in.
		std::string Print() { return m_name; }

		// Prints out a short description about the plant's state, and a hint on how to take care of it.
		virtual void PrintDescription() = 0;

	private:
		std::string m_name;
	};

	/////////////////////////////////////////////////////
	///					STRATEGIES					  ///
	/////////////////////////////////////////////////////

	// How a healty plant behaves.
	class Healthy : public PlantState
	{
	public:
		Healthy() : PlantState("Healthy") {}

		// A healthy plant will grow 10% each turn, and reduce the moisture by 10%.
		void Update(Plant* plant) override;

		// Prints that the plant is happy.
		void PrintDescription() override;
	};

	// How a dry plant behaves.
	class Dry : public PlantState
	{
	public:
		Dry() : PlantState("Dry") {}

		// A dry plant will not grow as much as a healthy plant and has a moistrue of 10% or lower. 
		// Dry plants reduce current moisture by 50% each turn.
		// ( 10 -> 5 -> 2.5 -> etc) Once it reaches 1% or lower the plant is then dieing.
		void Update(Plant* plant) override;

		// Prints that the plant is too "dry", and may need water.
		void PrintDescription() override;
	};

	// How a rotting plant behaves.
	class Rotting : public PlantState
	{
	public:
		Rotting() : PlantState("Rotting") {}

		// A Rotting plant is way over watered, so every turn it will only grow by 5% each turn.
		// Moisture will reduce by 5% each turn, untill it is normal or re-potted.
		void Update(Plant* plant) override;

		// Prints that the plant is "rotting", and doesn't need any more water.
		void PrintDescription() override;
	};

	// How a wilting plant behaves.
	class Wilting : public PlantState
	{
	public:
		Wilting() : PlantState("Wilting") {}

		// A wilting plant is too big for its pot.
		// It will not grow, and will reduce the plant moisture by 15% each turn.
		void Update(Plant* plant) override;

		// Prints that the plant is "wilting", and might need more room to grow.
		void PrintDescription() override;
	};

	// How a dieing plant behaves.
	class Dieing : public PlantState
	{
	public:
		Dieing() : PlantState("Dieing") {}

		// A dieing plant is in critical condition. Has a moisture level of 0 or less.
		// It will not grow, and will reduce the plant size by 30% each turn.
		// A dieing plant has 2 turns to fix things before it dies for good.
		void Update(Plant* plant) override;

		// Prints that the plant is "dieing", and needs water now!
		void PrintDescription() override;

	private:
		int m_turnCouter = 0;
	};

	// How a dead plant behaves.
	class Dead : public PlantState
	{
	public:
		Dead() : PlantState("Dead") {}

		// A Dead Plant does nothing in the update phase and cannot be saved.
		void Update(Plant* plant) override;

		// Prints that the plant is "dead", and there's nothing you can do for it now.
		void PrintDescription() override;
	};

	// How a fully grown plant behaves.
	class FullGrown : public PlantState
	{
	public:
		FullGrown() : PlantState("Fully Grown") {}

		// A fully grown plant does nothing at the update phase.
		// TODO: If time allows print a picture of a plant.
		void Update(Plant* plant) override;

		// Prints that the plant is "fully grown", and doesn't need any more help.
		void PrintDescription() override;
	};

public:
	// Plant Constructor Takes in a String for the plant name and a float for the pant's ideal Moisture level, and one for the plant's growth rate.
	Plant(std::string name, double IdealMoisture)
		: m_Name(name)
		, m_IdealMoisture(IdealMoisture)
	{
		// All plants start off Healthy.
		m_pPlantState = new Healthy;

		// All plants start off with the ideal moisture levels.
		m_Moisture = m_IdealMoisture;
	}

	// Updates the plant and determines the plant's current state.
	void Update();

	/////////////////////////////////////////////////////
	///						GETTERS					  ///
	/////////////////////////////////////////////////////

	// Return the plant's name.
	std::string GetName()
	{
		return m_Name;
	}

	// Print's the plant's state description.
	void Description();

	// Return the plant's current mositure level.
	double GetMositure()
	{
		return m_Moisture;
	}

	// Return the plant's current growth level.
	double GetGrowth()
	{
		return m_Growth;
	}

	// Return the plant's current pot size.
	size_t PotSize()
	{
		return m_PotSize;
	}

	// prints the plant's current state name.
	std::string GetStateName()
	{
		return m_pPlantState->Print();
	}

	// Returns weather its been watered or not
	bool IsWatered() 
	{
		if (m_isWatered)
		{
			std::cout << m_Name << " has been Watered already.";
			system("Pause");
		}
		return m_isWatered;
	}

	// Returns weather its been re-Potted or not.
	bool IsRePotted() 
	{ 
		if (m_isRePotted)
		{
			std::cout << m_Name << " has been re-potted already.";
			system("Pause");
		}
		return m_isRePotted;
	}

	/////////////////////////////////////////////////////
	///						 SETTERS				  ///
	/////////////////////////////////////////////////////

	// Changes plant moisture by the amount given.
	void ChangeMoisture(double water);

	// Changes the plant's growth by the amount given.
	void ChangeGrowth(double growth);

	// Re-pots the plant so it can grow larger.
	void RePot();

	// Changes the state of the plant.
	void ChangeState(PlantState* state);

	// Change m_isWatered bool to true
	void Watered() { m_isWatered = true; }

	// Change m_isRePotted bool to true
	void RePotted() { m_isRePotted = true; }

private:
	PlantState* m_pPlantState;

	std::string m_Name;
	double m_IdealMoisture;
	double m_Moisture = 0;
	double m_Growth = 10;
	size_t m_PotSize = 1;
	size_t m_MaxPotSize = 4;

	bool m_isWatered = false;
	bool m_isRePotted = false;

};
