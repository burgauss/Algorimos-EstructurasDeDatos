#pragma once

#include <stdio.h>
#include <cstdlib>
#include <limits.h>

struct Node
{
	int data;
	struct Node* next;
};


void display(struct Node* p)
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
	int m = -INT_MIN;
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



void InsertSorted(struct Node** H, int x)
{
	struct Node* q = NULL;
	struct Node* t = NULL;
	struct Node* p = *H;
	
	t = new Node();
	t->data = x;
	t->next = NULL;

	if (*H == NULL)
	{
		*H = t;
	}
	else
	{
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if (p == *H)
		{
			t->next = *H;
			*H = t;

		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

int Delete(struct Node** H, int key)
{
	struct Node* q = NULL;
	int x = -1;
	struct Node* p = *H;  //header pointer
	int i = 0;
	// getting the position of the key
	while (p && p->data != key)
	{
		q = p;
		p = p->next;
		i++;
	}
	
	int index = i;

	if (index == 0)
	{
		q = p;
		x = p->data;
		*H = p->next;
		delete q;
 		return x;
	}
	else
	{

		q->next = p->next;
		x = p->data;
		delete p;
		return x;

	}

}

//bool IsSorted(struct Node* p)
//{
//	int min = -INT_MAX;
//	p = first;
//
//	while (p != NULL)
//	{
//		if (p->data < min)
//		{
//			return false;
//		}
//		min = p->data;
//		p = p->next;
//
//	}
//	return true;
//}

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



void Concatenate(struct Node* p, struct Node* q)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
}



bool IsLoop(struct Node* f)
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
