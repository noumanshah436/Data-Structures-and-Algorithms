#include<iostream>
using namespace std;
#include"IEditor.h"
int main()
{
	/*CString a("Suleman");
	cout<< (a == "Suleman");
*/


	IEditor ie;
	ie.start();
	cout << "\nlast\n";

	return 0;
}