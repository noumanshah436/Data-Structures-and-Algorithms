#include<iostream>
#include"CString.h"
using namespace std;


//    CString::



istream & operator>>(istream & cin, CString & str)
{
	str.input();
	return cin;
}

ostream & operator<<(ostream & cout,const CString & str)
{
	str.display();
	return cout;
}

int CString::operator!=(const CString & s2) const
{
	return !(*this == s2);
}

int CString::operator==(const CString & s2)const
{
	int i = 0;
	while (data[i] != '\0' && s2.data[i] != '\0')
	{
		

		if (data[i] != s2.data[i])
		{
			return false;

		}
		i = i + 1;
	}
	return true;
}
//
//int CString::operator==(const CString & s2)const
//{
//	int i = 0;
//	while (data[i] != '\0'&& s2.data[i] != '\0')
//	{
//		if (data[i] != s2.data[i])
//		{
//			if (data[i] > s2.data[i])
//			{
//				return 1;
//			}
//			else
//			{
//				return -1;
//			}
//		}
//		i = i + 1;
//	}
//	if (data[i] == '\0'&&s2.data[i] != '\0')
//	{
//		return -1;
//	}
//	else if (data[i] == '\0'&&s2.data[i] == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}

CString & CString::operator = (CString && ref)//  move assignment operator
{
	cout << "\nCString & CString::operator = (CString && ref)\n";
	this->~CString();
	data = ref.data;
	size = ref.size;
	ref.data = nullptr;
	ref.size = 0;
	return *this;
/*

line 2 call this function
CString b;
b = CString("nouman");
*/



}


CString::CString(CString && a)
{
	cout << "\nCString::CString(CString && a)   "<<this<<endl;
	data = a.data;
	size = a.size;
	a.data = nullptr;
	a.size = 0;
}


void CString::reverse()
{
	CString d((const char *)data);   //nouman     //first i copy string as it is
	
//	d.display(); cout << endl<<"infunction";

	int length = getLength();
	int i = 0;
	int a = length-1;
	for (; i < length; i++)
	{
		d.data[i] = data[a];

		a = a - 1;
	}
	
	d.data[i] = '\0';
	//cout << "size of d  " << d.size;
	this->~CString();

	/*cout << d.data<<endl;
	cout << "gdhgsh"<<endl;*/
	data = d.data;
	size = d.size;
	d.data = nullptr;


}

