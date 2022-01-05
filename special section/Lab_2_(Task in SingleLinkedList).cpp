#include<iostream>
using namespace std;

class Node {
public:
	int	data;
	Node* next;
};
class List {
public:
	Node* head;

	List();
	void DisplayList();
	void Insert(int);
	int Delete(int d);
	int ElementCount();
	int Get(int);
	bool Find(int);
	~List();
};

void removeDuplicate(List* temp);
void print(Node* temp);
List* calculateUnion(List* a, List* b);
List* calculateIntersection(List* a, List* b);
List* subtraction(List* a, List* b);
void copyList(List* a, List* b);
void printList(List* a);

int main(void)
{
	List* listA = new List, * listB = new List;
	int noOfElementsA, noOfElementsB, element;

	cout << "Enter number of elements you want to enter for First List: ";
	cin >> noOfElementsA;
	for (int i = 1; i <= noOfElementsA; i++)
	{
		cout << "Enter " << i << " elements: ";
		cin >> element;
		listA->Insert(element);
	}

	cout << "\nEnter number of elements you want to enter for Second List: ";
	cin >> noOfElementsB;
	for (int i = 1; i <= noOfElementsB; i++)
	{
		cout << "Enter " << i << " elements: ";
		cin >> element;
		listB->Insert(element);
	}

	calculateUnion(listA, listB);
	calculateIntersection(listA, listB);
	subtraction(listA, listB);
	cout << "\nCopy Elements of List B into List A: ";
	copyList(listA, listB);
	printList(listA);

	delete listA;
	delete listB;

	return 0;
}


///////////////MEMBER FUNCTION///////////////
List::List()
{
	head = NULL;
}
void List::DisplayList()
{
	int num = 0;
	Node* currNode = head;
	while (currNode != NULL) {
		cout << currNode->data << endl;
		currNode = currNode->next;
		num++;
	}
	cout << "Number of nodes in the list: " << num << endl;
}
void List::Insert(int x)
{
	Node* currNode = head;
	if (head == NULL)
	{
		Node* newNode = new Node;					//NODE INSERT AT START
		head = newNode;
		head->data = x;
		head->next = NULL;
	}
	else
	{
		while (currNode->next != NULL)
		{
			currNode = currNode->next;				//NODE INSERT AT LAST
		}
		Node* newNode = new Node;
		currNode->next = newNode;
		newNode->data = x;
		newNode->next = NULL;
	}
}
int List::Delete(int d)
{
	Node* currNode = head;
	Node* previousNode = head;
	int currIndex = 0;
	if (head == NULL)
	{
		return -1;										//NODE IS EMPTY
	}
	while (currNode != NULL)
	{
		if (currNode->data == d)
		{
			if (currIndex == 0)							//DELETE AT START
			{
				head = head->next;
				return currIndex + 1;
			}
			else										//DELETE AT MID AND LAST
			{
				previousNode->next = currNode->next;
				previousNode = previousNode->next;
				currNode->next = previousNode;
				return currIndex + 1;
			}
		}
		currIndex++;
		previousNode = currNode;
		currNode = currNode->next;
	}
	return -1;											//ELEMENT NOT FOUND
}
int List::ElementCount()
{
	Node* currNode = head;
	int elementCounter = 0;
	if (head == NULL)
	{
		return -1;										//NODE IS EMPTY
	}
	else
	{
		while (currNode->next != NULL)
		{
			currNode = currNode->next;
			elementCounter++;
		}
		return elementCounter + 1;
	}
}
int List::Get(int x)
{
	if (head == NULL)
	{
		return -1;										//NODE IS EMPTY
	}
	else if (ElementCount() < x)
	{
		return -1;										//GIVEN POSITION x SHOULD BE LESS THAN OR EQUAL TO ELEMENTS IN NODE
	}
	else
	{
		Node* currNode = head;
		int count = 1;
		while (count <= x)
		{
			if (count == x)
			{
				return currNode->data;					//GET ELEMENT AT GIVEN POSITION
			}
			count++;
			currNode = currNode->next;
		}
		return -1;
	}
}
bool List::Find(int x)
{
	Node* currNode = head;
	if (head == NULL)
	{
		return false;										//NODE IS EMPTY
	}
	else
	{
		while (currNode != NULL)
		{
			if (currNode->data == x)
			{
				return true;								//ELEMENT FOUND
			}
			currNode = currNode->next;
		}
		return false;										//ELEMENT NOT FOUND
	}
}
List::~List()
{
	cout << "\nOBJECT DESTROYED";
	if (head == NULL)
	{
		return;										//NODE IS EMPTY
	}
	Node* currNode = head, * nextNode = NULL;
	while (currNode != NULL)
	{
		nextNode = currNode->next;
		delete currNode;							//DELETING NODE ONE BY ONE
		currNode = nextNode;
	}
	head = NULL;
}


///////////////GLOBAL FUNCTION///////////////
void removeDuplicate(List* temp)
{
	Node* currNode = temp->head;
start:
	for (int i = 1; currNode != NULL; i++)
	{
		for (Node* tempNode = currNode->next; tempNode != NULL; tempNode = tempNode->next)
		{
			if (temp->Get(i) == tempNode->data)
			{
				temp->Delete(temp->Get(i));
				currNode = temp->head;
				i = 1;
				goto start;
			}
		}
		currNode = currNode->next;
	}
}
void print(Node* temp)
{
	if (temp == NULL)
	{
		return;
	}
	print(temp->next);
	cout << " " << temp->data;
}
List* calculateUnion(List* a, List* b)
{
	List* temp = new List;
	copyList(temp, a);
	copyList(temp, b);
	removeDuplicate(temp);

	cout << "\nUNION: ";
	printList(temp);
	return temp;
}
List* calculateIntersection(List* a, List* b)
{
	List* temp = new List;

	Node* currNode = a->head;
	for (int i = 1; currNode != NULL; i++)
	{
		if (b->Find(a->Get(i)))
		{
			temp->Insert(a->Get(i));
		};
		currNode = currNode->next;
	}

	cout << "\nINTERSECTION: ";
	printList(temp);
	return temp;
}
List* subtraction(List* a, List* b)
{
	List* temp = new List;
	copyList(temp, a);

	Node* currNode = a->head;
	for (int i = 1; currNode != NULL; i++)
	{
		if (b->Find(a->Get(i)))
		{
			temp->Delete(a->Get(i));
		};
		currNode = currNode->next;
	}

	cout << "\nSUBTRACTION: ";
	printList(temp);
	return temp;
}
void copyList(List* a, List* b)
{
	Node* currNode = b->head;
	while (currNode != NULL)
	{
		a->Insert(currNode->data);
		currNode = currNode->next;
	}
}
void printList(List* a)
{
	print(a->head);
}