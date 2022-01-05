/* 
#include<iostream>
using namespace std;

class a
{
public:

	a()
	{
		cout << " a()" << endl;
	}
	~a()
	{
		cout << " ~a()"<< endl;
	}
};

struct X
{
	a obj;
	int m;
	X(int a):m(a)
	{
		if (a == 1)
		{
			throw 10;
		}
		cout << "X()  :" << m << endl;
	}
	~X()
	{
		cout << "~X()" << m << endl;
	}

};

double divByZero(int n, int d)
{
	if (d != 0)
	{
		return n / d;
	}

	throw X(1);
}

void f1()
{
	X a(1);

}
void f2()
{
	X a(2);
	f1();
}







int main()
{

	try
	{
		f2();
	}
	catch (int a)
	{
		cout << "in catch :" << a << endl;
	}



	cout << "\nhello\n";
	try
	{
		double res = divByZero(3,0);
		cout << res << endl;
	}
	catch(int a)
	{
		cout <<"in catch :" << a<<endl;
	}

	cout << "\nend\n";
return 0;
}

*/

//  exit behaviour

/*
#include<iostream>
using namespace std;

class A
{
	int m;
public:

	A(int a):m(a)
	{
		cout << " a():" <<a<< endl;
	}
	~A()
	{
		cout << " ~a()" << m << endl;
	}
};

A a(1);
void test() {
	static A b(2);
	A c(3);
	exit(0);
}
int main()
{
	test();

	return 0;
}


*/



//at exit

/*


void done()
{
	cout << "Exiting Successfully"
		<< "\n"; // Executed second
}
// Driver Code
int main()
{
	int value;
	value = atexit(done);

	if (value != 0) {
		cout << "atexit () function registration failed";
		exit(1);
	}
	cout << " Registration successful"
		<< "\n"; // Executed First
	return 0;
}





*/


//  set terminate
/*

void g()
{
	cout << "g()";
	exit(0);
}

int main()
{


	set_terminate(g);
	cout << "hello";
	//assert
	//throw 10;

	return 0;
}


*/

//  Note: If a registered function throws an exception which cannot be handled, then the terminate() function is called.


/*

void shows_Exception()
{
	int y = 50, z = 0;
	cout << "helo";
	// Program will terminate here
	int x = y / z;

	// Cannot get printed as the program
	// has terminated
	cout << "Divided by zero";
}
// Driver Code
int main()
{
	int value;
	value = atexit(shows_Exception);
	if (value != 0) {
		cout << "atexit() function registration failed";
		exit(1);
	}

	// Executed at the starting
	cout << "Registration successful" << endl;
	return 0;
}

*/