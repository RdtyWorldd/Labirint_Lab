#pragma once

class Game;

class IObserver {
public:
	virtual void event(Game& model) =0;
};