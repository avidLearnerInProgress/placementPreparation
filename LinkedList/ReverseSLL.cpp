#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *head;

struct node *createNode(int data)
{
	struct node *temp=(struct node *) malloc( sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}

void Print()
{
	struct node *traverse=head;
	while(traverse!=NULL){
	
		cout<<traverse->data<<" ";
		traverse=traverse->next;
}
		cout<<endl;
}


void LLReverse()
{
	struct node *curr=head;
	struct node *prev=NULL;
	struct node *next;
	
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	
	}
	head=prev;
	return;
}


void insertNodeBegin(int data)
{
	struct node *temp=createNode(data);
	if(head==NULL){
	
		temp->next=NULL;
		head=temp;
		return;
	}
	
	else
	{
		temp->next=head;
		head=temp;
		return;
	}
	
}



int main()
{
    head=NULL;
    
    insertNodeBegin(10);
    insertNodeBegin(20);
    insertNodeBegin(30);
    insertNodeBegin(40);
    
    Print();
    LLReverse();
    Print();
    
    
    
	return 0;
}
