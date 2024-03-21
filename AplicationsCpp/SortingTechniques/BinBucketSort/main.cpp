#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Node
{
	int data;
	int pos;
	struct Node* next;
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


void Insert(Node ** ptrBins, int val)
{
	Node* t = new Node();
	t->data = val;
	t->next = NULL;

	if (ptrBins[val] == NULL)
	{	
		ptrBins[val] = t;
	}
	else 
	{
		Node* p = ptrBins[val];
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

void BinBucketSort(int A[], int n)
{
	int max, i, j;

	Node** Bins;

	max = findMax(A, n);

	Bins = new Node * [max + 1];

	for (i = 0; i < max + 1; i++)
	{
		Bins[i] = NULL;
	}

	//TODO: Missing implementation del metodo insert
	for (i = 0; i < n; i++)
	{
		Insert(Bins, A[i]);

	}

	i = 0;
	j = 0;
	while (i < max + 1)
	{
		while (Bins[i] != NULL)
		{
			A[j++] = Delete(Bins, i);
		}
		i++;
	}

	delete[] Bins;


}

int main()
{
	int A[] = { 3,3,7,9,10,6,5,12,4,11,2 };
	int n = 11;

	BinBucketSort(A, n);

	//displaying elements
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}