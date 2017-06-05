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



void printInorder(Node *root){
	
	if(root){
		printInorder(root->left);
		cout<<root->data<<" ";
		printInorder(root->right);
		
		
	}
	
}

Node *removeShortPathNodes(Node *root,int k,int level){
	if(!root)return NULL;
	
	root->left=removeShortPathNodes(root->left,k,level+1);
	root->right=removeShortPathNodes(root->right,k,level+1);
	
	if(root->left==NULL && root->right==NULL && level<k){
		free(root);
		return NULL;
	}
	
	return root;
	
}


int main()
{
    int k = 4,level=1;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(7);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);
    cout << "Inorder Traversal of Original tree" << endl;
    printInorder(root);
    cout << endl;
    cout << "Inorder Traversal of Modified tree" << endl;
    Node *res = removeShortPathNodes(root,k,level);
    printInorder(res);
    return 0;
}
