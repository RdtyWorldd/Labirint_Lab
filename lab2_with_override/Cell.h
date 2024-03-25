#pragma once
#include <iostream>
#include "Player.h"

using namespace std;

class Cell {
protected:
	Player* hero;
public:
	Cell();
	Cell(const Cell& _cell);
	virtual ~Cell();

	Player& getHero();
	void setHero(Player* _hero);
	virtual bool hasAdd();

	virtual Cell& operator =(const Cell& _cell);
	//невозможно изменить клетку если присваивать по объекту который хранит указатель, тк 
	//измен€етс€ объект а не ссылка, и сокровище остаетс€ сокровищем
//	virtual Cell operator +(Player& player);
//	virtual Cell operator -(Player& player);

	//те же операторы, но возвращают ссылки
	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);

	void operator +=(Player& player);
	void operator -=(Player& player);

	virtual void visit(ostream& out) const;
	//friend ostream & operator << (ostream & out, const Cell & cell);
	//friend istream& operator >> (istream& in, Cell& cell);
};

