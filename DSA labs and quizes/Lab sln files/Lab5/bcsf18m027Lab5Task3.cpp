#include<iostream>
using namespace std;


class Stack
{
	int top;
	char * S;
	int maxSize;
public:
	Stack(int capacity = 0);
	~Stack();
	bool push(char x);
	bool pop(char & x);
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
	S = new char[capacity];
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
bool Stack::push(char x)
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
bool Stack::pop(char & x)
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

bool isPalindrome(string a)
{
	Stack s1(30);
	Stack s2(30);
	int size = a.length();
	if (a[size - 1]=='.')
	{
		size = size - 1;
	}
	for (int i = 0; i < size; i++)
	{
		s1.push(a[i]);
	}
	for (int i = size-1; i >= 0; i--)
	{
		s2.push(a[i]);
	}
	char check1, check2;
	for (int i = 0; i < size; i++)
	{
		s1.pop(check1);
		s2.pop(check2);
		if (check1 != check2)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	
	cout<<isPalindrome("ABLE WAS I ERE I SAW ELBA");

	
	

	



	return 0;
}
