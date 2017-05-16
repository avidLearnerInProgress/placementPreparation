#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
	
};


struct node *getNode(int data){
	
	struct node *temp=(struct node *) malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}


void iterativeInorder(struct node *root){
	
	stack <node *> s;
	if(!root)return;
	//s.push(root);
	while(root){
		s.push(root);
		root=root->left;
		
	}
	
	while(!s.empty()){
		struct node *vNode=s.top();
		cout<<vNode->data<<" ";
		s.pop();
		
		if(vNode->right){
			struct node* vRight=vNode->right;
			while(vRight){
				s.push(vRight);
				vRight=vRight->left;
			}
			
		}
	
	}
	
	
}

int main(){
    struct node *root = getNode(1);
    root->left        = getNode(2);
    root->right       = getNode(3);
    root->left->left  = getNode(4);
    root->left->right = getNode(5);
 
    iterativeInorder(root);
    return 0;
}

