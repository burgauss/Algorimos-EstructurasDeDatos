#include <iostream>

using namespace std;
int counter = 0;

int TOH(int n, int A, int B, int C)
{
	if (n > 0)
	{
		TOH(n - 1, A, C, B);
		printf("from %d to %d \n", A, C);
		counter++;
		TOH(n - 1, B, A, C);
	}
	return counter;
}


int fun(int n)
{
	int j = 0;
	j = n / 10;
	return j;
}

int main()
{
	//int counts = TOH(3, 1, 2, 3);
	//printf("total number of steps: %d", counts);
	int res = fun(2048);
	cout << res << endl;

	return 0;
}