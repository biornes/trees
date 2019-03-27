#include <iostream>

using namespace std;


template <typename T>
class Node
{
	public:
		// Node()
		// {

		// }
		Node(T val, Node<T> *parent = 0) : val(val), parent(parent){}
		Node(Node<T> *parent = 0) : parent(parent), left(NULL), right(NULL){}



		const T getVal()
		{
			return val;
		}
		void setVal(T val)
		{
			this->val = val;
		}
		Node<T>* getLeft()
		{
			return left;
		}
		Node<T>* getRight()
		{
			return right;
		}
		void setRight(Node<T> node)
		{
			right = node;
		}
		void setLeft(Node<T> node)
		{
			left = node;
		}

	private:
		Node<T> *parent = NULL;
		Node<T> *left = NULL;
		Node<T> *right = NULL;
		T val;
};


template <typename T>
class Tree
{
	public:
		// Tree(){
		// 	root = Node<T>();
		// }
		Tree(T val)
		{
			root = Node<T>(val);
			++count;
		}

		void print_root()
		{
			cout << root.getVal() << endl;
		}

		void append(T val)
		{
			if (count == 0){
				root.setVal(val);
			}
			else
				recursive_append(root, val);
			count++;
		}
		void recursive_append(Node<T> temp, T val)
		{
			cout << *temp.getRight() == NULL << endl;
			// if (temp.getVal() < val)
			// {
			// 	if (temp.getRight() == NULL)
			// 	{
			// 		temp.setRight(Node<T>(val));
			// 	}
			// 	else
			// 	{
			// 		recursive_append(temp.getRight(), val);
			// 	}
			// }
			// else if (temp.getVal() > val)
			// {
			// 	if (temp.getLeft() == NULL)
			// 	{
			// 		temp.setLeft(Node<T>(val));
			// 	}
			// 	else
			// 	{
			// 		recursive_append(temp.getLeft(), val);
			// 	}
			// }
		}

	private:
		Node<T> root;
		size_t count;
};