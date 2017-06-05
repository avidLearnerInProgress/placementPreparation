// C++ program to count BST nodes withing a given range
#include<bits/stdc++.h>
using namespace std;

// A BST node
struct node
{
	int data;
	struct node* left, *right;
};

// Utility function to create new node
node *newNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return (temp);
}

// Returns count of nodes in BST in range [low, high]
int getCount(node *root, int low, int high)
{
	
	if (!root) return 0;
	if (root->data == high && root->data == low)
		return 1;

	if (root->data <= high && root->data >= low)
		return 1 + getCount(root->left, low, high) +
					getCount(root->right, low, high);

	else if (root->data < low)
		return getCount(root->right, low, high);

	else return getCount(root->left, low, high);
}

// Driver program
int main()
{
	// Let us construct the BST shown in the above figure
	node *root	 = newNode(10);
	root->left	 = newNode(5);
	root->right	 = newNode(50);
	root->left->left = newNode(1);
	root->right->left = newNode(40);
	root->right->right = newNode(100);
	/* Let us constructed BST shown in above example
		10
		/ \
	5	 50
	/	 / \
	1	 40 100 */
	int l = 5;
	int h = 45;
	cout << "Count of nodes between [" << l << ", " << h
		<< "] is " << getCount(root, l, h);
	return 0;
}

