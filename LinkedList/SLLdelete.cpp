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

}

void deleteNodeBegin()
{
	//struct node *temp=createNode(data);
	struct node *temp=head;
	
	if(temp->next==NULL){
	
		free(temp);return;
		
	}
	else
	{
		head=temp->next;
		free(temp);
		return;
	}
	
}




void deleteNodeEnd()
{
	struct node *temp,*nextTemp;
	struct node *traverse=head;
	if(traverse->next==NULL){
		temp=traverse;
		traverse=NULL;
		free(temp);
		return;	
	}
	
	nextTemp=traverse;
	temp=traverse->next;
	
	
	while(temp->next!=NULL){
		nextTemp=temp;
		temp=temp->next;	
	}
	free(temp);
	nextTemp->next=NULL;
	
}

void deleteNodeByData(int key)
{
	struct node *temp,*nextTemp;
	struct node *traverse=head;
	if(traverse->data==key){
	
		head=traverse->next;
		free(traverse);
		
		//temp->next=NULL;
		return;
	}
	else
	{
	temp=traverse;
	nextTemp=traverse;
	while(temp->data!=key){
		nextTemp=temp;
		temp=temp->next;
	}
	nextTemp->next=temp->next;
	free(temp);
	return;
	}
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
  	deleteNodeBegin();
  	deleteNodeEnd();
  	//deleteNodeByData(30);
    
    Print();
    
	return 0;
}
