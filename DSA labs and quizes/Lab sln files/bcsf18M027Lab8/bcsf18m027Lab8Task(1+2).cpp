#include<iostream>
using namespace std;

class CDLinkedList;
class DNode
{
	friend class CDLinkedList;
private:
	int data;
	DNode* next;
	DNode* prev;
};
class CDLinkedList
{
private:
	DNode head; // Dummy header node
public:
	CDLinkedList() // Default constructor
	{
		head.next = &head;
		head.prev = &head;
		
	}
	~CDLinkedList() // Destructor
	{
		if (&head == head.prev)
		{
			return;
		}
		
		DNode* x = head.next;
		do
		{
			DNode* p = x;
			x = x->next;
			delete p;
		} while (x != &head);

		head.next = &head;
		head.prev = &head;
	}
	bool insert(int val) // Inserts val at the start of linked list - Time complexity: O(1)
	{
		

		DNode* x = new DNode;
		x->data = val;
		x->next = head.next;
		x->prev = &head;

		if (head.prev == &head)   // means list is empty
		{
			head.prev = x;
		}
		else
		{
			head.next->prev = x;
		}
		head.next = x;
		
		return true;

	}

	//  task2 functions

	bool removeLastNode(int& val) //Time complexity : O(1)
	{
		if (&head == head.prev)
		{
			return false;
		}
		
		val = head.prev->data;
		head.prev = head.prev->prev;
		delete head.prev->next;
		head.prev->next = &head;
		return true;
	
	}

	bool removeSecondLastNode(int& val)
	{
		if (&head == head.prev  ||  head.next->next== &head)  // in case of empty list or single node in list 
		{
			return false;
		}
		DNode* x = head.prev->prev;
		val = x->data;
		x->prev->next = x->next;
		x->next->prev = x->prev;
		delete x;
	}

	bool removeKthNode(int k, int& val)
	{
		if (&head == head.prev )  // in case of empty list 
		{
			return false;
		}
		int countNode = 0;        //  count total nodes in list
		DNode* h = head.next;
		do
		{
			countNode = countNode + 1;
			h = h->next;
		} while (h != &head);
		if (k > countNode)          //   in case of nodes less than k
		{
			return false;
		}

		if (k == 1)
		{
			DNode * x = head.next;
			val = x->data;
			head.next = x->next;
			x->next->prev = &head;
			delete x;
			return true;
		}

		DNode *p = head.next;
		for (int i = 0; i < (k - 2); i++)    //   to find adress of the node that is behind the desired removing node
		{
			p = p->next;
		}

		if (p->next->next == &head)      //   if removing node is the last node
		{
			val = head.prev->data;
			head.prev = head.prev->prev;
			delete head.prev->next;
			head.prev->next = &head;
			return true;
			
		}
		else                      //   otherwise 
		{
			DNode * x = p->next;
			val = x->data;
			x->next->prev = x->prev;
			x->prev->next = x->next;
			delete x;
			return true;
		}
	}

	void combine(CDLinkedList& list1, CDLinkedList& list2)
	{

		if (&list1.head == list1.head.next && &list2.head == list2.head.next)
		{
			return;
		}

		if (&list1.head == list1.head.next)    //  if List1 is empty only store List2 in calling object and return
		{
			list2.head.next->prev = &head;
			list2.head.prev->next = &head;
			head.next = list2.head.next;
			head.prev = list2.head.prev;

			list2.head.next = &list2.head;   //  make list2  empty
			list2.head.prev= &list2.head;


			return;
		}
		                                          // otherwise store list1 first in calling object
		list1.head.next->prev = &head;
		list1.head.prev->next = &head;
		head.next = list1.head.next;
		head.prev = list1.head.prev;
		list1.head.next = &list1.head;     //  madee list1  empty
		list1.head.prev = &list1.head;
		
		if (&list2.head != list2.head.next)  // Now if list2 is not empty, then combine list2 also in calling object,    otherwise do nothing
		{
			head.prev->next = list2.head.next;
			list2.head.next->prev = head.prev;
			head.prev = list2.head.prev;
			head.prev->next = &head;

			list2.head.next = &list2.head;     //  make list2  empty
			list2.head.prev = &list2.head;

		}
	}

	void display() // Display the contents of linked list on screen
	{
		if (head.next == &head)
		{
			return;
		}

		DNode* p = head.next;
		do
		{
			cout << p->data<< " ";
			p = p->next;
		} while (p != &head);

		cout << "\n";
		p = head.prev;
		do
		{
			cout << p->data<< " ";
			p = p->prev;
		} while (p != &head);

	}
	
};


int main() 
{


	CDLinkedList a;
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	a.insert(8);
	int j = -1;

	cout << "\nactual CDLinkedList : \n";
	a.display();
	
	int dataRemoved;

	a.removeLastNode(dataRemoved);
	cout << "\n\ndata removed after removeLastNode function :" << dataRemoved<<"\n";
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

