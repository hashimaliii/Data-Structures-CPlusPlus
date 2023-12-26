#include<iostream>
using namespace std;

template<typename type>
class Heap
{
private:
	type* head;
	int size;
	int numItems;
public:
	Heap(int s)
	{
		numItems = 0;
		size = s;
		head = new type[size];
	}

	~Heap()
	{
		numItems = 0;
		size = 0;
		delete head;
		head = NULL;
	}

	void perculateUP(type* node, int currIndex)
	{
		if (currIndex / 2 >= 0 && currIndex < size)
		{
			int parent = currIndex / 2;
			int child = currIndex;

			if (node[parent] > node[child])
			{
				type temp = node[parent];
				node[parent] = node[child];
				node[child] = node[parent];
			}
			else
			{
				return;
			}

			perculateUP(node, parent);
		}
	}

	void perculateDOWN(type* node, int currIndex)
	{
		if (currIndex >= 0 && ((currIndex * 2) + 1) < size)
		{
			int parent = currIndex;
			int child1 = currIndex * 2;
			int child2 = child1 + 1;

			int largest = parent;

			if (node[largest] < node[child1])
			{
				largest = child1;
			}
			if (node[largest] < node[child2])
			{
				largest = child2;
			}

			if (largest != parent)
			{
				type temp = node[parent];
				node[parent] = node[largest];
				node[largest] = node[parent];
			}
			else
			{
				return;
			}

			perculateDOWN(node, largest);
		}
		else
		{
			return;
		}
	}

	type top()
	{
		if (isEmpty())
		{
			return NULL;
		}

		return node[numItems - 1];
	}

	bool isFull()
	{
		return numItems == size;
	}

	bool isEmpty()
	{
		return numItems <= 0;
	}

	void insert_node(type value)
	{
		if (isFull())
		{
			cout << "Heap is full.\n";
			return;
		}

		node[numItems] = value;
		perculateUP(node, numItems);
		numItems++;
	}

	void delete_node(type& value)
	{
		if (isEmpty())
		{
			cout << "Heap is empty.\n";
			return;
		}

		value = node[0];

		type temp = node[0];
		node[0] = node[numItems - 1];
		node[numItems - 1] = temp;
		perculateDOWN(node, 0);
		numItems--;
	}

	void heapify(type* graph, int graphSize)
	{
		if (isFull())
		{
			cout << "Heap is full.\n";
			return;
		}

		if (isEmpty() == false)
		{
			for (int i = 0; i < graphSize; i++)
			{
				insert_node(graph[i]);
			}
			return;
		}

		for (int i = graphSize / 2; i >= 0; i--)
		{
			perculateDOWN(graph, i);
		}

		node = graph;
		return;
	}
};

int main()
{

	return 0;
}