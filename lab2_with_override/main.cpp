#include "Game.h"
#include "Room.h"
#include <conio.h>
#include <windows.h>


void run(Game game)
{
	//game.loadMaze("maze.txt");

	unsigned char key = _getch();
	while (key != 27) {
		key = _getch();
		if (key == 224) {
			key = _getch();
		}

		switch (key) {
		case 72:
			game.move(UP);
			break;
		case 80:
			game.move(DOWN);
			break;
		case 75:
			game.move(LEFT);
			break;
		case 77:
			game.move(RIGHT);
			break;
		}
		system("cls");
		cout << game;
	}
}

int main() {
	Player player(1, 2);
	Game game(player);
	Game game1(player);

	//Cell* cell = new Cell();
	//Wall* wall = new Wall();
	//cout << *cell << *wall <<endl;
	//cell = wall;
	//cout << *cell;
	//return 0;
	{
		try {
			ifstream file("maze3.txt");
			file >> game1;
			delete Singltone::getInstance();
		} catch (exception e) {
			cout << e.what();
			exit(-1);
		}
	}

	//{
	//	ifstream file("maze1.txt");
	//	Room room;
	//	file >> room;
	//	cout << room;
	//}
	//game1.loadMaze("maze.txt");
	//game = game1;
	cout << game1;
	
	run(game1);
	
//	Game game(player);
//	game = game1;
}