#include<iostream>
#include"SortedList.h"
using namespace std;


void sort(int * a,int n)
{
	for (int i = n - 1; i >= 1; i--)
	{
		int maxIdx = i;
		for (int j = 0; j < i; j++)
		{
			if (a[j] >= a[maxIdx])
				maxIdx = j;
		}

		int temp = a[i];
		a[i] = a[maxIdx];
		a[maxIdx] = temp;
	}
}

SortedList::~SortedList()
{
	if (arr != nullptr)
	{
		delete[] arr;
		maxSize = 0;
		currSize = 0;
	}
}

SortedList::SortedList(int size)
{
	if (size == 0)
	{
		arr = nullptr;
		maxSize = 0;
		currSize = 0;
		return;
	}
	arr = new int[size] {0};
	maxSize = size;
	currSize = 0;
}

int SortedList::removeAll(int val)
{
	int count = 0;
	for (int i = 0; i < currSize; i++)
	{
		if (val == arr[i])
		{
			SortedList::remove(i-count, val);
			count = count + 1;
		}
	}
	return count;
}


void SortedList::display()
{
	for (int i = 0; i < currSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

bool SortedList::remove(int index, int& val)
{
	if (arr[index] == val)
	{
		for (int i = index; i < currSize - 1; i++)
		{
			arr[i] = arr[i + 1];
		}

		currSize = currSize - 1;
		maxSize = maxSize - 1;

		return true;
	}
	return false;
}

bool SortedList::replace(int index, int newVal)
{
	arr[index] = newVal;
	sort(arr, currSize);
}

bool SortedList::insert(int val)
{
	/*if (currSize == 0)
	{
		arr[0] = val;
		currSize = currSize + 1;
		return 1;
	}
	for (int i = 0; i < currSize; i++)
	{
		if(val>a[])
	}*/

	if (currSize == maxSize)
	{
		return false;
	}
	if (currSize == 0)
	{
		arr[0] = val;
		currSize = currSize + 1;
		return true ;
	}
	arr[currSize] = val;
	currSize = currSize + 1;
	sort(arr, currSize);
	return true;
}