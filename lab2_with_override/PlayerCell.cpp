#include "PlayerCell.h"

bool PlayerCell::hasAdd() {
	return false;
}

Cell* PlayerCell::copy() {
	return new PlayerCell();
}
//�������� ������� �� ����������, ����� ������������ ������ ������ ���� ���������� ��� ��������
Cell* PlayerCell::operator +(Player& Player) {
	return this;
}

Cell* PlayerCell::operator -(Player& player) {
	return new ClearCell();
}

void PlayerCell::visit(ostream& out) const {
	out << "@";
}