#include "Exit.h"

Cell* Exit::copy() {
	return new Exit(nextRoom);
}

Cell* Exit::operator +(Player& player) {
	if (nextRoom == -1) {
		throw - 2;// код ошибки для завершения игры, так как других комнат нет, нашелся выход
	}
	throw ExitException(nextRoom); // код исключения для того чтобы загрузить другую комнату
	return new Exit(nextRoom);
}

Cell* Exit::operator -(Player& player) {
	throw AddCellException();
	return new Exit(nextRoom);
}

Cell* Exit::operator+(Monster& monster) {
	return new Exit(nextRoom);
}

Cell* Exit::operator-(Monster& monster) {
	throw AddCellException();
	return new Exit(nextRoom);
}

void Exit::visit(ostream& out) const {
	out << "/";
}