#ifndef MATRIX_H
#define MATRIX_H
#include "Array.h"

class Matrix
{
	Array* data;
	int row, col;
public:
	Matrix();
	Matrix(int r,int c);
	~Matrix();
	Array* operator()(int rNo);
	Array& operator[](int index);
	const Array& operator[](int index)const;
	Matrix(const Matrix& r);
	void operator= (const Matrix& r);
};
#endif // !MATRIX_H
