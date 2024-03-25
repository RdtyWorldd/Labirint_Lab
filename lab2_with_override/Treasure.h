#pragma once

#include "Cell.h"

class Treasure : public Cell {
	virtual void visit(ostream& out) const;
	virtual bool hasAdd();

	virtual Cell* operator +(Player& player);
};