#pragma once
#include <iostream>

using namespace std;
class ExitsVector {
	int n;
	int* a;
public:
	ExitsVector();
	~ExitsVector();

	int getSize();
	int& operator[](int i);
	friend istream& operator >>(istream& in, ExitsVector& vector);
};