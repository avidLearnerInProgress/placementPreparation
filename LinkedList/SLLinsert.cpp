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


void insertNodeEnd(int data)
{
	struct node *temp=createNode(data);
	struct node *traverse=head;
	if(head==NULL){
	
		temp->next=NULL;
		head=temp;
		return;
	}
	
	while(traverse->next!=NULL)
		traverse=traverse->next;
	
	traverse->next=temp;
	temp->next=NULL;
	
}

void insertNodeByData(int key)
{
	struct node *temp=createNode(key);
	struct node *traverse=head;
	if(traverse->next==NULL){
	
		traverse->next=temp;
		temp->next=NULL;
		return;
	}

	while(traverse->data!=key)
		traverse=traverse->next;

	temp->next=traverse->next;	
	traverse->next=temp;
	
}

void lengthOfSLL()
{
	struct node *temp=head;
	int count=0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
}
	cout<<count<<endl; 
}



int main()
{
    head=NULL;
    
    insertNodeBegin(10);
    insertNodeBegin(20);
    insertNodeBegin(30);
    insertNodeBegin(40);
    
    insertNodeEnd(50);
    insertNodeByData(40);
	lengthOfSLL();
    Print();
    
    
    
	return 0;
}
