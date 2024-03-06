#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

class IPResQueue
{
private:
	Node* front;
	Node* rear;

public:
	IPResQueue()
	{
		front = NULL;
		rear = NULL;
	}

	void rearEnqueue(int x)
	{
		Node* t = new Node();
		if (t == NULL)
			printf("Queue is FULL\n");
		else
		{
			t->data = x;
			t->next = NULL;
			t->prev = rear;
			if (front == NULL)
				front = rear = t;
			else
			{
				rear->next = t;
				//rear->prev = rear;
				rear = t;
			}
		}
	}

	int frontDequeue()
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

	int rearDequeue()
	{
		int x = -1;
		Node* t = new Node();
		if (rear == NULL)
			printf("Queue is Empty\n");
		else
		{
			x = rear->data;
			t = rear;
			rear = rear->prev;
			rear->next = NULL;
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
	IPResQueue myIPResQueue;

	myIPResQueue.rearEnqueue(10);
	myIPResQueue.rearEnqueue(20);
	myIPResQueue.rearEnqueue(30);
	myIPResQueue.rearEnqueue(40);

	myIPResQueue.display();

	//cout << "After dequeue " << myIPResQueue.frontDequeue() << endl;
	cout << "After rear dequeue " << myIPResQueue.rearDequeue() << endl;
	myIPResQueue.display();
	cout << "After enqueue 50 " << endl;
	myIPResQueue.rearEnqueue(50);
	myIPResQueue.display();



	return 0;
}