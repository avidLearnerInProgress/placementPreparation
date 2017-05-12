#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	struct Node *left,*right;
	Node(int data){
		data=data;
	}
};

bool isFoldableUtil(Node *a,Node *b){
	if(a==NULL && b==NULL)return 1;
	if(a==NULL || b==NULL)return 0;
	else
		return isFoldableUtil(a->left,b->right) && isFoldableUtil(a->right,b->left);
}

bool isFoldable(Node *root){
	if(root==NULL)return 1;
	
	return isFoldableUtil(root->left,root->right);
}



int main(){
	
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->right->left=new Node(4);
	root->left->right=new Node(5);
	/*root->right->left=new Node(6);
	root->right->left->left=new Node(7);
	root->right->left->right=new Node(8);
	*/
	
	cout<<isFoldable(root)<<endl;
	
	
}
