#include <iostream>
using namespace std;


class Test

{

	char cT;

public:

	Test(char c)

	{

		cT = c;

		cout << "Test::Test()  for " << c << endl;

	}

	~Test()

	{

		cout << "Test::~Test() for " << cT << endl;

	}

};



Test A('A'); //ȫ�ֶ�����main֮ǰ����
Test B('B');


void foo()
{
	Test C('C');
	Test D('D');
}



int main()

{

	cout << "inside  main()" << endl;

	foo();
	
	cout << "leaving main()" << endl;
	
	return 0;

	system("pause");
}

