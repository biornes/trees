#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
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

		Node(Node<T, E>* temp)
		{
			this->value_ = (temp->getValue());
			this->key_ = temp->getKey();
			this->height_ = (temp->getHeight());

			if (temp->getLeft())
			{
				this->left_ = new Node<T, E>((temp->getLeft()));
				this->left_->setParent(this);
			}
			if (temp->getRight())
			{
				this->right_ = new Node<T, E>((temp->getRight()));
				this->right_->setParent(this);
			}
		}

		Node<T, E>* getLeft() const
		{
			return left_;
		}

		Node<T, E>* getRight() const
		{
			return right_;
		}

		void setLeft(Node<T, E>* new_node)
		{
			this->left_ = new_node;
		}

		void setRight(Node<T, E>* new_node)
		{
			this->right_ = new_node;
		}

		void setValue(T temp)
		{
			this->value_ = temp;
		}

		const T& getValue() const
		{
			return value_;
		}

		Node<T, E>* getParent() const
		{
			return parent_;
		}

		void setParent(Node<T, E>* node)
		{
			this->parent_ = node;
		}

		const E& getKey() const
		{
			return key_;
		}

		void setKey(const E& key)
		{
			this->key_ = key;
		}

		void setHeight(int h)
		{
			this->height_ = h;
		}

		int getHeight() const
		{
			return this == 0 ? -1: this->height_;
		}

		Node<T, E> operator=(Node<T, E>* obj)
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

	Tree(const Tree<T, E>& cp)
	{
		root_ = new Node<T, E>(cp.getRoot());
		root_->setParent(nullptr);
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

	Node<T, E>* getRoot() const 
	{
		return root_;
	}

	void addElement(T value, E key)
	{
		if (!quantity_)
		{
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
		srand(time(0));
		for (int i = 0; i < 10000; ++i)
		{	
			(*this).addElement(0, rand());
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
			cout << temp->getLeft()->getValue() << " " << temp->getLeft()->getHeight() << " " << 
							temp->getLeft()->getKey() << endl;
			recPrint(temp->getLeft());
		}
		if (temp->getRight()){
			cout << temp->getRight()->getValue()<< " " << temp->getRight()->getHeight() << " " <<
							temp->getRight()->getKey() << endl;
			recPrint(temp->getRight());
		}
	}
	void setupParent(Node<T, E>* node, Node<T, E>* temp)
	{
		if (node->getParent()){
			if (node->getParent()->getLeft())
			{
				if (node->getParent()->getLeft()->getKey() == node->getKey())
				{
					node->getParent()->setLeft(temp);
				}
			}
			if (node->getParent()->getRight())
			{
				if (node->getParent()->getRight()->getKey() == node->getKey())
				{
					node->getParent()->setRight(temp);
				}
			}
			temp->setParent(node->getParent());
			node->setParent(temp);
		}
		else
		{
			root_ = temp;
			root_->setParent(0);
			node->setParent(temp);
		}
	}

	void recursive_add(Node<T, E>* node, T value, E key)
	{
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
					node = LR(node);
				}
				else
				{
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
					node = RR(node);
				}
				else
				{
					node = BRR(node);
				}

			}
		}
		node->setHeight(max(node->getLeft()->getHeight(), node->getRight()->getHeight()) + 1);

	}

	Node<T, E>* LR(Node<T, E>* node)
	{

		Node<T, E>* temp = node->getRight();
        node->setRight(temp->getLeft());
		temp->setLeft(node);
		setupParent(node, temp);
		node->setHeight(max(node->getLeft()->getHeight(), node->getRight()->getHeight())+1);
		temp->setHeight(max(node->getRight()->getHeight(), node->getHeight())+1);
		return temp;
	}


	Node<T, E>* RR(Node<T, E>* node)
	{
		Node<T, E>* temp = node->getLeft();
        node->setLeft(temp->getRight());
		temp->setRight(node);
		setupParent(node, temp);
		node->setHeight(max(node->getLeft()->getHeight(), node->getRight()->getHeight())+1);
		temp->setHeight(max(temp->getLeft()->getHeight(), node->getHeight())+1);
		return temp;
	}

	Node<T, E>* BLR(Node<T, E>* node)
	{
		node->setRight(RR(node->getRight()));
		return LR(node);
	}

	Node<T, E>* BRR(Node<T, E>* node)
	{
		node->setLeft(LR(node->getLeft()));
		return RR(node);
	}


};

