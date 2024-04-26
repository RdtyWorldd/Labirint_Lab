#include "Exit.h"

Cell* Exit::copy() {
	return new Exit(nextRoom);
}

Cell* Exit::operator +(Player& player) {
	if (nextRoom == -1) {
		throw - 2;// ��� ������ ��� ���������� ����, ��� ��� ������ ������ ���, ������� �����
	}
	throw ExitException(nextRoom); // ��� ���������� ��� ���� ����� ��������� ������ �������
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