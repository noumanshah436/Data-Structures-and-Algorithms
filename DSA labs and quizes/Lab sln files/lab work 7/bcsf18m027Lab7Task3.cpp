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

	void combine(LinkedList & list1, LinkedList& list2)
	{
		if (list1.head == nullptr && list2.head == nullptr)
		{
			head = nullptr;
			return;
		}

		if (list1.head == nullptr)    //  if List1 is empty only store List2 in calling object and return
		{
			head = list2.head;
			list2.head = nullptr;
			return;
		}
		
		head = list1.head;
		list1.head = nullptr;

		if (list2.head != nullptr)
		{
			Node * p = head;
			while (p->next != nullptr)    // find address of last node in list
			{
				p = p->next;
			}
			p->next = list2.head;
			list2.head = nullptr;
		}
	
	}
};



int main()
{
	
	LinkedList a;
	a.insert(21);
	a.insert(19);
	a.insert(17);
	a.insert(15);
	a.insert(13);
	cout << "linked list a :";
	a.display();
	cout << "\n\n";

	LinkedList b;
	b.insert(11);
	b.insert(9);
	b.insert(7);
	b.insert(5);
	b.insert(3);
	cout << "linked list b :";
	b.display();
	cout << "\n\n";

	LinkedList c;
	c.insert(0);
	c.insert(1);
	c.insert(2);
	cout << "linked list c :";
	c.display();
	cout << "\n\n";

	LinkedList d;    //  empty list




	cout << "combine two non empty LinkedList's b and a :";
	LinkedList e;    //   in case of two non empty LinkedList's
	e.combine(b, a);
	e.display();

	cout << "\n\n";

	cout << "in case of one empty LinkList d and non empty c:";
	LinkedList f;
	f.combine(d,c);
	f.display();

	cout << "\n\n";

	return 0;
}
