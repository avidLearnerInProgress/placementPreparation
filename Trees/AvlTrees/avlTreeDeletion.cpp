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

Node *getInorderSuccessor(Node *root){
	while(root->left!=NULL)root=root->left;
	return root;
}


Node *deleteFromAVL(Node *root,int k){
	if(root==NULL)return root;
	if(k<root->data)root->left=deleteFromAVL(root->left,k);
	else if(k>root->data)root->right=deleteFromAVL(root->right,k);
	else{
		if(root->left==NULL || root->right==NULL){
			Node *temp=root->left ? root->left : root->right;
			if(temp==NULL){
				temp=root;
				root=NULL;
			}
			*root=*temp;
			free(temp);
		}
		else{
			Node *temp=getInorderSuccessor(root->right);
			root->data=temp->data;
			root->right=deleteFromAVL(root->right,temp->data);
			
		}
		
	}
	if(root==NULL)return root;
	root->height=1+max(getHeight(root->left),getHeight(root->right));
	
	int bFactor=getBalanceFactor(root);
	
	if(bFactor>1 &&  getBalanceFactor(root->left)>=0)return rightRotate(root);
	if(bFactor<-1 && getBalanceFactor(root->right)<=0)return leftRotate(root);
	
	if(bFactor>1 && getBalanceFactor(root->left)<0){
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	if(bFactor<-1 && getBalanceFactor(root->right)>0){
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
  root=insertToAVL(root, 9);
  root=insertToAVL(root, 5);
  root=insertToAVL(root, 10);
  root=insertToAVL(root, 0);
  root=insertToAVL(root, 6);
  root=insertToAVL(root, 11);
  root=insertToAVL(root, -1);
  root=insertToAVL(root, 1);
  root=insertToAVL(root, 2);
  
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
  root = deleteFromAVL(root, 10);
 
    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */
 
   printf("\nPreorder traversal after deletion of 10 \n");
   printPreOrder(root);
 
  return 0;
}
