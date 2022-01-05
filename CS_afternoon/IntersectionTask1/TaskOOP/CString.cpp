#include<iostream>
using namespace std;
#include"CString.h"


CString::CString()
{
	size = 0;
	data = nullptr;
}
CString::CString(const char c)
{
	size = 2;
	data = new char[size];
	data[0] = c;
	data[1] = '\0';

}
CString::CString(const char* str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		length = length + 1;
	}
	size = length + 1;
	data = new char[size];
	for (int i = 0; i < length; i = i + 1)
	{
		data[i] = str[i];
	}
	data[length] = '\0';
}
CString::CString(const CString& ref)
{
	if (ref.data)
	{
		size = ref.size;
		data = new char[size];
		for (int i = 0; i < size; i = i + 1)
		{
			data[i] = ref.data[i];
		}

	}
	else
	{
		size = 0;
		data = nullptr;
	}
}
CString::~CString()
{
	if (data)
	{
		delete[] data;
		data = nullptr;
		size = 0;

	}
}
void CString::input()
{
	
	cin.getline(data, size);
}
void CString::shrink()
{
	if (getLength() < size)
	{
		reSize(getLength());
	}
	else
	{
		return;
	}
}
char & CString::at(int index)
{
	return data[index];
}
const char& CString::at(const int index)const
{
	return data[index];
}
bool CString::isEmpty()const
{
	return (size == 0);
}
int CString::getLength()const
{
	int length = 0;
	if (data)
	{
		while (data[length] != '\0')
		{
			length = length + 1;
		}
		return length;
	}
	else
	{
		return 0;
	}
}
void CString::display()const
{
	cout << data;
}
int CString::find(const CString& subStr, int start)const
{
	int i = start, j = 0, position;

	while (data[i] != '\0')
	{
		if (subStr.data[j] == data[i])
		{
			position = i;
			j = 0;
			while (subStr.data[j] != '\0'&&subStr.data[j] == data[i])
			{
				i = i + 1;
				j = j + 1;
			}
			if (subStr.data[j] == '\0')
			{
				return position;
			}


		}
		i = i + 1;
	}
	return -1;
}
void CString::insert(int index, const CString& subStr)
{
	int i = 0, j, count;
	if (subStr.data)
	{
		if (size!=0)
		{
			reSize(getSize() + subStr.getSize() - 1);

		}
		else
		{
			reSize(subStr.getSize());
		}

		bool flag = true;
		while (flag)
		{
			if (i == index)
			{
				count = size - index - subStr.size;
				data[size - 1] = '\0';
				i = size - 2;
				j = index + count - 1;
				for (int k = 0; k < count; k = k + 1)
				{
					data[i] = data[j];
					i = i - 1;
					j = j - 1;
				}
				i = index;
				for (int k = 0; k < subStr.size - 1; k = k + 1)
				{
					data[i] = subStr.data[k];
					i = i + 1;
				}
				flag = false;
			}
			i = i + 1;
		}
	}
	else
	{
		return;
	}
}
void CString::remove(int index, int count)
{
	if (index + count >= size)
	{
		return;
	}
	else
	{
		int indexAfterRemove = index + count, counter = size - index - count, i;
		for (i = 0; i < counter; i = i + 1)
		{
			data[index] = data[indexAfterRemove];
			index = index + 1;
			indexAfterRemove = indexAfterRemove + 1;
		}
		shrink();
	}
}

