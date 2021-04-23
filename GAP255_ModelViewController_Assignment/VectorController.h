#pragma once
#include <iostream>
#include <conio.h>
#include "Vector3Playground.h"
#include "VectorView.h"
class Vector3;

// Interface for all controllers to Inherit from.
struct VectorController
{
	// Prints All player options
	virtual int PrintOptions() = 0;
	virtual void AddVector3() = 0;
	virtual void ModifyVector3(size_t index) = 0;
	virtual void DeleteVector3(size_t index) = 0;
	virtual std::string toString() = 0;
};

// Command Controller Class that operates with basic commands and no selection highlights.
template<class Playground>
class CommandController : public VectorController
{
public:
	CommandController(Playground* playground, VectorView<Playground>* view)
		: m_pPlayground(playground), m_pView(view) {}

	int PrintOptions() override
	{
		std::cout << "1. Add a Vector3\n";
		std::cout << "2. Modify a Vector3\n";
		std::cout << "3. Delete a Vector3\n";
		std::cout << "4. Print Vectors\n";

		int choice;
		std::cin >> choice;

		return choice;
	}

	std::string toString() override
	{
		return "Command Controller";
	}
	void AddVector3() override
	{
		if (m_pPlayground->GetDataCount() >= 100)
		{
			m_pView->PrintError(" Vector is at Maximum Capacity, Please Delete a Vector before adding a new one.");
		}
		else
		{

			float x, y, z;

			std::cout << "type in a float for the following values\n";
			std::cout << " X = \n";
			std::cin >> x;

			std::cout << "Y = \n";
			std::cin >> y;

			std::cout << "Z = \n";
			std::cin >> z;

			// Creates a new Vector3.
			Vector3 newVector;
			newVector.SetX(x);
			newVector.SetY(y);
			newVector.SetZ(z);

			// Adds the new Vector3 To the Playground.
			m_pPlayground->AddData(newVector);
		}
	}

	void ModifyVector3(size_t index) override
	{
		// Make sure that the player's selection is within the range of vectors that exist.
		if (index > m_pPlayground->GetDataCount() || index < 0)
		{
			m_pView->PrintError("I'm sorry, please select an existing vector.");
		}
		else
		{
			float x, y, z;

			// Coppy Vector at index.
			Vector3 newVector;
			const Vector3* oldVector = m_pPlayground->GetData(index);

			newVector.SetX(oldVector->GetX());
			newVector.SetY(oldVector->GetY());
			newVector.SetZ(oldVector->GetZ());

			int choice;
			std::cout << " Which Value would You like to change? ( 1. X value , 2. Y Value , 3. Z value , 4. All values)\n";
			std::cin >> choice;

			if (choice == 1)
			{
				std::cout << "type in a float for the following value\n";
				std::cout << " X = \n";
				std::cin >> x;

				// Set the X value.
				newVector.SetX(x);
			}
			if (choice == 2)
			{
				std::cout << "type in a float for the following value\n";
				std::cout << " Y = \n";
				std::cin >> y;

				// Set the y value.
				newVector.SetY(y);
			}
			if (choice == 3)
			{
				std::cout << "type in a float for the following value\n";
				std::cout << " Z = \n";
				std::cin >> z;

				// Set the z value.
				newVector.SetZ(z);
			}
			if (choice == 4)
			{
				// Gather X Y Z values.
				std::cout << "type in a float for the following values\n";
				std::cout << " X = \n";
				std::cin >> x;

				std::cout << "Y = \n";
				std::cin >> y;

				std::cout << "Z = \n";
				std::cin >> z;

				// Set the new X Y Z values.
				newVector.SetX(x);
				newVector.SetY(y);
				newVector.SetZ(z);
			}

			// replaces the old Vector information with the new Vector3 information.
			m_pPlayground->ModifyData(index, newVector);
		}
	}

	void DeleteVector3(size_t index) override
	{
		// Checks to make sure player selection is within the Vector playground range.
		if (index > m_pPlayground->GetDataCount() || index < 0)
		{
			m_pView->PrintError("I'm sorry, please choose an existing vector.");
		}
		else
		{
			// Takes the given index and removes the vector at that index.
			m_pPlayground->RemoveData(index);
		}
	}

private:
	Playground* m_pPlayground;
	VectorView<Playground>* m_pView;
};

// Since Selection controller is Identical to Command controller other than the Print function. It is inheriting Commandcontroller.
// This way, if i wanted to make a different controller with the view interface i could.
template<class Playground>
class SelectionController : public CommandController<Playground>
{
public:
	SelectionController(Playground* playground, VectorView<Playground>* view) : CommandController<Playground>(playground, view) {}
	int PrintOptions() override
	{
		// Create a MultiDimensional array of Strings.
		std::string menu[4][2]
		{
			{"  ", "1. Add a Vector3 \n"},
			{"  ", "2. Modify a Vector3\n"},
			{"  ", "3. Delete a Vector3\n"},
			{"  ", "4. Print Vectors\n"}
		};
		
		// selection coordinates for the array.
		int x = 0, y = 0;

		// Loop that will print the array and move the player's arrow.
		bool Choosing = true;
		while (Choosing)
		{
			// Print the Instructions.

			std::cout << "Use W to move up, and S to move down. Press [ Space ] to make your selection.\n" << std::endl;
			menu[x][y] = "->";
			// Print the Array.
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					std::cout << menu[i][j];
				}
			}
			menu[x][y] = "  ";
			// Get the player's movement.
			char Movement;
			Movement = _getch();

			if (Movement == 'W' || Movement == 'w')
			{
				// Only move up if x will be greater than or equal to zero.
				if (x - 1 >= 0)
				{
					--x;

				}
			}
			if (Movement == 'S' || Movement == 's')
			{
				// Only move down if x will be less than or equal to 3.
				if (x + 1 <= 3)
				{
					++x;

				}
			}
			else if (Movement == ' ')
			{
				Choosing = false;
			}

			system("CLS");
		}

		// Returns a number for the menu option that the player wants to do.
		switch (x)
		{
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 3;
			break;
		case 3:
			return 4;
			break;
		}
	}
};