#include "Player.h"

Player::Player(int _x, int _y) : x(_x), y(_y) {}

int Player::getX() { return x; }
void Player::setX(int _x) { x = _x; }

int Player::getY() { return y; }
void Player::setY(int _y) { y = _y; }