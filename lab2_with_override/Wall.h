#pragma once

#include "Cell.h"

class Wall : public Cell {
public:
	//virtual bool hasAdd();
	virtual Cell* copy();

	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);

	virtual Cell* operator +(Monster& player);
	virtual Cell* operator -(Monster& player);

	virtual void visit(ostream& out) const;
};