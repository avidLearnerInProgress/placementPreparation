#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};


Node *createNode(int data){
	Node *temp=new Node;
	temp->data=data;
	temp->left=temp->right=NULL;
	
	return temp;
}

void doubleOfTree(Node *root){
	if(root==NULL)return ;
	doubleOfTree(root->left);
	doubleOfTree(root->right);
	Node *oldleft;
	oldleft=root->left;
	root->left=createNode(root->data);
	root->left->left=oldleft;
}

void InOrder(Node *root){
	if(root==NULL) return;
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

int main(){
	
	Node *root1=createNode(1);
	root1->left=createNode(2);
	root1->right=createNode(3);
	root1->left->left=createNode(4);
	root1->left->right=createNode(5);
	InOrder(root1);
	cout<<endl;
	
	doubleOfTree(root1);
	InOrder(root1);
	return 0;
}
	
