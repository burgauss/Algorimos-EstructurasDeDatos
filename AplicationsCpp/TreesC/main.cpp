#include <stdlib.h>
#include <stdio.h>
#include "QueueC.h"

using namespace std;

struct Node* root = NULL;

void Treecreate()
{
	struct Node* p, * t;
	int x;
	struct Queue q;
	create(&q, 100);

	printf("Enter Root Value ");
	scanf_s("%d", &x);
	root = (struct Node*)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q, root);

	while (!isEmpty(q))
	{
		p = dequeue(&q);
		printf("enter left child of %d ", p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			printf("Address of t %d ", &t);
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			enqueue(&q, t);
		}

		printf("enter right child of %d ", p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			printf("Address of t %d ", &t);
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			enqueue(&q, t);
		}

	}
}


void preorder(struct Node* p)
{
	if (p)
	{
		printf("%d ", p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(struct Node* p)
{
	if (p)
	{
		inorder(p->lchild);
		printf("%d ", p->data);
		inorder(p->rchild);
	}
}

void postorder(struct Node* p)
{
	if (p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d ", p->data);
	}
}

int main()
{
	Treecreate();
	preorder(root);
	printf("\nPost Order ");
	postorder(root);
	



	return 0;
}