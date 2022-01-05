#ifndef ARRAY_H
#define ARRAY_H

class Array
{
	int* data;
	int capacity;
	bool isValidIndex(int index)const;
public:
	Array(int argCount = 0, ...);
	Array(const Array& ref);
	Array& operator=(const Array& ref);
	~Array();
	int getCapacity()const;
	int& operator[](int index);
	const int& operator[](int index)const;
	void resize(int newCap);
	 
	
};


#endif // !ARRAY_H
