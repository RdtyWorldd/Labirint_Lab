#pragma once
#include "Cell.h"
#include "ClearCell.h"
#include "PlayerCell.h"
#include "Wall.h"
#include "Treasure.h"
#include "Exit.h"

#include "Monster.h"
#include "MonsterCell.h"

#include "Singltone.h"

class Room {
	int high, wide;
	Cell*** cells;
	Monster* monsters; //не реализованно, надо бы перейти к вектору
public:
	Room();
	Room(const Room& room);
	Room& operator =(const Room& room);
	~Room();

	int getWide();
	int getHigh();
	Cell*** getCells();

	friend ostream& operator <<(ostream& out, const Room& room);
	friend istream& operator >>(istream& in, Room& room);
};

ostream& operator <<(ostream& out, const Cell*& room);
istream& operator >>(istream& in, Cell*& cell);