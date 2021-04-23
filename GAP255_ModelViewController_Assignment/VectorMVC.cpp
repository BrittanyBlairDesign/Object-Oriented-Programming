#include "Vector3Playground.h"
#include "Vector3.h"
#include "VectorView.h"
#include "VectorController.h"
#include <iostream>

template <typename T>
T* GetChosenT(T* a, T* b) {
	int Option = 0;
	std::cout << "Which Option do you want (1 " << a->toString() << ", 2 = " << b->toString() << " ):\n";
	std::cin >> Option;

	if (Option == 1) {
		return a;
	}
	else {
		return b;
	}
}

int main()
{
	// Creating all 3 Vectors.
	Vector3 FirstVector;
	FirstVector.SetX(0.0f);
	FirstVector.SetY(1.0f);
	FirstVector.SetZ(2.0f);

	Vector3 SecondVector;
	SecondVector.SetX(3.0f);
	SecondVector.SetY(4.0f);
	SecondVector.SetZ(5.0f);

	Vector3 ThirdVector;
	ThirdVector.SetX(6.0f);
	ThirdVector.SetY(7.0f);
	ThirdVector.SetZ(8.0f);

	// Create a Vector Playground and add Vectors to the Playground.
	Vector3Playground<100> *newPlayground = new Vector3Playground<100>();

	newPlayground->AddData(FirstVector);
	newPlayground->AddData(SecondVector);
	newPlayground->AddData(ThirdVector);

	// Choose your View.
	VectorView<Vector3Playground<100>>* View = GetChosenT<VectorView<Vector3Playground<100>>>(
		new HorizontalView<Vector3Playground<100>>,
		new VerticalView<Vector3Playground<100>>);
	
	// Choose Your Controller
	VectorController* Controller = GetChosenT<VectorController>(
		new CommandController<Vector3Playground<100>>(newPlayground, View),
		new SelectionController<Vector3Playground<100>>(newPlayground, View));
	
	//VectorController<Vector3Playground<100>> , VectorView<Vector3Playground<100>>>* 

	while (true)
	{
		int Selection = Controller->PrintOptions();

		if (Selection == 1)
		{
			// Add a vector.
			Controller->AddVector3();
			system("CLS");
		}
		if (Selection == 2)
		{
			// Modify a vector.
			std::cout << " Which Vector would you Like to Change? \n";
			View->PrintVector3(newPlayground);
			size_t vector;
			std::cin >> vector;

			Controller->ModifyVector3(vector);
			system("CLS");
		}
		if (Selection == 3)
		{
			// Delete a vector.
			std::cout << " Which Vector would you Like to delete? \n";
			View->PrintVector3(newPlayground);
			size_t vector;
			std::cin >> vector;

			Controller->DeleteVector3(vector);
			system("CLS");
		}
		if (Selection == 4)
		{
			// Print all vectors.
			system("CLS");
			View->PrintVector3(newPlayground);
		}

		
	}

	
}