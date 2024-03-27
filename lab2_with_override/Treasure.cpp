#include "Treasure.h"

bool Treasure::hasAdd() {
	return true;
}

Cell* Treasure::copy() {
	return new Treasure();
}

Cell* Treasure::operator +(Player& player) {
	player.addTreasure();
	return new PlayerCell();
}

Cell* Treasure::operator -(Player& player) {
	return this;
}

void Treasure::visit(ostream& out) const {
	out << "$";
}
