#include<iostream>
#include<fstream>
using namespace std;

const int NAME_LENGTH = 25;

struct BowlingFigures
{
	char name[NAME_LENGTH + 1]; // Name of the bowler 
	int wickets; // Wickets taken by the bowler 
	int runs; // Runs conceded by the bowler

public:
	BowlingFigures&	operator=(const BowlingFigures&a)
	{
		strcpy(name, a.name);
		wickets = a.wickets;
		runs = a.runs;
	}


};


ostream& operator<<(ostream & fout, BowlingFigures & obj)
{

	fout << obj.name;
	fout << "\n";
	fout << obj.wickets;
	fout << " ";
	fout << obj.runs;
	fout << "\n";
	return fout;
}

//
//ostream & operator <<(ostream &out, BowlingFigures & s)
//{
//	out << s.name << "\n";
//	out << s.wickets<< " ";
//	out << s.runs<< "\n";
//
//	return out;
//}

istream& operator>>(istream& fin, BowlingFigures & obj)
{
	fin.getline(obj.name, 25);
	fin >> obj.wickets;
	fin >> obj.runs;
	fin.ignore();

	

	return fin;

}




BowlingFigures* readFromFile(const char* fileName, int & count)
{
	count = 0;
	ifstream ifs(fileName);
	
	if (!ifs.is_open())
	{
		//cout << "error";
		return NULL;

	}
	else
	{
		BowlingFigures* a = new BowlingFigures[100];

		while (ifs >> a[count])
		{

			count = count + 1;
		}
		cout << count;

		ifs.close();

		return a;
	}
	
	
	
}


void displayBowlingFigures(BowlingFigures * bp, int count)
{
	for (int i = 0; i < count; i = i + 1)
	{
		cout << bp[i];
	}
}
//
//void sortBowlingFigures(BowlingFigures * bp, int count)
//{
//
//
//
//}


int main()
{
	int count=0;
	ifstream ifs("record.txt");
	BowlingFigures a[3];
	for (int i = 0; i < 3; i++)
	{
		ifs >> a[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cout<< a[i];
	}




	//BowlingFigures *b= readFromFile("record", count);
	//displayBowlingFigures(b, 8);

	//readFromFile("test.txt", count);



	//displayBowlingFigures(readFromFile("record.txt", count), count);

}


// input
/*


int main()
{
	ofstream ofs("record.txt", ios::app);
	if (!ofs.is_open())
	{
		cout << "error";
	}
	BowlingFigures a;
	cin >> a;
	ofs << a;
	BowlingFigures b;
	cin >> b;
	ofs << b;
	BowlingFigures c;
	cin >> c;
	ofs << c;
	BowlingFigures d;
	cin >> d;
	ofs << d;
	BowlingFigures e;
	cin >> e;
	ofs << e;
	BowlingFigures f;
	cin >> f;
	ofs << f;
}
*/