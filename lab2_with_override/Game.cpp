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

	maze = new SCell * [high];
	for (size_t i = 0; i < high; i++) {
		maze[i] = new SCell[wide];
		for (size_t j = 0; j < wide; j++) {
			maze[i][j].setCell(new Cell());
		}
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

	if ((x < 0) || (y < 0) ||(x >= wide) || (y >= high) || !maze[y][x]->hasAdd()) {
		return;
	} 
	else {
		int ox = player.getX();
		int oy = player.getY();
//		*(maze[oy][ox].getCell()) = *(maze[oy][ox].getCell()) - player;
//		*(maze[y][x].getCell()) = *(maze[y][x].getCell()) + player;
		maze[oy][ox] -= player;
		maze[y][x] += player;
		
//		maze[oy][ox].setCell(*(maze[oy][ox].getCell()) - player);
//		maze[y][x].setCell( *(maze[y][x].getCell()) + player);
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

	maze = new SCell * [high];
	for (size_t i = 0; i < high; i++) {
		maze[i] = new SCell[wide];
		for (size_t j = 0; j < wide; j++) {
			maze[i][j].setCell(new Cell());
		}
	}

	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			maze[i][j] = _game.maze[i][j];
		}
	}
	return *this;
}

istream& operator >>(istream& in, Game& game) {
	int high, wide;
	in >> high >> wide;
	if (game.maze != nullptr)
		delete[] game.maze;

	game.maze = new SCell * [high];
	for (size_t i = 0; i < high; i++) {
		game.maze[i] = new SCell[wide];
		for (size_t j = 0; j < wide; j++) {
			game.maze[i][j].setCell(new Cell());
		}
	}

	for (size_t i = 0; i < high; i++) {
		for (size_t j = 0; j < wide; j++) {
			in >> game.maze[i][j];
		}
	}

	game.high = high;
	game.wide = wide;
	//game.maze = maze;
	*(game.maze[game.player.getY()][game.player.getX()].getCell()) += game.player;
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

//ostream& operator <<(ostream& out, const Cell* cell) {
//	cell->visit(out);
//	return out;
//}

//istream& operator >>(istream& in, SCell scell) {
//	unsigned char tmp;
//	in >> tmp;
//	if (tmp == '#') {
//		delete *cell;
//		*cell = new Wall();
//	}
//
//	return in;
//}