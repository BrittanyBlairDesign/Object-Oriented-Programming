#pragma once

#include <string>

#include "Component.h"

class NameComponent : public Component {
public:
	NameComponent(const std::string& name) : m_name(name) {}

	void Update() override {}

	const std::string& GetName() { return m_name; }
private:
	std::string m_name;
};