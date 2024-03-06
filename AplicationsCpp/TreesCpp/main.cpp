
#include "QueueCpp.h"
#include <iostream>
#include <stdio.h>

class Tree
{
public:
	Node* root;
	Tree() { root = NULL; }
	void CreateTree();
	void Preorder(Node* p);
	void Postorder(Node* p);
	void Inorder(Node* p);
	void LevelOrder(Node* p);
	int Height(Node* root);
	int count( Node* root);
};

void Tree::CreateTree()
{
	Node* p, * t;
	int x;
	Queue q(100);


	printf("Enter Root Value ");
	scanf_s("%d", &x);
	root = new Node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	q.enqueue(root);

	while (!q.isEmpty())
	{
		p = q.dequeue();
		printf("enter left child of %d ", p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			q.enqueue(t);
		}

		printf("enter right child of %d ", p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			q.enqueue(t);
		}

	}
}

void Tree::Preorder(Node* p)
{
	if (p)
	{
		printf("%d ", p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void Tree::Inorder(Node* p)
{
	if (p)
	{
		Inorder(p->lchild);
		printf("%d ", p->data);
		Inorder(p->rchild);
	}
}

void Tree::Postorder( Node* p)
{
	if (p)
	{
		Postorder(p->lchild);
		Postorder(p->rchild);
		printf("%d ", p->data);
	}
}

void Tree::LevelOrder( Node* root)
{
	Queue q(100);

	printf("%d ", root->data);
	q.enqueue(root);

	while (!q.isEmpty())
	{
		root = q.dequeue();
		if (root->lchild)
		{
			printf("%d ", root->lchild->data);
			q.enqueue(root->lchild);
		}
		if (root->rchild)
		{
			printf("%d ", root->rchild->data);
			q.enqueue(root->rchild);
		}
	}

}

int Tree::Height( Node* root)
{
	int x = 0, y = 0;
	if (root == 0)
		return 0;
	x = Height(root->lchild);
	y = Height(root->rchild);
	if (x > y)
		return x + 1;
	else
		return y + 1;
}

int Tree::count(struct Node* root)
{
	if (root)
		return count(root->lchild) + count(root->rchild) + 1;
	return 0;
}





int main()
{
	Tree t;			 
	t.CreateTree();
	printf("Count %d ", t.count(t.root));
	printf("\n");
	printf("Height %d ", t.Height(t.root));

	return 0;
}