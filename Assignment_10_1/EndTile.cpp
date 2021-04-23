// EndTile.cpp
#include <iostream>
#include "State.h"
#include "Player.h"
#include "World.h"


extern World* g_pWorld;  // let's us access a global variable declared in another CPP

void Tile::EndTile::Draw(TileStates state)
{
	std::cout << "H";
}

TileStates Tile::EndTile::OnEnter(Player* pPlayer, TileStates state)
{
	g_pWorld->EndGame();
	return state;
}