#include <iostream>
using namespace std;


int powersOf2(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1) {
		cout << 1 << endl;
		return 1;
	}
	else {
		int prev = powersOf2(n / 2);
		int curr = prev * 2;
		cout << curr << endl;
		return curr;
	}
}

int main()
{
	powersOf2(8);
	return 0;
}