#include "Entity.h"

Entity::Entity(int _x, int _y, int _hp): x(_x), y(_y), hp(_hp) {}
Entity::~Entity() {}

int Entity::getX() { return x; }
int Entity::getY() { return y; }
int Entity::getHP() { return hp; }
void Entity::move(int _x, int _y) { x = _x; y = _y; }
