#pragma once

#include <iostream>
#include <fstream>

#include "Room.h"
#include "Player.h"

enum Action {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Game {
	int roomsCount;
	int roomNow;
	Player& player;
	Room* rooms;
public:
	Game(Player& player);
	//void addPlayer(Player& player);
	Game(const Game& _game);

	//void loadMaze(string file);
	void move(Action act);
	void changeRoom(int roomId);
	Game& operator = (const Game& game);
	friend ostream& operator <<(ostream& out, const Game& game);
	friend istream& operator >> (istream& in, Game& game);

	~Game();
};