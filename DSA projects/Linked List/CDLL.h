#ifndef CDLL_H
#define CDLL_H
#include"DNode.h"
#include<iostream>
using namespace std;

template <typename T>
class CDLL
{
	DNode<T> * head;
public:
	CDLL()
	{
		head = nullptr;
	}

	void insertAtHead(T val)
	{
		if (head == nullptr)
		{
			head = new DNode<T>(val);
			head->prev = head;
			head->next = head;
			return;
		}
		DNode<T>*x = new DNode<T>(val);
		x->next = head;
		x->prev = head->prev;
		x->prev->next = x;
		head->prev = x;
		head = x;

	}
	void insertAtTail(T val)
	{
		if (head == nullptr)
		{
			head = new DNode<T>(val);
			head->prev = head;
			head->next = head;
			return;
		}
		DNode<T>*x = new DNode<T>(val);
		x->next = head;
		x->prev = head->prev;
		head->prev->next = x;
		head->prev = x;

	}
	void insertAfter(T key, T val)
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->prev->info == key)
		{
			DNode<T>*x = new DNode<T>(val);
			x->next = head;
			x->prev = head->prev;
			head->prev->next = x;
			head->prev = x;
			return;
		}
		DNode<T>*p = head;
		do
		{
			if (p->info == key)
			{
				DNode<T>*x = new DNode<T>(val);
				x->next = p->next;
				x->prev = p;
				p->next = x;
				x->next->prev = x;
				return;

			}
			p = p->next;

		} while (p != head);
	}
	void insertBefore(T key, T val)
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->info==key)
		{
			DNode<T>*x = new DNode<T>(val);
			x->next = head;
			x->prev = head->prev;
			x->prev->next = x;
			head->prev = x;
			head = x;
			return;
		}
		DNode<T>*p = head;
		do
		{
			if (p->info == key)
			{
				DNode<T>*x = new DNode<T>(val);
				x->next = p;
				x->prev = p->prev;
				p->prev = x;
				x->prev->next = x;
				return;

			}
			p = p->next;

		} while (p != head);


	}
	void removeAtHead()
	{
		if (head == nullptr)
		{
			return;
		}
		DNode<T>*x = head;
		head->next->prev = head->prev;
		head->prev->next = head->next;
		head = head->next;
		delete x;

	}
	void removeAtTail()
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->next == head)
		{
			//cout << head->prev << " " << head->next<<"\n";
			delete head;
			head = nullptr;
			return;
		}
		head->prev = head->prev->prev;
		delete head->prev->next;
		head->prev->next = head;
	}
	void removeAfter(T key)    // sir
	{
		if (head == nullptr)
		{
			return;
		}

		DNode<T>*p = head;
		do
		{
			if (p->info == key)
			{
				if (p->next == head)
				{
					removeAtHead();
					return;
				}
				p->next = p->next->next;
				delete p->next->prev;
				p->next->prev=p;
				return;

			}
			p = p->next;
		} while (p != head);
	}
	void removeBefore(T key)
	{
		if (head == nullptr)
		{
			return;
		}
		if (key==head->next->info)
		{
			removeAtHead();
			return;
		}
		DNode<T>*p = head;
		do
		{
			if (p->info == key)
			{
				if (p->info == head->info)   //  if key = info of head node
				{
					removeAtTail();
					return;
				}
				p->prev = p->prev->prev;
				delete p->prev->next;
				p->prev->next = p;
				return;

			}
			p = p->next;
		} while (p != head);

	}
		
	void remove(T key)
	{
		if (head == nullptr)
		{
			return;
		}

		if (head->info == key)
		{
			removeAtHead();
			return;
		}

		DNode<T>*p = head;
		do
		{
			if (p->info == key)
			{
				p->next->prev = p->prev;
				p->prev->next = p->next;
				delete p;
				return;
			}
			p = p->next;
		} while (p != head);

	}
	
	void display()
	{
		if (head == nullptr)
		{
			return;
		}
		DNode<T>*p = head;
		do
		{
			cout << p->info << " ";
			p = p->next;
		} while (p != head);
		cout << "\n";
		p = head->prev;
		do
		{
			cout << p->info << " ";
			p = p->prev;
		} while (p != head->prev);
	}
	

};

#endif

