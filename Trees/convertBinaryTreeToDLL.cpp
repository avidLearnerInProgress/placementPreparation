#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left,*right;
	node(int x)
	{
		data=x;
		left=NULL;
		right=NULL;
	}
};


int inorder(node *root,node **prev,node **head)
{
	if(root)
	{
		inorder(root->left,prev,head);
		if(*prev==NULL)
		{
			(*head)=root;
			(*prev)=root;
		}
		else
		{
			root->left=(*prev);
			(*prev)->right=root;
			(*prev)=root;
		}
		inorder(root->right,prev,head);
	}
}

void printdll(node *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->right;
	}
}

int main()
{
	node *root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	node *prev=NULL;
	node *head=NULL;
	inorder(root,&prev,&head);
	printdll(head);
}
 
