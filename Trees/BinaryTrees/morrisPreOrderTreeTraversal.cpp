#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	Node(int x){
		data=x;
	}
};

void morrisPreOrderTraversal(Node *root){
	
	if(root==NULL)return;
	while(root){
	
	if(root->left==NULL){
		cout<<root->data<<" ";
		root=root->right;
	}
	
	else{
		
		Node *current=root->left;
		
		while(current->right && current->right!=root)
			current=current->right;
		
		if(current->right==root){
			current->right=NULL;
			root=root->right;
		}	
		
		else{
			cout<<root->data<<" ";
			current->right=root;
			root=root->left;
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
	
	morrisPreOrderTraversal(root);
	
}
