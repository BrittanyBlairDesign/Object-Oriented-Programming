#include "RPGCharacter.h"
#include "StatComponent.h"
#include "NameComponent.h"


bool RPGCharacter::RPGUpdate()
{
	// If the character's health is less than 0, the game is over.
	if (m_Stats->HealthValue() <= 0) {
		std::cout << GetName() << " is dead!";
		return false;
	}

	// If the character is alive update stats.
	m_Stats->Update();

	return true;
}


std::string RPGCharacter::GetName()
{
	// Return the name component's name.
	return m_name->GetName();
}


void RPGCharacter::Display() {
	// Print name, and stats.
	std::cout << GetName() << ": \n";
	std::cout << "   ";
	m_Stats->Display();
}