#pragma once
#include <conio.h>
#include "Game.h"

class GameController {
	Game& model;
public:
	GameController(Game& _model) : model(_model) {};
	void start();
};