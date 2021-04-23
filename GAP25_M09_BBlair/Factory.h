#pragma once
#include "Hork.h"
#include "Yumans.h"

struct Factory
{
	virtual Unit* CreateWarrior() = 0;
	virtual Unit* CreateMelee() = 0;
	virtual Unit* CreateRanged() = 0;
};

class YumanFactory : public Factory
{
public:
	YumanFactory() : Factory() {}

	Unit* CreateWarrior() override
	{
		return new YumanWorker;
	}

	Unit* CreateMelee() override
	{
		return new YumanMelee;
	}

	Unit* CreateRanged() override
	{
		return new YumanRanged;
	}

};

class HorkFactory : public Factory
{
public:
	HorkFactory() : Factory() {}

	Unit* CreateWarrior() override
	{
		return new HorkWorker;
	}

	Unit* CreateMelee() override
	{
		return new HorkMelee;
	}

	Unit* CreateRanged() override
	{
		return new HorkRanged;
	}

};

