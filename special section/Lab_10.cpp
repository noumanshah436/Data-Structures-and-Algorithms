#include<iostream>
using namespace std;

/*
int Delete(int value)
	{
		if (!find(value))
			return 0;

		avl_node* currentNode = root;
		avl_node* tempNode = NULL;
		avl_node* previousNode = NULL;
		int flag = 0;
		while (currentNode != NULL)
		{
			if (value == currentNode->data)
			{
				tempNode = currentNode;
				break;
			}
			else if (value < currentNode->data)
			{
				flag = -1;
				previousNode = currentNode;
				currentNode = currentNode->left;
			}
			else
			{
				flag = 1;
				previousNode = currentNode;
				currentNode = currentNode->right;
			}
		}
		if (tempNode->left == NULL && tempNode->right == NULL)
		{
			if (flag == -1)
				previousNode->left = NULL;
			else if (flag == 1)
				previousNode->right = NULL;

			delete tempNode;
		}
		else if (tempNode->left == NULL)
		{
			if (flag == -1)
				previousNode->left = tempNode->right;
			else if (flag == 1)
				previousNode->right = tempNode->right;

			delete tempNode;
		}
		else if (tempNode->right == NULL)
		{
			if (flag == -1)
				previousNode->left = tempNode->left;
			else if (flag == 1)
				previousNode->right = tempNode->left;

			delete tempNode;
		}
		else
		{
			avl_node* maxNode = tempNode->left;
			while (maxNode->right != NULL)
			{
				maxNode = maxNode->right;
			}
			int max = maxNode->data;
			Delete(max);
			tempNode->data = max;
		}

		//rotation(root->right);
		 //balance(root->right);
		return 1;
	}*/
class BSTNode {
public:
	int	data;
	BSTNode* left;
	BSTNode* right;

	BSTNode();
	BSTNode(int);
};

class BinarySearchTree {
public:
	BSTNode* root;

	BinarySearchTree();
	BinarySearchTree(BSTNode*);
	bool isEmpty();
	int LeftMax(BSTNode*);
	int RightMin(BSTNode*);
	int LoopHeight(BSTNode*);
	bool Find(int);
	bool Insert(int);
	void Update(int, int);
	bool Remove(int);
	int Height(int);
	int Depth(int);
};


int main()
{
	BinarySearchTree task;

	/////////////////////////INSERT FUNCTION/////////////////////////
	task.Insert(30); task.Insert(10); task.Insert(3); task.Insert(7); task.Insert(8); task.Insert(5); task.Insert(4); task.Insert(-1); task.Insert(9);
	task.Insert(40); task.Insert(-5); task.Insert(-10); task.Insert(-4); task.Insert(45); task.Insert(35); task.Insert(32); task.Insert(12);

	/////////////////////////UPDATE FUNCTION/////////////////////////
	task.Update(3, 2); task.Update(7, 6); task.Update(10, 11); task.Update(30, 31); task.Update(40, 43); task.Update(45, 50); task.Update(-5, -9);

	/////////////////////////REMOVE FUNCTION/////////////////////////
	task.Remove(-1); task.Remove(9); task.Remove(4); task.Remove(32); task.Remove(50); task.Remove(31); task.Remove(35);

	/////////////////////////FIND FUNCTION/////////////////////////
	cout << "\n\nFINDING -9 (1 means found 0 means not found) = " << task.Find(-9);
	cout << "\nFINDING 21 (1 means found 0 means not found) = " << task.Find(21);

	/////////////////////////HEIGHT FUNCTION/////////////////////////
	cout << "\n\nHEIGHT OF 2 = " << task.Height(2);
	cout << "\nHEIGHT OF 43 = " << task.Height(43);

	/////////////////////////DEPTH FUNCTION/////////////////////////
	cout << "\n\nDEPTH OF 6 = " << task.Depth(6);
	cout << "\nDEPTH OF 11 = " << task.Depth(11);

	return 0;
}


