#pragma once

#include "IObserver.h"
#include "Game.h"

class PlayerStatsView : public IObserver {
	ostream& out;
public:
	PlayerStatsView(ostream& _out): out(_out) {}
	void event(Game& model);
};