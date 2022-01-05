#include<iostream>
using namespace std;
#include"ArrayBasedBinaryTree.h"
#include"LinkedBinaryTree.h"


int main()
{
	
	
	
	cout << "ArrayBasedBinaryTree\n";

	ArrayBasedBinaryTree<char> a;
	a.setRoot('A');
	a.setLeftChild('A', 'B');
	a.setRightChild('A', 'C');
	a.setLeftChild('C', 'D');
	a.setRightChild('C', 'E');
	a.setLeftChild('D', 'F');
	a.setRightChild('D', 'G');
	a.displayDescendants('A');
	cout << "\n";
	a.displayAncestors('G');
	a.remove('G');
	a.preOrder();
	cout << endl;
	a.inOrder();
	cout << endl;
	a.postOrder();
	
	

	cout << "\n\nLinkedBinaryTree\n";

	LinkedBinaryTree<char> b;
	b.setRoot('A');
	b.setLeftChild('A', 'B');
	b.setRightChild('A', 'C');
	b.setLeftChild('C', 'D');
	b.setRightChild('C', 'E');
	b.setLeftChild('D', 'F');
	b.setRightChild('D', 'G');

	//cout << b.getHeight();
	b.preOrder();
	cout << endl;
	b.inOrder();
	cout << endl;
	b.postOrder();

	return 0;
}