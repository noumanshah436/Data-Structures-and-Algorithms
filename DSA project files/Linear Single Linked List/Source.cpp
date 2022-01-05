#include<iostream>
using namespace std;

template <typename T>
struct Node
{
	T info;;
	Node<int> * next;

	Node()
	{
		next = nullptr;
	}
	Node(T val)
	{
		info = val;
		next = nullptr;
	}
};


template <typename T>
class LSLL
{
	Node<T> *head ;

public:
	LSLL()
	{
		head = nullptr;
	}
	void display()
	{
		Node<int> *p = head;
		while (p != nullptr)
		{
			cout << p->info << " ";
			p = p->next;
		}
	}
	void insertAtHead(T val)
	{
		Node<int> *x = new Node<T>(val);
		x->next = head;
		head = x;
	}
	void insertAtTail(T val)
	{

		if (head == nullptr)
		{
			head= new Node<T>(val);
			return;
		}
		Node<T> *p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new Node<T>(val);
	}
	void insertAfter(T key, T val)
	{
		if (head == nullptr)
		{
			return;
		}
		Node<int> *p = head;
		while (p != nullptr)
		{
			if (p->info==key)
			{
				Node<T> *x = new Node<T>(val);
				x->next = p->next;
				p->next=x;
				x = nullptr;
				break;
			}
			p = p->next;
		}

	}

	void insertBefore(T key, T val)
	{
		if (head == nullptr)
		{
			return;
		}
		if (key==head->info)
		{
			Node<T> *x = new Node<T>(val);
			x->next=head;
			head = x;
			return;
		}
		Node<T> *p = head;
		while (p != nullptr)
		{
			if (p->next && p->next->info == key)
			{
				Node<T> *x = new Node<T>(val);
				x->next = p->next;
				p->next = x;
				break;
			}
			p = p->next;
		}

	}
	void remove(T key)
	{
		if (head == nullptr)
		{
			return;
		}
		if(head->info==key)
		{ 
			Node<T>*x = head;
			head = head->next;
			delete x;
			
			return;
		}
		Node<int> *p = head;
		while (p != nullptr)
		{
			if (p->next  && p->next->info == key)
			{
				Node<T>*x= p->next;
				p->next=p->next->next;
				delete x;
				return;
			}
			p = p->next;
		}


	}
	void removeAtHead()
	{
		if (head == nullptr)
		{
			return;
		}
		head = head->next;
	}
	void removeAtTail()
	{
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		Node<T>*p = head;
		while (p != nullptr)
		{
			if (p->next->next == nullptr)
			{
				delete p->next;
				p->next = nullptr;
				break;
			}
			p = p->next;
		}

	}
	void removeAfter(T key)
	{
		if (head == nullptr)
		{
			return;
		}
		Node<T>*p = head;
		while (p !=nullptr)
		{ 
			if (p->info == key)
			{
				Node<T>*x = p->next;
				if (x == nullptr)
				{
					return;
				}
				p->next = x->next;
				delete x;
				return;
			}


			p = p->next;
		}


	}
	void removeBefore(T key);



};




int main()
{
	LSLL<int> q;
	
	q.insertAtHead(3);
	q.insertAtTail(10);
	q.insertAtHead(2);
	q.insertAtHead(0);
	q.remove(0);
	q.display();

	return 0;
}

/*
q.insertAtHead(3);
	q.insertAtTail(10);
	q.insertAtHead(1);
	q.insertAfter(3, 30);
	q.insertAfter(3, 30);
	q.insertAfter(10, 40);
	q.insertBefore(10, 300);
	
	q.display();
*/