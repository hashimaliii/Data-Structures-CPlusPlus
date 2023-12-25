//#include<iostream>
//#include<Queue>
//using namespace std;
//
//template<typename type>
//class Node
//{
//public:
//	type value;
//	Node<type>* left;
//	Node<type>* right;
//
//	Node(type val, Node<type>* l = NULL, Node<type>* r = NULL)
//	{
//		value = val;
//		left = l;
//		right = r;
//	}
//};
//
//template<typename type>
//class Tree
//{
//private:
//	queue<Node<type>*> queueNode;
//	Node<type>* root;
//
//	void inOrdertraversal(Node<type>* node)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//
//		inOrdertraversal(node->left);
//		cout << node->value << " ";
//		inOrdertraversal(node->right);
//	}
//
//public:
//	Tree()
//	{
//		root = NULL;
//		makeNull();
//	}
//
//	~Tree()
//	{
//		makeNull();
//	}
//
//	void display()
//	{
//		inOrdertraversal(root);
//	}
//
//	void makeNull()
//	{
//		deleteTree(root);
//		
//		while (queueNode.size() > 0)
//		{
//			queueNode.pop();
//		}
//
//		root = NULL;
//	}
//
//	void deleteTree(Node<type>* node)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//
//		deleteTree(node->left);
//		deleteTree(node->right);
//	
//		delete node;
//		node = NULL;
//	}
//
//	void insert(type value)
//	{
//		Node<type>* newNode = new Node<type>(value);
//
//		if (queueNode.empty() or root == NULL)
//		{
//			queueNode.push(newNode);
//			root = newNode;
//			cout << "main" << " ";
//
//			return;
//		}
//
//		queueNode.push(newNode);
//		Node<type>* front = queueNode.front();
//
//		if (front->left == NULL)
//		{
//			front->left = newNode;
//			cout << "left ";
//			return;
//		}
//		
//		if (front->right == NULL)
//		{
//			front->right = newNode;
//			queueNode.pop();
//			cout << "right ";
//			return;
//		}
//	}
//};
//
//template<typename type>
//class BinaryTree
//{
//private:
//	Node<type>* root;
//
//	void deleteTree(Node<type>* node)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//
//		deleteTree(node->left);
//		deleteTree(node->right);
//
//		delete node;
//		node = NULL;
//	}
//
//	void inOrdertraversal(Node<type>* node)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//
//		inOrdertraversal(node->left);
//		cout << node->value << " ";
//		inOrdertraversal(node->right);
//	}
//
//	void search_node(Node<type>* node, type value)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//
//		if (value < node->value)
//		{
//			insert_node(node->left, value);
//		}
//		else if (value > node->value)
//		{
//			insert_node(node->right, value);
//		}
//		else
//		{
//			cout << "Node Exists: " << node->value << endl;
//			return;
//		}
//	}
//
//	void delete_node(Node<type>*& node, type value)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//
//		if (value < node->value)
//		{
//			delete_node(node->left, value);
//		}
//		else if (value > node->value)
//		{
//			delete_node(node->right, value);
//		}
//		else
//		{
//			cout << "\nNode Found: " << node->value << endl;
//			makeDeletion(node);
//			cout << "Deleted\n";
//			return;
//		}
//	}
//
//	void makeDeletion(Node<type>*& node)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//		else if (node->right == NULL)
//		{
//			Node<type>* left = node->left;
//			delete node;
//			node = left;
//			return;
//		}
//		else if (node->left == NULL)
//		{
//			Node<type>* right = node->right;
//			delete node;
//			node = right;
//			return;
//		}
//		else
//		{
//			minSucceder(node);
//		}
//	}
//
//	void minSucceder(Node<type>*& node)
//	{
//		Node<type>* curr = node->right;
//		Node<type>* prev = NULL;
//
//		if (curr)
//		{
//			if (curr->left == NULL)
//			{
//				curr->left = node->left;
//				delete node;
//				node = curr;
//
//				return;
//			}
//
//			while (curr->left)
//			{
//				prev = curr;
//				curr = curr->left;
//			}
//
//			if (prev)
//			{
//				Node<type>* right = curr->right;
//				prev->left = right;
//			}
//
//			curr->left = node->left;
//			curr->right = node->right;
//			delete node;
//			node = curr;
//		}
//	}
//
//	void insert_node(Node<type>*& node, type value)
//	{
//		if (node == NULL)
//		{
//			node = new Node<type>(value);
//			return;
//		}
//
//		if (value < node->value)
//		{
//			insert_node(node->left, value);
//		}
//		else if (value > node->value)
//		{
//			insert_node(node->right, value);
//		}
//	}
//
//public:
//	BinaryTree()
//	{
//		root = NULL;
//	}
//
//	~BinaryTree()
//	{
//		makeNull();
//	}
//
//	void makeNull()
//	{
//		deleteTree(root);
//		root = NULL;
//	}
//
//	void insert(type value)
//	{
//		insert_node(root, value);
//	}
//	
//	void find(type value)
//	{
//		search_node(root, value);
//	}
//
//	void del(type value)
//	{
//		delete_node(root, value);
//	}
//
//	void display()
//	{
//		cout << "\nBinary Tree: ";
//		inOrdertraversal(root);
//		cout << endl;
//	}
//};
//
//template<typename type>
//class AVLTree
//{
//private:
//	Node<type>* root;
//
//	void deleteTree(Node<type>* node)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//
//		deleteTree(node->left);
//		deleteTree(node->right);
//
//		delete node;
//		node = NULL;
//	}
//
//	void inOrdertraversal(Node<type>* node)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//
//		inOrdertraversal(node->left);
//		cout << node->value << " ";
//		inOrdertraversal(node->right);
//	}
//
//	void search_node(Node<type>* node, type value)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//
//		if (value < node->value)
//		{
//			insert_node(node->left, value);
//		}
//		else if (value > node->value)
//		{
//			insert_node(node->right, value);
//		}
//		else
//		{
//			cout << "Node Exists: " << node->value << endl;
//			return;
//		}
//	}
//
//	void SingleLeftRotation(Node<type>*& node)
//	{
//		Node<type>* k1 = node;
//		Node<type>* k2 = node->right;
//		k1->right = k2->left;
//		k2->left = k1;
//
//		node = k2;
//
//	}
//
//	void SingleRightRotation(Node<type>*& node)
//	{
//		Node<type>* k1 = node;
//		Node<type>* k2 = node->left;
//		k1->left = k2->right;
//		k2->right = k1;
//
//		node = k2;
//	}
//
//	void DoubleLeftRotation(Node<type>*& node)
//	{
//		SingleRightRotation(node->right);
//		SingleLeftRotation(node);
//	}
//
//	void DoubleRightRotation(Node<type>*& node)
//	{
//		SingleLeftRotation(node->left);
//		SingleRightRotation(node);
//	}
//
//	int height(Node<type>* node)
//	{
//		if (node == NULL)
//		{
//			return -1;
//		}
//
//		return max(height(node->left), height(node->right));
//	}
//
//	int balanceFactor(Node<type>* node)
//	{
//		if (node)
//		{
//			return height(node->left) - height(node->right);
//		}
//
//		return 0;
//	}
//
//	void insert_node(Node<type>*& node, type value)
//	{
//		if (node == NULL)
//		{
//			node = new Node<type>(value);
//			return;
//		}
//
//		if (value < node->value)
//		{
//			insert_node(node->left, value);
//
//			if (balanceFactor(node) == 2)
//			{
//				if (value < node->left->value)
//				{
//					// Single Right Rotation
//					SingleRightRotation(node);
//				}
//				else
//				{
//					// Double Right Rotation
//					DoubleRightRotation(node);
//				}
//			}
//		}
//		else if (value > node->value)
//		{
//			insert_node(node->right, value);
//
//			if (balanceFactor(node) == -2)
//			{
//				if (value > node->right->value)
//				{
//					// Single Left Rotation
//					SingleLeftRotation(node);
//				}
//				else
//				{
//					// Double Left Rotation
//					DoubleLeftRotation(node);
//				}
//			}
//		}
//	}
//
//	void delete_node(Node<type>*& node, type value)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//
//		if (value < node->value)
//		{
//			delete_node(node->left, value);
//		}
//		else if (value > node->value)
//		{
//			delete_node(node->right, value);
//		}
//		else
//		{
//			cout << "\nNode Found: " << node->value << endl;
//			makeDeletion(node);
//			cout << "Deleted\n";
//		}
//
//		if (balanceFactor(node) == 2)
//		{
//			if (balanceFactor(node->left) == 1)
//			{
//				SingleLeftRotation(node);
//			}
//			else
//			{
//				DoubleLeftRotation(node);
//			}
//		}
//		else if (balanceFactor(node) == -2)
//		{
//			if (balanceFactor(node->right) == -2)
//			{
//				SingleRightRotation(node);
//			}
//			else
//			{
//				DoubleRightRotation(node);
//			}
//		}
//	}
//
//	void minSucceder(Node<type>*& node)
//	{
//		Node<type>* curr = node->right;
//		Node<type>* prev = NULL;
//
//		if (curr)
//		{
//			if (curr->left == NULL)
//			{
//				curr->left = node->left;
//				delete node;
//				node = curr;
//
//				return;
//			}
//
//			while (curr->left)
//			{
//				prev = curr;
//				curr = curr->left;
//			}
//
//			if (prev)
//			{
//				Node<type>* right = curr->right;
//				prev->left = right;
//			}
//
//			curr->left = node->left;
//			curr->right = node->right;
//			delete node;
//			node = curr;
//		}
//	}
//
//	void makeDeletion(Node<type>*& node)
//	{
//		if (node == NULL)
//		{
//			return;
//		}
//		else if (node->right == NULL)
//		{
//			Node<type>* left = node->left;
//			delete node;
//			node = left;
//			return;
//		}
//		else if (node->left == NULL)
//		{
//			Node<type>* right = node->right;
//			delete node;
//			node = right;
//			return;
//		}
//		else
//		{
//			minSucceder(node);
//		}
//	}
//
//public:
//	AVLTree()
//	{
//		root = NULL;
//	}
//
//	~AVLTree()
//	{
//		makeNull();
//	}
//
//	void makeNull()
//	{
//		deleteTree(root);
//		root = NULL;
//	}
//
//	void insert(type value)
//	{
//		insert_node(root, value);
//	}
//
//	void find(type value)
//	{
//		search_node(root, value);
//	}
//
//	void del(type value)
//	{
//		delete_node(root, value);
//	}
//
//	void display()
//	{
//		cout << "\nBinary Tree: ";
//		inOrdertraversal(root);
//		cout << endl;
//	}
//};
//
//int main()
//{
//	//Tree<int> tree;
//	//
//	//tree.insert(4);
//	//tree.insert(2);
//	//tree.insert(5);
//	//tree.insert(1);
//	//tree.insert(3);
//	//tree.display();
//
//	//BinaryTree<int> binaryTree;
//
//	//binaryTree.insert(1);
//	//binaryTree.insert(2);
//	//binaryTree.insert(3);
//	//binaryTree.insert(4);
//	//binaryTree.insert(5);
//	//binaryTree.display();
//
//	//binaryTree.del(1);
//	//binaryTree.display();
//	//binaryTree.del(2);
//	//binaryTree.display();
//	//binaryTree.del(3);
//	//binaryTree.display();
//	//binaryTree.del(4);
//	//binaryTree.display();
//	//binaryTree.del(5);
//	//binaryTree.display();
//
//	AVLTree<int> avlTree;
//
//	avlTree.insert(1);
//	avlTree.insert(2);
//	avlTree.insert(3);
//	avlTree.insert(4);
//	avlTree.insert(5);
//	avlTree.display();
//
//	avlTree.del(1);
//	avlTree.display();
//	avlTree.del(2);
//	avlTree.display();
//	avlTree.del(3);
//	avlTree.display();
//	avlTree.del(4);
//	avlTree.display();
//	avlTree.del(5);
//	avlTree.display();
//
//	return 0;
//}