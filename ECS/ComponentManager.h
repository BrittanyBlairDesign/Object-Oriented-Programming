#pragma once

#include <map>
#include <vector>

#include "Component.h"
#include "Entity.h"

typedef std::map<Entity, Component*> ComponentMap;

class ComponentManager {
public:
	template<typename T>
	const char* GetTypeKey() {
		return typeid(T).name();
	}

	template<typename T>
	void RegisterComponent() {
		m_components[GetTypeKey<T>()] = ComponentMap();
	}

	template<typename T>
	void AddComponent(Entity e, T* component) {
		const char* typeName = GetTypeKey<T>();
		ComponentMap& components = m_components[typeName];
		components[e] = component;
	}

	template<typename T>
	T* GetComponent(Entity e) {
		const char* typeName = GetTypeKey<T>();
		ComponentMap& components = m_components[typeName];
		if (components.find(e) == components.end()) {
			return nullptr;
		}
		return reinterpret_cast<T*>(components[e]);
	} 

	void Update() {
		for (auto componentMap : m_components) {
			for (auto component : componentMap.second) {
				component.second->Update();
			}
		}
	}

private:
	std::map<const char*, ComponentMap> m_components;
};