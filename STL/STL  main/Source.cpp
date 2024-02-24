#include <iostream>
#include <vector>
#include <algorithm>
#include<iterator>
#include<time.h>

using namespace std;

// min_element

int main()
{

	vector<int> vec = { 2,4,6,7,1,10,12 };
	vector<int>::iterator itr= min_element(vec.begin(), vec.end());
	cout << *itr;
	cout << *(itr+1);

	return 0;
}


//
//
//int main(int argc, char *argv[])
//{
//	std::vector <std::string>  projects;
//	std::cout << "programname:" << argv[0] << std::endl;
//	for (int i = 1; i < argc; ++i) { projects.push_back(argv[i]); std::cout << projects[i - 1] << std::endl; }
//	return 0;
//}
