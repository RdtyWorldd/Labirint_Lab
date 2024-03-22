#include "Cell.h"

Cell::Cell() {
	filled = false;
	hero = false;
}

void Cell::setHero(bool _hero) { hero = _hero; }
bool Cell::isFilled() { return filled; }

Cell Cell::operator+(const Player & player) {
	hero = true;
	return *this;
}

Cell Cell::operator-(const Player& player) {
	hero = false;
	return *this;
}

ostream& operator <<(ostream & out, const Cell & cell) {
	if (cell.filled) {
		return out << "#";
	}
	else if (cell.hero) {
		return out << "@";
	}
	else {
		return out << " ";
	}
	
}

istream& operator >>(istream& in, Cell& cell) {
	unsigned char tmp;
	in >> tmp;
	if (tmp == '#')
		cell.filled = true;
	
	return in;
}