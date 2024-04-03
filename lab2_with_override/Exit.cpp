#include "Exit.h"

Exit::Exit() {
	nextRoom = Singltone::getInstance()->getNext();
}

Cell* Exit::copy() {
	return new Exit(nextRoom);
}

Cell* Exit::operator +(Player& player) {
	if (nextRoom == -1) {
		throw - 2;// код ошибки для завершения игры, так как других комнат нет, нашелся выход
	}
	throw 3; // код исключения для того чтобы загрузить другую комнату
	return new Exit(nextRoom);
}

Cell* Exit::operator -(Player& player) {
	throw - 1;
	return new Exit(nextRoom);
}

void Exit::visit(ostream& out) const {
	out << "/";
}