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
	maze = new Cell** [high];
	for (size_t i = 0; i < high; i++) {
		maze[i] = new Cell * [wide];
	}
	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			maze[i][j] = new Cell();
		}
	}

	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			*(maze[i][j]) = *(_game.maze[i][j]);
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

	if ((x < 0) || (y < 0) ||(x >= wide) || (y >= high) || !maze[y][x]->hasAdd()) {
		return;
	} 
	else {
		*(maze[player.getY()][player.getX()]) -= player;
		*(maze[y][x]) += player;
		player.move(x, y);
	}
}

Game& Game::operator= (const Game& _game) {
	player = _game.player;
	high = _game.high;
	wide = _game.wide;

	if (maze != nullptr) {
		delete[] maze;
	}

	for (size_t i = 0; i < high; i++) {
		maze[i] = new Cell * [wide];
	}
	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			maze[i][j] = new Cell();
		}
	}

	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			*(maze[i][j]) = *(_game.maze[i][j]);
		}
	}
	return *this;
}

istream& operator >>(istream& in, Game& game) {
	int high, wide;
	in >> high >> wide;
	if (game.maze != nullptr)
		delete[] game.maze;

	//Cell** tmp = new Cell* [high * wide]();
	Cell*** maze = new Cell** [high];

	//for (int i = 0; i < high * wide; i++)
	//	tmp[i] = new Cell();
	//for (int i = 0; i < high * wide; i++){
	//	in >> *(tmp[i]);
	//}

	for (size_t i = 0; i < high; i++) {
		maze[i] = new Cell* [wide];
	}
	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			maze[i][j] = new Cell();
		}
	}
	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			in >> &maze[i][j];
		}
	}

	game.high = high;
	game.wide = wide;
	game.maze = maze;
	*(game.maze[game.player.getY()][game.player.getX()]) += game.player;
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

ostream& operator <<(ostream& out, const Cell* cell) {
	cell->visit(out);
	return out;
}

istream& operator >>(istream& in, Cell**cell) {
	unsigned char tmp;
	in >> tmp;
	if (tmp == '#') {
		delete *cell;
		*cell = new Wall();
	}

	return in;
}