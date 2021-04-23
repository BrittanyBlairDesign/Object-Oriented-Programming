#pragma once

/*
	Unit Interface
	Britany Blair
*/
#include <string>

struct Unit
{
public:

	// Returns the Class's Name
	virtual const std::string& GetUnitName() = 0;
	
	// Returns the class's Health
	virtual int GetHP() = 0;

	// Returns the Class's Behavior
	virtual const std::string& GetBehavior() = 0;

};

class UnitFactory
{
public:
	static Unit* CreateUnit(int Type, int kind);
};