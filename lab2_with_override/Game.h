#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Room.h"
#include "Player.h"

#include "Monster.h"
#include "Xmonster.h"

#include "IObserver.h"

class Game {
	int roomsCount;
	int roomNow;
	Player& player;
	Room* rooms;
	int visionRad;
	
	vector<IObserver*> observers;
	void event();
public:
	Game(Player& player);
	//void addPlayer(Player& player);
	Game(const Game& _game);
	
	Player& getPlayer();
	Room getRoom();
	int getVisionRad();

	void addObserver(IObserver* o);

	//void loadMaze(string file);
	
	void move(Action act);
	void changeRoom(int roomId);
	Game& operator = (const Game& game);
	friend ostream& operator <<(ostream& out, const Game& game);
	friend istream& operator >> (istream& in, Game& game);

	~Game();
};