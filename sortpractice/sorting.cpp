/***************************************************
 * Simple sort function implementations
 ***************************************************/

#include <iostream>
#include <random>

const int SIZE = 100;

void qsort(int array[], int lo, int hi);
int partition(int array[], int lo, int hi);

int main(int argc, char** argv)
{
	int array[SIZE];
	for(int i = 0; i < SIZE; i++)
	{
		array[i] = rand()%100 + 1; //random number from 1-100
	}

	qsort(array, 0, 100);

	for(int i = 0; i < SIZE; i++)
	{
		printf(" %i ", array[i]);
	}

	return 0;
}

void qsort(int array[], int lo, int hi)
{
	if(lo < hi)
	{
		int p = partition(array, lo, hi);
		qsort(array, lo, p - 1);
		qsort(array, p + 1, hi);

	}

	return;
}

int partition(int array[], int lo, int hi)
{
	int pivotIndex = lo + (hi - lo)/2;//middle node
	int pivotValue = array[pivotIndex];
	
	//swap A[pivotIndex] and A[hi]
	int temp = array[hi];
	array[hi] = array[pivotIndex];
	array[pivotIndex] = temp;
	
	int storeIndex = lo;

	for(int i = lo; i < hi; i++)
	{
		if(array[i] <= pivotValue)
		{
				//swap A[i] and A[storeIndex]
				int t = array[i];
				array[i] = array[storeIndex];
				array[storeIndex] = t;
				storeIndex++;
		}
	}
	//move pivot to its final place
	int swap = array[hi];
	array[hi] = array[storeIndex];
	array[storeIndex] = swap;

	return storeIndex;
}
