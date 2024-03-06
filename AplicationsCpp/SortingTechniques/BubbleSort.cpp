#include <stdio.h>

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int A[], int n)
{
	int i, j, isSorted=0;

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


int main()
{
	int A[] = { 3,7,9,10,6,5,12,4,11,2 };
	int n = 10;

	bubbleSort(A, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}