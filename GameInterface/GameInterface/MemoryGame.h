#pragma once

#include "Coord.h"
#include "Game.h"

// Representation of a memory game card.
struct Card
{
	// True if the card is face up.
	bool shown = false;
	// The symbol on the card face.
	char symbol;
};

// A simple memory game where you flip pairs of cards and try to match them.
class MemoryGame: public GameInterface
{

public:
	MemoryGame();
	~MemoryGame();

	// Draws the memory game board.
	void Draw() override;

	//Get the prompt for making a move
	std::string GetPrompt() override;

	// Handles a player move on the given coordinate of the board.
	void OnMove(const Coord& move) override;

	// Returns true if the game is still going, false if it is over.
	bool IsActive() override;

private:
	// Randomize the order of the cards.
	void ShuffleCards();
	// Flip all cards back to face-down state.
	void FlipAllCards();

	static constexpr int kWidth = 4;
	static constexpr int kHeight = 3;
	static constexpr int kNumCards = kWidth * kHeight;
	static constexpr char kSymbols[kNumCards / 2]{ '!', '@', '#', '$', '%', '&' };
	static constexpr char kSymbolNone = '0';

	Card** m_ppCards;
	char m_lastCard;
	char m_currentCard;
};

