//#include<iostream>
//using namespace std;
//
//template<typename type>
//class QueueArray
//{
//private:
//	type* head;
//	int size;
//	int front;
//	int rear;
//public:
//	QueueArray(int s)
//	{
//		size = s;
//		head = new type[size];
//		front = rear = -1;
//	}
//
//	~QueueArray()
//	{
//		makeNull();
//	}
//
//	void makeNull()
//	{
//		delete head;
//		head = NULL;
//		size = 0;
//		front = rear = -1;
//	}
//
//	bool isEmpty()
//	{
//		return front == -1 or rear == -1;
//	}
//
//	bool isFull()
//	{
//		return ((rear + 1) % size) == front;
//	}
//
//	bool push_rear(type value)
//	{
//		if (isFull())
//		{
//			cout << "The queue is full.\n";
//			return false;
//		}
//
//		if (isEmpty())
//		{
//			front = 0;
//		}
//
//		rear = ((rear + 1) % size);
//		head[rear] = value;
//		
//		return true;
//	}
//
//	bool push_front(type value)
//	{
//		if (isFull())
//		{
//			cout << "The queue is full.\n";
//			return false;
//		}
//
//		if (isEmpty())
//		{
//			front = rear = 0;
//			head[front] = value;
//			return true;
//		}
//
//		front = ((front - 1 + size) % size);
//		head[front] = value;
//
//		return true;
//	}
//
//	bool pop_front(type& value)
//	{
//		if (isEmpty())
//		{
//			cout << "The queue is empty.\n";
//			return false;
//		}
//
//		if (front == rear)
//		{
//			value = head[front];
//			front = rear = -1;
//
//			return true;
//		}
//
//		value = head[front];
//		front = (front + 1) % size;
//		
//		return true;
//	}
//
//	bool pop_rear(type& value)
//	{
//		if (isEmpty())
//		{
//			cout << "The queue is empty.\n";
//			return false;
//		}
//
//		if (rear == front)
//		{
//			value = head[rear];
//			front = rear = -1;
//			return true;
//		}
//
//		value = head[rear];
//		rear = (rear - 1 + size) % size;
//		
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
//class QueuePointer
//{
//private:
//	Node<type>* front;
//	Node<type>* rear;
//public:
//	QueuePointer()
//	{
//		front = rear = NULL;
//	}
//
//	~QueuePointer()
//	{
//		makeNull();
//	}
//
//	void makeNull()
//	{
//		while (front)
//		{
//			Node<type>* temp = front;
//			front = front->next;
//			delete temp;
//		}
//
//		front = rear = NULL;
//	}
//
//	bool isEmpty()
//	{
//		return front == NULL or rear == NULL;
//	}
//
//	bool push_front(type value)
//	{
//		if (isEmpty())
//		{
//			front = rear = new Node<type>(value);
//			return true;
//		}
//
//		Node<type>* newNode = new Node<type>(value);
//		newNode->next = front;
//		front = newNode;
//
//		return true;
//	}
//
//	bool push_rear(type value)
//	{
//		if (isEmpty())
//		{
//			front = rear = new Node<type>(value);
//			return true;
//		}
//
//		rear->next = new Node<type>(value);
//		rear = rear->next;
//		
//		return true;
//	}
//
//	bool pop_front(type& value)
//	{
//		if (isEmpty())
//		{
//			cout << "The queue is empty.\n";
//			return false;
//		}
//
//		if (front == rear)
//		{
//			value = rear->value;
//			delete front;
//			front = rear = NULL;
//
//			return true;
//		}
//
//		value = front->value;
//		Node<type>* temp = front;
//		front = front->next;
//		delete temp;
//		temp = NULL;
//
//		return true;
//	}
//
//	bool pop_rear(type& value)
//	{
//		if (isEmpty())
//		{
//			cout << "The queue is empty.\n";
//			return false;
//		}
//
//		if (front == rear)
//		{
//			value = rear->value;
//			delete front;
//			front = rear = NULL;
//
//			return true;
//		}
//
//		value = rear->value;
//		
//		Node<type>* curr = front;
//		Node<type>* prev = NULL;
//		while (curr->next)
//		{
//			prev = curr;
//			curr = curr->next;
//		}
//
//		rear = prev;
//
//		if (rear)
//		{
//			delete rear->next;
//			rear->next = NULL;
//		}
//
//		return true;
//	}
//};
//
////int main()
////{
////	//QueueArray<int> iQueue(6);
////	QueuePointer<int> iQueue;
////	cout << "Enqueuing 5 items...\n";
////	// Enqueue 5 items.
////	for (int x = 0; x < 5; x++)
////		iQueue.push_front(x);
////
////	// Attempt to enqueue a 6th item.
////	cout << "Now attempting to enqueue again...\n";
////	iQueue.push_rear(5);
////	// Deqeue and retrieve all items in the queue
////	cout << "The values in the queue were:\n";
////	while (!iQueue.isEmpty()) {
////
////		int value;
////		iQueue.pop_rear(value);
////		cout << value << endl;
////
////	}
////	return 0;
////}