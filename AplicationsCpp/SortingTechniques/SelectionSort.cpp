#include <stdio.h>

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int A[], int n)
{
	int i, j, isSorted = 0;

	for (i = 0; i < n - 1; i++)
	{
		isSorted = 0;
		for (j = 0; j < n - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(&A[j], &A[j + 1]);
				isSorted = 1;
			}
		}

		if (isSorted == 0)
			break;
	}
}

void insertionSort(int A[], int n)
{
	int i, j, x;

	for (i = 1; i < n; i++)
	{
		j = i - 1;
		x = A[i];

		while (j > -1 && A[j] > x)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;

	}
}

void selectionSort(int A[], int n)
{
	int i, j, k;

	for (i = 0; i < n - 1; i++)
	{
		for (j = k = i; j < n; j++)
		{
			if (A[j] < A[k])
				k = j;
		}
		swap(&A[i], &A[k]);
	}
}


int main()
{
	int A[] = { 3,7,9,10,6,5,12,4,11,2 };
	int n = 10;

	selectionSort(A, 10);

	//displaying elements
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}