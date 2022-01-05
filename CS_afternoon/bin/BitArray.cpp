#include<iostream>
using namespace std;
#include"BitArray.h"


int BitArray::getCapacity()
{
	return capacity;
}
/*BitArray::BitArray(const BitArray& ref)
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
}*/
void BitArray::on(int bitNo)
{
	if (isValidBit(bitNo))
	{
		int bit = bitNo % 8;
		int index = bitNo / 8;
		int no = 1;
		no = no << bit;
		data[index] = data[index] | no;
		
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
		if ((data[index] & no) == no)
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
}
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
}
void BitArray::dump()
{
	for (int i = capacity; i > 0; i = i - 1)
	{
		cout << checkBitStatus(i - 1);
		if ((i-1) % 8 == 0)
		{
			cout << " ";
		}
	}
	cout << '\n';

}

/*BitArray BitArray::AND(BitArray arr)
{
	BitArray ca;

	int s = (int)ceil((float)capacity / 8);
	for (int i = 0; i < s; i = i + 1)
	{
		ca.data[i] = data[i] & arr.data[i];
	}
	return ca;

}
BitArray BitArray::OR(BitArray arr)
{
	BitArray ba;
	int s = (int)ceil((float)capacity / 8);
	for (int i = 0; i < s; i = i + 1)
	{
		//ba.data[i] = data[i] | arr.data[i];
	}
	return ba;
}
*/
void BitArray::shiftLeft(int x)
{
	for (int i = capacity-1; i >= 0; i = i - 1)
	{
		if ((i-x>=0)&&checkBitStatus(i - x))
		{
			on(i);
		}
		else
		{
			off(i);
		}

	}

}
void BitArray::shiftRight(int x)
{
	
	
	for (int i = 0; i < capacity; i = i + 1)
	{
		if ((i+x<capacity)&&checkBitStatus(i + x))
		{
			on(i);

		}
		else
		{
			off(i);
		}
		
	}
}

unsigned long long BitArray::getUnSignedIntegerValue()
{
	int no = 1;
	unsigned long long a = 0;
	a = a + (no*checkBitStatus(0));
	for (int i = 1; i > capacity; i = i + 1)
	{
		no = no << 1;
		a = a + (no*checkBitStatus(i));

	}
	return a;
}
/*
void BitArray::setIntegerValue(unsigned long long)
{

}*/
BitArray::~BitArray()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	
}
