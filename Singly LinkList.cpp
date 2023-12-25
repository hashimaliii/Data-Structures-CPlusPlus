//#include<iostream>
//#include<list>
//
//using namespace std;
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
//int m()
//{
//	return NULL;
//}
//
//template<typename type>
//class List
//{
//private:
//	Node<type>* head;
//	int numItems;
//public:
//	List()
//	{
//		head = NULL;
//		numItems = 0;
//	}
//
//	~List()
//	{
//		clear();
//	}
//
//	void insert(int index, type value)
//	{
//		if (index-1 > numItems or index < 1)
//		{
//			cout << "\n[Error::Invalid Index]\n";
//			return;
//		}
//
//		if (index == 1)
//		{
//			push_front(value);
//			return;
//		}
//
//		if ((index - 1) == numItems)
//		{
//			push_back(value);
//			return;
//		}
//
//		Node<type>* curr = head;
//		Node<type>* prev = NULL;
//
//		for (int i = 1; curr != NULL; i++)
//		{
//			if (index == i)
//			{
//				numItems++;
//				Node<type>* mid = new Node<type>(value);
//				prev->next = mid;
//				mid->next = curr;
//
//				return;
//			}
//
//			prev = curr;
//			curr = curr->next;
//		}
//	}
//
//	void delete_value(int index)
//	{
//		if (index - 1 > numItems or index < 1)
//		{
//			cout << "\n[Error::Invalid Index]\n";
//			return;
//		}
//
//		if (index == 1)
//		{
//			pop_front();
//			return;
//		}
//
//		if ((index - 1) == numItems)
//		{
//			pop_back();
//			return;
//		}
//
//		Node<type>* curr = head;
//		Node<type>* prev = NULL;
//
//		for (int i = 1; curr != NULL; i++)
//		{
//			if (index == i)
//			{
//				numItems--;
//				Node<type>* temp = curr;
//				curr = curr->next;
//				prev->next = curr;
//				delete temp;
//				temp = NULL;
//
//				return;
//			}
//
//			prev = curr;
//			curr = curr->next;
//		}
//	}
//
//	void remove(type value)
//	{
//		if (front() == value)
//		{
//			pop_front();
//			return;
//		}
//
//		if (back() == value)
//		{
//			pop_back();
//			return;
//		}
//
//		Node<type>* curr = head;
//		Node<type>* prev = NULL;
//
//		for (int i = 1; curr != NULL; i++)
//		{
//			if (value == curr->value)
//			{
//				numItems--;
//				Node<type>* temp = curr;
//				curr = curr->next;
//				prev->next = curr;
//				delete temp;
//				temp = NULL;
//
//				return;
//			}
//
//			prev = curr;
//			curr = curr->next;
//		}
//	}
//
//	void clear()
//	{
//		numItems = 0;
//		Node<type>* curr = head;
//		while (curr)
//		{
//			Node<type>* temp = curr;
//			curr = curr->next;
//			delete temp;
//		}
//
//		head = NULL;
//	}
//
//	void push_back(type value)
//	{
//		if (isEmpty())
//		{
//			numItems++;
//			head = new Node<type>(value);
//			return;
//		}
//
//		Node<type>* curr = head;
//		while (curr->next)
//		{
//			curr = curr->next;
//		}
//		numItems++;
//		curr->next = new Node<type>(value);
//
//		return;
//	}
//
//	void push_front(type value)
//	{
//		numItems++;
//		Node<type>* curr = head;
//		head = new Node<type>(value);
//		head->next = curr;
//	}
//
//	type front()
//	{
//		return head == NULL ? NULL : head->value;
//	}
//
//	type back()
//	{
//		if (isEmpty())
//		{
//			return NULL;
//		}
//
//		Node<type>* curr = head;
//
//		while (curr->next)
//		{
//			curr = curr->next;
//		}
//
//		return curr->value;
//	}
//
//	void pop_back()
//	{
//		if (isEmpty())
//		{
//			return;
//		}
//
//		Node<type>* curr = head;
//		Node<type>* prev = NULL;
//
//		if (head->next == NULL)
//		{
//			numItems--;
//			delete head;
//			head = NULL;
//			return;
//		}
//
//		while (curr->next)
//		{
//			prev = curr;
//			curr = curr->next;
//		}
//
//		numItems--;
//		delete curr;
//		curr = NULL;
//		prev->next = NULL;
//	}
//
//	void pop_front()
//	{
//		if (head == NULL)
//		{
//			return;
//		}
//
//		numItems--;
//		Node<type>* curr = head;
//		head = head->next;
//		delete curr;
//		curr = NULL;
//	}
//
//	bool isEmpty()
//	{
//		return head == NULL;
//	}
//
//	void show_list()
//	{
//		Node<type>* curr = head;
//
//		cout << "Data: ";
//		while (curr)
//		{
//			cout << curr->value << " ";
//			curr = curr->next;
//		}
//		cout << endl;
//	}
//};
//
//int main()
//{
//	List<int> list;
//
//	list.insert(1, 1);
//	list.insert(2, 2);
//	list.insert(3, 3);
//	list.insert(4, 4);
//	list.show_list();
//
//	list.insert(5, 5);
//	list.show_list();
//
//	//list.push_front(1);
//	//list.show_list();
//
//	//list.pop_front();
//	//list.show_list();
//	//list.pop_front();
//	//list.show_list();
//	//list.pop_front();
//	//list.show_list();
//	//list.pop_front();
//	//list.show_list();
//
//	//list.delete_value(1);
//	//list.show_list();
//	//list.delete_value(2);
//	//list.show_list();
//	//list.delete_value(3);
//	//list.show_list();
//	//list.delete_value(1);
//	//list.show_list();
//	//list.delete_value(1);
//	//list.show_list();
//
//	list.remove(1);
//	list.show_list();
//	list.remove(2);
//	list.show_list();
//	list.remove(3);
//	list.show_list();
//	list.remove(4);
//	list.show_list();
//	list.remove(5);
//	list.show_list();
//
//	return 0;
//}