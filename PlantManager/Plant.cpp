#include "Plant.h"
#include <iostream>

///////////////////////////////////////////
///				PLANT	
///////////////////////////////////////////
void Plant::ChangeMoisture(double water)
{
	m_Moisture = m_Moisture + water;
}

void Plant::ChangeGrowth(double amount)
{
	m_Growth = m_Growth + amount;

	if (m_Growth > 100)
	{
		m_Growth = 100;
	}
}

void Plant::RePot()
{
	// Only increase the pot size if its not the same as the max size.
	if (m_PotSize < m_MaxPotSize)
	{
		// Repot the plant if it has grown enough to warrent a new pot.
		if (m_Growth > 30 &&m_PotSize < 2)
		{
			++m_PotSize;
			m_Moisture = m_IdealMoisture;
		}
		else if (m_Growth > 60 && m_PotSize < 3)
		{
			++m_PotSize;
			m_Moisture = m_IdealMoisture;
		}
		else if (m_Growth > 90 && m_PotSize < 4)
		{
			++m_PotSize;
			m_Moisture = m_IdealMoisture;
		}	
		else
		{
			std::cout << "This " << m_Name << " isn't quite large enough to get re-potted yet.\n";

			// Pause so the player can read the text that pops up.
			system("PAUSE");
		}
	}	
	else
	{
		std::cout << "This " << m_Name << " is already at the maximum pot size.\n";

		// Pause so the player can read the text that pops up.
		system("PAUSE");
	}
}

void Plant::Description()
{
	m_pPlantState->PrintDescription();
}

void Plant::ChangeState(PlantState* state)
{
	m_pPlantState = state;
}

void Plant::Update()
{
	// Update the strategy so the plant's stats are up to date when it changes states.
	m_pPlantState->Update(this);

	// Use plant information to decide what the plant's state is currently.
	if (m_Moisture < m_IdealMoisture - 30 && m_Moisture > 0)
	{
		// Change state to dry.
		ChangeState(new Dry);
	}
	else if (m_Moisture > m_IdealMoisture + 30 && m_Moisture < 100)
	{
		// Change the state to rotting.
		ChangeState(new Rotting);
	}
	else if (m_Moisture <= 0)
	{
		// Plant is close to death.
		ChangeState(new Dieing);
	}
	else if ((m_PotSize * 30) < m_Growth)
	{
		// Plant is wilting.
		ChangeState(new Wilting);
	}
	else if (m_Growth >= 100) 
	{
		// Plant is fully grown.
		ChangeState(new FullGrown);
	}
	else
	{
		// Plant is healthy if it is nothing else.
		ChangeState(new Healthy);
	} 

	m_isWatered = false;
	m_isRePotted = false;
}

///////////////////////////////////////////
///			HEALTHY STRAT	
///////////////////////////////////////////

void Plant::Healthy::Update(Plant* plant)
{
	// Percentage in which we are changing things.
	double percentage = 0.1;

	// Get ten percent of current moisture.
	double moisture = plant->GetMositure() * percentage;

	// Decrease plant moisture by that amount.
	plant->ChangeMoisture(-moisture);

	// Get percent of current growth.
	double GrowthPercent = 0.3;
	double Growth = plant->GetGrowth() * GrowthPercent;
	plant->ChangeGrowth(Growth);
}

void Plant::Healthy::PrintDescription()
{
	std::cout << "Perfectly Healthy";
}


///////////////////////////////////////////
///			DRY STRAT
///////////////////////////////////////////

void Plant::Dry::Update(Plant* plant)
{
	// Percentage in wich we are changing things.
	double percentage = .5;
	
	// Get the fifty percent of current moisture levels.
	double moisture = plant->GetMositure() * percentage;

	// If the decimal is a small number just subtract 5 every turn instead.
	if (moisture < 5)
	{
		moisture = 5.0;
	}

	// Decrease moisture by 50%.
	plant->ChangeMoisture(-moisture);

	// Get percent of current growth.
	double Growth = plant->GetGrowth() * .15;
	plant->ChangeGrowth(Growth);
}

void Plant::Dry::PrintDescription()
{
	std::cout << "Could really use some water.";
}

///////////////////////////////////////////
///			ROTTING STRAT	
///////////////////////////////////////////

void Plant::Rotting::Update(Plant* plant)
{
	// Percentage in which we are changing things.
	double percentage = .05f;

	// Find out what 5% of the moisture of the plant is.
	double moisture = plant->GetMositure() * percentage;

	// Decrease the moisture by  5%.
	plant->ChangeMoisture(-moisture);

}

void Plant::Rotting::PrintDescription()
{
	std::cout << "The soil is over flowing with water.";
}

///////////////////////////////////////////
///			WILTING STRAT
///////////////////////////////////////////

void Plant::Wilting::Update(Plant* plant)
{
	// Percentage in which we are changing things.
	double percentage = .15f;

	// Find out what 15% of the moisture of the plant is.
	double moisture = plant->GetMositure() * percentage;

	// Decrease the moisture by  15%
	plant->ChangeMoisture(-moisture);
}

void Plant::Wilting::PrintDescription()
{
	std::cout << "This plant's leaves are turning yellow. It might need more space.";
}

///////////////////////////////////////////
///			DIEING STRAT	
///////////////////////////////////////////

void Plant::Dieing::Update(Plant* plant)
{
	if (m_turnCouter < 2)
	{
		// Percentage in which we are changing things.
		double percentage = .3f;

		// Find out what 30% of the size of the plant is.
		double plantSize = plant->GetGrowth() * percentage;

		// Decrease the plant's size by  30%.
		plant->ChangeMoisture(-plantSize);
	}
	else
	{
		plant->ChangeState(new Dead);
	}

}

void Plant::Dieing::PrintDescription()
{
	std::cout << "This plant is very close to death. It needs attention now!";
}

///////////////////////////////////////////
///			DEAD STRAT	
///////////////////////////////////////////

void Plant::Dead::Update(Plant* plant)
{
	//Dead plants do not update.
}

void Plant::Dead::PrintDescription()
{
	std::cout << "Unfortunately, this plant has died.";
}

///////////////////////////////////////////
///			FULL GROWN STRAT	
///////////////////////////////////////////

void Plant::FullGrown::Update(Plant* plant)
{
	// Full grown plants do not update.
}

void Plant::FullGrown::PrintDescription()
{
	std::cout << "This plant is fully grown and no longer needs your attention.";
}