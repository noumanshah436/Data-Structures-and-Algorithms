#ifndef TIME_H
#define TIME_H

class Time
{
	int hour;
	int minute;
	int second;
public:
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	int getHour();
	int getMinute();
	int getSecond();
	void printTwentyFourHourFormat();
	void printTwelveHourFormat();
	void incSec(int sec=1 );
	void incMin(int min=1 );
	void incHour(int hour=1 );




};

#endif //TIME_H
