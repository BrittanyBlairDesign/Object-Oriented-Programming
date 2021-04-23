// TreasureTile.cpp
#include "State.h"
#include "Player.h"
#include <iostream>


void Tile::TreasureTile::Draw(TileStates state)
{
	switch (state)
	{
	case TileStates::KHidden:
		std::cout << '$';
		break;
	case TileStates::KRevealed:
		std::cout << '.';
		break;
	default:
		break;
	}
}

TileStates Tile::TreasureTile::OnEnter(Player* pPlayer, TileStates state)
{
	if (state == TileStates::KHidden)
	{
		int Gold = (rand() % 50); //(s_TreasureRange.second - s_TreasureRange.first)) + s_TreasureRange.first;
		pPlayer->AddGold(Gold);
		return TileStates::KRevealed;
	}
	else
	{
		return state;
	}
}
