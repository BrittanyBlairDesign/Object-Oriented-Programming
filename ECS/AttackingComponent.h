#pragma once
#include"Component.h"


class DefendingComponent;
class RPGCharacter;
class StatComponent;

// AttackingComponent base class.
class AttackingComponent : public Component {
public:
	// AttackingComponent Constructor takes in an RPGCharacter pointer.
	AttackingComponent(RPGCharacter* Character)
		: m_character(Character)
	{}

	virtual void Update() override {}

	// Attack Takes in a StatComponent pointer and a DefendingComponent.
	virtual void Attack(StatComponent* enemyStat, DefendingComponent* EnemyDefending) = 0;

protected:
	RPGCharacter* m_character;
	float m_multiplier = 0;
};

// WarriorAttack Class.
class WarriorAttack : public AttackingComponent
{
public:
	// Warrior Attack Constuctor.
	WarriorAttack(RPGCharacter* Character) : AttackingComponent(Character){}

	// Attack Takes in a StatComponent pointer and a DefendingComponent. Attacking Costs Stamina.
	void Attack(StatComponent* enemyStat, DefendingComponent* EnemyDefending) override;
};

// MageAttack Class
class MageAttack : public AttackingComponent
{
public:
	// Warrior Attack Constuctor.
	MageAttack(RPGCharacter* Character) : AttackingComponent(Character) {}

	// Attack Takes in a StatComponent pointer and a DefendingComponent. Attacking Costs Mana.
	void Attack(StatComponent* enemyStat, DefendingComponent* EnemyDefending) override;
};