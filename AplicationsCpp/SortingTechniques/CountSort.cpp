#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

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

int partition(int A[], int l, int h)
{
	int pivot = A[l];
	int i = l;
	int j = h;

	do
	{
		do { i++; } while (A[i] <= pivot);
		do { j--; } while (A[j] > pivot);

		if (i < j)
			swap(&A[i], &A[j]);

	} while (i < j);

	swap(&A[l], &A[j]);
	return j;
}

void QuickSort(int A[], int l, int h)
{
	int j;

	if (l < h)
	{
		j = partition(A, l, h);
		QuickSort(A, l, j);
		QuickSort(A, j + 1, h);
	}
}

void merge(int A[], int l, int mid, int h)
{
	int i = l, j = mid + 1, k = l;
	int B[100]; //forcing the size

	while (i <= mid && j <= h)
	{
		if (A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}

	for (; i <= mid; i++)
		B[k++] = A[i];
	for (; j <= h; j++)
		B[k++] = A[j];

	for (int i = l; i <= h; i++)
		A[i] = B[i];

}


void IMergeSort(int A[], int n)
{
	int p, l, h, mid, i;

	for (p = 2; p <= n; p = p * 2)
	{
		for (i = 0; i + p - 1 < n; i = i + p)
		{
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;

			merge(A, l, mid, h);
		}
	}
	if (p / 2 < n)
	{
		merge(A, 0, (p / 2) - 1, n);
	}
}

void MergeSort(int A[], int l, int h)
{
	int mid;
	if (l < h)
	{
		mid = (l + h) / 2;
		MergeSort(A, l, mid);
		MergeSort(A, mid + 1, h);
		merge(A, l, mid, h);
	}
}

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

int main()
{
	int A[] = { 3,7,9,10,6,5,12,4,11,2 };
	int n = 10;

	CountSort(A, n);

	//displaying elements
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}