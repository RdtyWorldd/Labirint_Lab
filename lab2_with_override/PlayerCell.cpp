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

Cell* PlayerCell::operator+(Monster& monster) {
	throw GameOverException();
	return new MonsterCell();
}

Cell* PlayerCell::operator-(Monster& monster) {
	return new PlayerCell();
}
void PlayerCell::visit(ostream& out) const {
	out << "@";
}