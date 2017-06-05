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


void printLVRNode(Node *root){
	
	if(root==NULL) return;
	
	//if(root!=NULL){
		
		printLVRNode(root->left);
		cout<<root->data<<" ";
		printLVRNode(root->right);
	//}
}


void mirror(Node *root){
	
	if(root==NULL)return;
	else{
		Node *temp;
		mirror(root->left);
		mirror(root->right);
		
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
	
}

int main(){
	
		Node *root1=createNode(1);
		root1->left=createNode(2);
		root1->right=createNode(3);
		root1->left->left=createNode(4);
		root1->left->right=createNode(5);
		root1->right->left=createNode(6);
		root1->right->right=createNode(7);
	
	cout<<"Data of Constructed Tree: "<<endl;
	printLVRNode(root1);
	cout<<endl;
	
	mirror(root1);
	
	cout<<"Data of Mirror Tree: "<<endl;
	printLVRNode(root1);
}
