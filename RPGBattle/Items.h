#pragma once
#include "RPG_Character.h"
//Items class 


// all kinds of potions 
enum class Potions
{
	kHealthPotion,
	KManaPotion,
	KDefault
};
// all kinds of rings
enum class Rings
{
	kAttack,
	KDefence,
	kDefault
};
// all kinds of weapons.
enum class Weapons
{
	kGreatSword,
	kGauntlets,
	kDefault
};


class Items
{
public:
	Items()
	{
		m_name = "default";
		m_value = 0;
	}
	// Item constructor takes in 3 parameters
	Items(std::string name, float val)
		:m_name(name)
		,m_value(val)
	{}
	
	//Destructor
	~Items(){}

	// Getters

	std::string GetName() const
	{
		return m_name;
	}

	float GetValue() const
	{
		return m_value;
	}

	//Useage

	void Use(Stat& stat)
	{
		stat.Modify(m_value);
	}


private:
	std::string m_name;
	float m_value;
};

class Potion : public Items
{
public:
	Potion() :Items(){}
	// Constructor for health potion takes in a const rpg character refrence.
	Potion(std::string name, float value, Potions Type): Items(name, value), m_type(Type){}
	
	// potion destructor

	~Potion() {}

	Potions GetType()
	{
		switch (m_type)
		{
		case Potions::kHealthPotion:
			return Potions::kHealthPotion;
			break;
		case Potions::KManaPotion:
			return Potions::KManaPotion;
			break;
		default:
			return Potions::KDefault;
			break;
		}
	}

private:
	Potions m_type = Potions::KDefault;
};

// Ring class
class Ring : public Items
{
public:
	Ring():Items(){}
	Ring(std::string name, float val, Rings type) : Items(name, val), m_type(type){}

private:
	Rings m_type = Rings::kDefault;
};


//weapon Class
class Weapon: public Items
{
public:
	Weapon() : Items(){}
	Weapon(std::string name, float val, Weapons type) : Items(name, val)
	{
		m_Type = type;
	}
private:
	Weapons m_Type = Weapons::kDefault;
};
