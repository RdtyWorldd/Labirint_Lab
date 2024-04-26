#pragma once

#include "IObserver.h"
#include "Game.h"

class PlayerStepsView : public IObserver {
	ostream& out;
public:
	PlayerStepsView(ostream& _out): out(_out) {}
	void event(Game& model);
};