//read or write student record

/*

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

	fstream fout(" xyz.txt", ios::in|ios::app| ios::binary);
	if (!fout.is_open())
	{
		cout << "error\n";
	}

	student stu;
	//fout.seekg(0, ios::beg);



	for (int i = 0; i < 3; i++)
	{
		stu.indata();
		fout.write((char*)&stu, sizeof(stu));

	}

	fout.seekg(0, ios::beg);

	for (int i = 0; i < 3; i++)
	{
		student a;

		fout.read((char*)&a, sizeof(stu));
		a.outdata();
	}


	fout.close();


	return 0;

}




*/

////read or write student record
 

/*
#include<iostream>
#include<fstream>

using namespace std;

class student
{
private:
	int rollno;
	float total;
public:
	void indata()
	{
		cin >> rollno >> total;
	}
	void outdata()
	{
		cout << rollno << total;
	}
};

int main()
{
//fstream ifs("xyz.bin", ios::binary | ios::in |ios::app);
fstream ifs("xyz.bin", ios::binary | ios::in | ios::out | ios::trunc);
if (!ifs.is_open())
{
	cout << "error";
}
else
{

	student s;
	s.indata();

	ifs.write((char*)&s, sizeof(student));

	ifs.seekg(0, ios::beg);

	student a;

	ifs.read((char*)&a, sizeof(student));



	a.outdata();
}
return 0;

}



*/



//   write data to file full and final  binary file
/*



int main()
{

	fstream fout(" xyz.txt", ios::in | ios::app | ios::binary);
	if (!fout.is_open())
	{
		cout << "error\n";
	}

	student stu;
	//fout.seekg(0, ios::beg);



	for (int i = 0; i < 3; i++)
	{
		stu.indata();
		fout.write((char*)&stu, sizeof(stu));

	}

	fout.seekg(0, ios::beg);

	for (int i = 0; i < 3; i++)
	{
		student a;

		fout.read((char*)&a, sizeof(stu));
		a.outdata();
	}


	fout.close();


	return 0;

}

*/

// update record inary file
/*
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




*/
