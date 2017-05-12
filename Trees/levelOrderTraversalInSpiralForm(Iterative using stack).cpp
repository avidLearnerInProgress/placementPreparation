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



void printSpiral(Node *root){
	
	if(root==NULL)return;
	
	stack<Node *> s1,s2;
	
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		
		while(!s1.empty()){
			
			Node *temp1=s1.top();
			cout<<temp1->data<<" ";
			s1.pop();
			
			if(temp1->right)s2.push(temp1->right);
			if(temp1->left)s2.push(temp1->left);
			
			
		}
		
		while(!s2.empty()){
			
			Node *temp2=s2.top();
			cout<<temp2->data<<" ";
			s2.pop();
			
			if(temp2->right)s1.push(temp2->right);
			if(temp2->left)s1.push(temp2->left);
			
			
		}
		
		
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


