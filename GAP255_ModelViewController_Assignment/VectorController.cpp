#include <iostream>
#include "Vector3Playground.h"
#include "VectorView.h"
class Vector3;

// Interface for all controllers to Inherit from.
template<class Playground , class View>
struct Controller
{
	Controller(){}
	// Prints All player options
	virtual void PrintOptions() = 0;
	virtual void AddVector3() = 0;
	virtual void ModifyVector3() = 0;
	virtual void DeleteVector3() = 0;

};

// Command Controller Class that operates with basic commands and no selection highlights.
template<class Playground, class View>
class CommandController : public Controller<Playground, View>
{
public:
	CommandController(Playground* playground, View* view) : m_pPlayground(playground), m_pView(view){}

	void PrintOptions() override
	{
		std::cout << "1. Add a Vector3\n";
		std::cout << "2. Modify a Vector3\n";
		std::cout << "3. Delete a Vector3\n";
		std::cout << "4. Print Vectors\n";

		char choice;
		std::cin >> choice;
		
		if (choice == 1)
		{
			void AddVector3();
		}
		if (Choice == 2)
		{
			std::cout << " Which Vector would you Like to Change? \n";
			view->PrintVector3(m_pPlayground);
			size_t vector;
			std::cin >> vector;

			ModifyVector3(vector);
		}
		if (Choice == 3)
		{
			std::cout << " Which Vector would you Like to delete? \n";
			view->PrintVector3(m_pPlayground);
			size_t vector;
			std::cin >> vector;

			DeleteVector3(vector);
		}
		if (choice == 4)
		{
			view->PrintVector3(m_pPlayground);
		}
	}

	void AddVector3() override
	{
		float x, y, z;

		std::cout << "type in a float for the following values\n";
		std::cout << " X = \n";
		std::cin >> x;

		std::cout << "Y = \n";
		std::cin >> y;

		std::cout << "Z = \n";
		std::cin >> y;

		// Creates a new Vector3.
		Vector3 newVector;
		newVector.SetX(x);
		newVector.SetY(y);
		newVector.SetZ(z);

		// Adds the new Vector3 To the Playground.
		m_pPlayground->AddData(newVector);
	}

	void ModifyVector3() override
	{
		float x, y, z;

		// Coppy Vector at index.
		Vector3 newVector = m_pPlayground->getData(index);

		char Choice;
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
			std::cin >> y;

			// Set the new X Y Z values.
			newVector.SetX(x);
			newVector.SetY(y);
			newVector.SetZ(z);
		}

		// replaces the old Vector information with the new Vector3 information.
		m_pPlayground->ModifyData(index, newVector);

	}

	void DeleteVector3() override
	{
		// Takes the given index and removes the vector at that index.
		m_pPlayground->RemovaData(index);
	}

private:
	Playground* m_pPlayground;
	View* m_pView;
};