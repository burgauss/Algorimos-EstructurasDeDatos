#include <iostream>

using namespace std;

double e(int x, int n)
{
	static double p = 1;
	static double f = 1;
	double r;
	if (n == 0)
		return 1;
	else
	{
		r = e(x, n - 1);
		p = p * x;
		f = f * n;
		return r + p / f;
	}
}

double eIterative(double x, int n)
{
	double s = 1.0;

	for (;n > 0; n--)
	{
		s = 1 + (x / n) * s;
	}
	return s;
}

int main()
{
	double res = eIterative(3, 10);
	cout << res << endl;
	return 0;
}