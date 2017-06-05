#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	
	int data;
	struct node *left;
	struct node *right;
	
}Node;



Node *createNode(int data){
	
	Node *temp=new Node();
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}

int sizeOfTree(Node *a){
	
	if(a==NULL)return 0;
	
	else return (1+ sizeOfTree(a->left)+ sizeOfTree(a->right));
	
}




int main(){
	Node *root1=createNode(1);
		root1->left=createNode(2);
		root1->right=createNode(3);
		root1->left->left=createNode(4);
		root1->left->right=createNode(5);
		root1->right->left=createNode(6);
		root1->right->right=createNode(7);
	
		cout<<sizeOfTree(root1)<<endl;
	
}
