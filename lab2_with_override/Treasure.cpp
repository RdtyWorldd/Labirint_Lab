#include "Treasure.h"


void Treasure::visit(ostream& out) const {
	out << " ";
}

bool Treasure::hasAdd() {
	return true;
}

Cell* Treasure::operator+ (Player& hero) {
	hero.addTreasure();
	Cell* cell = new Cell();
	*cell += hero;

	return cell;
}
