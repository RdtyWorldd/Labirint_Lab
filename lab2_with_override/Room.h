#pragma once
#include "Cell.h"
#include "ClearCell.h"
#include "PlayerCell.h"
#include "Wall.h"
#include "Treasure.h"
#include "Exit.h"

#include "Singltone.h"

class Room {
	int high, wide;
	Cell*** cells;
public:
	Room();
	~Room();

	int getWide();
	int getHigh();
	
	friend ostream& operator <<(ostream& out, const Room& room);
	friend istream& operator >>(istream& in, Room& room);
};

istream& operator >>(istream& in, Cell*& cell);