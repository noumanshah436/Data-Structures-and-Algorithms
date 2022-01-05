#include<iostream>
using namespace std;


//   task1
int power(int a, int b)
{
	if (b < 0)
	{
		throw exception();
	}
	if (b == 0)
	{
		return 1;
	}
	b = b - 1;
	return a * power(a, b);
	
}


//   task2
int product(int a, int b)
{

	if (a == 0 || b == 0)
	{
		return 0;
	}
	else if (a < 0) 
	{
		return -b + product(a + 1, b);
	}
	if (b < 0) 
	{
		return -a + product(a, b + 1);
	}
	b = b - 1;
	return a + product(a, b );

}


//   task3
int quotient(int num, int den)
{
	if (den == 0)
	{
		throw exception();
	}
	if (num >= 0 && num < den)
	{
		return 0;
	}
	if (num < 0)
	{
		return quotient(num + den, den) - 1;
	}
	if (num >= den)
	{
		return quotient(num - den, den) + 1;
	}
	
}


//   task4
void printChar(char ch, int n)
{
	if (n == 0)
	{
		return;
	}
	cout << ch;
	printChar(ch, n - 1);
}


//   task5
void printArrayReverse(int* arr, int n)
{
	if (n == 0)
	{
		return;
	}
	printArrayReverse(arr, n - 1);
	cout << arr[n - 1] << " ";
}

void histogram()
{
	int n[4];
	cout << "Enter Num 1 :";
	cin >> n[0];
	cout << "Enter Num 2 :";
	cin >> n[1];
	cout << "Enter Num 3 :";
	cin >> n[2];
	cout << "Enter Num 4 :";
	cin >> n[3];

	cout << "\n";

	for (int i = 0; i < 4; i++)
	{
		if (n[i] < 1 || n[i]>30)
		{
			cout << "invalid num\n";	
		}
		else
		{
			for (int j = 0; j < n[i]; j++)
			{
				cout << "*";
			}
			cout << "\n";
		}
	}
}


int main()
{
	histogram();

}

/*
int main()
{
	//   task1
	cout<<power(3, 3);
	cout << "\n";

	//   task2
	cout<<product(3, -3);
	cout << "\n";

	//   task3
	cout << quotient(-10, 2);
	cout << "\n";

	//   task4
	printChar('Z', 2);
	cout << "\n";

	//   task5
	int a[5] = { 1,2,3,4,5 };
	printArrayReverse(a, 5);
	cout << "\n";
	return 0;
}
*/