#include"DefendingComponent.h"
#include "NameComponent.h"
#include "RPGCharacter.h"
#include <iostream>
#include "StatComponent.h"

float DefendingComponent::GetDefence()
{
	// If the character is defending return the defence. otherwise their defence is 0.
	if (m_defending)
	{
		return m_Defence;
	}
	else
	{
		return 0;
	}
}

float DefendingComponent::Damage(float amount)
{
	// If the character is defending. State that they are blocking and reduce damage taken.
	if (m_defending)
	{
		std::cout << m_Character.GetName() << " blocked " << m_Defence << " damage.\n";

		amount -= std::min(m_Defence, amount);
		m_Defence -= amount;
	}
	// return the amount of damage the character will take.
	return amount;
}

std::string DefendingComponent::GetName()
{
	// Return the name of the character.
	return m_Character.GetName();
}

void WarriorDefend::Update()
{
	// If the character is defending, get their stats and increase the stamina by 2.
	if (m_defending)
	{
		StatComponent* stats = m_Character.GetStats();

		stats->ModifyStamina(2);

		// Set bool to false.
		m_defending = false;
	}
}

void MageDefend::Update()
{
	// If the character is defending, get their stats and increase their mana.
	if (m_defending)
	{
		StatComponent* stats = m_Character.GetStats();

		stats->ModifyMana(25);

		m_defending = false;
	}
}
