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

bool isLeaf(Node *root){
	if(!root)return false;
	if(root->left==NULL && root->right==NULL){
		return true;
	}
	return false;
}

int sumOfLeftLeaves(Node *root){
	
	if(root==NULL)return 0;
	int res=0;
	
	if(root){
		if(isLeaf(root->left))res+=root->left->data;
		
		else res+=sumOfLeftLeaves(root->left);
		
		res+=sumOfLeftLeaves(root->right);
	}
	return res;
}


int main(){
	
	Node *root=new Node(20);
	root->left                = new Node(9);
    root->right               = new Node(49);
    root->right->left         = new Node(23);
    root->right->right        = new Node(52);
    root->right->right->left  = new Node(50);
    root->left->left          = new Node(5);
    root->left->right         = new Node(12);
    root->left->right->right  = new Node(12);
    cout << "Sum of left leaves is "
         << sumOfLeftLeaves(root);
	
}
