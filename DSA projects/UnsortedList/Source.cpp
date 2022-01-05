#include<iostream>
using namespace std;
#include"UnsortedList.h"
int main()
{
	UnsortedList a(5);
	a.insert(1);
	a.display();

	a.insert(2);
	a.display();

	a.insert(4);
	a.display();

	a.insert(2);
	a.display();

	a.insert(0);
	a.display();
	cout << "helo";
	int b = 2;
	cout << a.remove(1, b) << endl;
	cout << a.remove(3, b);

	//a.display();
	return 0;
}
