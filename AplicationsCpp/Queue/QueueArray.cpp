#include <stdlib.h>
#include <iostream>

using namespace std;

class Queue
{
private:
	int front;
	int rear;
	int size;
	int* q;  //pointer to the array containing the elements

public:
	Queue() {
		size = 10;
		q = new int[size];
		rear = -1;
		front = -1;
	}
	Queue(int _size) {
		q = new int[_size];
		size = _size;
		rear = -1;
		front = -1;
	}

	void enqueue(int x)
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

	int dequeue()
	{
		int x = -1;

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
		for (int i = front+1; i <= rear; i++)
		{
			cout << q[i] << " ";
		}
		cout << endl;
	}

};

int main()
{
	Queue myQueue(5);
	myQueue.enqueue(3);
	myQueue.enqueue(2);
	myQueue.enqueue(1);
	myQueue.enqueue(0);
	myQueue.enqueue(8);
	myQueue.display();
	cout <<"Dequeue value " << myQueue.dequeue() << endl;
	cout <<"Dequeue value " << myQueue.dequeue() << endl;
	cout <<"Dequeue value " << myQueue.dequeue() << endl;
	
	myQueue.enqueue(20);
	myQueue.display();
	return 0;
}