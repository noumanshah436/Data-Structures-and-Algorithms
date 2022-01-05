#include<iostream>
using namespace std;
#include"BinaryTree.h"


int main()
{
	//  Task # 1
	BinaryTree a;

	//  Task # 2
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	
	
	//Task # 3
	cout << "Pre Ordre  : ";
	a.preOrder();
	cout << "\n";

	cout << "In Ordre   : ";
	a.inOrder();
	cout << "\n";

	cout << "Post Ordre : ";
	a.postOrder();
	cout << "\n";


	return 0;
}