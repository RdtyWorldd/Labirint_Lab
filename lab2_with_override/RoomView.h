#pragma once

#include "IObserver.h"
#include "Game.h"
#include "Room.h"

class RoomView : public IObserver {
	ostream& out;
public:
	RoomView(ostream& _out) : out(_out) {}
	void event(Game& model);
};