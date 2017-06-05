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


void nodesAtKDistanceFromLeaf(Node *root,int path[],bool visited[],int pathlen,int k){
	if(root==NULL)return;
	
	path[pathlen]=root->data;
	visited[pathlen]=false;
	pathlen++;
		
	if(root->left==NULL && root->right==NULL && pathlen-k-1>=0 && visited[pathlen-k-1]==false){
		cout<<path[pathlen-k-1]<<" ";
		visited[pathlen-k-1]=true;
		return;
		
	}
	
	nodesAtKDistanceFromLeaf(root->left,path,visited,pathlen,k);
	nodesAtKDistanceFromLeaf(root->right,path,visited,pathlen,k);
	
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
    nodesAtKDistanceFromLeaf(root,path,visited,pathlen,k);
	
	
 
    return 0;
}
