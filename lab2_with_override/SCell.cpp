#include "SCell.h"

SCell::SCell(): cell(nullptr), wachers(0){}
SCell::SCell(Cell* _cell) : cell(_cell), wachers(1) {}
SCell::SCell(const SCell& scell) {
	wachers = scell.wachers + 1;
	cell = scell.cell;
}

SCell::~SCell() {
	if (wachers == 1) {
		delete[] cell;
	}
}
void SCell::setCell(Cell* _cell) {
	if (this->cell == _cell)
		return;

	if (wachers == 1)
		delete cell;

	cell = _cell;
	wachers = 1;
}


Cell* SCell::getCell() {
	return cell;
}

SCell& SCell::operator =(SCell& scell) {
	if (&scell == this)
		return *this;
	if (wachers == 1) {
		delete cell;
	}
	cell = scell.cell;
	wachers = scell.wachers++;
	return *this;
}

void SCell::operator+= (Player& player) {
	cell = *cell + player;
}

void SCell::operator-= (Player& player) {
	cell = *cell - player;
}

Cell* SCell::operator->() {
	return cell;
}

istream& operator >>(istream& in, SCell& scell) {
	unsigned char tmp;
	in >> tmp;
	if (tmp == '#') {
		scell.setCell(new Wall());
	}
	else if (tmp == '$') {
		scell.setCell(new Treasure());
	}

	return in;
}