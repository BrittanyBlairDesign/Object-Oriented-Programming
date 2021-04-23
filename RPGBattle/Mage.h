#pragma once
#include "RPG_Character.h"
#include "Items.h"
// Mage class
class Mage : public RPGCharacter {
public:
	Mage() : RPGCharacter("mage", Health(50), Stamina(10), Mana(200) ) 
	{
		m_potion = Potion("Default", 0, Potions::KDefault);
		m_ring = Ring("Default", 0, Rings::kDefault);
	}

	void Attack(RPGCharacter& target) override {
		// target loses random amount of health from 0-10;
		// use stamina
		// use mana
		float manaCost = 50;
		if (m_mana.Value() < manaCost) {
			std::cout << "Not enough mana to attack!\n";
			return;
		}
		m_mana.Modify(-manaCost);
		float damage = rand() % 10;
		std::cout << m_name << " casts fireball at " << target.Name() << " for " << damage << " damage!\n";
		target.Damage(damage);
	}

	void Block() {
		m_block = 5;
		m_mana.Modify(25);
	}

	void SetPotion(Potions Type)
	{
		switch (Type)
		{
		case Potions::kHealthPotion:
			m_potion = Potion("Health Potion", 25, Potions::kHealthPotion);
			break;
		case Potions::KManaPotion:
			m_potion = Potion("Mana Potion", 25, Potions::KManaPotion);
			break;
		default:
			m_potion = Potion("Default", 0, Potions::KDefault);
			break;
		}
	}

	void SetRing(Rings Type)
	{
		switch (Type)
		{
		case Rings::kAttack:
			m_ring = Ring("Attack Ring", 3, Rings::kAttack);
			break;
		case Rings::KDefence:
			m_ring = Ring("Defence Ring", 4, Rings::KDefence);
			break;
		default:
			m_ring = Ring("Default", 0, Rings::kDefault);
			break;
		}
	}

	void UsePotion()
	{
		switch (m_potion.GetType())
		{
		case Potions::kHealthPotion:
			m_potion.Use(m_health);
			m_potion.~Potion();
			break;
		case Potions::KManaPotion:
			m_potion.Use(m_mana);
			m_potion.~Potion();
			break;
		default:
			break;
		}
	}
protected:
	Potion m_potion;
	Ring m_ring;
};

// Dark magician steals part of their opponents Health when they attack.
// Dark magicians also have one Mana Potion and a ring to increase their attack by 2.
class DarkMagician : public Mage
{
public:
	DarkMagician() : Mage() 
	{
		SetPotion(Potions::KManaPotion);
		SetRing(Rings::kAttack);
	}

	void Attack(RPGCharacter& target) override
	{
		float manaCost = 50;
		if (m_mana.Value() < manaCost) {
			std::cout << "Not enough mana to attack!\n";
			return;
		}
		m_mana.Modify(-manaCost);
		float damage = rand() % 10;

		damage = damage + m_ring.GetValue();

		std::cout << m_name << " casts fireball at " << target.Name() << " for " << damage << " damage!\n";
		target.Damage(damage);
		
		damage = damage / 2;
		m_health.Modify(damage);
	}
};

//Light mage has a holy defence that slowly gets stronger over time.
//Light mages have One Health potion to use and a ring to increase their initial defence;
class LightMage : public Mage
{
public:
	LightMage(float Defence):m_defence(Defence), Mage()
	{
		SetPotion(Potions::KManaPotion);
		SetRing(Rings::KDefence);
	}

	void Damage(float amount) override
	{
		amount = amount - m_defence;
		amount = amount - m_ring.GetValue();
		RPGCharacter::Damage(amount);

		if (m_defence > 10) 
		{
			++m_defence;
		}
	}
private:
	float m_defence;
};