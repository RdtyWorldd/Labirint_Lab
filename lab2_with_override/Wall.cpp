#include "Wall.h"
//bool Wall::hasAdd() {
//	return false;
//}

Cell* Wall::copy() {
	return new Wall();
}

Cell* Wall::operator +(Player& player) {
	throw AddCellException();
	return new Wall();
}

Cell* Wall::operator -(Player& player) {
	throw AddCellException();
	return new Wall();
}

void Wall::visit(ostream& out) const{
	out << "#";
}
