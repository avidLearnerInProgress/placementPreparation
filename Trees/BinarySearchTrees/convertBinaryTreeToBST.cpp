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

vector<int> v;

void extractTreeData(Node *root){
	if(root==NULL)return;
	
	extractTreeData(root->left);
	v.push_back(root->data);
	extractTreeData(root->right);
}


void convertToBST(Node *root,vector<int> &v,int &i){
	if(!root)return;
	
	convertToBST(root->left,v,i);
	root->data=v[i];
	i++;
	convertToBST(root->right,v,i);
}

void print(Node *root){
	if(root){
		print(root->left);
		cout<<root->data<<" ";
		print(root->right);
	}
}

int main()
{
    
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    Node *root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);
    cout<<"BINARY TREE BEFORE CONVERSION INORDER TRAVERSAL"<<endl;
    print(root);
    extractTreeData(root);
    cout<<endl;
    sort(v.begin(),v.end());
    cout<<"BINARY TREE TO BST INORDER TRAVERSAL"<<endl;
    int i=0;
    convertToBST(root,v,i);
    print(root);
 
    return 0;
}
