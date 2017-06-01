#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

void convert(node *root){
	if(root==NULL)return;
	convert(root->left);
	convert(root->right);
	
	if(root->left==NULL){
		root->left=root->right;
	}
	else{
		root->left->right=root->right;
	}
	root->right=NULL;
	
}
void downRightTraversal(node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        downRightTraversal(root->right);
        downRightTraversal(root->left);
    }
}
 
node* newNode(int key)
{
    node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 

int main()
{
    /*
           1
         /   \
        2     3
             / \
            4   5
           /   /  \
          6   7    8
    */
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);
 
    convert(root);
 
    cout << "Traversal of the tree converted to down-right form\n";
    downRightTraversal(root);
 
    return 0;
}
