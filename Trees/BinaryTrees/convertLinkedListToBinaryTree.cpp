#include<bits/stdc++.h>
using namespace std;

struct BTreeNode{
	int data;
	BTreeNode *left,*right;
	
};


struct LLNode{
	int data;
	LLNode *next;
};


BTreeNode *newBTreeNode(int data){
	BTreeNode *temp=new BTreeNode();
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void push(LLNode **head,int data){
	
	LLNode *temp=new LLNode();
	temp->data=data;
	temp->next=*head;
	*head=temp;
	
}

void convertListToBinaryTree(LLNode *head,BTreeNode* &root){
	
	if(!head){
		root=NULL;return;
	}
	
	queue<BTreeNode *> q;
	root=newBTreeNode(head->data);
	q.push(root);
	while(head){
		
		BTreeNode *current=q.front();
		q.pop();
		head=head->next;
		BTreeNode *leftChild=NULL;
		BTreeNode *rightChild=NULL;
		
		if(head){
			leftChild=newBTreeNode(head->data);
			q.push(leftChild);
			head=head->next;
		}
		if(head){
			rightChild=newBTreeNode(head->data);
			q.push(rightChild);
			head=head->next;
		}
		current->left=leftChild;
		current->right=rightChild;
	}
}


void print(BTreeNode *root){
	if(root){
		print(root->left);
		cout<<root->data<<" ";
		print(root->right);
	}
}



int main(){
	
	LLNode *head=NULL;
    push(&head,36); 
    push(&head,30);
    push(&head,25);
    push(&head,15);
    push(&head,12);
    push(&head,10); 
 
    BTreeNode *root;
    convertListToBinaryTree(head,root);
    cout<<"Inorder Traversal of the constructed Binary Tree is: \n";
    print(root);
    return 0;
	
}
