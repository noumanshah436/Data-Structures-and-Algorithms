#ifndef D_NODE_H
#define D_NODE_H


template <typename T>
struct DNode
{
	T info;;
	DNode<T> * next;
	DNode<T> * prev;

	DNode()
	{
		next = nullptr;
		prev = nullptr;
	}
	DNode(T val)
	{
		info = val;
		next = nullptr;
		prev = nullptr;
	}
};

#endif