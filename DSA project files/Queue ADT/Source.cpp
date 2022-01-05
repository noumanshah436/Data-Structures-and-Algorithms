#include<iostream>
using namespace std;

template <typename T>
class Queue
{
	T * data;
	int rear;   //  index where next val is palced
	int front;
	int capacity;
	int noOfElements;
	void reSize(int newSize);
public:
	Queue();
	~Queue();
	void enQueue(T val);
	T deQueue();
	bool isFull();
	bool isEmpty();
	T getElementAtFront();
	int getNoOfElements();
	int getCapacity();

	Queue(const Queue<T> & ref);
	Queue<T> operator=(const Queue<T> & ref);

};

template<typename T>
int Queue<T>::getCapacity()
{
	return capacity;
}

template<typename T>
int Queue<T>::getNoOfElements()
{
	return noOfElements;
}

template<typename T>
T Queue<T>::getElementAtFront()
{
	if (isEmpty())
	{
		throw exception();
	}
	return data[front];
}


template<typename T>
void Queue<T>::reSize(int newSize)
{
	T*temp = new T[newSize];
	for (int j = 0, i = front; j < noOfElements; j++)
	{
		temp[j] = data[i];
		i = (i + 1) % capacity;
	}
	this->~Queue();
	data = temp;
	//temp = nullptr;
	rear = noOfElements;
	front = 0;
	capacity = newSize;

	

}

template<typename T>
T Queue<T>::deQueue()
{
	if (isEmpty())
	{
		throw exception();
	}
	T val = data[front];
	front = (front + 1) % capacity;
	noOfElements--;
	if (noOfElements > 0 && (noOfElements == (capacity / 4)))
	{
		reSize(capacity / 2);
	}
	return val;
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return noOfElements == 0;
}

template<typename T>
Queue<T>::~Queue()
{
	if (!data)
	{
		return;
	}
	delete[] data;
	data = nullptr;
}


template<typename T>
bool Queue<T>::isFull()
{
	return noOfElements == capacity;

}

template<typename T>
void Queue<T>::enQueue(T val)
{
	if (isFull())
	{
		//cout << capacity << " " << noOfElements;
		reSize(capacity * 2);
	}
	data[rear] = val;
	rear = (rear + 1) % capacity;
	noOfElements++;

}

template<typename T>
Queue<T>::Queue()
{
	 rear = 0;
	 front = 0;
	capacity = 1;
	noOfElements = 0;
	data = new T[capacity];
}


int main()
{
	Queue<int> a;
	//a.enQueue(1);


	for (int i = 0; i <= 12; i++)
	{
		a.enQueue(i);

	}

	while (!(a.isEmpty()))
	{
		cout << a.deQueue()<<" ";
	}

	return 0;
}