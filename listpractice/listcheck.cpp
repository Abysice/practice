/***************************************************
 * Simple functions to do things in lists
 * randomly generates lists and find things
 ***************************************************/

#include <iostream>
#include <random>
#include <list>

const int size = 100;

int findmiddle(std::list<int> &mylist);
int thirdlast(std::list<int> &mylist);

int main(int argc, char** argv)
{
	std::list<int> mylist;

	for(int i = 0; i < size; i++)	
	{
		mylist.push_back(i);
	} 

	printf("%i is the middle \n", findmiddle(mylist));
	printf("%i is the 3rd last \n", thirdlast(mylist));

	return 0;
}

//find the middle element in a linked list
int findmiddle(std::list<int> &mylist)
{
	std::list<int>::iterator it = mylist.begin(); //advance by 2
	std::list<int>::iterator it2 = mylist.begin(); 
	
	while (it != mylist.end())
	{
		it++; //advance by 1
		if(it != mylist.end())
		{
			it++; //advance by 1 more
			it2++;//advance by 1
		}
	}

	return *it2;
}

// find 3rd from last element in a linked list
int thirdlast(std::list<int> &mylist)
{
	if(mylist.size() < 3)
		return 0; //too small

	std::list<int>::iterator it = mylist.begin();
	std::list<int>::iterator it2 = mylist.begin();
	it++;
	it++;
	
	while(it != mylist.end())
	{
		it++;
		it2++;
	}

	return *it2;
}