/////////////////////////MEMBER FUNCTION OF BinarySearchTree/////////////////////////
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}
BinarySearchTree::BinarySearchTree(BSTNode* root)
{
	this->root = root;
}
bool BinarySearchTree::isEmpty()
{
	if (root == NULL)
		return true;
	else
		return false;
}
int BinarySearchTree::LeftMax(BSTNode* root)
{
	if (root == NULL)
		return INT_MIN;

	int value = root->data;
	int left = LeftMax(root->left);
	int right = LeftMax(root->right);

	if (left > value)
		value = left;

	if (right > value)
		value = right;

	return value;
}
int BinarySearchTree::RightMin(BSTNode* root)
{
	if (root == NULL)
		return INT_MAX;

	int value = root->data;
	int left = RightMin(root->left);
	int right = RightMin(root->right);

	if (left < value)
		value = left;

	if (right < value)
		value = right;

	return value;
}
int BinarySearchTree::LoopHeight(BSTNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		int leftSide = LoopHeight(node->left);
		int rightSide = LoopHeight(node->right);

		if (leftSide >= rightSide)
			return leftSide + 1;
		else
			return rightSide + 1;
	}
}
bool BinarySearchTree::Find(int data)
{
	BSTNode* currentNode = root;
	while (currentNode != NULL)
	{
		if (data == currentNode->data)
			return 1;
		else if (data < currentNode->data)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}
	return 0;
}
bool BinarySearchTree::Insert(int data)
{
	BSTNode* newNode, * nodePtr = NULL;
	newNode = new BSTNode;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	if (root == NULL)
	{
		root = newNode;
		return 1;
	}
	else
	{
		nodePtr = root;
	}
	while (nodePtr != NULL)
	{
		if (data < nodePtr->data)
		{
			if (nodePtr->left)
			{
				nodePtr = nodePtr->left;
			}
			else
			{
				nodePtr->left = newNode;
				return 1;
			}
		}
		else if (data > nodePtr->data)
		{
			if (nodePtr->right)
			{
				nodePtr = nodePtr->right;
			}
			else
			{
				nodePtr->right = newNode;
				return 1;
			}
		}
		else
		{
			delete newNode;
			break;
		}
	}
	return 0;
}
void BinarySearchTree::Update(int data, int updatedData)
{
	if (!Find(data))
		return;

	if (Find(updatedData))
		return;

	BSTNode* currentNode = root;
	while (currentNode != NULL)
	{
		if (data == currentNode->data)
			break;
		else if (data < currentNode->data)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}
	int getLeft, getRight;

	if (currentNode->left != NULL)
		getLeft = LeftMax(currentNode->left);
	else
		getLeft = updatedData - 1;

	if (currentNode->right != NULL)
		getRight = RightMin(currentNode->right);
	else
		getRight = updatedData + 1;

	int save = currentNode->data;

	if (getLeft<updatedData && getRight>updatedData)
		currentNode->data = updatedData;

	if (!Find(updatedData))
		currentNode->data = save;
}
bool BinarySearchTree::Remove(int data)
{
	if (!Find(data))
		return 0;

	if (data == root->data)
	{
		if (root->right == NULL)
		{
			BSTNode* tempNode = root;
			root = root->left;
			delete tempNode;
			return 1;
		}
		else if (root->left == NULL)
		{
			BSTNode* tempNode = root;
			root = root->right;
			delete tempNode;
			return 1;
		}
		else
		{
			BSTNode* tempNode = root;
			BSTNode* currentNode1 = root;
			root = root->right;
			currentNode1 = currentNode1->right;
			while (currentNode1->left != NULL)
			{
				currentNode1 = currentNode1->left;
			}
			currentNode1->left = tempNode->left;
			delete tempNode;
			return 1;
		}
	}

	BSTNode* currentNode = root;
	BSTNode* previousNode = root;
	int previous;

	while (currentNode != NULL)
	{
		if (data == currentNode->data)
		{
			break;
		}
		else if (data < currentNode->data)
		{
			previous = -1;
			previousNode = currentNode;
			currentNode = currentNode->left;
		}
		else
		{
			previous = 1;
			previousNode = currentNode;
			currentNode = currentNode->right;
		}
	}

	if (currentNode->right == NULL)
	{
		if (previous == 1)
		{
			BSTNode* tempNode = currentNode;
			previousNode->right = currentNode->left;
			delete tempNode;
			return 1;
		}
		else if (previous == -1)
		{
			BSTNode* tempNode = currentNode;
			previousNode->left = currentNode->left;
			delete tempNode;
			return 1;
		}
	}
	else if (currentNode->left == NULL)
	{
		if (previous == 1)
		{
			BSTNode* tempNode = currentNode;
			previousNode->right = currentNode->right;
			delete tempNode;
			return 1;
		}
		else if (previous == -1)
		{
			BSTNode* tempNode = currentNode;
			previousNode->left = currentNode->right;
			delete tempNode;
			return 1;
		}
	}
	else
	{
		if (previous == -1)
		{
			BSTNode* tempNode = currentNode;
			previousNode->left = currentNode->right;
			currentNode = currentNode->right;
			while (currentNode->left != NULL)
			{
				currentNode = currentNode->left;
			}
			currentNode->left = tempNode->left;
			delete tempNode;
			return 1;
		}
		else if (previous == 1)
		{
			BSTNode* tempNode = currentNode;
			previousNode->right = currentNode->right;
			currentNode = currentNode->right;
			while (currentNode->left != NULL)
			{
				currentNode = currentNode->left;
			}
			currentNode->left = tempNode->left;
			delete tempNode;
			return 1;
		}
	}
	return 0;
}
int BinarySearchTree::Height(int data)
{
	if (!Find(data))
		return -1;

	BSTNode* currentNode = root;
	while (currentNode != NULL)
	{
		if (data == currentNode->data)
		{
			break;
		}
		else if (data < currentNode->data)
		{
			if (currentNode->left == NULL)
			{
				break;
			}
			else
			{
				currentNode = currentNode->left;
				continue;
			}
		}
		else
		{
			if (currentNode->right == NULL)
			{
				break;
			}
			else
			{
				currentNode = currentNode->right;
				continue;
			}
		}
	}

	int height = LoopHeight(currentNode) - 1;
	return height;
}
int BinarySearchTree::Depth(int data)
{
	if (!Find(data))
		return -1;

	int countOfEdges = 0;
	BSTNode* currentNode = root;

	while (currentNode != NULL)
	{
		if (data == currentNode->data)
		{
			return countOfEdges;
		}
		else if (data < currentNode->data)
		{
			if (!currentNode->left)
			{
				return countOfEdges;
			}
			else
			{
				countOfEdges++;
				currentNode = currentNode->left;
			}
		}
		else
		{
			if (!currentNode->right)
			{
				return countOfEdges;
			}
			else
			{
				countOfEdges++;
				currentNode = currentNode->right;
			}
		}
	}
}

/////////////////////////MEMBER FUNCTION OF BSTNode/////////////////////////
BSTNode::BSTNode()
{
	data = 0;
	left = NULL;
	right = NULL;
}
BSTNode::BSTNode(int data)
{
	this->data = data;
	left = NULL;
	right = NULL;
}