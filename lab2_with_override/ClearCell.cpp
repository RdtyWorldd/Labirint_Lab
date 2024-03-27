#include "ClearCell.h"

bool ClearCell::hasAdd() {
	return true;
}

Cell* ClearCell::copy() {
	return new ClearCell();
}

Cell* ClearCell::operator +(Player& player) {
	return new PlayerCell();
}

Cell* ClearCell::operator -(Player& player) {
	return this;
}

void ClearCell::visit(ostream& out) const {
	out << " ";
}