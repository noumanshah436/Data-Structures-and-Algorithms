#include<iostream>
using namespace std;

//
//int main()
//{
//	int sum = 0;
//	int n = 5;
//	int inner = 0;
//	int outer = 0;
//	for (int i = 1; i <= n; outer++, i++)
//	{
//		
//		for (int j = i; j <= n ; inner++, j++)
//		{
//			
//			sum = sum + 1;
//		}
//	}
//
//	cout <<sum << ":" <<outer << ":" << inner;
//}






int main()
{
	int sum = 0;
	int n = 5;
	int cnt = 0;

	for (int i = 0; i <= n * n; i++)
	{

		for (int j = 0; j < i;cnt++,  j++)
		{

			sum = sum + 1;
		}
	}
	cout <<sum<<":"<<cnt;
}




/*


int main()
{
	int sum = 0;


	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			sum = sum + (i*j);
		}
	}
	cout << sum;
}
*/


