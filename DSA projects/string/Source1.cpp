//Input Functions

//1. getline() :-This function is used to store a stream of characters as entered by the user in the object memory.

//2. push_back() : -This function is used to input a character at the end of the string.

//3. pop_back() : -Introduced from C++11(for strings), this function is used to delete the last character from the string.
/*

// C++ code to demonstrate the working of
// getline(), push_back() and pop_back()
#include<iostream>
#include<string> // for string class
using namespace std;
int main()
{
	// Declaring string
	string str;

	// Taking string input using getline()
	// "geeksforgeek" in givin output
	getline(cin, str);

	// Displaying string
	cout << "The initial string is : ";
	cout << str << endl;

	// Using push_back() to insert a character
	// at end
	// pushes 's' in this case
	str.push_back('s');

	// Displaying string
	cout << "The string after push_back operation is : ";
	cout << str << endl;

	// Using pop_back() to delete a character
	// from end
	// pops 's' in this case
	str.pop_back();

	// Displaying string
	cout << "The string after pop_back operation is : ";
	cout << str << endl;

	return 0;

}

*/

//Capacity Functions

//4. capacity() :-This function returns the capacity allocated to the string, which can be equal to or more than the size of the string.Additional space is allocated so that when the new characters are added to the string, the operations can be done efficiently.

//5. resize() : -This function changes the size of string, the size can be increased or decreased.

//6.length() : -This function finds the length of the string

//7.shrink_to_fit() : -This function decreases the capacity of the string and makes it equal to its size.This operation is useful to save additional memory if we are sure that no further addition of characters have to be made.
/*
// C++ code to demonstrate the working of
// capacity(), resize() and shrink_to_fit()
#include<iostream>
#include<string> // for string class
using namespace std;
int main()
{
	// Initializing string
	string str = "geeksforgeeks is for geeks";

	// Displaying string
	cout << "The initial string is : ";
	cout << str << endl;

	// Resizing string using resize()
	str.resize(13);

	// Displaying string
	cout << "The string after resize operation is : ";
	cout << str << endl;

	// Displaying capacity of string
	cout << "The capacity of string is : ";
	cout << str.capacity() << endl;

	//Displaying length of the string
	cout<<"The length of the string is :"<<str.length()<<endl;

	// Decreasing the capacity of string
	// using shrink_to_fit()
	str.shrink_to_fit();

	// Displaying string
	cout << "The new capacity after shrinking is : ";
	cout << str.capacity() << endl;

	return 0;

}

*/

//Iterator Functions

//8. begin() :-This function returns an iterator to beginning of the string.

//9. end() : -This function returns an iterator to end of the string.

//10. rbegin() : -This function returns a reverse iterator pointing at the end of string.

//11. rend() : -This function returns a reverse iterator pointing at beginning of string.

/*
// C++ code to demonstrate the working of
// begin(), end(), rbegin(), rend()
#include<iostream>
#include<string> // for string class
using namespace std;
int main()
{
	// Initializing string`
	string str = "geeksforgeeks";

	// Declaring iterator
	std::string::iterator it;

	// Declaring reverse iterator
	std::string::reverse_iterator it1;

	// Displaying string
	cout << "The string using forward iterators is : ";
	for (it=str.begin(); it!=str.end(); it++)
	cout << *it;
	cout << endl;

	// Displaying reverse string
	cout << "The reverse string using reverse iterators is : ";
	for (it1=str.rbegin(); it1!=str.rend(); it1++)
	cout << *it1;
	cout << endl;

	return 0;

}

*/


//Manipulating Functions

//12. copy(“char array”, len, pos) :-This function copies the substring in target character array mentioned in its arguments.It takes 3 arguments, target char array, length to be copied and starting position in string to start copying.

//13. swap() : -This function swaps one string with other.

