#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node* next;
};
 

void printNthFromLast(struct node* head, int n)
{
   int len=0; int i;
   struct node *temp=head;
   while(temp!=NULL)
   	{
   		temp=temp->next;
   		len++;
	}	
	   
	if(n>len)
	   	return;
	
	temp=head;
	
	for(i=1;i<(len-n+1);i++)   	
		temp=temp->next;
	
	cout<<temp->data;	
	
   return;
   
}
 
void push(struct node** head_ref, int new_data)
{
  struct node* new_node =
          (struct node*) malloc(sizeof(struct node));
  new_node->data  = new_data;
  new_node->next = (*head_ref);
  (*head_ref)    = new_node;
}
 

int main()
{

  struct node* head = NULL;
  push(&head, 10);
  push(&head, 20);
  push(&head, 30);
  push(&head, 40);
 
  printNthFromLast(head, 2);
  return 0; 
}
