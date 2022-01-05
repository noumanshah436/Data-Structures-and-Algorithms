#ifndef D_NODE_H
#define D_NODE_H


template <typename T>
struct DNode
{
	T info;;
	DNode<T> * next;
	DNode<T> * prev;

	DNode();
	DNode(T val);
	
};

#endif