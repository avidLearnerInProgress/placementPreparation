#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node *right;
	
};


struct node *createNode(int data){
	
	struct node *newNode=(struct node *) malloc(sizeof(struct node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	
	return newNode;
}

void printVLRNode(struct node *root){
	
	if(root==NULL) return;
	
	//if(root!=NULL){
		cout<<root->data<<" ";
		printVLRNode(root->left);
		printVLRNode(root->right);
	//}
}

void printLVRNode(struct node *root){
	
	if(root==NULL) return;
	
	//if(root!=NULL){
		
		printLVRNode(root->left);
		cout<<root->data<<" ";
		printLVRNode(root->right);
	//}
}

void printLRVNode(struct node *root){
	
	if(root==NULL) return;
	
	//if(root!=NULL){
		
		printLRVNode(root->left);
		printLRVNode(root->right);
		cout<<root->data<<" ";
	//}
}

int main(){
	/*
	int x;
	cin>>x;
	*/
	struct node *node1=createNode(1);
	node1->left=createNode(2);
	node1->right=createNode(3);
	node1->left->left=createNode(4);
	
	 
	 printVLRNode(node1);
	 cout<<endl;
	 printLVRNode(node1);
	 cout<<endl;
	 printLRVNode(node1);
	return 0;
	
}
