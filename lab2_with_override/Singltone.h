#pragma once
#include "ExitsVector.h"

class Singltone {
	static Singltone* p_instance;
	Singltone();
	Singltone(const Singltone&);
	Singltone& operator =(Singltone&);

	ExitsVector* vector;
	int exitCounter;
public:
	static Singltone* getInstance();
	ExitsVector& getVector();
	int getNext();

	~Singltone();
};
