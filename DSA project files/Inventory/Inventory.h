#ifndef INVENTORY_H
#define INVENTORY_H
#include"Manufactdate.h"

class Inventory
{
	int serialNum;
	Manufactdate date;
	int price;
	friend ostream & operator<<(ostream & out, const Inventory & str);
	friend istream & operator>>(istream & input, Inventory & str);
public:
	Inventory();
	Inventory(int serialNumber, Manufactdate date, int price);
	Inventory getInventory();
	void setInventory(int serialNumber, Manufactdate date, int price);
	void displayInventory();
};


ostream & operator<<(ostream & out, const Inventory & str);

istream & operator>>(istream & input, Inventory & str);



#endif
