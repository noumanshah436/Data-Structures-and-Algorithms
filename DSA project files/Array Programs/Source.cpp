#include<iostream>
using namespace std;


// To search a key to be deleted 
int findElement(int arr[], int n, int key);

// Function to delete an element 
int deleteElement(int arr[], int n, int key)
{
	// Find position of element to be deleted 
	int pos = findElement(arr, n, key);

	if (pos == -1)
	{
		cout << "Element not found";
		return n;
	}

	// Deleting element 
	int i;
	for (i = pos; i < n - 1; i++)
		arr[i] = arr[i + 1];

	return n - 1;
}

// Function to implement search operation 
int findElement(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == key)
			return i;

	return -1;
}


// Inserts a key in arr[] of given capacity. 
// n is current size of arr[]. This  
// function returns n + 1 if insertion 
// is successful, else n. 
int insertSorted(int arr[], int n, int key, int capacity)
{

	// Cannot insert more elements if n is  
	// already more than or equal to capcity 
	if (n >= capacity)
		return n;

	arr[n] = key;

	return (n + 1);
}

// Driver code 
int main()
{
	int i;
	int arr[] = { 10, 50, 30, 40, 20 };

	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 30;

	cout << "Array before deletion\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	n = deleteElement(arr, n, key);

	cout << "\n\nArray after deletion\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}

// This code is contributed by shubhamsingh10 
