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

	bool removeSecondLastNode(int& val)
	{
		if (head == nullptr)
		{
			return false;
		}
		if (head->next->next == nullptr)   //  in case of only two nodes
		{
			Node * x = head;
			val=x->data;
			head = x->next;
			delete x;
			return true;
		}

		Node * p = head;                 //  in case of more than two nodes
		while (p != nullptr)
		{
			if (p->next->next->next == nullptr)
			{
				Node * x = p->next;
				val = p->next->data;
				p->next = p->next->next;
				delete x;
				return true;
			}
			p = p->next;
		}
	}

	bool removeLastNode(int& val)
	{
		if (head == nullptr)
		{
			return false;
		}
		if (head->next == nullptr)
		{
			val = head->data;
			delete head;
			head = nullptr;
			return true;
		}

		Node * p = head;
		while (p != nullptr)
		{
			if (p->next->next == nullptr)
			{

				val= p->next->data;
				delete p->next;
				p->next = nullptr;
				return true;
			}
			p = p->next;
		}
		
	}

	
	bool removeKthNode(int k, int& val)
	{


		int count = 0;
		Node * f = head;
		while (f != nullptr)           //  find count of nodes
		{
			count = count + 1;
			f = f->next;

		}
		if (k > count)
		{
			return false;
		}

		if (head == nullptr)
		{
			return false;
		}
		if (k == 1)
		{
			Node * x = head;
			val = x->data;
			head = x->next;
			delete x;
			return true;
		}

		Node *p = head;
		for (int i = 0; i < (k - 2); i++)    //   to find adress of the node that is behind the desired removing node
		{
			p = p->next;
		}

		if (p->next->next == nullptr)      //   if removing node is the last node
		{
			val = p->next->data;
			delete p->next;
			p->next = nullptr;
			return true;
		}
		else
		{
			Node * x = p->next;
			val = x->data;
			p->next = x->next;
			delete x;
			return true;
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
	a.insert(11);
	a.insert(9);
	a.insert(7);
	a.insert(5);
	a.insert(3);
	a.display();
	cout << "\ntotal nodes:" << a.countNodes() << "\n";

	int dataRemoved;

	a.removeLastNode(dataRemoved);
	cout << "\n\ndata removed :" << dataRemoved;
	cout << "\ntotal nodes:" << a.countNodes() << "\n";
	a.display();

	a.removeSecondLastNode(dataRemoved);
	cout << "\n\ndata removed :" << dataRemoved;
	cout << "\ntotal nodes:" << a.countNodes() << "\n";
	a.display();

	int dataNew;

	a.removeKthNode(4, dataNew);
	cout << "\n\ndata removed :" << dataNew;
	cout << "\ntotal nodes:" << a.countNodes() << "\n";
	a.display();


	return 0;
}