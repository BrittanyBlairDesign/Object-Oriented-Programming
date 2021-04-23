#pragma once

class Player;
#include<iostream>
#include <utility>


enum class TileClass
{
	kBomb,
	KEnd,
	KFloor,
	KMimic,
	KTreasure
};

enum class TileStates
{
	KHidden,
	KRevealed,
	KExploded,
	KActive
};

class Tile
{
public:
	static Tile* CreateTile(TileClass Type);

	virtual void Draw()
	{
		m_TileStrategy->Draw(m_State);
	}

	virtual void OnEnter(Player* pPlayer) 
	{
		m_State = m_TileStrategy->OnEnter(pPlayer, m_State);
	}

	void SetState(TileStates newState)
	{
		m_State = newState;
	}
	 
private:

	//typedef std::pair<int, int> TileRange;
	//static const TileRange s_TileRange;

	struct TileStrategy
	{
		virtual void Draw(TileStates state) = 0;
		virtual TileStates OnEnter(Player* pPlayer, TileStates state)
		{
			return state;
		}
	};

	class Bombtile : public TileStrategy
	{
	public:
		void Draw(TileStates state) override;

		TileStates OnEnter(Player* pPlayer, TileStates state) override;
	};

	class EndTile : public TileStrategy
	{
	public:
		void Draw(TileStates state) override;

		TileStates OnEnter(Player* pPlayer, TileStates state) override;
	};

	class FloorTile : public TileStrategy
	{
	public:
		void Draw(TileStates state) override;
	};

	class TreasureTile : public TileStrategy
	{
	public:
		void Draw(TileStates state) override;

		TileStates OnEnter(Player* pPlayer, TileStates state) override;
	};


	Tile(TileStrategy* Strat , TileStates State) : m_TileStrategy(Strat), m_State(State) {}

	public:
	TileStrategy* m_TileStrategy;
	TileStates m_State;



};
