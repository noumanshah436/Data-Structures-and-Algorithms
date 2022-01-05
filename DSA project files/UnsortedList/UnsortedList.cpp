#include<iostream>
#include "UnsortedList.h"
using namespace std;


void sort(int * a, int n)
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

UnsorortedList::~UnsorortedList()
{
	if (arr != nullptr)
	{
		delete[] arr;
		maxSize = 0;
		currSize = 0;
	}
}

UnsorortedList::UnsorortedList(int size)
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

int UnsorortedList::removeAll(int val)
{
	int count = 0;
	for (int i = 0; i < currSize; i++)
	{
		if (val == arr[i])
		{
			remove(i , val);
			count = count + 1;
		}
	}
	return count;
}


void UnsorortedList::display()
{
	for (int i = 0; i < currSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

bool UnsorortedList::remove(int index, int& val)
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

bool UnsorortedList::replace(int index, int newVal)
{
	arr[index] = newVal;
	sort(arr, currSize);
}

bool UnsorortedList::insert(int val)
{


	if (currSize == maxSize)
	{
		return false;
	}
	
	arr[currSize] = val;
	currSize = currSize + 1;
	
	return true;
}