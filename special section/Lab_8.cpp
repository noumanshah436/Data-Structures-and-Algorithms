#include<iostream>
using namespace std;

class Node {
public:
	char data;
	Node* next;
	Node()
	{
		data = NULL;
		next = NULL;
	}
	Node(char Data)
	{
		data = Data;
		next = NULL;
	}
};

class Stack {
private:
	Node* head;

public:
	Stack()
	{
		head = NULL;
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	void push(char value)
	{
		if (head == NULL)
		{
			Node* newNode = new Node;
			head = newNode;
			head->data = value;
			head->next = NULL;
		}
		else
		{
			Node* currentNode = head;
			while (currentNode->next != NULL)
			{
				currentNode = currentNode->next;
			}
			Node* newNode = new Node;
			currentNode->next = newNode;
			newNode->data = value;
			newNode->next = NULL;
		}
	}
	char pop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty\n";
			return 0;
		}
		else if (head->next == NULL)
		{
			char popValue = head->data;
			head = NULL;
			return popValue;
		}
		else
		{
			Node* currentNode = head;
			Node* previousNode = head;
			while (currentNode->next != NULL)
			{
				previousNode = currentNode;
				currentNode = currentNode->next;
			}
			char popValue = currentNode->data;
			delete currentNode;
			previousNode->next = NULL;
			return popValue;
		}
	}
	int count()
	{
		if (isEmpty())
		{
			return 0;
		}
		else
		{
			Node* currentNode = head;
			int elementCounter = 0;
			while (currentNode->next != NULL)
			{
				currentNode = currentNode->next;
				elementCounter++;
			}
			return elementCounter + 1;
		}
	}
	char peek(int position)
	{
		Node* currentNode = head;
		for (int i = 0; i < count(); i++)
		{
			if (i + 1 == position)
			{
				return currentNode->data;
			}
			currentNode = currentNode->next;
		}
		return ' ';
	}
	char top()
	{
		return peek(count());
	}
	void change(int position, char value)
	{
		Node* currentNode = head;
		for (int i = 0; i < count(); i++)
		{
			if (i + 1 == position)
			{
				currentNode->data = value;
				return;
			}
			currentNode = currentNode->next;
		}
	}
	void display()
	{
		Node* currentNode = head;
		while (currentNode != NULL)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
	}
	void clear()
	{
		if (head == NULL)
		{
			return;
		}
		Node* currentNode = head;
		Node* nextNode = NULL;
		while (currentNode != NULL)
		{
			nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
		head = NULL;
	}
	~Stack()
	{
		clear();
	}
};

class LString
{
private:
	Node* head;
	void SimpleAdd(char* Str);
public:
	LString();
	bool isEmpty()const;
	void Display();
	void AddToStart(char* arr);
	void ToUpper();
	void ToLower();
	void AddToEnd(char* arr);
	char CharAt(int ind);
	char RemoveCharAt(int ind);
	char& operator [](int ind);
	int size()const;
	bool isPal();
	bool find(char* temp, char check);
	void insertCharAt(char* temp, int i);
};

LString::LString()
{
	head = NULL;
}
bool LString::isEmpty()const
{
	if (head == NULL)
	{
		return true;
	}
	return false;
}
void LString::Display()
{
	if (head == NULL)
	{
		cout << "\nEmpty";
		return;
	}
	Node* node = head;

	while (node->next != NULL)
	{
		cout << node->data;
		node = node->next;
	}
	cout << node->data << endl;
}
void LString::ToUpper()
{
	Node* node = head;
	while (node != NULL)
	{
		if ((int)node->data >= 97 && (int)node->data <= 122)
		{
			node->data = node->data - 32;
		}
		node = node->next;
	}
}
void LString::ToLower()
{
	Node* node = head;
	while (node != NULL)
	{
		if ((int)node->data >= 65 && (int)node->data <= 90)
		{
			node->data = node->data + 32;
		}
		node = node->next;
	}
}
void LString::SimpleAdd(char* Str)
{
	Node* node = NULL;
	for (int i = 0; Str[i] != '\0'; i++)
	{
		Node* newNode = new Node(Str[i]);
		if (head == NULL)
		{
			head = newNode;			//ANS
		}
		else
		{
			node = head;
			while (node->next != NULL)
			{
				node = node->next;
			}
			node->next = newNode;
		}
	}
}
void LString::AddToStart(char* arr)
{
	if (head == NULL)
	{
		SimpleAdd(arr);
		return;
	}
	Node* node = NULL;
	Node* tempHead = NULL;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (tempHead == NULL)
		{
			node = new Node(arr[i]);
			tempHead = node;
		}
		else
		{
			node->next = new Node(arr[i]);
			node = node->next;
		}
	}
	node->next = head;
	head = tempHead;
}
void LString::AddToEnd(char* arr)
{
	if (head == NULL)
	{
		SimpleAdd(arr);
		return;
	}
	Node* node = NULL;
	Node* tempHead = NULL;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (tempHead == NULL)
		{
			node = new Node(arr[i]);
			tempHead = node;
		}
		else
		{
			node->next = new Node(arr[i]);
			node = node->next;
		}
	}
	Node* last = head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tempHead;
}
char LString::CharAt(int ind)
{
	if (ind > this->size())
	{
		char ch = '\0';
		cout << "\nNothing found,as index is out of approach";
		return ch;
	}
	int i = 0;
	while (i < ind)
	{
		i += 1;
	}
	return (*this)[i];
}
char LString::RemoveCharAt(int ind)
{
	if (ind > this->size())
	{
		char ch = '\0';
		cout << "\nNothing found,as index is out of approach";
		return ch;
	}
	Node* node = head;
	Node* prev = NULL;
	Node* next = NULL;
	for (int i = 0; i < ind; i++)
	{
		prev = node;
		node = node->next;
		next = node->next;
	}
	prev->next = next;
	char Data = node->data;
	delete node;
	return Data;
}
char& LString::operator [](int ind)
{
	if (ind > this->size())
	{
		char ch = '\0';
		cout << "\nError! Please enter valid index";
		return ch;
	}
	Node* node = head;
	for (int i = 0; i < ind; i++)
	{
		node = node->next;
	}
	return node->data;
}
int LString::size()const
{
	int size = 0;
	Node* node = head;
	while (node->next != NULL)
	{
		size = size + 1;
		node = node->next;
	}
	size = size + 1;
	return size;
}
bool LString::isPal()
{
	Stack s;
	Node* currentNode = head;
	int count = 0;
	while (currentNode != NULL)
	{
		s.push(currentNode->data);
		count++;
		currentNode = currentNode->next;
	}
	currentNode = head;
	if (count == 0 || count == 1)
	{
		cout << "Palindrome\n";
		return true;
	}
	for (int i = 0; i < count; i++)
	{
		int a = s.pop();
		int b = currentNode->data;
		if (a != b)
		{
			cout << "Not Palindrome\n";
			return false;
		}
		currentNode = currentNode->next;
	}
	cout << "Palindrome\n";
	return true;
}
bool LString::find(char* temp, char check)
{
	for (int i = 0; i < size(); i++)
	{
		if (temp[i] == check)
		{
			return true;
		}
	}
	return false;
}
void LString::insertCharAt(char* temp, int i)
{

	Node* currentNode = head;
	int count = 0;
	while (currentNode != NULL)
	{
		if (count == i)
		{
			for (int j = 0; temp[j] != '\0'; j++)
			{
				currentNode->next = new Node(temp[j]);
				currentNode = currentNode->next;
			}
		}
		count++;
		currentNode = currentNode->next;
	}
	cout << endl;
}

