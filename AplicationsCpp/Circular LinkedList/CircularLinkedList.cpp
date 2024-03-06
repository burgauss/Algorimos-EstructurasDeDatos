#include <stdio.h>
#include <cstdlib>
#include <limits.h>

struct Node
{
	int data;
	struct Node* next;
}*Head = NULL;

void create(int A[], int n)
{
	int i;
	struct Node* t, *last;
	Head = new Node;
	Head->data = A[0];
	Head->next = Head;
	last = new Node;
	last = Head;

	for (i = 1; i < n; i++)
	{
		t = new Node();
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}

}

void display(struct Node* h)
{
	do
	{
		printf("%d ", h->data);
		h = h->next;
	} while (h != Head);
	printf("\n");
}


int main()
{
	int A[] = { 2,3,4,5,6 };
	create(A, 5);

	display(Head);

	return 0;
}
