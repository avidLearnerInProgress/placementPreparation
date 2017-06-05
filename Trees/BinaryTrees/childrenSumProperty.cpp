#include <bits/stdc++.h>
using namespace std;
 
struct Node{
	int data;
	struct Node *left,*right;
};


Node *createNode(int data){
	Node *temp=new Node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
	
}

bool isChildrenSumProperty(Node *root){
	
	if(root==NULL)return 1;
	if(root->left==NULL && root->right==NULL) return 1;
	
	int ldata=0,rdata=0;
	
	if(root->left!=NULL)ldata=root->left->data;
	if(root->right!=NULL)rdata=root->right->data;
	
	if((root->data==(ldata+rdata)) && isChildrenSumProperty(root->left) && isChildrenSumProperty(root->right))return 1;
	
	else return 0;
	
	
}


int main() {
	Node* root=createNode(10);
	root->left=createNode(8);
	root->right=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(5);
	root->right->left=createNode(2);
	
	if(isChildrenSumProperty(root))
		cout<<"Yes,it holds property"<<endl;
	else
		cout<<"No it doesn't hold"<<endl;
	
	return 0;
}
