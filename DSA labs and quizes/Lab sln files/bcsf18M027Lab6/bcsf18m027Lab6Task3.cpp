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
	Queue & operator=(const Queue & ref);
	bool isQueuesIdentical(Queue & b);
};

Queue::Queue(int maxSize)
{
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


bool Queue::isQueuesIdentical(Queue & b)
{
	if (currentSize != b.currentSize)
	{
		return false;
	}
	else
	{
		int cnt = 0;
		for (int i = front, counter = 0; counter < currentSize; counter++)
		{
			for (int j = b.front, counter1 = 0; counter1 < b.currentSize; counter1++)
			{
				if (q[i] == b.q[j])
				{
					cnt = cnt + 1;
				}
				j = (j + 1) % b.maxsize;
			}
			i = (i + 1) % maxsize;
		}
		return cnt == currentSize;
	}


}

int main()
{
	
	Queue a(5);
	Queue b(5);

	//   here i inset same data in both quque  

	for (int i = 4; i >= 0; i--)
	{
		a.enQueue(i);

	}

	for (int i = 0; i < 5; i++)
	{

		b.enQueue(i);
	}

	//   printing returning bool value from function

	cout << a.isQueuesIdentical(b);


	return 0;
}
