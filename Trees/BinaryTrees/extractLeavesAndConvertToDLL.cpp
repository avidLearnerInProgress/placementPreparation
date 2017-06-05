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

void print(Node *root){
	if(!root)return;
	print(root->left);
	cout<<root->data<<" ";
	print(root->right);
}

void printdll(Node *root){
	Node *temp=root;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->right;
	}
}

Node *extractLeavesAndConvertToDLL(Node *root,Node **head){
	
	static Node *prev=NULL;
	if(!root)return NULL;
	
	if(root->left==NULL && root->right==NULL){
		if(prev==NULL){
			root->left=prev;
			prev=root;
			*head=prev;
		}
		else{
			root->left=prev;
			prev->right=root;
			prev=root;
		}
		return NULL;
	}
	  root->left=extractLeavesAndConvertToDLL(root->left,head);
      root->right=extractLeavesAndConvertToDLL(root->right,head);
      
	return root;
}


int main()
{
     Node *root = new Node(1);
     root->left = new Node(2);
     root->right = new Node(3);
     root->left->left = new Node(4);
     root->left->right = new Node(5);
     root->right->right = new Node(6);
     root->left->left->left = new Node(7);
     root->left->left->right = new Node(8);
     root->right->right->left = new Node(9);
     root->right->right->right = new Node(10);
	Node *head=NULL;
    Node *temp=extractLeavesAndConvertToDLL(root,&head);
    print(temp);
    cout<<endl;
    printdll(head);
    return 0;
}  
