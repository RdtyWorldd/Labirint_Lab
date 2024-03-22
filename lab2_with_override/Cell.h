#pragma once
#include <iostream>
#include "Player.h"

using namespace std;

class Cell {
	bool filled;
	Player* hero;
public:
	Cell();
	Cell(const Cell& _cell);

	Player& getHero();
	void setHero(Player* _hero);
	bool isFilled();
	void setFilled();

	Cell& operator =(const Cell& _cell);

	Cell operator +(Player& player);
	Cell operator -(Player& player);

	void operator +=(Player& player);
	void operator -=(Player& player);

	friend ostream & operator << (ostream & out, const Cell & cell);
	friend istream& operator >> (istream& in, Cell& cell);
};