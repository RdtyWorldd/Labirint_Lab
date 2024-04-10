#include "MonsterCell.h"

Cell* MonsterCell::copy() {
	return new MonsterCell();
}

Cell* MonsterCell::operator+(Player& player) {
	throw GameOverException();
	return new MonsterCell();
}

Cell* MonsterCell::operator-(Player& player) {
	return new MonsterCell();
}

Cell* MonsterCell::operator+(Monster& monster) {
	throw AddCellException();
	return new MonsterCell;
}

Cell* MonsterCell::operator-(Monster& monster) {
	return new ClearCell();
}

void MonsterCell::visit(ostream& out) const {
	out << "&";
}