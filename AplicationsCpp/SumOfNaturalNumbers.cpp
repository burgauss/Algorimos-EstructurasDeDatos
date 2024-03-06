#include <iostream>

using namespace std;

int total = 0;
int sum(int n)
{
	if (n > 1)
	{
		total = n + sum(n - 1);
		return total;
	} return 1;

}

int sumProfe(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return sum(n - 1) + n;
	}
}

int sumFormule(int n)
{
	return n * (n + 1) / 2;
}
int main()
{
	int res = sumFormule(5);
	cout << res << endl;
	return 0;
}