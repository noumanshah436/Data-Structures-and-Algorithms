#ifndef DATE_H
#define DATE_H
#include"BoundedInteger.h"


class Date
{
private:
	BoundedInteger day;
	BoundedInteger month;
	BoundedInteger year;
	static const int daysInMonth[13];
	bool isLeapYear()const;

public:
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void printFormat1()const;
	void printFormat2()const;
	int getTotalDaysInMonth()const;
	
	void printFormat3()const;
	void incDay(int = 1);
	void incMonth(int = 1);
	void incYear(int = 1);
	void decDay(int = 1);
	void decMonth(int = 1);
	void decYear(int = 1);


	
	long long int getDatesBetweenDates(const Date & d1)const;

};



#endif // !DATE_H
