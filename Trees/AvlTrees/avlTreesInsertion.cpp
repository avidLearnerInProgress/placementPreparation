#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	int height;
};


int max(int a,int b){
	if(a>b)return a;
	return b;
}

int getHeight(Node *p){
	if(p==NULL)return 0;
	return p->height; 
}


int getBalanceFactor(Node *p){
	if(p==NULL)return 0;
	int lh=getHeight(p->left);
	int rh=getHeight(p->right);
	return (lh-rh);
}


Node *rightRotate(Node *p){
	Node *q=p->left;
	p->left=q->right;
	q->right=p;
	p->height=1+max(getHeight(p->left),getHeight(p->right));
	q->height=1+max(getHeight(q->left),getHeight(q->right));
	
	return q;
}

Node *leftRotate(Node *q){
	Node *p=q->right;
	q->right=p->left;
	p->left=q;
	q->height=1+max(getHeight(q->left),getHeight(q->right));
	p->height=1+max(getHeight(p->left),getHeight(p->right));
	
	return p;
}


Node *insertToAVL(Node *root,int k){
	
	if(root==NULL){
		Node *temp=new Node;
		temp->data=k;
		temp->left=NULL;temp->right=NULL;
		temp->height=1;
		return temp;
	}
	if(k<root->data)
		root->left=insertToAVL(root->left,k);
	else if(k>root->data)
		root->right=insertToAVL(root->right,k);
	else
		return root;
	
	int bFactor=getBalanceFactor(root);
	root->height=1+max(getHeight(root->left),getHeight(root->right));
	
	if(bFactor>1 && k < root->left->data)
		return rightRotate(root);
	
	if(bFactor<-1 && k > root->right->data)
		return leftRotate(root);
	
	if(bFactor>1 && k > root->left->data){
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	
	if(bFactor<-1 && k < root->right->data){
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

void printPreOrder(Node *root){
	if(!root)return ;
	
		cout<<root->data<<" ";
		printPreOrder(root->left);
		printPreOrder(root->right);
	
}


int main()
{
  Node *root=NULL;
  root=insertToAVL(root, 10);
  root=insertToAVL(root, 20);
  root=insertToAVL(root, 30);
  root=insertToAVL(root, 40);
  root=insertToAVL(root, 50);
  root=insertToAVL(root, 25);
  
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  printPreOrder(root);
 
  return 0;
}