int CString::replace(const CString & old, const CString & newSubStr)
{
	int j=0;
	int count = 0;
	

	while (data[j]!='\0')
	{
		if (find(old, j)!=-1)
		{
			
			remove(j, old.getLength());
			insert(j, newSubStr);
			count = count + 1;
			j = j + newSubStr.getLength();
		}
		j = j + 1;
	}
	return count;

	
}
void CString::trimLeft()
{
	int i = 0,count=0,index;
	while (data[i] == ' ')
	{
		
		count = count + 1;
		i = i + 1;
	}
	i = 0;
	index = count;
	while (data[i + 1] != '\0')
	{
		data[i] = data[index];
		i = i + 1;
		index = index + 1;
	}
	data[i] = '\0';
	size = size - count;

}
void CString::trimRight()
{
	int index = size-2,count=0;
	while (data[index] == ' ')
	{
		count = count + 1;
		index = index - 1;
	}
	index = index + 1;
	data[index] = '\0';
	size = size - count;
}
void CString::trim()
{
	trimLeft();
	trimRight();
}
void CString::makeUpper()
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'a'&&data[i] <= 'z')
		{
			data[i] = data[i] - ' ';
		}
		i = i + 1;
	}
}
void CString::makeLower()
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'A'&&data[i] <= 'Z')
		{
			data[i] = data[i] + ' ';
		}
		i = i + 1;
	}
}
void CString::reverse()
{
	int i,index=size-2;
	char a;
	for (i = 0; i < ((size-1)/2); i = i + 1)
	{
		a = data[index];
		data[index] = data[i];
		data[i] = a;
		index = index - 1;
	}
	
}
void CString::reSize(int s)
{
	char*p=new char[s];
	if (s <= 0)
	{
		p = nullptr;
		size = 0;
	}
	else if (s >= size)
	{
		for (int i = 0; i < size-1; i = i + 1)
		{
			p[i] = data[i];
		}
		size = s;
		p[size - 1] = '\0';
	}
	else
	{
		for (int i = 0; i < s; i = i + 1)
		{
			p[i] = data[i];
		}
		size = s;
		p[size - 1] = '\0';

	}
	
	delete[] data;
	data = nullptr;
	data = p;
	
}
int CString::compare(const CString & s2)const
{
	int i=0;
	while (data[i] != '\0'&&s2.data[i] != '\0')
	{
		if (data[i] != s2.data[i])
		{
			if (data[i] > s2.data[i])
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		i = i + 1;
	}
	if (data[i] == '\0'&&s2.data[i] != '\0')
	{
		return -1;
	}
	else if (data[i] == '\0'&&s2.data[i] == '\0')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
CString CString::left(int count)
{
	CString s;
	if (count <= 0)
	{
		
		return s;
	}
	else if(count<size)
	{
		s.reSize(count);
		for (int i = 0; i < count; i = i + 1)
		{
			s.data[i] = data[i];
		}
		return s;
	}
	else
	{
		return *this;
	}
}
CString CString::right(int count)
{
	CString s;
	int index = size - 2;
	if (count <= 0)
	{

		return s;
	}
	else if (count<size)
	{
		s.reSize(count);
		for (int i = 0; i < count; i = i + 1)
		{
			s.data[i] = data[index];
			index -= index - 1;
		}
		return s;
	}
	else
	{
		return *this;
	}
}
int CString::toInteger()const
{
	int num,sum=0, multiply = 1;
	for (int i = size - 2; i >= 0; i - i - 1)
	{
		num = 48 - data[i];
		sum = sum + (num*multiply);
		multiply = multiply * 10;
	}
	return sum;
}
float CString::toFloat()const
{
	int i = size - 2, num,intSum=0;
	float floatSum = 0, multiply = 1;
	while(data[i]!='.')
	{
		num = 48 - data[i];
		floatSum = floatSum + (num*multiply);
		multiply = multiply * 10;
		i = i - 1;
	}
	floatSum = floatSum / multiply;
	multiply = 1;
	for (int i = size - 2; i >= 0; i - i - 1)
	{
		num = 48 - data[i];
		intSum = intSum + (num*multiply);
		multiply = multiply * 10;
	}
	return intSum+floatSum;
}
CString CString::concat(const CString & s2)const
{
	CString s;

	s.insert(0, *this);
	s.insert(getLength(), s2);
	
	return s;
}
void CString::concatEqual(const CString & s2)
{
	int s = size-1;
	reSize(getLength() + s2.getLength() + 1);
	for (int i = 0; i <= s2.getLength(); i = i + 1)
	{
		data[s] = s2.data[i];
		s = s + 1;
	}
}

CString CString::tokenize(const CString & delim)
{
	CString s;
	bool flag = true;
	int j = 0;
	while (flag)
	{
		for (int i = 0; i < delim.size; i + 1)
		{
			if (data[j] == delim.data[i])
			{
				flag = false;
			}
		}
		if (flag)
		{
			s.reSize(j + 2);
			s.data[j] = data[j];
		}
		j = j + 1;
	}
	remove(0, j);
	return s;
}
int CString::getSize()const
{
	return size;
}