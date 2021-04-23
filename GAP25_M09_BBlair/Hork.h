#pragma once

#include "Character.h"

class HorkWorker : public Character
{
public:
	HorkWorker() : Character()
	{
		m_HP = 10;
		m_Name = "Peon";
		m_Behavior = "Gather resources or Build";
		m_GatherRate = 10;
		m_BuildRate = 20;
	}

private:
	int m_GatherRate;
	int m_BuildRate;
};


class HorkMelee: public Character
{
public:
	HorkMelee() :Character()
	{
		m_HP = 30;
		m_Name = "Chopper";
		m_Behavior = "Chop enemy with an ax";
		m_Attack = 20;
	}

private:
	int m_Attack;
};

class HorkRanged : public Character
{
public:
	HorkRanged() : Character()
	{
		m_HP = 20;
		m_Name = "Hammer Thrower";
		m_Behavior = "Throws Hammers at an enemy";
		m_Attack = 10;
		m_Range = 10;
	}

private:
	int m_Attack;
	int m_Range;
};