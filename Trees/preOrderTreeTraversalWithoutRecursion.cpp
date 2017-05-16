#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	Node(int x){
		data=x;
	}
};

void preOrderTraversalWithoutRecursion(Node *root){
	
	if(root==NULL)return;
	
	stack<Node *> s;
	s.push(root);
	
	while(!s.empty()){
		
		Node *vNode=s.top();
		cout<<vNode->data<<" ";
		s.pop();
		
		//Push right child first so that left child is processed first Stack(LIFO)
	
		if(vNode->right)	
			s.push(vNode->right);
		if(vNode->left)
			s.push(vNode->left);
		
	}
}


int main(){
	
	Node *root=new Node(10);
	root->left=new Node(8);
	root->right=new Node(2);
	root->left->left=new Node(3);
	root->left->right=new Node(5);
	root->right->left=new Node(2);
	//root->right->right=new Node(7);
	
	preOrderTraversalWithoutRecursion(root);
	
}
