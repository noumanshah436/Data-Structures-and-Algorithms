#include<iostream>
#include<fstream>
using namespace std;


const int NAME_LENGTH = 25;



struct BowlingFigures
{
	char name[NAME_LENGTH + 1]; // Name of the bowler 
	int wickets; // Wickets taken by the bowler 
	int runs; // Runs conceded by the bowler

};




void selectionSortWRTRun(BowlingFigures * bp, int size)
{
	int startScan, minIndex, minValue;
	BowlingFigures temp;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = bp[startScan].runs;
		for (int index = startScan + 1; index < size; index++)
		{
			if (bp[index].runs < minValue)
			{
				minValue = bp[index].runs;
				minIndex = index;
			}
		}

		temp = bp[minIndex];
		bp[minIndex] = bp[startScan];
		bp[startScan] = temp;
	}
}

void selectionSortWRTWicket(BowlingFigures * bp, int size)
{
	int startScan, minIndex, minValue;
	BowlingFigures temp;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = bp[startScan].wickets;
		for (int index = startScan + 1; index < size; index++)
		{
			if (bp[index].wickets > minValue)
			{
				minValue = bp[index].wickets;
				minIndex = index;
			}
		}

		temp = bp[minIndex];
		bp[minIndex] = bp[startScan];
		bp[startScan] = temp;
	}
}





istream& operator>>(istream& fin, BowlingFigures & obj)
{
	fin.getline(obj.name, 25);
	fin >> obj.wickets;
	fin >> obj.runs;
	fin.ignore();

	return fin;
	
}

ostream& operator<<(ostream& fout, BowlingFigures & obj)
{
	
	fout<<obj.name;
	fout << "\n";
	fout << obj.wickets;
	fout << " ";
	fout << obj.runs;
	fout << "\n";
	return fout;
}
BowlingFigures* readFromFile( const char* fileName, int& count)
{
	count = 0;
	ifstream fin(fileName);
	if (!(fin.is_open()))
	{
		return NULL;
	}
	else
	{
		BowlingFigures *bf = new  BowlingFigures[100];
		while (fin >> bf[count])
		{
			
			count = count + 1;
		}
		count = count + 1;
		return bf;
	}

}


void displayBowlingFigures(BowlingFigures * bp, int count)
{
	for (int i = 0; i < count; i = i + 1)
	{
		cout << bp[i];
	}
}

void sortBowlingFigures(BowlingFigures * bp, int count)
{

	selectionSortWRTRun(bp, count);
	selectionSortWRTWicket(bp, count);
}

int main()
{
	int count;
	ifstream fin("test.txt");
	readFromFile("test.txt", count);
	displayBowlingFigures(readFromFile("test.txt", count), count);
	
	return 0;
}




