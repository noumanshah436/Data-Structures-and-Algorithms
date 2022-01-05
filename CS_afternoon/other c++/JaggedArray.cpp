#include"JaggedArray.h"
#include <cstdarg>
bool JaggedArray::isValidRow(int r)const
{
	if (r >= 0 && r < rows)
	{
		return true;
	}
	return false;
}
JaggedArray::JaggedArray()
{
	data = nullptr;
	rows = 0;
}
JaggedArray::JaggedArray(int r, ...)
{
	if (r <= 0)
	{
		rows = 0;
		data = 0;
		return;
	}
	rows = r;
	data = new Array*[r];
	va_list vl;
	va_start(vl, r);
	for (int i = 0; i < r; i = i + 1)
	{
		data[i] = new Array(va_arg(vl, int));
	}
	va_end(vl);
}
JaggedArray::JaggedArray(const JaggedArray& ref)
{
	if(ref.rows>0)
	{
		rows = ref.rows;
		data = new Array*[rows];
		for (int i = 0; i < rows; i = i + 1)
		{
			if(ref.data[i])
			{
				data[i] = new Array[ref.data[i]->getCapacity()];
			}
		}
	}
	
	
}
Array& JaggedArray::operator[](int i)
{
	if(isValidRow(i))
	{
		return *data[i];
	}

}
const Array& JaggedArray::operator[](int i)const
{
	if(isValidRow(i))
	{
		return *data[i];
	}
}
int JaggedArray::getRows()const
{
	return rows;
}
int JaggedArray::getColumns(int r)const
{
	if (isValidRow(r))
	{
		if(data[r])
		{
			return data[r]->getCapacity();
		}
	}
}
JaggedArray::~JaggedArray()
{
	if (data)
	{
		for (int i = 0; i < rows; i = i + 1)
		{
		
			if(data[i]
			{
				data[i]->~Array();
			}
		}
		delete[]data;
		data = nullptr;
		rows = 0;
	}
	else
	{
		data = nullptr;
		rows = 0;
	}
}