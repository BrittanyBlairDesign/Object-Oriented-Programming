#include "TicTacToeGame.h"

#include <iostream>

TicTacToeGame::TicTacToeGame()
{
	for (int x = 0; x < kWidth; x++)
	{
        for (int y = 0; y < kHeight; y++)
        {
            SetValue(x, y, Value::kEmpty);
        }
	}
}

/////////////////////////////////////////////
// Draws the board in its current state.
/////////////////////////////////////////////
void TicTacToeGame::Draw()
{
	for (int y = kHeight - 1; y >= 0; --y)
	{
		for (int x = 0; x < kWidth; ++x)
		{
			std::cout << (char)GetValue(x, y);

			// Add vertical lines between columns
			if (x < kWidth - 1)
			{
				std::cout << "|";
			}
		}

		std::cout << std::endl;

		// Add horizontal lines between rows
		if (y > 0)
		{
			// The actual renderered width of the board matches this formula:
			constexpr int kDrawnWidth = kWidth * 2 - 1;
			for (int i = 0; i < kDrawnWidth; ++i)
			{
				std::cout << "-";
			}

			std::cout << std::endl;
		}
	}
}

/////////////////////////////////////////////
// Prints Prompt for User to make a move
/////////////////////////////////////////////

std::string TicTacToeGame::GetPrompt()
{
    std::string prompt = "Enter coordinates of move ([0-2], [0-2]): \n";

    return prompt;
}

/////////////////////////////////////////////
// Process all user input here.
/////////////////////////////////////////////
void TicTacToeGame::OnMove(const Coord& coord)
{
	if (GetValue(coord) != Value::kEmpty) {
        std::cout << "Invalid move!";
		return;
	}
    Value kind = m_xo ? Value::kCross : Value::kCircle;
	SetValue(coord, kind);
    m_moveCount++;

    //Check end conditions.

    // Check the row of the last move.
    for (int x = 0; x < kWidth; x++) {
        if (GetValue(x, coord.y) != kind)
            break;
        if (x == kWidth - 1) {
            m_gameOver = true;
        }
    }

    // Check the column of the last move
    for (int y = 0; y < kHeight; y++) {
        if (GetValue(coord.x, y) != kind)
            break;
        if (y == kHeight - 1) {
            m_gameOver = true;
        }
    }

    // Check diagonals.
    if (coord.x == coord.y) {
        // Move is on diagonal.
        for (int i = 0; i < kWidth; i++) {
            if (GetValue(i, i) != kind)
                break;
            if (i == kWidth - 1) {
                m_gameOver = true;
            }
        }
    }

    // Check anti-diagonal.
    if (coord.x + coord.y == kWidth - 1) {
        for (int i = 0; i < kWidth; i++) {
            if (GetValue(i, kHeight - 1 - i) != kind)
                break;
            if (i == kWidth - 1) {
                m_gameOver = true;
            }
        }
    }

    //check draw
    if (m_moveCount == kWidth * kHeight) {
        m_gameOver = true;
    }

    m_xo = !m_xo;
}

/////////////////////////////////////////////
// Returns whether the game is still in
// progress.
/////////////////////////////////////////////
bool TicTacToeGame::IsActive()
{
	return !m_gameOver;
}

const Value TicTacToeGame::GetValue(int x, int y) {
    return m_values[x][y];
}

const Value TicTacToeGame::GetValue(const Coord& coord) {
	return GetValue(coord.x, coord.y);
}

void TicTacToeGame::SetValue(int x, int y, Value value) {
    m_values[x][y] = value;
}

void TicTacToeGame::SetValue(const Coord& coord, Value value) {
    SetValue(coord.x, coord.y, value);
}


