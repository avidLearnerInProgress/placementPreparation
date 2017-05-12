#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
	
};

struct node *head;

void swapNodeByPointer(int x,int y){
	
	struct node *traversex=head;
	struct node *traversey=head;
	
	struct node *pTraversex=head;
	struct node *pTraversey=head;
	
	while(traversex && traversex->data!=x)
	{
		pTraversex=traversex;
		traversex=traversex->next;
	}
	
	
	while(traversey && traversey->data!=y)
	{
		pTraversey=traversey;
		traversey=traversey->next;
	}
	if(pTraversex!=NULL)
		pTraversex->next=traversey;
	else
		head=traversey;
	
	if(pTraversey!=NULL)		
		pTraversey->next=traversex;
	else
		head=traversex;
	
	struct node *swap=traversey->next;
	traversey->next=traversex->next;
	traversex->next= swap;
	
}



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
    insertNodeBegin(50);
    insertNodeBegin(60);
    Print();
    cout<<endl;
	swapNodeByPointer(20,40) ;
	Print();
	cout<<endl;
 
 	return 0;   
}



