#include<iostream>
using namespace std;

class Node {
public:
	double	data;
	Node* next;
	Node()
	{
		data = 0.0;
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
	void push(double value)
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
	double pop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty\n";
			return 0;
		}
		else if (head->next == NULL)
		{
			double popValue = head->data;
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
			double popValue = currentNode->data;
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
	double peek(int position)
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
		return 0;
	}
	double top()
	{
		return peek(count());
	}
	void change(int position, double value)
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

class Queue {
private:
	int front;
	int rear;
	Node* head;

public:
	Queue() 
	{
		front = -1;
		rear = -1;
		head = NULL;	
	}
	bool isEmpty() 
	{
		if (front == -1 && rear == -1)
			return true;
		else
			return false;
	}
	void enqueue(double value) 
	{
		if (isEmpty()) 
		{
			rear = 0;
			front = 0;
			Node* newNode = new Node;
			head = newNode;
			head->data = value;
			head->next = NULL;
		}
		else 
		{
			rear++;
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
	double dequeue() 
	{
		double value = 0;
		if (isEmpty()) 
		{
			cout << "Queue is Empty\n";
			return value;
		}
		else if (rear == front) 
		{
			value = head->data;
			head = NULL;
			rear = -1;
			front = -1;
			return value;
		}
		else 
		{
			Node* currentNode = head;
			value = head->data;
			head = head->next;
			front++;
			return value; 
		}
	}
	int count() 
	{
		return (rear - front + 1);
	}   
	void display() 
	{
		cout << "Values in the Queue :\n";
		Node* currentNode = head;
		while (currentNode != NULL)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
	}
};

bool is_palindrome(char* temp)
{
	int counter = 0;
	Stack s;
	Queue q;
	for (int i = 0; temp[i] != '\0'; i++)
	{
		if (temp[i] != ' ')
		{
			s.push(temp[i]);
			q.enqueue(temp[i]);
			counter = counter + 1;
		}
	}
	if (counter == 1 || counter == 0)
	{
		cout << "\nPalindrome";
		return true;
	}
	for (int i = 0; i < counter; i++)
	{
		double pop1 = s.pop();
		double dequeue1=q.dequeue();
		bool check = true;
		if (pop1>=65 && pop1<=90)
		{
			if (pop1 != dequeue1-32)
				check = false;
		}
		else if((pop1 >= 97 && pop1 <= 122))
		{
			if (pop1 != dequeue1 + 32)
				check = false;
		}
		else
		{
			if (pop1 != dequeue1)
				check = false;
		}

		if (check == false)
		{
			if (pop1 != dequeue1)
				return false;
		}
	}
	return true;
}

int main()
{
	char test[] = "daD";

	if (is_palindrome(test))
		cout << "\nPALINDROME\n";
	else
		cout << "\nNOT PALINDROME\n";
	
	return 0;
}