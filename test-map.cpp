#include "map.h"

int main()
{
	Tree<int, int> obj;
	for (int i = 0; i < 10; ++i)
	{
		obj.addElement(i, i);
		// obj.printTree();
		// cout << "*********\n";
	}
	obj.printTree();
	// obj.addElement(10, 10);
	// obj.printTree();
	// cout << "*********\n";
	// obj.addElement(12, 12);
	// obj.printTree();
	// cout << "*********\n";
	// obj.addElement(11, 11);
	// obj.printTree();
	// cout << "*********\n";
	// obj.addElement(2, 2);
	// obj.printTree();
	// cout << "*********\n";
	// // obj.addElement(12, 12);
	// // obj.printTree();
	// // cout << "*********\n";
	// // obj.addElement(11, 11);
	// // obj.printTree();
	// // cout << "*********\n";
	// obj.addElement(14, 14);
	// obj.printTree();
	// cout << "*********\n";
	// obj.addElement(-5, -5);
	// obj.printTree();
	// cout << "*********\n";
	// obj.addElement(3, 3);
	// obj.printTree();
	// cout << "*********\n";	
	// obj.addElement(4, 4);
	// obj.printTree();
	// cout << "*********\n";
	// obj.addElement(7, 7);
	// obj.printTree();
	// cout << "*********\n";
	// cout << "TEST APPENDING ELEMENT AND PRINTING INTERFACE: \n";
	// obj.printTree();
	cout << "COPY CONSTRUCTOR: \n";
	Tree<int, int> obj1(obj);
	obj.clearAll();
	obj1.printTree();
	// cout << "COPY OPERATOR= \n";
	// Tree<int, int> obj2(obj);
	// obj2.printTree();
	// cout << "***************\n";
	
	// obj.printTree();

	// cout << "TEST FOR SEARCHING ELEMENT: \n";
	// cout << obj[10] << endl;
	// cout << "Is empty obj: " << obj.empty() << endl;
	// cout << "TEST CLEARING: \n";
	// obj.clearAll();
	// cout << "Is empty: " << obj.empty() << endl;
	Tree<int, int> temp;
	temp.test();
	// temp.printTree();
	cout << "QUIT" << endl;
	return 0;
}