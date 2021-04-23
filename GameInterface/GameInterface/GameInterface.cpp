#include "MemoryGame.h"
#include "TicTacToeGame.h"

#include <iostream>
#include <time.h>

// NOTE: PlayMemoryGame(MemoryGame& game) and PlayTicTacToeGame(TicTacToeGame& game) should
// be combined into one method, PlayGame(Game& game), where Game is your new interface.


//Takes in a GameInterface refrence and Runs the main game loop game.
void RunGame(GameInterface& game) {
	while (game.IsActive()) {
		game.Draw();
		std::cout << game.GetPrompt();
		Coord move;
		std::cin >> move.x;
		std::cin >> move.y;
		game.OnMove(move);
	}
	std::cout << "Game Over!";
	while (true) {}
}

int main()
{
	srand((unsigned)time(nullptr));

	std::cout << "Choose a game: (1) Memory or (2) Tic-Tac-Toe. ";
	int choice;
	std::cin >> choice;

	if (choice == 1)
	{
		MemoryGame game;
		RunGame(game);
	}
	else
	{
		TicTacToeGame game;
		RunGame(game);
	}

	
	return 0;
}