#ifndef ARRAY_BASED_BINARY_TREE
#define ARRAY_BASED_BINARY_TREE

template<typename T>
class ArrayBasedBinaryTree
{
	T*data;
	int maxHeight;
	int maxNodes;
	bool * nodeStatus;



	void VLR(int i)   //   preOrder
	{
		cout << data[i] << ",";
		if (2 * i + 1 < maxNodes && nodeStatus[2 * i + 1] == true)
		{
			VLR(2 * i + 1);
		}
		if (2 * i + 2 < maxNodes && nodeStatus[2 * i + 2] == true)
		{
			VLR(2 * i + 2);
		}
	}
	void LVR(int i)   //  in Ordre
	{
		
		if (2 * i + 1 < maxNodes && nodeStatus[2 * i + 1] == true)
		{
			LVR(2 * i + 1);
		}
		cout << data[i] << ",";
		if (2 * i + 2 < maxNodes && nodeStatus[2 * i + 2] == true)
		{
			LVR(2 * i + 2);
		}
	}
	void LRV(int i)   // post Order
	{

		if (2 * i + 1 < maxNodes && nodeStatus[2 * i + 1] == true)
		{
			LRV(2 * i + 1);
		}
		
		if (2 * i + 2 < maxNodes && nodeStatus[2 * i + 2] == true)
		{
			LRV(2 * i + 2);
		}
		cout << data[i] << ",";
	}
	void removeNode(int i)
	{
		nodeStatus[i] = false;
		if (2 * i + 1 < maxNodes && nodeStatus[2 * i + 1] == true)
		{
			removeNode(2 * i + 1);
		}

		if (2 * i + 2 < maxNodes && nodeStatus[2 * i + 2] == true)
		{
			removeNode(2 * i + 2);
		}

	}

public:

	void inOrder()
	{
		LVR(0);
	}
	void postOrder()
	{
		LRV(0);
	}
	void preOrder()
	{
		VLR(0);
	}
	ArrayBasedBinaryTree(int h=4)
	{
		maxHeight = h;
		maxNodes = pow(2, maxHeight) - 1;
		//cout << "\n maxnodes\n"<<maxNodes;
		data = new T[maxNodes];
		nodeStatus = new bool[maxNodes];
		for (int i = 0; i < maxNodes; i++)
		{
			nodeStatus[i] = false;
		}
	}


	~ArrayBasedBinaryTree()
	{
		if (data)
		{
			delete[] data;
			data = nullptr;
			delete[] nodeStatus;
			nodeStatus = nullptr;
		}
	}

	void setRoot(T val)
	{
		data[0] = val;
		//cout << "data[0]" << data[0]<<endl;
		nodeStatus[0] = true;
	}
	T getRoot()
	{
		if (nodeStatus[0] == true)
		{
			return data[0];
		}
		throw exception();
	}
	int searchNode(T key)
	{
		return searchNode(key, 0);
	}
	int searchNode(T key, int i)   // time    0(n)
	{
		int res = -1;
		if (data[i] == key)
		{
			res = i;
		}

		if (res == -1 && (2 * i + 1) < maxNodes && nodeStatus[2 * i + 1] == true)
		{
			res = searchNode(key, 2 * i + 1);
		}
		if (res == -1 && (2 * i + 2) < maxNodes && nodeStatus[2 * i + 2] == true)
		{
			res = searchNode(key, 2 * i + 2);
		}

		return res;
	}
	void setLeftChild(T par, T ch)  //  time    0(1)
	{
		int p = searchNode(par);
		if (p != -1 && 2 * p + 1 < maxNodes)
		{
			data[2 * p + 1] = ch;
			nodeStatus[2 * p + 1] = true;
		}
	}
	void setRightChild(T par, T ch)   //  time    0(1)
	{

		int p = searchNode(par);
		if (p != -1 && 2 * p + 2 < maxNodes)
		{
			data[2 * p + 2] = ch;
			nodeStatus[2 * p + 2] = true;
		}
	}
	void remove(T key)   //  time    0(1)
	{
		int p = searchNode(key, 0);
		if (p == -1)
		{
			return;
		}
		removeNode(p);
	}

	void displayAncestors(T node)   //  time    0(1)
	{
		int p = searchNode(node);

		if (p % 2 == 0)
		{
			int parNode = (p - 2) / 2;
			if (parNode == 0)
			{
				cout << data[0];
				return;
			}
			cout << data[parNode] << ",";
			displayAncestors(data[parNode]);
		}
		else
		{
			int parNode = (p - 1) / 2;
			if (parNode == 0)
			{
				cout << data[0];
				return;
			}
			cout << data[parNode] << ",";
			displayAncestors(data[parNode]);
		}
	}

	void displayDescendants(T node)    //  time    0(1)
	{
		int p = searchNode(node);
		if (2 * p + 1 < maxNodes && nodeStatus[2 * p + 1] == true)
		{
			VLR(2 * p + 1);
		}
		if (2 * p + 2 < maxNodes && nodeStatus[2 * p + 2] == true)
		{
			VLR(2 * p + 2);
		}
	}


};


#endif
