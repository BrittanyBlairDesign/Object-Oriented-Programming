#include "State.h"
#include "Player.h"
#include "World.h"

Tile* Tile::CreateTile(TileClass Type)
{
		switch (Type)
		{
		case TileClass::kBomb:
			return new Tile(new Bombtile(), TileStates::KActive);
			break;
		case TileClass::KEnd:
			return new Tile(new EndTile(), TileStates::KRevealed);
			break;
		case TileClass::KFloor:
			return new Tile(new FloorTile(), TileStates::KRevealed);
			break;
		case TileClass::KMimic:
			return new Tile(new Bombtile(), TileStates::KHidden);
			break;
		case TileClass::KTreasure:
			return new Tile(new TreasureTile(), TileStates::KHidden);
			break;
		default:
			return new Tile(new FloorTile(), TileStates::KRevealed);
			break;
		}
} 