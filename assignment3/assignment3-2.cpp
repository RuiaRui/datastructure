#include<iostream>  

using namespace std;

void display(int num, int* arr, int n);

int* final;




void main()
{
	int n;
	cout << "Input a positive integer(n>3)" << endl;
	cin >> n;
	int* arr = new int[n + 1];
	display(1, arr, n);

	if (final == NULL) {
		cout << "there is no possible sequence" << endl;
	}//û�п�������
		
	system("pause");
	
	
}

void display(int num, int* arr, int n) {
	if (num == n+1 ) {

		 final = new int[2*n+1];

		//for debug
		//cout << "debug" << endl;
		//for (int i = 1; i < n + 1; i++) {
		//	cout << arr[i] << " ";
		//}
		//cout << endl;

		for (int i = 1; i <= n; i++) {
			final[arr[i]] = final[arr[i] + i + 1] = i;
		}

		for (int i = 1; i < 2*n + 1; i++) {
			cout << final[i] << " ";
		}
		cout << endl;
		

		
	}//������


	else {

		for (int pos = 1; pos + num + 1 <2*n+1; pos++) {
			bool settle = true;
			arr[num] = pos;


			for (int i = 1; i < num; i++) {

				if (pos == arr[i] || pos == arr[i] + i+ 1||pos + num + 1 == arr[i]|| pos + num + 1 == arr[i] + i + 1) {
					settle = false;
					break;
				}
			}//����Ƿ����ظ�Ԫ��
			if (settle) {
				display(num + 1, arr, n);
			}
		}
	}
}
