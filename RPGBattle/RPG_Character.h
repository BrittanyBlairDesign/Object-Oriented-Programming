#pragma once

#include "Stat.h"
#include <stdlib.h>
#include <time.h>
#include "Items.h"

// Represents a character from a role-playing game.
class RPGCharacter {
public:
	// Creates a new RPGCharacter with the given name, health, stamina, and mana.
	RPGCharacter(std::string name, Health health, Stamina stamina, Mana mana)
		: m_name(name)
		, m_health(health)
		, m_stamina(stamina)
		, m_mana(mana)
		, m_block(0) 
	{}

	// Attacks the given target. "Pure-virtual" function, i.e. must be overridden by subclasses.
	virtual void Attack(RPGCharacter& target) = 0;

	// Updates the character's statistics.
	virtual bool Update() {
		if (m_health.Value() <= 0) {
			std::cout << m_name << " is dead!";
			return false;
		}

		m_health.Update();
		m_stamina.Update();
		m_mana.Update();
		m_block = 0;

		// m_item.Update()?

		return true;

	}

	// Makes the character take the given amount of damage.
	virtual void Damage(float amount) {
		if (m_block > 0) {
			std::cout << m_name << " blocked " << m_block << " damage.\n";
		}
		// Modify amount using m_item?
		amount -= std::min(m_block, amount);
		m_block -= amount;

		m_health.Modify(-amount);
	}

	// Prints the character's statistics using std::cout.
	void Display() {
		std::cout << m_name << ": \n";
		std::cout << "   ";
		m_health.Display();
		std::cout << "   ";
		m_stamina.Display();
		std::cout << "   ";
		m_mana.Display();
	}

	// Gets the character's name.
	std::string Name() { return m_name; }

protected:
	std::string m_name;
	Health m_health;
	Stamina m_stamina;
	Mana m_mana;
	float m_block;

};