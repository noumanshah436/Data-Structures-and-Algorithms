#include<iostream>
using namespace std;
#include"ArrayBasedBinaryTree.h"
#include"LinkedBinaryTree.h"
int main()
{

	LinkedBinaryTree<char> a;
	a.setRoot('A');
	a.setLeftChild('A', 'B');
	a.setRightChild('A', 'C');
	a.setLeftChild('C', 'D');
	a.setRightChild('C', 'E');
	a.setLeftChild('D', 'F');
	a.setRightChild('D', 'G');
	a.preOrder();
	cout << endl;
	a.inOrder();
	cout << endl;
	a.postOrder();
	cout << "\nhello\n";

	/*ArrayBasedBinaryTree<char> a;
	a.setRoot('A');
	a.setLeftChild('A', 'B');
	a.setRightChild('A', 'C');
	a.setLeftChild('C', 'D');
	a.setRightChild('C', 'E');
	a.setLeftChild('D', 'F');
	a.setRightChild('D', 'G');
	a.preOrder();
	cout << endl;
	a.inOrder();
	cout << endl;
	a.postOrder();
	cout << "\nhello\n";*/
	return 0;
}