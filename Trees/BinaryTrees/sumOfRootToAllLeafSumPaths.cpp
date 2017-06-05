#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    int data;
    struct node *left, *right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 

//All helper functions taken from GFG 
int sumOfRootToAllLeafSumPaths(struct node *root,int val){
	
    if(root == NULL) return 0;
    if(!root -> left && !root->right) return root -> data + cSum*10 ;
    return sumOfRootToAllLeafSumPaths(root -> left , cSum*10  + root -> data) + sumOfRootToAllLeafSumPaths -> right , cSum*10  + root -> data);
}

int main()
{
    struct node *root = newNode(6);
    root->left        = newNode(3);
    root->right       = newNode(5);
    root->left->left  = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    int val=0;
    printf("Sum of all paths is", sumOfRootToAllLeafSumPaths(root,val));
    return 0;
}
