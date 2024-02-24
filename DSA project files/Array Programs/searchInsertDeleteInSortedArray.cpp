#include<iostream>
using namespace std;


//Search Operation

// C++ program to implement binary search in sorted array 


int binarySearch(int arr[], int low, int high, int key)
{
	if (high < low)
		return -1;
	int mid = (low + high) / 2; /*low + (high - low)/2;*/
	if (key == arr[mid])
		return mid;
	if (key > arr[mid])
		return binarySearch(arr, (mid + 1), high, key);
	return binarySearch(arr, low, (mid - 1), key);
}

/* Driver code for binary search 
int main()
{
	// Let us search 3 in below array 
	int arr[] = { 5, 6, 7, 8, 9, 10 };
	int n, key;

	n = sizeof(arr) / sizeof(arr[0]);
	key = 10;

	cout << "Index: " << binarySearch(arr, 0, n, key) << endl;
	return 0;
}
*/

//#############################################
//##############################################
// insert 
// C++ program to implement insert operation in 
// an sorted array. 

// Inserts a key in arr[] of given capacity. n is current 
// size of arr[]. This function returns n+1 if insertion 
// is successful, else n. 
int insertSorted(int arr[], int n, int key, int capacity)
{
	// Cannot insert more elements if n is already 
	// more than or equal to capcity 
	if (n >= capacity)
		return n;

	int i;
	for (i = n - 1; (i >= 0 && arr[i] > key); i--)
		arr[i + 1] = arr[i];

	arr[i + 1] = key;

	return (n + 1);
}

/* Driver code for insert
int main()
{
	int arr[20] = { 12, 16, 20, 40, 50, 70 };
	int capacity = sizeof(arr) / sizeof(arr[0]);
	int n = 6;
	int i, key = 26;

	cout << "\nBefore Insertion: ";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	// Inserting key 
	n = insertSorted(arr, n, key, capacity);

	cout << "\nAfter Insertion: ";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
*/




//#############################################
//##############################################
// C++ program to implement delete operation in a 
// sorted array 


// To search a ley to be deleted 
int binarySearch(int arr[], int low, int high, int key);

/* Function to delete an element */
int deleteElement(int arr[], int n, int key)
{
	// Find position of element to be deleted 
	int pos = binarySearch(arr, 0, n - 1, key);

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

int binarySearch(int arr[], int low, int high, int key)
{
	if (high < low)
		return -1;
	int mid = (low + high) / 2;
	if (key == arr[mid])
		return mid;
	if (key > arr[mid])
		return binarySearch(arr, (mid + 1), high, key);
	return binarySearch(arr, low, (mid - 1), key);
}

// Driver code for delete
int main()
{
	int i;
	int arr[] = { 10, 20, 30, 40, 50 };

	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 30;

	cout << "Array before deletion\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	n = deleteElement(arr, n, key);

	cout << "\n\nArray after deletion\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// This code is contributed by shubhamsingh10 

