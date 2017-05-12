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
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}


void Print()
{
	struct node *temp=head;
	
	while(temp->next!=head){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data;
	cout<<endl;
}

void insertNodeBegin(int data)
{
	struct node *temp=createNode(data);
	struct node *traverse=head;
	
	if(traverse==NULL)
	{
		head=temp;
		temp->next=head;
		return;
	}
	
	else{
		
		while(traverse->next!=head)
			traverse=traverse->next;
		 traverse->next=temp;
		 temp->next=head;
		 head=temp;
		 //return;
		
	}	
}


void insertNodeByData(int key,int data)
{
	struct node *temp=createNode(data);
	struct node *traverse=head;
	while(traverse->data!=key)
		traverse=traverse->next;
		
	temp->next=traverse->next; 
	traverse->next=temp;
	return;
}

	
void deleteNodeBegin()
{
	struct node *temp=head;
	struct node *nextTemp=head->next;
	if(temp->next==head)
	{
		head=NULL;
		free(temp);
		return;	
	}
	
	while(nextTemp!=head){
		temp=nextTemp;
		nextTemp=nextTemp->next;
	 	}
	temp->next=nextTemp->next;
	head=nextTemp->next;
	free(nextTemp);
	
	 	return;
		
}

void deleteNodeByData(int key){
	struct node *temp=head;
	struct node *prevTemp=head;
	
	while(temp->data!=key)
	{
		prevTemp=temp;
		temp=temp->next;
	}
	if(temp->next==head)
	{
		prevTemp->next=head;
		free(temp);return;
	}
	else{
	
	prevTemp->next=temp->next;
	
	free(temp);
	return;
	}
	
}




int main()
{
	head=NULL;		
	insertNodeBegin(10);
	insertNodeBegin(20);
	insertNodeBegin(30);
	//insertNodeBegin(10);
	Print();
	insertNodeByData(30,100);
	Print();
	deleteNodeBegin();Print();
	deleteNodeByData(20);
	Print();
	return 0;
}
