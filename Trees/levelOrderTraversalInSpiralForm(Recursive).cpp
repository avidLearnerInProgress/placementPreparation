#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node *left,*right;
};


Node *createNode(int data){
	Node *temp=new Node();
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
	
}

int height(Node *root){
	if(root==NULL)return 0;
	else{
		int lheight=height(root->left);
		int rheight=height(root->right);
		
		return (1+max(lheight,rheight));
	}
	return 0;
}

void printGivenLevel(Node *root,int level,bool ltr){
	
	if(root==NULL)return;
	if(level==1)cout<<root->data<<" ";
	else if(level>1){
		if(ltr){
			printGivenLevel(root->left,level-1,ltr);
			printGivenLevel(root->right,level-1,ltr);
		}
		
		else{
			printGivenLevel(root->right,level-1,ltr);
			printGivenLevel(root->left,level-1,ltr);
		}
		
		
	}
}

void printSpiral(Node *root){
	int h=height(root);
	bool ltr=false;
	
	for(int i=1;i<=h;i++){
		
		printGivenLevel(root,i,ltr);
		ltr=!ltr;	
		
	}
	
}

int main(){
	Node *root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(7);
    root->left->right=createNode(6);
    root->right->left=createNode(5);
    root->right->right=createNode(4);
    printSpiral(root);
 
    return 0;
	
}


