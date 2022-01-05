#include<iostream>
using namespace std;

// class deque 3

/*
Dequeue or Double Ended Queue is a generalized version of Queue data structure that allows insert and delete at both ends.

Some basic operations of dequeue are −

insert_at_beg(): inserts an item at the front of Dequeue.

insert_at_end(): inserts an item at the rear of Dequeue.

delete_fr_beg(): Deletes an item from front of Dequeue.

delete_fr_rear(): Deletes an item from rear of Dequeue.

Following is a C++ program to implement Dequeue

Algorithm
Begin
   Declare a class dequeue to declare front f and rear r and following functions:
   function insert_at_beg(int) to insert item at front:
	  If queue is not completely filled up, insert element at the front and update front and rear
	  Otherwise print overflow.
   function insert_at_end(int) to insert item at rear:
	  If queue is not completely filled up, insert element at the rear and update front and rear
	  Otherwise print overflow.
   function delete_fr_beg() to delete item from front:
	  If queue is empty, print underflow otherwise delete the front element and update front.
   function delete_fr_end() to delete item from end:
	  If queue is empty, print underflow otherwise delete the rear element and update rear.
End
*/

/*
#include<iostream>
using namespace std;
#define SIZE 10
class dequeue {
   int a[20],f,r;
   public:
	  dequeue();
	  void insert_at_beg(int);
	  void insert_at_end(int);
	  void delete_fr_front();
	  void delete_fr_rear();
	  void show();
};
dequeue::dequeue() {
   f=-1;
   r=-1;
}
void dequeue::insert_at_end(int i) {
   if(r>=SIZE-1) {
	  cout<<"\n insertion is not possible, overflow!!!!";
   } else {
	  if(f==-1) {
		 f++;
		 r++;
	  } else {
		 r=r+1;
	  }
	  a[r]=i;
	  cout<<"\nInserted item is"<<a[r];
   }
}
void dequeue::insert_at_beg(int i) {
   if(f==-1) {
	  f=0;
	  a[++r]=i;
	  cout<<"\n inserted element is:"<<i;
   } else if(f!=0) {
	  a[--f]=i;
	  cout<<"\n inserted element is:"<<i;
   } else {
	  cout<<"\n insertion is not possible, overflow!!!";
   }
}
void dequeue::delete_fr_front() {
   if(f==-1) {
	  cout<<"deletion is not possible::dequeue is empty";
	  return;
   }
   else {
	  cout<<"the deleted element is:"<<a[f];
	  if(f==r) {
		 f=r=-1;
		 return;
	  } else
		 f=f+1;
	  }
   }
   void dequeue::delete_fr_rear() {
	  if(f==-1) {
		 cout<<"deletion is not possible::dequeue is empty";
		 return;
	  }
	  else {
		 cout<<"the deleted element is:"<<a[r];
		 if(f==r) {
			f=r=-1;
		 } else
			r=r-1;
	  }
   }
   void dequeue::show() {
	  if(f==-1) {
		 cout<<"Dequeue is empty";
	  } else {
		 for(int i=f;i<=r;i++) {
			cout<<a[i]<<" ";
		 }
	  }
   }
   int main() {
	  int c,i;
	  dequeue d;
	  Do//perform switch opeartion {
	  cout<<"\n 1.insert at beginning";
	  cout<<"\n 2.insert at end";
	  cout<<"\n 3.show";
	  cout<<"\n 4.deletion from front";
	  cout<<"\n 5.deletion from rear";
	  cout<<"\n 6.exit";
	  cout<<"\n enter your choice:";
	  cin>>c;
	  switch(c) {
		 case 1:
			cout<<"enter the element to be inserted";
			cin>>i;
			d.insert_at_beg(i);
		 break;
		 case 2:
			cout<<"enter the element to be inserted";
			cin>>i;
			d.insert_at_end(i);
		 break;
		 case 3:
			d.show();
		 break;
		 case 4:
			d.delete_fr_front();
		 break;
		 case 5:
			d.delete_fr_rear();
		 break;
		 case 6:
			exit(1);
		 break;
		 default:
			cout<<"invalid choice";
		 break;
	  }
   } while(c!=7);
}
*/




