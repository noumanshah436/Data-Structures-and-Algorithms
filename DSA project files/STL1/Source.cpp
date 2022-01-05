// constructing vectors
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include<iterator>







// copy backward

int main()
{
	vector<int> from_vector;
	for (int i = 0; i < 10; i++)
	{
		from_vector.push_back(i);
	}
	vector<int> to_vector(10);
	copy_backward(from_vector.begin(), from_vector.end(), to_vector.end());
	cout << "to_vector contains: ";
	for (unsigned int i = 0; i < to_vector.size(); i++)
	{
		cout << to_vector[i] << " ";
	}
	cout << endl;
}
//count_if

//
//int main()
//{
//
//	vector<int> the_vector;
//	vector<int>::iterator the_iterator;
//	for (int i = 0; i < 10; i++)
//	{
//		the_vector.push_back(i);
//	}
//
//	//int num = count_if(the_vector.begin(), the_vector.end(), [](int x) {return x < 5; });
//	//	cout << num;
//	/*the_iterator = the_vector.begin();
//	while (the_iterator != the_vector.end())
//	{
//		cout<< *the_iterator;
//		the_iterator++;
//		
//	}*/
//
//
//
//	return 0;
//}








// binary search
/*
int main()
{
	int nums[] = { -242, -1, 0, 5, 8, 9, 11 };
	int start = 0; int end = 7; 
	for (int i = 0; i < 10; i++)
	{
		if (binary_search(nums + start, nums + end, i))
		{
			cout << "nums[] contains " << i << endl;
		}
		else
		{
			cout << "nums[] DOES NOT contain " << i << endl;
		}
	}
}
*/



// push back
/*
int main()
{
	std::vector<int> myvector(5);
	int myint = 9;
	cout << "\nsize is:" << myvector.size() << endl;
	for (int i = 0; i < myvector.size(); i++)
	{
		cin >> myvector[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout<< myvector[i]<<":";
	}
	cout << endl;
	myvector.push_back(myint);
	cout << "\nsize is:" << myvector.size();
	for (int i = 0; i < myvector.size(); i++)
	{
		cout<< myvector[i];
	}
	return 0;
}
*/

//vector constructor

/*

int main()
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;


	first.assign(7, 100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it = first.begin() + 1;
	cout << *first.begin();
	second.assign(it, first.end() - 1); // the 5 central values of first

	int myints[] = { 1776,7,4 };
	third.assign(myints, myints + 3);   // assigning from array.

	std::cout << "Size of first: " << int(first.size()) << '\n';
	std::cout << "Size of second: " << int(second.size()) << '\n';
	std::cout << "Size of third: " << int(third.size()) << '\n';
	return 0;
}


*/

// vector 
/*
int main()
{
	// constructors used in the same order as described above:
	vector<int> first;                                // empty vector of ints
	vector<int> second(4, 100);                       // four ints with value 100
	vector<int> third(second.begin(), second.end());  // iterating through second
	vector<int> fourth(third);                       // a copy of third



	// the iterator constructor can also be used to construct from arrays:
	int myints[] = { 16,2,77,29 };
	std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
*/



//
//#include<iostream> 
//#include<vector>
//#include<string>
//
//using namespace std;
//
//
//int main(int argc, char *argv[])
//{
//	std::vector <std::string>  projects;
//	std::cout << "programname:" << argv[0] << std::endl;
//	for (int i = 1; i < argc; ++i) { projects.push_back(argv[i]); std::cout << projects[i - 1] << std::endl; }
//	return 0;
//}
