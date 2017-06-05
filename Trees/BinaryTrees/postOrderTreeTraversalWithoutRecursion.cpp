#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	Node(int x){
		data=x;
	}
};

void postOrderTraversalWithoutRecursion(Node *root){ //using 2 stacks
	
	if(root==NULL)return;
	stack<Node *> s1;
	stack<Node *> s2;
	
	s1.push(root);
	while(!s1.empty()){
		Node *vNode=s1.top();
		s2.push(vNode);
		s1.pop();
		
		
		if(vNode->left)s1.push(vNode->left);
		if(vNode->right)s1.push(vNode->right);
		
		
	}
	
	while(!s2.empty()){
		cout<<s2.top()->data<<" ";
		s2.pop();
		
		
	}
	
}

/*
There are two important things that we need to take care of 
1) once left or right child is pushed make them NULL so that we don't revisit them again
2) Push the right child before the left child and print and pop the node when its both left and right child are NULL.
*/

void _postOrderTraversalWithoutRecursion(Node *root){ //Using 1 stack
	
	if(root==NULL)	return;
	stack<Node *> s;
	s.push(root);
	
	while(!s.empty()){
		
		Node *temp=s.top();
		//s.pop();
		
		if(temp->left==NULL && temp->right==NULL){
			cout<<temp->data<<" ";
			s.pop();
		}
		
		else{
			
			if(temp->right){
				s.push(temp->right);
				temp->right=NULL;
			}
			
			if(temp->left){
				s.push(temp->left);
				temp->left=NULL;
			}
		}
	}
}



int main(){
	
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	postOrderTraversalWithoutRecursion(root);
	cout<<endl;
	_postOrderTraversalWithoutRecursion(root);
	
}
