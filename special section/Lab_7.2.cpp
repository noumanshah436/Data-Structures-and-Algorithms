#include<iostream>
using namespace std;


class Node {
public:
	int	data;
	Node* next;
	Node* previous;

	Node()
	{
		data = 0;
		next = NULL;
		previous = NULL;
	}
	int getData()
	{
		return data;
	}	
	Node* getNext()
	{
		return next;
	}
	Node* getPrevious()
	{
		return previous;
	}
	void setNext(Node* temp)
	{
		next = temp;
	}
	void setPrevious(Node* temp)
	{
		previous = temp;
	}
	void setData(int temp)
	{
		data = temp;
	}
	~Node()
	{
		data = 0;
		delete next;
		delete previous;
	}
};

class DoubleLinkedList {
private:
	Node* head;
	Node* tail;

public:
	DoubleLinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	Node* getHead()
	{
		return head;
	}
	Node* getTail()
	{
		return tail;
	}
	void setHead(Node* temp)
	{
		head = temp;
	}
	void setTail(Node* temp)
	{
		tail = temp;
	}
	void AddAtHead(int value)
	{
		if (size() == 0)
		{
			Node* newNode = new Node;
			head = newNode;
			tail = newNode;

			head->setData(value);
			head->setPrevious(NULL);
			head->setNext(NULL);

			tail->setData(value);
			tail->setPrevious(NULL);
			tail->setNext(NULL);
		}
		else
		{
			Node* tempNode = head;
			Node* newNode = new Node;
			head = newNode;
			head->setData(value);
			head->setPrevious(NULL);
			head->setNext(tempNode);
			tempNode->setPrevious(head);
		}
	}
	void AddAtTail(int value)
	{
		if (size() == 0)
		{
			Node* newNode = new Node;
			head = newNode;
			tail = newNode;

			head->setData(value);
			head->setPrevious(NULL);
			head->setNext(NULL);
			
			tail->setData(value);
			tail->setPrevious(NULL);
			tail->setNext(NULL);
		}
		else
		{
			Node* tempNode = tail;
			Node* newNode = new Node;
			tail = newNode;
			tail->setData(value);
			tail->setPrevious(tempNode);
			tail->setNext(NULL);
			tempNode->setNext(tail);
		}
	}
	int RemoveAtHead()
	{
		int value = 0;
		if (size() == 0)
		{
			cout << "\nDouble Linked List is Empty. It returns Zero ";
			return value;
		}
		else if (size() == 1)
		{
			value = head->getData();
			head->setData(0);
			tail->setData(0);
			head = NULL;
			tail = NULL;
			return value;
		}
		else
		{
			value = head->getData();
			head = head->getNext();
			head->setPrevious(NULL);
			return value;
		}
	}
	int RemoveAtTail()
	{
		int value = 0;
		if (size() == 0)
		{
			cout << "\nDouble Linked List is Empty. It returns Zero ";
			return value;
		}
		else if (size() == 1)
		{
			value = tail->getData();
			head->setData(0);
			tail->setData(0);
			head = NULL;
			tail = NULL;
			return value;
		}
		else
		{
			value = tail->getData();
			tail = tail->getPrevious();
			tail->setNext(NULL);
			return value;
		}
	}
	int& operator[](int value)
	{
		int num = 0;
		if (value < 0 || value >= size())
			return num;

		Node* currentNode = head;
		for (int i = 0; i < value; i++)
		{
			currentNode = currentNode->getNext();
		}
		return currentNode->data;
	}
	int size()
	{
		int count = 0;
		Node* currentNode = head;
		while (currentNode != NULL)
		{
			count++;
			currentNode=currentNode->getNext();
		}
		return count;
	}
	void DisplayAll()
	{
		cout << "\nValues of Double Linked List : ";
		DoubleLinkedList temp;
		temp.head = head;
		for (int i = 0; i < size(); i++)
		{
			cout << temp[i] << " ";
		}
		cout << endl;
	}
	void Sort()
	{
		DoubleLinkedList temp;
		temp.head = head;
		for (int i = 0; i < size() - 1; i++)
		{
			for (int j = 0; j < size() - i - 1; j++)
			{
				int &a = temp[j];
				int &b = temp[j+1];
				if (a > b)
				{
					int temp = a;
					a = b;
					b = temp;
				}
			}
		}
	}
};

void DisplayInReverse(Node* tail);

int main()
{
	DoubleLinkedList task2;	
	
	task2.AddAtHead(9);
	task2.AddAtHead(1);
	task2.AddAtHead(8);
	
	task2.AddAtTail(7);
	task2.AddAtTail(6);
	task2.AddAtTail(0);
	
	task2.DisplayAll();
	DisplayInReverse(task2.getTail());

	task2.Sort();
	task2.DisplayAll();
	DisplayInReverse(task2.getTail());

	cout << task2.RemoveAtTail() << endl;
	cout << task2.RemoveAtTail() << endl;
	cout << task2.RemoveAtTail() << endl;
	cout << task2.RemoveAtTail() << endl;
	cout << task2.RemoveAtTail() << endl;
	cout << task2.RemoveAtHead() << endl;
	cout << task2.RemoveAtHead() << endl;
	
	return 0;
}

void DisplayInReverse(Node* tail)
{
	cout << "\nValues in Reverse Order of Double Linked List : ";
	DoubleLinkedList temp;
	temp.setHead(tail);

	while (tail != NULL)
	{
		temp.setHead(tail);
		tail = tail->getPrevious();
	}
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		cout << temp[i] << " ";
	}
	cout << endl;
}