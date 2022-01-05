#include<iostream>
#include"BoundedInteger.h"

bool BoundedInteger::isValidBound(int lb, int ub)const
{
	if (((lb >= INT_MIN) && (ub <= INT_MAX)) && (lb <= ub))
	{
		return true;
	}
	return false;
}
BoundedInteger::BoundedInteger()
{
	lowerBound = INT_MIN;
	upperBound = INT_MAX;
	value = lowerBound;
}
BoundedInteger::BoundedInteger(int lb, int ub) : BoundedInteger()
{
	if ((isValidBound(lb, ub)))
	{
		lowerBound = lb;
		upperBound = ub;
		value = lowerBound;
	}
}
BoundedInteger::BoundedInteger(int lb, int ub, int val) : BoundedInteger()
{
	if ((isValidBound(lb, ub)))
	{
		lowerBound = lb;
		upperBound = ub;
		value = lowerBound;
	}
	if (isValidValue(val))
	{
		value = val;
	}
}
void BoundedInteger::setValue(int val)
{
	if (isValidValue(val))
	{
		value = val;
	}
}
int BoundedInteger::getValue()const
{
	return value;
}
int BoundedInteger::getLowerBound()const
{
	return lowerBound;
}
int BoundedInteger::getUpperBound()const
{
	return upperBound;
}
void BoundedInteger::increment(int inc)
{
	int val;
	val = value + inc;
	if (val > upperBound)
	{
		val = upperBound-value;
		inc = inc - val - 1;
		value = lowerBound;
		inc = inc % ((upperBound - lowerBound) + 1);
		value = value + inc;
	}
	else
	{

		value = value + inc;

	}
}
void BoundedInteger::decrement(int dec)
{
	int val;
	val = value - dec;
	if (val < lowerBound)
	{
		val = value - lowerBound;
		dec = dec - val-1;
		value = upperBound;
		dec = dec % ((upperBound - lowerBound) + 1);
		value= value - dec;
	}
	else
	{

		value = value - dec;
		
	}
}
bool BoundedInteger::isValidValue(int val)
{
	if (val >= lowerBound&&val <= upperBound)
	{
		return true;
	}
	return false;
}

