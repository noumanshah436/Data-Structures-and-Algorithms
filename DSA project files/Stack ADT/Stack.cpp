#include<iostream>
using namespace std;
#include"Stack.h"





template<typename T>
int Stack<T>::getNumberOfElements()
{
	return top;
}



template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		throw exception();
	}

	T val = data[--top];
	if (top > 0 && top == capacity / 4)
	{
		resize(capacity / 2);
	}
	return val;
}

template<typename T>
void Stack<T>::push(T val)
{
	if (isFull())
	{
		resize(capacity == 0 ? 1 : capacity * 2);
	}
	data[top++] = val;   //  first top value is used and then incremented

}

template<typename T>
T Stack<T>::stackTop()
{
	if (isEmpty())
		throw exception();
	return data[top - 1];      //  it do not change value of top
}


template<typename T>
bool Stack<T>::isEmpty()
{
	return top == 0;
}

template<typename T>
int Stack<T>::getCapacity()
{
	return capacity;
}


template<typename T>
void Stack<T>::resize(int newSize)
{
	T * temp = new T[newSize];
	for (int i = 0; i < top; i++)
	{
		temp[i] = data[i];
	}

	this->~Stack();
	data = temp;
	temp = nullptr;
	capacity = newSize;
}

template<typename T>
Stack<T>::Stack()
{


	capacity = 0;
	data = nullptr;
	top = 0;
}

template<typename T>
Stack<T>::~Stack()
{
	if (!data)
	{
		return;
	}

	delete[] data;
	data = nullptr;
}

template<typename T>
bool Stack<T>::isFull()
{
	return top == capacity;

}