#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right,*next;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

void poplulateInOrderSuccessor(Node *p){
	
//	if(!p)return;
	
	static  Node *next=NULL;
	if(p){
		poplulateInOrderSuccessor(p->right);
		
		p->next=next;
		next=p;
		
		poplulateInOrderSuccessor(p->left);
	}
	
}

void printSuccessor(Node *root){
	
	Node *p;
	while(root->left!=NULL)
		root=root->left;
	p=root;	
	while(p!=NULL){
		
		cout<<p->data<<" -> ";
		(p->next)?cout<<p->next->data:cout<<-1;
		cout<<endl;
		
		p=p->next;
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
	
	poplulateInOrderSuccessor(root);
	
	printSuccessor(root);
	
}	
