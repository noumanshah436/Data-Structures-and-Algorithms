#include<iostream>
using namespace std;
#include"Date.h"


const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool Date::isLeapYear()const
{
	if (((year.getValue() % 4 == 0) && (year.getValue() % 100 != 0)) || (year.getValue() % 100 == 0 && year.getValue() % 400 == 0))
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
	day.setValue(day.getLowerBound());
	month.setValue(month.getLowerBound());
	year.setValue(year.getLowerBound());
}
Date::Date(int d, int m, int y)
{
	setDate(d, m, y);
}
void Date::setDate(int d, int m, int y)
{
	setYear(y);
	setMonth(m);
	setDay(d);

	


	
}
void Date::setDay(int d)
{
	
		if (d<= daysInMonth[month.getValue()])
		{
			day.setValue(d);
		}
		else if ((month.getValue() == 2) && (isLeapYear())&&(d==29))
		{
			day.setValue(d);
		}
		else
		{
			day.setValue(day.getLowerBound());
		}
	
}
void Date::setMonth(int m)
{
	month.setValue(m);
}
void Date::setYear(int y)
{
	year.setValue(y);
}
int Date::getDay()const
{
	return day.getValue();
}
int Date::getMonth()const
{
	return month.getValue();
}
int Date::getYear()const
{
	return year.getValue();
}
void Date::printFormat1()const
{
	cout << day.getValue() << "/" << month.getValue() << "/" << year.getValue() << "\n";
}
void Date::printFormat2()const
{
	switch (month.getValue())
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
	cout << day.getValue() << ", " << year.getValue() << "\n";
	
}
void Date::printFormat3()const
{
cout << day.getValue() << " ";
switch (month.getValue())
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
cout << year.getValue() << "\n";
}
void Date::incDay(int d)
{
	if ((day.getValue() + d) > daysInMonth[month.getValue()])
	{
		incMonth((day.getValue() + d) / daysInMonth[month.getValue()]);
		day.setValue((1 + day.getValue() % (daysInMonth[month.getValue()] + 1)));
	}

}
void Date::incMonth(int m)
{
	if (day.getValue()>daysInMonth[month.getValue()+m])
	{
		month.setValue(month.getValue() + m + 1);
		day.setValue(day.getValue() + daysInMonth[month.getValue() + m]);
	}
	else if (month.getValue() + m > month.getUpperBound())
	{
		incYear((month.getValue() + m) / 12);
		month.setValue(1 + (month.getValue()) % 13);
	}
	else
	{
		month.setValue(month.getValue() + m);
	}
}
void Date::incYear(int y)
{
	if (year.getValue() + y > year.getUpperBound())
	{
		year.setValue(((year.getValue() + y) % year.getUpperBound()));
		year.setValue(year.getValue() + year.getLowerBound());
	}
	else
	{
		year.setValue(year.getValue() + y);
	}
}
int Date::getTotalDaysInMonth()const
{
	if (isLeapYear())
	{
		if (month.getValue() == 2)
		{
			return (daysInMonth[month.getValue()]) + 1;
		}
		else
		{
			return (daysInMonth[month.getValue()]);
		}
	}
	else
	{
		return (daysInMonth[month.getValue()]);
	}
}



//long long int Date::getDatesBetweenDates(const Date & d1)const
//{
//	long long int days = 0;
//	if (((d1.getYear()) - getYear())==1)
//	{
//
//
//
//		days = ((d1.getYear()) - getYear()) * 365;
//	}
//		days = ((d1.getYear()) - getYear()) * 365;
//		int currentMonth, currentYear = year.getValue(), laterYear = d1.year.getValue(), d = 0;
//		int laterMonth;
//		if (month.getValue() > 2)
//		{
//			currentYear = currentYear + 1;
//		}
//		if (d1.month.getValue() <= 2)
//		{
//			laterYear = laterYear - 1;
//		}
//		while (currentYear <= laterYear)
//		{
//
//			if ((currentYear % 4 == 0) || ((currentYear % 100 == 0) && (currentYear % 400 == 0)))
//			{
//
//				days = days + 1;
//			}
//			currentYear = currentYear + 1;
//		}
//
//		(month.getValue() >= d1.month.getValue()) ? currentMonth = d1.month.getValue(), laterMonth = month.getValue() : currentMonth = month.getValue(), laterMonth = d1.month.getValue();
//		while (currentMonth <= laterMonth)
//		{
//			d = d + daysInMonth[currentMonth];
//			currentMonth = currentMonth + 1;
//			if ((currentMonth == month.getUpperBound() + 1) && (currentMonth != laterMonth))
//			{
//				currentMonth = 1;
//			}
//		}
//		d = d - (day.getValue() - 1);
//		d = d - ((d1.daysInMonth[d1.month.getValue()]) - d1.day);
//		days = days + d;
//		return days;
//
//}