#include<iostream>
using namespace std;


class Stack
{
	int top;
	int * S;
	int maxSize;
public:
	Stack(int capacity = 0);
	~Stack();
	bool push(int x);
	bool pop(int & x);
	bool isFull();
	bool isEmpty();

	
};

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
	S = new int[capacity];
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
bool Stack::push(int x)
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
bool Stack::pop(int & x)
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




int reverse(int x)
{
	Stack s(9);
	int quot = x;
	int rem = 0;
	while (quot != 0)
	{
		rem = quot % 10;
		quot = quot / 10;
		s.push(rem);
	}
	int result = 0;
	int d;
	int a = 1;
	while (s.pop(d))
	{
		d = d * a;
		a = a * 10;
		result = result + d;
	}
	return result;
}


int main()
{
	cout << reverse(12345678)<<"\n";
	cout << reverse(34324567);
	
	
	


	return 0;
}
