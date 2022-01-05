#include<iostream>
using namespace std;

class LinkedList;
class Node 
{
	friend class LinkedList;
private:
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() // Default constructor
	{
		head = nullptr;
	}
	~LinkedList() // Destructor
	{
		while (head != nullptr)
		{
			Node * x = head;
			head = head->next;
			delete x;
		}
		cout << "\n~LinkedList()";
	}

	void display()
	{
		Node * p = head;
		while (p!=nullptr)
		{
			cout << p->data<<" ";
			p = p->next;

		}
	}

	bool insert(int val)
	{
		Node *x = new Node;
		x->data = val;
		x->next = head;
		head = x;
		return true;
	}

	int countNodes()
	{
		int count=0;
		Node * p = head;
		while (p != nullptr)
		{
			count = count + 1;
			p = p->next;

		}
		return count;
	}
};



int main()
{
	LinkedList a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.display();
	cout << "\n" << a.countNodes();
	return 0;
}