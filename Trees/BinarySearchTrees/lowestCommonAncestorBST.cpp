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

Node *insertBST(Node *root,int key){
	if(root==NULL){
		Node *temp=new Node(key);
		return temp;
	}
	
	if(key<root->data){
		root->left=insertBST(root->left,key);
	}
	if(key>root->data){
		root->right=insertBST(root->right,key);
	}
	return root;
}


void inOrderPredecessorSuccessor(Node *root,int key,Node *&pre,Node *&suc){
	if(root==NULL)return;
	
	if(root->data==key){
		
		if(root->left!=NULL){
			Node *temp=root->left;
			while(temp->right)
				temp=temp->right;
			pre=temp;
		
		}
		if(root->right!=NULL){
			Node *temp=root->right;
			while(temp->left)
				temp=temp->left;
			suc=temp;	
		}
		return;
	}
	else
	{
		if(key<root->data){
			suc=root;
			inOrderPredecessorSuccessor(root->left,key,pre,suc);
		}
		if(key>root->data){
			pre=root;
			inOrderPredecessorSuccessor(root->right,key,pre,suc);
		}
	}

}

Node *lcaBST(Node *root,int n1,int n2){
	if(root==NULL)return NULL;
	
	if(root->data<n1 && root->data<n2)
		return lcaBST(root->right,n1,n2);
	if(root->data>n1 && root->data>n2)
		return lcaBST(root->left,n1,n2);
	else
		return root;
}


int main(){
	Node *root=NULL;
	root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);
    int key=70;
    int n1=70;
    int n2=40;
    Node *res=lcaBST(root,n1,n2);
    cout<<res->data<<endl;
	
}
