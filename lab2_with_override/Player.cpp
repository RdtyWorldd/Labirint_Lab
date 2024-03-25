#include "Player.h"

Player::Player(int _x, int _y) : x(_x), y(_y), treasures(0) {}

int Player::getX() { return x; }
int Player::getY() { return y; }
int Player::getTreasures() { return treasures; }

void Player::addTreasure() { treasures++; }
void Player::move(int _x, int _y) { x = _x; y = _y; }