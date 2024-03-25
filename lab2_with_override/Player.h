#pragma once


class Player {
	int x;
	int y;
	int treasures;
public:
	Player(int _x=0, int _y=0);

	int getX();
	int getY();
	int getTreasures();

	void addTreasure();
	void move(int _x, int _y);
};