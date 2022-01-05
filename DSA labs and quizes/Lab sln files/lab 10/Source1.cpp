#include<iostream>
using namespace std;








//   Task1


void innerLoop(char ch, int n)
{

	if (n == 0)
	{
		return;
	}
	innerLoop(ch, n - 1);
	cout << ch;
}


void printPattern1(char ch, int n)
{

	if (n == 0)
	{
		return;
	}
	//cout << ch;
	innerLoop(ch, n);
	cout << "\n";
	printPattern1(ch, n - 1);
	
	
}


bool areArraysEqual(int* a, int aSize, int* b, int bSize)
{
	bool check;

	if (aSize != bSize)
	{
		return false;
	}

	if (aSize < 0 && bSize < 0)
	{
		return true;
	}


	if (a[aSize] == b[bSize])
	{
		check = areArraysEqual(a, aSize - 1, b, bSize - 1);
		
	}
	else
	{
		return false;
	}
	

	

	if (check == false)
	{

	}

	
	

}



//  Task3
int findSum(int *arr, int start, int end)
{

	if (start > end)
	{
		return 0;
	}

	return (findSum(arr, start + 1, end) + arr[start]);
}


//   Task4
int findLargest(int* arr, int start, int end)
{


	if (start == end)
	{
		return arr[start];
	}
	else if (arr[start] < arr[end])
	{
		return findLargest(arr, start + 1, end);
	}
	else
	{
		return arr[start];
	}
}



bool isVowel(char ch)
{
	
	return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'||ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// to count total number of vowel from 0 to n 
int countVovels(char * str, int n)
{
	if (n == 1)
	{
		return isVowel(str[n - 1]);
	}

	return countVovels(str, n - 1) + isVowel(str[n - 1]);
}

int main()
{
	//   task1

	cout << "task1\n";
	printPattern1('a', 5);


	cout << "\n";
	cout << "\n";

	//  task 3

	cout << "sum of array";
	int ar[5] = { 1,2,3,4,5 };

	cout << "largest of array\n";
	cout<< findSum(ar, 1, 4);


	cout << "\n";
	cout << "\n";

	//   task4
	

	cout << findLargest(ar, 1, 4);

	cout << "\n";
	cout << "\n";

	return 0;
}





