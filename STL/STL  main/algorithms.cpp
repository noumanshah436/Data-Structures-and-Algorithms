




//count_if
/*
int main()
{

	vector<int> the_vector;
	vector<int>::iterator the_iterator;
	for (int i = 0; i < 10; i++)
	{
		the_vector.push_back(i);
	}

	int num = count_if(the_vector.begin(), the_vector.end(), [](int x) {return x < 5; });
		cout << num;
	//the_iterator = the_vector.begin();
	//while (the_iterator != the_vector.end())
	//{
 //    cout<< *the_iterator;
 //   the_iterator++;
	//	
 //   	}



	return 0;
}
*/


// max_element
/*
//  syntax
//  1. iterator max_element( iterator start, iterator end );
//  2. iterator max_element( iterator start, iterator end, BinPred p );
// The max_element() function returns an iterator to the largest element in the range [start,end).

int main()
{
    vector<int> vec = { 9,8,7,23,3,6};
	cout<<
	*max_element(vec.begin(), vec.end(),
	[](int x, int y)
	{
		cout << x << "  " << y <<"#"<< "\n";
		return x<y;
	}
	);

	cout << "\n val count x < 10 :" << count_if(vec.begin(), vec.end(), [](int x) {return x < 10; });

	cout << "\nbreak\n";

	vector<int> ve = { 1,3,4,5,6,5,5,6,3, 3, 1, 4, 1, 5, 23,34,65};
	cout<<
	*max_element(ve.begin(), ve.end(),
	[](int x, int y)
	{
		cout << x << "  " << y << "\n";
		return (x % 100) > (y % 100);
	}
	);

	cout << "\nbreak\n";

	cout <<
		*max_element(ve.begin(), ve.end(),
			[](int x, int y)
	{
		cout << x << "  " << y << "\n";
		return (x % 100) < (y % 100);
	}
	);

	cout << "\nbreak\n";

	int array[] = { 3, 1, 4, 1, 5, 9 };
	unsigned int array_size = 6;
	cout << "Max element in array is " << *max_element(array, array + array_size) << endl;
	vector<char> v;
	v.push_back('a');
	v.push_back('b');
	v.push_back('c');
	v.push_back('d');
	cout << "Max element in the vector v is " << * max_element( v.begin(), v.end()) << endl;
}
*/

// min_element
/*
int main()
{

	vector<int> vec = { 2,4,6,7,1,10,12 };
	vector<int>::iterator itr= min_element(vec.begin(), vec.end());
	cout << *itr;
	cout << *(itr+1);

	return 0;
}
*/


//  minmax_element by using pair of iterator
/*
int main()
{

	vector<int> vec = { 9,8,7,23,3,6,3,4,5,7,8,9,2,88,44,34,56,77 };


	pair< vector<int>::iterator, vector<int>::iterator  > pair_Of_Itr = minmax_element(vec.begin(), vec.end());

	cout << "min  :"<<*pair_Of_Itr.first;  // minmax_element returns a pair which contain first of minimum and last of maximum
	cout << "\nmax :"<<*pair_Of_Itr.second;

	return 0;
}
*/

//   count 
/*
int main()
{
	srand(time(0));

	vector<int> vec;                              // empty vector of ints

	for (int i = 0; i < 50; i++)
	{
		vec.push_back(i);
		int val = rand() % 50;
		cout << val<< " " ;
		vec.push_back(val);
	}

	cout<<"\nval count :"<<count(vec.begin(), vec.end(), 10);


	return 0;
}
*/


//  count_if   
/*
int main()
{


	vector<int> vec;                              // empty vector of ints

	for (int i = 0; i < 50; i++)
	{
		vec.push_back(i+3);

	}


	cout << "\n val count x < 10 :" << count_if(vec.begin(), vec.end(), [](int x) {return x < 10; });
	cout << "\n val count x = 10 :" << count_if(vec.begin(), vec.end(), [](int x) {return x ==10; });


	return 0;
}
*/

// copy backward
/*
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

*/

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
