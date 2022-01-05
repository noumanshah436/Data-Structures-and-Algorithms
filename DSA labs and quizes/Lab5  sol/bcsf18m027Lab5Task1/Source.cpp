#include<iostream>
using namespace std;
#include "Stack.h"
#include"Inventory.h"

void driver()
{
	int size;
	cout << "Enter Maximum Size of Stack :";
	cin >> size;

	Stack st(size);
	Inventory obj;
	bool check = true;
	while (check)
	{
		int a;
		cout << "\npress 1 to add to inventory \n";
		cout << "press 2 to take from inventory \n";
		cout << "press 3 to exit \n\n";
		cin >> a;
		if (a == 1)
		{
			cin >> obj;
			st.push(obj);

		}
		else if (a == 2)
		{
			if (st.pop(obj))
			{
				cout << obj;
			}
			else
			{ 
				cout << "\nStack is Empty\n";
			}

		}
		else if (a == 3)
		{
			check = false;
		}

		cout << "\n";
	}

	while (st.pop(obj))
	{
		cout << obj;
	}


}

int main()
{
	driver();


	//Inventory a;
	//cin >> a;
	//cout << a;
	//cin >> a;
	//cout << a;
	//cin >> a;
	//cout << a;

	/*Manufactdate a;
	cin >> a;
	cout << a;
	cin >> a;
	cout << a;
	cin >> a;
	cout << a;*/


	/*Manufactdate a(1, 2, 12);
	a.setdate(1, 23, 45);
	a.displayDate();*/

	return 0;
}