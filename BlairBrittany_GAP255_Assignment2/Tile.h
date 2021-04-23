#pragma once
#include "Grid.h"

class Tile
{
private:
	char m_content = ' ';
	int m_x = 0, m_y = 0;
public:
	//defalut constructor
	Tile(){}
	//returns the tiles content
	char GetContent()
	{
		return m_content;
	}
	//Returns the Column position
	int GetxPosition()
	{
		return m_x;
	}
	//Returns the Row position
	int GetyPosition()
	{
		return m_y;
	}
	//Sets the tile's row and column positions.
	void SetPosition(int column, int row)
	{
		m_x = column;
		m_y = row;
	}
	// set tile character
	void SetContent(char content)
	{
		m_content = content;
	}
	//Prints tile
	void Print()
	{
		std::cout << m_content;
	}
};


