#include<bits/stdc++.h>

using namespace std;

struct node{
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


//10->20->30->40->50->60
//50->60->10->20->30->40

void RotateLLSizeOfK(int k)
{
	struct node *curr=head;
	int count=1;
	while(curr!=NULL&&count<k)
	{
		curr=curr->next;
		count++;
	}
	
	if(curr==NULL)return;
	
	struct node *knode=curr;
	
	while(curr->next!=NULL)
		curr=curr->next;
	
	curr->next=head;
	head=knode->next;
	knode->next=NULL;
		
}


int main()
{
	head=NULL;
	
    insertNodeBegin(60);
    insertNodeBegin(50);
    insertNodeBegin(40);
    insertNodeBegin(30);
    insertNodeBegin(20);
    insertNodeBegin(10);
    Print();
    RotateLLSizeOfK(4);
    Print();
	return 0;
}
