/* Program to find next right of a given key */
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct node
{
	struct node *left, *right;
	int key;
};

node* nextRight(node *root, int k)
{
	// Base Case
	if (root == NULL)
		return 0;

	queue<node *> qn; 
	
    int n;
	qn.push(root);
	
	while (!qn.empty())
	{
		n = qn.size();

		while(n)
		{
		    node *node = qn.front();
		    qn.pop();
		    n--;
		    // If the dequeued node has the given key k
    		if (node->key == k)
    		{
    		    if(n == 0)
    		        return NULL;
    		    else
    			    return qn.front();
    		}
    		
    		if (node->left != NULL)
    		{
    			qn.push(node->left);
    		}
    		if (node->right != NULL)
    		{
    			qn.push(node->right);
    		}
    	}
	}

	// We reach here if given key x doesn't exist in tree
	return NULL;
}

// Utility function to create a new tree node
node* newNode(int key)
{
	node *temp = new node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to test above functions
void test(node *root, int k)
{
	node *nr = nextRight(root, k);
	if (nr != NULL)
	cout << "Next Right of " << k << " is " << nr->key << endl;
	else
	cout << "No next right node found for " << k << endl;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree given in the above example
	node *root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(6);
	root->right->right = newNode(5);
	root->left->left = newNode(8);
	root->left->right = newNode(4);

	test(root, 10);
	test(root, 2);
	test(root, 6);
	test(root, 5);
	test(root, 8);
	test(root, 4);
	return 0;
}

