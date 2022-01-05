#ifndef LDLL_H
#define LDLL_H
#include"DNode.h"

#include<iostream>
using namespace std;


template <typename T>
class LDLL
{
	DNode<T> * head;
public:
	LDLL()
	{
		head = nullptr;
	}
	void insertAtHead(T val)     //   sir
	{
		if (head == nullptr)
		{
			head = new DNode<T>(val);
			return;
		}
		DNode<T> * x = new DNode<T>(val);
		x->next = head;
		head->prev = x;
		head = x;
	}
	~LDLL()
	{
		while (head)
		{
			removeAtHead();

		}
		cout << "\n~LDLL()";
	}
	void insertAtTail(T val)
	{
		if (head == nullptr)
		{
			head = new DNode<T>(val);
			return;
		}
		DNode<T> *p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new DNode<T>(val);
		p->next->prev = p;
	}
	void insertAfter(T key, T val)
	{
		if (head == nullptr)
		{
			return;
		}
		DNode<T> *p = head;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				DNode<T> * x = new DNode<T>(val);
				x->next = p->next;
				x->prev = p;
				p->next = x;
				x->next->prev = x;
				break;
			}

			p = p->next;
		}

	}
	void insertBefore(T key, T val)    //   sir
	{
		if (head == nullptr)
		{
			return;
		}
		DNode<T> * p = head;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				DNode<T> * x = new DNode<T>(val);
				x->next = p;
				x->prev = p->prev;
				p->prev->next = x;
				p->prev = x;
				break;
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
		DNode<T> * x = head;
		head = head->next;
		if (head != nullptr)
		{
			head->prev = nullptr;
		}

		delete x;
	}
	void removeAtTail()
	{
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		DNode<T>*p = head;
		while (p != nullptr)
		{
			if (p->next == nullptr)  //   we cannot manage the head case i.e single node case here because we have to delete head and set it to nullptr
			{
				p->prev->next = nullptr;
				delete p;
				break;
			}
			p = p->next;
		}

	}
	void removeAfter(T key)
	{
		DNode<T>* p = head;
		while (p != nullptr)
		{
			if (p->info == key && p->next != nullptr)
			{
				DNode <T>* x = p->next;
				p->next = x->next;
				if (x->next)
					x->next->prev = p;
				delete x;
				return;
			}
			p = p->next;
		}
	}
	void removeBefore(T key)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}
		if (head->next->info == key)
		{
			DNode<T>* x = head;
			head = x->next;
			x->next->prev = nullptr;
			return;
		}
		DNode<T>* p = head;
		while (p != nullptr)
		{

			if (p->info == key)
			{
				DNode<T>* x = p->prev;
				x->prev->next = p;
				p->prev = x->prev;
				delete x;
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
		if (head->info == key)
		{
			DNode<T> * x = head;
			head = head->next;
			if (head != nullptr)
			{
				head->prev = nullptr;
			}
			delete x;
			return;
		}
		DNode<T>* p = head;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				if (p->next == nullptr)
				{
					p->prev->next = nullptr;
					delete p;
					break;
				}
				p->prev->next = p->next;
				p->next->prev = p->prev;
				delete p;
				break;

			}

			p = p->next;
		}
	}
	void display()    //   sir
	{
		if (head == nullptr)
		{
			return;
		}
		DNode<T>*tail = nullptr;
		DNode<T> *p = head;
		while (p != nullptr)
		{
			tail = p;
			cout << p->info << " ";
			p = p->next;
		}
		cout << endl;
		while (tail != nullptr)
		{
			cout << tail->info << " ";
			tail = tail->prev;
		}
		cout << endl;
	}
};

#endif


