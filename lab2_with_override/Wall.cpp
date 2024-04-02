#include "Wall.h"
//bool Wall::hasAdd() {
//	return false;
//}

Cell* Wall::copy() {
	return new Wall();
}

Cell* Wall::operator +(Player& player) {
	throw -1;
	return new Wall();
}

Cell* Wall::operator -(Player& player) {
	throw - 1;
	return new Wall();
}

void Wall::visit(ostream& out) const{
	out << "#";
}
