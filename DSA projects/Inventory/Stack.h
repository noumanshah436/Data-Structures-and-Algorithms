#ifndef STACK_H
#define STACK_H
#include"Inventory.h"


class Stack
{
	int top;
	Inventory * S;
	int maxSize;
public:
	Stack(int capacity = 0);
	~Stack();
	bool push(Inventory x);
	bool pop(Inventory & x);
	bool isFull();
	bool isEmpty();
	
};


#endif
