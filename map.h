#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
// #include <stdafx.h>
#include <ctime>
using namespace std;


template<typename T, typename E> class Node;
template<typename T, typename E> class Tree;


template <typename T, typename E>
class Node
{
	public:
		Node() : left_(0), right_(0), parent_(0), height_(0){}

		Node(T value, E key) : value_(value), left_(0), right_(0), parent_(0), height_(0), key_(key){}

		Node<T, E>* getLeft()
		{
			return left_;
		}

		Node<T, E>* getRight()
		{
			return right_;
		}

		void setLeft(Node<T, E>* new_node)
		{
			left_ = new_node;
		}

		void setRight(Node<T, E>* new_node)
		{
			right_ = new_node;
		}

		void setValue(T temp)
		{
			value_ = temp;
		}

		const T& getValue()
		{
			return value_;
		}

		Node<T, E>* getParent()
		{
			return parent_;
		}

		void setParent(Node<T, E>* node)
		{
			parent_ = node;
		}

		const E& getKey()
		{
			return key_;
		}

		void setKey(const E& key)
		{
			key_ = key;
		}

		void setHeight(int h)
		{
			this->height_ = h;
		}

		int getHeight()
		{
			return this == 0 ? -1: this->height_;
		}

		Node<T, E>* operator=(Node<T, E> obj)
		{
			this = obj;
			return *this;
		}



	private:
		int height_;
		T value_;
		E key_;
		Node<T, E> *left_ = nullptr;
		Node<T, E> *right_ = nullptr;
		Node<T, E> *parent_ = nullptr;
		
};

template <typename T, typename E>
class Tree
{
public:
	Tree()
	{
		root_ = new Node<T, E>;
	}

	Tree(T value,E key)
	{
		root_ = new Node<T, E>(value, key);
		++quantity_;
	}

	Tree(Tree<T, E>* cp)
	{
		root_ = new Node<T, E>;
		root_ = cp->getRoot();
	}

	~Tree()
	{
		clearAll();
	}

	Tree<T, E>* operator=(Tree<T, E>* tree)
	{
		this = tree;
		return *this;
	}

	T operator[](const E& key)
	{
			return find(key);
	}

	Node<T, E>& getRoot() const 
	{
		return *root_;
	}

	void addElement(T value, E key)
	{
		cout << key << endl;
		if (!quantity_)
		{
			cout << "ROOT: " <<  key << endl;
			root_->setKey(key);
			root_->setValue(value);
			root_->setHeight(max(root_->getLeft()->getHeight(), root_->getRight()->getHeight()) + 1);
		}
		else
		{
			recursive_add(root_, value, key);
		}
		++quantity_;

	}





	void printTree()
	{
		cout << root_->getValue() << " " << root_->getHeight() << " " << root_->getKey() << endl;
		recPrint(root_);
	}



	T find(const E& key)
	{
		return recFind(root_, key);
	}


	bool empty()
	{
		return quantity_ ? false : true;
	}

	void clearAll()
	{
		recClear(root_);
		quantity_ = 0;
		delete root_;
	}
	void test()
	{
		// Tree<int, int> temp;
		srand(time(0));
		for (int i = 0; i < 10; ++i)
		{	
			// cout << "ERROR here" << endl;
			(*this).addElement(0, rand());
			// this->printTree();
			// cout << i << endl;
		}
		cout << "Height: " << root_->getHeight() << endl;
		cout << (*this).empty() << endl;
		cout << (*this).quantity_ << endl;
	}


