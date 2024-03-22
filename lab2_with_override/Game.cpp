#include "Game.h"

Game::Game(Player& _player) : maze(nullptr), player(_player), high(0), wide(0) {}

Game::Game(const Game& _game): player(_game.player) {
	high = _game.high;
	wide = _game.wide;
	if (_game.maze == nullptr)
	{
		maze = nullptr;
		return;
	}

	Cell* tmp = new Cell[high * wide];

	maze = new Cell * [high];
	for (size_t i = 0; i < high; i++) {
		maze[i] = tmp + wide * i;
	}

	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			maze[i][j] = _game.maze[i][j];
		}
	}
}

Game::~Game() {
	delete[] maze;
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
		maze[player.getY()][player.getX()] -= player;
		maze[y][x] += player;
		player.move(x, y);
	}
}

Game& Game::operator= (const Game& _game) {
	if (maze != nullptr) {
		delete[] maze;
	}

	player = _game.player;
	high = _game.high;
	wide = _game.wide;

	Cell* tmp = new Cell[high * wide];

	maze = new Cell * [high];
	for (size_t i = 0; i < high; i++) {
		maze[i] = tmp + wide * i;
	}

	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			maze[i][j] = _game.maze[i][j];
		}
	}
	return *this;
}

istream& operator >>(istream& in, Game& game) {
	in >> game.high >> game.wide;
	Cell* tmp = new Cell[game.high * game.wide];

	if (game.maze == nullptr) {
		delete[] game.maze;
	}
	game.maze = new Cell * [game.high];
	/*подумать про реализацию правильно лежащего в двумерного памяти массива*/

	for (size_t i = 0; i < game.high; i++) {
		game.maze[i] = tmp + game.wide * i;
	}

	for (size_t i = 0; i < game.high; i++) {
		for (size_t j = 0; j < game.wide; j++) {
			in >> game.maze[i][j];
		}
	}

	game.maze[game.player.getY()][game.player.getX()] += game.player;
	return in;
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

