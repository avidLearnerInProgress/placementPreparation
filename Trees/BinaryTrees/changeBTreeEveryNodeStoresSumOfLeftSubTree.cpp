#include<bits/stdc++.h>
using namespace std;
 
// A tree node
struct node
{
    int data;
    struct node* left,  *right;
};
 
// Function to modify a Binary Tree so that every node
// stores sum of values in its left child including its
// own value
int updatetree(node *root)
{
    // Base cases
    if (!root)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;
 
    // Update left and right subtrees
    int leftsum  = updatetree(root->left);
    int rightsum = updatetree(root->right);
 
    // Add leftsum to current node
    root->data += leftsum;
 
    // Return sum of values under root
    return root->data + rightsum;
}
 
// Utility function to do inorder traversal
void inorder(struct node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}
 
// Utility function to create a new node
struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
// Driver program
int main()
{
    /* Let us construct below tree
                1
               / \
              2   3
             / \   \
            4   5   6    */
    struct node *root  = newNode(1);
    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);
    root->right->right = newNode(6);
 
    updatetree(root);
 
    cout << "Inorder traversal of the modified tree is \n";
    inorder(root);
    return 0;
}
