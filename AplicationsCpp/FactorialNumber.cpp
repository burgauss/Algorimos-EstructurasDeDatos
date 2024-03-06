#include <iostream>
using namespace std;


int factorial(int n)
{
	int res = 1;
	if (n > 1)
	{
		res = n * factorial(n - 1);
		return res;
	}
	return 1;
}

int main()
{
	int res = factorial(3);
	cout << res << endl;
	return 0;
}
