#include <stdio.h>
#include <cstdlib>
#include <limits.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}*first = NULL;

void create(int A[], int n)
{
	struct Node* t, * last;
	int i;

	first = new Node();	  
	first->data = A[0];
	first->prev = first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = last->next;
		t->prev = last;
		last->next = t;
		last = t;
	}

}

void display(struct Node* p)
{
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int lenght(struct Node* p)
{
	int len = 0;

	while (p)
	{
		len++;
		p = p->next;
	}

	return len;

}


void insert(struct Node* p, int index, int x)
{
	struct Node* t;
	int i;

	if (index < 0 || index > lenght(p))
		return;

	if (index == 0)
	{
		t = new Node();
		t->data = x;
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		t = new Node();
		t->data = x;
		t->prev = p;
		t->next = p->next;
		if (p->next) p->next->prev = t;
		p->next = t;
	}
}


int main()
{
	int A[] = { 1,2,3,4,5 };
	create(A, 5);
	printf("the lenght is %d \n", lenght(first));
	display(first);
	printf("\n");
	insert(first, 0, 25);
	display(first);


	return 0;
}