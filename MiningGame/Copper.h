#pragma once

#include "Material.h"
#include "Interface.h"
class Copper :public Material, public Interface
{
public:
	Copper() :Material("Copper") {};

	void Update() override
	{
		Mine();
		Factory();
		Furnace();
		Statements();
	}

	void Statements() override
	{
		//Print Material name condition
		if (m_amount > 0)
		{
			std::cout << "Copper: " << m_amount;

			Material::Statements();
		}
	}
};