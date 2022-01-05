#include<iostream>
using namespace std;

int convertNumberToBase(int num, int base)
{
	int quot = num;
	int rem;
	int a = 1;
	int ansAfterConvertion = 0;
	while (quot >= base)
	{
		rem = quot % base;
		rem = rem * a;
		a = a * 10;
		quot = quot / base;
		ansAfterConvertion = ansAfterConvertion + rem;
	}
	ansAfterConvertion = (quot*a) + ansAfterConvertion;
	return ansAfterConvertion;
}

int main()
{
	cout << convertNumberToBase(6, 2);

	return 0;
}
