#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Node
{
public:
	Node* lchild;
	int data;
	Node* rchild;
};

class Queue
{
private:
	int front;
	int rear;
	int size;
	Node** q;  //pointer to the array containing the elements

public:
	Queue() {
		size = 10;
		q = new Node*[size];
		rear = -1;
		front = -1;
	}
	Queue(int _size) {
		q = new Node*[_size];
		size = _size;
		rear = -1;
		front = -1;
	}

	void enqueue(Node* x)
	{
		if (rear == size - 1)
		{
			cout << "queue is full!, value will be omitted" << endl;
		}
		else
		{
			rear++;
			q[rear] = x;
		}
	}

	Node* dequeue()
	{
		Node* x = NULL;

		if (front == rear)
			cout << "Queue is empty" << endl;
		else
		{
			front++;
			x = q[front];
		}
		return x;
	}

	void display()
	{
		for (int i = front + 1; i <= rear; i++)
		{
			cout << q[i] << " ";
		}
		cout << endl;
	}

	bool isEmpty()
	{
		return front == rear;
	}
								   
};