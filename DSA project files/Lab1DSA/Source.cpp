#include<iostream>
using namespace std;
#include"CString.h"
#include<fstream>








int main()
{

	try
	{
		throw (float)1.0;
	}


	catch (float n)
	{
		cout << "first line\n";
		
	}
	

	

	return 0;
}






//
//
//
//int main()
//{
//
//
//
//	fstream obj;
//	obj.open("obj.txt",ios::trunc );
//	if (obj.is_open())
//	{
//		cout << "hello";
//	}
//	obj.close();
//	int a = 65;
//	//obj.write((char*)&a, sizeof(int));
//
//
//	//
//	//
//	//obj.write((char*)&a, sizeof(int));
//	//obj.write((char*)&a, sizeof(int));
//	//obj.read((char*)&a, sizeof(int));
//	//cout << a;
//
//	//obj.close();
//	//obj.open("inventory.txt", ios::app | ios::out | ios::binary);
//
//	return 0;
//}
//


//
//class inventory
//{
//	CString itemName;
//	int quantity;
//	float wholeSaleCost;
//	float retailCost;
//	friend istream & operator>>(istream & a, inventory & d);
//
//public:
//	inventory(CString a, int quant, float wholeRate, float retailCost) : itemName(a)
//	{
//		quantity = quant;
//		wholeSaleCost = wholeRate;
//		retailCost = retailCost;
//	}
//	int getQuantity()
//	{
//		return  quantity;
//	}
//
//
//
//
//};
//
//istream & operator>>(istream & a, inventory & d)
//{
//	cout << "eneter item name";
//	d.itemName.input();
//	cout << "eneter item quantity";
//	cin >> d.quantity;
//	cout << "eneter item wholeSaleCost";
//	cin >> d.wholeSaleCost;
//	cout << "eneter itemretail  Cost";
//	cin >> d.retailCost;
//
//}
//
//
//int main()
//{
//	inventory a("dish",3,3,3);
//	
//	fstream fs;
//	fs.open("inventory.txt",ios::out| ios::binary);
//	fs.seekg(0, ios::beg);
//
//
//	fstream obj;
//	obj.open("temp.txt", ios::app|ios::in|ios::binary);
//
//	while (!fs.eof())
//	{
//		int quantity;
//		fs.read((char *)&a, sizeof(inventory));
//		cout << "enter record quantity to change";
//		
//		cin >> quantity;
//
//		if (a.getQuantity() != quantity)
//		{
//			cin >> a;
//			obj >> a;
//		}
//		else
//		{
//			obj >> a;
//		}
//
//	}
//
//	obj.close();
//	fs.close();
//
//	remove("inventory.txt");
//	rename("temp.txt", "inventory.txt");
//
//	/*inventory a("dish", 3, 3, 3);
//	fstream fs;
//	fs.open("inventory.txt", ios::out | ios::binary);
//	while (fs.read((char*)&a), sizeof(inventory))
//	{
//
//	}*/
//
//	return 0;
//}















// task 7

//int main()
//{
//
//	try
//	{
//		try
//		{
//			throw 20;
//	}
//
//
//		catch (int n)
//		{
//			cout << "first line\n";
//			throw;
//		}
//
//	}
//	catch (int para)
//	{
//		cout << "second line\n";
//	}
//
//	return 0;
//}




//task 6

//int main()
//{
//	
//		try
//		{
//			
//			throw 10;
//			
//		}
//		
//
//		catch (...)
//		{
//			cout << "default exception\n";
//		}
//
//		catch (int para)
//		{
//			cout << "integer exception\n";
//		}
//
//		
//		
//
//
//	return 0;
//}





//task 5


//
//int main()
//{
//	
//		try
//		{
//			
//				throw 'a';
//			
//		}
//		catch (int para)
//		{
//			cout << "integer exception\n";
//		}
//
//		catch (...)
//		{
//			cout << "default exception\n";
//		}
//
//		cout << "afrter exception";
//		
//
//
//	return 0;
//}



// task 4



//int main()
//{
//	int x[3] = { -1,2 };
//
//	for (int i = 0; i < 2; i++)
//	{
//		int ex = x[i];
//
//		try
//		{
//			if (ex > 0)
//			{
//				throw ex;
//			}
//			else
//			{
//				throw 'ex';
//			}
//		}
//		catch (int ex)
//		{
//			cout << "integer exception\n";
//		}
//
//		catch (char ex)
//		{
//			cout << "character exception\n";
//		}
//
//	}
//
//	
//	return 0;
//}


// task 3

//int main()
//{
//
//	try
//	{
//		string s;
//		s.resize(-1);
//	}
//	catch (exception exception)
//	{
//		cout << "standard exception :" << exception.what() << '\n';
//	}
//	return 0;
//}

//task 2

//
//class Member
//{
//public:
//	Member()
//	{
//		cout << " Member generated\n";
//	}
//
//};
//
//class A
//{
//	int m_x;
//	Member m_memeber;
//public:
//
//
//	A(int x) :m_x(x)
//	{
//		if (x <= 0)
//		{
//			throw 1;
//		}
//	
//	}
//	~A()
//	{
//		cout << "~A()";
//	}
//};
//
//
//int main()
//{
//
//	try
//	{
//		A a(0);
//	}
//	catch(int)
//	{
//		cout << "oops\n";
//	}
//	return 0;
//}



// task 1

//
//class Base
//{
//public:
//	Base()
//	{
//		cout << "in base\n";
//	}
//
//};
//
//class Derived :public Base
//{
//public:
//	Derived()
//	{
//		cout << "in Derived\n";
//	}
//};
//
//int main()
//{
//	try
//	{
//		throw Derived();
//	}
//	catch (Base & base)
//	{
//		cout << "caught base\n";
//	}
//	catch (Derived & derived)
//	{
//		cout << "caught Derived\n";
//	}
//
//	return 0;
//}