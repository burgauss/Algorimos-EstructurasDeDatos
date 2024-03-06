#include <stdlib.h>
#include <stdio.h>
#include "QueueC.h"
#include "Stack.h"

using namespace std;

struct Node* root = NULL;

void Treecreate()
{
	struct Node* p, * t;
	int x;
	struct Queue q;
	createQueue(&q, 100);

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
			//printf("Address of t %d ", &t);
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
			//printf("Address of t %d ", &t);
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

void IPreorder(struct Node* p)
{
	struct Stack stk;
	StackCreate(&stk, 100);

	while (p || !isEmptyStack(stk))
	{
		if (p)
		{
			printf("%d ", p->data);
			push(&stk, p);
			p = p->lchild;
		}
		else
		{
			p = pop(&stk);
			p = p->rchild;
		}
	}
}

void IInorder(struct Node* p)
{
	struct Stack stk;
	StackCreate(&stk, 100);

	while (p || !isEmptyStack(stk))
	{
		if (p)
		{
			push(&stk, p);
			p = p->lchild;
		}
		else
		{
			p = pop(&stk);
			printf("%d ", p->data);
			p = p->rchild;
		}
	}
}

void LevelOrder(struct Node* root)
{
	struct Queue q;
	createQueue(&q, 100);

	printf("%d ", root->data);
	enqueue(&q, root);

	while (!isEmpty(q))
	{
		root = dequeue(&q);
		if (root->lchild)
		{
			printf("%d ", root->lchild->data);
			enqueue(&q, root->lchild);
		}
		if (root->rchild)
		{
			printf("%d ", root->rchild->data);
			enqueue(&q, root->rchild);
		}
	}
}


int main()
{
	Treecreate();
	printf("\nLevel Order \n");
	LevelOrder(root);
	



	return 0;
}