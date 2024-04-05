#include "PlayerCell.h"

//bool PlayerCell::hasAdd() {
//	return false;
//}

Cell* PlayerCell::copy() {
	return new PlayerCell();
}
//возможно перейти на исключения, чтобы определенные клетки нельзя было складывать или вычитать
Cell* PlayerCell::operator +(Player& Player) {
	throw AddCellException();
	return new PlayerCell();
}

Cell* PlayerCell::operator -(Player& player) {
	return new ClearCell();
}

void PlayerCell::visit(ostream& out) const {
	out << "@";
}