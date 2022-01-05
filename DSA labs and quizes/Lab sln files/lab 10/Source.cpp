//#include<iostream>
//using namespace std;
//
//
//
//
//// int findSum (int* arr, int start, int end)
//int findSum(int *arr, int start, int end)
//{
//	
//	if (start > end )
//	{
//		return 0;
//	}
//
//	return (arr[start] + findSum(arr, start + 1, end));
//}
//
//
//bool areArraysEqual(int* a, int aSize, int* b, int bSize)
//{
//	bool check;
//
//	if (aSize != bSize)
//	{
//		return false;
//	}
//
//	if (aSize < 0 && bSize < 0)
//	{
//		return true;
//	}
//
//
//	if (a[aSize - 1] == b[bSize - 1])
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//	
//
//	check=areArraysEqual(a, aSize - 1, b, bSize - 1);
//
//	if (check == false)
//	{
//
//	}
//
//	
//	
//
//}
//
//
//bool isVowel(char ch)
//{
//	
//	return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'||ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
//}
//
//// to count total number of vowel from 0 to n 
//int countVovels(char * str, int n)
//{
//	if (n == 1)
//	{
//		return isVowel(str[n - 1]);
//	}
//
//	return countVovels(str, n - 1) + isVowel(str[n - 1]);
//}
//
////  1 5 2 4 3
////   1 2 3 4 5    
//void printZigZag(int* arr, int start, int end)
//{
//	if (start == end)
//	{
//		cout<<arr[start];
//	}
//
//	printZigZag(arr, start, end);
//
//}
//
//int findLargest(int* arr, int start, int end)
//{
//
//	
//	if (start == end)
//	{
//		return arr[start];
//	}
//	else if (arr[start] < arr[end])
//	{
//		return findLargest(arr, start + 1, end);
//	}
//	else
//	{
//		return arr[start];
//	}
//}
//
////bool areArraysEqual(int* a, int aSize, int* b, int bSize)
//
//
//
//
//int main()
//{
//	//printPattern1('*', 5);
//
//
//	int ar[5] = { 1, 2,3,4,5 };
//	int arr[5] = { 1, 2,3,4,5 };
//
//	cout<<areArraysEqual(ar, arr, 5);
//
//	//int ar[5] = { 1, 2,3,4,5 };
//
//	//cout << findLargest(str, 1, 4);
//
//	return 0;
//}
//
