#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include"Queue.h"

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
		data =val;
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



	void VLR(TreeNode *p)   //   preOrder
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
	void LVR(TreeNode *p)   //  in Ordre
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
	void LRV(TreeNode *p)   // post Order
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
				if ( p->left != nullptr)
				{
					if(p->right!=nullptr)
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
					 p->left=new TreeNode(val);
					 return;
				}

				p = a.deQueue();
				
		}
		root = new TreeNode(val);
	}


};


#endif