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

void printLeftView(Node *root,int level,int *max_level){
	if(root==NULL)return;
	
	if(*max_level<level){
		
		*max_level=level;
		cout<<root->data<<" ";
	}
	printLeftView(root->left,level+1,max_level);
	printLeftView(root->right,level+1,max_level);
	
}

int main()
{
    Node *root = new Node(12);
    root->left = new Node(10);
    root->right = new Node(30);
    root->right->left = new Node(25);
    root->right->right = new Node(40);
    int level=1;
    int max_level=0;
    printLeftView(root,level,&max_level);
    return 0;
}


