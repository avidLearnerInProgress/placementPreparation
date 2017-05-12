#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};


Node *createNode(int data){
	Node *temp=new Node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

int height(Node *root){
	if(root==NULL)return 0;
	else return (1 + max(height(root->left),height(root->right)));
}

int diameter(Node *root){
	
	if(root==NULL)return 0;
	
	int lheight=height(root->left);
	int rheight=height(root->right);
	
	
	int ldiam=diameter(root->left);
	int rdiam=diameter(root->right);
	
	return max((1+ lheight +rheight),max(ldiam,rdiam));
}


int main(){
	Node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	
	cout<<"Diameter: "<<diameter(root)<<endl;
	
}

