//#include<iostream>
//#include<vector>
//#include<list>
//using namespace std;
//
//template<typename type>
//class ClosedHashing
//{
//private:
//	type* hashArray;
//	int size;
//	int numItems;
//	double rehashPercentage;
//
//	double hash(int key)
//	{
//		return key % size;
//	}
//
//	void calculatePercentage(int typeHash = 1)
//	{
//		if (((numItems / size) * 100) >= rehashPercentage)
//		{
//			rehash(typeHash);
//		}
//	}
//
//	void rehash(int typeHash = 1)
//	{
//		type* newArray = new int[size * 2];
//		type* oldArray = hashArray;
//		hashArray = newArray;
//
//		for (int i = 0; i < size; i++)
//		{
//			if (oldArray[i] != 0)
//			{
//				if (typeHash == 1)
//				{
//					linearProbing(oldArray[i]);
//				}
//				else if (typeHash == 2)
//				{
//					quadraticProbing(oldArray[i]);
//				}
//				else
//				{
//					doubleProbing(oldArray[i]);
//				}
//			}
//		}
//
//		delete[] oldArray;
//		oldArray = NULL;
//		newArray = NULL;
//	}
//
//	void linearProbing(int key)
//	{
//		int hashValue = hash(key);
//		if (hashArray[hashValue] == 0)
//		{
//			hashArray[hashValue] = key;
//			numItems++;
//			return;
//		}
//		else
//		{
//			cout << "Collision at " << hashValue << endl;
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			int linearHash = ((hashValue + 1) % size);
//
//			if (hashArray[linearHash] == 0)
//			{
//				hashArray[linearHash] = key;
//				numItems++;
//				return;
//			}
//			else
//			{
//				cout << "Collision at " << linearHash << endl;
//			}
//		}
//		cout << "Value not inserted.\n";
//	}
//
//	void quadraticProbing(int key)
//	{
//		int hashValue = hash(key);
//		if (hashArray[hashValue] == 0)
//		{
//			hashArray[hashValue] = key;
//			numItems++;
//			return;
//		}
//		else
//		{
//			cout << "Collision at " << hashValue << endl;
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			int quadraticPlus = (hashValue + (i * i)) % size;
//
//			if (hashArray[quadraticPlus] == 0)
//			{
//				numItems++;
//				hashArray[quadraticPlus] = key;
//				return;
//			}
//			else
//			{
//				cout << "Collision at " << quadraticPlus << endl;
//			}
//
//			int quadraticMinus = (hashValue - (i * i)) % size;
//
//			// Normalizing
//			if (quadraticMinus < 0)
//			{
//				quadraticMinus = (quadraticMinus + size) % size;
//				cout << "Normalize: " << quadraticMinus << endl;
//			}
//
//			if (hashArray[quadraticMinus] == 0)
//			{
//				numItems++;
//				hashArray[quadraticMinus] = key;
//				return;
//			}
//			else
//			{
//				cout << "Collision at " << quadraticMinus << endl;
//			}
//		}
//
//		cout << "Value not inserted.\n";
//	}
//
//	void doubleProbing(int key, int prime = 1)
//	{
//		int hashValue = hash(key);
//		if (hashArray[hashValue] == 0)
//		{
//			hashArray[hashValue] = key;
//			numItems++;
//			return;
//		}
//		else
//		{
//			cout << "Collision at " << hashValue << endl;
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			int hash1 = hashValue;
//			int hash2 = prime - (key % prime);
//			int doubleHash = (hash1 + (i * hash2)) % size;
//
//			if (hashArray[doubleHash] == 0)
//			{
//				hashArray[doubleHash] = key;
//				numItems++;
//				return;
//			}
//			else
//			{
//				cout << "Collision at " << doubleHash << endl;
//			}
//		}
//		cout << "Value not inserted.\n";
//	}
//
//	void searchLinear(int key, bool& found, int hashKey = 0)
//	{
//		int hashValue = hash(key);
//		if (hashArray[hashValue] == key)
//		{
//			cout << key << " Found at " << hashValue << endl;
//			hashKey = hashValue;
//			found = true;
//			return;
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			int linearHash = ((hashValue + 1) % size);
//
//			if (hashArray[linearHash] == key)
//			{
//				cout << key << " Found at " << hashValue << endl;
//				hashKey = hashValue;
//				found = true;
//				return;
//			}
//		}
//		cout << "Value not found.\n";
//		found = false;
//	}
//
//	void searchQuadratic(int key, bool& found, int hashKey = 0)
//	{
//		int hashValue = hash(key);
//		if (hashArray[hashValue] == key)
//		{
//			cout << key << " Found at " << hashValue << endl;
//			hashKey = hashValue;
//			found = true;
//			return;
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			int quadraticPlus = (hashValue + (i * i)) % size;
//
//			if (hashArray[quadraticPlus] == key)
//			{
//				cout << key << " Found at " << hashValue << endl;
//				hashKey = hashValue;
//				found = true;
//				return;
//			}
//
//			int quadraticMinus = (hashValue - (i * i)) % size;
//
//			// Normalizing
//			if (quadraticMinus < 0)
//			{
//				quadraticMinus = (quadraticMinus + size) % size;
//			}
//
//			if (hashArray[quadraticMinus] == key)
//			{
//				cout << key << " Found at " << hashValue << endl;
//				hashKey = hashValue;
//				found = true;
//				return;
//			}
//		}
//
//		found = false;
//		cout << "Value not found.\n";
//	}
//
//	void searchDouble(int key, bool& found, int hashKey = 0, int prime = 1)
//	{
//		int hashValue = hash(key);
//		if (hashArray[hashValue] == key)
//		{
//			cout << key << " Found at " << hashValue << endl;
//			hashKey = hashValue;
//			found = true;
//			return;
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			int hash1 = hashValue;
//			int hash2 = prime - (key % prime);
//			int doubleHash = (hash1 + (i * hash2)) % size;
//
//			if (hashArray[doubleHash] == key)
//			{
//				cout << key << " Found at " << hashValue << endl;
//				hashKey = hashValue;
//				found = true;
//				return;
//			}
//		}
//
//		found = false;
//		cout << "Value not found.\n";
//	}
//
//public:
//	ClosedHashing(int s, double percentage = 70)
//	{
//		rehashPercentage = percentage;
//		size = s;
//		hashArray = new type[size];
//	
//		for (int i = 0; i < size; i++)
//		{
//			hashArray[i] = 0;
//		}
//	}
//
//	~ClosedHashing()
//	{
//		delete[] hashArray;
//		size = 0;
//		numItems = 0;
//	}
//
//	void clearArray()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			hashArray[i] = 0;
//		}
//	}
//
//	void insert(int key, int typeHash = 1)
//	{
//		if (typeHash == 1)
//		{
//			linearProbing(key);
//		}
//		else if (typeHash == 2)
//		{
//			quadraticProbing(key);
//		}
//		else
//		{
//			doubleProbing(key);
//		}
//	}
//
//	void deletion(int key, int typeHash = 1)
//	{
//		bool found = false;
//		int hashKey = 0;
//		if (typeHash == 1)
//		{
//			searchLinear(key, found, hashKey);
//		}
//		else if (typeHash == 2)
//		{
//			searchQuadratic(key, found, hashKey);
//		}
//		else
//		{
//			searchDouble(key, found, hashKey);
//		}
//
//		if (found)
//		{
//			hashArray[hashKey] = 0;
//			cout << key << " Deleted.\n";
//		}
//	}
//
//	void search(int key, int typeHash = 1)
//	{
//		bool found = false;
//		int hashKey = 0;
//		if (typeHash == 1)
//		{
//			searchLinear(key, found, hashKey);
//		}
//		else if (typeHash == 2)
//		{
//			searchQuadratic(key, found, hashKey);
//		}
//		else
//		{
//			searchDouble(key, found, hashKey);
//		}
//	}
//};
//
//// Open Hashing
//
//template<typename type>
//class Chaining
//{
//private:
//	double hash(int key)
//	{
//		return key % head.size();
//	}
//
//	vector<list<type>> head;
//public:
//
//	Chaining(int size)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			list<type> temp;
//			head.push_back(temp);
//		}
//	}
//
//	~Chaining()
//	{
//		makeNull();
//	}
//
//	void makeNull()
//	{
//		for (int i = 0; i < head.size(); i++)
//		{
//			list<type> temp = head[i];
//			temp.clear();
//		}
//	}
//
//	void insert(int key)
//	{
//		int hashValue = hash(key);
//		list<type> temp = head[hashValue];
//		temp.push_back(key);
//		head[hashValue] = temp;
//	}
//
//	void deletion(int key)
//	{
//		int hashValue = hash(key);
//		list<type> temp = head[hashValue];
//		temp.remove(key);
//		head[hashValue] = temp;
//	}
//
//	void search(int key, bool& found, int hashKey = 0)
//	{
//		int hashValue = hash(key);
//		list<type> temp = head[hashValue];
//		
//		for (auto it = temp.begin(); it != temp.end(); it++)
//		{
//			type element = *it;
//
//			if (key == element)
//			{
//				found = true;
//				hashValue = hashKey;
//				return;
//			}
//		}
//	}
//};
//
//template<typename type>
//class BucketProbing
//{
//private:
//	vector<vector<type>> head;
//	double rehashPercentage;
//	int numItems;
//
//	double hash(int key)
//	{
//		return key % head.size();
//	}
//
//	void calculatePercentage()
//	{
//		if (((numItems / (head.size() + head[0].size())) * 100) >= rehashPercentage)
//		{
//			rehash();
//		}
//	}
//
//	void rehash()
//	{
//		vector<vector<type>> newHead;
//
//		for (int i = 0; i < head.size() * 2; i++)
//		{
//			vector<type> temp;
//			for (int j = 0; j < head[i].size() * 2; j++)
//			{
//				temp.push_back(0);
//			}
//			newHead.push_back(temp);
//		}
//		vector<vector<type>> oldHead = head;
//		head = newHead;
//		
//		for (int i = 0; i < oldHead.size(); i++)
//		{
//			for (int j = 0; j < oldHead[i].size(); j++)
//			{
//				if (oldHead[i][j] != 0)
//				{
//					insert(oldHead[i][j]);
//				}
//			}
//		}
//
//	}
//public:
//	BucketProbing(int buckets, int bucketSlot = 2, double percentage = 70)
//	{
//		numItems = 0;
//		rehashPercentage = percentage;
//		for (int i = 0; i < buckets; i++)
//		{
//			vector<type> temp;
//			for (int j = 0; j < bucketSlot; j++)
//			{
//				temp.push_back(0);
//			}
//			head.push_back(temp);
//		}
//	}
//
//	~BucketProbing()
//	{
//		makeNull();
//	}
//
//	void makeNull()
//	{
//		numItems = 0;
//		for (int i = 0; i < head.size(); i++)
//		{
//			for (int j = 0; j < head[i].size(); j++)
//			{
//				head[i][j] = 0;
//			}
//		}
//	}
//
//	void insert(int key)
//	{
//		int hashValue = hash(key);
//
//		for (int i = 0; i < head[hashValue].size(); i++)
//		{
//			if (head[hashValue][i] == 0)
//			{
//				numItems++;
//				cout << key << " inserted.\n";
//				head[hashValue][i] = key;
//				return;
//			}
//		}
//
//		cout << key << "not inserted.\n";
//	}
//
//	void deletion(int key)
//	{
//		int hashValue = hash(key);
//
//		for (int i = 0; i < head[hashValue].size(); i++)
//		{
//			if (head[hashValue][i] == key)
//			{
//				numItems--;
//				cout << key << " deleted.\n";
//				head[hashValue][i] = 0;
//				return;
//			}
//		}
//
//		cout << key << "not found.\n";
//	}
//
//	void search(int key, bool& found, int hashKey = 0, int bucketSlot = 0)
//	{
//		int hashValue = hash(key);
//
//		for (int i = 0; i < head[hashValue].size(); i++)
//		{
//			if (head[hashValue][i] == key)
//			{
//				found = true;
//				bucketSlot = i;
//				hashKey = hashValue;
//				cout << key << " found.\n";
//				return;
//			}
//		}
//
//		found = false;
//		cout << key << "not found.\n";
//	}
//};
//
//int main()
//{
//
//	return 0;
//}