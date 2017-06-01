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

void pushLeft(Node *root,stack<Node *>& s){

	while(root!=NULL){
		s.push(root);
		root=root->left;
	}
}

Node *insert(Node *root, int key){
	if(root==NULL)
		return new Node(key);
	if(root->data>key)
		root->left=insert(root->left,key);
	else if(root->data<key)
		root->right=insert(root->right,key);
	return root;
}

void mergeBST(Node *root1,Node *root2){
	
	stack<Node *> s1;
	stack<Node *> s2;
	
	pushLeft(root1,s1);
	pushLeft(root2,s2);
	
	while(!s1.empty() && !s2.empty()){
		
		Node *t1=s1.top();
		Node *t2=s2.top();
		
		if(t1->data<t2->data){
		
		cout<<t1->data<<" ";
		s1.pop();
		if(t1->right!=NULL){
			root1=t1->right;
			pushLeft(root1,s1);
			}
		
		}
		
		else{
			cout<<t2->data<<" ";
			s2.pop();
			if(t2->right!=NULL){
				root2=t2->right;
				pushLeft(root2,s2);
			}
		}
		
	}
	
	while(!s1.empty()){
		Node *t1=s1.top();
		cout<<t1->data<<" ";
		s1.pop();
		if(t1->right!=NULL){
			root1=t1->right;
			pushLeft(root1,s1);
		}
	}
	
	while(!s2.empty()){
		Node *t2=s2.top();
		cout<<t2->data<<" ";
		s2.pop();
		if(t2->left!=NULL){
			root2=t2->right;
			pushLeft(root2,s2);
			
		}
	}
}


int main(){
	Node  *root1 = NULL, *root2 = NULL;
    root2 = new Node(4);
    root2->left        = new Node(2);
    root2->right       = new Node(6);
    root2->left->left  = new Node(1);
    root2->left->right = new Node(3);
    root2->right->left  = new Node(5);
    root2->right->right = new Node(7);
 
  	root1 = new Node(100);
    root1->left        = new Node(90);
    root1->right       = new Node(105);
    root1->left->left  = new Node(70);
    root1->left->right = new Node(95);
    root1->right->left  = new Node(103);
    root1->right->right = new Node(106);
    mergeBST(root1,root2);
    return 0;
}
