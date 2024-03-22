#include "Player.h"

Player::Player(int _x, int _y) : x(_x), y(_y) {}

int Player::getX() { return x; }
int Player::getY() { return y; }
void Player::move(int _x, int _y) { x = _x; y = _y; }