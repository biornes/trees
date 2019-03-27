#include <iostream>

using namespace std;


template <typename T>
class Node
{
	public:
		Node()

	private:
		T* _l_;
		T* _r_;
		T* _parent_;
		T* _data_;
};