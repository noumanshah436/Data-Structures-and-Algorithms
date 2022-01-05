#include<iostream>
using namespace std;

#include"Container.h"
//
//void containerAfterTakingGreenCandy(Container & a)
//{
//	int cap = a.getcap();
//	for (int i = 0; i < cap; i++)
//	{
//		a[i];
//		
//	}
//
//
//}


int main()
{
	Container a(10);
	

	a.displaycandy();
	cout << "\ncontainerAfterTakingGreenCandy\n";
	a.containerAfterTakingGreenCandy(a);
	a.displaycandy();
	return 0;
}