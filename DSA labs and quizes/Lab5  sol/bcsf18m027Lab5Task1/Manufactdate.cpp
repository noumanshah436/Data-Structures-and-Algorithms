#include<iostream>
using namespace std;
#include"Manufactdate.h"


ostream & operator<<(ostream & out, const Manufactdate & man)
{
	out << "Date :" << man.day << "/" << man.month << "/" << man.year << "\n";

	return out;
}

istream & operator>>(istream & input, Manufactdate & man)
{
	cout << "input day :";
	input >> man.day;
	cout << "input month:";
	input >> man.month;
	cout << "input year :";
	input>> man.year;
	

	return input;
}

Manufactdate::Manufactdate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void Manufactdate::displayDate()
{
	cout << "Date :" << day << "/"<<month << "/" <<year<<"\n";
}
Manufactdate::Manufactdate()
{
	day = 0;
	month = 0;
	year = 0;

}
void Manufactdate::setdate(int d, int m, int y)
{
	day =d;
	month = m;
	year = y;
}
Manufactdate Manufactdate::getDate()
{
	return Manufactdate(day,month,year);
}