/// this code print n numbers of fibonaci series using memonization
#include <iostream>
using namespace std;

int fib(int n, int* memo);

void allFib(int n)
{
	int *memo = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		cout << i << " : " << fib(i, memo) << endl;
	}
}

int fib(int n, int* memo)
{
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	else if (memo[n] > 0) return memo[n];

	memo[n] = fib(n - 1, memo) + fib(n - 2, memo);

	return memo[n];
}



int main()
{
	allFib(10);
	return 0;
}