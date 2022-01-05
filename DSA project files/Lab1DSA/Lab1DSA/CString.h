
#ifndef CSTRING_H
#define CSTRING_H
#include <iostream>
using std::ostream;
using std::istream;

class CString
{
	char * data;
	int size;

public:


	CString();
	CString(const char c);
    CString(const char * a);
	CString(const CString & a);  // copy constructor
	CString(CString && a)    ;  //move constructor
	CString & operator= (const CString & ref);//  copy assignment operator
	CString & operator= (CString && ref);//  move assignment operator
	~CString();
	int getSize() const;
	void input();
	void shrink();

	int find(const CString& subStr, int start)const;

	

	int toInteger()const;
	char & operator[](const int index);
	const char & operator[](const int index) const;
	bool operator!() const;
	int getLength() const;
	
	void display() const;
	void trimLeft();
	void trimRight();
	void trim();
	void makeLower();
	void makeUpper();
	void reverse();
	void reSize(int a);
	void operator +=(const CString & s2);          //concatEqual
	CString operator +(const CString & s2);  //concat

	//int getLength(const char * p);




	bool isValidIndex(int index) const;
	void myStrcpy(char * des, const char * src);

	//int findCharOccurnce(CString * substr, int start = 0);


};


ostream & operator<<(ostream & cout,const CString & str);

istream & operator>>(istream & cin, CString & str);






#endif

