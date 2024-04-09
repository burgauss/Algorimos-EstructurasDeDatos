#include <stdlib.h>
#include <stdio.h>

int findMax(int A[], int n)
{
	int max = -INT_MAX;
	int i;
	for (i = 0; i < n; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

void CountSort(int A[], int n)
{
	int i, j, max, * C;

	max = findMax(A, n);
	C = (int*)malloc(sizeof(int) * max + 1);
	for (i = 0; i < max + 1; i++)
	{
		C[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		C[A[i]]++;
	}

	i = 0;
	j = 0;
	while (j < max + 1)
	{
		if (C[j] > 0)
		{
			A[i++] = j;
			C[j]--;
		}
		else
			j++;
	}

}

void ShellSort(int A[], int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap >= 1; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			temp = A[i];
			j = i - gap;
			while (j >= 0 && A[j] > temp)
			{
				A[j + gap] = A[j];
				j = j - gap;
			}
			A[j + gap] = temp;
		}

	}
}

int main()
{
	int A[] = { 11, 12, 7, 13, 16, 9, 24, 5, 10, 3 };
	int n = 10;
	int i;

	ShellSort(A, n);

	for (i = 0; i < 10; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}