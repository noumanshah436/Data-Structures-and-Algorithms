#include "Matrix.h"

Matrix::Matrix()
{
	data = nullptr;
	row = 0;
	col = 0;
}
Matrix::Matrix(int r,int c)
{
	if (r > 0 && c > 0)
	{
		row = r;
		col = c;
		data = new Array[col];
		for (int i = 0; i < row; i = i + 1)
		{
			data[i].resize(row);
		}
	}
	else
	{
		data = nullptr;
		row = 0;
		col = 0;
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < col; i = i + 1)
	{
		data[i].~Array();
	
	}
	delete[]data;
	col = 0;
}
Array* Matrix:: operator()(int rNo)
{
	if(rNo>0 &&rNo<row)
	{
		Array* a = new Array{ col };
		for (int i = 0; i < col; i = i + 1)
		{
			a->operator[](i) = data[i].operator[](rNo);
		}
		return a;
	}
	else
	{
		return new Array;
	}
}
Array& Matrix::operator[](int index)
{
	if (index >= 0 && index < col)
	{
		return data[index];
	}
}
const Array& Matrix::operator[](int index)const 
{
	if (index >= 0 && index < col)
	{
		return data[index];
	}
}

Matrix::Matrix(const Matrix& r)
{

	if (r.data)
	{
		col = r.col;
		data = new Array[col];
		if (r.data->getCapacity() != 0)
		{
			row = r.data->getCapacity();


				for (int i = 0; i < row; i = i + 1)
				{
					data[i].resize(row);
				}
				for (int i = 0; i < col; i = i + 1)
				{
					for (int j = 0; j < row; j = j + 1)
					{
						data[j].operator[](i) = r.data[j].operator[](i);
					}
				}
		}
	}
	else
	{
		data = nullptr;
		row = 0;
		col = 0;
	}
	
}
void Matrix::operator= (const Matrix& r)
{
	if (r.data)
	{
		col = r.col;
		data = new Array[col];
		if (r.data->getCapacity() != 0)
		{
			row = r.data->getCapacity();


			for (int i = 0; i < row; i = i + 1)
			{
				data[i].resize(row);
			}
			for (int i = 0; i < col; i = i + 1)
			{
				for (int j = 0; j < row; j = j + 1)
				{
					data[j].operator[](i) = r.data[j].operator[](i);
				}
			}
		}
	}
	else
	{
		data = nullptr;
		row = 0;
		col = 0;
	}
}