#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int A[10] = {2,4,6,8,10 };
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << A[i] << endl;
	//}
	for (int x : A)
	{
		cout << x << endl;
	}

	return 0;
}