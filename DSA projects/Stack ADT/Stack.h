#ifndef STACK_H
#define STACK_H


template <typename T>
class Stack
{
	int top;
	T * data;
	int capacity;
	void resize(int newSize);

public:
	Stack();
	~Stack();
	void push(T a);
	T pop();
	T stackTop();
	bool isFull();
	bool isEmpty();
	int getCapacity();
	int getNumberOfElements();


};

#endif