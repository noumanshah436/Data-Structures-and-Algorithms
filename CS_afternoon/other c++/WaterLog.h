#ifndef WATER_LOG_H
#define WATER_LOG_H
#include"Date.h"
#include"Time.h"

class WaterLog
{
	float quantity;
	Date waterDate;
	Time waterTime;
public:
	WaterLog(float = 0.5);
	WaterLog(float, Date, Time);
	void setQuantity(float);
	void setWaterDate(Date);
	void setWaterTime(Time);
	float getQuantity();
	Date getWaterDate();
	Time getWaterTime();
};


#endif // !WATER_LOG_H
