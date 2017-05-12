#include<bits/stdc++.h>

using namespace std;

struct node 
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head;


struct node *createNode(int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	
	return temp;
}

void print()
{
	struct node *traverse=head;
	while(traverse!=NULL)
	{
		cout<<traverse->data<<" ";
		traverse=traverse->next;
		
	}	
	return;
}



void insertNodeBegin(int data)
{
	struct node *temp=createNode(data);
	if(head==NULL)
	{
		head=temp;
		return;
	}
	head->prev=temp;
	temp->next=head;
	head=temp;
//	return;
	
}


void insertNodeEnd(int data)
{
	struct node *temp=createNode(data);
	if(head==NULL)
	{
		head=temp;
		return;
	}
	
	struct node *traverse=head;
	while(traverse->next!=NULL)
		traverse=traverse->next;
	
	traverse->next=temp;
	temp->prev=traverse;
	return;	
}


void insertNodeByData(int key,int data)
{
	struct node *temp=createNode(data);
	struct node *traverse=head;
	if(traverse==NULL)
	{
		cout<<"error"<<endl;
		return;
	}
	else
	{
		while(traverse->data!=key)
		{
			traverse=traverse->next;	
		}
		temp->next=traverse->next;
		temp->next->prev=temp;
		traverse->next=temp;
		temp->prev=traverse;
		return;
	}
}




int main()
{
	head=NULL;	
	
	insertNodeBegin(10);
	insertNodeBegin(20);
	insertNodeBegin(30);
	insertNodeEnd(40);
	insertNodeByData(30,100);
	print();
}
