#include "RoomView.h"

void RoomView::event(Game& model) {
	Room room = model.getRoom();
	Cell*** cells = room.getCells();
	int visionRad = model.getVisionRad();
	int h = room.getHigh();
	int w = room.getWide();
	int x = model.getPlayer().getX();
	int y = model.getPlayer().getY();

	system("cls");

	for (int i = -visionRad; i <= visionRad; i++) {
		for (int j = -visionRad; j <= visionRad; j++) {
			if (((i + y < 0) || (i + y >= h)) || ((j + x < 0) || (j + x >= w)))
				out << '#';
			else cells[i+y][j+x]->visit(out);
		}
		out << endl;
	}
}