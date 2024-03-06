#include <iostream>
#include <vector>

using namespace std;


int getNextMultiple(int _grade)
{
	int residual = _grade % 5;
	return _grade + 5 - residual;
}
/*
*Complete the 'gradingStudents' function below.
*
*The function is expected to return an INTEGER_ARRAY.
* The function accepts INTEGER_ARRAY grades as parameter.
*/

vector<int> gradingStudents(vector<int> grades) {
	int maxGrade = 100;
	int minGrade = 38;
	vector<int> newGrades;
	for (int i=0; i< grades.size(); i++)
	{
		if (grades[i] < minGrade || grades[i] >= maxGrade)
		{
			newGrades.push_back(grades[i]);
		}
		else
		{
			int nextMultiple5 = getNextMultiple(grades[i]);
			if (nextMultiple5 - grades[i] < 3)
			{
				newGrades.push_back(nextMultiple5);
			}
			else
			{
				newGrades.push_back(grades[i]);
			}
		}
	}
	return newGrades;
}



int main()
{
	vector<int> grades = { 100,89,88,70,55,20 };
	vector<int> newGrades = gradingStudents(grades);
	cout << "original grades: ";
	for (int x : grades)
	{
		cout << x << " ";
	}
	cout << endl << "the new grades are: ";
	for (int x : newGrades)
	{
		 cout << x << " ";
	}
	
	return 0;
}
