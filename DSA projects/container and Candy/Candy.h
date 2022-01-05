#ifndef CANDY_H
#define CANDY_H

class Candy
{
	string color;
public:
	
	Candy(string a="");
	string getColor();
	void setColor(string a);
	void displayCandy();

	
};
 void Candy::displayCandy()
{
	 int size = color.length();
	 for (int i = 0; i < size; i++)
	 {
		 cout << color[i];
	 }
}
inline void Candy::setColor(string a)
{
	color = a;
}
string Candy::getColor()
{
	return color;
}
Candy::Candy(string a)
{
	color = a;
}

#endif