#include <iostream>
using namespace std;


void sort(int &a, int &b, int &c) {
	int temp;
	//cout << "sorting the three number..." << endl;
	if (b > c) {
		temp = c;
		c = b;
		b = temp;
	}

	if (a > b) {
		temp = b;
		b = a;
		a = temp;
	}

	if (a > c) {
		temp = c;
		c = a;
		a = temp;
	}
}

int main() {
	int ifRun = 1;
	int i, j, k;
	while (ifRun) {
		cout << "enter the number" << endl;
		cin >> i >> j >> k;
		cout << "the original order is " << i << "  " << j << "  " << k << endl;

		sort(i, j, k);
		cout << "the resorted order is  " << i << "  " << j << "  " << k << endl;

		cout << "do you want to quit? if so, enter 0. Else, enter 1" << endl;
		cin >> ifRun;

	}
}

