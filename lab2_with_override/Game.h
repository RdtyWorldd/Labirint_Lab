#pragma once

#include <iostream>
#include <fstream>

#include "Cell.h"
#include "Wall.h"
#include "Treasure.h"
#include "SCell.h"
#include "Player.h"

enum Action {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Game {
	int high, wide;
	Player& player;
	SCell** maze;
	//Cell** * maze;
public:
	Game(Player& player);
	//void addPlayer(Player& player);
	Game(const Game& _game);
	int getHigh() const;
	int getWide() const;
	//void loadMaze(string file);
	void move(Action act);
	
	Game& operator = (const Game& game);
	friend ostream& operator <<(ostream& out, const Game& game);
	friend istream& operator >> (istream& in, Game& game);

	~Game();
};

ostream& operator <<(ostream& out, const Cell* cell);
//istream& operator >>(istream& in, Cell** cell);