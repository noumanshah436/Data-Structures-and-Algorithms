#include<iostream>
using namespace std;


class JosephusList;
class Node {
	friend class JosephusList;
private:
	int data;
	Node* next;
};

class JosephusList {
private:
	Node* head;
public:

	~JosephusList()
	{
		if (head == nullptr)
		{
			return;
		}
		Node * p = head;
		do 
		{
			Node * x = p;
			p = p->next;
			delete x;
		} while (p != head);
	}

	void display()
	{
		if (head == nullptr)
		{
			return;
		}
		Node * p = head;
		do
		{
			cout << p->data << " ";
			p = p->next;
			
		} while (p != head);
	}


	bool removeKthNode(int k, int& val)
	{


		int count = 0;
		Node * f = head;

		do
		{
			count = count + 1;
			f = f->next;

		} while (f != head);

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


	JosephusList(int N)
	{
		if (N == 0)
		{
			head = nullptr;
		}
		head = new Node;
		Node*p = head;
		p->data = 1;
		for (int i = 2; i <= N; i++)
		{
			p->next = new Node;
			p->next->data = i;
			p = p->next;

		}
		p->next = head;
	}

	int getWinner(int M)
	{

		int count = 0;
		Node * f = head;

		do
		{
			count = count + 1;
			f = f->next;

		} while (f != head);
		int k = 1;
		for (int i = 1; i <= (count - 1); i++)
		{
			
			k = (k + M) % count;
			int c;    //   just for function parameter
			removeKthNode(k, c);
			k = k + 1;
		}
		return head->data;
	}
};


int main()
{

	JosephusList a(5);
	a.display();
	cout << endl;
	cout<<a.getWinner(1);    //   incomplete

	return 0;
}

/*
int main()
{


	CDLinkedList a;
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	a.insert(8);

	cout << "\nactual CDLinkedList : \n";
	a.display();

	int dataRemoved;

	a.removeLastNode(dataRemoved);
	cout << "\n\ndata removed after removeLastNode function :" << dataRemoved << "\n";
	a.display();

	a.removeSecondLastNode(dataRemoved);
	cout << "\n\ndata removed after removeSecondLastNode function :" << dataRemoved << "\n";
	a.display();

	int dataNew;

	a.removeKthNode(2, dataNew);
	cout << "\n\ndata removed after removeKthNode function :" << dataNew << "\n";
	a.display();


	cout << "\n\n";
	return 0;
}
*/

