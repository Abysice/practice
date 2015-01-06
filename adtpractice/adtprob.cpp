/***************************************************
 * Simple implementations + testing of ADT's
 ***************************************************/

#include <iostream>

//constants
const int MAX_SIZE = 128;

//node class
class hashNode
{
private:
	int key;
	int data;
public:
	hashNode* next; // for collisions

	hashNode(){}
	hashNode(int key, int data) : key(key), data(data)
	{
		this->next = NULL;
	}
	int getKey()
	{
		return key;
	}
	int getData()
	{
		return data;
	}
};

class map
{
private:
	hashNode ** table;
public:
	map()
	{
		table = new hashNode*[MAX_SIZE];
		for(int i = 0; i < MAX_SIZE; i++)
		{
			table[i] = NULL;
		}
	}

	void insert(int key, int data)
	{
		int hash = (key % MAX_SIZE);
		//no entry
		if(table[hash] == NULL)
		{
			printf("inserted \n");
			table[hash] = new hashNode(key, data);
		}
		else //collision
		{
			hashNode * temp = table[hash];
			while(1)
			{	
				//key is in use
				if (temp != NULL && temp->getKey() == key)
				{
					printf("key in use \n");
					break;
				}
				//if there is node
				if(temp == NULL)
				{
					printf("conflict 1 \n");
					table[hash]->next = new hashNode(key, data);
					return;
				}
				else if(temp->next == NULL)
				{
					printf("conflict but inserted\n");
					temp->next = new hashNode(key, data);
					break;
				}
				else
					temp = temp->next;
			}
		}
	}
	void remove(int key)
	{
		int hash = key % MAX_SIZE;
		hashNode * temp = table[hash];
		if(temp == NULL)
		{
			printf("no entry matching key\n");
			return;
		}
		else
		{
			temp = temp->next;
			hashNode * last = table[hash];
			if(key == last->getKey()) // first entry is the one
			{
				delete last;
				printf("first entry removed\n");
				table[hash] = temp;
				return;
			}

			while(1)
			{
				if (temp == NULL)
				{
					printf("not found \n");
					return;
				}
				else if(key == temp->getKey())
				{
					last->next = temp->next;
					printf("later entry removed\n");
					delete temp;
					return;
				}
				temp = temp->next;

			}
		}

	}
};

int main(int argc, char** argv)
{
	map test;
	test.insert(1,20);
	test.insert(129, 25);
	test.insert(257, 25);

	test.remove(2);
	test.remove(129);
	test.remove(1);
	test.remove(129);
	return 0;
}
