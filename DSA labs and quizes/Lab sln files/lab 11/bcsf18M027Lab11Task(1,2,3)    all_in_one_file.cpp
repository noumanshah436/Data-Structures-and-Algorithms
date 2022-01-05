#include<iostream>
using namespace std;

//   BCSF18M027
//   Syed Nouman Rehman


//     this cpp file contain 
//     1)   1st  Queue class
//     2)   2nd TreeNode class
//     3)   3rd BinaryTree class
//     4)   and then the main()   function



//   this queue is implemented officially by Sir Fareed
//    Queue class for insert function of Task # 2
template <typename T>
class Queue
{
	T * data;
	int rear;   //  index where next val is palced
	int front;
	int capacity;
	int noOfElements;

	void reSize(int newSize)
	{
		T*temp = new T[newSize];
		for (int j = 0, i = front; j < noOfElements; j++)
		{
			temp[j] = data[i];
			i = (i + 1) % capacity;
		}
		this->~Queue();
		data = temp;
		//temp = nullptr;
		rear = noOfElements;
		front = 0;
		capacity = newSize;



	}
public:

	Queue()
	{
		rear = 0;
		front = 0;
		capacity = 1;
		noOfElements = 0;
		data = new T[capacity];
	}

	~Queue()
	{
		if (!data)
		{
			return;
		}
		delete[] data;
		data = nullptr;
	}

	void enQueue(T val)
	{
		if (isFull())
		{
			//cout << capacity << " " << noOfElements;
			reSize(capacity * 2);
		}
		data[rear] = val;
		rear = (rear + 1) % capacity;
		noOfElements++;

	}


	T deQueue()
	{
		if (isEmpty())
		{
			throw exception();
		}
		T val = data[front];
		front = (front + 1) % capacity;
		noOfElements--;
		if (noOfElements > 0 && (noOfElements == (capacity / 4)))
		{
			reSize(capacity / 2);
		}
		return val;
	}

	bool isFull()
	{
		return noOfElements == capacity;

	}

	bool isEmpty()
	{
		return noOfElements == 0;
	}

	T getElementAtFront()
	{
		if (isEmpty())
		{
			throw exception();
		}
		return data[front];
	}
	int getNoOfElements()
	{
		return noOfElements;
	}
	int getCapacity()
	{
		return capacity;
	}

};

//Task # 1

class TreeNode
{
	friend class BinaryTree;

	int data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int val)
	{
		data = val;
		left = right = nullptr;
	}
	TreeNode()
	{
		left = right = nullptr;
	}
};
class BinaryTree
{

	TreeNode * root;

	void VLR(TreeNode *p)   //   for  preOrder
	{
		cout << p->data << ",";
		if (p->left)
		{
			VLR(p->left);
		}
		if (p->right)
		{
			VLR(p->right);
		}
	}
	void LVR(TreeNode *p)   //  for  in Ordre
	{
		if (p->left)
		{
			LVR(p->left);
		}
		cout << p->data << ",";
		if (p->right)
		{
			LVR(p->right);
		}
	}
	void LRV(TreeNode *p)   //    for  post Order
	{
		if (p->left)
		{
			LRV(p->left);
		}

		if (p->right)
		{
			LRV(p->right);
		}
		cout << p->data << ",";
	}
	void removeNode(TreeNode * p)
	{

		if (p->left)
		{
			removeNode(p->left);
		}
		if (p->right)
		{
			removeNode(p->right);
		}
		delete p;
	}

public:
	//   Task # 3
	void inOrder()
	{
		LVR(root);
	}
	void postOrder()
	{
		LRV(root);
	}
	void preOrder()
	{
		VLR(root);
	}

	BinaryTree(int a)
	{
		root = new  TreeNode;
		root->data = a;
		root->left = root->right = nullptr;
	}
	BinaryTree()
	{
		root = nullptr;
	}

	~BinaryTree()
	{
		if (root)
		{
			removeNode(root);
			root = nullptr;
		}
	}

	// Task # 2
	void insert(int val)
	{
		Queue<TreeNode *> a;
		TreeNode * p = root;
		while (p != nullptr)
		{
			if (p->left != nullptr)
			{
				if (p->right != nullptr)
				{
					a.enQueue(p->left);
					a.enQueue(p->right);
				}
				else
				{
					p->right = new TreeNode(val);
					return;
				}
			}
			else
			{
				p->left = new TreeNode(val);
				return;
			}

			p = a.deQueue();

		}
		root = new TreeNode(val);
	}


};



int main()
{
	//  Task # 1
	BinaryTree a;

	//  Task # 2
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	
	
	//Task # 3
	cout << "Pre Ordre  : ";
	a.preOrder();
	cout << "\n";

	cout << "In Ordre   : ";
	a.inOrder();
	cout << "\n";

	cout << "Post Ordre : ";
	a.postOrder();
	cout << "\n";


	return 0;
}