#include<iostream>
using namespace std;
#include"Date.h"
const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool Date::isLeapYear()const
{
	if (((year % 4 == 0)&& (year % 100 != 0)) || (year % 100 == 0 && year % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}
Date::Date(int d, int m, int y)
{
	setDate(d, m, y);
}
void Date::setDate(int d, int m, int y)
{
	setDay(d);
	setMonth(m);
	setYear(y);


	
}
void Date::setDay(int d)
{
	if (day > 0 && day < 32)
	{
		if (d<= daysInMonth[month])
		{
			day = d;
		}
		else if ((month == 2) && (isLeapYear()))
		{
			day = d;
		}
		else
		{
			day = 1;
		}
	}
	else
	{
		day = 1;
	}
}
void Date::setMonth(int m)
{
	(month > 0 && month < 13) ? month = m : month = 1;
}
void Date::setYear(int y)
{
	(year >= 1971 && year <= 2100) ? year = y : year = 2000;

}
int Date::getDay()const
{
	return day;
}
int Date::getMonth()const
{
	return month;
}
int Date::getYear()const
{
	return year;
}
void Date::printFormat1()const
{
	cout << day << "/" << month << "/" << year << "\n";
}
void Date::printFormat2()const
{
	switch (month)
	{
	case 1:
		cout << "January ";
		break;
	case 2:
		cout << "Feburary ";
		break;
	case 3:
		cout << "March ";
		break;
	case 4:
		cout << "April ";
		break;
	case 5:
		cout << "May ";
		break;
	case 6:
		cout << "June ";
		break;
	case 7:
		cout << "July ";
		break;
	case 8:
		cout << "August ";
		break;
	case 9:
		cout << "September ";
		break;
	case 10:
		cout << "October ";
		break;
	case 11:
		cout << "November ";
		break;
	default:
		cout << "December ";
	}
	cout << day << ", " << year << "\n";
}
void Date::printFormat3()const
{
	cout << day << " ";
	switch (month)
	{
	case 1:
		cout << "January ";
		break;
	case 2:
		cout << "Feburary ";
		break;
	case 3:
		cout << "March ";
		break;
	case 4:
		cout << "April ";
		break;
	case 5:
		cout << "May ";
		break;
	case 6:
		cout << "June ";
		break;
	case 7:
		cout << "July ";
		break;
	case 8:
		cout << "August ";
		break;
	case 9:
		cout << "September ";
		break;
	case 10:
		cout << "October ";
		break;
	case 11:
		cout << "November ";
		break;
	default:
		cout << "December ";
	}
	cout << year << "\n";
}
void Date::incDay(int d)
{
	if ((day + d) > daysInMonth[month])
	{
		incMonth((day + d) / daysInMonth[month]);
		day = 1 + day % (daysInMonth[month] + 1);
	}
	
}
void Date::incMonth(int m)
{
	if (month + m >= 13)
	{
		incYear((month + m) / 12);
		month =1+ month % 13;
	}
	else
	{
		month = month + m;
	}
}
void Date::incYear(int y)
{
	if (year + y >= 2100)
	{
		year = (year + y) % 2100;
		year = 1900+year;
	}
	else
	{
		year = year + y;
	}
}
int Date::getTotalDaysInMonth()const
{
	if (isLeapYear())
	{
		if (month == 2)
		{
			return (daysInMonth[month]) + 1;
		}
		else
		{
			return (daysInMonth[month]);
		}
	}
	else
	{
		return (daysInMonth[month]);
	}
}

long long int Date::getDatesBetweenDates(const Date & d1)const
{
	long long int days = 0;
	days =( (d1.getYear()) - getYear())*365;
	int currentMonth,currentYear=year,laterYear=d1.year,d=0;
	int laterMonth;
	if (month > 2)
	{
		currentYear = currentYear + 1;
	}
	if (d1.month <= 2)
	{
		laterYear = laterYear - 1;
	}
	while (currentYear <= laterYear)
	{
		
		if ((currentYear % 4==0) || ((currentYear % 100==0) && (currentYear % 400==0)))
		{
			
			days = days + 1;
		}
		currentYear = currentYear + 1;
	}

	(month >= d1.month) ? currentMonth = d1.month, laterMonth = month : currentMonth = month, laterMonth =d1.month;
	while (currentMonth <= laterMonth)
	{
		d = d + daysInMonth[currentMonth];
		currentMonth = currentMonth + 1;
		if ((currentMonth == 13)&& (currentMonth != laterMonth))
		{
			currentMonth = 1;
		}
	}
	d = d - (day - 1);
	d = d - ((d1.daysInMonth[d1.month]) - d1.day);
	days = days + d;
	return days;
}