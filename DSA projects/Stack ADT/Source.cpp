#include<iostream>
using namespace std;
#include"Stack.h"







int main()
{
	Stack<double>  a;

	for (int i = 0; i <= 12; i++)
	{
		a.push(i);
	}

	while (!(a.isEmpty()))
	{
		cout << a.pop()<<" ";
	}

	

	return 0;
}


/*

int main()
{


	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(10);
	s.push(20);
	s.push(30);


	cout << "full   " << s.isFull() << "\n ";
	cout << "empty   " << s.isEmpty();
	cout << "\n";
	int a;
	a = s.pop();
	cout << a << " ";
	a = s.pop();
	cout << a << " ";
	a = s.pop();
	cout << a << " ";
	a = s.pop();
	cout << a << " ";
	a = s.pop();
	cout << a << " ";
	cout << "full   " << s.isFull() << "\n ";
	cout << "empty   " << s.isEmpty();


	return 0;
}

*/