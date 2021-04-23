#pragma once
/*
	Brittany Blair
	grid header file 
*/
#include <iostream>
#include "Tile.h"

class Grid
{
private:
	int m_rows = 0;				// rows
	int m_columns = 0;			// columns
	Tile m_empty;			// Empty tiles look like
	Tile m_player;
	Tile m_wall;
	Tile m_exit;
	bool m_playing = true;
	char m_grid[15][15]
	{
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
	};
public:
	//constructor that takes in 2 ints
	Grid(int columns, int rows) : m_rows(rows+2), m_columns(columns)
	{

		//set up player symbol and start position
		m_player.SetContent('@');
		m_player.SetPosition(0, 1);
		m_grid[m_player.GetxPosition()][m_player.GetyPosition()] = m_player.GetContent();

		//set up exit symbol and position
		m_exit.SetContent('X');
		m_exit.SetPosition(m_columns-1, m_rows-2);
		m_grid[m_exit.GetxPosition()][m_exit.GetyPosition()] = m_exit.GetContent();

		//set up walls
		m_wall.SetContent('#');
		m_grid[0][2] = m_wall.GetContent();
		m_grid[1][2] = m_wall.GetContent();
		m_grid[2][2] = m_wall.GetContent();
		m_grid[2][4] = m_wall.GetContent();
		m_grid[2][5] = m_wall.GetContent();
		m_grid[2][7] = m_wall.GetContent();
		m_grid[3][2] = m_wall.GetContent();
		m_grid[3][4] = m_wall.GetContent();
		m_grid[3][5] = m_wall.GetContent();		
		m_grid[3][7] = m_wall.GetContent();
		m_grid[3][8] = m_wall.GetContent();
		m_grid[3][9] = m_wall.GetContent();
		m_grid[4][4] = m_wall.GetContent();
		m_grid[4][9] = m_wall.GetContent();
		m_grid[4][7] = m_wall.GetContent();
		m_grid[5][1] = m_wall.GetContent();
		m_grid[5][2] = m_wall.GetContent();
		m_grid[5][3] = m_wall.GetContent();
		m_grid[5][4] = m_wall.GetContent();
		m_grid[5][6] = m_wall.GetContent();
		m_grid[6][6] = m_wall.GetContent();
		m_grid[7][2] = m_wall.GetContent();
		m_grid[7][3] = m_wall.GetContent();
		m_grid[7][4] = m_wall.GetContent();
		m_grid[7][5] = m_wall.GetContent();
		m_grid[7][6] = m_wall.GetContent();
		m_grid[7][7] = m_wall.GetContent();
		m_grid[7][8] = m_wall.GetContent();
		m_grid[7][9] = m_wall.GetContent();
		m_grid[7][10] = m_wall.GetContent();

	

		// empty tiles
		m_empty.SetContent('.');

		// empty space and side walls
		for (int i = 0; i < m_columns + 2; ++i)
		{
			for (int j = 0; j < m_rows+2; ++j)
			{
				if (m_grid[i][j] == ' ')
				{
					if (j == 0)
					{
						m_grid[i][j] = m_wall.GetContent();
					}
					else
					{
						m_grid[i][j] = m_empty.GetContent();
					}
	
					if (j == rows + 1)
					{
						m_grid[i][j] = m_wall.GetContent();
					}
				}
			}
		}
	}
	//Add walls
	void AddWalls(int row, int column)
	{
		if (m_grid[row][column] == m_empty.GetContent()) 
		{
			m_grid[row][column] = m_wall.GetContent();
		}
	}
	//Changes any tile on the map into a new one.
	void ChangeTile(int row, int column, Tile newtile)
	{
		m_grid[row][column] = newtile.GetContent();
	}
	//renders the grid
	void DrawGrid()
	{
		for (int i = 0; i < m_columns+2; ++i)
		{
			m_wall.Print();
			std::cout <<' ';
		}
		std::cout << std::endl;
		for (int i = 0; i < m_columns; i++) {
			for (int j = 0; j < m_rows; j++) {
				std:: cout << m_grid[i][j] << ' ';
			}
			std::cout << '\n';
		}
		for (int i = 0; i < m_columns+2; ++i)
		{
			m_wall.Print();
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
	// takes a character input and moves the player
	void PlayerMove(char direction)
	{
		int x = m_player.GetyPosition();
		int y = m_player.GetxPosition();

		switch (direction)
		{
		case'w':
			if (y - 1 >= 0) 
			{
				y = y - 1;
				break;
			}
		case 's':
			if(y + 1 <= m_columns+2)
			{
				y = y + 1;
				break;
			}
		case 'd':
			if (x + 1 < m_rows + 2)
			{
				x = x + 1;
				break;
			}
		case 'a':
			if (x - 1 > 0)
			{
				x = x - 1;
				break;
			}
		case'q':
			exit(1);
		default:
			break;
		}

		if (m_grid[y][x] == m_empty.GetContent())
		{
			m_grid[m_player.GetxPosition()][m_player.GetyPosition()] = m_empty.GetContent();
			m_grid[y][x] = m_player.GetContent();
			m_player.SetPosition(y,x);
		}

		if(m_grid[y][x] == 'X')
		{
			m_playing = false;
		}
	}
	// did the player reach the exit?? returns bool
	bool Playing()
	{
		return m_playing;
	}
};