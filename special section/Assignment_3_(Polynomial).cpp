#include<iostream>
using namespace std;

class Node {
public:
	int data;
	int exponent;
	Node* next;

	Node()
	{
		data = 0;
		exponent = -1;
		next = NULL;
	}
};

class Polynomial {
public:
	Node* head;

	Polynomial();
	int ElementCount();
	bool findByExponent(int);
	void Sort();
	void Insert(int, int);
	int Delete(int, int);
	void AddDuplicateTerms();
	void RemoveDuplicateTerms();
	friend istream& operator>> (istream&, const Polynomial&);
	friend ostream& operator<<(ostream&, const Polynomial&);
	friend Polynomial& operator+(const Polynomial&, const Polynomial&);
	friend Polynomial& operator-(const Polynomial&, const Polynomial&);
	friend Polynomial& operator*(const Polynomial&, const Polynomial&);
};

int main()
{
	Polynomial p1, p2, p3, p4, p5;

	cin >> p1;
	p1.Sort();
	p1.AddDuplicateTerms();
	p1.RemoveDuplicateTerms();

	cin >> p2;
	p2.Sort();
	p2.AddDuplicateTerms();
	p2.RemoveDuplicateTerms();

	cout << "\n\nFirst Polynomial:\t" << p1;
	cout << "\n\nSecond Polynomial:\t" << p2;

	p3 = p1 + p2; cout << "\n\nAddition:\t\t" << p3;

	p4 = p1 - p2; cout << "\n\nSubtraction:\t\t" << p4;

	p5 = p1 * p2; cout << "\n\nMultiplication:\t\t" << p5 << "\n\n";

	return 0;
}


