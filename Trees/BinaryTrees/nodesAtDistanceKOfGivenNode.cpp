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

void nodesAtDistanceKDown(Node *root,int k){
	if(root==NULL || k<0)return;
	
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	
	nodesAtDistanceKDown(root->left,k-1);
	nodesAtDistanceKDown(root->right,k-1);
}

int nodesAtDistanceK(Node *root,int k,Node *target){
	if(root==NULL) return -1;
	if(root==target){
		nodesAtDistanceKDown(root,k);
		return 0;
	}
	
	int dleft=nodesAtDistanceK(root->left,k,target);
	if(dleft!=-1){
		
		if(dleft+1==k)
			cout<<root->data<<" ";
		else
			nodesAtDistanceKDown(root->right,k-dleft-2);
			
		return dleft+1;	
	}
	
	int dright=nodesAtDistanceK(root->right,k,target);
	if(dright!=-1){
		if(dright+1==k)
			cout<<root->right<<" ";
		else
			nodesAtDistanceKDown(root->left,k-dright-2);
		
		return 	dright+1;
	}
	return -1;
}

int main()
{
 
    Node * root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    Node * target = root->left->right;
    nodesAtDistanceK(root,2,target);
    
}



