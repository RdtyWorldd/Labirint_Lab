#include "GameController.h"

void GameController::start()
{
	unsigned char key = 0;
	while (key != 27) {
		key = _getch();
		if (key == 224) {
			key = _getch();
		}

		switch (key) {
		case 72:
			model.move(UP);
			break;
		case 80:
			model.move(DOWN);
			break;
		case 75:
			model.move(LEFT);
			break;
		case 77:
			model.move(RIGHT);
			break;
		}
		//system("cls");
		//cout << game;
	}
}
