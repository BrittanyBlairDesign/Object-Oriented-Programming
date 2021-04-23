#pragma once
#include "Component.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>

// Represents any numerical statistic with current/maximum value and regeneration.
class Stat {
public:
	Stat(const std::string& name, float max, float regen)
		: m_name(name), m_value(max), m_max(max), m_regen(regen) {}

	// Updates the stat by adding regen amount to value.
	void Update() {
		Modify(m_regen);
	}

	// Modifies the value by the given amount (can be negative).
	void Modify(float amount) {
		m_value = std::clamp(m_value + amount, 0.f, m_max);
	}

	// Gets the current value of the stat.
	float Value() { return m_value; }

	// Prints the stat using std::cout.
	void Display() const {
		std::cout << m_name << ": " << m_value << "\n";
	}

private:
	std::string m_name;
	float m_value;
	float m_max;
	float m_regen;
};

// Represents a character's health.
class Health : public Stat {
public:
	Health(float max) : Stat("health", max, 1) {}
};

// Represents a character's stamina.
class Stamina : public Stat {
public:
	Stamina(float max) : Stat("stamina", max, 2) {}
};

// Represents a character's mana.
class Mana : public Stat {
public:
	Mana(float max) : Stat("mana", max, 0) {}
};