#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
};

Node* newNode(int data)
{
	Node* node=new Node();
	node->data=data;
	node->left=node->right=NULL;
	return (node);
}


bool printMaxPath(Node *root,int sum){

	if(root==NULL)return (sum==0);
	if(printMaxPath(root->left,sum-root->data)||printMaxPath(root->right,sum-root->data)){
		cout<<root->data<<" ";
		return true;
	}
	return false;
}


int maxPathSumUtil(Node *root){
	
	if(root==NULL)return 0;
	if(root->left==NULL && root->right==NULL)return root->data;
	return max(root->data+maxPathSumUtil(root->left),root->data+maxPathSumUtil(root->right));
}



int main()
{
    //int res=INT_MIN;
	struct Node *root=newNode(-10);
	root->left=newNode(25);
	root->right=newNode(6);
	root->left->left=newNode(-8);
	root->left->right=newNode(1);
	root->left->left->left=newNode(2);
	root->left->left->right=newNode(6);
	root->right->left=newNode(3);
	root->right->right=newNode(9);
	root->right->right->right=newNode(0);
	root->right->right->right->left=newNode(4);
	
	int sum=maxPathSumUtil(root);
	cout<<sum<<endl;
	cout<<"Nodes on path are: ";
	printMaxPath(root,sum);
	//cout<<"Max pathSum of the given binary tree is "<<res;
	return 0;
}
