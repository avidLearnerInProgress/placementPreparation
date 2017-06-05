#include <bits/stdc++.h>
using namespace std;

struct node
{
    node* left;
    node* right; 
    int data;
};
 
node* newNode(int x)
{
    node* temp=new node();
    temp->left=NULL;
    temp->right=NULL;
    temp->data=x;
    return temp;
}
 
struct node* insert(struct node* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data);
 
    /* Otherwise, recur down the tree */
    if (data <= node->data)
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);
 
    /* return the (unchanged) node pointer */
    return node;
}

void kthLargest(node* root,int &k,int c)   
{
    if(root==NULL)
        return;   

    kthLargest(root->right,k,c);  // First recurse for the right sub-tree

    k=k-1; // Here k is a reference variable
    
    if(k==0)
        printf("%d-Largest is %d\n",c,root->data);   // Variable c is used just for the print statement
                                     
    kthLargest(root->left,k,c); // Recurse for the left sub-tree
}


int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    for (int c=1; c<=7; c++)
    {   int k=c;
        kthLargest(root,k,c);
    }
    return 0;
}
