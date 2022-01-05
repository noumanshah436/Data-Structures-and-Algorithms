#include<iostream>
using namespace std;






int main()
{
	string a="AbRAcaDaBRA" ;
	int cnt = 1;
	int array[52][2] = { 0 };
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] <= 90)
		{
			int index = a[i] - 65;
			array[index][0] = array[index][0] +1;
			if (array[index][1] == 1)
			{
				
				array[index][1] = cnt;
				cnt += 1;
			}
			
		}
		else
		{
			int index = a[i] - 71;
			array[index][0] = array[index][0] + 1;
			if (array[index][1] == 0)
			{
				
				array[index][1] = cnt;
				cnt += 1;
			}
			
		}
	}
	
	for (int i = 0; i < 52; i++)
	{
		cout << i << "  :  " << array[i][0] << "   occurrence   " << array[i][1] << endl;;
	}
	
	return 0;
}









//  challenge e
/*

int main()
{
	int num[2] = {0};
	int array[20] = { 0,1, 0,1, 0,1, 0,1, 0,1, 0,1, 0,1, 0,1,0,0,0,0 };
	for (int i = 0; i < 20; i++)
	{
		if (array[i] == 0)
		{
			num[0] = num[0] + 1;
		}
		else
		{
			num[1] = num[1] + 1;
		}
	}

	int i = 0;
	for (; i < (2 * ((num[0] >= num[1]) ? num[1] : num[0])); )
	{
		array[i] = 0;
		array[i + 1] = 1;
		i = i + 2;
	}
	int d = ((num[0] > num[1]) ? 0 : 1);
	for (; i < 17; i++)
	{
		array[i] = d;
	}
	for (int i=0; i < 20; i++)
	{
		cout<<array[i]<<",";
	}
	return 0;
}

*/



// challenge B

//
//int func(int a[],int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (a[i] == 0)
//		{
//			return i;
//		}
//	}
//}
//
//
//
//int main()
//{
//
//	int a[10] = { 1,2,0,4,5,0,7,8,9,10 };
//
//	cout << func(a, 10);
//
//	return 0;
//}





//Given a string consisting of English alphabets(case Sensitive),
//find the maximum length of string which forms a palindrome.
//For example, for the string "xbazabaazzy", the largest length can be 9 and one of such palindrome is "azabzbaza".
//Do it O(N) time and O(1) space bound.

/*


int main()
{
	string a="NOUMAN" ;

	int array[52] = { 0 };
	for (int i = 0; i < 6; i++)
	{
		if (a[i] <= 90)
		{
			int index = a[i] - 65;
			array[index] = array[index]+1;
		}
		else
		{
			int index = a[i] - 71;
			array[index] = array[index] + 1;
		}
	}
	int maxLength = 0;
	int maxODD = 0;
	for (int i = 0; i < 52; i++)
	{
		if ((array[i] % 2) == 0)
		{
			maxLength = maxLength + array[i];
		}
		else
		{
			if (array[i] > maxODD)
			{
				maxODD = array[i];
			}
		}
	}
	maxLength = maxLength + maxODD;
	cout << maxLength;
	return 0;
}


*/