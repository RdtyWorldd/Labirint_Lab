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
		maze[i] = new Cell*[wide];
		for (size_t j = 0; j < wide; j++) {
			maze[i][j] = _game.maze[i][j]->copy();
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
		int ox = player.getX();
		int oy = player.getY();
		maze[oy][ox] = *(maze[oy][ox]) - player;
		maze[y][x] = *(maze[y][x]) + player;

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

	if (_game.maze == nullptr) {
		maze = nullptr;
		return *this;
	}

	maze = new Cell** [high];
	for (size_t i = 0; i < high; i++) {
		maze[i] = new Cell* [wide];
		for (size_t j = 0; j < wide; j++) {
			maze[i][j] = _game.maze[i][j]->copy();
		}
	}

	return *this;
}

istream& operator >>(istream& in, Game& game) {
	int high, wide;
	in >> high >> wide;
	if (game.maze != nullptr)
		delete[] game.maze;

	game.maze = new Cell ** [high];
	for (size_t i = 0; i < high; i++) {
		game.maze[i] = new Cell*[wide];
	}

	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			in >> &(game.maze[i][j]);
		}
	}

	game.high = high;
	game.wide = wide;
	//game.maze = maze;
	game.maze[game.player.getY()][game.player.getX()] = new PlayerCell();
	return in;
}

ostream& operator <<(ostream& out, const Game& game) {
	for (size_t i = 0; i < game.high; i++) {
		for (size_t j = 0; j < game.wide; j++) {
			game.maze[i][j]->visit(out);
		}
		out << endl;
	}
	out << "Treasures find: " << game.player.getTreasures();
	return out;
}
//
//ostream& operator <<(ostream& out, const Cell* cell) {
//	cell->visit(out);
//	return out;
//}

istream& operator >>(istream& in, Cell** cell) {
	unsigned char tmp;
	in >> tmp;
	switch (tmp)
	{
	case '_':
		*cell = new ClearCell();
		break;
	case '#':
		*cell = new Wall();
		break;
	case '$':
		*cell = new Treasure();
		break;
	default:
		break;
	}

	return in;
}