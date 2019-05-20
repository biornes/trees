#include "map.h"

int main()
{
	Tree<int, int> obj;
	obj.addElement(10, 10);
	obj.addElement(2, 2);
	obj.addElement(12, 12);
	obj.addElement(11, 11);
	obj.addElement(14, 14);
	obj.addElement(-5, -5);
	obj.addElement(3, 3);	
	obj.addElement(4, 4);
	obj.addElement(7, 7);
	cout << "TEST APPENDING ELEMENT AND PRINTING INTERFACE: \n";
	obj.printTree();
	cout << "COPY CONSTRUCTOR: \n";
	Tree<int, int> obj1(obj);


	obj1.printTree();
	cout << "COPY OPERATOR= \n";
	Tree<int, int> obj2(obj);
	obj2.printTree();
	cout << "***************\n";
	
	obj.printTree();

	cout << "TEST FOR SEARCHING ELEMENT: \n";
	cout << obj[10] << endl;
	cout << "Is empty obj: " << obj.empty() << endl;
	cout << "TEST CLEARING: \n";
	obj.clearAll();
	cout << "Is empty: " << obj.empty() << endl;
	cout << "QUIT" << endl;
	return 0;
}