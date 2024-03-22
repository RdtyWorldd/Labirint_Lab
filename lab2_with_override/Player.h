#pragma once


class Player {
	int x;
	int y;
public:
	Player(int _x, int _y);
	
	int getX();
	void setX(int _x);

	int getY();
	void setY(int _y);
};