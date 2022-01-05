#ifndef JAGGED_ARRAY_H
#define JAGGED_ARRAY_H
#include"Array.h"
class JaggedArray
{
	Array** data;
	int rows;
	bool isValidRow(int r)const;
public:
	JaggedArray();
	JaggedArray(int r=0,...);
	JaggedArray(const JaggedArray& ref);
	Array& operator[](int i);
	const Array& operator [](int i)const;
	int getRows()const;
	int getColumns(int r)const;
	~JaggedArray();
};

#endif // ! JAGGED_ARRAY_H
