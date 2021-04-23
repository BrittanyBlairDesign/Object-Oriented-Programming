// ECS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "ComponentManager.h"
#include "Entity.h"
#include "NameComponent.h"
#include "PhysicsComponent.h"
#include "DefendingComponent.h"
#include "AttackingComponent.h"
#include "StatComponent.h"
#include "Stat.h"
#include "RPGCharacter.h"

int main()
{
    std::cout << "Hello World!\n";

    // Create the component manager.
    ComponentManager cm;

    // Register Components.
    cm.RegisterComponent<NameComponent>();
    cm.RegisterComponent<StatComponent>();
    cm.RegisterComponent<DefendingComponent>();
    cm.RegisterComponent<AttackingComponent>();

    // Create the Warrior entity and add all Warrior components.
    Entity Warrior = CreateEntity();
    cm.AddComponent<NameComponent>(Warrior, new NameComponent(std::string("Warrior")));
    cm.AddComponent<StatComponent>(Warrior, new StatComponent(new Health(100), new Stamina(10), new Mana(0)));
    RPGCharacter WarriorCharacter(cm.GetComponent<StatComponent>(Warrior), cm.GetComponent<NameComponent>(Warrior));
    cm.AddComponent<DefendingComponent>(Warrior, new WarriorDefend(5, WarriorCharacter));
    cm.AddComponent<AttackingComponent>(Warrior, new WarriorAttack(&WarriorCharacter));
    
    // Create the Mage entity and all the Mage components.
    Entity Mage = CreateEntity();
    cm.AddComponent<NameComponent>(Mage, new NameComponent(std::string("Mage")));
    cm.AddComponent<StatComponent>(Mage, new StatComponent(new Health(100), new Stamina(10), new Mana(200)));
    RPGCharacter MageCharacter(cm.GetComponent<StatComponent>(Mage), cm.GetComponent<NameComponent>(Mage));
    cm.AddComponent<DefendingComponent>(Mage, new MageDefend(10, MageCharacter));
    cm.AddComponent<AttackingComponent>(Mage, new MageAttack(&MageCharacter)); 

    // While Both characters are alive, play the game loop.
    while (WarriorCharacter.RPGUpdate() && MageCharacter.RPGUpdate()) 
    {
        // Update the Component Manager.
        cm.Update();

        // Update and display Warrior.
        WarriorCharacter.RPGUpdate();
        WarriorCharacter.Display();

        // Update and display Mage.
        MageCharacter.RPGUpdate();
        MageCharacter.Display();

        // Print instructions for the player.
        std::cout << "Enter command: ";

        std::string command;
        std::getline(std::cin, command);

        // Get the player's decision.
        if (command == "attack") 
        {
            // Attack the Warrior.
            cm.GetComponent<AttackingComponent>(Mage)->Attack(cm.GetComponent<StatComponent>(Warrior), cm.GetComponent<DefendingComponent>(Warrior));
        }
        else if (command == "block") 
        {
            // Block the Warrior.
            cm.GetComponent<DefendingComponent>(Mage)->Defending();
        }
        // Warrior Attacks Mage.
        cm.GetComponent<AttackingComponent>(Warrior)->Attack(cm.GetComponent<StatComponent>(Mage), cm.GetComponent<DefendingComponent>(Mage));
    }
}
