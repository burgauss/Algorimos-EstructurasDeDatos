#include <iostream>

using namespace std;

int f(int& x, int c)
{
	c = c - 1;
	if (c == 0) return 1;
	x = x + 1;
	return f(x, c) * x;
}



int main()
{
	int a = 0;
	for (a = 1; a < 2; a++)
	{
		cout << a << endl;
	}
	//int p = 5;
	//int res = f(p, p);
	//cout << res << endl;
	return 0;
}