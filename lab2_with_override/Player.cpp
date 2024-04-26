#include "Player.h"

Player::Player(int _x, int _y, int _hp):Entity(_x, _y, _hp), treasures(0), steps(0) {}

int Player::getTreasures() { return treasures; }
void Player::addTreasure() { treasures++; }
int Player::getSteps() { return steps; }
void Player::move(int _x, int _y) { x = _x; y = _y; steps++; }