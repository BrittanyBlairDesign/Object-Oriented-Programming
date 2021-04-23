#pragma once
#include "Component.h"
#include <string>

class RPGCharacter;

// Defending Component Class.
class DefendingComponent : public Component
{
public:
	// Defending Component Constructor, Takes in a float for the defence, and an RPG Character Refrence.
	DefendingComponent(float Defence,RPGCharacter& Character) 
		: m_Defence(Defence)
		, m_Character(Character)
	{}

	// Updates the Defending Component, Sets the m_defending bool to false.
	void Update() override
	{
		m_defending = false;
	}

	// Returns the Defence value.
	float GetDefence();

	// Sets Sets the Component To Defencing.
	void Defending()
	{
		m_defending = true;
	}

	// Changes the Damage a this player takes based off of weather or not the player is defending.
	float Damage(float amount);

	// Returns the character's name.
	std::string GetName();

protected:
	RPGCharacter&m_Character;
	float m_Defence;
	bool m_defending = false;
};

// Warrior Defend Class. 
class WarriorDefend : public DefendingComponent
{
public:
	// Warrior Constructor.
	WarriorDefend(float Defence, RPGCharacter& Character) : DefendingComponent(Defence, Character){}

	// When WarriorDefend updates it increases warrior stamina if defending.
	void Update() override;
};

// Mage Defend class.
class MageDefend : public DefendingComponent
{
public:
	// Mage Defend constructor.
	MageDefend(float Defence, RPGCharacter& Character) : DefendingComponent(Defence, Character) {}

	// When Mage Defend updates, if the character is defending, increase their mana.
	void Update() override;
};