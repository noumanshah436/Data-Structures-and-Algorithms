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



int main()
{

	
	 Stack s(5);
	cout << s.push(10) << " ";
	cout << s.push(20) << " ";
	cout << s.push(30) << " ";
	cout << s.push(40) << " ";
	cout << s.push(50) << "\n ";

	cout <<"full   "<< s.isFull() << "\n ";
	cout <<"empty   " << s.isEmpty();
	cout << "\n";
	int a;
	s.pop(a);
	cout << a<<" ";
	s.pop(a);
	cout << a << " ";
	s.pop(a);
	cout << a << " ";
	s.pop(a);
	cout << a << " ";
	s.pop(a);
	cout << a << " ";
	


	return 0;
}
