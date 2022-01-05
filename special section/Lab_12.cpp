#include<iostream>
#include<string>
using namespace std;

void menu();

class HashTable {
	string* table;
	int size;
	int currentSize;

public:
	HashTable(int);
	~HashTable();
	bool isEmpty();
	bool isFull();
	bool insert(string);
	bool search(string);
	bool remove(string);
	int value(string);
	int hashFunction(string);
	double loadFactor();
	void setSize(int);
	void display();
};


int main()
{
	menu();
	return 0;
}


////////////////////////////////MEMBER FUNCTION OF HashTable////////////////////////////////
HashTable::HashTable(int temp)
{
	setSize(temp);
	currentSize = 0;
	table = new string[size];
}
HashTable::~HashTable()
{
	for (int i = 0; i < size; i++)
	{
		table[i] = "";
	}
	size = 0;
	currentSize = 0;
	delete[] table;
}
bool HashTable::isEmpty()
{
	if (currentSize == 0)
		return true;
	else
		return false;
}
bool HashTable::isFull()
{
	if (currentSize == size)
		return true;
	else
		return false;
}
bool HashTable::insert(string name)
{
	if (isFull())
		return false;

	int index = hashFunction(name);
	while (true)
	{
		if (table[index] == "")
		{
			table[index] = name;
			currentSize++;
			return true;
		}
		else
		{
			index++;
		}

		if (index > size)
			index = 0;
	}
}
bool HashTable::search(string name)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] == name)
			return true;
	}
	return false;
}
bool HashTable::remove(string name)
{
	if (isEmpty())
		return false;

	if (!search(name))
		return false;

	int index = hashFunction(name);
	while (true)
	{
		if (table[index] == name)
		{
			table[index] = "";
			currentSize--;
			return true;
		}
		else
		{
			index++;
		}

		if (index > size)
			index = 0;
	}
}
int HashTable::value(string name)
{
	int count = 0;
	for (int i = 0; i < name.length(); i++)
		count = count + name[i];
	return count;
}
int HashTable::hashFunction(string name)
{
	return (value(name) % size);
}
double HashTable::loadFactor()
{
	return ((double)currentSize / (double)size);
}
void HashTable::setSize(int temp)
{
	if (temp < 0)
		size = 0;
	else
		size = temp;
}
void HashTable::display()
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] == "")
			cout << "EMPTY" << endl;
		else
			cout << table[i] << endl;
	}
}

void menu()
{
	int hashSize;
	cout << "Enter the size of the hash table: ";
	cin >> hashSize;

	int choice;
	string hashName;
	bool condition = true;
	HashTable hash(hashSize);

	do
	{
		cout << "\n1. Insert a name";
		cout << "\n2. Search for a name";
		cout << "\n3. Remove a name";
		cout << "\n4. Display the table";
		cout << "\n5. Display the load factor of the table";
		cout << "\n6. Exit\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cin >> hashName;
			if (hash.insert(hashName))
				cout << "\nName is successfully inserted";
			else
				cout << "\nTable is fulled";
			break;
		case 2:
			cin >> hashName;
			if (hash.search(hashName))
				cout << "\nFound successfully";
			else
				cout << "\nNot found";
			break;
		case 3:
			if (hash.isEmpty())
			{
				cout << "\nTable is empty";
				break;
			}
			cin >> hashName;
			if (hash.remove(hashName))
				cout << "\nName is successfully removed";
			else
				cout << "\nName not found";
			break;
		case 4:
			cout << "\nTable:\n";
			hash.display();
			break;
		case 5:
			cout << "\nLoad Factor of the table = " << hash.loadFactor();
			break;
		case 6:
			condition = false;
			break;
		default:
			cout << "\nInvalid Choice. Enter Again!";
			break;
		}
	} while (condition);
}