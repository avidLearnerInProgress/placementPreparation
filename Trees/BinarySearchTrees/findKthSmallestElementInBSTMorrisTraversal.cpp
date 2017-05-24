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

Node*insert(Node *root,int d)
{
	if(root==NULL)
	return new Node(d);
	
	if(root->data>d)
	root->left=insert(root->left,d);
	else if(root->data<d)
	root->right=insert(root->right,d);
	
	return root;
}


Node *findKthSmallestElementInBSTMorrisTraversal(Node *root,int k){
	if(root==NULL)return NULL;
	int c=0;
	Node *current=root;
	
	while(current!=NULL){
		if(current->left==NULL){
			c++;
			if(c==k)return current;
			current=current->right;
		}
		else if(current->left){
			Node *next=current->left;
			while(next->right!=NULL && next->right!=current)
				next=next->right;
			if(next->right==NULL){
				next->right=current;
				current=current->left;
			}
			else{
				next->right=NULL;
				c++;
				if(c==k)return current;
				current=current->right;
			}
		}
	}
	return current;
}


int main(){
	Node *root=NULL;
	root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
	int k=4;
    Node *kth=findKthSmallestElementInBSTMorrisTraversal(root,k);
    if(kth)
    printf("\nKth node is = %d",kth->data);
    else
    printf("nodes does not exists");

}
