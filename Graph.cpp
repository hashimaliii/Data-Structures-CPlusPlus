#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template<typename type>
class Node
{
public:
	type value;
	Node<type>* next;

	Node(type val=0, Node<type>* n = NULL)
	{
		value = val;
		next = n;
	}
};

template<typename type>
class GraphMatrix
{
private:
	Node<type>** root;
	int size;
public:
	GraphMatrix(int s)
	{
		size = s;
		root = new Node<type> *[size];

		for (int i = 0; i < size; i++)
		{
			root[i] = new Node<type>[size];
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				root[i][j] = NULL;
			}
		}
	}

	~GraphMatrix()
	{
		makeNull();
	}

	void makeNull()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] root[i];
		}

		delete[] root;
		root = NULL;
		size = 0;
	}

	void add_edge(int nodeOne, int nodeTwo, type value)
	{
		if (nodeOne >= 0 && nodeOne < size && nodeTwo >= 0 && nodeTwo < size)
		{
			root[nodeOne][nodeTwo].value = value;
			root[nodeTwo][nodeOne].value = value;
		}
		else
		{
			cout << "Entered invalid node.\n";
		}
	}

	void remove_edge(int nodeOne, int nodeTwo, type value)
	{
		if (nodeOne >= 0 && nodeOne < size && nodeTwo >= 0 && nodeTwo < size)
		{
			root[nodeOne][nodeTwo].value = 0;
		}
		else
		{
			cout << "Entered invalid node.\n";
		}
	}

	void display()
	{
		cout << "\nGraph: \n";
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << root[i][j].value << "\t";
			}
			cout << endl;
		}
	}

	bool notInQue(queue<int> que, int vertex)
	{
		while (que.empty() == false)
		{
			if (vertex == que.front())
			{
				return false;
			}
			que.pop();
		}

		return true;
	}

	void bfs(int start = 0)
	{
		cout << "\nBFS: ";
		if (start >= 0 && start < size)
		{
			char* vertex = new char[size];

			for (int i = 0; i < size; i++)
			{
				vertex[i] = 'W';
			}

			queue<int> que;
			que.push(start);
			vertex[start] = 'G';

			while (que.empty() == false)
			{
				int top = que.front();
				cout << top << " ";

				vertex[top] = 'B';
				que.pop();

				for (int i = 0; i < size; i++)
				{
					if (root[top][i].value != 0 && vertex[i] == 'W')
					{
						vertex[i] = 'G';
						que.push(i);
					}
				}

			}

			cout << "\nNot Visited Vertex: ";
			for (int i = 0; i < size; i++)
			{
				if (vertex[i] != 'B')
				{
					cout << i << " ";
				}
			}
			cout << endl;

			delete[] vertex;
			vertex = NULL;
		}
		else
		{
			cout << "Invalid start of bfs.\n";
		}
	}

	bool notInStack(stack<int> stk, int vertex)
	{
		while (stk.empty() == false)
		{
			if (stk.top() == vertex)
			{
				return false;
			}
			stk.pop();
		}
		return true;
	}

	void dfs(int start = 0)
	{
		cout << "\nDFS: ";
		if (start >= 0 && start < size)
		{
			char* vertex = new char[size];

			for (int i = 0; i < size; i++)
			{
				vertex[i] = 'W';
			}

			stack<int> stk;
			stk.push(start);
			vertex[start] = 'G';

			while (stk.empty() == false)
			{
				int top = stk.top();
				cout << top << " ";
				vertex[top] = 'B';
				stk.pop();

				for (int i = 0; i < size; i++)
				{
					if (root[top][i].value != 0 && vertex[i] == 'W')
					{
						vertex[i] = 'G';
						stk.push(i);
					}
				}

			}

			cout << "\nNot Visited Vertex: ";
			for (int i = 0; i < size; i++)
			{
				if (vertex[i] != 'B')
				{
					cout << i << " ";
				}
			}
			cout << endl;

			delete[] vertex;
			vertex = NULL;
		}
		else
		{
			cout << "Invalid start of dfs.\n";
		}
	}

	bool existVectors(bool* vector)
	{
		for (int i = 0; i < size; i++)
		{
			if (vector[i] == true)
			{
				return true;
			}
		}

		return false;
	}

	int Min(int* key, bool* existVector)
	{
		int index = 0;
		int min = key[index];
		for (int i = 0; i < size; i++)
		{
			if (min > key[i] && existVector[i])
			{
				min = key[i];
				index = i;
			}
		}
		return index;
	}

	void prims(int start = 0)
	{
		if (start >= 0 && start < size)
		{
			queue<int> que;
			int* parent = new int[size];
			int* key = new int[size];
			bool* existVector = new bool[size];
			int v = start;

			for (int i = 0; i < size; i++)
			{
				parent[i] = -1;
				key[i] = INT_MAX;
				existVector[i] = true;
			}

			while (existVectors(existVector))
			{
				v = Min(key, existVector);
				existVector[v] = false;
				for (int i = 0; i < size; i++)
				{
					if (root[v][i].value < key[i] && root[v][i].value != 0 && existVector[i] == true)
					{
						key[i] = root[v][i].value;
						parent[i] = v;
					}
				}

				que.push(v);
			}
			key[start] = 0;
			cout << "\nPrims: ";
			int mstCost = 0;
			while (que.empty() == false)
			{
				int vert = que.front();
				cout << vert << " ";
				que.pop();
				mstCost += vert;
			}
			cout << endl;
			cout << "MST: " << mstCost << endl;

			delete[] parent;
			delete[] key;
			delete[] existVector;

			parent = NULL;
			key = NULL;
			existVector = NULL;
		}
		else
		{
			cout << "Invalid start of dfs.\n";
		}
	}

	void dijkstra(int start = 0)
	{
		if (start >= 0 && start < size)
		{
			queue<int> que;
			int* parent = new int[size];
			int* key = new int[size];
			bool* existVector = new bool[size];
			int v = start;

			for (int i = 0; i < size; i++)
			{
				parent[i] = -1;
				key[i] = INT_MAX;
				existVector[i] = true;
			}

			while (existVectors(existVector))
			{
				v = Min(key, existVector);
				existVector[v] = false;
				for (int i = 0; i < size; i++)
				{
					if (root[v][i].value + key[v] < key[i] && root[v][i].value != 0 && existVector[i] == true)
					{
						key[i] = root[v][i].value + key[v];
						parent[i] = v;
					}
				}

				que.push(v);
			}
			key[start] = 0;
			cout << "\nDijkstra: ";
			int mstCost = 0;
			while (que.empty() == false)
			{
				int vert = que.front();
				cout << vert << " ";
				que.pop();
				mstCost += vert;
			}
			cout << endl;
			cout << "MST: " << mstCost << endl;

			delete[] parent;
			delete[] key;
			delete[] existVector;

			parent = NULL;
			key = NULL;
			existVector = NULL;
		}
		else
		{
			cout << "Invalid start of dfs.\n";
		}
	}
};

