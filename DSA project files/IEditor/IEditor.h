#ifndef IEDITOR_H
#define IEDITOR_H
#include"DNode.h"
#include"CString.h"

enum EditorCommands
{
	LIST_ALL, UP, DOWN, OPEN, SAVE, EXIT, APPEND, REMOVE, MODIFY, NO_COMMAND
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
	void setFileName(const CString & fn);
	CString getFileName();

};




#endif
