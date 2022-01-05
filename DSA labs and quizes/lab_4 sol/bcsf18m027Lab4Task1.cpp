#include<iostream>
using namespace std;


int  intersection3(int *A, int*B, int* C, int n)
{
	int i = 0, j = 0, k = 0;

	while (i < n)
	{
		if (A[i] < B[j])
		{
			i++;
		}
		else if (B[j] < A[i])
		{
			j++;
		}
		else
		{

			C[k] = B[j];
			i++;
			j++;
			k++;
		}
	}

	return k;
}



int main()
{

	int array2[5] = { 1,2,3,4,5 };
	int array1[5] = { 2,4,5,6,7 };



	int array3[5];
	int n = intersection3(array1, array2, array3, 5);
	cout << "intersection of two arrays are :";
	for (int i = 0; i < n; i++)
	{
		cout << array3[i] << " ";
	}

	return 0;
}
