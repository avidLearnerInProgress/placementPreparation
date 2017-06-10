#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
};

Node *newNode(int d){
	Node *temp=new Node;
	temp->data=d;
	temp->left=NULL;temp->right=NULL;
	return temp;
}


//Left - Left
Node *rightRotate(Node *p){
	Node *q=p->left;
	p->left=q->right;
	q->right=p;
	return q;
}
//Right - Left
Node *leftRotate(Node *q){
	Node *p=q->right;
	q->right=p->left;
	p->left=q;
	return p;
}

Node *splaySearch(Node *root,int k){
	if(root==NULL)return root;
	
	if(k<root->data){
		
		if(root->left==NULL)return root;
		
		if(k<root->left->data){
			root->left->left=splaySearch(root->left->left,k);
			
			root=rightRotate(root);
		}
		if(k>root->left->data){
			root->left->right=splaySearch(root->left->right,k);
			if(root->left->right!=NULL)
				root->left=leftRotate(root->left);
		}
		
		return (root->left==NULL)?root:rightRotate(root);
	}
	else{
		if(root->right==NULL)return root;
		if(k<root->right->data){
			root->right->left=splaySearch(root->right->left,k);
			if(root->right->left!=NULL)
				root->right=rightRotate(root->right);
		}
		if(k>root->right->data){
			root->right->right=splaySearch(root->right->right,k);
			
			root=leftRotate(root);
		}
		
		return (root->right==NULL)?root:leftRotate(root);
	}
	
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
/* Drier program to test above function*/
int main()
{
    Node *root = newNode(100);
    root->left = newNode(50);
    root->right = newNode(200);
    root->left->left = newNode(40);
    root->left->left->left = newNode(30);
    root->left->left->left->left = newNode(20);
 
    root = splaySearch(root, 20);
    printf("Preorder traversal of the modified Splay tree is \n");
    preOrder(root);
    return 0;
}



