#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct Term {
	int Coef;
	int Exp;
	Term* Next;

};

class Polynominal {
public:
	Polynominal();
	~Polynominal();

	Term *head;

	void Append(int c, int e);
	void Sort();
	void Merge();
	void inputPoly();
	void outputPoly();

	friend Polynominal& operator*(const Polynominal& polyA, const Polynominal& polyB);

private:

};
#endif