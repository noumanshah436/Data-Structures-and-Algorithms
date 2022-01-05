#include <iostream>
#include <cstdlib>
#include<cassert>
using namespace std;

void h()
{
	cout << "h()\n";
	exit(0);
}
void f() throw(int ,double)
{
	cout << "f()\n";
	//throw "hello";
	throw 10;
}
void expect() 
{
	cout << "expect()()\n";
	//terminate();
}

void g()
{
	cout << "g()\n";
	exit(0);
}


int main()
{
	//assert(10 == 1)
		cout<<cin.rdbuf();

	//set_unexpected(expect);
	
	set_terminate(h);
	//set_terminate(g);



	try
	{
		f();
	}
	catch (float)
	{

	}
	
	//assert
	//throw 10;
	
	return 0;
}


//class SomeClassType
//{
//public:
//
//	SomeClassType()
//	{
//		cout << " SomeClassType()" << endl;
//	}
//	~SomeClassType()
//	{
//		cout << " ~SomeClassType()" << endl;
//	}
//};
//
//SomeClassType someobject;
//
//void myProgramIsTerminating1(void)
//{
//	cout << "exit function 1" << endl;
//}
//
//void myProgramIsTerminating2(void)
//{
//	cout << "exit function 2" << endl;
//}
//
//int main(int argc, char**argv)
//{
//	atexit(myProgramIsTerminating1);
//	atexit(myProgramIsTerminating2);
//	//abort();
//	return 0;
//}