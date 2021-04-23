#pragma once

#include "Coord.h"
#include "Game.h"

// The value of a tic-tac-toe square.
enum class Value : char
{
	kEmpty = ' ',
	kCross = 'X',
	kCircle = 'O'
};

// A simple tic-tac-toe game where players take turns placing xs and os.
class TicTacToeGame: public GameInterface
{
public:
	TicTacToeGame();

	// Draws the tic-tac-toe board including current xs and os.
	void Draw() override;

	//Get the prompt for making a move
	std::string GetPrompt() override;

	// Makes a move on the given coordinate of the board.
	// Swaps back and forth between x and o.
	void OnMove(const Coord& coord) override;

	// Returns true if the game is still going, false if it is over.
	bool IsActive() override;

private:
	// Get the value of the board at coordinate (x,y).
	const Value GetValue(int x, int y);
	// Get the value of the board at the given coord.
	const Value GetValue(const Coord& coord);
	// Set the value of the board at coordinate (x,y) to the given Value.
	void SetValue(int x, int y, Value value);
	// Set the value of the board at the given coord to the given Value.
	void SetValue(const Coord& coord, Value value);

	static constexpr int kWidth = 3;
	static constexpr int kHeight = 3;

	Value m_values[kWidth][kHeight];
	int m_moveCount = 0;
	bool m_xo = true;
	bool m_gameOver = false;
};

