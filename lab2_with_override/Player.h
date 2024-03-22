#pragma once


class Player {
	int x;
	int y;
public:
	Player(int _x=0, int _y=0);

	int getX();
	int getY();

	void move(int _x, int _y);
};