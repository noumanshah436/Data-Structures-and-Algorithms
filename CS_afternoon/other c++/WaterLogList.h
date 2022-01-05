#ifndef WATER_LOG_LIST_H
#define WATER_LOG_LIST_H
#include"WaterLog.h"

enum WaterUnits{MILLI_LITRE,LITRE};
class WaterLogList
{
	WaterLog** waterLogArray;
	WaterUnits defaultWaterUnit = MILLI_LITRE;
	int waterLogCount;
	int waterLogCapacity;
	void reSize();
public:
	WaterLogList();
	~WaterLogList();
	void logWater(float);
	void logWater(float, Date, Time);
	WaterUnits getDefaultWaterUnit();
	void changeDefaultWaterUnit(WaterUnits);
	float totalWaterIntakeToday()const;
	float totalWaterIntakeCurrentMonth()const;
	float totalWaterIntakeInLastNDays(int)const;
	void printMonthWiseHistogram(int)const;
	void printDaywiseHistogramLastNDays(int)const;
};


#endif // !WATER_LOG_LIST_H
