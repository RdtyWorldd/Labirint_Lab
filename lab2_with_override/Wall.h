#pragma once
#include "Cell.h"

class Wall : public Cell {
public:
	virtual void visit(ostream& out) const;
	virtual bool hasAdd();
};