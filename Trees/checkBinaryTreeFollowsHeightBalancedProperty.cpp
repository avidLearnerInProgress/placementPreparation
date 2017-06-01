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


bool isBalanced(Node *root,int &minh,int &maxh){
	if(root==NULL){
		maxh=minh=0;
		return true;
	}
	
	int leftMin,leftMax;
	int rightMin,rightMax;
	
	if(isBalanced(root->left,leftMin,leftMax)==false)return false;
	if(isBalanced(root->right,rightMin,rightMax)==false)return false;
	
	maxh=max(leftMax,rightMax)+1;
	minh=max(leftMin,rightMin)+1;
	if(maxh<=2*minh)return true;
	
	return false;
}

void print(Node *root){
	if(!root)return;
	print(root->left);
	cout<<root->data<<" ";
	print(root->right);
	
}



int main()
{
    
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    int k=2;
    int path[10000];
    int pathlen=0;
    bool visited[10000]={false};
    int maxh,minh;
    if(isBalanced(root,minh,maxh))
    	cout<<1<<endl;
    else
    	cout<<0<<endl;
    
	
	
 
    return 0;
}
