#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(char k)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

int countNodes(Node *root){
	if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}
 
 
bool isComplete(Node *root,int index,unsigned int node_count){
	
	if(!root)return true;
	if(index>node_count)return false;
	
	return isComplete(root->left,2*index+1,node_count)&&isComplete(root->right,2*index+2,node_count);
	
}


int main()
{

    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;
 
    if (isComplete(root, index, node_count))
        printf("The Binary Tree is complete\n");
    else
        printf("The Binary Tree is not complete\n");
    return (0);
}


