//#include<iostream>
//using namespace std;
//
//template<typename type>
//class StackArray
//{
//private:
//	type* head;
//	int size;
//	int top;
//public:
//	StackArray(int s)
//	{
//		top = -1;
//		size = s;
//		head = new type[size];
//	}
//
//	~StackArray()
//	{
//		clear();
//	}
//
//	void clear()
//	{
//		top = -1;
//		delete head;
//		head = NULL;
//	}
//
//	bool isFull()
//	{
//		return top + 1 == size;
//	}
//
//	bool isEmpty()
//	{
//		return top == -1;
//	}
//
//	type get_top()
//	{
//		return isEmpty() ? NULL : head[top];
//	}
//
//	bool push(type value)
//	{
//		if (isFull())
//		{
//			cout << "The stack is full.\n";
//			return false;
//		}
//
//		top++;
//		head[top] = value;
//		return true;
//	}
//
//	bool pop(type& value)
//	{
//		if (isEmpty())
//		{
//			cout << "The stack is empty.\n";
//			return false;
//		}
//
//		value = head[top];
//		top--;
//		return true;
//	}
//};
//
//template<typename type>
//class Node
//{
//public:
//	type value;
//	Node<type>* next;
//
//	Node(type val, Node<type>* nxt = NULL)
//	{
//		value = val;
//		next = nxt;
//	}
//};
//
//template<typename type>
//class StackPointer
//{
//private:
//	Node<type>* top;
//
//public:
//	StackPointer()
//	{
//		top = NULL;
//	}
//
//	~StackPointer()
//	{
//		makeNull();
//	}
//
//	bool isEmpty()
//	{
//		return top == NULL;
//	}
//
//	void makeNull()
//	{
//		Node<type>* curr = top;
//
//		while (curr)
//		{
//			Node<type>* temp = curr;
//			curr = curr->next;
//			delete temp;
//		}
//
//		top = NULL;
//	}
//
//	void push(type value)
//	{
//		Node<type>* newNode = new Node<type>(value);
//		newNode->next = top;
//		top = newNode;
//	}
//
//	void pop(type& value)
//	{
//		if (isEmpty())
//		{
//			cout << "The stack is empty.\n";
//			return;
//		}
//		value = top->value;
//		Node<type>* nextNode = top->next;
//		delete top;
//		top = nextNode;
//	}
//};
//
////int main()
////{
////	//StackArray<int> stack(4);
////	StackPointer<int> stack;
////
////	int catchVar;
////
////	cout << "Pushing Integers\n";
////
////	stack.push(5);
////	stack.push(10);
////	stack.push(15);
////	stack.push(20);
////
////	cout << "Popping...\n";
////
////	stack.pop(catchVar);
////	cout << catchVar << endl;
////
////	stack.pop(catchVar);
////	cout << catchVar << endl;
////
////	stack.pop(catchVar);
////	cout << catchVar << endl;
////
////	stack.pop(catchVar);
////	cout << catchVar << endl;
////
////
////	return 0;
////}