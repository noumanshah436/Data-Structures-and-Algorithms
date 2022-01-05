#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class SortedList
{
private:
	int * arr; // Array which contains the elements of the list in Sorted (increasing) order 
	int maxSize;
	int currSize;

public:
	SortedList(int size);   // Constructor 
   ~SortedList();   // Destructor 
	bool insert(int val); // Insert a new value in the list 
	bool remove(int index, int& val);  //// Remove the value stored at a particular index in the list  void 
	void display(); // Display the contents of list on screen 
	int removeAll(int val);
	bool replace(int index, int newVal);
};



#endif