	const int& max(const int& a, const int& b)
	{
	    return (a < b) ? b : a;
	}

private:
	Node<T, E> *root_;
	uint32_t quantity_ = 0;
	void recClear(Node<T, E>* node)
	{
		if (node->getLeft())
		{
			recClear(node->getLeft());
			delete node;
		}
		if (node->getRight())
		{
			recClear(node->getRight());
			delete node;
		}
	}
	T recFind(Node<T, E>* node, const E& key)
	{
		if (!node->getLeft() and !node->getRight())
		{
			cout << "No such element" << endl;
			return 0;
		}
		else if (node->getKey() == key)
			return node->getValue();
		else
		{
			if (key > node->getKey())
				return recFind(node->getRight(), key);
			else
				return recFind(node->getLeft(), key);
		}
	}
	void recPrint(Node<T, E>* temp)
	{
		if (temp->getLeft()){
			// cout << "left: " << endl;
			cout << temp->getLeft()->getValue() << " " << temp->getLeft()->getHeight() << " " << 
							temp->getLeft()->getKey() << endl;
			recPrint(temp->getLeft());
		}
		if (temp->getRight()){
			// cout << "right: " << endl;
			cout << temp->getRight()->getValue()<< " " << temp->getRight()->getHeight() << " " <<
							temp->getRight()->getKey() << endl;
			recPrint(temp->getRight());
		}
	}
	void setupParent(Node<T, E>* node, Node<T, E>* temp)
	{

		// cout << "HERE" << endl;
		if (node->getParent()->getLeft())
		{
			if (node->getParent()->getLeft()->getKey() == node->getKey()){
			// cout << "HERE" << endl;
			node->getParent()->setLeft(temp);
		}
		else if (node->getParent()->getRight())
		{
			if (node->getParent()->getLeft()->getKey() == node->getKey()){
			// cout << "HERE" << endl;
			node->getParent()->setLeft(temp);
		}
		}
		}
		// if (node->getParent()->getLeft()->getKey() == node->getKey()){
		// 	cout << "HERE" << endl;
		// 	node->getParent()->setLeft(temp);
		// }
		// // cout << "2 step " << endl;
		// else if (node->getParent()->getRight()->getKey() == node->getKey()){
		// 	cout << "HERE" << endl;
		// 	node->getParent()->setRight(temp);
		// }
		// cout << "HERE" << endl;
		temp->setParent(node->getParent());
		node->setParent(temp);
	}
	void recursive_add(Node<T, E>* node, T value, E key)
	{
		// cout << value << endl;
		if (node->getKey() < key)
		{
			if (node->getRight() == 0)
			{
				node->setRight(new Node<T, E>(value, key));
				node->getRight()->setParent(node);
			}
			else
			{
				recursive_add(node->getRight(), value, key);
				
			}
			if (node->getRight()->getHeight() - node->getLeft()->getHeight() == 2)
			{
				if (key > node->getRight()->getKey())
				{
					// if (node->getKey() == 3)
					// 	cout << "ERROR ZONE: " << node->getKey() << endl;
					// cout << "CASE 1" << endl;
					node = LR(node);
					// cout << node->getValue() << endl;
					// cout << 

				}
				else
				{
					// cout << "CASE 2" << endl;
					// printTree();
					node = BLR(node);

				}
			}

		}
		else if (node->getKey() > key)
		{
			if (node->getLeft() == 0)
			{
				node->setLeft(new Node<T, E>(value, key));
				node->getLeft()->setParent(node);
			}
			else
			{
				 recursive_add(node->getLeft(),value, key);
			}
			if (node->getLeft()->getHeight() - node->getRight()->getHeight() == 2)
			{

				if (key < node->getLeft()->getKey())
				{
					// cout << "CASE 3" << endl;
					// Node<T, E>* t_node = RR(node);
					node = RR(node);
					// node-
				}
				else
				{
					
					node = BRR(node);
					// cout << "CASE 4" << endl;
				}

			}
		}
		// cout << "CASE 5" << endl;
		node->setHeight(max(node->getLeft()->getHeight(), node->getRight()->getHeight()) + 1);

	}

	Node<T, E>* LR(Node<T, E>* node)
	{

		Node<T, E>* temp = node->getRight();
		// cout << temp->getLeft()->getValue();
        node->setRight(temp->getLeft());
        
		temp->setLeft(node);
		node->setParent(temp);
		setupParent(node, temp);
		// cout << "case 5" << endl;
		node->setHeight(max(node->getLeft()->getHeight(), node->getRight()->getHeight())+1);
		temp->setHeight(max(node->getRight()->getHeight(), node->getHeight())+1);
		return temp;
	}


	Node<T, E>* RR(Node<T, E>* node)
	{
		Node<T, E>* temp = node->getLeft();
		// cout << node->getLeft() << endl;
		// if (temp->getLeft() == nullptr )
			// cout << temp->getLeft() << endl;
		
		

        node->setLeft(temp->getRight());

		temp->setRight(node);
		// cout << "RR" << endl;
		// cout << "RR" << endl;
		// printTree();
		node->setParent(temp);
		// cout << "RR" << endl;
		setupParent(node, temp);
		
		node->setHeight(max(node->getLeft()->getHeight(), node->getRight()->getHeight())+1);

		temp->setHeight(max(temp->getLeft()->getHeight(), node->getHeight())+1);
		return temp;
	}

	Node<T, E>* BLR(Node<T, E>* node)
	{
		node->setRight(RR(node->getRight()));
		// cout << "case 6" << endl;
		return LR(node);
	}

	Node<T, E>* BRR(Node<T, E>* node)
	{
		// cout << "CASE 4" << endl;
		// cout << node->getLeft()->getValue() << endl;
		node->setLeft(LR(node->getLeft()));

		return RR(node);
	}


};

