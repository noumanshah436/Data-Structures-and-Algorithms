#include<iostream>
using namespace std;




void rvereseArray(int a[], int startIndex, int endIndex)
{
	while (startIndex < endIndex)
	{ 
		int temp = a[startIndex];
		a[startIndex] = a[endIndex];
		a[endIndex] = temp;
		startIndex++;
		endIndex--;
	}
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };


	rvereseArray(a, 0, 5);

	cout << "Reversed array is" << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << a[i];
	}
	

	return 0;
}










//   return the kth largest element of an array containing n 
/*
int findKthLargest(int* a, int n, int k)
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
	

	return a[n-k];
}

int main()
{
	int a[5] = { 5,4,1,2,9 };
	cout<<findKthLargest(a, 5, 2);

	return 0;
}
*/

/*


#include<iostream>
#include<algorithm>
using namespace std;

// Function to return k'th smallest element in a given array
int kthSmallest(int arr[], int n, int k)
{
	// Sort the given array
	sort(arr, arr+n);

	// Return k'th element in the sorted array
	return arr[k-1];
}

// Driver program to test above methods
int main()
{
	int arr[] = {12, 3, 5, 7, 19};
	int n = sizeof(arr)/sizeof(arr[0]), k = 2;
	cout << "K'th smallest element is " <<  kthSmallest(arr, n, k);
	return 0;
}
*/
