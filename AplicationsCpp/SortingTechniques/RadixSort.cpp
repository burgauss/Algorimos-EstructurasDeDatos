#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <cmath>

class Node
{
public:
	int data;
	Node* next;
};


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

int countDigits(int x) {  /// This Function Counts the Digits
	int count = 0;  /// Initialize the count to 0
	while (x != 0) { /// repeat until 0 
		x = x / 10;   /// divide to get the Quotient
		count++; /// increment the count
	}
	return count;  /// return the count
}

void Insert(Node** ptrBins, int val, int idx)
{
	Node* t = new Node();
	t->data = val;
	t->next = NULL;

	if (ptrBins[idx] == NULL)
	{
		ptrBins[idx] = t;
	}
	else
	{
		Node* p = ptrBins[idx];
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = t;
	}
}

int Delete(Node** ptrBins, int val)
{
	Node* p = ptrBins[val];	  //ptrBins[val] is head ptr
	ptrBins[val] = ptrBins[val]->next;
	int x = p->data;
	delete p;
	return x;
}

void RadixSort(int A[], int n)
{
	Node** Bins = new Node*[10];

	int max = findMax(A, n);
	int nPass = countDigits(max);

	for (int i = 0; i < 10; i++)
	{
		Bins[i] = NULL;
	}

	for (int pass = 0; pass < nPass; pass++)
	{
		for (int i = 0; i < n; i++)
		{
			int binIdx = (int)(A[i] / pow(10, i)) % 10;
			Insert(Bins, A[i], binIdx);

		}

		int i = 0;
		int j = 0;
		while (i < 10)
		{
			while (Bins[i] != NULL)
			{
				A[j++] = Delete(Bins, i);
			}
			i++;
		}
		for (int i = 0; i < n; i++)
		{
			Bins[i] = NULL;
		}

	}
	delete[] Bins;

}

int main()
{
	int A[] = { 3,3,7,9,10,6,5,12,4,11,2 };
	int n = 11;

	RadixSort(A, n);

	//displaying elements
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d ", A[i]);
	//}
	//printf("\n");

	return 0;
}