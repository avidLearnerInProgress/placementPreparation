#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
	
};

Node *removeBSTKeysOutsideRange(Node *root,int min,int max)
{
	if(root==NULL)return NULL;
	
	root->left=removeBSTKeysOutsideRange(root->left,min,max);
	root->right=removeBSTKeysOutsideRange(root->right,min,max);
	
	if(min<=root->data && root->data<=max)return root;
	
	if(root->data<min){
		Node *rchild=root->right;
		free(root);
		return rchild;
	}
	if(root->data>max){
		Node *lchild=root->left;
		free(root);
		return lchild;
	}
	return root;
}

void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}


Node* insert(Node* node, int data)
{
	if (node == NULL) return new Node(data);
	if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}

int main()
{
	
	Node*root=NULL;
	root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    inorder(root);
	cout<<endl;	
	int min=30,max=60;
	Node *temp=removeBSTKeysOutsideRange(root,min,max);
	inorder(temp);
}	
