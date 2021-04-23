#include "Hork.h"
#include "Yumans.h"

Unit* UnitFactory::CreateUnit(int Type, int kind)
{
	if (Type == 1)
	{
		if (kind == 1)
		{
			return new HorkWorker;
		}
		if (kind == 2)
		{
			return new HorkMelee;
		}
		if (kind == 3)
		{
			return new HorkRanged;
		}
	}
	else
	{
		if (kind == 1)
		{
			return new YumanWorker;
		}
		if (kind == 2)
		{
			return new YumanMelee;
		}
		if (kind == 3)
		{
			return new YumanRanged;
		}
	}
}