#include "Wall.h"
bool Wall::hasAdd() {
	return false;
}

Cell* Wall::copy() {
	return new Wall();
}

Cell* Wall::operator +(Player& player) {
	return this;
}

Cell* Wall::operator -(Player& player) {
	return this;
}

void Wall::visit(ostream& out) const{
	out << "#";
}
