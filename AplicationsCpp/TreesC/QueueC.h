#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* lchild;
	int data;
	struct Node* rchild;
};

struct Queue
{
	int size;
	int front;
	int rear;
	Node** Q;

};

void create(struct Queue* q, int size)
{
	q->size = size;
	q->front = q->rear = 0;
	q->Q = (Node**)malloc(q->size * sizeof(Node*));
}

void enqueue(struct Queue* q, Node * x)
{
	if ((q->rear + 1) % q->size == q->front)
		printf("Queue is Full");
	else
	{
		q->rear = (q->rear + 1) % q->size;
		q->Q[q->rear] = x;
	}
}

Node * dequeue(struct Queue* q)
{
	Node* x = NULL;
	if (q->front == q->rear)
		printf("Queue is Empty \n");
	else
	{
		q->front = (q->front + 1) % q->size;
		x = q->Q[q->front];
	}
	return x;
}

//void display(struct Queue q)
//{
//
//	for (int i = q.front + 1; i <= q.rear; i++)
//	{
//		printf("%d ", q.Q[i]);
//	}
//
//	printf("\n");
//
//}

int isEmpty(struct Queue q)
{
	return q.front == q.rear;
}

///cpp version of the Queue Class
//class Queue
//{
//private:
//	int front;
//	int rear;
//	int size;
//	Node** Q;  //pointer to a an array of node pointers
//
//public:
//	Queue() {
//		size = 10;
//		//q = new Node*[size];
//		Q = (Node**)malloc(size * sizeof(Node*));
//		rear = -1;
//		front = -1;
//	}
//
//	Queue(int _size) {
//		//q = new int[_size];
//		Q = (Node**)malloc(size * sizeof(Node*));
//		size = _size;
//		rear = -1;
//		front = -1;
//	}
//
//	void enqueue(Node* x)
//	{
//		if (rear == size - 1)
//		{
//			cout << "queue is full!, value will be omitted" << endl;
//		}
//		else
//		{
//			rear++;
//			Q[rear] = x;
//		}
//	}
//
//	Node* dequeue()
//	{
//		Node* x = NULL;
//
//		if (front == rear)
//			cout << "Queue is empty" << endl;
//		else
//		{
//			front++;
//			x = Q[front];
//		}
//		return x;
//	}
//
//
//	int isEmpty()
//	{
//		return 	front == rear;
//	}
//
//};