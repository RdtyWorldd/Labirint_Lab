#pragma once
#include <iostream>
#include "Player.h"

using namespace std;

class Cell {
	bool filled;
	bool hero;
public:
	Cell();
	bool isHero();
	void setHero(bool _hero);
	bool isFilled();
	void setFilled();

	Cell operator +(const Player& player);
	Cell operator -(const Player& player);

	friend ostream & operator << (ostream & out, const Cell & cell);
	friend istream& operator >> (istream& in, Cell& cell);
};