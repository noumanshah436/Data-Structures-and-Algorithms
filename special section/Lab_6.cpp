#include<iostream>
#include<cmath>
using namespace std;

class Node {
public:
	double	data;		// data
	Node* next;		// pointer to next
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
		if (head == NULL)										//NODE INSERT AT START
		{
			Node* newNode = new Node;
			head = newNode;
			head->data = value;
			head->next = NULL;
		}
		else													//NODE INSERT AT LAST
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
		else if (head->next == NULL)							//NODE DELETE AT START
		{
			double popValue = head->data;
			head = NULL;
			return popValue;
		}
		else													//NODE DELETE AT LAST 
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

bool isOperator(char a)
{
	if (a == '^' || a == '/' || a == '*' || a == '+' || a == '-')
		return true;
	else
		return false;
}
int precedence(char a)
{
	if (a == '^')
		return 3;
	else if (a == '*' || a == '/')
		return 2;
	else if (a == '+' || a == '-')
		return 1;
	else
		return -1;
}
double solve(double first, double second, char sign)
{
	if (sign == '+')
		return first + second;
	else if (sign == '-')
		return first - second;
	else if (sign == '*')
		return first * second;
	else if (sign == '/')
		return first / second;
	else if (sign == '^')
		return pow(first, second);
}
string convertInfixToPostfix(Stack s, string infix)
{
	string postfix;
	for (int i = 0; i < infix.length(); i++)
	{
		if ((infix[i] >= '0' && infix[i] <= '9')
			|| (infix[i] >= 'a' && infix[i] <= 'z')
			|| (infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix = postfix + infix[i];
		}
		else if (infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while ((s.top() != '(') && (!s.isEmpty()))
			{
				char temp = s.top();
				postfix = postfix + temp;
				s.pop();
			}
			if (s.top() == '(')
			{
				s.pop();
			}
		}
		else if (isOperator(infix[i]))
		{
			if (s.isEmpty())
			{
				s.push(infix[i]);
			}
			else
			{
				if (precedence(infix[i]) > precedence(s.top()))
				{
					s.push(infix[i]);
				}
				else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
				{
					s.push(infix[i]);
				}
				else
				{
					while ((!s.isEmpty()) && (precedence(infix[i]) <= precedence(s.top())))
					{
						postfix += s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while (!s.isEmpty())
	{
		postfix += s.top();
		s.pop();
	}

	return postfix;
}
void getOperatorAndOperandCount(int& operandCount, int& operatorCount, string postfix)
{
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isOperator(postfix[i]))
			operatorCount++;
		else
			operandCount++;
	}
}
double calculatePostifx(Stack s, string postfix)
{
	for (int i = 0; i < postfix.length(); i++)
	{
		if ((postfix[i] >= 'a' && postfix[i] <= 'z')
			|| (postfix[i] >= 'A' && postfix[i] <= 'Z'))
		{
			cout << "\nGiven String is in Alphabets";
			return 0;
		}
	}
	int countOfOperators = 0, countOfOperands = 0;
	getOperatorAndOperandCount(countOfOperands, countOfOperators, postfix);
	if (countOfOperands != countOfOperators + 1)
	{
		if (countOfOperands <= countOfOperators)
		{
			if (postfix.length() == 0)
			{
				cout << "\nGiven String is Empty";
				return 0;
			}
			cout << "\nNot Enough Operands";
			return 0;
		}
		else
		{
			cout << "\nToo Many Operands";
			return 0;
		}
	}
	double firstOperand = 0, secondOperand = 0, num = 0;
	countOfOperators = 0, countOfOperands = 0;
	for (int i = postfix.length(); i >= 0; i--)
	{
		if (num != 0)
		{
			secondOperand = s.pop();
			num = 0;
		}
		if (isOperator(postfix[i]))
		{
			if (secondOperand != 0)
			{
				s.push(secondOperand);
				secondOperand = 0;
			}
			s.push(postfix[i]);
			countOfOperators++;
		}
		else if (secondOperand == 0)
		{
			secondOperand = postfix[i];
			secondOperand = secondOperand - 48;
		}
		else
		{
			firstOperand = postfix[i];
			firstOperand = firstOperand - 48;
			num = solve(firstOperand, secondOperand, s.pop());
			countOfOperators--;
			s.push(num);
			firstOperand = 0;
			secondOperand = 0;
		}
	}

	while (countOfOperators != 0)
	{
		firstOperand = s.pop();
		secondOperand = s.pop();
		num = solve(firstOperand, secondOperand, s.pop());
		s.push(num);
		countOfOperators--;

	}
	return num;
}

int main()
{
	string infixExpression, postfixExpression;
	cout << "Enter a Infix Expression : ";
	cin >> infixExpression;
	Stack stack;
	postfixExpression = convertInfixToPostfix(stack, infixExpression);

	cout << "\n\nINFIX EXPRESSION: " << infixExpression;
	cout << "\n\nPOSTFIX EXPRESSION: " << postfixExpression;
	cout << "\n\nCALCULATE EXPRESSION: " << calculatePostifx(stack, postfixExpression);

	return 0;
}