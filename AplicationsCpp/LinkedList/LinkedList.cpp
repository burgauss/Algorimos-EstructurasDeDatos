#include <stdio.h>
#include <cstdlib>
#include <limits.h>

struct Node
{
	int data;
	struct Node* next;
}*first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
	int i;
	struct Node* t, *last;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t= (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void create2(int A[], int n)
{
	int i;
	struct Node* t, * last;
	second = (struct Node*)malloc(sizeof(struct Node));
	second->data = A[0];
	second->next = NULL;
	last = second;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void display(struct Node *p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

int count(struct Node* p)
{
	if (p == NULL)
		return 0;
	else
		return count(p->next) + 1;
}

int sum(struct Node* p)
{
	int sum = 0;
	while (p)
	{
		sum = sum + p->data;
		p = p->next;
	}
	return sum;
}

int max(struct Node* p)
{
	int m = - INT_MIN;
	while (p)
	{
		if (p->data > m)
		{
			m = p->data;
		}
		p = p->next;
	}
	return m;
}

int min(struct Node* p)
{
	int m = INT_MAX;
	while (p)
	{
		if (p->data < m)
		{
			m = p->data;
		}
		p = p->next;
	}
	return m;
}

Node* Search(Node* p, int key)
{
	while (p != NULL)
	{
		if (key == p->data)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

Node* SearchMoveToHead(Node* p, int key)
{
	struct Node* q = new Node();
	while (p != NULL)
	{
		if (key == p->data)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}

void Insert(struct Node *p, int pos, int x)
{
	Node* t;
	if (pos < 0 || pos > count(p))
		return;

	t = new Node();
	t->data = x;
	
	if (pos == 0)
	{
		t->next = first;
		first = t;
	}
	else if (pos > 0)
	{
		for (int i = 0; i < pos - 1; i++)
		{
			p = p->next;
		}

		t->next = p->next;
		p->next = t;
		
	}
}

void InsertSorted(struct Node* p, int x)
{
	struct Node* q = NULL;
	struct Node* t = NULL;
	t = new Node();
	t->data = x;
	t->next = NULL;

	if (first == NULL)
	{
		first = t;
	}
	else
	{
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			t->next = first;
			first = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

int Delete(struct Node* p, int index)
{
	struct Node* q = NULL;
	int x = -1;

	if (index < 1 || index > count(p))
		return -1;
	if (index == 1)
	{
		q = first;
		x = first->data;
		first = first->next;
		delete q;
		return x;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;

		}
		q->next = p->next;
		x = p->data;
		delete p;
		return x;

	}

}

bool IsSorted(struct Node* p)
{
	int min = - INT_MAX;
	p = first;

	while (p != NULL)
	{
		if (p->data < min)
		{
			return false;
		}
		min = p->data;
		p = p->next;

	}
	return true;
}

void RemoveDuplicates(struct Node* p)
{
	struct Node* q = p->next;
	
	while (q != NULL)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			q = q->next;
		}
	}
}

void Reverse(struct Node* p)
{
	Node * q = NULL;
	Node * r = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
			
	}

	first = q;
}

void ReverseRecursive(Node* q, Node * p)
{
	if (p != NULL)
	{
		ReverseRecursive(p, p->next);
		p->next = q;
	}
	else
	{
		first = q;
	}
}

void Concatenate(struct Node* p, struct Node* q)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
}

void Merge(struct Node* p, struct Node* q)
{
	struct Node* last;
	if (p->data < q->data)
	{
		third = last = p;
		p = p->next;
		third->next = NULL;
	}  	
	else
	{
		third = last = q;
		q = q->next;
		third->next = NULL;
	}

	while (p && q)
	{
		if (p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}

	if (p)
	{
		last->next = p;
	}
	if (q)
	{
		last->next = q;
	}

}

bool IsLoop(struct Node *f)
{
	struct Node* p, * q;
	p = q = f;

	do
	{
		p = p->next;
		q = q->next;
		q = q ? q->next : q;
	} while (p && q && p != q);

	if (p == q)
		return true;
	else
		return false;
}

int main()
{
	struct Node* t1, * t2;
	int A[] = { 3,3,5,7,10,15 };
	create(A, 6	);

	//t1 = first->next->next;
	//t2 = first->next->next->next->next;
	//t2->next = t1;

	printf("%d", IsLoop(first));

	//display(first);
	//printf("\n");
	//display(second);

	//Merge(first, second);
	//printf("\n");
	//display(third);
	//printf("the count is %d \n", count(first));
	//printf("the sum is %d \n", sum(first));
	//printf("the max element is %d \n", max(first));
	//printf("the min element is %d \n", min(first));

	//Node* myP = SearchMoveToHead(first, 9);
	//if (myP)
	//{
	//	printf("the value was found %d \n", myP->data);
	//}
	//else
	//{
	//	printf("the value was not found \n");
	//}
	
	//InsertSorted(first, 11);
	//InsertSorted(first, 15);
	//InsertSorted(first, 20);
	//InsertSorted(first, 25);
	//InsertSorted(first, 17);
	//InsertSorted(first, 35);
	//display(first);
	//ReverseRecursive(NULL,first);
	//printf("\n");
	//display(first);
	//printf("\nIs linked list sorted %s", IsSorted(first)? "true": "false");
	//printf("inserting element 5 in position 4 \n");
	//Insert(first, 0, 5);


	return 0;
}