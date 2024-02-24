#include<iostream>
using namespace std;
#include"Inventory.h"

ostream & operator<<(ostream & out, const Inventory & inv)
{
	out << "\nSerial Number :" <<inv.serialNum<< "\n";
	cout << inv.date;
	cout << "Price :" << inv.price << "\n";
	return out;
}



istream & operator>>(istream & input, Inventory & inv)
{
	cout << "\n\ninput Serial Number:";
	input >> inv.serialNum;
	input >> inv.date;
	cout << "input price:";
	input >> inv.price;
	return input;
}

Inventory::Inventory(int serialNumber, Manufactdate date, int price)
{
	serialNum= serialNumber;
	this->date=date;
	this->price=price;
}
Inventory::Inventory()
{
	serialNum = 0;
	price = 0;
}

/*
 serialNum;
 date;
 price;
*/
void Inventory::displayInventory()
{
	cout<<"Serial Number :"<< serialNum<<"\n";
	date.displayDate();
	cout << "Price :" << price << "\n";
}

void Inventory::setInventory(int serialNumber, Manufactdate date, int price)
{
	serialNum = serialNumber;
	this->date = date;
	this->price = price;
}

Inventory Inventory::getInventory()
{
	return Inventory(serialNum, date, price);
}