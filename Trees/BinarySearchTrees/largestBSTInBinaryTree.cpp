#include<bits/stdc++.h>
using namespace std;

//video tushar roy code implemented in cpp

struct Node{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

struct info{
	bool isBST;
	int size;
	int min;
	int max;
};

Node *Insert(Node *root,int num)
{
if(root==NULL)
root=new Node(num);
 
else if(num<root->data)
root->left=Insert(root->left,num);
 
else if(num>root->data)
root->right=Insert(root->right,num);
 
return root;
}
 

info largestUtil(Node *root){
	info rootInfo;
	
	if(root==NULL){
		rootInfo.size=0;
		rootInfo.min=INT_MAX;
		rootInfo.max=INT_MIN;
		rootInfo.isBST=true;
		return rootInfo;
	}
	info leftInfo,rightInfo;
	leftInfo=largestUtil(root->left);
	rightInfo=largestUtil(root->right);
	
	if(!leftInfo.isBST || !rightInfo.isBST || root->data<leftInfo.max || root->data>rightInfo.min){
		rootInfo.size=max(leftInfo.size,rightInfo.size);
		rootInfo.min=INT_MAX;
		rootInfo.max=INT_MIN;
		rootInfo.isBST=false;
		return rootInfo;
	}
	
	rootInfo.isBST=true;
	rootInfo.size=leftInfo.size+rightInfo.size+1;
	
	if(root->left)
		rootInfo.min=leftInfo.min;
	else
		rootInfo.min=root->data;
	
	if(root->right)
		rootInfo.max=rightInfo.max;
	else
		rootInfo.max=root->data;
	return rootInfo;
}

int largest(Node *root){
	info rootInfo=largestUtil(root);
	return rootInfo.size;
}



int main(){
	Node *root=NULL;
	root=new Node(50);
	root->left	 = new Node(10);
	root->right	 = new Node(60);
	root->left->left = new Node(5);
	root->left->right = new Node(20);
	root->right->left = new Node(55);
	root->right->left->left = new Node(45);
	root->right->right = new Node(70);
	root->right->right->left = new Node(65);
	root->right->right->right = new Node(80);
	cout<<largest(root)<<" ";
	
}

