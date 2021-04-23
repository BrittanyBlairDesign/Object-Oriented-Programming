#pragma once
#include "Component.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>

class Health;
class Stamina;
class Mana;

// Contains and manages all RPG Character Stats.
class StatComponent : public Component
{
public:
	// Stat Constructor, Takes in a Health pointer, Stamina pointer, and a mana pointer.
	StatComponent(Health* health, Stamina* stamina, Mana* mana)
		: m_health(health)
		, m_stamina(stamina)
		, m_mana(mana)
	{}

	// Updates all stats inside of the stat component.
	void Update();

	//////////////////////////////////////////////
	/// Modifiers, Modify the values of the Stats.
	//////////////////////////////////////////////
	void ModifyHealth(float amount);

	void ModifyStamina(float amount);

	void ModifyMana(float amount);

	//////////////////////////////////////////////
	/// Returns the Values of the Stats.
	//////////////////////////////////////////////
	float HealthValue();

	float StaminaValue();

	float ManaValue();

	void Display() const;

protected:
	Health* m_health;
	Stamina* m_stamina;
	Mana* m_mana;

};

