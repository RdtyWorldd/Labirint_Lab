#pragma once

#include "Cell.h"
#include "ClearCell.h"

class PlayerCell : public Cell {
public:
	//virtual bool hasAdd();
	virtual Cell* copy();

	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);

	virtual void visit(ostream& out) const;
};