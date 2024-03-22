#include "Game.h"

Game::Game(Player& _player) : maze(nullptr), player(_player), high(0), wide(0) {}
Game::~Game() {
	delete[] maze;
}

void Game::loadMaze(string fileName) {
	ifstream file(fileName);
	
	file >> high >> wide;
	Cell* tmp = new Cell[high * wide];
	maze = new Cell* [high];
	/*подумать про реализацию правильно лежащего в двумерного памяти массива*/
	
	for (size_t i = 0; i < high; i++) {
		maze[i] = tmp + wide * i;
	}

	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			file >> maze[i][j];
		}
	}

	maze[player.getY()][player.getX()] + player;
}

void Game::move(Action act) {
	int x = player.getX();
	int y = player.getY();

	switch (act)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case RIGHT:
		x++;
		break;
	case LEFT:
		x--;
		break;
	}

	if ((x < 0) || (y < 0) ||(x >= wide) || (y >= high) || maze[y][x].isFilled()) {
		return;
	} 
	else {
		maze[player.getY()][player.getX()] - player;
		maze[y][x] + player;
		player.setX(x);
		player.setY(y);
	}
}

ostream& operator <<(ostream& out, const Game& game) {
	for (size_t i = 0; i < game.high; i++) {
		for (size_t j = 0; j < game.wide; j++) {
			out << game.maze[i][j];
		}
		out << endl;
	}
	return out;
}

