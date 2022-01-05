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
	
	Queue(int maxSize = 0);
	~Queue();
	bool enQueue(int val);
	bool dequeue(int &val);
	bool isFull();
	bool isEmpty();
	Queue & operator=(const Queue & ref);
	
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
	q = new int [maxsize];
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


Queue & Queue::operator=(const Queue & ref)
{
	if (!ref.q)
	{
		this->~Queue();
		back = 0;
		front = 0;
		maxsize = 0;
		currentSize = 0;
		return *this;

	}
	this->~Queue();
	q = new int[ref.maxsize];
	maxsize = ref.maxsize;

	for (int j = 0, i = ref.front; j < ref.currentSize; j++)
	{
		q[j] = ref.q[i];
		i = (i + 1) % ref.maxsize;
	}

	front = 0;
	currentSize = ref.currentSize;
	back = ref.currentSize % maxsize;
	return *this;

}
int main()
{
	Queue a(5);
	
	for (int i = 0; i < 5; i++)
	{
		a.enQueue(i);
	}

	Queue b;
	b = a;

	
	int temp;
	while (!(b.isEmpty()))
	{
		b.dequeue(temp);
		cout<<temp<<" ";
	}
	
	
	return 0;
}


