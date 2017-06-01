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

Node *constructTree(int pre[],int n){
	
	stack<Node *> s;
	Node *root=new Node(pre[0]);
	Node *currentptr=NULL;
	s.push(root);
	for(int i=0;i<n;i++)
	{
		while(!s.empty() && pre[i]>s.top()->data){
			currentptr=s.top();
			s.pop();
		}	
		if(currentptr==NULL){
			s.top()->left=new Node(pre[i]);
			s.push(s.top()->left);
		}
		else{
			currentptr->right=new Node(pre[i]);
			s.push(currentptr->right);
		}
	}	
	return root;
}

void inorder(Node *root){
	if(!root)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	int pre[] = {10,5,1,7,40,50};
	int n=sizeof(pre)/sizeof(pre[0]);
	Node *root=NULL;
	root=constructTree(pre,n);
	inorder(root);
	
}
