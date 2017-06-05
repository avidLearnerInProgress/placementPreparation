#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	struct Node *left,*right,*nextRight;
	Node(int x){
		data=x;
		left=right=nextRight=NULL;
	}
};


Node *getNextRight(Node *current){
	Node *temp=current->nextRight;
	
	while(temp!=NULL){
	
	if(temp->left!=NULL)
		return temp->left;
	if(temp->right!=NULL)
		return temp->right;
	
	temp=temp->nextRight;	
	}	
	
	return NULL;
}


void connectNodesAtSameLevel(Node *root){
	
	if(!root)return;
	
	root->nextRight=NULL;
	
	while(root!=NULL){
		
		Node *current=root;
		
		while(current!=NULL){
			
			if(current->left){
				if(current->right)
					current->left->nextRight=current->right;
				
				else
					current->left->nextRight=getNextRight(current);
					
			cout<<current->left->data<<" -> ";
			(current->left->nextRight)?cout<<current->left->nextRight->data:cout<<"-1";
			cout<<endl;
			
			}
			
			if(current->right){
			
			current->right->nextRight=getNextRight(current);
			
			cout<<current->right->data<<" -> ";
			(current->right->nextRight)?cout<<current->right->nextRight->data:cout<<"-1";
			cout<<endl;
			
			}
			
			current=current->nextRight;
		}
		
		if(root->left)
			root=root->left;
		else if(root->right)	
			root=root->right;
		else
			root=getNextRight(root);
	}

}



int main(){
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	connectNodesAtSameLevel(root);
	
}
