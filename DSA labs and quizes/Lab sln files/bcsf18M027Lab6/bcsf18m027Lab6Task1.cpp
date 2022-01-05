#include<iostream>
using namespace std;



struct Queue
{
	int * q;
	int back;
	int front;
	int maxsize;
	int currentSize;

public:

	Queue(int maxSize);
	~Queue();
	bool enQueue(int val);
	bool dequeue(int &val);
	bool isFull();
	bool isEmpty();


};

Queue::Queue(int maxSize)
{
	if (maxSize == 0)
	{
		back = 0;
		front = 0;
		q = nullptr;
		currentSize = 0;
	}
	back = 0;
	front = 0;
	maxsize = maxSize;
	currentSize = 0;
	q = new int[maxsize];
}

Queue::~Queue()
{
	if (!q)
	{
		return;
	}

	//cout << " nomi ";
	delete[] q;
	q = nullptr;
}

bool Queue::enQueue(int val)
{
	if (isFull())
	{
		return false;
	}
	q[back] = val;
	back = (back + 1) % maxsize;
	currentSize++;
	return true;
}

bool Queue::dequeue(int & val)
{
	if (isEmpty())
	{
		return false;
	}
	val = q[front];
	front = (front + 1) % maxsize;
	currentSize--;
	return true;
}

bool Queue::isEmpty()
{
	return currentSize == 0;
}

bool Queue::isFull()
{
	return currentSize == maxsize;

}


int main()
{
	Queue a(5);

	for (int i = 0; i < 5; i++)
	{
		a.enQueue(i);
	}

	cout << "a.isEmpty() :" << a.isEmpty() << "\n";
	cout << "a.isFull() :" << a.isFull() << "\n\n";

	int temp;
	for (int i = 0; i < 5; i++)
	{
		a.dequeue(temp);
		cout << temp << " ";
	}

	cout << "\n\na.isEmpty() :" << a.isEmpty() << "\n";
	cout << "a.isFull() :" << a.isFull() << "\n";


	return 0;
}

