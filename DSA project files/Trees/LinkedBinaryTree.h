#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H


template<typename T>
struct BTNode
{
	T info;
	BTNode<T>*left;
	BTNode<T>*right;
	BTNode()
	{
		left = right = nullptr;
	}
	BTNode(T val)
	{
		info = val;
		left = right = nullptr;
	}

};
template<typename T>
class LinkedBinaryTree
{
	BTNode<T>*root;


	void VLR(BTNode<T> *p)   //   preOrder
	{
		cout <<p->info<< ",";
		if (p->left)
		{
			VLR(p->left);
		}
		if (p->right)
		{
			VLR(p->right);
		}
	}
	void LVR(BTNode<T> *p)   //  in Ordre
	{
		if (p->left)
		{
			LVR(p->left);
		}
		cout << p->info << ",";
		if (p->right)
		{
			LVR(p->right);
		}
	}
	void LRV(BTNode<T> *p)   // post Order
	{
		if (p->left)
		{
			LRV(p->left);
		}
		
		if (p->right)
		{
			LRV(p->right);
		}
		cout << p->info << ",";
	}


public:

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



	BTNode<T>* searchNode(T key, BTNode<T> *p)
	{
		BTNode<T> *res = nullptr;
		if (p->info == key)
		{
			res = p;
		}

		if (res == nullptr && p->left)
		{
			res = searchNode(key, p->left);
		}
		if (res == nullptr && p->right)
		{
			res = searchNode(key, p->right);
		}

		return res;
	}

	LinkedBinaryTree()
	{
		root = nullptr;
	}
	void setRoot(T val)
	{
		if (!root)
		{
			root = new BTNode<T>(val);
		}
		else
		{
			root->info = val;
		}
	}
	void setLeftChild(T par,T ch)
	{
		BTNode<T> * p = searchNode(par, root);
		/*if (p == nullptr)
		{
			return;
		}

		if (p->left)
		{
			p->left->info = ch;
			

		}
		else
		{
			p->left = new BTNode<T>(ch);
		}*/
		if (p != nullptr)
		{
			if (p->left == nullptr)
			{
				p->left = new BTNode<T>(ch);

			}
			else 
			{
				p->left->info = ch;
			}
		}
	}
	void setRightChild(T par, T ch)
	{

		BTNode<T> * p = searchNode(par, root);
		
		if (p != nullptr)
		{
			if (p->right == nullptr)
			{
				p->right = new BTNode<T>(ch);

			}
			else
			{
				p->right->info = ch;
			}
		}
		/*if (p == nullptr)
		{
			return;
		}

		if (p->right)
		{
			p->right->info = ch;


		}
		else
		{
			p->right = new BTNode<T>(ch);
		}*/
	}

	bool searchNode(T key)
	{
	
		return searchNode(key, root) != nullptr;
	}



};


#endif