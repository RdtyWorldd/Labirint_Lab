#pragma once
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "AddCellException.h"
#include "GameOverException.h"

using namespace std;

class Cell {
public:
	//virtual bool hasAdd() =0;

	virtual Cell* copy() =0;

	virtual Cell* operator +(Player& player) =0;
	virtual Cell* operator -(Player& player) =0;

	virtual Cell* operator +(Monster& monster) =0;
	virtual Cell* operator -(Monster& monster) = 0;

	virtual void visit(ostream& out) const =0;
};

