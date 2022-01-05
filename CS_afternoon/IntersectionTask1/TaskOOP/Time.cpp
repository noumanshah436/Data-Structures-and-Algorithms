#include"Time.h"
#include<iostream>
using namespace std;

void Time::setHour(int h)
{
	if (h >= 0 && h <= 23)
	{
		hour = h;
	}
}
void Time::setMinute(int m)
{

	if (m >= 0 && m <= 59)
	{
		minute = m;
	}
}
void Time::setSecond(int s)
{

	if (s >= 0 && s <= 59)
	{
		second = s;
	}
}
int Time::getHour()
{
	return hour;
}
int Time::getMinute()
{
	return minute;

}
int Time::getSecond()
{
	return second;
		

}
void Time::printTwentyFourHourFormat()
{
	cout << hour << " : " << minute << " : " << second << "\n";
}
void Time::printTwelveHourFormat()
{
	if (hour == 0)
	{
		cout << 12 << " : " << minute << " : " << second << " am\n";

	}
	else if (hour < 12)
	{
		cout << hour << " : " << minute << " : " << second << " am\n";
	}
	else if (hour == 12)
	{
		cout << hour << " : " << minute << " : " << second << " pm\n";

	}
	else
	{
		cout << hour-12 << " : " << minute << " : " << second << " pm\n";

	}
}
void Time::incSec(int sec )
{
	second = second + sec;
	if (second > 59)
	{
		minute =minute+( second / 59);
		second = second % 60;
		if (minute > 59)
		{
			hour = hour + (minute / 59);
			minute = minute % 60;
			if (hour > 23)
			{
				hour = hour % 24;
			}
		}

	}
}
void Time::incMin(int min)
{
	minute = minute + min;
	if (minute > 59)
	{
		hour = hour + (minute / 59);
		minute = minute % 60;
		if (hour > 23)
		{
			hour = hour % 24;
		}
	}

}
void Time::incHour(int h )
{
	hour = hour + h;
	if (hour > 23)
	{
		hour = hour % 24;
	}
}