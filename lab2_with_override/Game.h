#pragma once

#include <iostream>
#include <fstream>

#include "Cell.h"
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
	Cell** maze;
public:
	Game(Player& player);
	//void addPlayer(Player& player);
	void loadMaze(string file);
	void move(Action act);
	friend ostream& operator <<(ostream& out, const Game& game);
	~Game();
};