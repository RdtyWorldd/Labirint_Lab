#pragma once
#include "Cell.h"
#include "Wall.h"
#include "Treasure.h"

class SCell {
	int wachers;
	Cell* cell;
public:
	SCell();
	SCell(Cell* _cell);
	SCell(const SCell& scell);
	~SCell();
	
	void setCell(Cell* _cell);
	Cell* getCell();

	SCell& operator =(SCell& scell);
	Cell* operator ->();

	friend istream& operator >>(istream& in, SCell& scell);
};