#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include"WaterLog.h"

WaterLog::WaterLog(float a)
{
	quantity = a;
	time_t t = time(NULL);
	tm curTime = * localtime(&t);
	waterDate.setDate(curTime.tm_mday, curTime.tm_mon + 1, curTime.tm_year + 1900);
	waterTime.setTime((curTime.tm_hour), (curTime.tm_min), (curTime.tm_sec));

}
WaterLog::WaterLog(float a, Date b, Time c) :waterDate(b), waterTime(c)
{
	if (a >0)
	{
		quantity = a;
	}
	else
	{
		quantity = 0.5;
	}

}
void WaterLog::setQuantity(float a)
{
	if (a > 0)
	{
		quantity = a;
	}

}
void WaterLog::setWaterDate(Date d)
{
	waterDate.setDate(d.getDay(), d.getMonth(), d.getMonth());
}
void WaterLog::setWaterTime(Time t)
{
	waterTime.setTime(t.getHour(),t.getMinute(),t.getSecond());
}
float WaterLog::getQuantity()
{
	return quantity;
}
Date WaterLog::getWaterDate()
{
	return waterDate;
}
Time WaterLog::getWaterTime()
{
	return waterTime;

}