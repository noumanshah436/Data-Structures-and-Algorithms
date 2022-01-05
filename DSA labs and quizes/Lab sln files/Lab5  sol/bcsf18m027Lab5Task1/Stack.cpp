#include<iostream>
using namespace std;
#include "Stack.h"


Stack::Stack(int capacity)
{
	if (capacity == 0)
	{
		maxSize = capacity;
		S = nullptr;
		top = -1;
		return;
	}

	maxSize = capacity;
	S = new Inventory[capacity];
	top = -1;
}

Stack::~Stack()
{
	if (!S)
	{
		top = -1;
		maxSize = 0;
		S = nullptr;
		return;
	}

	delete[] S;
	S = nullptr;
	top = -1;
	maxSize = 0;
}

bool Stack::isFull()
{
	return ((top + 1) == maxSize);

}


bool Stack::push(Inventory x)
{
	if (top >= (maxSize - 1))
	{
		return false;
	}
	else
	{
		S[++top] = x;

		return true;
	}
}


bool Stack::pop(Inventory & x)
{
	if (top < 0)
	{
		return false;
	}
	else
	{
		x = S[top--];
		return true;
	}
}



bool Stack::isEmpty()
{
	return ((top + 1) < maxSize);
}



