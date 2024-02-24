#ifndef MANUFACTURE_DATE_H
#define MANUFACTURE_DATE_H



class Manufactdate
{
	int day;
	int month;
	int year;

	friend ostream & operator<<(ostream & out, const Manufactdate & str);
	friend istream & operator>>(istream & input, Manufactdate & str);
public:
	Manufactdate();
	Manufactdate(int d, int m, int y);
	void setdate(int d, int m, int y);
	Manufactdate getDate();
	void displayDate();

};
ostream & operator<<(ostream & out, const Manufactdate & str);
 istream & operator>>(istream & input, Manufactdate & str);



#endif