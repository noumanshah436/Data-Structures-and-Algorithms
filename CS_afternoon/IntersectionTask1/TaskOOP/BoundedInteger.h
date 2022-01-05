#ifndef BOUNDED_INTEGER_H
#define BOUNDED_INTEGER_H


class BoundedInteger
{
	int lowerBound;
	int upperBound;
	int value;
	bool isValidBound(int lb, int ub)const;
public:
	BoundedInteger();
	BoundedInteger(int lb, int ub);
	BoundedInteger(int lb, int ub, int val);
	void setValue(int val);
	int getValue()const;
	int getLowerBound()const;
	int getUpperBound()const;
	void increment(int inc=1);
	void decrement(int dec = 1);
	bool isValidValue(int val);




};



#endif // !BOUNDED_INTEGER_H
