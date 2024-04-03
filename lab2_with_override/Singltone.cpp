#include "Singltone.h"

Singltone* Singltone::p_instance = 0;

Singltone::Singltone() {
	exitCounter = 0;
	vector = new ExitsVector();
}

Singltone::~Singltone() {
	delete vector;
}

Singltone* Singltone::getInstance() {
	if (!p_instance) {
		p_instance = new Singltone();
	}
	return p_instance;
}


ExitsVector& Singltone::getVector() {
	return *vector;
}

void Singltone::resetCount() {
	exitCounter = 0;
}

int Singltone::getNext() {
	if (exitCounter >= vector->getSize())
		throw - 5;
	return (*vector)[exitCounter++];
}


