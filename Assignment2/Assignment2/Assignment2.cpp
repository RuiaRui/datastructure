// Assignment2.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include "Polynominal.h"


int main()
{
	Polynominal ah, bh, ch;
	ah.inputPoly();      //input polynomial a
	ah.outputPoly();
	bh.inputPoly();      //input polynomial b
	bh.outputPoly();
	ch = ah*bh;
	ch.outputPoly();    //output the result
	system("pause");
	return 0;
}

