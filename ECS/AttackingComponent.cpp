#include "AttackingComponent.h"
#include "RPGCharacter.h"
#include "StatComponent.h"
#include "DefendingComponent.h"
#include <Math.h>

// TODO: Cant get all the stats to update properly. Damage is taken, but stamina is not decreasing when attacking?
// EDIT: Mage now reduces Mana, Warrior Still not reducing stamina.

void WarriorAttack::Attack(StatComponent* enemyStat, DefendingComponent* EnemyDefending)
{
	// Get Warrior current stats.
	StatComponent* currentStats = m_character->GetStats();

	// If the Warrior has enough Stamina, he can attack otherwise turn ends.
	float staminaCost = 5;
	if (currentStats->StaminaValue() < staminaCost) {
		std::cout << ": not enough stamina to attack!\n";

		return;
	}

	// Reduce the mana cost from current mana.
	currentStats->ModifyStamina(-staminaCost);

	// Get the random damage to deal to the opponent.
	float damage = (rand() % 10);

	// Save the Stats
	m_character->SaveStats(currentStats);

	// Get the Damage based off of weather the enemy is Defending or not.
	damage = EnemyDefending->Damage(damage);

	// Announce the damage to the opposing character.
	std::cout << m_character->GetName() << " attacks " << EnemyDefending->GetName() << " for " << damage << " damage!\n";
	enemyStat->ModifyHealth(-damage);
}

void MageAttack::Attack(StatComponent* enemyStat, DefendingComponent* EnemyDefending)
{
	// Get the Mage's Current Stats.
	StatComponent* currentStats = m_character->GetStats();

	// IF the mana cost of the attack is more than the mana the character has, end the attack phase.
	float ManaCost = 20;
	if (currentStats->ManaValue() < ManaCost) {
		std::cout << ": not enough stamina to attack!\n";

		return;
	}
	// Reduce the mana cost from current mana.
	currentStats->ModifyMana(-ManaCost);

	// Get the random damage to deal to the opponent.
	float damage = (rand() % 10);

	// Save Mage's Current Stats.
	m_character->SaveStats(currentStats);

	// Get the Damage based off of weather the enemy is Defending or not.
	damage = EnemyDefending->Damage(damage);

	// Announce the damage to the opposing character.
	std::cout << m_character->GetName() << " attacks " << EnemyDefending->GetName() << " for " << damage << " damage!\n";
	enemyStat->ModifyHealth(-damage);
}