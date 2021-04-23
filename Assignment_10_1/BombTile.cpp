// BombTile.cpp
#include <iostream>
#include "State.h"
#include "Player.h"

void Tile::Bombtile::Draw(TileStates state)
{
	switch (state)
	{
	case TileStates::KHidden:
		std::cout << '$';
		break;
	case TileStates::KRevealed:
		std::cout << '*';
		break;
	case TileStates::KExploded:
		std::cout << '#';
		break;
	case TileStates::KActive:
		std::cout << '*';
		break;
	default:
		break;
	}
}

TileStates Tile::Bombtile::OnEnter(Player* pPlayer, TileStates state)
{
	if (state == TileStates::KActive || state == TileStates::KHidden)
	{
		int damage = (rand() % 5); //(s_damageRange.second - s_damageRange.first)) + s_damageRange.first;
		pPlayer->Damage(damage);
		return TileStates::KExploded;
	}
	else
	{
		return state;
	}
}