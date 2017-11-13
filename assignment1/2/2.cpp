#include <iostream>
using namespace std;
int main() {
	//cout << "Hello, World!" << endl;
	

	char c = '6';
	const int &rc = c;
	int i = 8;
	const int &ri = i;

	cout << &rc << endl;
	cout << &c << endl;
	//if (&rc == &c) { cout << "&rc=&c" << endl; }

	cout << &ri << endl;
	cout << &i << endl;

	if (&ri == &i) { cout << "&ri=&i" << endl; }

	getchar();
}