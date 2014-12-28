/***************************************************
 * Simple functions to solve simple problems
 ***************************************************/

#include <iostream>

bool ispower(float const &x);

int main(int argc, char** argv)
{

	printf("%s \n", ispower(512) ? "true" : "false");

	return 0;
}

//recursive
bool ispower(float const &x)
{
	if(x/2 < 2)
	{
		return false;
	}
	if(x/2 == 2)
	{ 
		return true;
	}
	else if (ispower(x/2))
	{
		return true;
	}
	else return false;	
}
