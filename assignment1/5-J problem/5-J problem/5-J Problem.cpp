

#include <iostream>

using namespace std;
void main()
{
	int N = 0, M = 0;
	cout << "Please enter the number of people:N=";
	cin >> N;
	cout << "Please enter:M=";
	cin >> M;
	int i = 0, j = 0, n = N, s = 0;
	
	//定义数列 1代表元素仍然存在
	int *a = new int[N];
	for (i = 0; i<N; i++)
	{
		a[i] = 1;
	}

	while (0 != n)
	{
		s += a[j];  //不用循环判断改元素是否依然存在
		/*if (a[j] == 1) {
			s += 1; 
		}*/
		if (M == s)
		{
			a[j] = 0;
			s = 0;
			--n;
			if (0 != n)
			{
				cout << j + 1 << "->";
			}
			else
			{
				cout << j + 1 << endl;
			}
		}
		j = (j + 1) % N;   //j=j+1 同时若在队列尾部则回到队列头
		/*j += 1;
		j = j%N;*/
	}

	delete[]a;
}