///////////////MEMBER FUNCTION OF Polynomial///////////////
Polynomial::Polynomial()
{
	head = new Node;
	head->next = head;
}
int Polynomial::ElementCount()
{
	int elementCounter = 0;
	Node* currentNode = head;
	while (currentNode->next != head)
	{
		currentNode = currentNode->next;
		elementCounter++;
	}
	return elementCounter;
}
bool Polynomial::findByExponent(int power)
{
	Node* currentNode = head;
	while (currentNode->next != head)
	{
		if (currentNode->exponent == power)
		{
			return true;
		}
		currentNode = currentNode->next;
	}
	if (currentNode->exponent == power)
	{
		return true;
	}
	return false;
}
void Polynomial::Sort()
{
	Node* start = head->next;
	while (start != head)
	{
		Node* currentNode = start->next;
		while (currentNode != head)
		{
			int max = start->exponent;
			if (currentNode->exponent > max)
			{
				max = currentNode->exponent;
				int tempValue = start->data;
				int tempPower = start->exponent;
				start->data = currentNode->data;
				start->exponent = currentNode->exponent;
				currentNode->data = tempValue;
				currentNode->exponent = tempPower;
			}
			currentNode = currentNode->next;
		}
		start = start->next;
	}
}
void Polynomial::Insert(int value, int power)
{

	Node* currentNode = head;
	while (currentNode->next != head)
	{
		currentNode = currentNode->next;
	}
	Node* newNode = new Node;
	currentNode->next = newNode;

	newNode->data = value;
	newNode->exponent = power;
	newNode->next = head;
}
int Polynomial::Delete(int value, int power)
{
	Node* currentNode = head;
	Node* previousNode = head;
	int currentIndex = 0;
	while (currentNode->next != head)
	{
		if (currentNode->data == value && currentNode->exponent == power)
		{
			if (currentIndex == 0)
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
			else
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
	if (head->next == head)
	{
		head = NULL;
		return currentIndex + 1;
	}
	else if (currentNode->data == value && currentNode->exponent == power)
	{
		previousNode->next = currentNode->next;
		delete currentNode;
		return currentIndex + 1;
	}
	else
	{
		return -1;
	}
}
void Polynomial::AddDuplicateTerms()
{
	Node* start = head->next;
	while (start != head)
	{
		Node* currentNode = start->next;
		while (currentNode != head)
		{
			int max = start->exponent;
			if (currentNode->exponent == max)
			{
				start->data = start->data + currentNode->data;
			}
			currentNode = currentNode->next;
		}
		start = start->next;
	}
}
void Polynomial::RemoveDuplicateTerms()
{
	Node* currentNode = head->next;
	while (currentNode != head)
	{
		int previous = currentNode->exponent;
		int next = currentNode->next->exponent;
		if (next == previous)
		{
			currentNode->next = currentNode->next->next;
			currentNode = head;
		}
		currentNode = currentNode->next;
	}
}
istream& operator>> (istream& in, const Polynomial& c)
{
	bool choice = true;
	cout << "\nEnter Polynomial: ";
	Node* currentNode = c.head;
	while (currentNode->next != c.head)
	{
		currentNode = currentNode->next;
	}
	while (choice)
	{
		Node* newNode = new Node;
		in >> newNode->data;
		in >> newNode->exponent;
		if (newNode->data == 0 && newNode->exponent == -1)
		{
			choice = false;
			currentNode->next = c.head;
		}
		else
		{
			currentNode->next = newNode;
		}
		currentNode = currentNode->next;
	}
	return in;
}
ostream& operator<<(ostream& out, const Polynomial& c)
{
	Node* currentNode = c.head->next;
	while (currentNode != c.head)
	{
		if (currentNode->data != 0)
		{
			if (currentNode->data == 1)
				out << "+";
			else if (currentNode->data == -1)
				out << "-";
			else if (currentNode->data > 1)
				out << "+" << currentNode->data;
			else
				out << currentNode->data;

			if (currentNode->exponent == 0)
				out << " ";
			else if (currentNode->exponent == 1)
				out << "x" << " ";
			else
				out << "x^" << currentNode->exponent << " ";
		}
		currentNode = currentNode->next;
	}
	out << "+" << c.head->data;
	out << "^" << c.head->exponent << " ";
	return out;
}
Polynomial& operator+(const Polynomial& p1, const Polynomial& p2)
{
	Polynomial* p = new Polynomial;
	Node* currentNode1 = p1.head->next;
	while (currentNode1 != p1.head)
	{
		Node* currentNode2 = p2.head->next;
		while (currentNode2 != p2.head)
		{
			if (currentNode1->exponent == currentNode2->exponent)
			{
				p->Insert(currentNode1->data + currentNode2->data, currentNode1->exponent);
			}
			currentNode2 = currentNode2->next;
		}
		currentNode1 = currentNode1->next;
	}
	currentNode1 = p1.head->next;
	while (currentNode1 != p1.head)
	{
		if (!(p->findByExponent(currentNode1->exponent)))
		{
			p->Insert(currentNode1->data, currentNode1->exponent);
		}
		currentNode1 = currentNode1->next;
	}
	Node* currentNode2 = p2.head->next;
	while (currentNode2 != p2.head)
	{
		if (!(p->findByExponent(currentNode2->exponent)))
		{
			p->Insert(currentNode2->data, currentNode2->exponent);
		}
		currentNode2 = currentNode2->next;
	}

	p->Sort();
	return *p;
}
Polynomial& operator-(const Polynomial& p1, const Polynomial& p2)
{
	Polynomial* p = new Polynomial;
	Node* currentNode1 = p1.head->next;
	while (currentNode1 != p1.head)
	{
		Node* currentNode2 = p2.head->next;
		while (currentNode2 != p2.head)
		{
			if (currentNode1->exponent == currentNode2->exponent)
			{
				p->Insert(currentNode1->data - currentNode2->data, currentNode1->exponent);
			}
			currentNode2 = currentNode2->next;
		}
		currentNode1 = currentNode1->next;
	}
	currentNode1 = p1.head->next;
	while (currentNode1 != p1.head)
	{
		if (!(p->findByExponent(currentNode1->exponent)))
		{
			p->Insert(currentNode1->data, currentNode1->exponent);
		}
		currentNode1 = currentNode1->next;
	}
	Node* currentNode2 = p2.head->next;
	while (currentNode2 != p2.head)
	{
		if (!(p->findByExponent(currentNode2->exponent)))
		{
			p->Insert(-currentNode2->data, currentNode2->exponent);
		}
		currentNode2 = currentNode2->next;
	}
	p->Sort();
	return *p;
}
Polynomial& operator*(const Polynomial& p1, const Polynomial& p2)
{
	Polynomial* p = new Polynomial;
	Node* currentNode1 = p1.head->next;
	while (currentNode1 != p1.head)
	{
		Node* currentNode2 = p2.head->next;
		while (currentNode2 != p2.head)
		{
			p->Insert(currentNode1->data * currentNode2->data, currentNode1->exponent + currentNode2->exponent);
			currentNode2 = currentNode2->next;
		}
		currentNode1 = currentNode1->next;
	}
	p->Sort();
	p->AddDuplicateTerms();
	p->RemoveDuplicateTerms();
	return *p;
}