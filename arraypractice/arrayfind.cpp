/**************************************************
 * Simple functions to look for things in arrays
 * randomly generates arrays and finds things
 ***************************************************/

#include <iostream>
#include <random>
#include <set> 

int findduplicate(int arr[], int size);

int main(int argc, char** argv)
{
	//populate a random array with 1-100
	int array[100];	
	for(int i = 0; i < 100; i++)
	{
		//array[i] = rand()%100 + 1;
		if(i == 55)
			array[i] = 54;
		else
			array[i] = i + 1;
	}	
	printf("%i \n", findduplicate(array, 100)); 
	

	return 0;
}

//find the duplicate in an array of 1-n
int findduplicate(int arr[], int size)
{
	int duplicate;			
	std::set<int> set;
	std::set<int>::iterator it;
	std::pair<std::set<int>::iterator, bool> ret;

	for(int i = 0; i < size; i++)
	{	
		ret = set.insert(arr[i]);
		if(!ret.second)
		{
			duplicate = arr[i];
		}
	}
	
	return duplicate;
}