/*
// C++ code to demonstrate the working of
// copy() and swap()
#include<iostream>
#include<string> // for string class
using namespace std;
int main()
{
	// Initializing 1st string
	string str1 = "geeksforgeeks is for geeks";

	// Declaring 2nd string
	string str2 = "geeksforgeeks rocks";

	// Declaring character array
	char ch[80];

	// using copy() to copy elements into char array
	// copies "geeksforgeeks"
	str1.copy(ch,13,0);

	// Diplaying char array
	cout << "The new copied character array is : ";
	cout << ch << endl << endl;

	// Displaying strings before swapping
	cout << "The 1st string before swapping is : ";
	cout << str1 << endl;
	cout << "The 2nd string before swapping is : ";
	cout << str2 << endl;

	// using swap() to swap string content
	str1.swap(str2);

	// Displaying strings after swapping
	cout << "The 1st string after swapping is : ";
	cout << str1 << endl;
	cout << "The 2nd string after swapping is : ";
	cout << str2 << endl;

	return 0;

}

*/


//C++ string class and its applications
//In C++ we can store string by one of the two ways –

//C style strings
//string class (discussed in this post)
//In this post, the second method is discussed.string class is part of C++ library that supports a lot much functionality over C style strings.
//C++ string class internally uses char array to store character but all memory management, allocation, and null termination is handled by string class itself that is why it is easy to use.The length of the C++ string can be changed at runtime because of dynamic allocation of memory similar to vectors.As string class is a container class, we can iterate over all its characters using an iterator similar to other containers like vector, set and maps, but generally, we use a simple for loop for iterating over the characters and index them using[] operator.
//C++ string class has a lot of functions to handle string easily.Most useful of them are demonstrated in below code.

/*
// C++ program to demonstrate various function string class
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// various constructor of string class

	// initialization by raw string
	string str1("first string");

	// initialization by another string
	string str2(str1);

	// initialization by character with number of occurrence
	string str3(5, '#');

	// initialization by part of another string
	string str4(str1, 6, 6); // from 6th index (second parameter)
							// 6 characters (third parameter)

	// initialization by part of another string : iteartor version
	string str5(str2.begin(), str2.begin() + 5);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;

	// assignment operator
	string str6 = str4;

	// clear function deletes all character from string
	str4.clear();

	// both size() and length() return length of string and
	// they work as synonyms
	int len = str6.length(); // Same as "len = str6.size();"

	cout << "Length of string is : " << len << endl;

	// a particular character can be accessed using at /
	// [] operator
	char ch = str6.at(2); // Same as "ch = str6[2];"


	cout << "third character of string is : " << ch << endl;

	// front return first character and back returns last character
	// of string

	char ch_f = str6.front(); // Same as "ch_f = str6[0];"
	char ch_b = str6.back(); // Same as below
							// "ch_b = str6[str6.length() - 1];"

	cout << "First char is : " << ch_f << ", Last char is : "
		<< ch_b << endl;

	// c_str returns null terminated char array version of string
	const char* charstr = str6.c_str();
	printf("%s\n", charstr);

	// append add the argument string at the end
	str6.append(" extension");
	// same as str6 += " extension"

	// another version of append, which appends part of other
	// string
	str4.append(str6, 0, 6); // at 0th position 6 character

	cout << str6 << endl;
	cout << str4 << endl;

	// find returns index where pattern is found.
	// If pattern is not there it returns predefined
	// constant npos whose value is -1

	if (str6.find(str4) != string::npos)
		cout << "str4 found in str6 at " << str6.find(str4)
			<< " pos" << endl;
	else
		cout << "str4 not found in str6" << endl;

	// substr(a, b) function returns a substring of b length
	// starting from index a
	cout << str6.substr(7, 3) << endl;

	// if second argument is not passed, string till end is
	// taken as substring
	cout << str6.substr(7) << endl;

	// erase(a, b) deletes b characters at index a
	str6.erase(7, 4);
	cout << str6 << endl;

	// iterator version of erase
	str6.erase(str6.begin() + 5, str6.end() - 3);
	cout << str6 << endl;

	str6 = "This is a examples";

	// replace(a, b, str) replaces b characters from a index by str
	str6.replace(2, 7, "ese are test");

	cout << str6 << endl;

	return 0;
}

*/