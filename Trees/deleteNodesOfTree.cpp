#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	
	int data;
	struct node *left;
	struct node *right;
	
}Node;



Node *createNode(int data){
	
	Node *temp=new Node();
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}

void deleteTree(struct node* node) 
{
    if(node==NULL) 
    	return;
    deleteTree(node->left);
    deleteTree(node->right);
	cout<<node->data<<" ";
    free(node);
} 
 
 
void _deleteTree(struct node* node)
{
    if(node==NULL) 
    	return;
    _deleteTree(node->left);
    _deleteTree(node->right);
	cout<<node->data<<" ";
    free(node);
}
 
void deleteTreeAndSetRootAsNULL(Node *node)
{
  _deleteTree(node);
  node=NULL;
}




int main(){
		Node *root1=createNode(1);
		root1->left=createNode(2);
		root1->right=createNode(3);
		root1->left->left=createNode(4);
		root1->left->right=createNode(5);
		root1->right->left=createNode(6);
		root1->right->right=createNode(7);
		
		Node *root2=createNode(1);
		root2->left=createNode(2);
		root2->right=createNode(3);
		root2->left->left=createNode(4);
		root2->left->right=createNode(5);
		root2->right->left=createNode(6);
		root2->right->right=createNode(7);
		
		deleteTree(root1);cout<<endl;
		deleteTreeAndSetRootAsNULL(root2);
	
}
