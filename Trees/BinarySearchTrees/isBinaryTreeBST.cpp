#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

int isBinaryTreeBST(Node* root,int l,int h){
	if(!root)return 1;
	return(
		(root->data>l && root->data<h) && 
		(isBinaryTreeBST(root->left,l,root->data)) &&
		(isBinaryTreeBST(root->right,root->data,h))
		);
}


Node *insertBST(Node *root,int key){
	if(root==NULL){
		Node *temp=new Node(key);
		return temp;
	}
	
	if(key<root->data){
		root->left=insertBST(root->left,key);
	}
	if(key>root->data){
		root->right=insertBST(root->right,key);
	}
	return root;
}


int main(){
	Node *root=NULL;
	root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);
	if(isBinaryTreeBST(root,INT_MIN,INT_MAX))cout<<1<<endl;
	else cout<<0<<endl;
   
    
	
}
