#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *prev;
	Node *next;
	Node(int x){
		data=x;
		prev=NULL;
		next=NULL;
	}
};

void push(Node **headf,int d)
{
	Node*n=new Node(d);
	n->next=*headf;
	if(*headf)
	(*headf)->prev=n;
	*headf=n;
}

void printlist(Node *headf)
{
	
	while(headf->next)
	{
		printf("%d<->",headf->data);
		headf=headf->next;
	}
	printf("%d",headf->data);
	printf("\n");
}

void inorder(Node *root)
{
	if(root==NULL)
	return;
	
	inorder(root->prev);
	printf("%d ",root->data);
	inorder(root->next);
	
}



Node *sortedLLToBST(Node *head){
	if(!head || !head->next)return head;
	
	Node *fast=head;
	Node *mid=head;
	
	while(fast && fast->next){
		mid=mid->next;
		fast=fast->next->next;
	}
	
	if(mid->prev)mid->prev->next=NULL;
	if(mid->next)mid->next->prev=NULL;
	
	mid->prev=sortedLLToBST(head);
	mid->next=sortedLLToBST(mid->next);
	
	return mid;
}




int main(){
	Node *headf=NULL;
	push(&headf,10);
	push(&headf,23);
	push(&headf,29);
	push(&headf,30);
	push(&headf,45);
	push(&headf,50);
	cout<<"Printing DLL:"<<endl;
	printlist(headf);
	Node *head=sortedLLToBST(headf);
	printf("\n");
	cout<<"Printing BST: "<<endl;
	inorder(head);
	return 0;
}
