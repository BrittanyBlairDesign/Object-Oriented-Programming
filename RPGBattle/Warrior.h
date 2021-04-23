#pragma once
#include "RPG_Character.h"

// A fighter that uses stamina to attack.
class Warrior : public RPGCharacter {
public:
	Warrior(std::string name = "warrior") : RPGCharacter(name, Health(100), Stamina(10), Mana(0)) 
	{
		m_weapon = Weapon();
	}

	void Attack(RPGCharacter& target) override {
		float staminaCost = 4;
		if (m_stamina.Value() < staminaCost) {
			std::cout << m_name << ": not enough stamina to attack!\n";
			return;
		}
		m_stamina.Modify(-staminaCost);
		float damage = (rand() % 10) * m_attackMultiplier;
		std::cout << m_name << " attacks " << target.Name() << " for " << damage << " damage!\n";
		target.Damage(damage);
	}

	void Block() {
		m_block = 5;
		m_mana.Modify(25);
	}

	void SetWeapon(Weapons type)
	{
		switch (type)
		{
		case Weapons::kGreatSword:
			m_weapon = Weapon("Great Sword", 10, type);
			break;
		case Weapons::kGauntlets:
			m_weapon = Weapon("Iorn Gauntlets", 5, type);
			break;
		default:
			break;
		}
		
	}
protected:
	// A multiplier that is used when calculating damage.
	float m_attackMultiplier = 1;
	Weapon m_weapon;
	bool m_usingWeapon = false;
};

// A Warrior who goes berzerk when they take enough damage.
class Berzerker : public Warrior {
public:
	Berzerker() : Warrior("berzerker"), m_rage(0) {}

	void Attack(RPGCharacter& target) override {
		if (m_rage > 20) {
			m_attackMultiplier += 1 + rand() % 5;
			std::cout << m_name << " goes BERZERK for " << m_attackMultiplier << "x Damage!\n";
			m_rage = 0;
		}
		Warrior::Attack(target);
		m_attackMultiplier = 1;
	}

	void Damage(float amount) override {
		RPGCharacter::Damage(amount);

		m_rage += amount;
	}

private:
	// The current rage level of the berzerker (at 20 they deal tons of damage!)
	float m_rage;
};

//Knights have high defence but over time their defence lowers meaning that they need to end battles quickly.
//Knights use a Great Sword that does a set amount of damage every time they attack.
class Knight : public Warrior
{
public:
	Knight() : Warrior("Knight")
	{
		SetWeapon(Weapons::kGreatSword);
	}

	void Attack(RPGCharacter& target) override
	{
		float staminaCost = 4;
		if (m_stamina.Value() < staminaCost) {
			std::cout << m_name << ": not enough stamina to attack!\n";
			return;
		}
		m_stamina.Modify(-staminaCost);
		float damage = m_weapon.GetValue() * m_attackMultiplier;
		std::cout << m_name << " attacks " << target.Name() << " for " << damage << " damage!\n";
		target.Damage(damage);
	}

	// Take less damage but every time they get hit, their defence decreases.
	void Damage(float amount) override
	{
		amount = amount - m_defence;
		RPGCharacter::Damage(amount);
	}

	bool Update() override
	{
		if (m_health.Value() <= 0) {
			std::cout << m_name << " is dead!";
			return false;
		}

		m_health.Update();
		m_stamina.Update();
		m_mana.Update();
		m_block = 0;
		--m_defence;
		// m_item.Update()?

		return true;



	}
private:
	float m_defence = 10;
};

// close range fighter has a higher attack damage and a lower defence. but they also increase attack damage
// Also has a 25% chance at getting a critical hit that does 2x the damage.
// Because he fights with his fists he also takes a small amount of damage for every hit he lands.

class Fighter : public Warrior
{
public:
	Fighter() : Warrior("Fighter"){}

	void Attack(RPGCharacter& Target) override
	{
		int random = rand() % 4;
		if (random == 3)
		{
			m_attackMultiplier = 2;
			std::cout << "Critical HIT!" << '\n';
		}
		else
		{
			m_attackMultiplier = 1;
		}

		Warrior::Attack(Target);

		Damage(0);
	}

	void Damage(float amount) override
	{
		amount = amount + m_vulnerability;
		RPGCharacter::Damage(amount);
	}
private:
	float m_vulnerability = 2;
};