//class dequeue   1
/*

#include<iostream>
using namespace std;
#define SIZE 5
class dequeue
{
	int a[10],front,rear;
	public:
		dequeue();
		void add_at_beg(int);
		void add_at_end(int);
		void delete_fr_front();
		void delete_fr_rear();
		void display();
};
dequeue::dequeue()
{
	front=-1;
	rear=-1;
}
void dequeue::add_at_end(int item)
{

	if(rear>=SIZE-1)
	{
		cout<<"\n insertion is not posibble,overflow!!!!";
	}
	else
	{
		if(front==-1)
		{
			front++;
			rear++;
		}
		else
		{
			rear=rear+1;
		}
	a[rear]=item;
	cout<<"\nInserted item is"<<a[rear];
	}
}
void dequeue::add_at_beg(int item)
{

		if(front==-1)
		{
			front=0;
			a[++rear]=item;
			cout<<"\n inserted element is"<<item;
		}
		else if(front!=0)
		{
			a[--front]=item;
			cout<<"\n inserted element is"<<item;

		}
		else
		{
			  cout<<"\n insertion is not posibble,overflow!!!";
		}

}
void dequeue::display()
{
	if(front==-1)
	{
		cout<<"Dequeue is empty";
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<a[i]<<" ";
		}
	}
}
void dequeue::delete_fr_front()
{
		if(front==-1)
		{
			cout<<"deletion is not possible::dequeue is empty";
			return;
		}
		else
		{
			cout<<"the deleted element is"<<a[front];
			if(front==rear)
			{
				front=rear=-1;
				return;
			}
			else
				front=front+1;
		}
}
void dequeue::delete_fr_rear()
{
		if(front==-1)
		{
			cout<<"deletion is not possible::dequeue is empty";
			return;
		}
		else
		{
			cout<<"the deleted element is"<<a[rear];
			if(front==rear)
			{
				front=rear=-1;
			}
			else
				rear=rear-1;
		}
}
int main()
{
	int c,item;
	dequeue d1;
	do
	{
		cout<<"\n\n***DEQUEUE OPERATION***\n";
		cout<<"\n 1_insert at beginning";
		cout<<"\n 2_insert at end";
		cout<<"\n 3_display";
		cout<<"\n 4_deletion from front";
		cout<<"\n 5_deletion from rear";
		cout<<"\n 6_exit";
		cout<<"\n enter your choice";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"enter the element to be inserted";
						  cin>>item;
						  d1.add_at_beg(item);
						  break;
			case 2:cout<<"enter the element to be inserted";
						 cin>>item;
						d1.add_at_end(item);
						break;
			case 3:d1.display();
						break;
			case 4:d1.delete_fr_front();
						break;
			case 5:d1.delete_fr_rear();
					  break;
			case 6:exit(1);
						break;
			csdefault:cout<<"invalid choice";
					break;
		}
	}
	while(c!=7);
}
*/


