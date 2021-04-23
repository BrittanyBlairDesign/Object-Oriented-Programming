#include "MemoryGame.h"

#include <iostream>

MemoryGame::MemoryGame()
	: m_ppCards{new Card*[kNumCards]}, m_lastCard(kSymbolNone), m_currentCard(kSymbolNone)
{
	for (int i = 0; i < kNumCards; ++i)
	{
		// We change symbol every two cards.
		char symbol = kSymbols[i / 2];
		m_ppCards[i] = new Card{ false, symbol };
	}

	ShuffleCards();

}

MemoryGame::~MemoryGame()
{
	for (int i = 0; i < kNumCards; ++i)
	{
		delete m_ppCards[i];
	}
	delete[] m_ppCards;
}

/////////////////////////////////////////////
// Draws the board in its current state.
/////////////////////////////////////////////
void MemoryGame::Draw()
{
	int cardIndex = 0;
	for (int y = 0; y < kHeight; ++y)
	{
		// tops of cards
		for (int x = 0; x < kWidth; ++x)
		{
			std::cout << "--- ";
		}
		std::cout <<  std::endl;

		// middles of cards
		for (int x = 0; x < kWidth; ++x)
		{
			std::cout << '|';

			Card* pCard = m_ppCards[cardIndex];
			if (pCard->shown)
			{
				std::cout << pCard->symbol;
			}
			else
			{
				std::cout << ' ';
			}

			std::cout << "| ";

			++cardIndex;
		}
		std::cout << std::endl;

		// bottoms of cards
		for (int x = 0; x < kWidth; ++x)
		{
			std::cout << "--- ";
		}
		std::cout << std::endl;

		// empty space
		for (int x = 0; x < kWidth; ++x)
		{
			std::cout << "    ";
		}
		std::cout << std::endl;
	}
}

/////////////////////////////////////////////
// Prints Prompt for User to make a move
/////////////////////////////////////////////

std::string MemoryGame::GetPrompt()
{
	std::string prompt ="Enter coordinates of tile to flip ([0-3], [0-2]): \n";

	return prompt;
}

/////////////////////////////////////////////
// Process all user input here.
/////////////////////////////////////////////
void MemoryGame::OnMove(const Coord& coord)
{
	if (m_currentCard != kSymbolNone && m_lastCard != m_currentCard) {
		m_lastCard = kSymbolNone;
		m_currentCard = kSymbolNone;
		FlipAllCards();
	}

	int index = (kHeight - 1 - coord.y) * kWidth + coord.x;
	m_ppCards[index]->shown = true;
	char symbol = m_ppCards[index]->symbol;
	if (m_lastCard == kSymbolNone) {
		m_lastCard = symbol;
	}
	else if (m_currentCard == kSymbolNone) {
		m_currentCard = symbol;
	}
}

/////////////////////////////////////////////
// Returns whether the game is still in
// progress.
/////////////////////////////////////////////
bool MemoryGame::IsActive()
{
	return m_currentCard == kSymbolNone || m_lastCard != m_currentCard;
}

/////////////////////////////////////////////
// Shuffles the cards.
/////////////////////////////////////////////
void MemoryGame::ShuffleCards()
{
	// Simple Fisher-Yates shuffle
	// We swap each card with some other randomly picked card.
	for (int i = 0; i < kNumCards; ++i)
	{
		// Pick another random card
		// As i increases, we will exclude cards we already swapped
		int randomIndex = i + rand() % (kNumCards - i);

		// Do a simple swap of the two card pointers
		Card* pTemp = m_ppCards[i];
		m_ppCards[i] = m_ppCards[randomIndex];
		m_ppCards[randomIndex] = pTemp;
	}
}

void MemoryGame::FlipAllCards() {
	for (int i = 0; i < kNumCards; i++)
	{
		m_ppCards[i]->shown = false;
	}
}