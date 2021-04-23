/*
	Brittany Blair
	GAP 255 - Assignment 2
	Maze Game
*/

#include <iostream>
#include "Grid.h"

int main()
{
	Grid level1(10, 10);
	while (level1.Playing()) 
	{
		system("CLS");
		level1.DrawGrid();
		char input;
		std::cin >> input;
		level1.PlayerMove(input);
	}

}