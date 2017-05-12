#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	
	int data;
	struct node *left,*right;
	
}Node;





Node *createNode(int data){
	Node *temp=new Node();
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
	
}

Node *head=NULL;
Node *p1=NULL;

Node *binaryTreeToDoublyCll(Node *root){
	if(root==NULL)
		return NULL;
		
	binaryTreeToDoublyCll(root->left);
	if(head==NULL){
		head=root;
		p1=root;
	}
	else{
		head->right=root;
		head->right->left=head;
		head=head->right;
	}

	binaryTreeToDoublyCll(root->right);
		
	
}

void displayDoublyCLL(Node *root){
	Node *itr=head;
	
	do{
		cout<<itr->data<<" ";
		itr=itr->right;
		
	}while(head!=itr);
	
}



int main(){
	
		Node *root1=createNode(10);
		root1->left=createNode(12);
		root1->right=createNode(15);
		root1->left->left=createNode(25);
		root1->left->right=createNode(30);
		root1->right->left=createNode(36);
	
	binaryTreeToDoublyCll(root1);
	p1->left=head;
	head->right=p1;
	displayDoublyCLL(p1);

}
