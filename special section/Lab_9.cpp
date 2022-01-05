#include<iostream>
using namespace std;

void task1();
void task2();
void task3();
bool isOperator(char);
void convert_postfix_expression_to_binary_tree(char*);
class BSTNode {
public:
	char	data;
	BSTNode* left;
	BSTNode* right;

	BSTNode()
	{
		data = 0.0;
		left = NULL;
		right = NULL;
	}
	BSTNode(char data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};
class Stack {
private:
	int top;
	int size;
	BSTNode* values[50];

public:
	Stack(int size)
	{
		top = -1;
		this->size = size - 1;
	}
	bool IsEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}
	bool IsFull()
	{
		if (top == size)
			return true;
		else
			return false;
	}
	void push(BSTNode* temp)
	{
		if (!IsFull())
			values[++top] = temp;
		else
			cout << "\nStack is Full";
	}
	BSTNode* pop()
	{
		if (!IsEmpty())
			return values[top--];
	}

};
class BinarySearchTree {
public:
	BSTNode* root;

	BinarySearchTree()
	{
		root = NULL;
	}
	BinarySearchTree(BSTNode* root)
	{
		this->root = root;
	}
	bool isEmpty()
	{
		if (root == NULL)
			return true;
		else
			return false;
	}
	void insertNode(BSTNode* newNode)
	{
		if (root == NULL)
		{
			root = newNode;
		}
		else
		{
			BSTNode* temp = root;
			while (temp != NULL)
			{
				if (newNode->data > temp->data)
				{
					if (temp->right == NULL)
					{
						temp->right = newNode;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
				else if (newNode->data < temp->data)
				{
					if (temp->left == NULL)
					{
						temp->left = newNode;
						break;
					}
					else
					{
						temp = temp->left;
					}
				}
				else
				{
					return;
				}
			}
		}
	}
	void printInorder(BSTNode* BSTNode)
	{
		if (BSTNode == NULL)
			return;

		printInorder(BSTNode->left);
		cout << BSTNode->data << " ";
		printInorder(BSTNode->right);
	}
	void printPreorder(BSTNode* BSTNode)
	{
		if (BSTNode == NULL)
			return;

		cout << BSTNode->data << " ";
		printPreorder(BSTNode->left);
		printPreorder(BSTNode->right);
	}
	void printPostorder(BSTNode* BSTNode)
	{
		if (BSTNode == NULL)
			return;

		printPostorder(BSTNode->left);
		printPostorder(BSTNode->right);
		cout << BSTNode->data << " ";
	}

};

class Node {
public:
	double	data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}
	Node(double data)
	{
		this->data = data;
		next = NULL;
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
	double getFront()
	{
		Node* currentNode = head;
		while (currentNode != head)
		{
			currentNode = currentNode->next;
		}
		return currentNode->data;
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

};
class StackWithQueue {
public:
	Queue q;

	bool isEmpty()
	{
		if (q.isEmpty())
			return true;
		else
			return false;
	}
	void push(double value)
	{
		Queue temp;
		temp.enqueue(value);
		while (!q.isEmpty())
		{
			temp.enqueue(q.dequeue());
		}
		q = temp;
	}
	double pop()
	{
		if (q.isEmpty())
			return -1;
		else
			return q.dequeue();
	}
	int count()
	{
		return q.count();
	}
	double getTop()
	{
		if (q.isEmpty())
			return -1;
		else
			return q.getFront();
	}
};

int main()
{
	cout << "\n----------------------------------TASK 1----------------------------------";
	task1();

	cout << "\n\n----------------------------------TASK 2----------------------------------";
	task2();

	cout << "\n\n----------------------------------TASK 3----------------------------------";
	task3();

	return 0;
}

bool isOperator(char temp)
{
	if (temp == '+' || temp == '-' || temp == '/' || temp == '*')
		return true;
	else
		return false;
}
void convert_postfix_expression_to_binary_tree(char* temp)
{
	BSTNode* start = new BSTNode;
	BinarySearchTree b;
	int counter = 0;
	Stack* s = new Stack(50);
	for (int i = 0; temp[i] != '\0'; i++)
	{
		if (temp[i] != ' ')
		{
			if (isOperator(temp[i]))
			{
				BSTNode* newNode = new BSTNode;
				newNode->data = temp[i];
				newNode->right = s->pop();
				newNode->left = s->pop();
				s->push(newNode);
				start = newNode;
			}
			else
			{
				BSTNode* newNode = new BSTNode;
				newNode->data = temp[i];
				s->push(newNode);
			}

			counter = counter + 1;
		}
	}
	s->pop();
	if (s->IsEmpty())
	{
		b.insertNode(start);
		cout << "  "; b.printInorder(start); cout << "\t";
		cout << "  "; b.printPreorder(start); cout << "\t";
		cout << "  "; b.printPostorder(start); cout << "\n";
	}
	else
	{
		cout << "\nGiven Expression is not correct";
	}
}
void task1()
{
	BSTNode* n = new BSTNode;
	BSTNode* n1 = new BSTNode; BSTNode* n2 = new BSTNode; BSTNode* n3 = new BSTNode;
	BSTNode* n4 = new BSTNode; BSTNode* n5 = new BSTNode; BSTNode* n6 = new BSTNode;
	BSTNode* n7 = new BSTNode; BSTNode* n8 = new BSTNode; BSTNode* n9 = new BSTNode;


	n->data = 'K';
	n1->data = 'L'; n2->data = 'Q'; n3->data = 'M';
	n4->data = 'A'; n5->data = 'E'; n6->data = 'F';
	n7->data = 'G'; n8->data = 'Z'; n9->data = 'I';

	BinarySearchTree b;
	b.insertNode(n);
	b.insertNode(n1); b.insertNode(n2); b.insertNode(n3);
	b.insertNode(n4); b.insertNode(n5); b.insertNode(n6);
	b.insertNode(n7); b.insertNode(n8); b.insertNode(n9);

	cout << "\nInOder:  \t"; b.printInorder(n);
	cout << "\nPreOder: \t"; b.printPreorder(n);
	cout << "\nPostOder:\t"; b.printPostorder(n);
}
void task2()
{
	char test_1[] = { "ABC*+D+" };
	char test_2[] = { "AB+CD+*" };
	char test_3[] = { "AB*CD*+" };
	char test_4[] = { "AB+C+D+" };
	cout << "\nInfix Expression\tPrefix Expression\tPostfix Expression\n";
	convert_postfix_expression_to_binary_tree(test_1);
	convert_postfix_expression_to_binary_tree(test_2);
	convert_postfix_expression_to_binary_tree(test_3);
	convert_postfix_expression_to_binary_tree(test_4);
}
void task3()
{
	StackWithQueue test;
	cout << "\nPushing Values in Stack  ";
	test.push(2); test.push(5); test.push(3); test.push(9); test.push(6), test.push(7);
	cout << "\nStack is Empty(1) or Not Empty(0): " << test.isEmpty();
	cout << "\nPoping Values from Stack One by One:  ";
	cout << test.pop() << " "; cout << test.pop() << " "; cout << test.pop() << " ";
	cout << test.pop() << " "; cout << test.pop() << " "; cout << test.pop() << " ";
	cout << "\nStack is Empty(1) or Not Empty(0): " << test.isEmpty(); cout << endl;
}