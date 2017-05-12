#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	
	Node(int data){
		data=data;
	}
};


bool isSubSum(Node *root){
	if(root==NULL)return 0;
	
	else return (isSubSum(root->left)+root->data+isSubSum(root->right));
	
}

bool isSumTree(Node *root){
	
	if(root==NULL || (root->left==NULL && root->right==NULL))return 1;
	
	int ls=isSubSum(root->left);
	int rs=isSubSum(root->right);
	
	if((ls+rs==root->data)&&isSumTree(root->left)&&isSumTree(root->right))
		return 1;
	
	//return 0;
}


bool isLeafNode(Node *root){
	if(root==NULL)return 0;
	if(root->left==NULL && root->right==NULL)return 1;
	//return 0;
}

bool _isSumTree(Node *root){ 
	
	//o(n) solution
	int ls,rs;
	if(root==NULL || isLeafNode(root))return 1;
	
	if(_isSumTree(root->left) && _isSumTree(root->right)){
		if(root->left==NULL)ls=0;
		if(isLeafNode(root->left))ls=root->left->data;
		else ls=2*(root->left->data);
		
		if(root->right==NULL)rs=0;
		if(isLeafNode(root->right))rs=root->right->data;
		else rs=2*(root->right->data);
		
		
		return (root->data==(ls+rs));
	}
	return 0;
	
}

int main(){
	Node *root=new Node(26);
	root->left=new Node(10);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(6);
	root->right->right=new Node(3);
	
	int x=isSumTree(root);
	
	cout<<x<<endl;
	
	int y=_isSumTree(root);
	
	cout<<y<<endl;
	
	
}
