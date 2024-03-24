#include "Wall.h"

void Wall::visit(ostream& out) const {
	out << "#";
}

bool Wall::hasAdd() {
	return false;
}