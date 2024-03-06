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
		rear = 0;
		front = 0;
	}
	Queue(int _size) {
		q = new int[_size];
		size = _size;
		rear = 0;
		front = 0;
	}

	void enqueue(int x)
	{
		if ((rear + 1)%size == front)
		{
			cout << "queue is full!, value will be omitted" << endl;
		}
		else
		{
			rear = (rear +1)%size;
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
			front = (front+1)%size;
			x = q[front];
		}
		return x;
	}

	void display()
	{
		int i = front + 1;
		do
		{
			cout << q[i] << " ";
			i = (i + 1) % size;
		} while (i != (rear + 1) % size);
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
	myQueue.display();
	cout << "Dequeue value " << myQueue.dequeue() << endl;
	cout << "Dequeue value " << myQueue.dequeue() << endl;
	cout << "Dequeue value " << myQueue.dequeue() << endl;

	myQueue.enqueue(20);
	myQueue.display();
	return 0;
}