#pragma once
#include "Entity.h"

class Player : public Entity {
	int treasures;
	int steps;
public:
	Player(int _x = 1, int _y = 1, int _hp = 1);
	int getTreasures();
	void addTreasure();
	int getSteps();
	void move(int _x, int _y);
};