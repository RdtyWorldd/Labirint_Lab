#pragma once
#include "Cell.h"
#include "PlayerCell.h"
#include "MonsterCell.h"

class ClearCell : public Cell {
public:
	//virtual bool hasAdd();
	virtual Cell* copy();
	
	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);

	virtual Cell* operator +(Monster& monster);
	virtual Cell* operator -(Monster& monster);

	virtual void visit(ostream& out) const;
};