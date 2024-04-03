#include "Room.h"

Room::Room(): high(0), wide(0), cells(nullptr) {}
Room::~Room() {
	if (cells != nullptr) {
		for (int i = 0; i < high; i++) {
			for (int j = 0; j < wide; j++) {
				delete cells[i][j];
			}
			delete cells[i];
		}
		delete[] cells;
	}
}

int Room::getHigh() { return high; }
int Room::getWide() { return wide; }

ostream& operator <<(ostream& out, const Room& room) {
	for (int i = 0; i < room.high; i++) {
		for (int j = 0; j < room.wide; j++) {
			room.cells[i][j]->visit(out);
		}
		out << endl;
	}
	return out;
}

istream& operator >>(istream& in, Room& room) {
	int high = 0;
	int wide = 0;

	in >> high >> wide;
	if (high <= 0 || wide <= 0) {
		throw - 100;
		return in;
	}
	room.high = high;
	room.wide = wide;

	in >> Singltone::getInstance()->getVector();

	room.cells = new Cell **[high];
	for (int i = 0; i < high; i++) {
		room.cells[i] = new Cell * [wide];
		for (int j = 0; j < wide; j++) {
			in >> room.cells[i][j];
		}
	}

	//delete Singltone::getInstance();
	return in;
}

istream& operator >>(istream& in, Cell*& cell) {
	unsigned char tmp;
	
	in >> tmp;
	switch (tmp)
	{
	case '_':
		cell = new ClearCell();
		break;
	case '#':
		cell = new Wall();
		break;
	case '$':
		cell = new Treasure();
		break;
	case '/':
		cell = new Exit();
		break;
	default:
		break;
	}

	return in;
}