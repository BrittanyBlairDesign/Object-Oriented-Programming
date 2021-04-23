#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "controller.h"
// Forward declarations.
class Plant;


// Interface for all view classes to be based off of.
class View
{
public:
	// Returns view type.
	virtual std::string toString() = 0;

	// Display takes in a plant vector.
	virtual void Display(std::vector<Plant>& plants, Controller* controller ){}

	// Prints whatever error has happened.
	void PrintError(std::string message)
	{
		std::cout << message << std::endl;
	}

protected:
	std::string m_Arrow = "--> ";
	std::string m_Empty = "    ";
};

// The main menu view
class MainView : public View
{
public:
	std::string toString() override
	{
		return "Main Menu";
	}

	void Display(std::vector<Plant>& plants, Controller* controller) override;

	// Increase the current day.
	void ChangeDay() { ++m_Day; }

private:
	size_t m_Day = 1;
};

// The plant menu view
class PlantView : public View
{
public:
	std::string toString() override
	{
		return "Plant Menu";
	}

	void Display(std::vector<Plant>& plants, Controller* controller) override;

private:
	std::string m_Options[3]{ "Water","Re-pot", "Exit to main menu." };
};