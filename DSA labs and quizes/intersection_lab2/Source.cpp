#include<iostream>
using namespace std;

int intersection1(int* A, int* B, int* C, int n);

int intersection2(int* A, int* B, int* C, int n);

int main()
{
	int a[5] = { 1,2,3,4 ,5 };
	int b[5] = { 2,3,4,6,8 };
	int c[5];

	int cnt = intersection2(a, b, c, 5);
	
	cout << cnt << '\n';

	for (int i = 0; i < cnt; i++)
	{
		cout << c[i]<<":";
	}

	return 0;
}



int intersection2(int* A, int* B, int* C, int n)
{
	int count = 0;
	
	for (int i = 0; i < n; i++)
	{
		int l = 0;
		int u = n - 1;
		int mid = 0;
		
		while (l <= u)
		{
			//cout << "\nhello  "<<l << ": " <<u << ":  " <<n << ":  " <<mid<<":"<< A[mid] << ":  " << B[i] << ":  ";
			mid = (l + u) / 2;
			if (A[mid] == B[i])
			{
				C[count] = B[i];
				count = count + 1;

				l = u + 1;     // to break the condition
			}
			else if (A[mid] > B[i])
			{

				u = mid - 1;
			}
			else
			{
				l = mid + 1;

			}
		}
		
	}
	cout << "By\n";
	return count;

}


int intersection1(int* A, int* B, int* C, int n)
{
	int count = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i] == B[j])
			{
				C[count] = A[i];
				count = count + 1;

			}
		}
	}
	return count;

}

