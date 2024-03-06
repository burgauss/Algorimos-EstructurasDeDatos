#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lonelyinteger(vector<int> a) {
	int len = a.size();
	bool SingleNumberFound = false;
	int pivot = 0;
	
	for (int i = 0; i < len; i++)
	{
		pivot = a[i];
		int j = i+1;
		SingleNumberFound = true;
		for (j; j < len ; j++)
		{
			if (pivot == a[j])
			{
				SingleNumberFound = false;
				a.erase(a.begin() + j);
				len = a.size();
				break;
			}
		}
		if (SingleNumberFound )
			break;
	}
	return pivot;
}

int main()
{
	//vector<int> arr{ 1,2,3,4,3,2,1 };
	vector<int> arr{1,1,2};
	//vector<int> arr{ 84,48,13,20,61,20,33,97,34,45,6,63,71,66,24,57,92,74,6,25,51,86,48,15,64,55,77,30,56,53,37,99,9,59,57,61,30,97,50,63,59,62,39,32,34,4,96,51,8,86,10,62,16,55,81,88,71,25,27,78,79,88,92,50,16,8,67,82,67,37,84,3,33,4,78,98,39,64,98,94,24,82,45,3,53,74,96,9,10,94,13,79,15,27,56,66,32,81,77 };
	int Singlenumb = lonelyinteger(arr);
	cout << "the number is " << Singlenumb;
	return 0;
}