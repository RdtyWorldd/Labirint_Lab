#pragma once

#include "Cell.h"
#include "ClearCell.h"

class MonsterCell : public Cell {
public:

	virtual Cell* copy();

	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);

	virtual Cell* operator +(Monster& monster);
	virtual Cell* operator -(Monster& monster);

	virtual void visit(ostream& out) const;
};