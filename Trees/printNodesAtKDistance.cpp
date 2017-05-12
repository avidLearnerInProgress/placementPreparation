#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	struct Node *left,*right;
	
	Node(int x){
		data=x;
	}
};

void printNodesAtKDistance(Node *root,int k){
	if(root==NULL)return;
	if(k==0){
		cout<<root->data<<" ";
		return;
		
	}
	
	else{
		printNodesAtKDistance(root->left,k-1);
		printNodesAtKDistance(root->right,k-1);
	}
	
}


int main(){
	
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->left->left=new Node(7);
	root->right->left->right=new Node(8);
	
	int k=3;
	printNodesAtKDistance(root,k);
	
}
