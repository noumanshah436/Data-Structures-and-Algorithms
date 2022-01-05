

#include<iostream>
#include"CDLL.h"
#include"LDLL.h"
#include"LSLL.h"
using namespace std;


//drive foor CDLL



int fun(int i)
{

	if (i % 2)return (i++);
	else return fun(fun(i - 1));
}
int main()
{
	cout << " " << fun(200) << " ";
	//CDLL<int> a;

	//a.insertAtHead(5);
	//a.insertAtHead(4);
	//a.insertAtHead(3);
	//a.insertAtHead(0);
	//a.insertAtHead(1);
	//a.insertAtHead(4);
	//a.insertAtHead(7);
	//a.insertAtHead(6);

	////a.remove(5);


	//cout << "\nhello\n";
	//a.middle();
	//return 0;
}


//   driver for LSLL
/*
int main()
{
	LSLL<int> q;
	q.insertAtHead(0);
	q.insertAtHead(3);
	q.insertAtHead(2);
	q.insertAtHead(4);
	
	q.display();
	cout << "\n";
	LSLL<int> q2;
	q2.insertAtHead(8);
	q2.insertAtHead(6);
	q2.insertAtHead(4);
	
	q2.display();
	cout << "\n";

	q.doUnion(q2);

	cout << "\nhello";
	return 0;
}
*/

//   driver for LDLL
/*

int main()
{
	LDLL<int> a;
	a.insertAtHead(0);
	a.insertAtHead(2);
	a.insertAtHead(3);
	a.insertAtHead(4);

	a.remove(2);
	a.remove(3);
	//.insertAfter(3, 4);
	//a.removeAtTail();
	//a.removeAtHead();
	//a.removeAtTail();
	//a.removeAtTail();
	//a.removeAtTail();
	//a.removeAtTail();
	//a.insertBefore(2, 1);
	//a.insertAtTail(10);
	a.display();

	cout << "hello";

	return 0;
}
*/
