#include "Cell.h"

Cell::Cell() {
	filled = false;
	hero = nullptr;
}

Cell::Cell(const Cell& _cell) {
	hero = nullptr;
	if (_cell.hero != nullptr) {
		hero = new Player();
		*hero = *(_cell.hero);
	}

	filled = _cell.filled;
}
void Cell::setHero(Player* _hero) { hero = _hero; }
bool Cell::isFilled() { return filled; }

Cell& Cell::operator=(const Cell& _cell) {
	if (hero != nullptr)
		delete[] hero;
	hero = _cell.hero;
	filled = _cell.filled;
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

ostream& operator <<(ostream & out, const Cell & cell) {
	if (cell.filled) {
		return out << "#";
	}
	else if (cell.hero) {
		return out << "@";
	}
	else {
		return out << " ";
	}
	
}

istream& operator >>(istream& in, Cell& cell) {
	unsigned char tmp;
	in >> tmp;
	if (tmp == '#')
		cell.filled = true;
	
	return in;
}