#pragma once

enum Action {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Entity {
protected:
	int x, y;
	int hp;
public:
	Entity(int x = 1, int y = 1, int _hp = 1);
	int getX();
	int getY();
	int getHP();
	virtual void move(int x, int y);
	virtual ~Entity();
};