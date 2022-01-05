#ifndef CONTAINER_H
#define CONTAINER_H
#include"Candy.h"
#include<time.h>
class Container
{
	Candy * data;
	int capacity;
public:
	Container(int cap=0);
	int getcap();
	void setCap(int newCap);
	void displaycandy();
	~Container();
	void containerAfterTakingGreenCandy(Container & a);
};

inline Container::~Container()
{
	if (!data)
	{
		return;
	}
	delete[] data;
	data = nullptr;
}

inline void Container::setCap(int newCap)
{
	capacity = newCap;
}
inline void Container::displaycandy()
{
	for (int i = 0; i < capacity; i++)
	{
		data[i].displayCandy();
		cout << " ";
	}
}
 int Container::getcap()
{
	return capacity;
}
Container::Container(int cap)
{
	srand(time(0));
	if (cap == 0)
	{
		data = nullptr;
		capacity = 0;
		return;
	}
	capacity = cap;
	data = new Candy [capacity];
	for (int i = 0; i < cap; i++)
	{
		int a = (rand() % 5)+1;
		if (a == 1)
		{
			data[i].setColor("green");
		}
		else if (a==2)
		{
			data[i].setColor("yellow");
		}
		else if (a == 3)
		{
			data[i].setColor("orange");
		}
		else if (a == 4)
		{
			data[i].setColor("pink");
		}
		else
		{
			data[i].setColor("red");
		}

	}
}

inline void Container::containerAfterTakingGreenCandy(Container & a)
{
	
	
	for (int i = 0; i < capacity; i++)
	{
		
		if (data[i].getColor() == "green")
		{
			int cap = capacity;
			cout << i << " ";

			//int c = i;
			for (int j = i; j < cap-i ;j++)
			{
				data[j] = data[j + 1];
			}
			capacity = capacity - 1;
			
		}
	}
	cout << "\n";
	//capacity = capacity - cnt;
}

#endif