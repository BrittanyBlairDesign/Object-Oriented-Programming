#pragma once
#include <string>

class GameInterface
{
public:
	//Draws the game board
	virtual void Draw()=0;

	//Get the prompt for making a move.
	virtual std::string GetPrompt() = 0;

	// Handles a player move on the given coordinates of the board.
	virtual void OnMove(const Coord& move) =0;

	//Returns true if the game is still goin, false if the game is over.
	virtual bool IsActive() = 0;

};