#include<bits/stdc++.h>
using namespace std;

struct tNode{
	int data;
	tNode *left,*right;
	tNode(int x){
		data=x;
		left=right=NULL;
	}
};

struct lNode{
	int data;
	lNode *next;
	lNode(int x){
		data=x;
		next=NULL;
	}
};


tNode *sortedLLToBST(lNode **head,int n){
	if(n<=0)return NULL;
	
	
	tNode*left=sortedLLToBST(head,n/2);
	tNode*root=new tNode((*head)->data);
	root->left=left;
	
	(*head)=(*head)->next;
	root->right=sortedLLToBST(head,n-(n/2)-1);
	
	return root;
	
}

int countnodes(lNode*head)
{
	if(head==NULL)
	return 0;
	int p=0;
	while(head)
	{
		p++;
		head=head->next;
	}
	return p;
}

void push(lNode**headf,int d)
{
	lNode*n=new lNode(d);
	n->next=*headf;
	*headf=n;
}

void inorder(tNode*root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void printlist(lNode*head)
{
	while(head)
	{
		printf("%d->",head->data);
		head=head->next;
	}
}


int main()
{
	lNode *head=NULL;
	push(&head,10);
	push(&head,9);
	push(&head,8);
	push(&head,6);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	
	printlist(head);
	int n=countnodes(head);
	tNode*root=sortedLLToBST(&head,n);
	printf("\n");
	inorder(root);
	return 0;
}

