#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};
 
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
struct node* newNode(int data)
{
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}


int fbst(node *root)
{
	node *p1=NULL;
	node *p2=NULL;
	node *t1=root->left;
	node *t2=root->right;
	if((t1->data<root->data) && (t2->data>root->data))
	{
		fbst(t1);
		fbst(t2);
	}
	else if((t1->data<root->data) && (t2->data<root->data))
	{
		fbst(t1);
		p2=t2;
	}
	else if((t1->data>root->data) && (t2->data>root->data))
	{
		fbst(t2);
		p1=t1;
	}
	else if((t1->data>root->data) && (t2->data<root->data))
	{
		p2=t2;
		p1=t1;
	}
	swap(&(p1->data),&(p2->data));
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
 
int main()
{
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */
 
    struct node *root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);
 
    printf("Inorder Traversal of the original tree \n");
    printInorder(root);
 
    fbst(root);
 
    printf("\nInorder Traversal of the fixed tree \n");
    printInorder(root);
 
    return 0;
}
