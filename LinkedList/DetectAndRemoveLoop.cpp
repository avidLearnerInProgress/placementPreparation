#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node *head;


node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


void detectAndRemoveLoop(){
	
	struct node *slow_ptr=head;
	struct node *fast_ptr=head->next;
	
	
	while(fast_ptr && fast_ptr->next)
	{
		if(slow_ptr==fast_ptr)
			break;
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
		
	}
	
	if(slow_ptr==fast_ptr)
	{
		slow_ptr=head;
		while(slow_ptr!=fast_ptr->next)	
		{
			slow_ptr=slow_ptr->next;
			fast_ptr=fast_ptr->next;
		}
		
		fast_ptr->next=NULL;
		return;
	}
	
	else{
		cout<<"No Loop"<<endl;return;
	}
	
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


int main()
{
	//head=NULL;
	head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = head->next->next;
    //Print();
    detectAndRemoveLoop();
    Print();
    
 
	return 0;
}
