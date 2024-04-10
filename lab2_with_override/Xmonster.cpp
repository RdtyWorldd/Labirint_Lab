#include "Xmonster.h"
#include <math.h>

Xmonster::Xmonster(int _x, int _y, int _hp) :Monster(_x, _y, _hp) {
	act = UP;
	maxRad = 1;
	isVertical = true;
	isHorizontal = false;
}

void Xmonster::move(int _x, int _y) {
	if (_x > 0 && _y > 0) {
		Entity::move(_x, _y);
		startX = x;
		startY = y;
		return;
	}

	switch (act)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	}

	if (isVertical && isHorizontal) {
		if (abs(x - startX) == 0 || abs(y - startY) == 0) {
			if (act == UP) {
				act = LEFT;
				isVertical = false;
			}
			else {
				act = UP;
				isHorizontal = false;
			}
		}
	}
	else if (isVertical && (abs(y - startY) == maxRad)) {
		if (act == UP) act = DOWN;
		else {
			act = UP;
			isHorizontal = true;
		}
	}
	else if(abs(x - startX) == maxRad ) {
		if (act == LEFT) act = RIGHT;
		else {
			act = LEFT;
			isVertical = true;
		}
	}


}