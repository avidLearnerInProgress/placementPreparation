#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};


int toSumTree(Node *node)
{
    
    if(node==NULL)return 0;
    int old_val=node->data;
    node->data=toSumTree(node->left)+toSumTree(node->right);
    return node->data+old_val;
}

void printInOrder(Node *root){
	if(!root)return;
	printInOrder(root->left);
	cout<<root->data<<" ";
	printInOrder(root->right);
	
}

int main(){
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	toSumTree(root);
	printInOrder(root);
}	
