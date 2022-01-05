#include <iostream>
#include<fstream>

using namespace std;

struct Student
{
	int roll;
	char name[100];
	float cgpa;
};

ostream & operator <<(ostream &out, Student & s)
{
	out << s.roll<<"\n";
	out << s.name << "\n";
	out << s.cgpa << "\n";

	return out;
}

istream & operator >>(istream & in , Student & s)
{
	in >> s.roll;
	in.ignore();
	in.getline(s.name, 100);
	in >> s.cgpa;

	return in;
}
#include <iostream>
#include <fstream>
using namespace std;



//display all file on console in single statement


int main()
{
	ifstream ifs("Student_Record.txt");
	cout << ifs.rdbuf();
	
return 0;
}


/*
ofstream ofs;
	ofs.open("Student_Record.txt",ios::app);


	Student s1;
	//Student s= { 7,"mohsan", 3.7 };
	//ofs << s;
	ofs.close();

	ifstream ifs;
	ifs.open("temp.txt");
	while (!ifs.eof())
	{
		ifs >> s1;
		if (!ifs.eof())
			cout << s1;
	}
	ifs.close();

*/

//remove record
/*

int main()
{

	ifstream ifs;
	ifs.open("Student_Record.txt");


	Student s1;
	//Student s= { 7,"mohsan", 3.7 };
	//ofs << s;


	ofstream ofs;
	ofs.open("temp.txt",ios::app);

	while (ifs>>s1)
	{
		//cout << s1;
		if (!(s1.roll == 2))
		{
			ofs << s1;
		}
	}

	remove("Student_Record.txt");
	rename("temp.txt", "Student_Record.txt");

		//cin >> s;
	//cout << s;

	//ofstream ofs;
	//ofs.open("file.txt");
	//ofs << "hello how are you";
	////cout << "copleted";
	//ofs.close();

	//ifstream ifs;
	//ifs.open("file.txt");
	//char ch;
	////cout << ifs.tellg();


	//ifs.seekg(-1, ios::end);
	//cout << ifs.tellg()<<endl;
	//ifs >> ch;
	//cout << ch;
	//ifs.close();
	return 0;
}
*/


//update record
/*


int main()
{

	ifstream ifs;
	ifs.open("Student_Record.txt");



	Student s1;
	Student s= { 13,"nomi", 3.7 };
	//ofs << s;


	ofstream ofs;
	ofs.open("temp.txt",ios::app);

	while (ifs>>s1)
	{

		if (s1.roll == 3)
		{
			ofs << s;
		}
		else
		{
			ofs << s1;
		}
	}

	ifs.close();
	ofs.close();

	remove("Student_Record.txt");
	rename("temp.txt", "Student_Record.txt");


	return 0;
}
*/