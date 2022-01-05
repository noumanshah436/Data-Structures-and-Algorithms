
#ifndef CSTRING_H
#define CSTRING_H
#include <iostream>
using std::ostream;
using std::istream;

class CString
{
	friend ostream & operator<<(ostream & cout, const CString & str);

	friend istream & operator>>(istream & cin, CString & str);

	char * data;
	int size;

public:
	CString();
	CString(const char c);
	CString(const char * a);
	CString(const CString & a);  // copy constructor
	CString(CString && a);  //move constructor
	~CString();
	int operator==(const CString & s2)const;
	int operator!=(const CString & s2)const;
	
	const char * getData();
	CString & operator= (const CString & ref);//  copy assignment operator
	CString & operator= (CString && ref);//  move assignment operator
	
	int getSize() const;
	bool operator!() const;
	int getLength() const;

	void input();
	void shrink();
	char & operator[](const int index);
	const char & operator[](const int index) const;
	void trimLeft();
	void trimRight();
	void trim();




	int find(const CString& subStr, int start)const;
	void insert(int index, const CString & subStr);
	void remove(int index, int count=1);
	int replace(const CString & old, const CString & newSubStr);
	int toInteger()const;
	
	
	void display() const;
	void makeLower();
	void makeUpper();


	void reverse();
	void reSize(int a);


	void operator +=(const CString & s2);          //concatEqual
	CString operator +(const CString & s2);       //concat


	bool isValidIndex(int index) const;
	void myStrcpy(char * des, const char * src);


};


ostream & operator<<(ostream & cout,const CString & str);

istream & operator>>(istream & cin, CString & str);






#endif

