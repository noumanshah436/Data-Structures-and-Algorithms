#include<iostream>
#include<fstream>
#include<process.h>
using namespace std;

class student
{
private:
	int rollno;
	float total;
public:
	void indata()
	{
		cout << "enter roll no: ";
		cin >> rollno;
		cout << "enter total: ";
		cin >> total;
	}
	void outdata()
	{
		cout << "roll no: " << rollno << "\ntotal: " << total<<"\n";
	}
};





int main()
{

	fstream fout(" xyz.txt", ios::in|ios::out|ios::ate| ios::binary);
	if (!fout.is_open())
	{
		cout << "error\n";
	}

	student stu;
	
	
	fout.seekg(0, ios::beg);
	cout << "\nenter new record\n";
	stu.indata();

	cout << fout.tellg()<<'\n';
	fout.write((char*)&stu, sizeof(student));

	cout << "\nrecord list\n";

	fout.seekg(0, ios::beg);

	while (!(fout.eof()))
	{
		student a;

		fout.read((char*)&a, sizeof(stu));
		a.outdata();
	}



	fout.close();


	return 0;

}


