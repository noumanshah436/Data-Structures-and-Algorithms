#include<iostream>
using namespace std;

class Stack 
{
	int top;
	int * S;
	int maxSize;
public:
	 

	Stack(int capacity = 0);
	
	bool push(int x);
	bool pop(int &x);
	int peek();
	bool isFull();
	bool isEmpty();
	~Stack();
	int topOfStack()
	{
		return top;
	}
	void displayStack();
};

bool Stack::isFull()
{
	return ((top + 1) == maxSize);

}

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

void Stack::displayStack()
{
	for (int i = 0; i < (top + 1); i++)
	{
		cout << S[i] << " ";
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


int Stack::peek()
{
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = S[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return ((top+1) < maxSize);
}



int  intersection3(int *A, int*B, int* C, int n)
{
	int i = 0, j = 0, k = 0;

	while (i < n)
	{
		if (A[i] < B[j])
		{
			i++;
		}
		else if (B[j] < A[i])
		{
			j++;
		}
		else 
		{
			
			C[k] = B[j];
			i++;
			j++;
			k++;
		}
	}

	
	
	return k;
}


int reverse(int x)
{
	Stack s(9);
	int quot = x;
	int rem = 0;
	while (quot!=0) 
	{
		rem = quot % 10;
		quot = quot / 10;
		s.push(rem);
	}
		int result=0;
	int d;
	int a = 1;
	while (s.pop(d))
	{
		d = d * a;
		a = a * 10;
		result = result+d;
	}
	return result;
}

int printIntersection(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
			i++;
		else if (arr2[j] < arr1[i])
			j++;
		else // if arr1[i] == arr2[j] 
		{
			cout << arr2[j] << " ";
			i++;
			j++;
		}
	}
	return 1;
}


int main()
{
	
	int arr2[5] = { 1, 2,3,4,5 };
	int arr1[5] = { 3,4,5,6,7 };
	


	int arr3[5];
	int n = intersection3(arr1, arr2, arr3, 5);
	for (int i = 0; i < n; i++)
	{
		cout << arr3[i];
	}

	/*
	 Stack s(5);
	cout<<s.push(10)<<" ";
	cout << s.push(20) << " ";
	cout << s.push(30) << " ";
	//cout << s.push(40)  << " ";
	cout << s.push(1000) <<endl;

	cout <<"full   "<< s.isFull()<<endl;
	cout << "empty   " << s.isEmpty();
	cout << "\n ";
	int a;
	s.pop(a);
	cout << a<<" ";
	s.pop(a);
	cout << a << " ";
	s.pop(a);
	cout << a << " "; 
	s.pop(a);
	cout << a << " ";
	*/


	return 0;
}