//class dequeue   2
/*
// C++ implementation of De-queue using circular 
// array 
#include<iostream> 
using namespace std;

// Maximum size of array or Dequeue 
const int MAX =100;

// A structure to represent a Deque 
class Deque
{
	int arr[MAX];
	int front;
	int rear;
	int size;
public:
	Deque(int size)
	{
		front = -1;
		rear = 0;
		this->size = size;
	}

	// Operations on Deque: 
	void insertfront(int key);
	void insertrear(int key);
	void deletefront();
	void deleterear();
	bool isFull();
	bool isEmpty();
	int getFront();
	int getRear();
};

// Checks whether Deque is full or not. 
bool Deque::isFull()
{
	return ((front == 0 && rear == size - 1) ||
		front == rear + 1);
}

// Checks whether Deque is empty or not. 
bool Deque::isEmpty()
{
	return (front == -1);
}

// Inserts an element at front 
void Deque::insertfront(int key)
{
	// check whether Deque if full or not 
	if (isFull())
	{
		cout << "Overflow\n" << endl;
		return;
	}

	// If queue is initially empty 
	if (front == -1)
	{
		front = 0;
		rear = 0;
	}

	// front is at first position of queue 
	else if (front == 0)
		front = size - 1;

	else // decrement front end by '1' 
		front = front - 1;

	// insert current element into Deque 
	arr[front] = key;
}

// function to inset element at rear end 
// of Deque. 
void Deque::insertrear(int key)
{
	if (isFull())
	{
		cout << " Overflow\n " << endl;
		return;
	}

	// If queue is initially empty 
	if (front == -1)
	{
		front = 0;
		rear = 0;
	}

	// rear is at last position of queue 
	else if (rear == size - 1)
		rear = 0;

	// increment rear end by '1' 
	else
		rear = rear + 1;

	// insert current element into Deque 
	arr[rear] = key;
}

// Deletes element at front end of Deque 
void Deque::deletefront()
{
	// check whether Deque is empty or not 
	if (isEmpty())
	{
		cout << "Queue Underflow\n" << endl;
		return;
	}

	// Deque has only one element 
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
		// back to initial position 
		if (front == size - 1)
			front = 0;

		else // increment front by '1' to remove current 
			// front value from Deque 
			front = front + 1;
}

// Delete element at rear end of Deque 
void Deque::deleterear()
{
	if (isEmpty())
	{
		cout << " Underflow\n" << endl;
		return;
	}

	// Deque has only one element 
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (rear == 0)
		rear = size - 1;
	else
		rear = rear - 1;
}

// Returns front element of Deque 
int Deque::getFront()
{
	// check whether Deque is empty or not 
	if (isEmpty())
	{
		cout << " Underflow\n" << endl;
		return -1;
	}
	return arr[front];
}

// function return rear element of Deque 
int Deque::getRear()
{
	// check whether Deque is empty or not 
	if (isEmpty() || rear < 0)
	{
		cout << " Underflow\n" << endl;
		return -1;
	}
	return arr[rear];
}

// Driver program to test above function 
int main()
{
	Deque dq(5);
	cout << "Insert element at rear end : 5 \n";
	dq.insertrear(5);

	cout << "insert element at rear end : 10 \n";
	dq.insertrear(10);

	cout << "get rear element " << " "
		<< dq.getRear() << endl;

	dq.deleterear();
	cout << "After delete rear element new rear"
		<< " become " << dq.getRear() << endl;

	cout << "inserting element at front end \n";
	dq.insertfront(15);

	cout << "get front element " << " "
		<< dq.getFront() << endl;

	dq.deletefront();

	cout << "After delete front element new "
		<< "front become " << dq.getFront() << endl;
	return 0;
}

*/

// find kth smallest element 

/*


#include<iostream>
#include<algorithm>
using namespace std;

// Function to return k'th smallest element in a given array
int kthSmallest(int arr[], int n, int k)
{
	// Sort the given array
	sort(arr, arr+n);

	// Return k'th element in the sorted array
	return arr[k-1];
}

// Driver program to test above methods
int main()
{
	int arr[] = {12, 3, 5, 7, 19};
	int n = sizeof(arr)/sizeof(arr[0]), k = 2;
	cout << "K'th smallest element is " <<  kthSmallest(arr, n, k);
	return 0;
}
*/



//Write a function to reverse the contents of a 1-D array of integers.
//You are NOT allowed to allocate any new array within this function. 
//Also determine the exact step count of your function as well as its time complexity (in Big Oh notation).

/*
void rvereseArray(int arr[], int start, int end)
{
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

//Utility function to print an array 
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << endl;
}

// Driver function to test above functions 
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };

	int n = sizeof(arr) / sizeof(arr[0]);

	// To print original array  
	printArray(arr, n);

	// Function calling 
	rvereseArray(arr, 0, n - 1);

	cout << "Reversed array is" << endl;

	// To print the Reversed array 
	printArray(arr, n);

	return 0;
}

*/