template<typename type>
class GraphList
{
private:
	Node<type>** root;
	int size;
public:
	GraphList(int s = 0)
	{
		size = s;
		if (size > 0)
		{
			root = new Node<type>*[size];
		}
	}

	void add_vertex()
	{
		Node<type>* newRoot = new Node<type>[size + 1];

		for (int i = 0; i < size; i++)
		{
			newRoot[i] = root[i];
		}

		size++;

		delete root;
		root = newRoot;
	}

	void add_edge(int nodeOne, int nodeTwo)
	{
		if (nodeOne >= 0 && nodeOne < size && nodeTwo >= 0 && nodeTwo < size)
		{
			Node<type>* curr = root[nodeOne];

			while (curr->next)
			{
				if (curr->value == nodeTwo)
				{
					return;
				}
				curr = curr->next;
			}

			curr->next = new Node<type>(nodeTwo);
		}
		else
		{
			cout << "Entered invalid node.\n";
		}
	}

	void display()
	{
		cout << "\nGraph: \n";
		for (int i = 0; i < size; i++)
		{
			Node<type>*curr = root[i];
			while (curr)
			{
				cout << curr->value << "\t";
				curr = curr->next;
			}
			cout << endl;
		}
	}
};

int main()
{
	//GraphMatrix<int> graphMatrix(5);
	//graphMatrix.add_edge(1, 3, 1);
	//graphMatrix.add_edge(2, 3, 2);
	//graphMatrix.add_edge(0, 1, 3);
	//graphMatrix.add_edge(0, 2, 4);
	//graphMatrix.add_edge(3, 4, 4);
	//graphMatrix.display();
	//graphMatrix.bfs();
	//graphMatrix.dfs();
	//graphMatrix.prims(2);
	//graphMatrix.dijkstra(2);

	GraphList<int> graphList(5);
	graphList.add_edge(1, 3);
	graphList.add_edge(2, 3);
	graphList.add_edge(0, 1);
	graphList.add_edge(0, 2);
	graphList.add_edge(3, 4);
	graphList.display();
	//graphList.bfs();
	//graphList.dfs();
	//graphList.prims(2);
	//graphList.dijkstra(2);

	return 0;
}