#pragma once

#include "Character.h"



class YumanWorker : public Character
{
public:
	YumanWorker() : Character()
	{
		m_HP = 10;
		m_Name = "Farmer";
		m_Behavior = "Gather resources or Build";
		m_GatherRate = 20;
		m_BuildRate = 10;
	}

private:
	int m_GatherRate;
	int m_BuildRate;
};


class YumanMelee : public Character
{
public:
	YumanMelee() :Character()
	{
		m_HP = 40;
		m_Name = "Slicer";
		m_Behavior = "Slice enemy with a sword";
		m_Attack = 15;
	}

private:
	int m_Attack;
};

class YumanRanged : public Character
{
public:
	YumanRanged() : Character()
	{
		m_HP = 20;
		m_Name = "Shooter";
		m_Behavior = "Fire arrows at an enemy";
		m_Attack = 8;
		m_Range = 15;
	}

private:
	int m_Attack;
	int m_Range;
};