#pragma once
#include<vector>
#include<iostream>
class Vector3;

// View Vector Interface, Contains pure Virtual Print functions for both vector classes
template<class Playground>
struct VectorView
{
	virtual void PrintVector3(Playground* Vector) = 0;
	virtual std::string toString() = 0;
	virtual void PrintError(std::string Message)
	{
		std::cout << Message << '\n';
	}
};

// Horizontal View Visualizes both kinds of vectors in a Horizontal pattern each on their own line.
template<class Playground>
class HorizontalView : public VectorView<Playground>
{
public:
	void PrintVector3(Playground* Vector) override
	{
		// Get the size of the current list of vectors.
		size_t size = Vector->GetDataCount();

		for (auto i = 0; i < size; ++i)
		{
			// Print out the X, Y, & Z Values of each vector Within the list.
			const Vector3* const currentVector = Vector->GetData(i);
			std::cout << i << ": " << currentVector->GetX() << ", " << currentVector->GetY() << ", " << currentVector->GetZ() << " \n";
		}

		std::cout<< std::endl;
	}

	std::string toString() override
	{
		return "Horizontal view";
	}
};

// Vertical view visualizes both kinds of vectors in a Vertical view, where each vectore is in its own column.
template<class Playground>
class VerticalView : public VectorView<Playground>
{
public:
	void PrintVector3(Playground* Vector) override
	{
		size_t size = Vector->GetDataCount();
	
		// Print the Index.
		std::cout << "Index:\t";
	
		for (auto k = 0; k < size; ++k)
		{
			std::cout << k << ' ';
		}
		std::cout << std::endl;
	
	
		// Print all X values.
		std::cout << "X: \t";
		for (auto i = 0; i < size; i++)
		{
			const Vector3* const currentVector = Vector->GetData(i);
			std::cout << currentVector->GetX() << ' ';
		}
		std::cout << '\n';
	
		// Print all Y values.
		std::cout << "Y: \t";
		for (auto i = 0; i < size; i++)
		{
			const Vector3* const currentVector = Vector->GetData(i);
			std::cout << currentVector->GetY() << ' ';
		}
		std::cout << '\n';
	
		// Print all Z values.
		std::cout << "Z: \t";
		for (auto i = 0; i < size; i++)
		{
			const Vector3* const currentVector = Vector->GetData(i);
			std::cout << currentVector->GetZ() << ' ';
		}
		std::cout << '\n';
	}

	std::string toString() override
	{
		return "Vertical view";
	}
};