bool check(char* temp);
int openingBracket(char temp);
int closingBracket(char temp);
LString* Substring(int from, int size, LString ls);
LString* Concatenate(LString first, LString second);

int main()
{
	char arr1[] = { "Muhammad" };
	char arr2[] = { "Anas" };
	LString s;
	cout << "CHECK LSTRING IS EMPTY OR NOT: " << s.isEmpty() << " (1 means EMPTY 0 means NOT EMPTY)\n";
	cout << "\nADD ARRAY AT START: ";
	s.AddToStart(arr1);
	s.Display();
	cout << "\nADD ARRAY AT END: ";
	s.AddToEnd(arr2);
	s.Display();
	cout << "\nSIZE OF LSTRING: " << s.size() << endl;
	cout << "\nCHECK LSTRING IS PALINDROME OR NOT: ";
	s.isPal();
	cout << "\nMAKE LSTRING TO LOWER: ";
	s.ToLower();
	s.Display();
	cout << "\nMAKE LSTRING TO UPPER: ";
	s.ToUpper();
	s.Display();
	cout << "\nREMOVE CHARACTER AT LOCATION 8 IN LSTRING: ";
	s.RemoveCharAt(8);
	s.Display();
	cout << "\nGET CHARACTER AT LOCATION 2 IN LSTRING: " << s.CharAt(2) << endl;
	cout << "\nFIND CHARACTER IN LSTRING: ";
	cout << s.find(arr1, 'a');
	cout << " (1 means FOUND 0 means NOT FOUND)\n";;
	LString s1, s2, * s3, * s4;
	s1.AddToEnd(arr2);
	s2.AddToStart(arr1);
	cout << "\nCONCATENATE: ";
	s3 = Concatenate(s2, s1);
	s3->Display();
	cout << "\nSUBSTRING: ";
	s4 = Substring(2, 6, s);
	s4->Display();
	/////////////////////////////////////////////TASK 2

	/*char task2[] ="{({})}[({({}})]";

	if (check(task2))
		cout << "\nYES\n";
	else
		cout << "\nNO\n";*/

	return 0;
}

bool check(char* temp)
{
	Stack s;
	for (int i = 0; temp[i] != '\0'; i++)
	{
		if (temp[i] == '(' || temp[i] == '{' || temp[i] == '[')
		{
			s.push(temp[i]);
		}
		else if (temp[i] == ')' || temp[i] == '}' || temp[i] == ']')
		{
			if (s.isEmpty())
				return false;
			if (closingBracket(temp[i]) != openingBracket(s.pop()))
				return false;
		}
		else
		{
			return false;
		}
	}

	if (s.isEmpty())
		return true;
	else
		return false;
}
int openingBracket(char temp)
{
	if (temp == '[')
		return 3;
	else if (temp == '{')
		return 2;
	else if (temp == '(')
		return 1;
	else
		return 0;
}
int closingBracket(char temp)
{
	if (temp == ']')
		return 3;
	else if (temp == '}')
		return 2;
	else if (temp == ')')
		return 1;
	else
		return 0;
}
LString* Substring(int from, int size, LString ls)
{
	LString* lstr = new LString;
	if (ls.size() - from < size)
	{
		cout << "\nPlease enter indexes,which are valid";
		return lstr;
	}
	int index = from;
	for (int i = 0; i < size; i++)
	{
		lstr->AddToEnd(&ls[index]);

		index = index + 1;
	}
	return lstr;
}
LString* Concatenate(LString first, LString second)
{
	LString* result = new LString;
	for (int i = 0; i < first.size(); i++)
	{
		result->AddToEnd(&first[i]);
	}
	for (int j = 0; j < second.size(); j++)
	{
		result->AddToEnd(&second[j]);
	}
	return result;
}