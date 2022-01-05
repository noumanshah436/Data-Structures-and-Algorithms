#include<iostream>
#include"BitArray.h"
using namespace std;

int main()
{
	BitArray ba(8);
	ba.on(1);

	ba.on(7);
	ba.off(1);
	
	return 0;
}