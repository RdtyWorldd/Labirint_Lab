#include "Game.h"

Game::Game(Player& _player) : roomsCount(0), roomNow(-1), rooms(nullptr), player(_player), visionRad(2) {}

Game::Game(const Game& _game): player(_game.player) {
	visionRad = _game.visionRad;
	roomNow = _game.roomNow;
	roomsCount = _game.roomsCount;
	if (_game.rooms == nullptr) {
		rooms = nullptr;
		return;
	}

	rooms = new Room[roomsCount];
	for (size_t i = 0; i < roomsCount; i++) {
		rooms[i] = _game.rooms[i];
	}
	observers = _game.observers;
}

Game::~Game() {
	delete[] rooms;
}

void Game::event() {
	for (IObserver* o : observers)
		o->event(*this);
}

int Game::getVisionRad() { return visionRad; }
Room Game::getRoom() { return rooms[roomNow]; }
Player& Game::getPlayer() { return player; }
void Game::addObserver(IObserver* o) { observers.push_back(o); }

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

	if ((x < 0) || (y < 0) ||(x >= rooms[roomNow].getWide()) || (y >= rooms[roomNow].getHigh())) {
		return;
	} 
	else {
		try {
			Cell*** cells = rooms[roomNow].getCells();
			
			int ox = player.getX();
			int oy = player.getY();
			Cell* t = cells[y][x];

			cells[y][x] = *t + player;
			delete t;

			t = cells[oy][ox];
			cells[oy][ox] = *t - player;
			delete t;

			player.move(x, y);
		}
		catch (ExitException e) {
			changeRoom(e.getNextRoom());
		}
		catch (AddCellException e) {
			//cout <<e.what();
		}
	}
	event();
}

void Game::changeRoom(int roomId) {
	int ox = player.getX();
	int oy = player.getY();

	Cell*** cells = rooms[roomNow].getCells();
	delete cells[oy][ox];
	cells[oy][ox] = new ClearCell();
	

	roomNow = roomId;
	int x = (rooms[roomNow].getWide() - 1) / 2;
	int y = (rooms[roomNow].getHigh() - 1) / 2;

	cells = rooms[roomNow].getCells();
	delete cells[y][x];
	cells[y][x] = new PlayerCell();
	

	player.move(x, y);
}

Game& Game::operator= (const Game& _game) {
	if (this == &_game) {
		return *this;
	}

	player = _game.player;
	roomsCount = _game.roomsCount;
	roomNow = _game.roomNow;
	visionRad = _game.visionRad;

	if (rooms != nullptr) {
		delete[] rooms;
	}

	if (_game.rooms == nullptr) {
		rooms = nullptr;
		return *this;
	}

	rooms = new Room[roomsCount];
	for (size_t i = 0; i < roomsCount; i++) {
		rooms[i] = _game.rooms[i];
	}
	observers = _game.observers;
	return *this;
}

istream& operator >>(istream& in, Game& game) {
	int roomsCount, roomNow;
	in >> roomsCount >> roomNow;
	
	game.roomsCount = roomsCount;
	game.roomNow = roomNow;

	if (game.rooms != nullptr)
		delete[] game.rooms;

	if (roomsCount <= 0 || roomNow < 0) {
		throw - 10000; // € об€щательно напишу классы исключений, честно
	}

	game.rooms = new Room[roomsCount];
	for (size_t i = 0; i < roomsCount; i++) {
		in >> game.rooms[i];
	}

	game.rooms[game.roomNow].getCells()[game.player.getY()][game.player.getX()] = new PlayerCell();
	//game.rooms[game.roomNow].getCells()[game.monster->getY()][game.monster->getX()] = new MonsterCell();
	game.event();
	return in;
}

ostream& operator <<(ostream& out, const Game& game) {
	out << game.rooms[game.roomNow];
	out << "Treasures find: " << game.player.getTreasures();
	return out;
}

//

