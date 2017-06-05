#include<bits/stdc++.h>
using namespace std;


typedef struct node{
	int data;
	struct node *left;
	struct node *right;
	
}Node;

//typedef struct node Node;

Node *createNode(int data){
	
		Node *temp=new Node();
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		
		return temp;
		
}


bool identicalTrees(Node *a,Node *b){
	
	if(a==NULL && b==NULL)return true;
	else if(a!=NULL && b!=NULL){
		return(
			a->data==b->data && 
			identicalTrees(a->left,b->left) && 
			identicalTrees(a->right,b->right)
			
			);
	}
	return 0;
}


int main(){
		Node *root1=createNode(1);
		root1->left=createNode(2);
		root1->right=createNode(3);
		root1->left->left=createNode(4);
		root1->left->right=createNode(5);
		root1->right->left=createNode(6);
		root1->right->right=createNode(7);
		
		Node *root2=createNode(1);
		root2->left=createNode(2);
		root2->right=createNode(3);
		root2->left->left=createNode(4);
		root2->left->right=createNode(5);
		root2->right->left=createNode(6);
		root2->right->right=createNode(7);
		
		
		int x=identicalTrees(root1,root2);
		if(x)cout<<"Identical"<<endl;
		else cout<<"Not Identical"<<endl;
		
}
