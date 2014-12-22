/***************************************************
 * Simple functions to do things in trees
 * generates a binary tree
 ***************************************************/

#include <iostream>

//hard coded int tree
struct treenode 
{
	int data;
	treenode *left;
	treenode *right;

	treenode(int _data)
	{
		data = _data;
	}
};


//prototypes
void populate(treenode *root);
int depthfind(treenode *root);
void printtree(treenode *root);
void printleafs(treenode *root);

int main(int argc, char** argv)
{
	//populate a tree
	treenode * root = new treenode(3);
	populate(root);
	
	//find deepest node depth
	printf("%i \n", depthfind(root));

	printtree(root);
	printf("\n");
	printleafs(root);
	printf("\n");
	

	return 0;
}

//print the leaves of a tree (nodes with no children)
void printleafs(treenode *root)
{
	if(root == NULL)
		return;//empty node

	if(root->left == NULL && root->right == NULL)
	{
		printf(" %i ", root->data);
	}
	else
	{
		printleafs(root->left);
		printleafs(root->right);
	}

	return;
}

//print trees in order, assuming sorted tree where left < root < right 
void printtree(treenode *root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		printtree(root->left);
		printf(" %i ", root->data);
		printtree(root->right);
	}

	return;
}

int depthfind(treenode *root)
{
	if(root == NULL)
	{
		return 0;
	}
	int countl = depthfind(root->left) + 1;
	int countr = depthfind(root->right) + 1;

	if(countl >= countr)
		return countl;
	else
		return countr;
	
	return 0;// will not reach here
}

//populates tree with some test values
void populate(treenode *root)
{
	root->left = new treenode(1);
	root->left->left = new treenode(0);
	root->left->right = new treenode(2);
	root->right = new treenode(5);
	root->right->left = new treenode(4);
	root->right->right = new treenode(6);
	
	return;
}
