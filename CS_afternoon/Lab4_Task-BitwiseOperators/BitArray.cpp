#include<iostream>
using namespace std;
#include"BitArray.h"


int BitArray::getCapacity()
{
	return capacity;
}
BitArray::BitArray(const BitArray& ref)
{
	if (ref.data == 0)
	{
		data = 0;
		capacity = 0;
		return;
	}
	capacity = ref.getCapacity;
	data = new unsigned char[capacity];
	memcpy(data, ref.data, capacity * sizeof(unsigned char));
}
void BitArray::on(int bitNo)
{
	if (isValidBit(bitNo))
	{
		int bit = bitNo % 8;
		int index = bitNo / 8;
		int no = 1;
		no = no << bit;
		data[index] = data[index] | no;
		cout << (int)data[index] << endl;
	}
	else
	{
		return;
	}
}
void BitArray::off(int bitNo)
{
	if (isValidBit(bitNo))
	{
		int bit = bitNo % 8;
		int index = bitNo / 8;
		int no = 1;
		no = no << bit;
		no = ~no;
		data[index] = data[index] & no;
		cout << (int)data[index] << endl;
	}
	else
	{
		return;
	}
}
int BitArray::checkBitStatus(int bitNo)
{
	if (isValidBit(bitNo))
	{
		int bit = bitNo % 8;
		int index = bitNo / 8;
		int no = 1;
		no = no << bit;
		if (data[index] & no == no)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return -1;
	}
}/*
void BitArray::invert(int bitNo)
{
	if (isValidBit(bitNo))
	{


		if (checkBitStatus(bitNo))
		{
			off(bitNo);
		}
		else
		{
			on(bitNo);
		}
	}
	else
	{
		return;
	}
}/*
void BitArray::dump()
{

}
BitArray BitArray::AND(BitArray)
{

}
BitArray BitArray::OR(BitArray)
{

}
*/
void BitArray::shiftLeft(int x)
{


}/*
void BitArray::shiftRight(int)
{

}

unsigned long long BitArray::getUnSignedIntegerValue()
{
 
}
void BitArray::setIntegerValue(unsigned long long)
{

}*/
BitArray::~BitArray()
{
	delete[] data;
	data = nullptr;
}