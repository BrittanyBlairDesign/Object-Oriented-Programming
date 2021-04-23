#pragma once

#include "Component.h"
#include "Vector3.h"

class PhysicsComponent : public Component {
public:
	PhysicsComponent(Vector3 position, float mass)
      : m_position(position), m_velocity(0, 0, 0), m_mass(mass) {}

	void AddVelocity(const Vector3& v) {
		m_velocity = m_velocity + v;
	}

	void Update() override {
		m_position = m_position + m_velocity;
	}

	const Vector3& GetPosition() { return m_position; }
private:
	Vector3 m_position;
	Vector3 m_velocity;
	float m_mass;
};