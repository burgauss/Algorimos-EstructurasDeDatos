#include<iostream>
#include<stdio.h>
#include<string>
#include <vector>

using namespace std;

vector<int> breakingRecords(vector<int> scores)
{
	int leastPointRecords = 0;
	int mostPointsRecords = 0;
	int minimum = scores[0];
	int maximum = scores[0];

	for (int score : scores)
	{
		if (score > maximum)
		{
			mostPointsRecords += 1;
			maximum = score;
		}
		else if (score < minimum)
		{
			leastPointRecords += 1;
			minimum = score;
		}
	}

	vector<int> records{ mostPointsRecords, leastPointRecords };
	return records;
}


int main()
{
	vector<int> scores{ 3, 4, 21, 36, 10, 28, 35, 5, 24, 42 };
	vector<int> result = breakingRecords(scores);
	cout << result[0] << " " << result[1] << endl;
	return 0;
}