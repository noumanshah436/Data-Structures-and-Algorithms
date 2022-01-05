#include<iostream>
using namespace std;

bool isElementPresent1(int * a, int size, int element)
{
	for (int i = 0; i < size; i = i + 1)
	{
		if (a[i] == element)
		{
			return true;
		}
	}
	return false;
}
bool isElementPresent2(int * a, int size, int element)
{
	int l = 0, u = size - 1, mid;
	while (l <= u)
	{
		mid = l + u / 2;
		if (a[mid] == element)
		{
			return true;
		}
		else if (a[mid] < element)
		{
			l = mid + 1;
		}
		else
		{
			u = mid - 1;
		}
	}
	return false;
}
int intersectioa1(int *a, int * b, int *c, int n)
{
	int size = 0;
	for (int i = 0; i < n; i = i + 1)
	{
		if (isElementPresent1(b, n, a[i]))
		{
			c[size] = a[i];
			size = size + 1;
		}
	}
	return size;
}
int intersection2(int *a, int * b, int *c, int n)
{
	int size = 0;
	for (int i = 0; i < n; i = i + 1)
	{
		if (isElementPresent2(b, n, a[i]))
		{
			c[size] = a[i];
			size = size + 1;
		}
	}
	return size;

}
int main()
{

	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 2,5,6,7,8 };
	int c[5] = { 11,12,13,14,15 };
	intersection2(a, b, c, 5);
	for (int i = 0; i < 5; i = i + 1)
	{
		cout<<c[i]<<" ";
	}


	return 0;
}