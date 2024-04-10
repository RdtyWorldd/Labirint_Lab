#pragma once

#include "Monster.h"

class Xmonster : public Monster {
	Action act;
	bool isVertical;
	bool isHorizontal;
	int maxRad;
public:
	Xmonster(int _x = 1, int _y = 1, int _hp = 1);
	virtual void move(int _x = -1, int _y = -1);
};