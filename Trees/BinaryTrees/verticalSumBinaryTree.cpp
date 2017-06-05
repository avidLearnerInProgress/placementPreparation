#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

map<int,int> m;
int verticalSumBinaryTree(Node *root,int c){
	if(!root)return 0;
	verticalSumBinaryTree(root->left,c-1);
	m[c]+=root->data;
	verticalSumBinaryTree(root->right,c+1);
}


int main(){
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	verticalSumBinaryTree(root,0);
	
	for(auto it=m.begin();it!=m.end();it++){
		cout<<it->first<<" "<<it->second;
		cout<<endl;	
	}
	
	
}	
