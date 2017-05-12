#include<bits/stdc++.h>
using namespace std;

struct node{
	
	int data;
	struct node *left;
	struct node *right;
};

struct node *createNode(int data){
	
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}


int heightOfTree(struct node *root){
	
	if(root==NULL)return 0;
	
	int hleft=heightOfTree(root->left);
	int hright=heightOfTree(root->right);
	
	if(hleft>hright)
		return (hleft+1);
	else
		return (hright+1);
		
}
/*
void printGivenLevel(struct node *root,int level){
	if(root==NULL)return;
    if(level==1)cout<<root->data<<" ";
	else if(level>1){
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}
}
*/

void printLevelOrder(struct node *root){
	
	struct node *temp=(struct node*) malloc(sizeof(struct node));
	queue<node *> q;
	q.push(root);
	while(!q.empty()){
		
		temp=q.front();
		cout<<temp->data;
		q.pop();
		if(temp->left!=NULL)
			q.push(temp->left);
		
		if(temp->right!=NULL)	
			q.push(temp->right);
			
		
		
	}
	

}

int main(){
	struct node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);
		
	printLevelOrder(root);
	return 0;
}

