#pragma once
#include "Cell.h"
#include "PlayerCell.h"

class ClearCell : public Cell {
public:
	virtual bool hasAdd();
	virtual Cell* copy();
	
	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);

	virtual void visit(ostream& out) const;
};