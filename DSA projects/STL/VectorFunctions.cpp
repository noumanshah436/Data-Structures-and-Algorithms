
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
	vector<int> v1( 5, 42 ); // it creates a vector consisting of five copies of the integer 42

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


//  end
/*int main()
{
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	//int bad_val = *(v1.end());
	//cout << "bad_val is " << bad_val << endl;
	int good_val = *(v1.end() - 1);
	cout << "good_val is " << good_val << endl;

	return 0;
}
*/