#include "Cell.h"

Cell::Cell() {
	hero = nullptr;
}

Cell::Cell(const Cell& _cell) {
	hero = nullptr;
	if (_cell.hero != nullptr) {
		hero = new Player();
		*hero = *(_cell.hero);
	}
}

Cell::~Cell() {
	delete hero;
}

void Cell::setHero(Player* _hero) { hero = _hero; }

bool Cell::hasAdd() {
	return true;
}

Cell& Cell::operator=(const Cell& _cell) {
	if (hero != nullptr)
		delete[] hero;
	hero = _cell.hero;
	return *this;
}

Cell Cell::operator+(Player & player) {
	Cell cell = *this;
	cell.hero = &player;

	return cell;
}

Cell Cell::operator-(Player& player) {
	Cell cell = *this;
	cell.hero = nullptr;

	return cell;;
}

void Cell::operator +=(Player& player) {
	hero = &player;
}

void Cell::operator -=(Player& Player) {
	hero = nullptr;
}

void Cell::visit(ostream& out) const {
	if (hero) {
		out << "@";
	}
	else {
		out << " ";
	}
}

