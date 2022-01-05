
#include<iostream> 
using namespace std;

class Deque
{
	int * q;
	int front;
	int back;
	int capacity;
public:
	
	Deque(int n);
	~Deque();
	bool isEmpty();
	bool isFull();
	void display();
	bool insertAtFront(int val);
	bool insertAtBack(int val);
	bool removeFromFront(int& val);
    bool removeFromBack(int& val);
	void makeEmpty();

};


Deque::Deque(int n)
{
	if (n == 0)
	{
		front = -1;
		back = -1;
		q = nullptr;
		return;
	}
	capacity = n;
	front = -1;
	back = -1;
	q = new int[n];
}
void Deque::makeEmpty()
{
	front = -1;
	back = -1;
}

Deque::~Deque()
{
	if (q==nullptr)
	{
		return;
	}
	delete[] q;
	q = nullptr;
}



 
bool Deque::isFull()
{
	return (((front == 0) && (back == capacity - 1)) || (front == back + 1));
}

bool Deque::isEmpty()
{
	return ((front == -1) && (back == -1));
}

void Deque::display()
{
	if (isEmpty())
	{
		cout << "\nDeque is empty\n";
		return;
	}
	else
	{
		int i = front;
		while (i != back)
		{
			cout << q[i]<<" ";
			i = (i + 1) % capacity;
		}
		cout << q[back];
	}
}

bool Deque::insertAtFront(int val)
{
	
	if (isFull())
	{
		return false;
	}
	if (isEmpty())
	{
		front = 0;
		back = 0;
		q[front] = val;
		return true;
	}
	else if (front == 0)
	{
		front = capacity - 1;
		//cout << "\n"<<front;
		q[front] = val;
		return true;
	}
	else 
	{
		front = front - 1;
		q[front] = val;
		return true;
	}
}


bool Deque::insertAtBack(int val)
{
	if (isFull())
	{
		return false;
	}
	if (isEmpty())
	{
		front = 0;
		back = 0;
		q[back] = val;
		return true;
	}
	else if (back == capacity - 1)
	{
		back = 0;
		q[back] = val;
		return true;
	}
	else
	{
		back = back + 1;
		q[back] = val;
		return true;
	}


	
	
}
 
bool Deque::removeFromFront(int& val)
{
	
	if (isEmpty())
	{
		return false;
	}
	if (front == back)
	{
		val = q[front];
		front = -1;
		back = -1;  
		return true;
	}
	else  if (front == capacity - 1)
	{
		val = q[front];
		front = 0;
		return true;
	}
	else 
	{
		val = q[front];
		front = front + 1;
		return true;
	}
}


bool Deque::removeFromBack(int& val)
{
	if (isEmpty())
	{
		
		return false;
	}
	if (front == back)
	{
		val = q[back];
		front = -1;
		back = -1;
		return true;
	}
	else if (back == 0)
	{
		val = q[back];
		back = capacity - 1;
		return true;
	}	
	else
	{
		val = q[back];
		back = back - 1;
		return true;
	}
		
}

int main()
{
	Deque q(10);
	q.insertAtFront(50);
	q.insertAtBack(100);
	q.insertAtFront(60);
	q.insertAtBack(200);

	int a;
	q.removeFromFront(a);
	cout << a<<" ";
	q.removeFromBack(a); 
	cout << a << " ";

	cout << "\nafter removing front and back once :";
	q.display();

	q.makeEmpty();
	cout << "\nafter making deque empty :";
	q.display();
	return 0;
}

