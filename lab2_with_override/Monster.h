#pragma once
#include "Entity.h"

class Monster : public Entity{
protected:
	int startX, startY;
public:
	Monster(int _x = 0, int _y = 0, int _hp = 1):Entity(_x, _y, _hp), startX(_x), startY(_y) {};
	virtual void move(int x = -1, int y = -1) =0;
	virtual ~Monster() {}
};