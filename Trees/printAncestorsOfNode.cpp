#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	struct Node *left,*right;
	Node(int x){
		data=x;
		
	}
	
};

bool printAncestors(Node *root,int target){
	
	if(root==NULL)return 1;
	
	if(root->data==target){
		//cout<<root->data<<" ";
		return 1;
	}
	
	if(printAncestors(root->left,target) && printAncestors(root->right,target)){
		cout<<root->data<<" ";
		return 1;
	}
	
	return 0;
}

int main(){
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->left->left->left=new Node(6);
	
	cout<<endl<<printAncestors(root,6)<<endl;
	
}
