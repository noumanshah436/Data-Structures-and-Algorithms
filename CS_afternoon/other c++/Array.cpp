#include"Array.h"
#include <cstdarg>
using namespace std;

bool Array::isValidIndex(int index)const
{
	if (index>=0&&index < capacity)
	{
		return true;
	}
	return false;
}
Array::Array(int argCount , ...)
{
	if (argCount <= 0)
	{
		capacity = 0;
		data = 0;
		return;
	}
	capacity = argCount;
	data = new int[capacity];
	va_list vl;
	va_start(vl, argCount);
	for (int i = 0; i < capacity; i = i + 1)
	{
		data[i] = va_arg(vl, int);
	}
	va_end(vl);

}
Array::Array(const Array& ref)
{
	capacity = ref.capacity;
	data = new int[capacity];
	for (int i = 0; i < capacity; i = i + 1)
	{
		data[i] = ref.data[i];

	}
}
Array& Array::operator=(const Array& ref)
{
	if (data)
	{
		delete[]data;
		data = nullptr;
		capacity = 0;
	}
	capacity = ref.capacity;
	data = new int[capacity];
	for (int i = 0; i < capacity; i = i + 1)
	{
		data[i] = ref.data[i];

	}
	return *this;

}
Array::~Array()
{
	if (data)
	{
		delete[]data;
		data = nullptr;
		capacity = 0;
	}
}
int  Array::getCapacity()const
{
	return capacity;

}
int& Array::operator[](int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
}
const int& Array::operator[](int index)const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
}
void  Array::resize(int newCap)
{
	int* p;
	p = new int[newCap];
	for (int i = 0; i < capacity; i = i + 1)
	{
		p[i] = data[i];
	}
	delete[]data;
	data = nullptr;
	capacity = newCap;
	data = p;
}
