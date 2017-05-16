#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		//left=right=NULL;
	}
};


void morrisInOrderTraversal(Node *root1){
	
	if(root1==NULL)return;
	
	Node *root=root1;
	while(root!=NULL){
		
		if(root->left==NULL){
			cout<<root->data<<" ";
			root=root->right;
		}
		
		else{
			Node *current=root->left;
			
			while(current->right!=NULL && current->right!=root)
				current=current->right;
			
			if(current->right==NULL){
				
				current->right=root;
				root=root->left;
			}
			
			else{
				current->right=NULL;
				cout<<root->data<<" ";
				root=root->right;
				
			}
			
		}
		
	}
	
}

int main(){
		Node *root=new Node(10);
	root->left=new Node(8);
	root->right=new Node(2);
	root->left->left=new Node(3);
	root->left->right=new Node(5);
	root->right->left=new Node(2);
	//root->right->right=new Node(7);
	
	morrisInOrderTraversal(root);
	
}
