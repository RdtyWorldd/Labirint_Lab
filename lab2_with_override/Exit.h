#pragma once

#include "Cell.h"
#include "Singltone.h"
#include "ExitException.h"

class Exit : public Cell {
	int nextRoom;
public:
	//virtual bool hasAdd();
	Exit();
	Exit(int _nextRoom): nextRoom(_nextRoom) {}

	virtual Cell* copy();

	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);

	virtual void visit(ostream& out) const;
};