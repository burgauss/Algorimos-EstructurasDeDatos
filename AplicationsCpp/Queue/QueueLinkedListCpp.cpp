#include <iostream>
using namespace std;


struct Node
{
	int data;
	struct Node* next;
};

class Queue {

private:
	Node* front;
	Node* rear;

public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	
	void enqueue(int x)
	{
		Node *t = new Node();
		if (t == NULL)
			printf("Queue is FULL\n");
		else
		{
			t->data = x;
			t->next = NULL;
			if (front == NULL)
				front = rear = t;
			else
			{
				rear->next = t;
				rear = t;
			}
		}
	}

	int dequeue()
	{
		int x = -1;
		Node* t = new Node();
		if (front == NULL)
			printf("Queue is Empty\n");
		else
		{
			x = front->data;
			t = front;
			front = front->next;
			free(t);
		}
		return x;
	}

	void display()
	{
		Node* p = front;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

};

int main()
{
	Queue myQueue;
	myQueue.enqueue(10);
	myQueue.enqueue(20);
	myQueue.enqueue(30);

	myQueue.display();

	cout << "dequeue action " << myQueue.dequeue() << endl;

	myQueue.display();

	return 0;
}
