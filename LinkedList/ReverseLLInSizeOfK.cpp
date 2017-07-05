#include<bits/stdc++.h>

using namespace std;


//refer mycodeschool for reverse function

struct node
{
    int data;
    struct node* next;
};

//struct node *head;

struct node *createNode(int data)
{
	struct node *temp=(struct node *) malloc( sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}

void Print(struct node *head)
{
	struct node *traverse=head;
	while(traverse!=NULL){
	
		cout<<traverse->data<<" ";
		traverse=traverse->next;
}
	cout<<endl;	
}


void insertNodeBegin(struct node **head,int data)
{
	struct node *temp=createNode(data);
	if(head==NULL){
	
		temp->next=NULL;
		*head=temp;
		return;
	}
	
	else
	{
		temp->next=*head;
		*head=temp;
		return;
	}
	
}


struct node *ReverseInSizeOfK(struct node *head,int k){
	
	struct node *curr=head;
	struct node *prev=NULL;
	struct node *next=NULL;
	int count=0;
	while(curr!=NULL && count<k)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	if(next!=NULL)
		head->next=ReverseInSizeOfK(next,k);	
	return prev;
}

int main(){
	struct node* head = NULL;
	int n;cin>>n;
	for(int i=n;i>=1;i--)
		insertNodeBegin(&head,i);
    
	Print(head);
    head=ReverseInSizeOfK(head,3);
	Print(head);
		return 0;
}
