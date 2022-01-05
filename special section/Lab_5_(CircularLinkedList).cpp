#include<iostream>
using namespace std;

class Node {
public:
	int	data;
	Node* next;
};
class CircularLinkedList {
public:
	Node* head;

	CircularLinkedList();
	void loopPrinting(Node*);
	void Insert(int);
	int Delete(int d);
	void Print();
	int Update(Node*, int);
	int ElementCount();
	int Get(int);
	bool Find(int);
	void Clear();
	~CircularLinkedList();
};

int GetJosephus(CircularLinkedList*, int, int);

int main()
{
	CircularLinkedList test;
	Node* n = new Node;
	n->data = 10;

	cout << "\t\t\tTASK 1\n";
	cout << "--------------TESTING Insert FUNCTION--------------\n";
	test.Insert(1); test.Insert(2); test.Insert(3); test.Insert(4);
	test.Insert(5); test.Insert(6); test.Insert(7); test.Insert(8);
	cout << "Elements In Circular Linked List : "; test.Print();

	cout << "\n\n--------------TESTING Update FUNCTION--------------\n";
	test.Update(n, 8);
	cout << "Elements In Circular Linked List : "; test.Print();

	cout << "\n\n--------------TESTING Delete FUNCTION--------------\n";
	test.Delete(10);
	cout << "Elements In Circular Linked List : "; test.Print();

	cout << "\n\n--------------TESTING ElementTCount FUNCTION-------\n";
	cout << "Number Of Elements In Circular Linked List: " << test.ElementCount() << endl;
	cout << "Elements In Circular Linked List : "; test.Print();

	cout << "\n\n--------------TESTING Get FUNCTION-----------------\n";
	cout << "Element At Given Position: " << test.Get(4) << endl;
	cout << "Elements In Circular Linked List : "; test.Print();

	cout << "\n\n--------------TESTING Find FUNCTION----------------\n";
	if (test.Find(9))
		cout << "Given Element Found" << endl;
	else
		cout << "Given Element Not Found" << endl;
	cout << "Elements In Circular Linked List : "; test.Print();

	cout << "\n\n\t\t\tTASK 2\n";
	cout << "\nThe person to survive is: " << GetJosephus(&test, test.ElementCount(), 3) << endl;

	return 0;
}

