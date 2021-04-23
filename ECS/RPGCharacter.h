#pragma once
#include <iostream>

class StatComponent;
class NameComponent;

// RPGCharacter Class contains the name and stats of a character.
class RPGCharacter
{
public:
	// Creates a new RPGCharacter with the given name, health, stamina, and mana.
	RPGCharacter(StatComponent* Stats , NameComponent* name)
	: m_Stats(Stats)
	, m_name(name)
	{}

	// Updates the character's statistics.
	bool RPGUpdate();
	
	// Returns a pointer to the character's stats.
	StatComponent* GetStats()
	{
		return m_Stats;
	}

	// Saves the new stats to the player's stat component.
	void SaveStats(StatComponent* stats)
	{
		m_Stats = stats;
	}

	// Returns the Name of the character.
	std::string GetName();

	// Prints the character's statistics using std::cout.
	void Display();

private:
	NameComponent* m_name;
	StatComponent* m_Stats;
};