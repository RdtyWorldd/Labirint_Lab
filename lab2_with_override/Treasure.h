#pragma once

#include "Cell.h"
#include "PlayerCell.h"

class Treasure : public Cell {
public:
	//virtual bool hasAdd();
	virtual Cell* copy();

	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);

	virtual Cell* operator +(Monster& monster);
	virtual Cell* operator -(Monster& monster);

	virtual void visit(ostream& out) const;
};