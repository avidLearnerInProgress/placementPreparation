#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	Node(int x){
		data=x;
	}
};

void printBoundaryLeft(Node *root){
	
	if(root==NULL)return;
	
	while(root->left||root->right){
		
		cout<<root->data<<" ";
		root=root->left;
	}
}

void printBoundaryRight(Node *root){
	
	if(root==NULL)return;
	
	while(root->left||root->right){
		
		cout<<root->data<<" ";
		root=root->right;
	}
}


void printLeaves(Node *root){
	if(root==NULL)return;
	printLeaves(root->left);
	if(root->left==NULL && root->right==NULL)
		cout<<root->data<<" ";
	printLeaves(root->right);
	
}

void boundaryTraversal(Node *r){
	
	if(r==NULL)return;
	cout<<r->data<<" ";
	printBoundaryLeft(r->left);
	printLeaves(r->left);
	printLeaves(r->right);
	printBoundaryRight(r->right);
	
}

int main(){
	
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	boundaryTraversal(root);
	
}

