#ifndef IEDITOR_H
#define IEDITOR_H
#include"DNode.h"
#include"CString.h"

#include<iostream>
using namespace std;

enum EditorCommands
{
	LIST_ALL,UP,DOWN,OPEN,SAVE,EXIT,APPEND,REMOVE,MODIFY,NO_COMMAND
};
class IEditor
{
	DNode<CString> * head;
	int linesCount;
	int currentLineNumber;
	DNode<CString>* currentLineRef;
	CString fileName = "Test.txt";
public:
	void start();
	~IEditor();
	void insertAtTail(CString a);

};



IEditor::~IEditor()
{
	if (head ==nullptr)
	{
		return;
	}
	DNode<CString>* x = head;
	while(x!=nullptr)
	{
		DNode<CString>* p = x;
		x = x->next;
		delete p;
	} 
	head = nullptr;
}

void IEditor::insertAtTail(CString a)
{
	if (head == nullptr)
	{
		head = new DNode<CString>(a);
		linesCount = linesCount + 1;
		currentLineRef = head;
		currentLineNumber = currentLineNumber + 1;
	}
	else
	{
		DNode<CString> *p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new DNode<CString>(a);
		currentLineRef = p->next;
		p->next->prev = p;

		linesCount = linesCount + 1;
		
		currentLineNumber = currentLineNumber + 1;
	}

}



void IEditor::start()
{
	head =  nullptr;
	linesCount = 0;
	currentLineNumber = 1;
	currentLineRef = new DNode<CString>;

	//DNode<CString> a;
	cout << currentLineNumber << ">";
	currentLineRef->info.input();     // a.info.input();
	

	while (currentLineRef->info != "_E")
	{
		if (currentLineRef->info[0] == '_')
		{
			
			char b = currentLineRef->info[1];   //    command L E U D  etc
			switch (b)
			{
			case 'L':    // list_all
			{
				if (head != nullptr)
				{
					DNode<CString> *p = head;
					int a = 1;
					while (p != nullptr)
					{
						cout << a << ">";
						cout << p->info << "\n";
						p = p->next;
						a = a + 1;
					}
					//cout << endl;
				}
				break;
			}


			case 'U':               // Move_UP
			{
				if (currentLineRef->info.getLength() == 2)
				{
					currentLineRef = currentLineRef->prev;
					currentLineNumber = currentLineNumber - 1;
				}
				else
				{
					int goToLine = currentLineRef->info[3]-'0';
					for (int i = 0; i < goToLine; i++)
					{
						currentLineRef = currentLineRef->prev;
					}
					currentLineNumber = currentLineNumber - goToLine;
				}
				break;
			}

			case 'D':
			{

			}
			case 'A':
			{
				DNode<CString> b(currentLineRef->info);
				cout << currentLineNumber << ">";
				b.info.input();



				DNode<CString> *x = new DNode<CString>(b);
				x->next = currentLineRef->next;
				x->prev = currentLineRef;
				if (currentLineRef->next != nullptr)
				{
					x->next->prev = x;
				}
				x->prev->next = x;

				currentLineRef = x;
				linesCount = linesCount + 1;
				currentLineNumber = currentLineNumber + 1;

				break;

			}
			case 'M':
			{

				
					CString b;
					cout << currentLineNumber-1 << ">";
					b.input();
					currentLineRef->info = b;
					break;
			}
			case 'R':
			{

			}
			
			}

		}
		else                 //   insert line at currentLineRef
		{
			
			if (head == nullptr)
			{
				head = currentLineRef;
				currentLineRef=new DNode<CString>;
				currentLineRef->prev = head;

				linesCount = linesCount + 1;
				currentLineNumber = currentLineNumber + 1;
			}
			else
			{
				
				if (currentLineRef->prev == nullptr)
				{
					head->next = currentLineRef;
					currentLineRef->prev = head;
					currentLineRef = new DNode<CString>;
					currentLineRef->prev = head->next;
					linesCount = linesCount + 1;
					currentLineNumber = currentLineNumber + 1;
				}




				DNode<CString> *x = new DNode<CString>;
				x->prev = currentLineRef;

				x->next = currentLineRef->next;
				x->prev = currentLineRef;
				if (currentLineRef->next != nullptr)
				{
					x->next->prev = x;
				}
				currentLineRef->next = x;

				currentLineRef = x;
				linesCount = linesCount + 1;
				currentLineNumber = currentLineNumber + 1;
			}
		}

		//currentLineRef->info.~CString();
		cout << currentLineNumber  << ">";
		currentLineRef->info.input();

	}

	
	


}




#endif
