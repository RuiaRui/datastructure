#include "Polynominal.h"
#include <iostream>


//using std::cout;
//using std::cin;
//using std::endl;

using namespace std;

Polynominal::Polynominal()
{
	head = new Term();
	head->Coef = 0;
	head->Exp = 0;
	head->Next = head;
}


Polynominal::~Polynominal()
{
	Term *p = head->Next;
	while (p != head) {
		head->Next = p->Next;
		delete p;
		p = head->Next;
	}
	delete head;
}

void Polynominal::Append(int c, int e)
{
	Term *term = new Term;
	term->Coef = c;
	term->Exp = e;
	term->Next = head->Next;
	head->Next = term;
	
}

void Polynominal::inputPoly()
{
	Polynominal *poly = new Polynominal();
	int e, c;

	cout << "Please input a polynominal." << endl;
	cout << "when you finish the input, please set coeffcient to 0 to quit the input" << endl;

	while (true) {
		cout << "Input the coeffcient: " << endl;
		cin >> c;
		if (c == 0) break;
		cout << "Input the exponent:  " << endl;
		cin >> e;
		this->Append(c, e);
	}

	cout << "The polynominal is input completely. \n";

	this->Merge();
}

void Polynominal::outputPoly()
{
	Term* display = head->Next;
	bool isFirst = true;
	bool isPlus = false;

	for (; display != head; display = display->Next) {
		if (display->Coef >= 0) {
			isPlus = true;
		}
		else {
			isPlus = false;
		}

		if (!isFirst) {
			if (isPlus) {
				cout << "+";
			}
		}
		if (!isPlus) {
			cout << "-";
		}

		if (abs(display->Coef) != 1) {
			if (display->Exp == 0) {
				cout << abs(display->Coef);
			}
			else if (display->Exp == 1) {
				cout << abs(display->Coef) << "x";
			}
			else {
				cout << abs(display->Coef) << "x^" << display->Exp;
			}
		}
		else {
			if (display->Exp == 0) {
				cout << "1";
			}
			else if (display->Exp == 1) {
				cout << "x";
			}
			else {
				cout << "x^" << display->Exp;
			}
		}
		isFirst = false;
	}

	cout << endl << endl;
}



Polynominal & operator*(const Polynominal & polyA, const Polynominal & polyB)
{
	// TODO: 在此处插入 return 语句
	Polynominal *polyC = new Polynominal;


	Term *operA = polyA.head->Next;
	Term *operB = polyB.head->Next;
	//Term *operC = polyC->head;

	cout << "doing the multiplication calculation..." << endl;


	while (operA != polyA.head)
	{

		operB = polyB.head->Next;

		while (operB != polyB.head)
		{
			polyC->Append(operA->Coef*operB->Coef, operA->Exp + operB->Exp);
			operB = operB->Next;

		}
		operA = operA->Next;
		//operC->Next = polyC->head;

	}
	polyC->Merge();

	return *polyC;
}

void Polynominal::Sort()
{
	int tempCoef;
	int tempExp;

	Term *compare = head;
	Term *mess = head;
	for (; mess->Next != head; mess = mess->Next) {
		compare = head;
		for (; compare->Next != head; compare = compare->Next)

			if (compare->Exp > compare->Next->Exp) {

				tempCoef = compare->Coef;
				compare->Coef = compare->Next->Coef;
				compare->Next->Coef = tempCoef;

				tempExp = compare->Exp;
				compare->Exp = compare->Next->Exp;
				compare->Next->Exp = tempExp;

			}

	}
}

void Polynominal::Merge()
{
	this->Sort();

	Term *poly = head;
	bool Action = false;

	while (poly->Next != head)
	{

		if (!Action)
		{
			poly = poly->Next;
		}

		Action = false;
		if (poly->Next == head)
		{
			break;
		}

		if (poly->Exp == poly->Next->Exp)
		{

			poly->Coef = poly->Coef + poly->Next->Coef;
			if (poly->Next->Next == head)
			{
				poly->Next = head;
				break;
			}
			else
			{
				poly->Next = poly->Next->Next;
			}

			Action = true;

			if (poly->Coef == 0)
			{
				Term *temp = poly;
				poly = poly->Next;
				delete temp;
			}

		}
	}
}




