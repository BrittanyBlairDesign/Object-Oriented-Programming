#pragma once
#include "Unit.h"

class Character : public Unit
{
public:
	// Hork Constructor
	Character(){}
	
	// Returns the Hork name
	const std::string& GetUnitName() override
	{
		return m_Name;
	}

	// Returns the Hork HP
	int GetHP() override
	{
		return m_HP;
	}

	// Returns the Hork Behavior
	const std::string& GetBehavior() override
	{
		return m_Behavior;
	}

protected:
	int m_HP = 0;
	std::string m_Name = " " ;
	std::string m_Behavior = " ";
};

