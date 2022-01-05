#include<iostream>
#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

class BitArray
{
private:
	int capacity;
	unsigned char* data;
	bool isValidBit(int i)
	{
		return i >= 0 && i < capacity;
	}
public:
	int getCapacity();
	BitArray(int n = 8)
	{
		capacity = n;
		int s = (int)ceil((float)capacity / 8);
		data = new unsigned char[s];
		for (int i = 0; i < s; i = i + 1)
		{
			data[i] = data[i] & 0;
		}
	}
	BitArray(const BitArray& ref);
	void on(int bitNo);
	void off(int bitNo);
	int checkBitStatus(int bitNo);
	void invert(int bitNo);
	void dump();
	BitArray AND(BitArray);
	BitArray OR(BitArray);

	void shiftLeft(int);
	void shiftRight(int);

	unsigned long long getUnSignedIntegerValue();
	void setIntegerValue(unsigned long long);
	~BitArray();

};


#endif // !BIT_ARRAY_H

