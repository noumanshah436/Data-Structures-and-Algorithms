#include<iostream>
using namespace std;

int findMinAndMax(int[], int, int&, int&);			//TASK 1
int getMostCharacterOccurrence(char*, char, int);	//TASK 2
int binToDec(int, int, int);						//TASK 3
int divide(int, int, int);							//TASK 4
int sortDescending(int[], int, int);				//TASK 5
int findAndReplace(char*, char*, char*, int, int);  //TASK 6

int main()
{
	///////////////////TASK 1///////////////////
	const int arraySize = 6;
	int arr[arraySize] = { 110,3,-1,200,-99,-50 };
	int size = arraySize - 1;
	int min = arr[size], max = arr[size];
	cout << "TASK 1:\n";
	findMinAndMax(arr, size, min, max);


	///////////////////TASK 2///////////////////
	int count = 0;
	char findCharacter = 'a';
	const int stringSize = 1000;
	char str[stringSize] = "DAta";
	cout << "\nTASK 2:\n";
	cout << "Count of " << findCharacter << "(CASE SENSITIVE) = " << getMostCharacterOccurrence(str, findCharacter, count) << endl;


	///////////////////TASK 3///////////////////
	int num = 111, start1 = 0, mod = 0;
	cout << "\nTASK 3:\n";
	cout << "Number " << num << "(Binary) in Decimal = ";
	cout << binToDec(num, start1, mod) << endl;


	///////////////////TASK 4///////////////////
	int quotient = 0;
	int divider = 4, dividend = 18;
	cout << "\nTASK 4:\n";
	divide(divider, dividend, quotient);


	///////////////////TASK 5///////////////////
	int start2 = 0;
	sortDescending(arr, start2, arraySize);
	cout << "\n\nTASK 5:\n";
	cout << "ARRAY IN DESCENDING ORDER = ";
	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


	///////////////////TASK 6///////////////////
	char strg[stringSize] = "Pakistan is the Country ";
	char find[stringSize] = "is";
	int findLength = 2;
	char replace[stringSize] = "ar";
	int replaceLength = 2;
	findAndReplace(strg, find, replace, findLength, replaceLength);
	cout << "\n\nTASK 6:\n";
	cout << "String After Replace = " << strg << endl;
	return 0;
}

int findMinAndMax(int a[], int size, int& min, int& max)
{
	if (size >= 0)
	{
		if (min > a[size])
		{
			min = a[size];
		}
		if (max < a[size])
		{
			max = a[size];
		}
		size = size - 1;
		return findMinAndMax(a, size, min, max);
	}
	else
	{
		cout << "Minimun of Array = " << min << endl;
		cout << "Maximun of Array = " << max << endl;
		return 1;
	}
}
int getMostCharacterOccurrence(char* line, char find, int count)
{
	char num;
	if (find >= 'a' && find <= 'z')
		num = -32;
	else
		num = 32;

	if (*line == '\0')
	{
		return count;
	}
	else
	{
		if (*line == find || (*line == find + num))
		{
			count = count + 1;
		}
		return getMostCharacterOccurrence(line + 1, find, count);
	}
}
int binToDec(int num, int start, int mod)
{
	if (num == 0 || num == 1)
	{
		return  num * pow(2, start);
	}
	else
	{
		mod = num % 10;
		num = num / 10;
		return mod * pow(2, start) + binToDec(num, start + 1, mod);
	}
}
int divide(int divider, int dividend, int quotient)
{
	if (quotient * divider + dividend % divider == dividend)
	{
		cout << "Quotient = " << quotient;
		cout << "\nRemainder = " << dividend % divider;
		return 1;
	}
	else
	{
		return divide(divider, dividend, quotient + 1);
	}
}
int sortDescending(int a[], int start, int size)
{
	if (start < size)
	{
		int max = a[start], temp;
		for (int i = start; i < size; i++)
		{
			if (max < a[i])
			{
				temp = a[i];
				a[i] = max;
				max = temp;
			}
		}
		a[start] = max;
		return sortDescending(a, start + 1, size);
	}
	else
	{
		return 1;
	}
}

int findAndReplace(char* str, char* find, char* replace, int findLength, int replaceLength)
{
	if (*str == '\0')
	{
		return 1;
	}
	else
	{
		if (*str == *find)
		{
			int count = 0;
			for (int i = 0; i < findLength; i++)
			{
				if (*(str + i) == *(find + i))
				{
					count++;
				}
			}
			if (count == findLength)
			{
				if (findLength == replaceLength)
				{
					*str = *str - replaceLength;
					for (int i = 0; i < findLength; i++)
					{
						*str = *(replace + i);
						str++;
					}
				}
			}
		}
		return findAndReplace(str + 1, find, replace, findLength, replaceLength);
	}
}