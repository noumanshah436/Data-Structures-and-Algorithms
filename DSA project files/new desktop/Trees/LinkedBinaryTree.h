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

	void VLR(BTNode<T> *p)   //   preOrder   // time    0(n)
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
	void LVR(BTNode<T> *p)   //  in Ordre   // time    0(n)
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
	void LRV(BTNode<T> *p)   // post Order // time    0(n)
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
	void removeNode(BTNode<T> * p)   // time    0(n)
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
	

	int nodeHeight(BTNode<T> * p)    // time    0(n)
	{
		int lh = 0, rh = 0;
		if (p->left)
		{
			lh=nodeHeight(p->left);
		}
		if (p->right)
		{
			rh = nodeHeight(p->right);
		}

		return lh>rh?lh+1:rh+1;
	}
	int getHeight()  // time    0(n)
	{
		return 	nodeHeight(root);
	}

	void displayAncestors(T node)     // time    0(n)
	{
		// BTNode<T> * p = searchNode(node, root);
		 BTNode<T> * par = searchParent(node, root);
		 while (par != root)
		 {
			 cout << par->info << ",";
			 par = searchParent(par->info, root);
		 }
		 cout << par->info;
	}

	void displayDescendants(T node)   // time    0(n)
	{
		BTNode<T> * p = searchNode(node,root);

		if (p->left)
		{
			VLR(p->left);
		}
		if (p->right)
		{
			VLR(p->right);
		}
	}
	

	void remove(T key)   // time    0(n)
	{
		BTNode<T> * par= searchParent(key,root);
		if (par == nullptr)
		{
			return;
		}
		if (par->left && par->left->info == key)
		{
			removeNode(par->left);
			par->left = nullptr;
		}
		else 
		{
			removeNode(par->right);
			par->right = nullptr;
		}
	}

	BTNode<T> * searchParent(T key, BTNode<T> *p)   // time    0(n)
	{
		BTNode<T> * res = nullptr;
		if (p->left && p->left->info==key)
		{
			res = p;
		}
		else if (p->right && p->right->info == key)
		{
			res = p;
		}

		if (p->left && res == nullptr)
		{
			res = searchParent(key, p->left);
		}
		if (p->right &&  res == nullptr)
		{
			res = searchParent(key, p->right);
		}

		return res;
	}


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



	BTNode<T>* searchNode(T key, BTNode<T> *p)   // time    0(n)
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
	~LinkedBinaryTree()
	{
		if (root)
		{
			removeNode(root);
			root = nullptr;
		}
	}
	LinkedBinaryTree()
	{
		root = nullptr;
	}
	void setRoot(T val)     //  time    0(1)
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
	void setLeftChild(T par,T ch) //  time    0(1)
	{
		BTNode<T> * p = searchNode(par, root);
		
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
	void setRightChild(T par, T ch)  //  time    0(1)
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
		
	}

	bool searchNode(T key)
	{
	
		return searchNode(key, root) != nullptr;
	}



};


#endif