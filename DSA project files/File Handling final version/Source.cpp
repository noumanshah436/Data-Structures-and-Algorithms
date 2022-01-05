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
	out << s.roll << "\n";
	out << s.name << "\n";
	out << s.cgpa << "\n";

	return out;
}

istream & operator >>(istream & in , Student & s)
{

	//cout << "enter roll no:";
	in >> s.roll;


	in.ignore();   // as cin stops on \n  (enter), cin.getline read it and stops reading hence do not take any input
	
	//cout << "enter name:";
	
	in.getline(s.name, 100);  // cin.getline readsan entire line including leading and embedded char and stops on \n
							  
						//cout << "enter cgpa:";
	in >> s.cgpa;

	return in;
}






int main()
{

	fstream fs("Student_Record.txt", ios::in|ios::app);
	if (!fs.is_open())
	{
		cout << "error";
	}

	Student s;
	for (int i = 0; i < 3; i++)
	{
		cin >> s;   // input from keyboard
		fs << s;   // write to file
	}

	fs.seekg(0, ios::beg);
	




	Student a;
	while (fs >> a)
	{

		cout << a;  // dispay on screen
	}

	fs.close();


	return 0;
}



//store record in file and then display it by fstream object 
//  the point is that we have to control filepointer after writing to file 
// i.e to read from file we have to take file pointer at the begining
 
/*


int main()
{

	fstream fs("Student_Record.txt", ios::in|ios::app);
	if (!fs.is_open())
	{
		cout << "error";
	}

	Student s;
	for (int i = 0; i < 3; i++)
	{
		cin >> s;   // input from keyboard
		fs << s;   // write to file
	}

	fs.seekg(0, ios::beg);





	Student a;
	while (fs >> a)
	{

		cout << a;  // dispay on screen
	}

	fs.close();


	return 0;
}


*/




// store record in file and then display in screen
/*



int main()
{

	ofstream ofs("Student_Record.txt", ios::app);
	if (!ofs.is_open())
	{
		cout << "error";
	}

	Student s;
	for (int i = 0; i < 5; i++)
	{
		cin >> s;
		ofs << s;
	}

	ofs.close();


	ifstream ifs;
	ifs.open("Student_Record.txt");
	if (!ifs.is_open())
	{
		cout << "error";
	}

	Student a;
	while (ifs >> a)
	{

		cout << a;
	}




	ifs.close();
	return 0;
}

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