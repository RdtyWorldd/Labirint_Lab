#include "ExitsVector.h"

ExitsVector::ExitsVector() : n(0), a(nullptr) {}
ExitsVector::~ExitsVector() {
	if (a != nullptr)
		delete[] a;
}

int ExitsVector::getSize() {
	return n;
}

int& ExitsVector::operator[] (int i) {
	return a[i];
}

istream& operator >>(istream& in, ExitsVector& vector) {
	int n;
	in >> n;
	if (n < 0)
		throw - 5;

	if (vector.a != nullptr)
		delete[] vector.a;

	vector.n = n;
	if (n == 0) {
		vector.a = nullptr;
		return in;
	}
	vector.a = new int[n];
	for (int i = 0; i < n; i++) {
		in >> vector.a[i];
	}
	return in;
}