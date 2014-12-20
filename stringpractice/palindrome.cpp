/**************************************************
 * Simple paldindrome practice problem
 * Reads from command line, prints true/false
 **************************************************/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) 
{	
	//args into vector of strings
  	std::vector<std::string> all_args(argv, argc + argv);
	
	if (argc > 1)
	{
	int head, tail;
	for(int i = 1; i < argc; i++)
	{
		head = 0;
		tail = all_args[i].length()-1;
		for(int j = 0; j < (tail+1)/2; j++)
		{
			if (all_args[i].at(tail-j) != all_args[i].at(head+j))
			{
				printf("%s is not a palindrome \n", all_args[i].c_str());
				break;
			}
			else if ((tail-j) - (head+j) <= 2)
			{
				printf("%s is a palindrome \n", all_args[i].c_str());
				break;	
			}
		}	
	}
	}
	
	return 0;
}
