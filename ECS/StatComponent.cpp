#include "StatComponent.h"
#include "Stat.h"

void StatComponent::Update()
{
	m_health->Update();
	m_stamina->Update();
	m_mana->Update();
}

void StatComponent::ModifyHealth(float amount)
{
	m_health->Modify(amount);
}

void StatComponent::ModifyStamina(float amount)
{
	m_stamina->Modify(amount);
}

void StatComponent::ModifyMana(float amount)
{
	m_mana->Modify(amount);
}


float StatComponent::HealthValue()
{
	return m_health->Value();
}

float StatComponent::StaminaValue()
{
	return m_stamina->Value();
}

float StatComponent::ManaValue()
{
	return m_mana->Value();
}

void StatComponent::Display()const
{
			m_health->Display();
		m_stamina->Display();
		m_mana->Display();
}