///////////////MEMBER FUNCTION OF CircularLinkedList///////////////
CircularLinkedList::CircularLinkedList()
{
	head = NULL;
}
void CircularLinkedList::loopPrinting(Node* currentNode)
{
	if (currentNode == NULL)
	{
		return;
	}
	if (currentNode->next == head)
	{
		cout << currentNode->data << " ";
		return;
	}
	cout << currentNode->data << " ";
	loopPrinting(currentNode->next);
}
void CircularLinkedList::Insert(int d)
{
	if (head == NULL)								//NODE INSERTED AT FIRST POSITION
	{
		Node* newNode = new Node;
		head = newNode;
		newNode->data = d;
		newNode->next = head;
	}
	else										//NODE INSERTED AT LAST POSITION
	{
		Node* currentNode = head;
		while (currentNode->next != head)
		{
			currentNode = currentNode->next;
		}
		Node* newNode = new Node;
		currentNode->next = newNode;
		newNode->data = d;
		newNode->next = head;
	}
}
int CircularLinkedList::Delete(int d)
{
	if (head == NULL)
	{
		return -1;										//NODE IS EMPTY
	}
	Node* currentNode = head;
	Node* previousNode = head;
	int currentIndex = 0;
	while (currentNode->next != head)
	{
		if (currentNode->data == d)
		{
			if (currentIndex == 0)						//DELETE NODE AT START
			{
				head = head->next;
				while (currentNode->next != previousNode)
				{
					currentNode = currentNode->next;
				}
				currentNode->next = head;
				delete previousNode;
				return currentIndex + 1;
			}
			else										//DELETE NODE AT MID
			{
				previousNode->next = currentNode->next;
				delete currentNode;
				return currentIndex + 1;
			}
		}
		currentIndex++;
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	if (head->next == head)								//DELETE NODE AT START WHEN ONLY ONE NODE
	{
		head = NULL;
		return currentIndex + 1;
	}
	else if (currentNode->data == d)						//DELETE NODE AT LAST
	{
		previousNode->next = currentNode->next;
		delete currentNode;
		return currentIndex + 1;
	}
	else
	{
		return -1;										//ELEMENT NOT FOUND
	}
}
void CircularLinkedList::Print()
{
	loopPrinting(head);
}
int CircularLinkedList::Update(Node* nNode, int d)
{
	if (head == NULL)
	{
		return -1;										//NODE IS EMPTY
	}
	Node* currentNode = head;
	Node* previousNode = head;
	int currentIndex = 0;
	while (currentNode->next != head)
	{
		if (currentNode->data == d)						//UPDATE NODE AT START AND AT MID
		{
			nNode->next = currentNode->next;
			currentNode->data = nNode->data;
			currentNode = nNode;
			return currentIndex + 1;
		}
		currentIndex++;
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode->data == d)							//UPDATE NODE AT LAST
	{
		nNode->next = currentNode->next;
		currentNode->data = nNode->data;
		currentNode = nNode;
		return currentIndex + 1;
	}
	return -1;											//ELEMENT NOT FOUND
}
int CircularLinkedList::ElementCount()
{
	Node* currentNode = head;
	int elementCounter = 0;
	if (head == NULL)
	{
		return -1;										//NODE IS EMPTY
	}
	else
	{
		while (currentNode->next != head)
		{
			currentNode = currentNode->next;
			elementCounter++;
		}
		return elementCounter + 1;						//NUMBER OF ELEMENTS IN NODES
	}
}
int CircularLinkedList::Get(int d)
{
	if (head == NULL)
	{
		return -1;									//NODE IS EMPTY
	}
	else if (ElementCount() < d)
	{
		return -1;									//GIVEN POSITION x SHOULD BE LESS THAN OR EQUAL TO ELEMENTS IN NODE
	}
	else
	{
		Node* currentNode = head;
		int count = 1;
		while (count <= d)
		{
			if (count == d)
			{
				return currentNode->data;				//GET ELEMENT AT GIVEN POSITION
			}
			count++;
			currentNode = currentNode->next;
		}
		return -1;
	}
}
bool CircularLinkedList::Find(int d)
{
	if (head == NULL)
	{
		return false;										//NODE IS EMPTY
	}
	else
	{
		Node* currentNode = head;
		while (currentNode->next != head)
		{
			if (currentNode->data == d)
			{
				return true;								//ELEMENT FOUND
			}
			currentNode = currentNode->next;
		}
		if (currentNode->data == d)
		{
			return true;									//ELEMENT FOUND AT LAST
		}
		return false;										//ELEMENT NOT FOUND
	}
}
void CircularLinkedList::Clear()
{
	if (head == NULL)
	{
		return;										//NODE IS EMPTY
	}
	Node* currentNode = head, * nextNode = NULL;
	while (currentNode->next != head)
	{
		nextNode = currentNode->next;
		delete currentNode;							//DELETING NODE ONE BY ONE
		currentNode = nextNode;
	}
	delete currentNode;
	head = NULL;
}
CircularLinkedList::~CircularLinkedList()
{
	Clear();
}

int GetJosephus(CircularLinkedList* list, int n, int k)
{
	cout << "\nThe persons in circular list are: \n";
	list->Print();
	cout << "\nn = " << n << "  k = " << k;
	int counterOFK = 1, count = 0, temp = 0, save = n;
	for (int i = 1; save != 1; i++)
	{
		if (counterOFK == k)
		{
			cout << "\n" << list->Get(i - temp) << " has been killed.";
			list->Delete(list->Get(i - temp));
			save--;
			counterOFK = 0;
			temp++;
		}
		if (i == n - count)
		{
			i = 0;
			count = n - save;
			temp = 0;
		}
		counterOFK++;
	}
	return list->Get(1);
}