void CString::shrink()
{ //nouman
	if (getLength() < size)
	{
		reSize(getLength());
	}
	else
	{
		return;
	}
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
			while (subStr.data[j] != '\0' && subStr.data[j] == data[i])
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



void CString::trimLeft()
{

	int count = 0;

	for (int i = 0; data[i] == ' ' || data[i] == '\t' || data[i] == '\n'; i++)
	{
		count = count + 1;    //give count of white space char
	}
	
	size = size - count;  

	for (int i = 0; data[i] != '\0'; i++)
	{
		data[i] = data[count];
		count = count + 1;
	}

	

}
void CString::trimRight()
{
	int index = size - 2, count = 0;
	while (data[index] == ' ' || data[index] == '\t'  || data[index] == '\n' )
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

int CString::toInteger()const
{
	int num, sum = 0, multiply = 1;                            //   1234        size=5
	for (int i = size - 2; i >= 0; i = i - 1)
	{
		num = data[i] - 48;
		sum = sum + (num*multiply);
		multiply = multiply * 10;
	}
	return sum;
}
void CString::reSize(int a)
{
	
	if (a <= 0)
	{
		this->~CString();
		return;
	}
	//size = a;
	char * p = new char[a];
	
	int i = 0;
	for (; i < (a > size ? size : a) - 1; i++)        //(a > size ? size : a)   //nouman   3
	{
		p[i] = data[i];
	}
//	cout <<endl<< i<<"in function";
	p[i] = '\0';
	
	this->~CString();
	data = p;
	size = a;
	//delete p;    do no do this
	p = nullptr;

}
int  CString::getLength() const
{
	if (!data)
	{
		return 0;
	}


	int length = 0;
	for (int i = 0; data[i] != '\0'; i++)
	{
		length = length + 1;
	}
	return length;
}


void CString::makeUpper()
{

	for (int i = 0; i < (size-1) && data[i] != '\0'; i++)
	{
		if (data[i] >= 97 && data[i] <= 122)
		{
			data[i] = data[i] - 32;
		}
	}

}

void CString::operator += (const CString & s2)
{
	int count = size-1;                          // nouman  syed
	reSize(size + s2.size-1);
	for (int i = count; i < (count + s2.size-1); i++)
	{
		data[i] = s2.data[i - count];


		//cout<<endl << data<<endl;
	}
	data[count + s2.size-1] = '\0';
}
CString CString::operator +(const CString & s2)  //concat
{
	//cout << &s2<<endl;          // nouman // syed
	CString temp(*this);
	int count = size - 1;                          // nouman  syed
	temp.reSize(size + s2.size - 1);
	for (int i = count; i < (count + s2.size - 1); i++)
	{
		temp.data[i] = s2.data[i - count];
	}
	temp.data[count + s2.size - 1] = '\0';
	/*int count = size;
	temp.resize(count + s2.size);
	for (int i = count; i < (count + s2.size); i++)
	{
		temp.data[i] = s2.data[i - count];


		//cout<<endl << data<<endl;
	}
	temp.data[count + s2.size] = '\0';

	temp.display();*/
	return temp;
}


void CString::makeLower()
{

	for (int i = 0; i < (size-1) && data[i] != '\0'; i++)
	{
		if (data[i] >= 65 && data[i] <= 90)
		{
			data[i] = data[i] + 32;
		}
	}

}


void CString::input()
{
	
	char input;    
	cin.get(input);//   scedular
	int index = getLength();  // size is initialized either by default or other   // nouman index =6 , size=7

	int a = index + 2;
	
	while (input != '\0' && input != '\n')
	{
		reSize(a);   // it also reset size  
		data[index] = input;   //
		index = index + 1;
		a = a + 1;
		cin.get(input);
		
		//size = index + 1;
	}

	data[index] = '\0';
	//size = size + 1;
}


CString & CString::operator= (const CString & ref)
{
	//cout << "\nCString & CString::operator= (const CString & ref)\n";
	if (!ref.data)
	{
		data = nullptr;
		size = 0;
		return *this;
	}    

	this->~CString();

	size = ref.size;  //nouman
	data = new char[ref.size];
	for (int i = 0; i < (ref.size); i++)
	{
		data[i] = ref.data[i];
	}

	return *this;
}

bool CString::isValidIndex(int index)  const
{
	if (index >= 0 && index <= size)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

bool CString::operator!() const
{
	if (!data)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void CString::myStrcpy(char * des, const char * src)
{
	int i = 0;
	for (; src[i] != '\0'; i++)
	{
		des[i] = src[i];
	}

	des[i] = '\0';
}

const char & CString::operator[](const int index) const
{

	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}
char & CString::operator[](const int index)
{

	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}

CString::CString()
{
	//cout << "\nCString::CString()\n";
	data = nullptr;
	size = 0;
}


int CString::getSize() const
{
	return size;
}


CString::CString(char c)
{
	cout << "\nCString::CString(char c)\n";
	size = 2;
	data = new char[size];
	data[0] = c;
}

CString::CString(const char * a)
{
	//cout << "\nCString::CString(const char * a)    "<<this<<"\n";

	int length = 0;
	while (a[length] != '\0')
	{
		length = length + 1;
	}
	size = length + 1;    //  1 for marker '\0'
	data = new char[size];
	for (int i = 0; i < length; i++)
	{
		data[i] = a[i];
	}
	data[length] = '\0';
}


void CString::display()const
{
	if (!data)
	{
		return;
	}

	cout << data;
}
  CString::CString(const CString & a)
{
	//cout << "\nCString::CString(const CString & a)\n";
	if (!a.data)
	{
		data = nullptr;
		size = 0;
		return;
	}

	size = a.size;
	data = new char[size];
	for (int i = 0; i < a.size; i++)
	{
		data[i] = a.data[i];
	}
}


//int CString::getLength(const char * p)

//{
//	if (!data)
//	{
//		return 0;
//	}
//
//	int count = 0;
//	while (p[count] != '\0')
//		count++;
//	return count;
//}

CString::~CString()
{
	//cout << "\nCString::~CString()\n";
	if (!data)
	{
		return;
	}

	delete[] data;
	data = nullptr;
	size = 0;


}