#include "ClearCell.h"

//bool ClearCell::hasAdd() {
//	return true;
//}

Cell* ClearCell::copy() {
	return new ClearCell();
}

Cell* ClearCell::operator +(Player& player) {
	return new PlayerCell();
}

Cell* ClearCell::operator -(Player& player) {
	throw -1;
	return new ClearCell();
}

void ClearCell::visit(ostream& out) const {
	out << " ";
}