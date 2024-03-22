#pragma once


class Player {
	int x;
	int y;
public:
	Player(int _x=0, int _y=0);
	
	int getX();
	void setX(int _x);

	int getY();
	void setY(int _y);
};