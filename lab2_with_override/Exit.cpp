#include "Exit.h"

Cell* Exit::copy() {
	return new Exit(nextRoom);
}

Cell* Exit::operator +(Player& player) {
	throw - 1;
	return new Exit(nextRoom);
}

Cell* Exit::operator -(Player& player) {
	throw - 1;
	return new Exit(nextRoom);
}

void Exit::visit(ostream& out) const {
	out << "/";
}