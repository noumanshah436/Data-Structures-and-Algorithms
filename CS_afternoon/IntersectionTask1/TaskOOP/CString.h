#ifndef C_STRING_H
#define C_STRING_H

class CString
{
	char* data;
	int size;
public:
	CString();
	CString(const char c);
	CString(const char*);
	CString(const CString &);
	~CString();
	void input();
	void shrink();
	char & at(int index);
	const char & at(const int index)const;
	bool isEmpty()const;
	int getLength()const;
	void display()const;
	int find(const CString& subStr, int start = 0)const;
	void insert(int index, const CString& substr);
	void remove(int index, int count = 1);
	int replace(const CString & old, const CString & newSubStr);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(int);
	int compare(const CString & s2)const;
	CString left(int count);
	CString right(int count);
	int toInteger()const;
	float toFloat()const;
	CString concat(const CString & s2)const;
	void concatEqual(const CString & s2);
	CString tokenize(const CString & delim);
	int getSize()const;





};

#endif // !C_STRING_H
