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

int maxPathSumUtil(Node *root, int &res)
{
	if (root==NULL) return 0;
	if (!root->left && !root->right) return root->data;
	
	int ls = maxPathSumUtil(root->left, res);
	int rs = maxPathSumUtil(root->right, res);

	if (root->left && root->right)
	{   
	    res=max(res,ls+rs+root->data);
		int temp=max(ls, rs)+root->data;
		cout<<"for node = "<<root->data <<" Sum is = "<<temp<<" ls = "<<ls<<" rs = "<<rs<<endl;
		return temp;
	}
    
    int temp=(!root->left)?rs+root->data:ls+root->data; 
	cout<< "for leaf = "<<root->data <<" Sum is = "<<temp<<endl;
	return temp;
}

int main()
{
    int res=INT_MIN;
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

	maxPathSumUtil(root,res);
	cout<<"Max pathSum of the given binary tree is "<<res;
	return 0;
}
