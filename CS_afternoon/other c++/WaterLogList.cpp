#include"WaterLogList.h"

void WaterLogList::reSize()
{
	int cap = waterLogCapacity * 2;
	WaterLog**p= new WaterLog * [cap];
	for (int i = 0; i < waterLogCapacity; i = i + 1)
	{
		
			p[i] = new WaterLog;
			p[i]->setQuantity(waterLogArray[i]->getQuantity);
			p[i]->setWaterDate(waterLogArray[i]->getWaterDate);
			p[i]->setWaterTime(waterLogArray[i]->getWaterTime);
			delete waterLogArray[i];
			waterLogArray[i] = p[i];
		
	}
	
}
WaterLogList::WaterLogList()
{
	waterLogCapacity = 10;
	waterLogArray = new WaterLog*[waterLogCapacity];
	waterLogCount = 0;
	
}
WaterLogList::~WaterLogList()
{
	if (waterLogArray)
	{
		for (int i = 0; i < waterLogCount; i = i + 1)
		{
			if (waterLogArray[i])
			{
				delete waterLogArray[i];
				waterLogArray[i] = nullptr;
			}
		}
		delete[]waterLogArray;
		waterLogArray = nullptr;
		waterLogCapacity = 0;
		waterLogCount = 0;

	}
	else
	{
		waterLogArray = nullptr;
		waterLogCapacity = 0;
		waterLogCount = 0;
	}

}
void WaterLogList::logWater(float a)
{
	if(!(waterLogCount < waterLogCapacity))
	{
		reSize();
	}
	waterLogArray[waterLogCount] = new WaterLog;
	waterLogArray[waterLogCount]->setQuantity(a);
	waterLogCount = waterLogCount + 1;
}
void WaterLogList::logWater(float a, Date d, Time t)
{
	if (!(waterLogCount < waterLogCapacity))
	{
		reSize();
	}
	waterLogArray[waterLogCount] = new WaterLog;
	waterLogArray[waterLogCount]->setQuantity(a);
	waterLogArray[waterLogCount]->setWaterDate(d);
	waterLogArray[waterLogCount]->setWaterTime(t);

}
WaterUnits WaterLogList::getDefaultWaterUnit()
{
	return defaultWaterUnit;
}
void WaterLogList::changeDefaultWaterUnit(WaterUnits w)
{
	if (w == MILLI_LITRE || w == LITRE)
	{
		defaultWaterUnit = w;
	}
	else
	{
		defaultWaterUnit = MILLI_LITRE;
	}
}