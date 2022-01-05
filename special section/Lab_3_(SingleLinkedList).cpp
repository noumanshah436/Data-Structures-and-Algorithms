#include<iostream>
using namespace std;
class Node {
public:
	double	data;		// data
	Node* next;		// pointer to next
};
class List {
private:
	Node* head;

public:
	List();
	List(double);
	bool IsEmpty();
	Node* first()const;
	Node* InsertNode(int, double);
	int FindNode(double);
	int DeleteNode(double);
	void DisplayList();
	void Insert(int);
	int Delete(int d);
	void Print(Node*);
	int Update(Node*, int);
	int ElementCount();
	int Get(int);
	bool Find(int);
	void Clear();
	~List();
};

List::List()
{
	head = NULL;
}
List::List(double d)
{
	head = new Node;
	head->data = d;
}
bool List::IsEmpty()
{
	return head == NULL;
}
Node* List::first()const
{
	return head;
}
Node* List::InsertNode(int index, double x) {
	if (index < 0) return NULL;

	int currIndex = 1;
	Node* currNode = head;
	while (currNode && index > currIndex) {
		currNode = currNode->next;
		currIndex++;
	}
	if (index > 0 && currNode == NULL) return NULL;

	Node* newNode = new	Node;
	newNode->data = x;
	if (index == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	return newNode;
}
int List::FindNode(double x) {
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && currNode->data != x) {
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode) return currIndex;
	return 0;
}
int List::DeleteNode(double x) {
	Node* prevNode = NULL;
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && currNode->data != x) {
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode) {
		if (prevNode) {
			prevNode->next = currNode->next;
			delete currNode;
		}
		else {
			head = currNode->next;
			delete currNode;
		}
		return currIndex;
	}
	return 0;
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
void List::Print(Node* currNode)
{
	if (currNode == NULL)
	{
		return;
	}
	cout << currNode->data << '\n';
	Print(currNode->next);
}
int List::Update(Node* nNode, int d)
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
			if (currIndex == 0)							//UPDATE AT START
			{
				Node* tempNode = new Node;
				tempNode = head;
				head = nNode;
				head->next = tempNode->next;
				return currIndex + 1;
			}
			else										//UPDATE AT MID AND LAST
			{
				previousNode->next = nNode;
				nNode->next = currNode->next;
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
void List::Clear()
{
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
List::~List()
{
	Clear();
}


int main(void)
{
	List list;
	Node* node = new Node;
	node->data = 15.0;

	list.InsertNode(0, 7.0);					//SUCESSFULLY ADDED
	list.InsertNode(1, 5.0);					//SUCESSFULLY ADDED
	list.InsertNode(2, 6.0);					//SUCESSFULLY ADDED
	cout << "DISPLAY: \n";
	list.Print(list.first());

	cout << "----------INSERT 18----------\n";
	list.Insert(18);							//INSERTS DATA AT END,IF EMPTY THEN INSERTS AT START
	cout << "DISPLAY: \n";
	list.Print(list.first());

	cout << "----------DELETE 18----------\n";
	list.Delete(18);							//DELETES DATA AND RETURN ITS INDEX
	cout << "DISPLAY: \n";
	list.Print(list.first());

	cout << "----------UPDATE 5----------\n";
	list.Update(node, 5);						//UPDATES DATA
	cout << "DISPLAY: \n";
	list.Print(list.first());

	cout << "\nElements In The List = "
		<< list.ElementCount() << endl;

	cout << "Value of Given Position = "
		<< list.Get(2) << endl;

	cout << "Element Checker = "
		<< list.Find(6) << endl;					//RETURN 1 IF FOUND, ELSE 0

	list.Clear();									//DELETE ALL
	cout << "DISPLAY: \n";
	list.Print(list.first());

	return 0;
}